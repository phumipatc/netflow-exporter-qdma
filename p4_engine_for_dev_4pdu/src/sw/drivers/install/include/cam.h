/////////////////////////////////////////////////////////////////////////////
//
// (c) Copyright 2018, 2023 Advanced Micro Devices, Inc. All rights reserved.
//
// This file contains confidential and proprietary information
// of AMD and is protected under U.S. and international copyright
// and other intellectual property laws.
//
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// AMD, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND AMD HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) AMD shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or AMD had been advised of the
// possibility of the same.
//
// CRITICAL APPLICATIONS
// AMD products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of AMD products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
//
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.
////////////////////////////////////////////////////////////
//


/**
 *
 * Public cam argument configuration and error codes
 *
 * @file cam.h
 *
 *
 * @addtogroup camarg Configuration Parameters and Error Codes
 * @{
 */

#ifndef _CAM_H_
#define _CAM_H_


#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Error numbers.
 *
 * These are the return codes from the bcam, tcam and stcam API functions.
 * If zero is returned, the function call was successful.
 *
 * Similar CCAM_ERROR_* constants are used by the hardware managed
 * CAMs; they are identically numbered.
 */
enum cam_errnos {
    CAM_OK                                 = 0,
    /* Non-fatal errors */
    CAM_ERROR_FULL                         = 1,
    CAM_ERROR_NO_OPEN                      = 2,
    CAM_ERROR_INVALID_ARG                  = 3,
    CAM_ERROR_WRONG_KEY_WIDTH              = 5,
    CAM_ERROR_TOO_MANY_INSTANCES           = 6,
    CAM_ERROR_WRONG_BIT_FIELD_MASK         = 7,
    CAM_ERROR_WRONG_CONST_FIELD_MASK       = 8,
    CAM_ERROR_WRONG_UNUSED_FIELD_MASK      = 9,
    CAM_ERROR_INVALID_TERNARY_FIELD_LEN    = 10,
    CAM_ERROR_WRONG_PRIO_WIDTH             = 11,
    CAM_ERROR_WRONG_MAX                    = 12,
    CAM_ERROR_DUPLICATE_FOUND              = 13,
    CAM_ERROR_WRONG_PREFIX                 = 14,
    CAM_ERROR_WRONG_PREFIX_MASK            = 15,
    CAM_ERROR_WRONG_RANGE                  = 16,
    CAM_ERROR_WRONG_RANGE_MASK             = 17,
    CAM_ERROR_KEY_NOT_FOUND                = 18,
    CAM_ERROR_WRONG_MIN                    = 19,
    CAM_ERROR_WRONG_PRIO                   = 20,
    CAM_ERROR_WRONG_LIST_LENGTH            = 21,
    CAM_ERROR_WRONG_NUMBER_OF_SLOTS        = 22,
    CAM_ERROR_INVALID_MEM_TYPE             = 23,
    CAM_ERROR_TOO_HIGH_FREQUENCY           = 24,
    CAM_ERROR_WRONG_TERNARY_MASK           = 25,
    CAM_ERROR_MASKED_KEY_BIT_IS_SET        = 26,
    CAM_ERROR_INVALID_MODE                 = 28,
    CAM_ERROR_WRONG_RESPONSE_WIDTH         = 29,

    /** Syntax error in format */
    CAM_ERROR_FORMAT_SYNTAX                = 30,

    /** Too many fields */
    CAM_ERROR_TOO_MANY_FIELDS              = 31,

    /** Too many ranges */
    CAM_ERROR_TOO_MANY_RANGES              = 32,

    /** Invalid range len */
    CAM_ERROR_INVALID_RANGE_LEN            = 33,

    /** Range start + len exceeds key len */
    CAM_ERROR_INVALID_RANGE_START          = 34,

    /** Invalid prefix len */
    CAM_ERROR_INVALID_PREFIX_LEN           = 35,

    /** Prefix start + len exceeds key len */
    CAM_ERROR_INVALID_PREFIX_START         = 36,

    /** Prefix key longer than prefix len */
    CAM_ERROR_INVALID_PREFIX_KEY           = 37,

    /** Invalid bit len */
    CAM_ERROR_INVALID_BIT_FIELD_LEN        = 38,

    /** Bit start + len exceeds key len */
    CAM_ERROR_INVALID_BIT_FIELD_START      = 39,

    /** Invalid const len */
    CAM_ERROR_INVALID_CONST_FIELD_LEN      = 40,

    /** Const start + len exceeds key len */
    CAM_ERROR_INVALID_CONST_FIELD_START    = 41,

    /** Invalid unused len */
    CAM_ERROR_INVALID_UNUSED_FIELD_LEN     = 42,

    /** Unused start + len exceeds key len */
    CAM_ERROR_INVALID_UNUSED_FIELD_START   = 43,

    /** Sum of all field lengths exceeds key len */
    CAM_ERROR_MAX_KEY_LEN_EXCEED           = 44,

    /** Prio width is too narrow or too wide */
    CAM_ERROR_INVALID_PRIO_AND_INDEX_WIDTH = 45,

    /** Too many logical or physical memory units */
    CAM_ERROR_TOO_MANY_UNITS               = 46,

    /** Error during tcam_insert. The entry has not been inserted since
     hardware resources are partially depleted. It
     is possible to continue using the instance, inserting entries using already
     allocated resources, updating entries, get entries or delete entries. */
    CAM_ERROR_NO_MASK                      = 47,

    /** The memory structure defined by the combined key and response
     * width is too wide */
    CAM_ERROR_INVALID_MEMORY_WIDTH         = 48,

    /** Unsupported Computational BCAM command */
    CAM_ERROR_UNSUPPORTED_COMMAND          = 49,

    /** Computational BCAM environment error at transport layer or IP
     * non responsive */
    CAM_ERROR_ENVIRONMENT                  = 50,

    /** API request for an unsupported cam type */
    CAM_ERROR_UNSUPPORTED_CAM_TYPE         = 51,

    /** Null pointer */
    CAM_ERROR_NULL_POINTER                 = 52,

    /** Too many pseudo-channels (PCs) are used */
    CAM_ERROR_TOO_MANY_PCS                 = 53,

    /** Hardware configuration parameters do not match software settings */
    CAM_ERROR_CONFIGURATION                = 54,

    /** Computational BCAM FSM reporting busy */
    CAM_ERROR_ENVIRONMENT_FSMBUSY          = 55,

    /** Computational CAM poll timeout
     *
     * The hardware managed CAM took too long to execute an operation.  The operation is still
     * pending and software should treat this as fatal. This can happen if lookup requests are
     * arriving too quickly and leaving no memory bandwidth available to service requests from
     * software. To guarantee that software operations succeed, do not submit lookups to the
     * CAM more quickly than the rate chosen when the IP block was configured. */
    CAM_ERROR_ENVIRONMENT_POLLED_OUT = 56,

    /** Virtual BCAM has zero segments */
    CAM_ERROR_SEGMENT_COUNT_ZERO = 57,

    /** Unsupported Virtual container command */
    CAM_ERROR_VC_UNSUPPORTED_COMMAND       = 58,

    /** Wrong virtual BCAM identifier */
    CAM_ERROR_WRONG_VIRTUAL_CAM_ID         = 59,

    /** Wrong segment number */
    CAM_ERROR_WRONG_SEGMENT_NUMBER         = 60,

    /** Too many RAM instances are used */
    CAM_ERROR_TOO_MANY_RAMS                = 61,

    /** Shadow and HW does not match */
    CAM_ERROR_FOUND_IN_SHADOW_BUT_NOT_IN_HW = 62,

    /** The max heap for tcam is not sufficiently large */
    CAM_ERROR_TOO_SMALL_HEAP               = 63,

    /** The RAM is not large enough to be divided into virtual segments */
    CAM_ERROR_RAM_TOO_SMALL                = 64,

    /** Still contains entries */
    CAM_ERROR_NOT_EMPTY                    = 65,

    /** The hardware was not generated with statistics enabled */
    CAM_ERROR_STATISTICS_NOT_AVAILABLE     = 66,

    /** Too many key entries */
    CAM_ERROR_TOO_MANY_ENTRIES             = 67,    

    /** Format string complexity too high */
    CAM_ERROR_FORMAT_COMPLEXITY            = 69,

    /** The user's selected pseudo-channel count is invalid. */
    CAM_ERROR_INVALID_USER_PCS             = 70,

    /* Fatal error codes: CAM_ERROR_FATAL_BASE_START <= error code < CAM_ERROR_FATAL_BASE_END */
    /* The instance is not working anymore */

    CAM_ERROR_FATAL_BASE_START             = 100,
    CAM_ERROR_FATAL_BASE_END = 199, /* No error codes have a higher number */
    CAM_ERROR_NOMEM                        = CAM_ERROR_FATAL_BASE_END,
    CAM_ERROR_MALLOC_FAILED                = CAM_ERROR_FATAL_BASE_END - 1,

};


/**
 * Debug flags to enable debug printouts and hardware verification.
 */
#define CAM_DEBUG_NONE               0x00000000  /* Quiet, only software error messages are printed */
#define CAM_DEBUG_NO_ERROR_MSG       0x00000001  /* Disable software error messages printout */
#define CAM_DEBUG_ARGS               0x00000002  /* Software echoes input arguments */
#define CAM_DEBUG_VERIFY_WR          0x00000004  /* Software immediately reads back written data from hardware
                                                    for verification. Mismatching data is reported with error
                                                    message. */
#define CAM_DEBUG_VERIFY_SHADOW      0x00000008  /* 'get_by_response' and 'get_by_key' operations read data from
                                                    hardware and verifies software shadow data */
#define CAM_DEBUG_VERBOSE_VERIFY     0x00000010  /* Enables printout of all verify operations, including correct
                                                    compare. Applies to CAM_DEBUG_VERIFY_WR, CAM_DEBUG_VERIFY_SHADOW,
                                                    and CAM_DEBUG_VERIFY_CONFIG. */
#define CAM_DEBUG_SKIP_MEM_INIT      0x00000020  /* Skip memory initialization, useful to speedup Verilog
                                                    simulation */
#define CAM_DEBUG_CONFIG             0x00000040  /* Enable printout of configuration parameters for both software
                                                    and Verilog hardware simulation */
#define CAM_DEBUG_VERIFY_CONFIG      0x00000080  /* DEPRECATED: Configuration parameters are automatically read from
                                                    hardware for verification */
#define CAM_DEBUG_KEY_MASKING        0x00000100  /* Enable error check for the presence of key value '1' in masked
                                                    (wildcarded) bit position. Applies stcam and tcam input arguments. */
#define CAM_DEBUG_STATS              0x00000200  /* Enable statistics printout in the 'bcam_destroy' and
                                                    'stcam_destroy' functions. */
#define CAM_DEBUG_SEGMENTS           0x00000400  /* Software prints segment map for virtualized bcam (vbcam) */
#define CAM_DEBUG_SKIP_VERIFY_CONFIG 0x00000800  /* Skip verification of hardware/software configuration parameters */
#define CAM_DEBUG_SET_COVER          0x00001000  /* Software prints heap and set cover information for tcam */
#define CAM_DEBUG_CONFIG_ARGS        0x00002000  /* Software prints cam_arg values before creating the instance */
#define CAM_DEBUG_HW_WR              0x00010000  /* Verilog hardware prints write operations */
#define CAM_DEBUG_HW_RD              0x00020000  /* Verilog hardware prints read operations */
#define CAM_DEBUG_HW_LOOKUP          0x00040000  /* Verilog hardware prints lookup operations */

/**
 * Optimization flags
 */
#define CAM_OPTIMIZE_NONE        0x00000000  /* No optimizations*/
#define CAM_OPTIMIZE_RAM         0x00000001  /* The default hw generation balances logic and ram.
                                                Use this flag to reduce ram cost with a potentially higher logic cost.
                                                Reducing both ram and logic is not possible. Not supported for dram */
#define CAM_OPTIMIZE_LOGIC       0x00000002  /* The default hw generation balances logic and ram.
                                                Use this flag to reduce logic cost with a potentially higher ram cost.
                                                Reducing both ram and logic is not possible. Not supported for dram */
#define CAM_OPTIMIZE_ENTRIES     0x00000004  /* This flag is only valid for stcam and bcam.
                                                The default behavior is to disallow more than num_entries to be
                                                inserted. This flag allows additional insertions if there is spare memory.
                                                When memory was allocated for num_entries, quantification effects might
                                                have created spare memory. For stcam, inserting excessive entries might
                                                compromise the number of masks that can be inserted. The stcam
                                                dimensioning algorithm uses a worst case distribution of entries over
                                                masks. The actual number of entries that can be inserted might
                                                be much higher than num_entries if the distribution is favorable.  */
#define CAM_OPTIMIZE_MASKS       0x00000008  /* This flag is only valid for stcam. The default behavior is to disallow more than num_masks to be
                                                inserted. This flag allows
                                                additional mask insertions. Inserting excessive masks may compromise
                                                how many entries that can be inserted. The stcam
                                                dimensioning algorithm uses a worst case distribution of entries over
                                                masks. The actual number of masks that can be inserted might
                                                be much higher than num_masks if the distribution is favorable.*/



#define CAM_MAX_KEY_WIDTH                           992
#define CAM_MAX_RESPONSE_WIDTH                      1024

/*
 * Common structures for the get_stat functions
 */

/*
 * Only valid for URAM/BRAM cams. The response is always valid. If status indicates a match the response contains the response data of the
 * the matching entry.
 * If there is no match, response contains the default response data. key_width bits of the key are valid. response_width bits
 * of the response are valid.
 * During a hw lookup operation many memory reads take place,
 * if a double bit error is identified the double bit error bit is set and the content in the affected memories is disregarded.
 * If a match and double bit error is indicated at the same time for a bcam, the match is still always correct and can be trusted.
 * If a match and double bit error is indicated at the same time for a tcam/stcam, there might be a better match but this is unknown
 * due to the double bit error. Only if the user can guarantee non-overlapping entries the match can be considered correct.
 */
struct cam_last_lookup {
    uint8_t key[(CAM_MAX_KEY_WIDTH + 7) / 8];  // The last lookup key
    uint8_t response[(CAM_MAX_RESPONSE_WIDTH + 7) / 8];
    uint32_t status;  // Bit 0: Match, Bit 1: Double bit error
};

struct cam_sw {
    uint32_t num_entries; // this is the total
    uint32_t narrow_num_entries; // Only used in mixed mode--the number of narrow entries.
    // The following equation is always true: wide entries + narrow entries = num_entries
    uint64_t num_inserts;
    uint64_t num_updates;
    uint64_t num_deletes;
    uint32_t failed_inserts;
    uint32_t failed_updates;
    uint32_t failed_deletes;
    uint64_t num_collisions; // bcam/stcam statistics
    uint16_t max_collisions; // bcam/stcam statistics
    uint8_t num_used_masks; // Only for stcam
    uint64_t num_shadow_writes;  // bcam/stcam statistics
};

typedef struct cam_arg_t cam_arg_t;

/**
 * Creates cam_arg which is used to pass arguments during the creation of a vbcam, bcam, tcam or stcam instance.
 * If the function is successful, 0 is returned. If the function fails an error code is returned. The function
 * uses malloc to allocate memory. The malloc cannot be replaced by the function specified by
 * cam_arg_set_malloc_function. If malloc must be replaced use cam_arg_size and cam_arg_init instead of
 * cam_arg_create.
 *
 * @param[out]  out_cam_arg   The newly created cam_arg. If successful memory was allocated.
 *                            If unsuccessful, no memory was allocated and out_cam_arg is left unchanged.
 *
 * @return                    Returns 0 for success, otherwise the error code.
 *
 */
int cam_arg_create(cam_arg_t **out_cam_arg);


/**
 * This function should only be used if cam_arg_create should be replaced.
 * This would be the case if the standard malloc used by cam_arg_create needs to be replaced. The function
 * sets the same default values to cam_arg as cam_arg_create. out_cam_arg is allocated outside of the function.
 *
 * @param[out]  out_cam_arg      Pointer to cam_arg
 *
 */
void cam_arg_init(cam_arg_t *out_cam_arg);


/**
 *  This function should only be used if cam_arg_create should be replaced.
 *
 * @return  size   Returns the size in bytes of the cam_arg structure. See cam_arg_init for more information.
 *
 */
size_t cam_arg_size(void);


/**
 * Destroy cam_arg. The memory allocated by cam_arg_create is released. The stdlib free function is used.
 * The free function is not replaced by the function specified by the cam_arg_set_free_function.
 *
 * @param[in]  cam_arg   Pointer to cam_arg.
 *
 */
void cam_arg_destroy(cam_arg_t *cam_arg);


/**
 * Sets the format string of cam_arg. If the cam_arg_set_format is unsuccessful, the format is not set.
 * The function is only used for tcam. This function shall not be called for bcam or stcam.
 * The format string is used to specify the location and size of range fields, since
 * ternary matching hardware is replaced by range matching hardware for these fields.
 * Furthermore the format string is used to determine key width and to guide the tcam API software.
 * The entry size = 2 x key width + response width + priority width + 1 cannot exceed 2048 bits.
 * The default format of cam_arg is "/0".
 *
 * @param[in]   cam_arg Pointer to cam_arg
 * @param[in]   format  String describing the format of all entries
 *                      of a tcam instance. An entry consists of
 *                      several fields. Fields are separated by ':'.
 *                      The string is read left to right. The first
 *                      field will correspond to the least significant bits
 *                      of the key. The key is specified as little-endian.
 *                      Each field is specified as: \<field len\>
 *                      \<field type\>. The following field types and
 *                      lengths are supported. There are no alignment
 *                      restrictions for the fields.
 *                      - r - Range, most significant byte of field is
 *                          in most significant byte of key.
 *                          The allowed length of the field is 1 to 16 bits.
 *                          Maximum 8 ranges per format
 *                      - p - Prefix, most significant byte of field is in
 *                          most significant byte of key.
 *                         The allowed length of the field is 1 to 128 bits.
 *                      - b - bit field.
 *                          The allowed length of the field is 1 to 128 bits.
 *                      - t - Ternary field.
 *                          The allowed length of the field is 2 to 16 bits.
 *                      - c - Bit field with mask always set.
 *                          The allowed length of the field is 1 to 128 bits.
 *                      - u - Unused bit field with mask always cleared.
 *                          The allowed length of the field is 1 to 128 bits.
 *
 *                      For example, the format "16r:16r:64p:64p:48b:48b"
 *                      contains 2 x 16 bit range fields for port numbers,
 *                      2 x 64 bit prefix fields for IPv6 addresses and
 *                      2 x 48 bit fields for MAC addresses. The 16r field is
 *                      located in the 16 least significant bits of the key
 *
 * @return              Returns 0 for success, otherwise the error code.
 *
 */
int cam_arg_set_format(cam_arg_t *cam_arg, char *format);


/**
 * Sets the instance context pointer of cam_arg. The context is user-defined and will always be passed
 * when the following functions are invoked:
 * hw write, hw read, hw_write_sequence_start, hw_write_sequence_end, info print and error print.
 * An example of usage of context could be for addressing multiple cam instances.
 * Each instance would be given a unique base address using cam_arg_set_inst_ctx.
 * The hw read/write functions would then add the base address from the context before accessing the
 * hardware.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  inst_ctx             Pointer to the instance context.
 *
 */
void cam_arg_set_inst_ctx(cam_arg_t *cam_arg, void *inst_ctx);


/**
 * Sets the hardware write function of cam_arg. The hw write function will be called by the
 * cam instance to write to the HW
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  hw_write_function    Pointer to the hw write function. This function is provided by the user
 *
 */
void cam_arg_set_hw_write_function(cam_arg_t *cam_arg, void (*hw_write_function)(void*, uint32_t, uint32_t));


/**
 * Sets the hardware read function of cam_arg. The hw read function will be called by the
 * cam instance to read from the HW
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  hw_read_function     Pointer to the hw read function. This function is provided by the user
 *
 */
void cam_arg_set_hw_read_function(cam_arg_t *cam_arg, void (*hw_read_function)(void*, uint32_t, uint32_t*));


/**
 * Sets a pair of hardware read/write functions. This variant is used by drivers which communicate
 * with multiple hardware blocks. Calling this function with hw_block == 0 is equivalent to calling
 * cam_arg_set_hw_write_function() and cam_arg_set_hw_read_function().
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  hw_block             Index of the hardware block (refer to driver documentation).
 * @param[in]  hw_write_function    Pointer to the hw write function.
 * @param[in]  hw_read_function     Pointer to the hw read function. This function is provided by the user
 *
 * @return                          0 for success.
 *
 *                                  CAM_ERROR_INVALID_ARG if the value of 'hw_block' is out of range.
 */
int cam_arg_set_hw_io(cam_arg_t *cam_arg,
                      unsigned hw_block,
                      void (*hw_write_function)(void*, uint32_t, uint32_t),
                      void (*hw_read_function)(void*, uint32_t, uint32_t*));


/**
 * Sets the supported number of entries to cam_arg. This is the number of entries the cam instance supports.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  num_entries          The number of supported entries the instance can store before it becomes full
 *
 */
void cam_arg_set_num_entries(cam_arg_t *cam_arg, uint32_t num_entries);


/**
 * Sets the lookup rate of the instance to cam_arg. This is the supported lookup rate of the instance.
 * In order to save resources it is important not to set the lookup rate higher than required.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  lookup_rate          The lookup rate of the instance expressed in Mlookups/s
 *
 */
void cam_arg_set_engine_lookup_rate(struct cam_arg_t *cam_arg, float lookup_rate);


/**
 * This function should not be used for dram.
 * Sets the frequency of the lookup interface to cam_arg.
 * This is the clock frequency of the lookup request and response interfaces.
 * The frequency of the lookup interface must be at least as high as the lookup rate.
 * Sometimes a higher frequency is used, for example:
 * Lookup interface frequency == Lookup rate       (A lookup can be issued every clock cycle)
 * Lookup interface frequency == 2 * Lookup rate   (A lookup can be issued every second cycle)
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  freq                 The frequency of the instance expressed in MHz
 *
 */
void cam_arg_set_lookup_interface_freq(struct cam_arg_t *cam_arg, float freq);


/**
 * This function should not be used for dram.
 * Sets the RAM clock frequency of the instance to cam_arg.
 *
 * The RAM clock defines the clock frequency of the memories and the internal data path.
 * A high RAM clock frequency enables time division of the hardware resources, leading to significant
 * savings.
 * The amount of time division possible is calculated as:
 * RAM clock frequency / lookup rate, rounded downwards to the nearest power of two.
 *
 * Example:
 * Lookup rate = 150, Lookup interface frequency = 330
 * RAM frequency = 600 -> Time division = 600 / 150 = 4
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  freq                 The RAM clock frequency expressed in MHz.
 *
 */
void cam_arg_set_ram_freq(struct cam_arg_t *cam_arg, float freq);


/**
 * Sets the response width of the instance to cam_arg. This is the supported width of response.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  response_width       The response width expressed in number of bits (1-1024).
 *                                  The following limitations apply:
 *                                  For vbcam/bcam, key width + response width + 1 cannot exceed 1024 (dram), 2048 (bram/uram) bits.
 *                                  For cbcam,      key width + response width + 1 cannot exceed 2048 bits.
 *                                  For stcam,      key width + response width + priority width + 1 cannot exceed 2048 bits.
 *                                  For tcam,     2*key width + response width + priority width + 1 cannot exceed 2048 bits.
 *
 */
void cam_arg_set_response_width(struct cam_arg_t *cam_arg, uint16_t response_width);


/**
 * Forces a wider priority width of the instance to cam_arg. This function is not applicable
 * for vbcam/bcam instances. The default value is a priority width
 * corresponding to the number of entries for tcam, and the number of masks for stcam. In some scenarios a
 * wider priority width is useful.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  prio_width           The prio width is expressed in number of bits.
 *                                  The legal range for stcam is clog2(num_masks) - 32.
 *                                  The legal range for tcam is clog2(num_entries) - 32.
 *                                  The priority is used to determine the winning match when multiple matches occurs.
 *                                  To represent the priority value a certain priority width is required.
 *                                  The following limitations apply:
 *                                  For stcam,  key width + response width + priority width + 1 cannot exceed 2048 bits.
 *                                  For tcam, 2*key width + response width + priority width + 1 cannot exceed 2048 bits.
 *
 */
void cam_arg_force_prio_width(struct cam_arg_t *cam_arg, uint8_t prio_width);


/**
 * Forces the dimensioning process to use the given number of pseudo-channels in preference to its
 * calculated default. This is used by the Vivado IP configuration wizard when the user manually
 * overrides the driver's chosen number of PCs.
 *
 * HBM only.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  num_pcs              Number of pseudo-channels to use. Set to 0 to use driver's value.
 */
void cam_arg_force_num_pcs(struct cam_arg_t *cam_arg, unsigned num_pcs);


/**
 * This function is only used for vbcam, bcam and stcam. For tcam the format string should be used instead.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  key_width            The key width expressed in number of bits (10-992).
 *                                  The following limitations apply:
 *                                  For bcam/vbcam, key width + response width + 1 cannot exceed 1024 (dram), 2048 (bram/uram) bits.
 *                                  For cbcam,      key width + response width + 1 cannot exceed 2048 bits.
 *                                  For stcam,      key width + response width + priority width + 1 cannot exceed 2048 bits.
 *
 */
void cam_arg_set_key_width(struct cam_arg_t *cam_arg, uint16_t key_width);


/**
 * Set fingerprint width (DRAM BCAM only). Defaults to zero (fingerprints disabled).
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  fingerprint_width    The fingerprint width expressed in number of bits (0-16).
 */
void cam_arg_set_fingerprint_width(struct cam_arg_t *cam_arg, uint16_t fingerprint_width);


/**
 * This function is only used for stcam.
 * An stcam is dimensioned to support a specific number of unique masks and a specific number of entries. The dimensioning is based
 * on a worst case scenario. The stcam memory management algorithm allocates memory dynamically for each unique mask. All entries can use
 * the same mask or entries can use different masks. The memory dimensioning guarantees that the specified number of masks and
 * the specified number of entries will fit in the memory simultaneously.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  num_masks            The number of unique masks.
 *
 */
void cam_arg_set_num_masks(struct cam_arg_t *cam_arg, uint8_t num_masks);


/**
 * This function is not used for dram.
 * Overrides the automatic memory dimensioning. A cam consists of a number of memory units. The automatic
 * memory dimensioning calculates the number of required memory units to store all entries and masks.
 * This function is used to override the automatic dimensioning and forces the number of memory units to a specified
 * value. This function can be used for optimization in certain cases when the automatic
 * dimensioning provides too much headroom.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  num_units            The number of memory units (1-256).
 *
 */
void cam_arg_force_num_units(struct cam_arg_t *cam_arg, uint16_t num_units);


/**
 * This function is not used for dram.
 * Forces the instance to use either URAM or BRAM. Based on the cam_arg parameters an optimal solution in terms of
 * hardware resources is calculated. This solution is an instance using either BRAM or URAM. In some scenarios the
 * usage of a certain memory type might be constrained and then the solution can be forced to use a certain memory type
 * even though it is not the optimal solution.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  uram                 If true uram is forced to be used. If false bram is forced to be used.
 *
 */
void cam_arg_force_mem_type(struct cam_arg_t *cam_arg, bool uram);


/**
 * Set the maximum number of BRAMs available in the chosen target device.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  max_num_brams        Maximum number of BRAMs in the device.
 *
 */
void cam_arg_set_max_num_brams(struct cam_arg_t *cam_arg, uint16_t max_num_brams);


/**
 * Set the maximum number of URAMs available in the chosen target device.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  max_num_urams        Maximum number of URAMs in the device.
 *
 */
void cam_arg_set_max_num_urams(struct cam_arg_t *cam_arg, uint16_t max_num_urams);


/**
 * Set the maximum height of placement macro (RAM column), measured in clock regions.
 * The maximum RAM column height varies depending on the chosen target devices.
 * This parameter provides control over RAM column height versus number of required RAM columns.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  max_macro_height     Maximum height of placement macro (1-device limit), measured in clock regions.
 *
 */
void cam_arg_set_max_macro_height(struct cam_arg_t *cam_arg, uint8_t max_macro_height);


/**
 * Set the target device architecure.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  versal               Target Versal if true. Target UltraScale if false.
 *
 */
void cam_arg_set_device_arch(struct cam_arg_t *cam_arg, bool versal);


/**
 * This function is only used for a vbcam/bcam using HBM.
 * If this function is called, the bcam uses HBM instead of URAM/BRAM or DDR-DRAM.
 * Both DDR-DRAM and HBM cannot be forced.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 *
 */
void cam_arg_force_hbm(struct cam_arg_t *cam_arg);


/**
 * This function can only be used for a vbcam/bcam using dram. This function activates mixed mode.
 * In mixed mode, wide and narrow entries are efficiently stored together in the same memory.
 * The wide entry is 1024 or 512 bits wide. The narrow entry is half the width of the wide entry.
 * key_width + response_width + 2 is rounded upwards to 512 or 1024 bits for the wide entry.
 * narrow_key_width + response_width + 2 is rounded upwards to 256 or 512 bits for the narrow entry.
 * Both these conditions must be fulfilled:
 * 1: key_width >= narrow_key_width and
 * 2: narrow entry width = wide entry width / 2 .
 * This function sets the key width of the narrow entry. The key width of the
 * wide entry is specified using cam_arg_set_key_width.
 *
 * @param[in]  cam_arg                  Pointer to cam_arg.
 * @param[in]  narrow_key_width         The key width for the narrow entry
 *
 */
void cam_arg_set_narrow_key_width(struct cam_arg_t *cam_arg, uint16_t narrow_key_width);


/**
 * This function can only be used for vbcam/bcam.
 * Sets the maximum number of allowed hw writes for the bcam_insert/vbcam_insert function.
 * A hw write occurs every time the hw write function is called.
 * Sometimes the transport method between the driver and the hw requires that all writes are
 * stored in a packet of limited size. This function can be used to limit the number of hw writes
 * so they fit in a single packet. Limiting the number of allowed HW writes may cause the cam to become
 * full earlier than expected. When the cam becomes full due to the hw writes limit, it might still be possible to
 * insert another entry successfully. If this function is called, the number of hw writes is limited. If this
 * function is not called or called with max_hw_writes = 0, no such hw write limitation exists.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  max_hw_writes        Maximum number of allowed hw writes
 *
 */
void cam_arg_set_max_hw_writes(struct cam_arg_t *cam_arg, uint16_t max_hw_writes);


/**
 * Sets the lookup response flow control configuration.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  flow_control         False = Response flow control off (fixed lookup rate & latency)
 *                                  True  = Response flow control on (variable lookup rate & latency)
 *
 */
void cam_arg_set_flow_control(struct cam_arg_t *cam_arg, bool flow_control);


/**
 * Sets the aging configuration (only used for cbcam and cstcam).
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  aging                False = Aging disabled (entries can only be removed by deleting them)
 *                                  True  = Aging enabled (old entries are invalidated or overwritten)
 *
 */
void cam_arg_set_aging(struct cam_arg_t *cam_arg, bool aging);


/**
 * Sets the default response. When a key is looked up in the data plane and there is no match,
 * the default response is output together with a no match indication. If the default response is not set
 * all bits are cleared as default. The width of the default response is specified by the
 * cam_arg_set_response_width function. cam_arg_set_response_width must be called prior to this function
 * otherwise the number of bits t copy from the input argument is unknown and zero bytes will be copied.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  default_response     The default response
 *
 */
void cam_arg_set_default_response(struct cam_arg_t *cam_arg, const uint8_t *default_response);


/**
 * This function is only used if mixed mode is activated, see cam_arg_set_narrow_key_width.
 * This function sets the narrow default response.
 * When a narrow key is looked up in the data plane and there is a no match,
 * the narrow default response is output together with a no match indication. If the narrow default response
 * is not set, that is if this function is not called, all bits are cleared as default.
 * The width of the narrow default response is specified by the
 * cam_arg_set_response_width function. cam_arg_set_response_width must be called prior to this function
 * otherwise the number of bits to copy from the input argument is unknown and zero bytes will be copied.
 *
 * @param[in]  cam_arg                      Pointer to cam_arg.
 * @param[in]  narrow_default_response      The narrow default response
 *
 */
void cam_arg_set_narrow_default_response(struct cam_arg_t *cam_arg, const uint8_t *narrow_default_response);


/**
 * This function can only be used for a vbcam.
 * Sets a uniquie identifer (vcid) for each virtualised bcam (vbcam)
 *
 * @param[in]  cam_arg                      Pointer to cam_arg
 * @param[in]  vcid                         The unique identifier of the vbcam
 *
 */
void cam_arg_set_vcid(struct cam_arg_t* cam_arg, uint8_t vcid);


/**
 * This function can only be used for a vbcam.
 * Each vbcam uses one or multiple address segments. This function should be called multiple times
 * if many segments should be used for the vbcam.
 * A segment can only be used by one vbcam at a time otherwise the behavior is undefined.
 * This needs to be enforced by the user.
 *
 * @param[in]  cam_arg       Pointer to cam_arg
 * @param[in]  segment_id    segment num (0-255) allocated to the vbcam
  *
 */
void cam_arg_set_seg(struct cam_arg_t* cam_arg, uint16_t segment_id);


/**
 * This function is only applicable for vbcam.
 * Sets the start and end functions for the hw write sequence. The hw registers use indirect addressing since the hw bus is narrow.
 * For this reason, key and response updates require a sequence of multiple hw writes to finish.
 * If the cam is used by multiple threads as would be the typical use case for vbcams, the write sequence must be
 * protected from being interrupted by another thread's write sequence. The start_function and
 * end_function arguments are called when the sequence is started and ended. These functions can for instance
 * be used to lock and unlock a mutex common for all threads.
 * The argument to the start_function and end_function is the context as specified by the
 * cam_arg_set_inst_ctx.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  start_function       Pointer to the start function. This function is provided by the user
 * @param[in]  end_function         Pointer to the end function. This function is provided by the user
 *
 */
void cam_arg_set_hw_write_sequence_functions(cam_arg_t *cam_arg, void (*start_function)(void*),
        void (*end_function)(void*));


/**
 * Sets the debug flags of cam_arg. The debug flags control how much information is displayed
 * for information, warning and error purposes.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  debug_flags          Bit mask value, every bit corresponds to a class of debug messages.
 *
 */
void cam_arg_set_debug_flags(cam_arg_t *cam_arg, uint32_t debug_flags);


/**
 * Sets the optimization flags of cam_arg. The optimization flags specifies how the hardware is optimized. E.g.
 * optimized to reduce either logic or memory
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  optimization_flags   Bit mask value.
 *
 */
void cam_arg_set_optimization_flags(cam_arg_t *cam_arg, uint32_t optimization_flags);


/**
 * Enable options for bcam. This function is only applicable for bcam. The bcam functions are variadic C functions.
 * If options is enabled, the bcam expects one additional
 * argument containing the options
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 *
 */
void cam_arg_enable_options(cam_arg_t *cam_arg);


/**
 * This function is only used for stcam/bcam using asic ram.
 * The size of the asic ram is set by cam_arg_set_ram_size
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 *
 */
void cam_arg_force_asic_ram(struct cam_arg_t *cam_arg);


/**
 * This function is only used for a vbcam/bcam using DDR-DRAM.
 * If this function is called, the bcam uses DDR-DRAM instead of URAM/BRAM.
 * Both DDR-DRAM and HBM cannot be forced.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 *
 */
void cam_arg_force_dram(struct cam_arg_t *cam_arg);


/**
 * This function is used to specify the size of the ddr-dram in KB or the size of the asic ram in number of addresses per ram.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  size                 Memory size. The unit is different depending on if it is ddr-dram or asic ram.
 *                                  E.g. size = 1024 = 1MB of dram for ddr-dram.
 *                                  size = 512 corresponds to 512 addresses per ram for asic ram.
 *                                  In both cases the size must be a power of 2.
 *
 */
void cam_arg_set_ram_size(struct cam_arg_t *cam_arg, uint32_t size);


/**
 * This function is only used for dram bcam.
 * The default hash function is Murmur3. The hash function can be changed by using this function.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  function             The hash function
 *
 */
void cam_arg_set_hash_function(struct cam_arg_t *cam_arg, uint8_t function);


/**
 * Set the SipHash key. Using a secret value for this key offers some
 * protection against hash flooding attacks.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  k0                   Least significant 64 bits of key.
 * @param[in]  k1                   Most significant 64 bits of key.
 */
void cam_arg_set_siphash_key(struct cam_arg_t *cam_arg, uint64_t k0, uint64_t k1);

/**
 * Only valid for ddr-dram BCAMs. This function is used to specify the number of banks the bcam
 * uses. Default is 8 banks
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  num_banks            Only 8 and 4 are allowed
 *
 */
void cam_arg_set_num_banks(struct cam_arg_t *cam_arg, uint8_t num_banks);


/**
 * Only valid for ddr-dram BCAMs. This function is used to specify the amount of data (in bits) that are transferred
 * on the dram channel using a single read/write access. The value is the product of the
 * burst length and physical data width. Default is 512 bits.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  width                 Only 256 and 512 are allowed.
 *
 */
void cam_arg_set_channel_width(struct cam_arg_t *cam_arg, uint16_t width);



/**
 * Set the replication factor. By storing the same data in multiple physical memories, multiple read
 * operations can access it at the same time, which can improve lookup performance at the expense of
 * resource usage. If this function is not called then cam_config_create() will calculate a suitable
 * replication factor automatically.
 *
 * Not needed at run time.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  replication          The number of copies of the data to store.
 *
 */
void cam_arg_set_replication(struct cam_arg_t *cam_arg, unsigned replication);



/**
 * Set the update mode. There are two types of DBCAM: software-managed and hardware-managed. They
 * differ in the method used to insert new items and this option adjusts the dimensioning
 * calculation to allow for this difference.
 *
 * If not set, defaults to SOFTWARE.
 *
 * Not needed at run time.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  update_mode          The update mode to use.
 *
 */

enum cam_arg_update_mode {
    CAM_UPDATE_SOFTWARE = 0,
    CAM_UPDATE_HARDWARE = 1
};

void cam_arg_set_update_mode(struct cam_arg_t *cam_arg, enum cam_arg_update_mode update_mode);



/**
 * This function is only used for dram-bcam. The DRAM controller cannot support atomicity for wider data than its transaction size.
 * This function creates atomicity with generation numbers per transaction size or narrower.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  granularity          default is 0. Supported values 0 and 256
 *
 */
void cam_arg_set_generation_number_granularity(struct cam_arg_t *cam_arg, uint16_t granularity);


/**
 * This function is used to let the create function calculate the heap size before allocating it.
 * Instead of creating the driver, the create function calculates the maximum heap size it
 * will use during its lifetime.
 * When a CAM driver is created, all heap allocations are performed by the create function except
 * for the TCAM which performs allocations in other functions as well. For the TCAM,
 * the returned heap size also includes heap size which will be allocated in other functions.
 * The create function returns an error code or the calculated heap size. If it is
 * an error code or the heap size that is returned is determined by comparing with
 * CAM_ERROR_FATAL_BASE_END. If the return code has a greater value, it is the heap size that is
 * returned. The returned heap size is in Bytes.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  calculate            default is false
 *
 */
void cam_arg_calc_heap_size(struct cam_arg_t *cam_arg, bool calculate);


/**
 * Sets the error print function of cam_arg. The error print function will be called by the
 * cam instance to print error messages. The default error print function is printing to stderr.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  error_print_function Pointer to the error print function. This function is provided by the user
 *
 */
void cam_arg_set_error_print_function(struct cam_arg_t *cam_arg, void (*error_print_function)(void *, char*));


/**
 * Sets the info print function of cam_arg. The info print function will be called by the
 * cam instance to print informational messages. The default info print function is printing to stdout.
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  info_print_function  Pointer to the info print function. This function is provided by the user
 *
 */
void cam_arg_set_info_print_function(struct cam_arg_t *cam_arg, void (*info_print_function)(void *, char*));


/**
 * Sets the malloc function of cam_arg. The malloc function will be called by the
 * cam instance to allocate memory on the heap of size bytes. It returns a pointer to this memory.
 * The default malloc is stdlib malloc
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  malloc_function      Pointer to the malloc function. This function is provided by the user
 *
 */
void cam_arg_set_malloc_function(struct cam_arg_t* cam_arg, void* (*malloc_function)(size_t size));


/**
 * Sets the posix_memalign function of cam_arg. The posix_memalaign function will be called by the
 * cam instance to allocate memory on the heap of size bytes aligned to 64 Bytes which corresponds to a cache line.
 * This might improve the performance of the shadow memory.
 * It returns a result code. If the posix_memalign function is not set, the calloc function will be used instead.
 *
 * @param[in]  cam_arg                     Pointer to cam_arg.
 * @param[in]  posix_memalign_function      Pointer to the posix_memalign function. This function is provided by the user
 *
 */
void cam_arg_set_posix_memalign_function(struct cam_arg_t* cam_arg,
        int (*posix_memalign_function)(void** ptr, size_t align_size, size_t num));


/**
 * Sets the realloc function of cam_arg. The realloc function will be called by the
 * cam instance to re-allocate memory on the heap of size bytes. It returns a pointer to this memory.
 * The default realloc is stdlib realloc. Realloc is only used by tcam instances
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  realloc_function     Pointer to the realloc function. This function is provided by the user
 *
 */
void cam_arg_set_realloc_function(struct cam_arg_t* cam_arg,
        void* (*realloc_function)(void *ptr, size_t size));


/**
 * Sets the calloc function of cam_arg. The calloc function will be called by the
 * cam instance to allocate memory for an array of num elements of size bytes each and returns a pointer
 * to the allocated memory  on the heap. The memory is also set to zero and a pointer to this memory is returned.
 * The default calloc is stdlib calloc
 *
 * @param[in]  cam_arg              Pointer to cam_arg.
 * @param[in]  calloc_function      Pointer to the calloc function. This function is provided by the user
 *
 */
void cam_arg_set_calloc_function(struct cam_arg_t* cam_arg, void* (*calloc_function)(size_t num, size_t size));


/**
 * Sets the free function of cam_arg. This will be called by the cam instance to free up heap memory
 * that was allocated by the malloc and calloc functions.
 * The default free is stdlib free.
 *
 * @param[in]  cam_arg         Pointer to cam_arg.
 * @param[in]  free_function   Pointer to the free function. This function is provided by the user
 *
 */
void cam_arg_set_free_function(struct cam_arg_t* cam_arg, void (*free_function)(void* ptr));


/**
 * This function is only for debug purposes and returns the error code as a string.
 *
 * @param[in]  error_code           error code to print. The error code is returned from the API functions
 * @return     error_string         The error code as text.
 *
 */
const char *cam_error_string(int error_code);


/**
 * This function is only for debug purposes and prints the error code on stderr.
 *
 * @param[in]  error_code           error code to print. The error code is returned from the API functions
 *
 */
void cam_print_error(int error_code);

typedef struct cam_options_t cam_options_t;

/**
 * Creates cam_options which is used to pass additional arguments to insert, delete, update etc.
 * If the function was successful, 0 is returned. If the function fails an error code is returned. The function
 * uses malloc to allocate memory. The malloc cannot be replaced by the function specified by
 * cam_arg_set_malloc_function. If malloc must be replaced use cam_options_size and cam_options_init instead of
 * cam_options_create. Options can only be used for dram bcam/vbcam
 *
 * @param[out]  out_cam_options     The newly created cam_options. If successful memory was allocated.
 *                                  If unsuccessful, no memory was allocated and out_cam_options is left unchanged.
 *
 * @return                          Returns 0 for success, otherwise the error code.
 *
 */
int cam_options_create(cam_options_t** out_cam_options);

/**
 * Gets the byte size of cam_options_t. This is useful if it it is preferred to allocate memory for cam_options_t using
 * something else than the malloc used inside cam_options_create. E.g. alloca.
 * cam_options_create can be replaced by using cam_options_size, alloca/malloc and cam _options_init. Options can only be used for dram bcam/vbcam
 *
 * @return                          Returns the byte size of cam_options_t
 *
 */
size_t cam_options_size(void);

/**
 * Initializes options by setting default values. This function is used together with cam_options_size. out_options is
 * allocated outside of the function. Options can only be used for dram bcam/vbcam
 *
 * @param[out]  out_options     A pointer to options is passed. The function will modify the content
 *                              pointed to by the pointer. The content is set to the same default values as if
 *                              cam_options_create would have been used.
 *
 */
void cam_options_init(cam_options_t *out_options);

/**
 * Destroy cam_options. The memory allocated by cam_options_create is released. The stdlib free function is used.
 * The free function is not replaced by the function specified by the cam_arg_set_free_function. Options can only be used for dram bcam/vbcam
 *
 * @param[in]  cam_options   Pointer to cam_options.
 *
 */
void cam_options_destroy(cam_options_t *cam_options);

/**
 * This function sets if it is a wide or narrow key. The key is either wide or narrow. Default is wide.
 * Options can only be used for dram bcam/vbcam
 *
 * @param[in]  cam_options              Pointer to cam_options.
 * @param[in]  narrow                   If true, the key is narrow.
 *                                      If false, the key is wide.
 */
void cam_options_set_narrow_key(struct cam_options_t *cam_options, bool narrow);

/**
 * This function sets the pre-computed hash value. When a pre-computed hash-value is passed,
 * a new computation of the hash value is not made thus saving processor cycles.Default is not to use
 * pre-computed hash values. If a key is passed with a non-matching hash value, the behavior is undefined.
 * This function is meant to be used for dram bcams in order to serialize access to segments.
 *
 * @param[in]  cam_options              Pointer to cam_options.
 * @param[in]  hash_value               A 256 bit wide hash value. Little-endian is used.
 *
 */
void cam_options_set_precomputed_hash_value(struct cam_options_t *cam_options, uint8_t hash_value[32]);

/**
 * This function clears pre-computed hash value. A pre-computed hash-value is not used and a new computation of the hash value
 * will take place.
 *
 * @param[in]  cam_options              Pointer to cam_options.
 *
 */
void cam_options_clear_precomputed_hash_value(struct cam_options_t *cam_options);

/**
 * This function is only used for dram vbcams' and provides an option to vbcam_get_by_response.
 * The function specifies a single segment to be searched, instead of searching all segments which
 * is the default behavior. The option provides flexibility in how mutex locking can be
 * performed in a multi-threaded environment. Searching only one segment at a time allows for
 * sequentially locking and releasing segments one at a time instead of locking all
 * segments of the dram vbcam upfront.
 *
 * @param[in]  options                  Pointer to cam_options.
 * @param[in]  segment                  The single segment to be searched
 *
 */
void cam_options_set_single_segment_search(struct cam_options_t *options, uint8_t segment);

/**
 * This function clears searching a single segment. The default behavior is restored. That is,
 * vbcam_get_by_response searches all segments.
 *
 * @param[in]  options                  Pointer to cam_options.
 *
 */
void cam_options_clear_single_segment_search(struct cam_options_t *options);


/**
 * The debug flags can be sent as an option. The debug flags passed in the options argument overrides the
 * default debug flags which were passed in cam_arg when the cam instance was created. The debug flags passed as an option argument
 * are only valid for the specific function call. When the function returns, the debug flags are restored to the
 * default debug flags. By default passing debug flags in the options argument is disabled/cleared.
 * Options can only be used for dram bcam/vbcam
 *
 * @param[in]  options                  Pointer to cam_options.
 * @param[in]  debug_flags              The debug flags.
 *
 */
void cam_options_set_debug_flags(struct cam_options_t* options, uint32_t debug_flags);

/**
 * Disables the use of the debug flags in the options argument.
 *
 * @param[in]  options                  Pointer to cam_options.
 *
 */
void cam_options_clear_debug_flags(struct cam_options_t *options);





#ifdef __cplusplus
}
#endif

/** @}*/
#endif
