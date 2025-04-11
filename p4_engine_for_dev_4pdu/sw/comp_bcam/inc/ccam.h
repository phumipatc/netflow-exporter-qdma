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
 * Public API of the Hardware Managed CAM.
 *
 * @file ccam.h
 *
 *
 * @addtogroup ccam Hardware Managed CAM Public API
 * @{
 */

#ifndef _CCAM_H_
#define _CCAM_H_


#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CCAM_MIN_KEY_WIDTH                           10
#define CCAM_MAX_KEY_WIDTH                           992
#define CCAM_MIN_RESPONSE_WIDTH                      1
#define CCAM_MAX_RESPONSE_WIDTH                      1024

struct ccam_arg {
    void *ctx;
    void (*hw_write_function)(void *ctx, uint32_t address, uint32_t data);
    void (*hw_read_function)(void *ctx, uint32_t address, uint32_t *data);
    void (*error_print_function)(void *ctx, char *message);
    void (*info_print_function)(void *ctx, char *message);
    uint32_t debug_flags;
    uint32_t optimization_flags;
};

/*
 * defines for stats_group for ccam_get_stats
 *
 */
#define CCAM_STATS_SW 0
#define CCAM_STATS_RATE 1
#define CCAM_STATS_LAST_LOOKUP 2
#define CCAM_STATS_ITERATIONS 3

/*
 * Software counters
 * These counters are only updated when cxcam_insert, cxcam_update, cxcam_delete and cxcam_get_by_key are called
 * The exception is num_masks which is also updated by the stcam_clear_and_free_unit and stcam_alloc_id functions
 */
struct ccam_sw_stats {
    uint32_t num_entries; // counter to record the current number of entries
    uint64_t num_inserts;
    uint64_t failed_inserts;
    uint64_t num_updates;
    uint64_t failed_updates;
    uint64_t num_deletes;
    uint64_t failed_deletes;
    uint64_t poll_count;  // Total number of times the CPU read from HW and got BUSY
    uint16_t num_masks; // Counter to record the current number of masks. This is always zero for cbcam
};

/*
 * HW counters, these counters are sampled every 100us by hw. Read them faster than 100us to avoid missed samples.
 * The 26 least significant bits contains the counter value. The 6 most significant bits contains the sample number.
 * If the counters do not belong to the same sample number, it means that different sample intervals has been counted.
 *
 */
struct ccam_rate_counters {
    uint32_t inserts;
    uint32_t lookup_request_wait_states;
    uint32_t lookups;
    uint32_t hits;
    uint32_t external_events;

};

/*
 * The response is always valid. If status indicates a match the response contains the response data of the  the matching entry.
 * If there is no match, response contains the default response data. key_width bits of the key are valid. response_width bits
 * of the response are valid.
 * During a hw lookup operation many memory reads take place,
 * if a double bit error is identified the double bit error bit is set and the content in the affected memories is disregarded.
 * If a match and double bit error is indicated at the same time for a cbcam, the match is still always correct and can be trusted.
 * If a match and double bit error is indicated at the same time for a cstcam, there might be a better match but this is unknown
 * due to the double bit error. Only if the user can guarantee non-overlapping entries the match can be considered correct.
 */
struct ccam_last_lookup {
    uint8_t key[(CCAM_MAX_KEY_WIDTH + 7) / 8];  // The last lookup key
    uint8_t response[(CCAM_MAX_RESPONSE_WIDTH + 7) / 8];
    uint32_t status;  // Bit 0: Match, Bit 1: Double bit error
};

/* Iteration counters. Returns the total number of insert iterations,
 * the number of iterations used for the last insert, and the maximum
 * number of iterations used for an insert. All counters are cleared
 * on read. */
struct ccam_iteration_count {
    uint64_t total_iterations;
    uint32_t last_insert_iterations;
    uint32_t max_iterations;
};

/*
 * See documentation for each struct in the union.
 *
 */
union ccam_stats {
    struct ccam_sw_stats sw;
    struct ccam_rate_counters rate;
    struct ccam_last_lookup last_lookup;
    struct ccam_iteration_count iteration_count;

    struct ccam_reserved {
        uint8_t resv[512];
    } reserved;
};


/* Error codes must be kept in sync with the CAM_ERROR_* constants defined in cam.h */

#define CCAM_OK 0
#define CCAM_ERROR_FULL  1
#define CCAM_ERROR_INVALID_ARG   3
#define CCAM_ERROR_WRONG_PRIO_WIDTH 11

#define CCAM_ERROR_DUPLICATE_FOUND   13

#define CCAM_ERROR_NOT_FOUND 18
#define CCAM_ERROR_WRONG_PRIO 20

#define CCAM_ERROR_NO_MASK 47

#define CCAM_ERROR_ENVIRONMENT 50 /* HW non responsive or garbage is read from HW */

#define CCAM_ERROR_NULL_POINTER 52

#define CCAM_ERROR_ENVIRONMENT_POLLED_OUT 56 /* Status register polled beyond the max allowed */

#define CCAM_ERROR_NOT_EMPTY 65

#define CCAM_ERROR_STATISTICS_NOT_AVAILABLE 66 /* The HW was not generated with statistics enabled */

#define CCAM_ERROR_WRONG_API 67

#define CCAM_ERROR_COUNTER_SATURATED 68

/* Fatal error codes: CAM_ERROR_FATAL_BASE_START <= error code < CAM_ERROR_FATAL_BASE_END */
/* The instance is not working anymore */
#define CCAM_ERROR_FATAL_BASE_START 100
#define CCAM_ERROR_FATAL_BASE_END  199 /* No error codes have a higher number */

/**
 * Debug flags to enable debug printouts and hardware verification.
 */
#define CCAM_DEBUG_NONE           0x00000000  /* Quiet, no debug messages */
#define CCAM_DEBUG_NO_ERROR_MSG   0x00000001  /* Disable software error messages printout */
#define CCAM_DEBUG_ARGS           0x00000002  /* Software echoes input arguments */

#define CCAM_DEBUG_VERIFY_WR      0x00000004    /*Software immediately reads back written data from hardware
                                                  for verification. Mismatching data is reported with error
                                                  message.*/

#define CCAM_DEBUG_VERBOSE_VERIFY 0x00000010    /*Enables printout for CCAM_DEBUG_VERIFY_WR */

#define CCAM_DEBUG_SKIP_MEM_INIT  0x00000020    /*Skip memory initialization, useful to speedup Verilog
                                                  simulation*/

#define CCAM_DEBUG_CONFIG         0x00000040  /*Enable printout of configuration parameters for both software
                                                and Verilog hardware simulation*/

#define CCAM_DEBUG_STATS          0x00000200  /* Enable statistics printout for the 'ccam_get_stat' function*/

#define CCAM_OPTIMIZE_ENTRIES     0x00000004  /* The default behavior is to disallow more than num_entries to be
                                                inserted. This flag allows additional insertions if there is spare memory.
                                                When memory resources were calculated to allow for for num_entries,
                                                quantification effects might have created spare memory. For cstcam,
                                                allowing insertion of excessive entries might
                                                compromise the number of masks that can be inserted. The cstcam
                                                dimensioning algorithm uses a worst case distribution of entries over
                                                masks. The actual number of entries that can be inserted might
                                                be much higher than num_entries if the distribution is favorable.  */
#define CCAM_OPTIMIZE_MASKS       0x00000008  /* This flag is only valid for cstcam. The default behavior is to disallow more than num_masks to be
                                                inserted. This flag allows
                                                additional masks to be inserted. Inserting excessive masks may compromise
                                                how many entries that can be inserted.The cstcam
                                                dimensioning algorithm uses a worst case distribution of entries over
                                                masks. The actual number of masks that can be inserted might
                                                be much higher than num_masks if the distribution is favorable.*/


struct ccam;


/**
 * Reads and clears the ECC counters. When the instance is created the ECC counters
 * are automatically cleared.
 *
 * @param[in] ccam                          Pointer to ccam instance
 *
 * @param[out] corrected_single_bit_errors  The number of single bit errors the hardware scrubbing
 *                                          process has detected and corrected permanently. Single bit errors
 *                                          might have been detected by hardware lookups and then corrected
 *                                          dynamically for the lookups. These errors are not counted.
 *                                          The scrubbing process runs in the background and corrects
 *                                          errors permanently. The corrected_single_bit_errors counter
 *                                          is only incremented after the error is corrected permanently. The
 *                                          counter is cleared after this function is called.
 *
 * @param[out] detected_double_bit_errors   The number of detected double-bit errors. Double-bit
 *                                          errors are fatal errors and the cam is corrupt. The hardware
 *                                          cannot correct the error. The instance generates an interrupt every
 *                                          time a double bit error is detected. The error is detected by a lookup
 *                                          or scrubbing. Lookups detecting double-bit errors
 *                                          signals double bit error and it is advised to discard the response
 *                                          from such lookups.
 *                                          The detected_double_bit_errors counter is only incremented by the
 *                                          scrubbing process. The counter is cleared after it is read.
 *                                          Double bit errors should not occur and the memory might be defect.
 *
 * @return                                  Returns 0 for success, otherwise the error code.
 *
 */
int ccam_read_and_clear_ecc_counters(const struct ccam *ccam, uint32_t *corrected_single_bit_errors,
        uint32_t *detected_double_bit_errors);


/**
 * Reads and clears the ECC address registers. The ECC address registers are
 * automatically cleared when the instance is created.
 *
 * @param[in] ccam                               Pointer to ccam instance
 *
 * @param[out] failing_address_single_bit_error  The address of the first single bit error detected and corrected
 *                                               by the hardware scrubbing process since the last call of this function. Additional
 *                                               errors might have been detected during a hardware lookup and then corrected
 *                                               dynamically, but the failing_address_single_bit_error only reflects the
 *                                               errors detected by hardware scrubbing.
 *                                               If there are no errors, 0xfffffffff is returned.
 *                                               If the error occurs for the same address frequently, the memory might be defect.
 *
 * @param[out] failing_address_double_bit_error  The address of the first double-bit error detected by the
 *                                               hardware scrubbing process since the last call of this function.
 *                                               If there are no errors, 0xfffffffff is returned.
 *                                               If double bit errors occur, the memory might be defect.
 *
 * @return                                       Returns 0 for success, otherwise the error code.
 *
 */
int ccam_read_and_clear_ecc_addresses(const struct ccam *ccam, uint32_t *failing_address_single_bit_error,
        uint32_t *failing_address_double_bit_error);


/**
 * Sets error injection for ECC test. Error injection makes subsequently inserted entries to be stored in memory with errors.
 *
 * @param[in] ccam                               Pointer to ccam instance
 *
 * @param[in] inject_single_bit_errors           Enable insertion of single-bit errors (correctable).
 *
 * @param[in] inject_double_bit_errors           Enable insertion of double-bit errors (uncorrectable).
 *
 * @return                                       Returns 0 for success, otherwise the error code.
 *
 */
int ccam_set_ecc_test(struct ccam *ccam, bool inject_single_bit_errors, bool inject_double_bit_errors);


/**
 * Reads statistics information. The statistics information
 * is organized in different groups. The statistics associated with a certain group is read from the instance.
 * See documentation for the ccam_stats union for further information.
 *
 * @param[in]   ccam            Pointer to ccam instance
 *
 * @param[in]   stats_group     Selects the group of statistics to be read
 * @param[out]  stats           The read statistics
 *
 * @return                      Returns 0 for success, otherwise the error code.
 *
 */
int ccam_get_stats(const struct ccam *ccam, uint64_t stats_group, union ccam_stats *stats);


/** @}*/
#ifdef __cplusplus
}
#endif

#endif
