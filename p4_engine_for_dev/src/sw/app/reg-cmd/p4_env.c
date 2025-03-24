#include "p4_env.h"

#include <string.h>

// read register
XilVitisNetP4ReturnType read_register(XilVitisNetP4EnvIf *EnvIfPtr, XilVitisNetP4AddressType Address, uint32_t *ReadValuePtr)
{
	struct xcmd_info xcmd;
	struct xcmd_reg *regcmd = &xcmd.req.reg;
	int rv;

	memset(&xcmd, 0, sizeof(struct xcmd_info));
	memset(regcmd, 0, sizeof(struct xcmd_reg));

	xcmd.op = XNL_CMD_REG_RD;
	xcmd.vf = 0;
	xcmd.if_bdf = strtoul("1000", NULL, 16);
	
	regcmd->bar = 2;
	regcmd->sflags |= XCMD_REG_F_BAR_SET;

	regcmd->reg = (unsigned int )Address;
	regcmd->sflags |= XCMD_REG_F_REG_SET;

	rv = xnl_proc_cmd(&xcmd);
	if (rv < 0) {
		printf("Error in processing read register command with ret = %d\n", rv);
		return XIL_VITIS_NET_P4_REGISTER_ERR_INVALID_INDEX;
	}

	*ReadValuePtr = regcmd->val;

	return XIL_VITIS_NET_P4_SUCCESS;
}

XilVitisNetP4ReturnType write_register(XilVitisNetP4EnvIf *EnvIfPtr, XilVitisNetP4AddressType Address, uint32_t WriteValue)
{
	struct xcmd_info xcmd;
	struct xcmd_reg *regcmd = &xcmd.req.reg;

	memset(&xcmd, 0, sizeof(struct xcmd_info));
	memset(regcmd, 0, sizeof(struct xcmd_reg));

	xcmd.op = XNL_CMD_REG_WRT;
	xcmd.vf = 0;
	xcmd.if_bdf = strtoul("1000", NULL, 16);

	regcmd->bar = 2;
	regcmd->sflags |= XCMD_REG_F_BAR_SET;

	regcmd->reg = (unsigned int )Address;
	regcmd->sflags |= XCMD_REG_F_REG_SET;

	regcmd->val = WriteValue;
	regcmd->sflags |= XCMD_REG_F_VAL_SET;

	int rv = xnl_proc_cmd(&xcmd);
	if (rv < 0) {
		printf("Error in processing write register command with ret = %d\n", rv);
		return XIL_VITIS_NET_P4_REGISTER_ERR_INVALID_INDEX;
	}

	return XIL_VITIS_NET_P4_SUCCESS;
}

XilVitisNetP4ReturnType log_error(XilVitisNetP4EnvIf *EnvIfPtr, const char *MessagePtr)
{
	if (EnvIfPtr == NULL)
	{
		return XIL_VITIS_NET_P4_GENERAL_ERR_NULL_PARAM;
	}

	if (MessagePtr == NULL)
	{
		return XIL_VITIS_NET_P4_GENERAL_ERR_NULL_PARAM;
	}

	printf("Error: %s\n", MessagePtr);

	return XIL_VITIS_NET_P4_SUCCESS;
}

XilVitisNetP4ReturnType log_info(XilVitisNetP4EnvIf *EnvIfPtr, const char *MessagePtr)
{
	if (EnvIfPtr == NULL)
	{
		return XIL_VITIS_NET_P4_GENERAL_ERR_NULL_PARAM;
	}

	if (MessagePtr == NULL)
	{
		return XIL_VITIS_NET_P4_GENERAL_ERR_NULL_PARAM;
	}

	printf("Info: %s\n", MessagePtr);

	return XIL_VITIS_NET_P4_SUCCESS;
}

XilVitisNetP4ReturnType XilVitisNetP4EnvIfPrep(XilVitisNetP4EnvIf *EnvIfPtr)
{
	if (EnvIfPtr == NULL)
	{
		return XIL_VITIS_NET_P4_GENERAL_ERR_NULL_PARAM;
	}

	EnvIfPtr->UserCtx = NULL;

	EnvIfPtr->WordWrite32 = write_register;
	EnvIfPtr->WordRead32 = read_register;
	EnvIfPtr->LogError = log_error;
	EnvIfPtr->LogInfo = log_info;

	return XIL_VITIS_NET_P4_SUCCESS;
}