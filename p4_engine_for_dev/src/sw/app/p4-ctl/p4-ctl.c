/****************************************************************************************************************************************************/
/* SECTION: Header includes */
/****************************************************************************************************************************************************/

/*
 * The example designs include file should be present in the target/inc directory
 * NOTE: This file that gives access to the generated configuration file
 */
#include "p4_env.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/****************************************************************************************************************************************************/
/* SECTION: Constants/macros */
/****************************************************************************************************************************************************/

#define EXAMPLE_NUM_TABLE_ENTRIES (4)

#define DISPLAY_ERROR(ErrorCode)  printf("Error Code is value %s\n\r", XilVitisNetP4ReturnTypeToString(ErrorCode))

#define CONVERT_BITS_TO_BYTES(NumBits) ((NumBits/XIL_VITIS_NET_P4_BITS_PER_BYTE) + ((NumBits % XIL_VITIS_NET_P4_BITS_PER_BYTE)? 1 : 0))

/****************************************************************************************************************************************************/
/* SECTION: Local function declarations*/
/****************************************************************************************************************************************************/
static void DisplayVitisNetP4Versions(XilVitisNetP4TargetCtx *CtxPtr);
static void printUsage();
/****************************************************************************************************************************************************/
/* SECTION: Global variables */
/****************************************************************************************************************************************************/

struct arg_info {
    char *table_name;
    char *action;
    uint8_t *keyPtr;
    uint8_t *actionParams;
    uint8_t *maskPtr;
    uint32_t *priority;
    uint32_t keySizeBits;
    uint32_t actionParamsSizeBit;
    uint32_t maskSizeBits;
    bool printVersion;
    bool tableOp;
    bool tableInsertOp;
    bool tableUpdateOp;
    bool tableDeleteOp;
    bool tableGetOp;
    bool actionOp;
};


/****************************************************************************************************************************************************/
/* SECTION: Entry point */
/* ex. p4_ctl table tableName action actionName actionParams insert key keyData mask maskData prior priority */ 

/****************************************************************************************************************************************************/

int main(int argc, char *argv[])
{
    int numberOfCommands;
    char *command[20];
    char *token;
    char receivedCommand[1024];
    XilVitisNetP4EnvIf EnvIf;
    XilVitisNetP4TargetCtx ProgramTargetCtx;
    XilVitisNetP4TableCtx *ProgramTableCtxPtr;
    XilVitisNetP4ReturnType Result;
    XilVitisNetP4TableMode TableMode;
    uint8_t tempMask[] = {0xFF, 0xFF, 0xFF, 0xFF};
    uint8_t ReadParamActionsBuffer[10];
    uint32_t tempPriority = 0;
    uint32_t ActionId;
    uint32_t ReadActionId;
    uint32_t keySizeBits;
    uint32_t maskSizeBits;
    uint32_t actionParamsSizeBit;
    int rv = 0;
    struct arg_info args;

    Result = XilVitisNetP4EnvIfPrep(&EnvIf);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        DISPLAY_ERROR(Result);
        goto exit_program;
    }

    printf("Initialize the Target Driver\n\r");
    Result = XilVitisNetP4TargetInit(&ProgramTargetCtx, &EnvIf, &(XilVitisNetP4TargetConfig_p4_engine));
    if (Result == XIL_VITIS_NET_P4_TARGET_ERR_INCOMPATIBLE_SW_HW)
    {
        /* DisplayVitisNetP4IP and Software versions to determine the differences */
        DisplayVitisNetP4Versions(&ProgramTargetCtx);
        goto exit_program;
    }
    else if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        DISPLAY_ERROR(Result);
        goto exit_program;
    }

    while(1) {

        // read line from stdin
        // parse the line
        printf(">>> ");
        fgets(receivedCommand, 1024, stdin);

        // tokenize the command and store it in command variable
        command[0] = argv[0];
        numberOfCommands = 1;
        token = strtok(receivedCommand, " \n");
        while(token != NULL) {
            command[numberOfCommands] = token;
            numberOfCommands++;
            token = strtok(NULL, " \n");
        }

        if(numberOfCommands == 2 && !strcmp(command[1], "exit")) {
            break;
        }

        // printf("Number of commands: %d\n", numberOfCommands);
        // for(int i = 0; i < numberOfCommands; i++) {
        //     printf("Command[%d]: %s\n", i, command[i]);
        // }
        // continue;

        // Parse the arguments
        rv = parse_cmd(numberOfCommands, command, &args);
        if (rv != 0) {
            printUsage(argv[0]);
            continue;
        }

        if(args.printVersion) {
            printf("Display the VitisNetP4 Versions\n\r");
            DisplayVitisNetP4Versions(&ProgramTargetCtx);
            continue;
        } else if (args.tableOp) {

            printf("Get Table Handle with name %s\n\r", args.table_name);

            Result = XilVitisNetP4TargetGetTableByName(&ProgramTargetCtx, args.table_name, &ProgramTableCtxPtr);
            if (Result != XIL_VITIS_NET_P4_SUCCESS)
            {
                DISPLAY_ERROR(Result);
                continue;
            }

            // Get table mode
            Result = XilVitisNetP4TableGetMode(ProgramTableCtxPtr, &TableMode);
            if (Result != XIL_VITIS_NET_P4_SUCCESS)
            {
                DISPLAY_ERROR(Result);
                continue;
            }
            printf("Table Mode is %s\n\r", XilVitisNetP4TableModeToString(TableMode));

            if(TableMode == XIL_VITIS_NET_P4_TABLE_MODE_BCAM || TableMode == XIL_VITIS_NET_P4_TABLE_MODE_TINY_BCAM) {
                args.maskPtr = NULL;
                args.maskSizeBits = 0;
                args.priority = NULL;
            }

            Result = XilVitisNetP4TableGetKeySizeBits(ProgramTableCtxPtr, &keySizeBits);
            if (Result != XIL_VITIS_NET_P4_SUCCESS)
            {
                DISPLAY_ERROR(Result);
                goto target_exit;
            } else if (keySizeBits != args.keySizeBits) {
                printf("Key size mismatch. Expected %d, got %d\n\r", keySizeBits, args.keySizeBits);
                continue;
            }

            if(args.actionOp) {

                printf("Get ActionId from Action Name %s\n\r", args.action);
                Result = XilVitisNetP4TableGetActionId(ProgramTableCtxPtr, args.action, &ActionId);
                if (Result != XIL_VITIS_NET_P4_SUCCESS)
                {
                    DISPLAY_ERROR(Result);
                    continue;
                }

                Result = XilVitisNetP4TableGetActionParamsSizeBits(ProgramTableCtxPtr, &actionParamsSizeBit);
                if (Result != XIL_VITIS_NET_P4_SUCCESS)
                {
                    DISPLAY_ERROR(Result);
                    goto target_exit;
                } 
                else if (actionParamsSizeBit != args.actionParamsSizeBit) {
                    printf("Action Parameters size mismatch. Expected %d, got %d\n\r", actionParamsSizeBit, args.actionParamsSizeBit);
                    if (actionParamsSizeBit == 0){
                        printf("Since expected size is 0, auto configuring the action parameters\n\r");
                        args.actionParamsSizeBit = 0;
                        uint8_t temp[1] = {0};
                        args.actionParams = temp;
                    } else {
                        continue;
                    }
                }

                if(args.tableInsertOp) {
                    printf("Inserting table element\n\r");

                    Result = XilVitisNetP4TableInsert(ProgramTableCtxPtr,
                                                args.keyPtr,
                                                args.maskPtr,
                                                (args.priority == NULL? 0: args.priority[0]),
                                                ActionId,
                                                args.actionParams);
                    if (Result != XIL_VITIS_NET_P4_SUCCESS)
                    {
                        printf("Error in inserting table entry\n\r");
                        DISPLAY_ERROR(Result);

                        if(Result != XIL_VITIS_NET_P4_CAM_ERR_DUPLICATE_FOUND && Result != XIL_VITIS_NET_P4_TABLE_ERR_PARAM_NOT_REQUIRED && Result != XIL_VITIS_NET_P4_GENERAL_ERR_NULL_PARAM) {
                            goto target_exit;
                        } else {
                            continue;
                        }
                    }

                    Result = XilVitisNetP4TableGetByKey(ProgramTableCtxPtr  ,
                                                args.keyPtr,
                                                (TableMode == XIL_VITIS_NET_P4_TABLE_MODE_TINY_BCAM?tempMask :args.maskPtr), // MaskPtr not used for a table with mode of BCAM
                                                &tempPriority,
                                                &ReadActionId,
                                                ReadParamActionsBuffer);
                    if (Result == XIL_VITIS_NET_P4_SUCCESS)
                    {
                        printf("Read shadow table entry, Action Id is %d with priority %d and Action Params: ",
                            ReadActionId, tempPriority);
                        for(int i = 0; i < actionParamsSizeBit/8; i++) {
                            printf("%02x", ReadParamActionsBuffer[i]);
                        }
                        printf("\n\r");
                    }
                    else
                    {
                        printf("Error in reading table entry\n\r");
                        DISPLAY_ERROR(Result);
                        goto target_exit;
                    }

                } else if(args.tableUpdateOp) {
                    // printf("Updating the Response for table\n\r");
                    // ReadParamActionsBuffer[0]++;
                    // ReadParamActionsBuffer[1]++;
                    // Result = XilVitisNetP4TableUpdate(ProgramTableCtxPtr,
                    //                             args.keyPtr,
                    //                             args.maskPtr,
                    //                             ActionId,
                    //                             ReadParamActionsBuffer);
                    // if (Result != XIL_VITIS_NET_P4_SUCCESS)
                    // {
                    //     printf("Error in updating table entry\n\r");
                    //     DISPLAY_ERROR(Result);
                    //     goto target_exit;
                    // }

                    // Result = XilVitisNetP4TableGetByKey(ProgramTableCtxPtr,
                    //                             args.keyPtr,
                    //                             args.maskPtr, // MaskPtr not used for a table with mode of BCAM
                    //                             args.priority, // Priority is ignored for a table with mode of BCAM
                    //                             &ReadActionId,
                    //                             ReadParamActionsBuffer);
                    // if (Result == XIL_VITIS_NET_P4_SUCCESS)
                    // {
                    //     printf("The Action Id is %d\n\r",
                    //         ReadActionId);
                    // }
                    // else
                    // {
                    //     printf("Error in reading table entry\n\r");
                    //     DISPLAY_ERROR(Result);
                    //     goto target_exit;
                    // }
                }
            } else if(args.tableDeleteOp) {
                printf("Delete table entry\n\r");
                Result = XilVitisNetP4TableDelete(ProgramTableCtxPtr, args.keyPtr, args.maskPtr);

                if (Result == XIL_VITIS_NET_P4_SUCCESS)
                {
                    /* Not neccessary but checking if the key can be found to demo the usage */
                    Result = XilVitisNetP4TableGetByKey(ProgramTableCtxPtr,
                                                args.keyPtr,
                                                (TableMode == XIL_VITIS_NET_P4_TABLE_MODE_TINY_BCAM?tempMask :args.maskPtr), // MaskPtr not used for a table with mode of BCAM
                                                &tempPriority, // Priority is ignored for a table with mode of BCAM
                                                &ReadActionId,
                                                ReadParamActionsBuffer);
                    if (Result != XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND)
                    {
                        printf("Error table entry is still present\n\r");
                        DISPLAY_ERROR(Result);
                    }
                    else
                    {
                        printf("Table entry successfully deleted\n\r");
                    }
                }
                else
                {
                    printf("Error in deleting table entry\n\r");
                    DISPLAY_ERROR(Result);
                    continue;
                }
            } else if (args.tableGetOp) {
                Result = XilVitisNetP4TableGetByKey(ProgramTableCtxPtr  ,
                                            args.keyPtr,
                                            (TableMode == XIL_VITIS_NET_P4_TABLE_MODE_TINY_BCAM?tempMask :args.maskPtr), // MaskPtr not used for a table with mode of BCAM
                                            &tempPriority, // Priority is ignored for a table with mode of BCAM
                                            &ReadActionId,
                                            ReadParamActionsBuffer);
                if (Result == XIL_VITIS_NET_P4_SUCCESS)
                {
                    printf("Read shadow table entry, Action Id is %d with priority %d and Action Params: ",
                        ReadActionId, tempPriority);
                    for(int i = 0; i < actionParamsSizeBit/8; i++) {
                        printf("%02x", ReadParamActionsBuffer[i]);
                    }
                    printf("\n\r");
                }
                else
                {
                    printf("Error in reading table entry\n\r");
                    DISPLAY_ERROR(Result);
                    continue;
                }
            }
            
        }
    }

target_exit:

    printf("Exiting the Target Driver\n\r");
    Result = XilVitisNetP4TargetExit(&ProgramTargetCtx);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        DISPLAY_ERROR(Result);
    }

exit_program:
    printf("Exiting the Program\n\r");
    return Result;
}

/****************************************************************************************************************************************************/
/* SECTION: Local function definitions */
/****************************************************************************************************************************************************/
static void DisplayVitisNetP4Versions(XilVitisNetP4TargetCtx *CtxPtr)
{
    XilVitisNetP4ReturnType Result;
    XilVitisNetP4Version SwVersion;
    XilVitisNetP4Version IpVersion;
    XilVitisNetP4TargetBuildInfoCtx *BuildInfoCtxPtr;


    Result =  XilVitisNetP4TargetGetSwVersion(CtxPtr, &SwVersion);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        printf("Error in getting the Software Version\n");
        return;
    }

    printf("----VitisNetP4Runtime Software Version\n");
    printf("\t\t Major = %d\n", SwVersion.Major);
    printf("\t\t Minor = %d\n", SwVersion.Minor);
    printf("\n");

    /* The BuildInfo Driver provides access to the IP Version if present */
    Result = XilVitisNetP4TargetGetBuildInfoDrv(CtxPtr, &BuildInfoCtxPtr);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        printf("Error in getting the Build Info Driver\n");
        return;
    }

    Result = XilVitisNetP4TargetBuildInfoGetIpVersion(BuildInfoCtxPtr, &IpVersion);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        printf("Error in getting the IP Version\n");
        return;
    }

    printf("----VitisNetP4IP Version\n");
    printf("\t\t Major = %d\n", IpVersion.Major);
    printf("\t\t Minor = %d\n", IpVersion.Minor);
}

static void printUsage(char* progName)
{
    printf("Usage: table name <tableName> action <actionName> <actionParams> <insert|delete|get> key <keyData> mask <maskData> prior <priority>\n");
    printf("Set of commands\n");
    printf("table name <tableName>\n");
    printf("action <actionName> <actionParams>\n");
    printf("<insert|delete|get>\n");
    printf("key <keyData>\n");
    printf("Optional: mask <maskData>\n");
    printf("Optional: prior <priority>\n");
    printf("The actionParams, keyData, maskData should be in hexadecimal format\n");
    printf("Example: table FiveTuple action InsertVLAN 3111 insert key fd5f0bc89aaa20101124116cc1 \n");
}

int parse_key(char *inp, uint8_t **out, uint32_t *size)
{
    int len = strlen(inp);
    int j;

    if(!strcmp(inp, "NULL")) {
        *size = 0;
        return 0;
    }

    if(len % 2) {
        // print usage
        printf("The key length is not in bytes\n");
        return -1;
    }

    *size = len*4;
	uint8_t *arr = (uint8_t *)malloc(len/2 * sizeof(uint8_t));
    *out = arr;

    for(j = 0; j < len; j++) {
        if(!isxdigit(inp[j])) {
            // print usage
            printf("The key is not in hexadecimal format: %d %c\n", j, inp[j]);
            return -1;
        }
    }

    for(j = 0; j < len/2; j++) {
        sscanf(inp+j*2, "%02X", (*out)+j);
        // printf("Key[%d] = %02X\n", j, (*out)[j]);
    }
    return 0;
}

int parse_key32(char *inp, uint32_t **out, uint32_t *size)
{
    int len = strlen(inp);
    int j;

    if(!strcmp(inp, "NULL")) {
        *size = 0;
        return 0;
    }

    if(len % 2) {
        // print usage
        printf("The key length is not in bytes\n");
        return -1;
    }

    *size = len*4;
	uint32_t *arr = (uint32_t *)malloc(len/2 * sizeof(uint32_t));
    *out = arr;

    for(j = 0; j < len; j++) {
        if(!isxdigit(inp[j])) {
            // print usage
            printf("The key is not in hexadecimal format: %d %c\n", j, inp[j]);
            return -1;
        }
    }

    for(j = 0; j < len/2; j++) {
        sscanf(inp+j*2, "%08X", (*out)+j);
        // printf("Key[%d] = %02X\n", j, (*out)[j]);
    }
    return 0;
}

int parse_table_cmd(int argc, char *argv[], int i, struct arg_info *args)
{
    int rv = 0;

    args->tableOp = true;

    args->actionParams = NULL;
    args->keyPtr = NULL;
    args->maskPtr = NULL;
    args->priority = NULL;

    args->keySizeBits = 0;
    args->maskSizeBits = 0;
    args->actionParamsSizeBit = 0;

    while(i < argc) {
        if(!strcmp(argv[i], "name")) {
            if(i+1 >= argc) {
                // print usage
                printf("Table name not provided\n");
                return -1;
            }

            args->table_name = argv[i+1];

            i += 2;
        } else if(!strcmp(argv[i], "action")) {
            if(i+2 >= argc) {
                // print usage
                printf("Action name and/or parameters not provided\n");
                return -1;
            }
            args->actionOp = true;
            args->action = argv[i+1];

            if(!strcmp(argv[i+2], "NULL")) {
                uint8_t temp[1] = {0};
                args->actionParams = temp;
                args->actionParamsSizeBit = 0;
            } else {
                rv = parse_key(argv[i+2], &args->actionParams, &args->actionParamsSizeBit);
                if(rv != 0) {
                    return rv;
                }
            }

            i += 3;
        } else if(!strcmp(argv[i], "insert")) {
            args->tableInsertOp = true;
            i++;
        } else if(!strcmp(argv[i], "update")) {
            args->tableUpdateOp = true;
            i++;
        } else if(!strcmp(argv[i], "delete")) {
            args->tableDeleteOp = true;
            i++;
        } else if(!strcmp(argv[i], "get")) {
            args->tableGetOp = true;
            i++;
        } else if(!strcmp(argv[i], "key")) {
            if(i+1 >= argc) {
                // print usage
                printf("Key not provided\n");
                return -1;
            }

            rv = parse_key(argv[i+1], &args->keyPtr, &args->keySizeBits);
            if(rv != 0) {
                return rv;
            }

            i += 2;
        } else if(!strcmp(argv[i], "mask")) {
            if(i+1 >= argc) {
                // print usage
                printf("Mask not provided\n");
                return -1;
            }

            rv = parse_key(argv[i+1], &args->maskPtr, &args->maskSizeBits);
            if(rv != 0) {
                return rv;
            }

            i += 2;
        } else if(!strcmp(argv[i], "prior")) {
            if (i+1 >= argc) {
                // print usage
                printf("Priority not provided\n");
                return -1;
            }


            uint32_t temp;
            rv = parse_key32(argv[i+1], &args->priority, &temp);
            if(rv != 0) {
                return rv;
            }
            
            i += 2;
        } else {
            // print usage
            printf("Invalid command: %s\n", argv[i]);
            return -1;
        }
    }

    if(args->keyPtr == NULL) {
        // print usage
        printf("Key must be provided\n");
        return -1;
    } else {
        if(args->maskPtr != NULL) {
            // check mask size
            if(args->keySizeBits != args->maskSizeBits) {
                // print usage
                printf("Key and mask size mismatch\n");
                return -1;
            }
        }
    }

    return rv;
}

int parse_cmd(int argc, char *argv[], struct arg_info *args)
{
    int i = 0;
    int rv = 0;

    memset(args, 0, sizeof(struct arg_info));

    if (argc == 1){
        // print usage
        return -1;
    }

    if (argc == 2) {
        if (!strcmp(argv[1], "?") || !strcmp(argv[1], "h") || !strcmp(argv[1], "help")){
                // print usage
                return -1;
        }

        if (!strcmp(argv[1], "v") || !strcmp(argv[1], "version")) {
            args->printVersion = true;
            return 0;
        }

        return -1;
    }

    i = 2;
    if (!strcmp(argv[1], "table")) {
        rv = parse_table_cmd(argc, argv, i, args);
        return rv;
    }

    return rv;
}