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
#include <inttypes.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#ifndef _CBCAM_H_
#define _CBCAM_H_
#include <stdint.h>
#include <stdlib.h>
#ifndef _CCAM_H_
#define _CCAM_H_
#ifdef __cplusplus
extern "C" {
#endif
#define CCAM_MIN_KEY_WIDTH 10
#define CCAM_MAX_KEY_WIDTH 992
#define CCAM_MIN_RESPONSE_WIDTH 1
#define CCAM_MAX_RESPONSE_WIDTH 1024
struct ccam_arg {
void *ctx;
void (*hw_write_function)(void *ctx, uint32_t address, uint32_t data);
void (*hw_read_function)(void *ctx, uint32_t address, uint32_t *data);
void (*error_print_function)(void *ctx, char *message);
void (*info_print_function)(void *ctx, char *message);
uint32_t debug_flags;
uint32_t optimization_flags;
};
#define CCAM_STATS_SW 0
#define CCAM_STATS_RATE 1
#define CCAM_STATS_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP 2
#define CCAM_STATS_ITERATIONS 3
struct ccam_sw_stats {
uint32_t num_entries; 
uint64_t num_inserts;
uint64_t failed_inserts;
uint64_t num_updates;
uint64_t failed_updates;
uint64_t num_deletes;
uint64_t failed_deletes;
uint64_t poll_count; 
uint16_t num_masks; 
};
struct ccam_rate_counters {
uint32_t inserts;
uint32_t lookup_request_wait_states;
uint32_t lookups;
uint32_t hits;
uint32_t external_events;
};
struct ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup {
uint8_t key[(CCAM_MAX_KEY_WIDTH + 7) / 8]; 
uint8_t response[(CCAM_MAX_RESPONSE_WIDTH + 7) / 8];
uint32_t status; 
};
struct ccam_iteration_count {
uint64_t total_iterations;
uint32_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaiterations;
uint32_t max_iterations;
};
union ccam_stats {
struct ccam_sw_stats sw;
struct ccam_rate_counters rate;
struct ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup;
struct ccam_iteration_count iteration_count;
struct ccam_reserved {
uint8_t resv[512];
} reserved;
};
#define CCAM_OK 0
#define CCAM_ERROR_FULL 1
#define CCAM_ERROR_INVALID_ARG 3
#define CCAM_ERROR_WRONG_PRIO_WIDTH 11
#define CCAM_ERROR_DUPLICATE_FOUND 13
#define CCAM_ERROR_NOT_FOUND 18
#define CCAM_ERROR_WRONG_PRIO 20
#define CCAM_ERROR_NO_MASK 47
#define CCAM_ERROR_ENVIRONMENT 50 
#define CCAM_ERROR_NULL_POINTER 52
#define CCAM_ERROR_ENVIRONMENT_POLLED_OUT 56 
#define CCAM_ERROR_NOT_EMPTY 65
#define CCAM_ERROR_STATISTICS_NOT_AVAILABLE 66 
#define CCAM_ERROR_WRONG_API 67
#define CCAM_ERROR_aaaaaaaaaaaaaaaaaaaaaaaa1aaaER_SATURATED 68
#define CCAM_ERROR_FATAL_BASE_START 100
#define CCAM_ERROR_FATAL_BASE_END 199 
#define CCAM_DEBUG_NONE 0x00000000 
#define CCAM_DEBUG_NO_ERROR_MSG 0x00000001 
#define CCAM_DEBUG_ARGS 0x00000002 
#define CCAM_DEBUG_VERIFY_WR 0x00000004 
#define CCAM_DEBUG_VERBOSE_VERIFY 0x00000010 
#define CCAM_DEBUG_SKIP_MEM_INIT 0x00000020 
#define CCAM_DEBUG_CONFIG 0x00000040 
#define CCAM_DEBUG_STATS 0x00000200 
#define CCAM_OPTIMIZE_ENTRIES 0x00000004 
#define CCAM_OPTIMIZE_MASKS 0x00000008 
struct ccam;
int ccam_read_and_clear_ecc_counters(const struct ccam *ccam, uint32_t *corrected_single_bit_errors,
uint32_t *detected_double_bit_errors);
int ccam_read_and_clear_ecc_addresses(const struct ccam *ccam, uint32_t *failing_address_single_bit_error,
uint32_t *failing_address_double_bit_error);
int ccam_set_ecc_test(struct ccam *ccam, bool inject_single_bit_errors, bool inject_double_bit_errors);
int ccam_get_stats(const struct ccam *ccam, uint64_t stats_group, union ccam_stats *stats);
#ifdef __cplusplus
}
#endif
#endif
#ifdef __cplusplus
extern "C" {
#endif
struct cbcam;
size_t cbcam_size(void);
int cbcam_init(const struct ccam_arg *arg, struct cbcam *cbcam);
int cbcam_insert(struct cbcam *cbcam, const uint8_t key[], const uint8_t response[]);
int cbcam_update(struct cbcam *cbcam, const uint8_t key[], const uint8_t response[]);
int cbcam_get_by_key(struct cbcam *cbcam, const uint8_t key[], uint8_t response[]);
int cbcam_delete_all(struct cbcam *cbcam);
int cbcam_delete(struct cbcam *cbcam, const uint8_t key[]);
int cbcam_get_by_response(struct cbcam *cbcam, const uint8_t in_response[], const uint8_t response_mask[],
uint32_t *pos, uint8_t out_key[], uint8_t out_response[]);
#ifdef __cplusplus
}
#endif
#endif
#ifndef _CCAMP_H_
#define _CCAMP_H_
#ifdef __cplusplus
extern "C" {
#endif
#define CCAM_MAX_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa 2048
#ifndef NULL_CHECK
#define NULL_CHECK(ptr) if (ptr == NULL) return CCAM_ERROR_NULL_POINTER
#endif
typedef enum aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaENUM {
aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaSUCCESS = 0x00,
aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaFULL = 0x01,
aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaNOTFOUND = 0x02,
aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaDUPLICATEKEY = 0x03,
aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaFSMBUSY = 0x04,
aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaNOTFOUND = 0x05,
aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaSUCCESSBLOCKED = 0x06
} aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaENUM;
typedef enum aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaENUM {
aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa4aaa = 0x00,
aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbb3aaa = 0x01,
aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa4aaa = 0x02,
aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaa4aaaBYKEY = 0x03,
aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaRDBYADDR = 0x04,
aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaWRBYADDR = 0x05
} aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaENUM;
#define aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x100)
#define aaaaaaaaaaaaaaaaaaa1aaaINDIRECT_RD_DATA_00_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x104)
#define aaaaaaaaaaaaaaaaaaa1aaaINDIRECT_WR_DATA_00_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x108)
#define aaaaaaaaaaaaaaaaaaa1aaaINDIRECT_WR_DATA_01_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x10c)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa (0x100)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa (0x104)
#define aaaaaaaaaaaaaaaaaaaa1aaaRESP_WIDTH (0x108)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaaS (0x10C)
#define aaaaaaaaaaaaaaaaaaaa1aaaTIME_SLOTS (0x110)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaa1aaaDATA (0x114)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaR (0x118)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa (0x11C)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaa4aaa (0x120)
#define aaaaaaaaaaaaaaaaaaaa1aaaBUILD_NUM (0x128)
#define aaaaaaaaaaaaaaaaaaaa1aaaASIC (0x12C)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaS (0x130)
#define aaaaaaaaaaaaaaaaaaaa1aaaCACHE_EN (0x134)
#define aaaaaaaaaaaaaaaaaaaa1aaaAGING_EN (0x138)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaSTATS_EN (0x13C)
#define aaaaaaaaaaaaaaaaaaaa1aaaSCRATCH (0x184)
#define aaaaaaaaaaaaaaaaaaaa1aaaSBITERR_CNT (0x300)
#define aaaaaaaaaaaaaaaaaaaa1aaaDBITERR_CNT (0x304)
#define aaaaaaaaaaaaaaaaaaaa1aaaSBITERR_FFA (0x308)
#define aaaaaaaaaaaaaaaaaaaa1aaaDBITERR_FFA (0x30C)
#define aaaaaaaaaaaaaaaaaaaa1aaaECC_TEST (0x310)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x20000)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP_KEY (0x400)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP_RESPONSE (0x480)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP_STATUS (0x500)
#define aaaaaaaaaaaaaaaaaaa1aaaVERSION_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x0)
#define aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaBER_PASSES_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x14)
#define aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x18)
#define aaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP_aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x28)
#define aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x2c)
#define aaaaaaaaaaaaaaaaaaa1aaaEXT_EVENT_aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x38)
#define aaaaaaaaaaaaaaaaaaa1aaaLI_REQ_WS_aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x3c)
#define aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaTAL_NUM_PASS_aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x40)
#define aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaTAL_NUM_PASS_aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x44)
#define aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaDET_NUM_PASS_aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x48)
#define aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaDET_NUM_PASS_aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x4c)
#define aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x11c)
#define aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x110)
#define aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaaRITY_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x144)
#define aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x120)
#define aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaDATA_00_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x300)
#define aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaDATA_00_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x200)
#define aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaCTRL_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x280)
#define aaaaaaaaaaaaaaaaaaa1aaaOPERATION_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x114)
#define aaaaaaaaaaaaaaaaaaa1aaaMU_SELECT_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x148)
#define aaaaaaaaaaaaaaaaaaa1aaaCHMU_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x14C)
#define aaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaPER_CHMU_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x150)
#define aaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaPER_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x118)
#define CCAM_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa1US 0
#define CCAM_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa10US 1
#define CCAM_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa100US 2
#define CCAM_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa1MS 3
#define CCAM_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa10MS 4
#define CCAM_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa100MS 5
#define CCAM_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa1S 6
#define CCAM_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaNO_SAMPLE 7
#define CCAM_AGING_BITS 7
#define CCAM_FILL_RATIO 95/100
#define CCAM_2W_aaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa 5/10
#define CCAM_3W_aaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa 9/10
#define INSTANCE_CBCAM 5
#define INSTANCE_CSTCAM 6
#define CCAM_SW_VERSION_MAJOR 2
#define CCAM_SW_VERSION_MINOR 6
#define CCAM_SW_VERSION_PATCH 0
#define CCAM_BUILD_NUMBER 3971855
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaWORD 0x04
#define aaaaaa1aaaCA_WORD 0x08
#define aaaaaa1aaaECC_WORD 0x04
#define aaaaaa1aaaSM_WORD 0x80
#define aaaaaa1aaaaaaaaaaaaaaa1aaaWORD 0x80
#define aaaaaa1aaaaa1aaaWORD 0x08
#define aaaaaa1aaaaaaa1aaaWORD 0x100
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa 0x000100
#define aaaaaa1aaaCA_BASE 0x000200
#define aaaaaa1aaaECC_BASE 0x000300
#define aaaaaa1aaaSM_BASE 0x040000
#define aaaaaa1aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa 0x100000
#define aaaaaa1aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa 0x200000
#define aaaaaa1aaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa 0x400000
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa 0x0fff00
#define aaaaaa1aaaCA_MASK 0x0ffff0
#define aaaaaa1aaaECC_MASK 0x0ffff0
#define aaaaaa1aaaSM_MASK 0x7c0000
#define aaaaaa1aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa 0x700000
#define aaaaaa1aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa 0x600000
#define aaaaaa1aaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa 0x400000
#define aaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa 0x00800000
#define aaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa 0xff800000
struct ccam_config {
uint32_t hw_version;
uint32_t hw_build_num;
uint32_t key_width;
uint32_t prio_width; 
uint32_t response_width;
uint32_t num_slots;
uint32_t phys_units;
uint32_t ram_data_width;
uint32_t ram_addresses;
uint32_t instance_type;
uint32_t num_entries;
uint32_t num_masks; 
uint32_t cache_en;
uint32_t aging_en;
uint32_t hw_stats_en; 
uint32_t asic;
};
struct ccam {
struct ccam_arg arg;
struct ccam_config config;
struct ccam_sw_stats sw_stats;
bool blocked;
};
const char *ccam_error_string(int error_code);
void ccam_print_entry(int error_code, const char *function, const struct ccam *ccam, const uint8_t key[],
const uint8_t mask[], const uint8_t response[], const char *match);
int ccam_poll_status(struct ccam *ccam);
void ccam_set_key(const struct ccam *ccam, const uint8_t key[]);
void ccam_get_key(const struct ccam *ccam, uint8_t key[]);
void ccam_set_resp(const struct ccam *ccam, const uint8_t response[]);
void ccam_get_resp(const struct ccam *ccam, uint8_t response[]);
void ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(const struct ccam *ccam, uint32_t indirect_address, uint32_t *data);
void ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(struct ccam *ccam, uint32_t indirect_address, uint64_t data);
void ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(const struct ccam *ccam, uint32_t direct_address, uint32_t data);
void ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(const struct ccam *ccam, uint32_t direct_address, uint32_t *data);
int ccam_init(const struct ccam_arg *arg, struct ccam *ccam);
int ccam_clear(const struct ccam *ccam);
bool ccam_is_blocked(const struct ccam *ccam);
bool ccam_is_cache(const struct ccam *ccam);
uint32_t ccam_calculate_max_num_entries(const struct ccam *ccam);
uint32_t ccam_calculate_base_address(const struct ccam *ccam, uint16_t unit, uint32_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber);
int ccam_read_entry(struct ccam *ccam, uint16_t unit, uint32_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber, bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaa1aaa);
int ccam_get_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaby_response(struct ccam *ccam, const uint8_t response[], const uint8_t response_mask[],
uint16_t unit, uint32_t *start_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber);
int ccam_get_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaby_response(struct ccam *ccam, const uint8_t response[], const uint8_t response_mask[]);
#ifdef __cplusplus
}
#endif
#endif
#ifndef aaaaaaaa1aaaH
#define aaaaaaaa1aaaH
#include <stddef.h>
#define BIT(n) ( 1<<(n) )
#define BIT_SET(y, mask) ( y |= (mask) )
#define BIT_CLEAR(y, mask) ( y &= ~(mask) )
#define BIT_FLIP(y, mask) ( y ^= (mask) )
#define BIT_MASK(len) (( 1<<(len) )-1)
static inline uint8_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa8(uint8_t len);
static inline uint16_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa16(uint8_t len);
static inline uint32_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa(uint8_t len);
static inline uint64_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa64(uint8_t len);
static inline uint8_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa8(uint8_t y, uint8_t shift, uint8_t len);
static inline uint16_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa16(uint16_t y, uint8_t shift, uint8_t len);
static inline uint32_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(uint32_t y, uint8_t shift, uint8_t len);
static inline uint64_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa64(uint64_t y, uint8_t shift, uint8_t len);
static inline uint8_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa8(uint8_t y, uint8_t x, uint8_t shift, uint8_t len);
static inline uint16_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa16(uint16_t y, uint16_t x, uint8_t shift, uint8_t len);
static inline uint32_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa(uint32_t y, uint32_t x, uint8_t shift, uint8_t len);
static inline uint64_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa64(uint64_t y, uint64_t x, uint8_t shift, uint8_t len);
static inline uint16_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa16(uint8_t len)
{
assert(len <= 16);
if (len == 16) {
return UINT16_MAX;
} else {
return ~(UINT16_MAX << len);
}
}
static inline uint8_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa8(uint8_t len)
{
assert(len <= 8);
if (len == 8) {
return UINT8_MAX;
} else {
return ~(UINT8_MAX << len);
}
}
static inline uint32_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa(uint8_t len)
{
assert(len <= 32);
if (len == 32) {
return UINT32_MAX;
} else {
return ~(UINT32_MAX << len);
}
}
static inline uint64_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa64(uint8_t len)
{
assert(len <= 64);
if (len == 64) {
return UINT64_MAX;
} else {
return ~(UINT64_MAX << len);
}
}
static inline uint8_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa8(uint8_t y, uint8_t shift, uint8_t len)
{
assert(len <= 8);
assert(shift <= 7);
assert(shift + len <= 8);
uint8_t mask = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa8(len);
return (y >> shift) & mask;
}
static inline uint16_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa16(uint16_t y, uint8_t shift, uint8_t len)
{
assert(len <= 16);
assert(shift <= 15);
assert(shift + len <= 16);
uint16_t mask = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa16(len);
return (y >> shift) & mask;
}
static inline uint32_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(uint32_t y, uint8_t shift, uint8_t len)
{
assert(len <= 32);
assert(shift <= 31);
assert((shift + len) <= 32);
uint32_t mask = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa(len);
return (y >> shift) & mask;
}
static inline uint64_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa64(uint64_t y, uint8_t shift, uint8_t len)
{
assert(len <= 64);
assert(shift <= 63);
assert(shift + len <= 64);
uint64_t mask = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa64(len);
return (y >> shift) & mask;
}
static inline uint16_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa16(uint16_t y, uint16_t x, uint8_t shift, uint8_t len)
{
assert(len <= 16);
assert(shift <= 15);
assert(shift + len <= 16);
uint16_t mask = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa16(len);
return (y & ~(mask << shift)) | ((x & mask) << shift);
}
static inline uint8_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa8(uint8_t y, uint8_t x, uint8_t shift, uint8_t len)
{
assert(len <= 8);
assert(shift <= 7);
assert(shift + len <= 8);
uint16_t mask = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa8(len);
return (y & ~(mask << shift)) | ((x & mask) << shift);
}
static inline uint32_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa(uint32_t y, uint32_t x, uint8_t shift, uint8_t len)
{
assert(len <= 32);
assert(shift <= 31);
assert((shift + len) <= 32);
uint32_t mask = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa(len);
return (y & ~(mask << shift)) | ((x & mask) << shift);
}
static inline uint64_t aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa64(uint64_t y, uint64_t x, uint8_t shift, uint8_t len)
{
assert(len <= 64);
assert(shift <= 63);
assert(shift + len <= 64);
uint64_t mask = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa64(len);
return (y & ~(mask << shift)) | ((x & mask) << shift);
}
static inline uint32_t aaaaaaaa1aaarotate_left32(uint32_t x, uint8_t r)
{
return (x << r) | (x >> (32 - r));
}
void cam_write_field8(uint8_t *target, const uint8_t *source, uint16_t target_start_pos, uint16_t bit_len);
void cam_read_field8(uint8_t *target, const uint8_t *source, uint16_t source_start_pos, uint16_t bit_len);
void cam_copy_bits(uint8_t *target, const uint8_t *source, uint16_t bit_len);
void cam_write_field(uint32_t *target, uint16_t start_pos, uint16_t end_pos, const uint32_t *source,
uint16_t prio_end_pos);
void cam_read_field(const uint32_t *source, uint16_t start_pos, uint16_t end_pos, uint32_t *target);
#endif
struct cbcam {
struct ccam ccam;
};
size_t cbcam_size(void) {
return sizeof(struct cbcam);
}
int cbcam_init(const struct ccam_arg *arg, struct cbcam *cbcam) {
NULL_CHECK(cbcam);
NULL_CHECK(arg);
memset(cbcam, 0, cbcam_size());
int rc = ccam_init(arg, (struct ccam *) cbcam);
   ccam_print_entry(rc, "cbcam_init", (struct ccam *) cbcam, NULL, NULL, NULL, "");
return rc;
}
int cbcam_update(struct cbcam *cbcam, const uint8_t key[], const uint8_t response[]) {
NULL_CHECK(cbcam);
NULL_CHECK(key);
NULL_CHECK(response);
cbcam->ccam.sw_stats.num_updates++;
ccam_set_key((struct ccam *) cbcam, key);
ccam_set_resp((struct ccam *) cbcam, response);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((struct ccam *) cbcam, aaaaaaaaaaaaaaaaaaa1aaaOPERATION_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbb3aaa);
int rc = ccam_poll_status((struct ccam *) cbcam);
if (rc == 0) {
} else {
cbcam->ccam.sw_stats.failed_updates++;
}
   ccam_print_entry(rc, "cbcam_update", (struct ccam *) cbcam, key, NULL, response, "");
return rc;
}
int cbcam_insert(struct cbcam *cbcam, const uint8_t key[], const uint8_t response[])
{
NULL_CHECK(cbcam);
NULL_CHECK(key);
NULL_CHECK(response);
int rc = 0;
cbcam->ccam.sw_stats.num_inserts++;
if ((cbcam->ccam.arg.optimization_flags & CCAM_OPTIMIZE_ENTRIES) > 0) {
const uint32_t max_num_entries = ccam_calculate_max_num_entries((struct ccam *) cbcam);
if (cbcam->ccam.sw_stats.num_entries >= max_num_entries) {
rc = CCAM_ERROR_FULL;
}
} else if (cbcam->ccam.sw_stats.num_entries >= cbcam->ccam.config.num_entries) {
rc = CCAM_ERROR_FULL;
}
if (rc == 0) {
ccam_set_key((struct ccam *) cbcam, key);
ccam_set_resp((struct ccam *) cbcam, response);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((struct ccam *) cbcam, aaaaaaaaaaaaaaaaaaa1aaaOPERATION_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa,
aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa4aaa);
rc = ccam_poll_status((struct ccam *) cbcam);
}
if (rc == 0) {
cbcam->ccam.sw_stats.num_entries++;
} else {
cbcam->ccam.sw_stats.failed_inserts++;
}
   ccam_print_entry(rc, "cbcam_insert", (struct ccam *) cbcam, key, NULL, response, "");
return rc;
}
int cbcam_get_by_key(struct cbcam *cbcam, const uint8_t key[], uint8_t response[])
{
NULL_CHECK(cbcam);
NULL_CHECK(key);
NULL_CHECK(response);
bool using_default_response = false;
ccam_set_key((struct ccam *) cbcam, key);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((struct ccam *) cbcam, aaaaaaaaaaaaaaaaaaa1aaaOPERATION_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaa4aaaBYKEY);
int rc = ccam_poll_status((struct ccam *) cbcam);
if (rc == 0) {
ccam_get_resp((struct ccam *) cbcam, response);
} else if (rc == CCAM_ERROR_NOT_FOUND) {
using_default_response = true;
ccam_get_resp((struct ccam *) cbcam, response);
} else {
       ccam_print_entry(rc, "cbcam_get_by_key", (struct ccam *) cbcam, key, NULL, NULL, "");
return rc;
}
   ccam_print_entry(0, "cbcam_get_by_key", (struct ccam *) cbcam, key, NULL, response,
           using_default_response ? "DEFAULT_MATCH" : "KEY_MATCH");
return rc;
}
int cbcam_delete_all(struct cbcam *cbcam) {
NULL_CHECK(cbcam);
int rc = ccam_clear((struct ccam *) cbcam);
if (rc == 0) {
cbcam->ccam.sw_stats.num_deletes = cbcam->ccam.sw_stats.num_deletes + cbcam->ccam.sw_stats.num_entries;
cbcam->ccam.sw_stats.num_entries = cbcam->ccam.sw_stats.num_entries - cbcam->ccam.sw_stats.num_deletes;
}
   ccam_print_entry(rc, "cbcam_delete_all", (struct ccam *) cbcam, NULL, NULL, NULL, "");
return rc;
}
int cbcam_delete(struct cbcam *cbcam, const uint8_t key[])
{
NULL_CHECK(cbcam);
NULL_CHECK(key);
cbcam->ccam.sw_stats.num_deletes++;
ccam_set_key((struct ccam *) cbcam, key);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((struct ccam *) cbcam, aaaaaaaaaaaaaaaaaaa1aaaOPERATION_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa4aaa);
int rc = ccam_poll_status((struct ccam *) cbcam);
if (rc == 0) {
if (cbcam->ccam.sw_stats.num_entries == 0)
rc = CCAM_ERROR_ENVIRONMENT;
else
cbcam->ccam.sw_stats.num_entries--;
} else {
cbcam->ccam.sw_stats.failed_deletes++;
}
   ccam_print_entry(rc, "cbcam_delete", (struct ccam *) cbcam, key, NULL, NULL, "");
return (rc);
}
int cbcam_get_by_response(struct cbcam *cbcam, const uint8_t in_response[], const uint8_t response_mask[],
uint32_t *pos, uint8_t out_key[], uint8_t out_response[])
{
NULL_CHECK(cbcam);
NULL_CHECK(in_response);
NULL_CHECK(response_mask);
NULL_CHECK(out_key);
NULL_CHECK(out_response);
NULL_CHECK(pos);
int rc;
if (*pos == 0x80000000) {
rc = CCAM_ERROR_NOT_FOUND;
goto end;
}
const uint32_t start_unit = *pos >> 16;
uint32_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber = *pos & 0x0000ffff;
if (start_unit >= (cbcam->ccam.config.phys_units * cbcam->ccam.config.num_slots)) {
rc = CCAM_ERROR_INVALID_ARG;
goto end;
}
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber > (cbcam->ccam.config.ram_addresses / cbcam->ccam.config.num_slots)) {
rc = CCAM_ERROR_INVALID_ARG;
goto end;
}
const uint16_t num_units = cbcam->ccam.config.phys_units * cbcam->ccam.config.num_slots;
rc = CCAM_ERROR_NOT_FOUND;
for (uint16_t unit = start_unit; unit < num_units; unit++) {
rc = ccam_get_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaby_response((struct ccam *) cbcam, in_response, response_mask, unit,
&aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber);
if (rc == 0) {
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber++;
*pos = unit << 16 | aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber;
ccam_get_key((const struct ccam *) cbcam, out_key);
ccam_get_resp((const struct ccam *) cbcam, out_response);
goto end;
}
if (rc != CCAM_ERROR_NOT_FOUND)
goto end;
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber = 0;
}
if (rc == CCAM_ERROR_NOT_FOUND) {
rc = ccam_get_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaby_response((struct ccam *) cbcam, in_response, response_mask);
if (rc == 0) {
ccam_get_key((const struct ccam *) cbcam, out_key);
ccam_get_resp((const struct ccam *) cbcam, out_response);
*pos = 0x80000000; 
}
}
    end: ccam_print_entry(rc, "cbcam_get_by_response", (struct ccam *) cbcam,
                          rc == 0 ? out_key : NULL, NULL, in_response, "");
return rc;
}
#define POLL_aaaaaaaaaaaaaaaaaaaaaaaa1aaa 300000
#define NUM_BITS_IN_BYTE (8)
#define NUM_BITS_IN_DWORD (32)
#define NUM_BYTES_IN_DWORD (4)
#define BYTE_MASK (0xFF)
#define BYTE_ARR_SZ 300
#define MSG_SZ 1024
static void byte_arr_to_str(uint16_t bit_len, const uint8_t *src, char *target) {
assert(src != NULL);
assert(target != NULL);
uint16_t byte_len = (bit_len + 7) / 8;
uint8_t tailbits = bit_len - (byte_len - 1) * 8;
;
if (tailbits == 0)
tailbits = 8;
uint8_t tailmask = 0xff >> (8 - tailbits);
target[0] = '\0';
   sprintf(target + strlen(target), "0x");
for (int i = byte_len - 1; i >= 0; i--) {
if ((i == byte_len - 1) && (byte_len != (bit_len + 3) / 8)) {
           sprintf(target + strlen(target), "%1x", src[i] & tailmask);
} else {
           sprintf(target + strlen(target), "%02x", src[i] & tailmask);
}
tailmask = 0xff;
}
}
const char *ccam_error_string(int error_code) {
   const char *err_txt[CCAM_ERROR_FATAL_BASE_END + 1] = { "UNDEFINED ERROR" };
   err_txt[CCAM_ERROR_FULL] = "CCAM_ERROR_FULL";
   err_txt[CCAM_ERROR_WRONG_PRIO_WIDTH] = "CCAM_ERROR_WRONG_PRIO_WIDTH";
   err_txt[CCAM_ERROR_DUPLICATE_FOUND] = "CCAM_ERROR_DUPLICATE_FOUND";
   err_txt[CCAM_ERROR_NOT_FOUND] = "CCAM_ERROR_NOT_FOUND";
   err_txt[CCAM_ERROR_NO_MASK] = "CCAM_ERROR_NO_AMSK";
   err_txt[CCAM_ERROR_WRONG_API] = "CCAM_ERROR_WRONG_API";
   err_txt[CCAM_ERROR_NOT_EMPTY] = "CCAM_ERROR_NOT_EMPTY";
   err_txt[CCAM_ERROR_WRONG_PRIO] = "CAM_ERROR_WRONG_PRIO";
   err_txt[CCAM_ERROR_NO_MASK] = "CCAM_ERROR_NO_MASK";
#if 0
   err_txt[CAM_ERROR_INVALID_MEMORY_WIDTH] = "CAM_ERROR_INVALID_MEMORY_WIDTH";
   err_txt[CAM_ERROR_NOMEM] = "CAM_ERROR_NOMEM";
   err_txt[CAM_ERROR_MALLOC_FAILED] = "CAM_ERROR_MALLOC_FAILED";
   err_txt[CAM_ERROR_UNSUPPORTED_COMMAND] = "CAM_ERROR_UNSUPPORTED_COMMAND";
   err_txt[CAM_ERROR_ENVIRONMENT] = "CAM_ERROR_ENVIRONMENT";
   err_txt[CCAM_ERROR_ENVIRONMENT] = "CCAM_ERROR_ENVIRONMENT";
   err_txt[CAM_ERROR_UNSUPPORTED_CAM_TYPE] = "CAM_ERROR_UNSUPPORTED_CAM_TYPE";
#endif
   err_txt[CCAM_ERROR_NULL_POINTER] = "CCAM_ERROR_NULL_POINTER";
   err_txt[CCAM_ERROR_ENVIRONMENT_POLLED_OUT] = "CCAM_ERROR_ENVIRONMENT_POLLED_OUT";
#if 0
   err_txt[CAM_ERROR_SEGMENT_aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaZERO] = "CAM_ERROR_SEGMENT_aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaZERO";
   err_txt[CAM_ERROR_VC_UNSUPPORTED_COMMAND] = "CAM_ERROR_VC_UNSUPPORTED_COMMAND";
   err_txt[CAM_ERROR_WRONG_VIRTUAL_CAM_ID] = "CAM_ERROR_WRONG_VIRTUAL_CAM_ID";
   err_txt[CAM_ERROR_WRONG_SEGMENT_NUMBER] = "CAM_ERROR_WRONG_SEGMENT_NUMBER";
   err_txt[CAM_ERROR_FOUND_IN_SHADOW_BUT_NOT_IN_HW] = "CAM_ERROR_FOUND_IN_SHADOW_BUT_NOT_IN_HW";
   err_txt[CAM_ERROR_TOO_SMALL_HEAP] = "CAM_ERROR_TOO_SMALL_HEAP";
#endif
if (error_code < 0 || error_code > CCAM_ERROR_FATAL_BASE_END) {
       return "UNDEFINED ERROR";
} else {
return err_txt[error_code];
}
}
void ccam_print_entry(int error_code, const char *function, const struct ccam *ccam, const uint8_t key[],
const uint8_t mask[], const uint8_t response[], const char *match) {
if (error_code && (ccam->arg.debug_flags & CCAM_DEBUG_NO_ERROR_MSG))
return;
if (!error_code && !(ccam->arg.debug_flags & CCAM_DEBUG_ARGS))
return;
char message[MSG_SZ];
   char key_str[BYTE_ARR_SZ] = "N/A";
if (key != NULL) {
byte_arr_to_str(ccam->config.key_width, key, key_str);
}
   char mask_str[BYTE_ARR_SZ] = "N/A";
if (mask != NULL) {
byte_arr_to_str(ccam->config.key_width, mask, mask_str);
}
   char response_str[BYTE_ARR_SZ] = "N/A";
if (response != NULL) {
byte_arr_to_str(ccam->config.response_width, response, response_str);
}
if (!error_code && (ccam->arg.debug_flags & CCAM_DEBUG_ARGS)) {
       snprintf(message, MSG_SZ, "%-22s key = %s mask = %s response = %s %8s", function, key_str, mask_str,
response_str, match);
ccam->arg.info_print_function(ccam->arg.ctx, message);
}
if (error_code) {
sprintf(message,
               "%-22s key = %s mask = %s response = %s  %s\n\n%10s%-20s  num_entries = %0d  (%0d used)",
               function, key_str, mask_str, response_str, ccam_error_string(error_code), " ", "ccam resources",
ccam->config.num_entries, (uint32_t)
ccam->sw_stats.num_entries);
ccam->arg.error_print_function(ccam->arg.ctx, message);
}
}
void ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(const struct ccam *ccam, uint32_t indirect_address, uint32_t *data) {
ccam->arg.hw_write_function(ccam->arg.ctx, aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, indirect_address);
ccam->arg.hw_write_function(ccam->arg.ctx, aaaaaaaaaaaaaaaaaaa1aaaOPERATION_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaRDBYADDR);
ccam->arg.hw_read_function(ccam->arg.ctx, aaaaaaaaaaaaaaaaaaa1aaaINDIRECT_RD_DATA_00_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, data);
}
void ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(struct ccam *ccam, uint32_t indirect_address, uint64_t data) {
ccam->arg.hw_write_function(ccam->arg.ctx, aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, indirect_address);
uint32_t temp[2];
memcpy(temp, &data, sizeof(data));
ccam->arg.hw_write_function(ccam->arg.ctx, aaaaaaaaaaaaaaaaaaa1aaaINDIRECT_WR_DATA_00_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, temp[0]);
memcpy(temp, &data, sizeof(uint32_t));
ccam->arg.hw_write_function(ccam->arg.ctx, aaaaaaaaaaaaaaaaaaa1aaaINDIRECT_WR_DATA_01_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, temp[1]);
ccam->arg.hw_write_function(ccam->arg.ctx, aaaaaaaaaaaaaaaaaaa1aaaOPERATION_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaWRBYADDR);
if (ccam->arg.debug_flags & CCAM_DEBUG_VERIFY_WR) {
char message[MSG_SZ];
uint64_t read_data;
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, indirect_address, (uint32_t *) &read_data);
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, indirect_address + 4, ((uint32_t *) &read_data) + 1);
if (read_data != data) {
sprintf(message,
                   "CCAM_DEBUG_VERIFY_WR  address = 0x%08" PRIx32 "  data = 0x%016" PRIx64 " expected data = 0x%016" PRIx64 "     FAIL",
indirect_address, read_data, data);
ccam->arg.error_print_function(ccam->arg.ctx, message);
} else if (ccam->arg.debug_flags & CCAM_DEBUG_VERBOSE_VERIFY) {
sprintf(message,
                   "CCAM_DEBUG_VERIFY_WR  address = 0x%08" PRIx32 "  data = 0x%016" PRIx64 " expected data = 0x%016" PRIx64 "     OK",
indirect_address, read_data, data);
ccam->arg.info_print_function(ccam->arg.ctx, message);
}
}
}
void ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(const struct ccam *ccam, uint32_t direct_address, uint32_t data) {
ccam->arg.hw_write_function(ccam->arg.ctx, direct_address, data);
if (ccam->arg.debug_flags & CCAM_DEBUG_VERIFY_WR) {
char message[MSG_SZ];
uint32_t read_data;
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, direct_address, &read_data);
if (read_data != data) {
sprintf(message,
                   "CCAM_DEBUG_VERIFY_WR  address = 0x%08" PRIx32 "  data = 0x%08" PRIx32 " expected data = 0x%08" PRIx32 "     FAIL",
direct_address, read_data, data);
ccam->arg.error_print_function(ccam->arg.ctx, message);
} else if (ccam->arg.debug_flags & CCAM_DEBUG_VERBOSE_VERIFY) {
sprintf(message,
                   "CCAM_DEBUG_VERIFY_WR  address = 0x%08" PRIx32 "  data = 0x%08" PRIx32 " expected data = 0x%08" PRIx32 "     OK",
direct_address, read_data, data);
ccam->arg.info_print_function(ccam->arg.ctx, message);
}
}
}
void ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(const struct ccam *ccam, uint32_t direct_address, uint32_t *data) {
ccam->arg.hw_read_function(ccam->arg.ctx, direct_address, data);
}
static void read_rate_counters(const struct ccam *ccam, struct ccam_rate_counters *rate_counters) {
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, &rate_counters->inserts);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP_aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, &rate_counters->lookups);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, &rate_counters->hits);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaa1aaaEXT_EVENT_aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, &rate_counters->external_events);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaa1aaaLI_REQ_WS_aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, &rate_counters->lookup_request_wait_states);
}
static void read_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup_data(const struct ccam *ccam, struct ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup *aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup) {
const uint8_t key_num_words = ccam->config.key_width / 32;
for (uint8_t i = 0; i < key_num_words; i++) {
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP_KEY + i * 4, (uint32_t *) &(aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup->key[i * 4]));
}
const uint8_t key_rem_bits = ccam->config.key_width - key_num_words * 32;
if (key_rem_bits) {
uint32_t rem_word;
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP_KEY + key_num_words * 4, &rem_word);
cam_write_field8((uint8_t *) &aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup->key[key_num_words * 4], (uint8_t *) &rem_word, 0, key_rem_bits);
}
const uint8_t response_num_words = ccam->config.response_width / 32;
for (uint8_t i = 0; i < response_num_words; i++) {
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP_RESPONSE + i * 4, (uint32_t *) &(aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup->response[i * 4]));
}
const uint8_t response_rem_bits = ccam->config.response_width - response_num_words * 32;
if (response_rem_bits) {
uint32_t rem_word;
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP_RESPONSE + response_num_words * 4, &rem_word);
cam_write_field8((uint8_t *) &aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup->response[response_num_words * 4], (uint8_t *) &rem_word, 0,
response_rem_bits);
}
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP_STATUS, &aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup->status);
}
static void read_iteration_counts(const struct ccam *ccam, struct ccam_iteration_count *iteration_counts) {
uint32_t total_hi, total_lo;
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaTAL_NUM_PASS_aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, &total_lo);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaTAL_NUM_PASS_aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, &total_hi);
iteration_counts->total_iterations = (((uint64_t)total_hi) << 32) | total_lo;
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaDET_NUM_PASS_aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, &iteration_counts->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaiterations);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaDET_NUM_PASS_aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, &iteration_counts->max_iterations);
}
static void read_config(struct ccam *ccam) {
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaa1aaaVERSION_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, &ccam->config.hw_version);
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa, &ccam->config.key_width);
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa, &ccam->config.prio_width);
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaRESP_WIDTH, &ccam->config.response_width);
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaTIME_SLOTS, &ccam->config.num_slots);
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaaS, &ccam->config.phys_units);
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaaaaa1aaaDATA, &ccam->config.ram_data_width);
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaR, &ccam->config.ram_addresses);
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, &ccam->config.instance_type);
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaa4aaa, &ccam->config.num_entries); 
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaS, &ccam->config.num_masks); 
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaCACHE_EN, &ccam->config.cache_en);
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaBUILD_NUM, &ccam->config.hw_build_num);
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaASIC, &ccam->config.asic);
if (ccam->config.asic) {
ccam->config.aging_en = 1;
ccam->config.hw_stats_en = 1;
} else {
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaAGING_EN, &ccam->config.aging_en);
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaSTATS_EN, &ccam->config.hw_stats_en);
}
}
static int scratch_test(struct ccam *ccam) {
const uint64_t write_data = 0xfedcba9876543210;
uint32_t read_data[2] = {0};
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaSCRATCH, write_data);
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaSCRATCH, &read_data[0]);
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaSCRATCH + 4, &read_data[1]);
int rc = 0;
bool err;
err = read_data[0] != (write_data & 0xffffffff) ||
read_data[1] != (write_data >> 32);
if (err || (ccam->arg.debug_flags & CCAM_DEBUG_VERBOSE_VERIFY)) {
if (err) {
rc = CCAM_ERROR_ENVIRONMENT;
}
char sub_str[512];
char message[1024];
       sprintf(sub_str, "Scratch read-back = 0x%08" PRIx32 "%08" PRIx32 " (expected 0x%016" PRIx64 ")",
read_data[1], read_data[0], write_data);
       sprintf(message, "%-26s%-70s%s",
               err ? ccam_error_string(rc) : "CAM_DEBUG_VERBOSE_VERIFY",
               sub_str, err ? "FAIL" : "OK");
if (err) {
ccam->arg.error_print_function(ccam->arg.ctx, message);
} else {
ccam->arg.info_print_function(ccam->arg.ctx, message);
}
}
return rc;
}
int ccam_clear(const struct ccam *ccam) {
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, 0x10001);
uint32_t count = 0;
uint32_t data;
do {
if (count >= POLL_aaaaaaaaaaaaaaaaaaaaaaaa1aaa)
return CCAM_ERROR_ENVIRONMENT_POLLED_OUT;
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, &data);
count++;
} while ((data & 1) != 0);
return 0;
}
static void dummy_wr_function(void *ctx, uint32_t address, uint32_t data) {
(void) ctx;
(void) address;
(void) data;
}
static void dummy_rd_function(void *ctx, uint32_t address, uint32_t *data) {
(void) ctx;
(void) address;
(void) data;
}
static void default_error_print_function(void *inst_ctx, char *message) {
(void) inst_ctx; 
   fprintf(stderr, "** Error: %s\n", message);
}
static void default_info_print_function(void *inst_ctx, char *message) {
(void) inst_ctx; 
   fprintf(stdout, "** Info:  %s\n", message);
}
int ccam_poll_status(struct ccam *ccam) {
aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaENUM status;
uint32_t count = 0;
do {
if (count == POLL_aaaaaaaaaaaaaaaaaaaaaaaa1aaa)
return CCAM_ERROR_ENVIRONMENT_POLLED_OUT;
uint32_t data;
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, &data);
status = data & 7;
count++;
} while (status == aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaFSMBUSY);
if (count > 1) {
ccam->sw_stats.poll_count += count;
}
int rc;
switch (status) {
case aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaFULL:
ccam->blocked = true;
rc = CCAM_ERROR_FULL;
break;
case aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaNOTFOUND:
rc = CCAM_ERROR_NOT_FOUND;
break;
case aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaDUPLICATEKEY:
rc = CCAM_ERROR_DUPLICATE_FOUND;
break;
case aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaNOTFOUND:
rc = CCAM_ERROR_ENVIRONMENT;
break;
case aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaSUCCESS:
ccam->blocked = false;
rc = 0;
break;
case aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaSUCCESSBLOCKED:
ccam->blocked = true;
rc = 0;
break;
default: 
rc = CCAM_ERROR_ENVIRONMENT;
break;
}
return rc;
}
void ccam_set_resp(const struct ccam *ccam, const uint8_t response[]) {
uint32_t num_words = ccam->config.response_width / NUM_BITS_IN_DWORD;
const uint32_t remaining_bits = ccam->config.response_width -
(num_words * NUM_BITS_IN_DWORD);
uint32_t *response32 = (uint32_t *) &response[0];
uint32_t aaaaaaaaaaaaaaaaaaaaaa1aaa = aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaDATA_00_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa;
for (uint32_t count = 0; count < num_words; count++) {
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaaaa1aaa, *response32);
aaaaaaaaaaaaaaaaaaaaaa1aaa += NUM_BYTES_IN_DWORD;
response32++;
}
if (remaining_bits > 0) {
uint32_t data = 0;
cam_read_field8((uint8_t *) &data, (uint8_t *) response32, 0, remaining_bits);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaaaa1aaa, data);
}
}
void ccam_set_key(const struct ccam *ccam, const uint8_t key[]) {
uint32_t num_words = ccam->config.key_width / NUM_BITS_IN_DWORD;
const uint32_t remaining_bits = ccam->config.key_width - (num_words * NUM_BITS_IN_DWORD);
uint32_t *key32 = (uint32_t *) &key[0];
uint32_t aaaaaaaaaaaaaaaaaaaaaa1aaa = aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaDATA_00_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa;
for (uint8_t count = 0; count < num_words; count++) {
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaaaa1aaa, *key32);
aaaaaaaaaaaaaaaaaaaaaa1aaa += NUM_BYTES_IN_DWORD;
key32++;
}
if (remaining_bits > 0) {
uint32_t data = 0;
cam_read_field8((uint8_t *) &data, (uint8_t *) key32, 0, remaining_bits);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaaaa1aaa, data);
}
}
void ccam_get_key(const struct ccam *ccam, uint8_t key[]) {
const uint32_t num_words = ccam->config.key_width / NUM_BITS_IN_DWORD;
const uint32_t remaining_bits = ccam->config.key_width - (num_words * NUM_BITS_IN_DWORD);
uint32_t aaaaaaaaaaaaaaaaaaaaaa1aaa = aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaDATA_00_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa;
uint32_t *key32 = (uint32_t *) &key[0];
for (uint32_t count = 0; count < num_words; count++) {
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaaaa1aaa, key32);
aaaaaaaaaaaaaaaaaaaaaa1aaa += NUM_BYTES_IN_DWORD;
key32++;
}
if (remaining_bits > 0) {
uint32_t data;
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaaaa1aaa, &data);
cam_write_field8((uint8_t *) key32, (uint8_t *) &data, 0, remaining_bits);
}
}
void ccam_get_resp(const struct ccam *ccam, uint8_t response[]) {
const uint32_t num_words = ccam->config.response_width / NUM_BITS_IN_DWORD;
const uint32_t remaining_bits = ccam->config.response_width -
(num_words * NUM_BITS_IN_DWORD);
uint32_t aaaaaaaaaaaaaaaaaaaaaa1aaa = aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaDATA_00_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa;
uint32_t *response32 = (uint32_t *) &response[0];
for (uint32_t count = 0; count < num_words; count++) {
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaaaa1aaa, response32);
aaaaaaaaaaaaaaaaaaaaaa1aaa += NUM_BYTES_IN_DWORD;
response32++;
}
if (remaining_bits > 0) {
uint32_t data;
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaaaa1aaa, &data);
cam_write_field8((uint8_t *) response32, (uint8_t *) &data, 0, remaining_bits);
}
}
uint32_t ccam_calculate_max_num_entries(const struct ccam *ccam) {
return ccam->config.phys_units * ccam->config.ram_addresses * CCAM_FILL_RATIO;
}
static char* get_depth_and_width_info(const struct ccam_config *config, uint32_t num_entries) {
static char message[100];
int mem_width = config->ram_data_width;
uint8_t control = 1;
int32_t unused = mem_width - config->key_width - config->response_width - control;
char prio[13];
if (config->instance_type == INSTANCE_CSTCAM) {
unused -= config->prio_width;
       sprintf(prio, " + %5"PRIu32"    ", config->prio_width);
} else {
       sprintf(prio, " ");
}
char aging[13];
if (config->aging_en) {
unused -= CCAM_AGING_BITS;
       sprintf(aging, " + %3"PRIu32"   ", CCAM_AGING_BITS);
} else {
       sprintf(aging, " ");
}
   sprintf(message, "%17"PRIu32" x %5"PRIu32" (%3"PRIu32" +   %4"PRIu32"  %s+   %"PRIu8"  %s+  %3"PRIi32")",
num_entries, mem_width, config->key_width,
config->response_width, &prio[0],
control, &aging[0], unused);
return &message[0];
}
static char* get_ram_utilization_info(const struct ccam *ccam) {
static char message[150];
int used = ccam->config.key_width + ccam->config.response_width + 1 + CCAM_AGING_BITS + ccam->config.prio_width;
uint32_t num_entries = ccam->config.num_entries;
uint32_t num_entries_max = ccam->config.phys_units * ccam->config.ram_addresses * CCAM_FILL_RATIO;
   char num_entries_info[20] = "";
if (ccam->config.instance_type == INSTANCE_CSTCAM) {
if (ccam->arg.optimization_flags & CCAM_OPTIMIZE_MASKS) {
           sprintf(num_entries_info, "(up to) ");
}
if (ccam->arg.optimization_flags & CCAM_OPTIMIZE_ENTRIES) {
           sprintf(num_entries_info, "(up to) ");
num_entries = num_entries_max;
}
}
if (ccam->config.instance_type == INSTANCE_CBCAM) {
if (ccam->config.num_entries == num_entries_max) {
           sprintf(num_entries_info, "(max) ");
}
if (ccam->arg.optimization_flags & CCAM_OPTIMIZE_ENTRIES) {
           sprintf(num_entries_info, "(max) ");
num_entries = num_entries_max;
}
}
uint32_t depth_util = 0;
uint32_t divisor = ccam->config.ram_addresses * ccam->config.phys_units;
if (divisor != 0)
depth_util = (100 * num_entries + (divisor / 2)) / divisor;
uint32_t width_util = 0;
if (ccam->config.ram_data_width != 0)
width_util = (100 * used + ccam->config.ram_data_width / 2) / ccam->config.ram_data_width;
int total_util = 0;
divisor = ccam->config.phys_units * ccam->config.ram_addresses * ccam->config.ram_data_width;
if (divisor != 0)
total_util = (100 * num_entries * used + divisor / 2) / divisor;
   sprintf(message, " Depth %s%d%% (%d / %d) x Width %d%% (%d / %d) = Total %d%%", num_entries_info, depth_util,
num_entries, ccam->config.phys_units * ccam->config.ram_addresses, width_util, used,
ccam->config.ram_data_width,
total_util);
return &message[0];
}
static char* get_memory_units_info(const struct ccam_config *config) {
static char message[150];
   sprintf(message, " %d logical / %d physical", config->phys_units * config->num_slots, config->phys_units);
return &message[0];
}
static void print_config(const struct ccam *ccam) {
char message[500];
char patch[10];
const char *padding =
           "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
int col_top[3] = { 25, 78, 22 };
   sprintf(message, " ");
ccam->arg.info_print_function(ccam->arg.ctx, message);
ccam->arg.info_print_function(ccam->arg.ctx, message);
if (CCAM_SW_VERSION_PATCH == 0)
patch[0] = '\0';
else
       sprintf(patch, ".%d", CCAM_SW_VERSION_PATCH);
   sprintf(message, "SW Version %d.%d%s, Build %d", CCAM_SW_VERSION_MAJOR,
CCAM_SW_VERSION_MINOR, patch, CCAM_BUILD_NUMBER);
ccam->arg.info_print_function(ccam->arg.ctx, message);
if ((ccam->config.hw_version & 0x000f) == 0)
patch[0] = '\0';
else
       sprintf(patch, ".%"PRIu8, ccam->config.hw_version & 0x000f);
   sprintf(message, "HW Version %"PRIu8".%"PRIu8"%s, Build %"PRIu32"  %s",
(ccam->config.hw_version & 0xff00) >> 8, (ccam->config.hw_version & 0x00f0) >> 4,
           patch, ccam->config.hw_build_num, ccam->config.asic ? "ASIC" : "");
ccam->arg.info_print_function(ccam->arg.ctx, message);
   sprintf(message, "+%-.*s+%-.*s+", col_top[0], padding, col_top[1], padding);
ccam->arg.info_print_function(ccam->arg.ctx, message);
uint32_t num_entries = ccam->config.num_entries;
   char num_entries_info[150] = "    Depth (fixed)";
if (ccam->arg.optimization_flags & CCAM_OPTIMIZE_MASKS) {
if (ccam->config.instance_type == INSTANCE_CSTCAM) {
           sprintf(num_entries_info, "    Depth (up to)");
}
}
if (ccam->arg.optimization_flags & CCAM_OPTIMIZE_ENTRIES) {
num_entries = ccam_calculate_max_num_entries(ccam);
if (num_entries > ccam->config.num_entries) {
if (ccam->config.instance_type == INSTANCE_CBCAM) {
               sprintf(num_entries_info, "Depth (optimized)");
}
if (ccam->config.instance_type == INSTANCE_CSTCAM) {
               sprintf(num_entries_info, "    Depth (up to)");
}
}
}
char *message_pos = &num_entries_info[0];
message_pos += strlen(message_pos);
   sprintf(message_pos, " x Width (Key + Response %s+ Valid %s+ Unused)",
           ccam->config.instance_type == INSTANCE_CSTCAM ? "+ Priority " : "",
           ccam->config.aging_en ? "+ Aging " : "");
   sprintf(message, "|%-*s|%-*s|", col_top[0], " Instance Type", col_top[1], num_entries_info);
ccam->arg.info_print_function(ccam->arg.ctx, message);
   sprintf(message, "+%-.*s+%-.*s+", col_top[0], padding, col_top[1], padding);
ccam->arg.info_print_function(ccam->arg.ctx, message);
char instance[50];
if (ccam->config.instance_type == INSTANCE_CSTCAM) {
uint16_t max_num_masks = ccam->config.num_masks;
if (ccam->arg.optimization_flags & CCAM_OPTIMIZE_MASKS)
max_num_masks = ccam->config.phys_units * ccam->config.num_slots;
       sprintf(instance, " %d-Mask %s CSTCAM", max_num_masks,
((ccam->arg.optimization_flags & CCAM_OPTIMIZE_MASKS)
                       || (ccam->arg.optimization_flags & CCAM_OPTIMIZE_ENTRIES)) ? "(up to) " : "");
}
else
       sprintf(instance, " CBCAM");
   sprintf(message, "|%-*s|%-*s|", col_top[0], instance, col_top[1], get_depth_and_width_info(&ccam->config, num_entries));
ccam->arg.info_print_function(ccam->arg.ctx, message);
   sprintf(message, "+%-.*s+%-.*s+", col_top[0], padding, col_top[1], padding);
ccam->arg.info_print_function(ccam->arg.ctx, message);
   sprintf(message, " ");
ccam->arg.info_print_function(ccam->arg.ctx, message);
int col[2] = { 28, 75 };
   sprintf(message, "+%-.*s+%-.*s+", col[0], padding, col[1], padding);
ccam->arg.info_print_function(ccam->arg.ctx, message);
char slot_info[50];
   sprintf(slot_info, " %d", ccam->config.num_slots);
   sprintf(message, "|%-*s|%-*s|", col[0], " TDM Factor", col[1], slot_info);
ccam->arg.info_print_function(ccam->arg.ctx, message);
   sprintf(message, "+%-.*s+%-.*s+", col[0], padding, col[1], padding);
ccam->arg.info_print_function(ccam->arg.ctx, message);
   sprintf(message, "|%-*s|%-*s|", col[0], " Memory units", col[1], get_memory_units_info(&ccam->config));
ccam->arg.info_print_function(ccam->arg.ctx, message);
   sprintf(message, "+%-.*s+%-.*s+", col[0], padding, col[1], padding);
ccam->arg.info_print_function(ccam->arg.ctx, message);
   sprintf(message, "|%-*s|%-*s|", col[0], " RAM utilization", col[1],
get_ram_utilization_info(ccam));
ccam->arg.info_print_function(ccam->arg.ctx, message);
   sprintf(message, "+%-.*s+%-.*s+", col[0], padding, col[1], padding);
ccam->arg.info_print_function(ccam->arg.ctx, message);
const char *flag_str[32] = { NULL };
   flag_str[2] = " CCAM_OPTIMIZE_ENTRIES";
   flag_str[3] = " CCAM_OPTIMIZE_MASKS";
bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa = true;
for (int i = 0; i < 32; i++) {
uint32_t flag = 1 << i;
if ((ccam->arg.optimization_flags & flag) != 0 && flag_str[i] != NULL) {
           sprintf(message, "|%-*s|%-*s|", col[0], aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa ? " Optimization flags" : "", col[1], flag_str[i]);
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa = false;
ccam->arg.info_print_function(ccam->arg.ctx, message);
}
}
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa) {
       sprintf(message, "|%-*s|%-*s|", col[0], " Optimization flags", col[1], " CCAM_OPTIMIZE_NONE");
ccam->arg.info_print_function(ccam->arg.ctx, message);
}
   sprintf(message, "+%-.*s+%-.*s+", col[0], padding, col[1], padding);
ccam->arg.info_print_function(ccam->arg.ctx, message);
   flag_str[0] = " CCAM_DEBUG_NO_ERROR_MSG";
   flag_str[1] = " CCAM_DEBUG_ARGS";
   flag_str[2] = " CCAM_DEBUG_VERIFY_WR";
   flag_str[4] = " CCAM_DEBUG_VERBOSE_VERIFY";
   flag_str[5] = " CCAM_DEBUG_SKIP_MEM_INIT";
   flag_str[6] = " CCAM_DEBUG_CONFIG";
   flag_str[9] = " CCAM_DEBUG_STATS";
   flag_str[16] = " CCAM_DEBUG_HW_WR";
   flag_str[17] = " CCAM_DEBUG_HW_RD";
   flag_str[18] = " CCAM_DEBUG_HW_LOOKUP";
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa = true;
for (int i = 0; i < 32; i++) {
uint32_t flag = 1 << i;
if ((ccam->arg.debug_flags & flag) != 0 && flag_str[i] != NULL) {
           sprintf(message, "|%-*s|%-*s|", col[0], aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa ? " Debug flags" : "", col[1], flag_str[i]);
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa = false;
ccam->arg.info_print_function(ccam->arg.ctx, message);
}
}
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa) {
       sprintf(message, "|%-*s|%-*s|", col[0], " Debug flags", col[1], " CAM_DEBUG_NONE");
ccam->arg.info_print_function(ccam->arg.ctx, message);
}
   sprintf(message, "+%-.*s+%-.*s+", col[0], padding, col[1], padding);
ccam->arg.info_print_function(ccam->arg.ctx, message);
}
bool ccam_is_cache(const struct ccam *ccam) {
if (ccam->config.cache_en)
return true;
return false;
}
int ccam_init(const struct ccam_arg *arg, struct ccam *ccam) {
ccam->arg = *arg;
if (ccam->arg.hw_read_function == NULL)
ccam->arg.hw_read_function = dummy_rd_function;
if (ccam->arg.hw_write_function == NULL)
ccam->arg.hw_write_function = dummy_wr_function;
if (ccam->arg.error_print_function == NULL)
ccam->arg.error_print_function = default_error_print_function;
if (ccam->arg.info_print_function == NULL)
ccam->arg.info_print_function = default_info_print_function;
read_config(ccam);
if (ccam->arg.debug_flags & CCAM_DEBUG_CONFIG) {
print_config(ccam);
}
int rc = 0;
rc = scratch_test(ccam);
if (rc)
return rc;
if (!(ccam->arg.debug_flags & CCAM_DEBUG_SKIP_MEM_INIT)) {
rc = ccam_clear(ccam);
}
if (rc)
return rc;
if(ccam->config.hw_stats_en) {
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaPER_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, CCAM_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa100US);
}
return 0;
}
int ccam_read_and_clear_ecc_counters(const struct ccam *ccam, uint32_t *corrected_single_bit_errors,
uint32_t *detected_double_bit_errors)
{
NULL_CHECK(ccam);
NULL_CHECK(corrected_single_bit_errors);
NULL_CHECK(detected_double_bit_errors);
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaSBITERR_CNT, corrected_single_bit_errors);
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaDBITERR_CNT, detected_double_bit_errors);
   ccam_print_entry(0, "ccam_read_and_clear_ecc_counters", ccam, NULL, NULL, NULL, "");
return 0;
}
int ccam_read_and_clear_ecc_addresses(const struct ccam *ccam, uint32_t *failing_address_single_bit_error,
uint32_t *failing_address_double_bit_error)
{
NULL_CHECK(ccam);
NULL_CHECK(failing_address_single_bit_error);
NULL_CHECK(failing_address_double_bit_error);
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaSBITERR_FFA, failing_address_single_bit_error);
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaDBITERR_FFA, failing_address_double_bit_error);
   ccam_print_entry(0, "ccam_read_and_clear_ecc_addresses", ccam, NULL, NULL, NULL, "");
return 0;
}
int ccam_set_ecc_test(struct ccam *ccam, bool inject_single_bit_errors, bool inject_double_bit_errors)
{
NULL_CHECK(ccam);
const uint32_t data = (inject_single_bit_errors ? 1 : 0) + (inject_double_bit_errors ? 2 : 0);
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaaa1aaaECC_TEST, data);
   ccam_print_entry(0, "ccam_set_ecc_test", ccam, NULL, NULL, NULL, "");
return 0;
}
int ccam_get_stats(const struct ccam *ccam, uint64_t group, union ccam_stats *stats)
{
NULL_CHECK(ccam);
NULL_CHECK(stats);
int rc = 0;
if (group == CCAM_STATS_SW) {
stats->sw = ccam->sw_stats;
} else if (group == CCAM_STATS_RATE) {
if (ccam->config.hw_stats_en == 0) {
rc = CCAM_ERROR_STATISTICS_NOT_AVAILABLE;
goto end;
}
read_rate_counters(ccam, &stats->rate);
} else if (group == CCAM_STATS_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP) {
if (ccam->config.hw_stats_en == 0) {
rc = CCAM_ERROR_STATISTICS_NOT_AVAILABLE;
goto end;
}
read_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup_data(ccam, &stats->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup);
} else if (group == CCAM_STATS_ITERATIONS) {
if (ccam->config.hw_stats_en == 0) {
rc = CCAM_ERROR_STATISTICS_NOT_AVAILABLE;
goto end;
}
read_iteration_counts(ccam, &stats->iteration_count);
} else {
rc = CCAM_ERROR_INVALID_ARG;
goto end;
}
if (ccam->arg.debug_flags & CCAM_DEBUG_STATS) {
char message[MSG_SZ];
if (group == CCAM_STATS_SW) {
           snprintf(message, sizeof(message), "CAM_DEBUG_STATS  inserts     = %6" PRIu64 " (%" PRIu64 " fail)",
ccam->sw_stats.num_inserts, ccam->sw_stats.failed_inserts);
ccam->arg.info_print_function(ccam->arg.ctx, message);
           snprintf(message, sizeof(message), "CAM_DEBUG_STATS  updates     = %6" PRIu64 " (%" PRIu64 " fail)",
ccam->sw_stats.num_updates, ccam->sw_stats.failed_updates);
ccam->arg.info_print_function(ccam->arg.ctx, message);
           snprintf(message, sizeof(message), "CAM_DEBUG_STATS  deletes     = %6" PRIu64 " (%" PRIu64 " fail)",
ccam->sw_stats.num_deletes, ccam->sw_stats.failed_deletes);
ccam->arg.info_print_function(ccam->arg.ctx, message);
           snprintf(message, sizeof(message), "CAM_DEBUG_STATS  num_entries = %6" PRIu32,
ccam->sw_stats.num_entries);
ccam->arg.info_print_function(ccam->arg.ctx, message);
           snprintf(message, sizeof(message), "CAM_DEBUG_STATS  num_polls   = %6" PRIu64,
ccam->sw_stats.poll_count);
ccam->arg.info_print_function(ccam->arg.ctx, message);
           snprintf(message, sizeof(message), "CAM_DEBUG_STATS  num_masks   = %6" PRIu16,
ccam->sw_stats.num_masks);
ccam->arg.info_print_function(ccam->arg.ctx, message);
} else if (group == CCAM_STATS_RATE) {
           snprintf(message, sizeof(message), "CAM_DEBUG_STATS  inserts                    = %6" PRIu32 "   (time stamp %" PRIu8 ")",
0x03ffffff & stats->rate.inserts, stats->rate.inserts >> 26);
ccam->arg.info_print_function(ccam->arg.ctx, message);
           snprintf(message, sizeof(message), "CAM_DEBUG_STATS  lookups                    = %6" PRIu32 "   (time stamp %" PRIu8 ")",
0x03ffffff & stats->rate.lookups, stats->rate.lookups >> 26);
ccam->arg.info_print_function(ccam->arg.ctx, message);
           snprintf(message, sizeof(message), "CAM_DEBUG_STATS  hits                       = %6" PRIu32 "   (time stamp %" PRIu8 ")",
0x03ffffff & stats->rate.hits, stats->rate.hits >> 26);
ccam->arg.info_print_function(ccam->arg.ctx, message);
           snprintf(message, sizeof(message), "CAM_DEBUG_STATS  lookup request wait states = %6" PRIu32 "   (time stamp %" PRIu8 ")",
0x03ffffff & stats->rate.lookup_request_wait_states, stats->rate.lookup_request_wait_states >> 26);
ccam->arg.info_print_function(ccam->arg.ctx, message);
           snprintf(message, sizeof(message), "CAM_DEBUG_STATS  external events            = %6" PRIu32 "   (time stamp %" PRIu8 ")",
0x03ffffff & stats->rate.external_events, stats->rate.external_events >> 26);
ccam->arg.info_print_function(ccam->arg.ctx, message);
} else if (group == CCAM_STATS_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP) {
char key_str[BYTE_ARR_SZ];
char response_str[BYTE_ARR_SZ];
byte_arr_to_str(ccam->config.key_width, stats->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup.key, key_str);
byte_arr_to_str(ccam->config.response_width, stats->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup.response, response_str);
           snprintf(message, sizeof(message), "CAM_DEBUG_STATS  last key      = %s", key_str);
ccam->arg.info_print_function(ccam->arg.ctx, message);
           snprintf(message, sizeof(message), "CAM_DEBUG_STATS  last response = %s   %s   (%s)",
response_str,
                    stats->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup.status & 1 ? "KEY_MATCH" : "DEFAULT_MATCH",
                    stats->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup.status & 2 ? "DBIT_ERR" : "NO_DBIT_ERR");
ccam->arg.info_print_function(ccam->arg.ctx, message);
} else if (group == CCAM_STATS_ITERATIONS) {
           snprintf(message, sizeof(message), "CAM_DEBUG_STATS  total iterations           = %6" PRIu64,
stats->iteration_count.total_iterations);
ccam->arg.info_print_function(ccam->arg.ctx, message);
           snprintf(message, sizeof(message), "CAM_DEBUG_STATS  iterations for last insert = %6" PRIu32,
stats->iteration_count.aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaiterations);
ccam->arg.info_print_function(ccam->arg.ctx, message);
           snprintf(message, sizeof(message), "CAM_DEBUG_STATS  max iterations for insert  = %6" PRIu32,
stats->iteration_count.max_iterations);
ccam->arg.info_print_function(ccam->arg.ctx, message);
}
}
   end: ccam_print_entry(rc, "ccam_get_stats", ccam, NULL, NULL, NULL, "");
return rc;
}
uint32_t ccam_calculate_base_address(const struct ccam *ccam, uint16_t unit, uint32_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber) {
uint32_t num_entries = ccam->config.ram_addresses / ccam->config.num_slots;
assert(aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber < num_entries);
const uint8_t phys_unit = unit / ccam->config.num_slots;
const uint8_t slot_number = unit - phys_unit * ccam->config.num_slots;
const uint32_t phys_address = num_entries * slot_number + aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber;
assert(phys_address < ccam->config.ram_addresses);
const uint32_t base = aaaaaa1aaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa + phys_unit * aaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa + phys_address * aaaaaa1aaaaaaa1aaaWORD;
return base;
}
int ccam_read_entry(struct ccam *ccam, uint16_t unit, uint32_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber, bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaa1aaa) {
const uint32_t base = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaa1aaa ? aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaa1aaa :
ccam_calculate_base_address(ccam, unit, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, base);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaa1aaaOPERATION_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaRDBYADDR);
int rc = ccam_poll_status(ccam);
assert(rc == 0);
uint32_t valid_data;
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa(ccam, aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaCTRL_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, &valid_data);
if (!(valid_data & 0x80000000))
return CCAM_ERROR_NOT_FOUND;
return 0;
}
bool ccam_is_blocked(const struct ccam *ccam) {
return ccam->blocked;
}
int ccam_get_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaby_response(struct ccam *ccam, const uint8_t response[], const uint8_t response_mask[],
uint16_t unit, uint32_t *start_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber) {
const uint32_t num_entries = ccam->config.ram_addresses / ccam->config.num_slots;
uint8_t cleared_response_mask[(CCAM_MAX_RESPONSE_WIDTH + 7) / 8];
cleared_response_mask[(CCAM_MAX_RESPONSE_WIDTH + 7) / 8 - 1] = 0;
cam_read_field8(cleared_response_mask, response_mask, 0, ccam->config.response_width);
for (uint16_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber = *start_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber; aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber < num_entries; aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber++) {
if (0 == ccam_read_entry(ccam, unit, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber, false)) {
uint8_t read_response[(CCAM_MAX_RESPONSE_WIDTH + 7) / 8];
ccam_get_resp(ccam, &read_response[0]);
bool match = true;
for (uint16_t i = 0; i < (ccam->config.response_width + 7) / 8; i++) {
if ((read_response[i] & response_mask[i]) != (response[i] & response_mask[i])) {
match = false;
break;
}
}
if (match) {
*start_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber;
return 0;
}
}
}
return CCAM_ERROR_NOT_FOUND;
}
int ccam_get_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaby_response(struct ccam *ccam, const uint8_t response[], const uint8_t response_mask[]) {
uint8_t cleared_response_mask[(CCAM_MAX_RESPONSE_WIDTH + 7) / 8];
cleared_response_mask[(CCAM_MAX_RESPONSE_WIDTH + 7) / 8 - 1] = 0;
cam_read_field8(cleared_response_mask, response_mask, 0, ccam->config.response_width);
if (ccam_is_blocked(ccam) == true) {
if (0 == ccam_read_entry(ccam, 0, 0, true)) {
uint8_t read_response[(CCAM_MAX_RESPONSE_WIDTH + 7) / 8];
ccam_get_resp(ccam, &read_response[0]);
bool match = true;
for (uint16_t i = 0; i < (ccam->config.response_width + 7) / 8; i++) {
if ((read_response[i] & response_mask[i]) != (response[i] & response_mask[i])) {
match = false;
break;
}
}
if (match) {
return 0;
}
}
}
return CCAM_ERROR_NOT_FOUND;
}
#ifndef _CSTCAM_H_
#define _CSTCAM_H_
#ifdef __cplusplus
extern "C" {
#endif
struct cstcam;
size_t cstcam_size(void);
int cstcam_init(const struct ccam_arg *arg, struct cstcam *cstcam);
int cstcam_insert(struct cstcam *cstcam, const uint8_t key[], const uint8_t mask[], uint32_t priority,
const uint8_t response[]);
int cstcam_update(struct cstcam *cstcam, const uint8_t key[], const uint8_t mask[], const uint8_t response[]);
int cstcam_get_by_key(struct cstcam *cstcam, const uint8_t key[], const uint8_t mask[], uint8_t response[]);
int cstcam_delete(struct cstcam *cstcam, const uint8_t key[], const uint8_t mask[]);
int cstcam_get_by_response(struct cstcam *cstcam, const uint8_t in_response[], const uint8_t response_mask[],
uint32_t *pos, uint8_t out_key[], uint8_t out_mask[], uint8_t out_response[], uint32_t *out_prio);
#define CSTCAM_MAX_MASKS 64
#define CSTCAM_STATS_EFFICIENCY 0
#define CSTCAM_STATS_MEMORY_USAGE 1
struct cstcam_mask_efficiency {
struct tuple {
uint16_t mask_id;
uint32_t efficiency;
} tuple[CSTCAM_MAX_MASKS];
uint8_t num_masks;
};
struct cstcam_mask_memory_usage {
uint32_t num_masks;
uint32_t phys_units;
uint32_t num_slots;
struct {
uint32_t mask_id;
uint32_t num_mus;
} usage[CSTCAM_MAX_MASKS];
};
union cstcam_stats {
struct cstcam_mask_efficiency mask_efficiency;
struct cstcam_mask_memory_usage memory_usage;
struct cstcam_reserved {
uint8_t resv[1000];
} reserved;
};
int cstcam_get_stats(const struct cstcam *cstcam, uint64_t stats_group, union cstcam_stats *stats);
int cstcam_mu_alloc(struct cstcam *cstcam, const uint8_t mask[], uint16_t mask_id);
int cstcam_mu_free(struct cstcam *cstcam, uint16_t mask_id);
#define CSTCAM_MAX_MASK_IDS 1024
int cstcam_insert_by_id(struct cstcam *cstcam, const uint8_t key[], uint16_t mask_id,
const uint8_t response[]);
int cstcam_delete_by_id(struct cstcam *cstcam, const uint8_t key[], uint16_t mask_id);
int cstcam_update_by_id(struct cstcam *cstcam, const uint8_t key[], uint16_t mask_id, const uint8_t response[]);
int cstcam_mask_alloc(struct cstcam *cstcam, const uint8_t mask[], uint32_t priority, uint16_t *mask_id);
int cstcam_mask_free(struct cstcam *cstcam, uint16_t mask_id);
#ifdef __cplusplus
}
#endif
#endif
#define SHIFT32BIT 32
#define MIN_UNITS_PER_MASK 1
#define MAX_UNITS 256
typedef struct {
uint8_t mask[(CCAM_MAX_KEY_WIDTH + 7) / 8];
bool enabled;
uint16_t mask_id;
} unit_t;
typedef struct {
uint32_t num_entries;
uint32_t priority;
bool used;
bool compressed;
} mask_id_t;
#define MASK_API_IS_UNDETERMINED 0
#define MASK_API_IS_MASK_ID 1
#define MASK_API_IS_MASK 2
struct cstcam {
struct ccam ccam;
mask_id_t mask_ids[CSTCAM_MAX_MASK_IDS];
unit_t units[MAX_UNITS];
uint8_t mask_id_mode;
};
static void invalidate_entry(const struct cstcam *cstcam, uint16_t unit, uint32_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber) {
const uint32_t base = ccam_calculate_base_address((const struct ccam *) cstcam, unit, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((const struct ccam *) cstcam, aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, base);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((const struct ccam *) cstcam, aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaCTRL_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, 0);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((const struct ccam *) cstcam, aaaaaaaaaaaaaaaaaaa1aaaOPERATION_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa,
aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaWRBYADDR);
}
static uint16_t get_num_units(const struct cstcam *cstcam, uint16_t mask_id) {
const uint16_t max_num_units = cstcam->ccam.config.phys_units * cstcam->ccam.config.num_slots;
uint16_t num_units = 0;
for (uint16_t i = 0; i < max_num_units; i++) {
if (cstcam->units[i].enabled == false)
continue;
if (mask_id == cstcam->units[i].mask_id) {
num_units++;
}
}
return num_units;
}
static bool free_memory_unit_available(const struct cstcam *cstcam) {
uint16_t max_num_units = cstcam->ccam.config.phys_units * cstcam->ccam.config.num_slots;
for (uint16_t i = 0; i < max_num_units; i++) {
if (!cstcam->units[i].enabled) {
return true;
}
}
return false;
}
static bool is_mask_full(const struct cstcam *cstcam, uint16_t mask_id) {
const uint16_t num_units = get_num_units(cstcam, mask_id);
if (num_units < 2)
return false;
uint32_t max_num_entries = num_units * cstcam->ccam.config.ram_addresses / cstcam->ccam.config.num_slots;
if (num_units == 2)
max_num_entries = max_num_entries * CCAM_2W_aaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa;
else if (num_units == 3)
max_num_entries = max_num_entries * CCAM_3W_aaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa;
else
max_num_entries = max_num_entries * CCAM_FILL_RATIO;
if (cstcam->mask_ids[mask_id].num_entries >= max_num_entries)
return true;
return false;
}
static void set_priority(const struct cstcam *cstcam, uint16_t priority) {
const uint32_t aaaaaaaaaaaaaaaaaaaaaa1aaa = aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaaRITY_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa;
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((struct ccam *) cstcam, aaaaaaaaaaaaaaaaaaaaaa1aaa, priority);
}
static uint32_t get_priority_from_mask_id(struct cstcam *cstcam, uint16_t mask_id) {
assert(mask_id < CSTCAM_MAX_MASK_IDS);
assert(cstcam->mask_ids[mask_id].used == true);
return cstcam->mask_ids[mask_id].priority;
}
#define BITS(N) (32 - __builtin_clz((uint32_t) (N)))
static bool is_mask_under_filled(const struct cstcam *cstcam, uint16_t mask_id) {
uint16_t num_units = get_num_units(cstcam, mask_id);
if (num_units)
num_units--; 
if (num_units == 0)
return false;
uint32_t max_num_entries = num_units * cstcam->ccam.config.ram_addresses / cstcam->ccam.config.num_slots;
if (num_units < 2) {
max_num_entries = 1 << ((BITS(max_num_entries) - 1) / 2);
} else if (num_units == 2) {
max_num_entries = max_num_entries * CCAM_2W_aaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa;
} else if (num_units == 3) {
max_num_entries = max_num_entries * CCAM_3W_aaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa;
} else {
max_num_entries = max_num_entries * CCAM_FILL_RATIO;
}
if (cstcam->mask_ids[mask_id].num_entries <= max_num_entries)
return true;
return false;
}
static int aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa(const struct cstcam *cstcam, uint16_t mask_id, uint16_t *start_unit) {
const uint16_t max_num_units = cstcam->ccam.config.phys_units * cstcam->ccam.config.num_slots;
for (uint16_t i = *start_unit; i < max_num_units; i++) {
if (cstcam->units[i].enabled == false)
continue;
if (mask_id == cstcam->units[i].mask_id) {
*start_unit = i;
return 0;
}
}
return CCAM_ERROR_NOT_FOUND;
}
static void write_mask(struct cstcam *cstcam, bool write_mask, uint16_t unit, bool valid,
bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaenable);
static void set_mask_id(const struct cstcam *cstcam, uint16_t mask_id);
static void free_unit(struct cstcam *cstcam, uint16_t unit);
static int aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaexisting_memory_unit(struct cstcam *cstcam, const uint8_t key[], uint32_t priority,
const uint8_t response[], uint16_t mask_id);
static int empty_one_memory_unit(struct cstcam *cstcam) {
const uint32_t num_entries = cstcam->ccam.config.ram_addresses / cstcam->ccam.config.num_slots;
for (uint16_t mask_id = 0; mask_id < CSTCAM_MAX_MASK_IDS; mask_id++) {
if (cstcam->mask_ids[mask_id].used == true && cstcam->mask_ids[mask_id].compressed == false) {
if (true == is_mask_under_filled(cstcam, mask_id)) { 
uint16_t unit = 0;
int rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa(cstcam, mask_id, &unit);
assert(rc == 0);
write_mask(cstcam, false, unit, true, false);
set_mask_id(cstcam, mask_id);
if (cstcam->ccam.config.asic) {
set_priority(cstcam, get_priority_from_mask_id(cstcam, mask_id));
}
for (uint16_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber = 0; aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber < num_entries; aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber++) {
if (0 == ccam_read_entry((struct ccam *) cstcam, unit, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber, false)) {
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((struct ccam *) cstcam,
aaaaaaaaaaaaaaaaaaa1aaaOPERATION_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa4aaa);
rc = ccam_poll_status((struct ccam *) cstcam);
if (rc == 0) {
invalidate_entry(cstcam, unit, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber);
if (ccam_is_blocked((struct ccam *) cstcam)) {
rc = CCAM_ERROR_FULL;
}
}
if (rc != 0) {
write_mask(cstcam, false, unit, true, true);
cstcam->mask_ids[mask_id].compressed = true;
if (ccam_is_blocked((struct ccam *) cstcam)) {
set_mask_id(cstcam, mask_id);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((struct ccam *) cstcam,
aaaaaaaaaaaaaaaaaaa1aaaOPERATION_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa4aaa);
int rc_clear_blockage = ccam_poll_status((struct ccam *) cstcam);
if (rc_clear_blockage != CCAM_ERROR_DUPLICATE_FOUND) {
return CCAM_ERROR_ENVIRONMENT;
}
rc_clear_blockage = ccam_read_entry((struct ccam *) cstcam, 0, 0, true);
if (rc_clear_blockage != CCAM_ERROR_NOT_FOUND) {
return CCAM_ERROR_ENVIRONMENT;
}
struct ccam * ccam = (struct ccam *) cstcam;
ccam->blocked = false;
}
break; 
}
}
} 
if (rc == 0) {
write_mask(cstcam, false, unit, false, true);
free_unit(cstcam, unit);
return 0;
}
}
}
}
return CCAM_ERROR_FULL;
}
static int aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(const struct cstcam *cstcam, const uint8_t mask[], uint16_t *mask_id) {
const uint16_t num_units = cstcam->ccam.config.phys_units * cstcam->ccam.config.num_slots;
const uint8_t mask_bytes = cstcam->ccam.config.key_width / 8;
const uint8_t rem_mask_bits = cstcam->ccam.config.key_width - mask_bytes * 8;
for (uint16_t i = 0; i < num_units; i++) {
if (cstcam->units[i].enabled == false)
continue;
if (0 == memcmp(mask, cstcam->units[i].mask, mask_bytes)) {
if (rem_mask_bits) {
if (aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa8(cstcam->units[i].mask[mask_bytes], 0, rem_mask_bits) !=
aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa8(mask[mask_bytes], 0, rem_mask_bits)) {
continue;
}
}
*mask_id = cstcam->units[i].mask_id;
return 0;
}
}
return CCAM_ERROR_NO_MASK;
}
static int alloc_unit(struct cstcam *cstcam, const uint8_t mask[], const uint16_t mask_id, uint16_t *unit) {
const uint16_t num_units = cstcam->ccam.config.phys_units * cstcam->ccam.config.num_slots;
for (uint16_t i = 0; i < num_units; i++) {
if (cstcam->units[i].enabled == false) {
*unit = i;
cam_write_field8(cstcam->units[i].mask, mask, 0, cstcam->ccam.config.key_width);
cstcam->units[i].mask_id = mask_id;
cstcam->units[i].enabled = true;
return 0;
}
}
return CCAM_ERROR_FULL;
}
static int alloc_unit_and_write_mask(struct cstcam *cstcam, const uint8_t mask[], uint16_t mask_id) {
uint16_t unit;
int rc = alloc_unit(cstcam, mask, mask_id, &unit);
assert(rc == 0);
write_mask(cstcam, true, unit, true, true);
return 0;
}
static void free_unit(struct cstcam *cstcam, uint16_t unit) {
assert(unit < MAX_UNITS);
assert(cstcam->units[unit].enabled == true);
cstcam->units[unit].enabled = false;
}
static int alloc_mask_id(struct cstcam *cstcam, uint32_t priority, uint16_t *mask_id) {
for (uint16_t i = 0; i < CSTCAM_MAX_MASK_IDS; i++) {
if (cstcam->mask_ids[i].used == true) {
if (cstcam->mask_ids[i].priority == priority)
return CCAM_ERROR_WRONG_PRIO;
}
}
for (uint16_t i = 0; i < CSTCAM_MAX_MASK_IDS; i++) {
if (cstcam->mask_ids[i].used != true) {
*mask_id = i;
cstcam->mask_ids[i].used = true;
cstcam->mask_ids[i].compressed = false;
cstcam->mask_ids[i].priority = priority;
return 0;
}
}
return CCAM_ERROR_FULL;
}
static void free_mask_id(struct cstcam *cstcam, uint16_t mask_id) {
assert(mask_id < CSTCAM_MAX_MASK_IDS);
assert(cstcam->mask_ids[mask_id].used == true);
cstcam->mask_ids[mask_id].used = false;
}
static void set_mask_id(const struct cstcam *cstcam, uint16_t mask_id) {
const uint32_t aaaaaaaaaaaaaaaaaaaaaa1aaa = aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa;
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((struct ccam *) cstcam, aaaaaaaaaaaaaaaaaaaaaa1aaa, mask_id);
}
size_t cstcam_size(void) {
return sizeof(struct cstcam);
}
int cstcam_init(const struct ccam_arg *arg, struct cstcam *cstcam) {
NULL_CHECK(cstcam);
NULL_CHECK(arg);
memset(cstcam, 0, cstcam_size());
int rc = ccam_init(arg, (struct ccam *) cstcam);
if (ccam_is_cache((struct ccam *) cstcam))
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((struct ccam *) cstcam, aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaBER_PASSES_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, 4);
if (rc == 0) {
const uint16_t num_units = cstcam->ccam.config.phys_units * cstcam->ccam.config.num_slots;
for (uint16_t i = 0; i < num_units; i++) {
write_mask(cstcam, false, i, false, false);
}
}
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((struct ccam *) cstcam, aaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaPER_CHMU_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, CCAM_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa1S);
   ccam_print_entry(rc, "cstcam_init", (struct ccam *) cstcam, NULL, NULL, NULL, "");
return rc;
}
static int aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaexisting_memory_unit(struct cstcam *cstcam, const uint8_t key[], uint32_t priority,
const uint8_t response[], uint16_t mask_id) {
set_mask_id(cstcam, mask_id);
set_priority(cstcam, priority);
ccam_set_key((struct ccam *) cstcam, key);
ccam_set_resp((struct ccam *) cstcam, response);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((struct ccam *) cstcam, aaaaaaaaaaaaaaaaaaa1aaaOPERATION_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa4aaa);
int rc = ccam_poll_status((struct ccam *) cstcam);
return rc;
}
static void write_mask(struct cstcam *cstcam, bool write_mask, uint16_t unit, bool valid,
bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaenable) {
assert(unit < MAX_UNITS);
assert((write_mask && valid && cstcam->units[unit].enabled) || (!write_mask));
assert((!write_mask && !aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaenable) || (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaenable && cstcam->units[unit].enabled));
assert((!write_mask && !valid) || (valid && cstcam->units[unit].enabled));
if (cstcam->ccam.config.asic && !valid) {
int rc = ccam_read_entry((struct ccam *) cstcam, unit, 0, false);
assert(rc == CCAM_ERROR_NOT_FOUND);
}
const uint16_t mask_id = cstcam->units[unit].mask_id;
assert(mask_id < CSTCAM_MAX_MASK_IDS);
uint8_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaen = 0;
uint8_t val = 0;
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaenable)
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaen = 1;
if (valid)
val = 1;
const uint16_t physical_unit = unit / cstcam->ccam.config.num_slots;
const uint8_t slot = unit - physical_unit * cstcam->ccam.config.num_slots;
const uint32_t base = aaaaaa1aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa + physical_unit * aaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa + slot * aaaaaa1aaaaaaaaaaaaaaa1aaaWORD;
uint64_t word15 = 0;
word15 = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa64(word15, val, 32 + 16, 1); 
word15 = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa64(word15, mask_id, 32 + 16 + 1, 10);
word15 = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa64(word15, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaen, 32 + 16 + 1 + 10, 1); 
const uint16_t width8 = (cstcam->ccam.config.key_width + 7) / 8;
assert(width8 <= (960 / 8));
const uint16_t width64 = (cstcam->ccam.config.key_width + 63) / 64;
assert(width64 < 15);
if (write_mask) {
for (uint8_t i = 0; i < width64; i++) {
uint64_t temp;
memcpy(&temp, &cstcam->units[unit].mask[i * 8], sizeof(temp));
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((struct ccam *) cstcam, base + i * 0x8, temp);
}
}
ccam_inaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((struct ccam *) cstcam, base + 15 * 0x8, word15);
}
static int aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaanew_memory_unit(struct cstcam *cstcam, const uint8_t key[], const uint8_t mask[],
uint32_t priority,
const uint8_t response[], uint16_t mask_id) {
int rc = alloc_unit_and_write_mask(cstcam, mask, mask_id);
if (rc)
return rc;
rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaexisting_memory_unit(cstcam, key, priority, response, mask_id);
if (rc == CCAM_ERROR_FULL)
rc = CCAM_ERROR_ENVIRONMENT;
return rc;
}
int cstcam_get_by_key(struct cstcam *cstcam, const uint8_t key[], const uint8_t mask[], uint8_t response[]) {
NULL_CHECK(cstcam);
NULL_CHECK(key);
NULL_CHECK(response);
int rc;
if (ccam_is_cache((struct ccam *) cstcam) == true) {
rc = CCAM_ERROR_WRONG_API;
goto error;
}
bool using_default_response = false;
uint16_t mask_id;
rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(cstcam, mask, &mask_id);
if (rc == 0) {
set_mask_id(cstcam, mask_id);
ccam_set_key((struct ccam *) cstcam, key);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((struct ccam *) cstcam, aaaaaaaaaaaaaaaaaaa1aaaOPERATION_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaa4aaaBYKEY);
rc = ccam_poll_status((struct ccam *) cstcam);
if (rc == 0) {
ccam_get_resp((struct ccam *) cstcam, response);
} else if (rc == CCAM_ERROR_NOT_FOUND) {
using_default_response = true;
ccam_get_resp((struct ccam *) cstcam, response);
} else {
goto error;
}
       ccam_print_entry(0, "cstcam_get_by_key", (struct ccam *) cstcam, key, mask, response,
               using_default_response ? "DEFAULT_MATCH" : "KEY_MATCH");
return rc;
}
   error: ccam_print_entry(rc, "cstcam_get_by_key", (struct ccam *) cstcam, key, mask, NULL, "");
return rc;
}
int cstcam_mask_free(struct cstcam *cstcam, uint16_t mask_id) {
NULL_CHECK(cstcam);
int rc = 0;
if (cstcam->mask_id_mode != MASK_API_IS_MASK_ID) {
rc = CCAM_ERROR_WRONG_API;
goto end;
}
if (ccam_is_cache((struct ccam *) cstcam) == true) {
rc = CCAM_ERROR_WRONG_API;
goto end;
}
if (mask_id >= CSTCAM_MAX_MASK_IDS) {
rc = CCAM_ERROR_INVALID_ARG;
goto end;
}
if (cstcam->mask_ids[mask_id].num_entries) {
rc = CCAM_ERROR_NOT_EMPTY;
goto end;
}
uint16_t unit = 0;
rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa(cstcam, mask_id, &unit);
if (rc == 0) {
write_mask(cstcam, false, unit, false, true);
free_unit(cstcam, unit);
assert(aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa(cstcam, mask_id, &unit) != 0);
free_mask_id(cstcam, mask_id);
cstcam->ccam.sw_stats.num_masks--;
}
   end: ccam_print_entry(rc, "cstcam_mask_free", (struct ccam *) cstcam, NULL, NULL, NULL, "");
return (rc);
}
int cstcam_delete(struct cstcam *cstcam, const uint8_t key[], const uint8_t mask[]) {
NULL_CHECK(cstcam);
NULL_CHECK(key);
NULL_CHECK(mask);
int rc;
cstcam->ccam.sw_stats.num_deletes++;
if (cstcam->mask_id_mode != MASK_API_IS_MASK) {
rc = CCAM_ERROR_WRONG_API;
goto end;
}
if (ccam_is_cache((struct ccam *) cstcam) == true) {
rc = CCAM_ERROR_WRONG_API;
goto end;
}
uint16_t mask_id;
rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(cstcam, mask, &mask_id);
if (rc == 0) {
set_mask_id(cstcam, mask_id);
ccam_set_key((struct ccam *) cstcam, key);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((struct ccam *) cstcam, aaaaaaaaaaaaaaaaaaa1aaaOPERATION_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa4aaa);
rc = ccam_poll_status((struct ccam *) cstcam);
if (rc == 0) {
if (cstcam->ccam.sw_stats.num_entries == 0) {
rc = CCAM_ERROR_ENVIRONMENT;
} else {
cstcam->ccam.sw_stats.num_entries--;
assert(cstcam->mask_ids[mask_id].num_entries);
cstcam->mask_ids[mask_id].num_entries--;
cstcam->mask_ids[mask_id].compressed = false;
if (cstcam->mask_ids[mask_id].num_entries == 0) {
uint16_t unit = 0;
while (0 == aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa(cstcam, mask_id, &unit)) {
write_mask(cstcam, false, unit, false, true);
free_unit(cstcam, unit);
unit++;
}
free_mask_id(cstcam, mask_id);
cstcam->ccam.sw_stats.num_masks--;
}
}
}
}
end:
if (rc != 0)
cstcam->ccam.sw_stats.failed_deletes++;
   ccam_print_entry(rc, "cstcam_delete", (struct ccam *) cstcam, key, mask, NULL, "");
return (rc);
}
int cstcam_delete_by_id(struct cstcam *cstcam, const uint8_t key[], uint16_t mask_id) {
NULL_CHECK(cstcam);
NULL_CHECK(key);
int rc = 0;
cstcam->ccam.sw_stats.num_deletes++;
if (cstcam->mask_id_mode != MASK_API_IS_MASK_ID) {
rc = CCAM_ERROR_WRONG_API;
goto end;
}
if (ccam_is_cache((struct ccam *) cstcam) == true) {
rc = CCAM_ERROR_WRONG_API;
goto end;
}
if (mask_id >= CSTCAM_MAX_MASK_IDS) {
rc = CCAM_ERROR_INVALID_ARG;
goto end;
}
uint16_t start_unit = 0;
rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa(cstcam, mask_id, &start_unit);
if (rc) {
rc = CCAM_ERROR_NO_MASK;
goto end;
}
set_mask_id(cstcam, mask_id);
ccam_set_key((struct ccam *) cstcam, key);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((struct ccam *) cstcam, aaaaaaaaaaaaaaaaaaa1aaaOPERATION_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa4aaa);
rc = ccam_poll_status((struct ccam *) cstcam);
if (rc == 0) {
if (cstcam->ccam.sw_stats.num_entries == 0) {
rc = CCAM_ERROR_ENVIRONMENT;
} else {
cstcam->ccam.sw_stats.num_entries--;
assert(cstcam->mask_ids[mask_id].num_entries);
cstcam->mask_ids[mask_id].num_entries--;
cstcam->mask_ids[mask_id].compressed = false;
if (cstcam->mask_ids[mask_id].num_entries == 0) {
uint16_t unit = 0, prev_unit = 0xffff;
while (0 == aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa(cstcam, mask_id, &unit)) {
if(prev_unit != 0xffff) {
write_mask(cstcam, false, prev_unit, false, true);
free_unit(cstcam, prev_unit);
}
prev_unit = unit;
unit++;
}
}
}
}
end: if (rc != 0)
cstcam->ccam.sw_stats.failed_deletes++;
   ccam_print_entry(rc, "cstcam_delete_by_id", (struct ccam *) cstcam, key, NULL, NULL, "");
return (rc);
}
int cstcam_update(struct cstcam *cstcam, const uint8_t key[], const uint8_t mask[], const uint8_t response[]) {
NULL_CHECK(cstcam);
NULL_CHECK(key);
NULL_CHECK(mask);
NULL_CHECK(response);
int rc;
cstcam->ccam.sw_stats.num_updates++;
if (cstcam->mask_id_mode != MASK_API_IS_MASK) {
rc = CCAM_ERROR_WRONG_API;
goto end;
}
if (ccam_is_cache((struct ccam *) cstcam) == true) {
rc = CCAM_ERROR_WRONG_API;
goto end;
}
uint16_t mask_id;
rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(cstcam, mask, &mask_id);
if (rc == 0) {
set_mask_id(cstcam, mask_id);
const uint32_t priority = get_priority_from_mask_id(cstcam, mask_id);
set_priority(cstcam, priority);
ccam_set_key((struct ccam *) cstcam, key);
ccam_set_resp((struct ccam *) cstcam, response);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((struct ccam *) cstcam, aaaaaaaaaaaaaaaaaaa1aaaOPERATION_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbb3aaa);
rc = ccam_poll_status((struct ccam *) cstcam);
}
end:
if (rc != 0)
cstcam->ccam.sw_stats.failed_updates++;
   ccam_print_entry(rc, "cstcam_update", (struct ccam *) cstcam, key, mask, NULL, "");
return (rc);
}
int cstcam_update_by_id(struct cstcam *cstcam, const uint8_t key[], uint16_t mask_id, const uint8_t response[]) {
NULL_CHECK(cstcam);
NULL_CHECK(key);
NULL_CHECK(response);
int rc = 0;
cstcam->ccam.sw_stats.num_updates++;
if (cstcam->mask_id_mode != MASK_API_IS_MASK_ID) {
rc = CCAM_ERROR_WRONG_API;
goto end;
}
if (ccam_is_cache((struct ccam *) cstcam) == true) {
rc = CCAM_ERROR_WRONG_API;
goto end;
}
if (mask_id >= CSTCAM_MAX_MASK_IDS) {
rc = CCAM_ERROR_INVALID_ARG;
goto end;
}
uint16_t start_unit = 0;
rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa(cstcam, mask_id, &start_unit);
if (rc) {
rc = CCAM_ERROR_NO_MASK;
goto end;
}
set_mask_id(cstcam, mask_id);
const uint32_t priority = get_priority_from_mask_id(cstcam, mask_id);
set_priority(cstcam, priority);
ccam_set_key((struct ccam *) cstcam, key);
ccam_set_resp((struct ccam *) cstcam, response);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((struct ccam *) cstcam, aaaaaaaaaaaaaaaaaaa1aaaOPERATION_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, aaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbb3aaa);
rc = ccam_poll_status((struct ccam *) cstcam);
end: if (rc != 0)
cstcam->ccam.sw_stats.failed_updates++;
   ccam_print_entry(rc, "cstcam_update_by_id", (struct ccam *) cstcam, key, NULL, NULL, "");
return (rc);
}
int cstcam_mask_alloc(struct cstcam *cstcam, const uint8_t mask[], uint32_t priority, uint16_t *mask_id) {
NULL_CHECK(cstcam);
NULL_CHECK(mask);
int rc = 0;
if (cstcam->mask_id_mode == MASK_API_IS_MASK) {
rc = CCAM_ERROR_WRONG_API;
goto end;
}
if (ccam_is_cache((struct ccam *) cstcam) == true) {
rc = CCAM_ERROR_WRONG_API;
goto end;
}
uint16_t in_use_mask_id;
rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(cstcam, mask, &in_use_mask_id);
if (rc == 0) {
rc = CCAM_ERROR_INVALID_ARG;
goto end;
}
const uint8_t prio_width = cstcam->ccam.config.prio_width;
const uint64_t prio_range = ((uint64_t) priority) >> prio_width;
if (prio_range > 0) {
rc = CCAM_ERROR_WRONG_PRIO_WIDTH;
goto end;
}
if ((cstcam->ccam.arg.optimization_flags & CCAM_OPTIMIZE_MASKS) == 0) {
if (cstcam->ccam.sw_stats.num_masks >= cstcam->ccam.config.num_masks) {
rc = CCAM_ERROR_FULL;
goto end;
}
}
rc = alloc_mask_id(cstcam, priority, mask_id);
if (rc == CCAM_ERROR_WRONG_PRIO) {
goto end;
}
assert(rc == 0);
rc = alloc_unit_and_write_mask(cstcam, mask, *mask_id);
if (rc) {
free_mask_id(cstcam, *mask_id);
goto end;
}
cstcam->ccam.sw_stats.num_masks++;
cstcam->mask_id_mode = MASK_API_IS_MASK_ID;
end:
#if 0
int masks = 0;
for (int i = 0; i < CSTCAM_MAX_MASK_IDS; i++)
if (cstcam->mask_ids[i].used) masks++;
int units = 0;
for (int i = 0; i < MAX_UNITS; i++)
if (cstcam->units[i].enabled) units++;
       printf("Num masks in use %d, units in use %d\n", masks, units);
#endif
   ccam_print_entry(rc, "cstcam_mask_alloc", (struct ccam *) cstcam, NULL, mask, NULL, "");
return rc;
}
int cstcam_insert(struct cstcam *cstcam, const uint8_t key[], const uint8_t mask[], uint32_t priority,
const uint8_t response[]) {
NULL_CHECK(cstcam);
NULL_CHECK(key);
NULL_CHECK(mask);
NULL_CHECK(response);
int rc = 0;
cstcam->ccam.sw_stats.num_inserts++;
if (cstcam->mask_id_mode == MASK_API_IS_MASK_ID) {
rc = CCAM_ERROR_WRONG_API;
goto end;
}
if (ccam_is_cache((struct ccam *) cstcam) == true) {
rc = CCAM_ERROR_WRONG_API;
goto end;
}
const uint8_t prio_width = cstcam->ccam.config.prio_width;
const uint64_t prio_range = ((uint64_t) priority) >> prio_width;
if (prio_range > 0) {
rc = CCAM_ERROR_WRONG_PRIO_WIDTH;
goto end;
}
if (cstcam->ccam.sw_stats.num_entries >= cstcam->ccam.config.num_entries &&
(cstcam->ccam.arg.optimization_flags & CCAM_OPTIMIZE_ENTRIES) == 0) {
rc = CCAM_ERROR_FULL;
goto end;
}
assert(ccam_is_blocked((struct ccam *) cstcam) == false);
if (!free_memory_unit_available(cstcam)) {
rc = empty_one_memory_unit(cstcam);
if (rc) {
rc = CCAM_ERROR_FULL;
goto end;
}
}
uint16_t mask_id;
rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(cstcam, mask, &mask_id);
if (rc == CCAM_ERROR_NO_MASK) {
if (cstcam->ccam.sw_stats.num_masks >= cstcam->ccam.config.num_masks &&
(cstcam->ccam.arg.optimization_flags & CCAM_OPTIMIZE_MASKS) == 0) {
rc = CCAM_ERROR_FULL;
goto end;
}
rc = alloc_mask_id(cstcam, priority, &mask_id);
if (rc == CCAM_ERROR_WRONG_PRIO)
goto end;
assert(rc == 0);
rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaanew_memory_unit(cstcam, key, mask, priority, response, mask_id);
if (rc == 0) {
cstcam->ccam.sw_stats.num_masks++;
} else {
free_mask_id(cstcam, mask_id); 
}
} else {
const uint32_t used_priority = get_priority_from_mask_id(cstcam, mask_id);
if (used_priority != priority) {
rc = CCAM_ERROR_WRONG_PRIO;
goto end;
}
const bool full = is_mask_full(cstcam, mask_id);
if (full) {
rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaanew_memory_unit(cstcam, key, mask, priority, response, mask_id);
} else {
rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaexisting_memory_unit(cstcam, key, priority, response, mask_id);
if (rc == CCAM_ERROR_FULL) {
rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaanew_memory_unit(cstcam, key, mask, priority, response, mask_id);
} else if (ccam_is_blocked((struct ccam *) cstcam) == true) {
int rc_clear_blockage;
rc_clear_blockage = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaanew_memory_unit(cstcam, key, mask, priority,
response, mask_id);
if (rc_clear_blockage != CCAM_ERROR_DUPLICATE_FOUND) {
return CCAM_ERROR_ENVIRONMENT;
}
rc_clear_blockage = ccam_read_entry((struct ccam *) cstcam, 0, 0, true);
if (rc_clear_blockage != CCAM_ERROR_NOT_FOUND) {
return CCAM_ERROR_ENVIRONMENT;
}
struct ccam * ccam = (struct ccam *) cstcam;
ccam->blocked = false;
}
}
}
end:
if (rc == 0) {
cstcam->ccam.sw_stats.num_entries++;
cstcam->mask_ids[mask_id].num_entries++;
cstcam->mask_id_mode = MASK_API_IS_MASK;
cstcam->mask_ids[mask_id].compressed = false;
} else {
cstcam->ccam.sw_stats.failed_inserts++;
#if 0
int masks = 0;
for (int i = 0; i < CSTCAM_MAX_MASK_IDS; i++)
if (cstcam->mask_ids[i].used) masks++;
int units = 0;
for (int i = 0; i < MAX_UNITS; i++)
if (cstcam->units[i].enabled) units++;
       printf("Num masks in use %d, units in use %d\n", masks, units);
#endif
}
   ccam_print_entry(rc, "cstcam_insert", (struct ccam *) cstcam, key, mask, response, "");
return rc;
}
int cstcam_insert_by_id(struct cstcam *cstcam, const uint8_t key[], uint16_t mask_id,
const uint8_t response[]) {
NULL_CHECK(cstcam);
NULL_CHECK(key);
NULL_CHECK(response);
int rc = 0;
cstcam->ccam.sw_stats.num_inserts++;
if (cstcam->mask_id_mode != MASK_API_IS_MASK_ID) {
rc = CCAM_ERROR_WRONG_API;
goto end;
}
if (ccam_is_cache((struct ccam *) cstcam) == true) {
rc = CCAM_ERROR_WRONG_API;
goto end;
}
if (mask_id >= CSTCAM_MAX_MASK_IDS) {
rc = CCAM_ERROR_INVALID_ARG;
goto end;
}
if (cstcam->ccam.sw_stats.num_entries >= cstcam->ccam.config.num_entries &&
(cstcam->ccam.arg.optimization_flags & CCAM_OPTIMIZE_ENTRIES) == 0) {
rc = CCAM_ERROR_FULL;
goto end;
}
assert(ccam_is_blocked((struct ccam *) cstcam) == false);
if (!free_memory_unit_available(cstcam)) {
rc = empty_one_memory_unit(cstcam);
if (rc) {
rc = CCAM_ERROR_FULL;
goto end;
}
}
uint16_t start_unit = 0;
rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa(cstcam, mask_id, &start_unit);
if (rc) {
rc = CCAM_ERROR_NO_MASK;
goto end;
}
const uint32_t priority = get_priority_from_mask_id(cstcam, mask_id);
const bool full = is_mask_full(cstcam, mask_id);
if (full) {
rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaanew_memory_unit(cstcam, key, cstcam->units[start_unit].mask, priority,
response, mask_id);
} else {
rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaexisting_memory_unit(cstcam, key, priority, response, mask_id);
if (rc == CCAM_ERROR_FULL) {
rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaanew_memory_unit(cstcam, key, cstcam->units[start_unit].mask,
priority, response, mask_id);
} else if (ccam_is_blocked((struct ccam *) cstcam) == true) {
int rc_clear_blockage;
rc_clear_blockage = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaanew_memory_unit(cstcam, key,
cstcam->units[start_unit].mask,
priority, response, mask_id);
if (rc_clear_blockage != CCAM_ERROR_DUPLICATE_FOUND) {
return CCAM_ERROR_ENVIRONMENT;
}
rc_clear_blockage = ccam_read_entry((struct ccam *) cstcam, 0, 0, true);
if (rc_clear_blockage != CCAM_ERROR_NOT_FOUND) {
return CCAM_ERROR_ENVIRONMENT;
}
struct ccam * ccam = (struct ccam *) cstcam;
ccam->blocked = false;
}
}
end:
if (rc == 0) {
cstcam->ccam.sw_stats.num_entries++;
cstcam->mask_ids[mask_id].num_entries++;
cstcam->mask_ids[mask_id].compressed = false;
} else {
cstcam->ccam.sw_stats.failed_inserts++;
#if 0
int masks = 0;
for (int i = 0; i < CSTCAM_MAX_MASK_IDS; i++)
if (cstcam->mask_ids[i].used) masks++;
int units = 0;
for (int i = 0; i < MAX_UNITS; i++)
if (cstcam->units[i].enabled) units++;
       printf("Num masks in use %d, units in use %d\n", masks, units);
#endif
}
   ccam_print_entry(rc, "cstcam_insert_by_id", (struct ccam *) cstcam, key, NULL, response, "");
return rc;
}
int cstcam_get_by_response(struct cstcam *cstcam, const uint8_t in_response[], const uint8_t response_mask[],
uint32_t *pos, uint8_t out_key[], uint8_t out_mask[], uint8_t out_response[], uint32_t *out_prio) {
NULL_CHECK(cstcam);
NULL_CHECK(in_response);
NULL_CHECK(response_mask);
NULL_CHECK(out_key);
NULL_CHECK(out_response);
NULL_CHECK(pos);
NULL_CHECK(out_mask);
NULL_CHECK(out_prio);
int rc;
if (ccam_is_cache((struct ccam *) cstcam) == true) {
rc = CCAM_ERROR_WRONG_API;
goto end;
}
if (*pos == 0x80000000) {
rc = CCAM_ERROR_NOT_FOUND;
goto end;
}
const uint32_t start_unit = (*pos >> 16) & 0x00007fff;
const uint32_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa = *pos >> 31;
uint32_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber = *pos & 0x0000ffff;
if (start_unit >= (cstcam->ccam.config.phys_units * cstcam->ccam.config.num_slots)) {
rc = CCAM_ERROR_INVALID_ARG;
goto end;
}
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber > (cstcam->ccam.config.ram_addresses / cstcam->ccam.config.num_slots)) {
rc = CCAM_ERROR_INVALID_ARG;
goto end;
}
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa && (start_unit | aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber)) {
rc = CCAM_ERROR_INVALID_ARG;
goto end;
}
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa) {
rc = CCAM_ERROR_NOT_FOUND; 
goto end;
}
const uint16_t num_units = cstcam->ccam.config.phys_units * cstcam->ccam.config.num_slots;
for (uint16_t unit = start_unit; unit < num_units; unit++) {
if (cstcam->units[unit].enabled == false)
continue;
rc = ccam_get_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaby_response((struct ccam *) cstcam, in_response, response_mask, unit,
&aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber);
if (rc == 0) {
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber++;
*pos = unit << 16 | aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber;
cam_read_field8(out_mask, cstcam->units[unit].mask, 0, cstcam->ccam.config.key_width);
ccam_get_key((const struct ccam *) cstcam, out_key);
ccam_get_resp((const struct ccam *) cstcam, out_response);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((const struct ccam *) cstcam, aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaaRITY_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, out_prio);
break;
}
if (rc != CCAM_ERROR_NOT_FOUND)
break; 
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber = 0;
}
if (rc == CCAM_ERROR_NOT_FOUND) {
rc = ccam_get_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaby_response((struct ccam *) cstcam, in_response, response_mask);
if (rc == 0) {
uint32_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa;
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((const struct ccam *) cstcam, aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, &aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
uint16_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = 0;
rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa(cstcam, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, &aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
if (rc == CCAM_ERROR_NOT_FOUND) {
rc = CCAM_ERROR_ENVIRONMENT; 
goto end;
}
cam_read_field8(out_mask, cstcam->units[aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa].mask, 0, cstcam->ccam.config.key_width);
ccam_get_key((const struct ccam *) cstcam, out_key);
ccam_get_resp((const struct ccam *) cstcam, out_response);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((const struct ccam *) cstcam, aaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaaRITY_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, out_prio);
*pos = 0x80000000; 
}
}
   end: ccam_print_entry(rc, "cstcam_get_by_response", (struct ccam *) cstcam, out_key, out_mask, in_response,
           "MATCH");
return rc;
}
#define aaaaaaaaaaaaaaaaaaa1aaaMU_SELECT_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x148)
#define aaaaaaaaaaaaaaaaaaa1aaaCHMU_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x14C)
static void read_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(const struct cstcam *cstcam, uint8_t unit, uint32_t *value) {
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((struct ccam *) cstcam, aaaaaaaaaaaaaaaaaaa1aaaMU_SELECT_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, unit);
ccam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa((struct ccam *) cstcam, aaaaaaaaaaaaaaaaaaa1aaaCHMU_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, value);
}
static bool read_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas(const struct cstcam *cstcam, uint32_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa[MAX_UNITS]) {
const uint16_t num_units = cstcam->ccam.config.phys_units * cstcam->ccam.config.num_slots;
bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = true;
uint32_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa;
for (uint16_t unit = 0; unit < num_units; unit++) {
if (cstcam->units[unit].enabled == false)
continue;
uint32_t counter;
read_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(cstcam, unit, &counter);
const uint32_t sample = (counter & 0xfc000000) >> 26;
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa) {
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = sample;
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = false;
}
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa != sample) {
return false;
}
const uint32_t value = (counter & 0x03ffffff);
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa[unit] = value << 4; 
}
return true;
}
static int cstcam_efficiency(const struct cstcam *cstcam, struct cstcam_mask_efficiency *stats) {
NULL_CHECK(cstcam);
NULL_CHECK(stats);
int rc = 0;
uint32_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa[MAX_UNITS];
if (!read_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas(cstcam, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa)) { 
if (!read_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas(cstcam, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa)) { 
rc = CCAM_ERROR_ENVIRONMENT_POLLED_OUT;
goto end;
}
}
uint64_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaasum[CSTCAM_MAX_MASK_IDS] = { 0 };
uint8_t num_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas[CSTCAM_MAX_MASK_IDS] = { 0 };
const uint16_t num_units = cstcam->ccam.config.phys_units * cstcam->ccam.config.num_slots;
for (uint16_t unit = 0; unit < num_units; unit++) {
if (cstcam->units[unit].enabled == false)
continue;
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaasum[cstcam->units[unit].mask_id] += aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa[unit];
num_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas[cstcam->units[unit].mask_id]++;
}
stats->num_masks = 0;
for (uint16_t m_id = 0; m_id < CSTCAM_MAX_MASK_IDS; m_id++) {
if (num_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas[m_id] == 0)
continue;
stats->tuple[stats->num_masks].mask_id = m_id;
stats->tuple[stats->num_masks].efficiency = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaasum[m_id]
/ num_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas[m_id];
stats->num_masks++;
}
   end: ccam_print_entry(rc, "cstcam_get_stats", (struct ccam *) cstcam, NULL, NULL, NULL, "");
return rc;
}
static int cstcam_memory_usage(const struct cstcam *cstcam, struct cstcam_mask_memory_usage *stats) {
stats->phys_units = cstcam->ccam.config.phys_units;
stats->num_slots = cstcam->ccam.config.num_slots;
unsigned units_per_mask[CSTCAM_MAX_MASK_IDS] = { 0 };
const uint16_t num_units = cstcam->ccam.config.phys_units * cstcam->ccam.config.num_slots;
for (unsigned u = 0; u < num_units; u++) {
const unit_t *unit = &cstcam->units[u];
if (unit->enabled == false)
continue;
units_per_mask[unit->mask_id]++;
}
unsigned n = 0;
for (unsigned m = 0; m < CSTCAM_MAX_MASK_IDS; m++) {
if(units_per_mask[m] == 0)
continue;
stats->usage[n].mask_id = m;
stats->usage[n].num_mus = units_per_mask[m];
n++;
}
stats->num_masks = n;
return 0;
}
int cstcam_get_stats(const struct cstcam *cstcam, uint64_t stats_group, union cstcam_stats *stats) {
if((cstcam == NULL) ||
(stats == NULL))
return CCAM_ERROR_INVALID_ARG;
memset(stats, 0, sizeof *stats);
switch(stats_group) {
case CSTCAM_STATS_EFFICIENCY: return cstcam_efficiency(cstcam, &stats->mask_efficiency);
case CSTCAM_STATS_MEMORY_USAGE: return cstcam_memory_usage(cstcam, &stats->memory_usage);
default: return CCAM_ERROR_INVALID_ARG;
}
}
int cstcam_mu_alloc(struct cstcam *cstcam, const uint8_t mask[], uint16_t mask_id) {
NULL_CHECK(cstcam);
int rc;
if (mask_id >= CSTCAM_MAX_MASK_IDS) {
rc = CCAM_ERROR_INVALID_ARG;
goto end;
}
if (ccam_is_cache((struct ccam *) cstcam) == false) {
rc = CCAM_ERROR_WRONG_API;
goto end;
}
uint16_t unit = 0;
uint16_t out_mask_id;
bool new_mask = false;
rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(cstcam, mask, &out_mask_id);
if (rc == 0) {
if (mask_id != out_mask_id) {
rc = CCAM_ERROR_NO_MASK;
goto end;
}
} else {
rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa(cstcam, mask_id, &unit);
if (rc == 0) {
rc = CCAM_ERROR_NO_MASK;
goto end;
}
if ((cstcam->ccam.arg.optimization_flags & CCAM_OPTIMIZE_MASKS) == 0) {
if (cstcam->ccam.sw_stats.num_masks >= cstcam->ccam.config.num_masks) {
rc = CCAM_ERROR_FULL;
goto end;
}
}
new_mask = true;
}
rc = alloc_unit(cstcam, mask, mask_id, &unit);
if (rc)
goto end;
write_mask(cstcam, true, unit, true, true);
if (new_mask)
cstcam->ccam.sw_stats.num_masks++;
end:
   ccam_print_entry(rc, "cstcam_alloc_unit", (struct ccam *) cstcam, NULL, mask, NULL, "");
return rc;
}
int cstcam_mu_free(struct cstcam *cstcam, uint16_t mask_id) {
NULL_CHECK(cstcam);
int rc = 0;
if (mask_id >= CSTCAM_MAX_MASK_IDS) {
rc = CCAM_ERROR_INVALID_ARG;
goto end;
}
if (ccam_is_cache((struct ccam *) cstcam) == false) {
rc = CCAM_ERROR_WRONG_API;
goto end;
}
uint16_t unit = 0;
rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa(cstcam, mask_id, &unit);
if (rc)
goto end;
const uint32_t num_entries = cstcam->ccam.config.ram_addresses / cstcam->ccam.config.num_slots;
write_mask(cstcam, false, unit, true, false);
for (uint16_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber = 0; aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber < num_entries; aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber++) {
invalidate_entry(cstcam, unit, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaber);
}
write_mask(cstcam, false, unit, false, true);
free_unit(cstcam, unit);
rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa(cstcam, mask_id, &unit);
if (rc == CCAM_ERROR_NOT_FOUND) { 
assert(cstcam->ccam.sw_stats.num_masks);
cstcam->ccam.sw_stats.num_masks--;
rc = 0;
}
   end: ccam_print_entry(rc, "cstcam_clear_and_free_unit", (struct ccam *) cstcam, NULL, NULL, NULL, "");
return rc;
}
