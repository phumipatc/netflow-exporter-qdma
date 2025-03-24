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
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <alloca.h>
#ifndef _BCAM_H_
#define _BCAM_H_
#ifndef _CAM_H_
#define _CAM_H_
#include <stdint.h>
#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif
enum cam_errnos {
CAM_OK = 0,
CAM_ERROR_FULL = 1,
CAM_ERROR_NO_OPEN = 2,
CAM_ERROR_INVALID_ARG = 3,
CAM_ERROR_WRONG_KEY_WIDTH = 5,
CAM_ERROR_TOO_MANY_INSTANCES = 6,
CAM_ERROR_WRONG_BIT_FIELD_MASK = 7,
CAM_ERROR_WRONG_CONST_FIELD_MASK = 8,
CAM_ERROR_WRONG_UNUSED_FIELD_MASK = 9,
CAM_ERROR_INVALID_TERNARY_FIELD_LEN = 10,
CAM_ERROR_WRONG_PRIO_WIDTH = 11,
CAM_ERROR_WRONG_MAX = 12,
CAM_ERROR_DUPLICATE_FOUND = 13,
CAM_ERROR_WRONG_PREFIX = 14,
CAM_ERROR_WRONG_PREFIX_MASK = 15,
CAM_ERROR_WRONG_RANGE = 16,
CAM_ERROR_WRONG_RANGE_MASK = 17,
CAM_ERROR_KEY_NOT_FOUND = 18,
CAM_ERROR_WRONG_MIN = 19,
CAM_ERROR_WRONG_PRIO = 20,
CAM_ERROR_WRONG_LIST_LENGTH = 21,
CAM_ERROR_WRONG_NUMBER_OF_SLOTS = 22,
CAM_ERROR_INVALID_MEM_TYPE = 23,
CAM_ERROR_TOO_HIGH_FREQUENCY = 24,
CAM_ERROR_WRONG_TERNARY_MASK = 25,
CAM_ERROR_MASKED_KEY_BIT_IS_SET = 26,
CAM_ERROR_INVALID_MODE = 28,
CAM_ERROR_WRONG_RESPONSE_WIDTH = 29,
CAM_ERROR_FORMAT_SYNTAX = 30,
CAM_ERROR_TOO_MANY_FIELDS = 31,
CAM_ERROR_TOO_MANY_RANGES = 32,
CAM_ERROR_INVALID_RANGE_LEN = 33,
CAM_ERROR_INVALID_RANGE_START = 34,
CAM_ERROR_INVALID_PREFIX_LEN = 35,
CAM_ERROR_INVALID_PREFIX_START = 36,
CAM_ERROR_INVALID_PREFIX_KEY = 37,
CAM_ERROR_INVALID_BIT_FIELD_LEN = 38,
CAM_ERROR_INVALID_BIT_FIELD_START = 39,
CAM_ERROR_INVALID_CONST_FIELD_LEN = 40,
CAM_ERROR_INVALID_CONST_FIELD_START = 41,
CAM_ERROR_INVALID_UNUSED_FIELD_LEN = 42,
CAM_ERROR_INVALID_UNUSED_FIELD_START = 43,
CAM_ERROR_MAX_KEY_LEN_EXCEED = 44,
CAM_ERROR_INVALID_aaaaaaaaaaaaaa1aaaINDEX_WIDTH = 45,
CAM_ERROR_TOO_MANY_UNITS = 46,
CAM_ERROR_NO_MASK = 47,
CAM_ERROR_INVALID_MEMORY_WIDTH = 48,
CAM_ERROR_UNSUPPORTED_COMMAND = 49,
CAM_ERROR_ENVIRONMENT = 50,
CAM_ERROR_UNSUPPORTED_CAM_TYPE = 51,
CAM_ERROR_NULL_POINTER = 52,
CAM_ERROR_TOO_MANY_PCS = 53,
CAM_ERROR_CONFIGURATION = 54,
CAM_ERROR_ENVIRONMENT_FSMBUSY = 55,
CAM_ERROR_ENVIRONMENT_POLLED_OUT = 56,
CAM_ERROR_SEGMENT_aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaZERO = 57,
CAM_ERROR_VC_UNSUPPORTED_COMMAND = 58,
CAM_ERROR_WRONG_VIRTUAL_CAM_ID = 59,
CAM_ERROR_WRONG_SEGMENT_NUMBER = 60,
CAM_ERROR_TOO_MANY_RAMS = 61,
CAM_ERROR_FOUND_IN_SHADOW_BUT_NOT_IN_HW = 62,
CAM_ERROR_TOO_SMALL_HEAP = 63,
CAM_ERROR_RAM_TOO_SMALL = 64,
CAM_ERROR_NOT_EMPTY = 65,
CAM_ERROR_STATISTICS_NOT_AVAILABLE = 66,
CAM_ERROR_TOO_MANY_ENTRIES = 67, 
CAM_ERROR_FORMAT_COMPLEXITY = 69,
CAM_ERROR_INVALID_USER_PCS = 70,
CAM_ERROR_FATAL_BASE_START = 100,
CAM_ERROR_FATAL_BASE_END = 199, 
CAM_ERROR_NOMEM = CAM_ERROR_FATAL_BASE_END,
CAM_ERROR_MALLOC_FAILED = CAM_ERROR_FATAL_BASE_END - 1,
};
#define CAM_DEBUG_NONE 0x00000000 
#define CAM_DEBUG_NO_ERROR_MSG 0x00000001 
#define CAM_DEBUG_ARGS 0x00000002 
#define CAM_DEBUG_VERIFY_WR 0x00000004 
#define CAM_DEBUG_VERIFY_SHADOW 0x00000008 
#define CAM_DEBUG_VERBOSE_VERIFY 0x00000010 
#define CAM_DEBUG_SKIP_MEM_INIT 0x00000020 
#define CAM_DEBUG_CONFIG 0x00000040 
#define CAM_DEBUG_VERIFY_CONFIG 0x00000080 
#define CAM_DEBUG_KEY_MASKING 0x00000100 
#define CAM_DEBUG_STATS 0x00000200 
#define CAM_DEBUG_SEGMENTS 0x00000400 
#define CAM_DEBUG_SKIP_VERIFY_CONFIG 0x00000800 
#define CAM_DEBUG_SET_COVER 0x00001000 
#define CAM_DEBUG_CONFIG_ARGS 0x00002000 
#define CAM_DEBUG_HW_WR 0x00010000 
#define CAM_DEBUG_HW_RD 0x00020000 
#define CAM_DEBUG_HW_LOOKUP 0x00040000 
#define CAM_OPTIMIZE_NONE 0x00000000 
#define CAM_OPTIMIZE_RAM 0x00000001 
#define CAM_OPTIMIZE_LOGIC 0x00000002 
#define CAM_OPTIMIZE_ENTRIES 0x00000004 
#define CAM_OPTIMIZE_MASKS 0x00000008 
#define CAM_MAX_KEY_WIDTH 992
#define CAM_MAX_RESPONSE_WIDTH 1024
struct cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup {
uint8_t key[(CAM_MAX_KEY_WIDTH + 7) / 8]; 
uint8_t response[(CAM_MAX_RESPONSE_WIDTH + 7) / 8];
uint32_t status; 
};
struct cam_sw {
uint32_t num_entries; 
uint32_t narrow_num_entries; 
uint64_t num_inserts;
uint64_t num_updates;
uint64_t num_deletes;
uint32_t failed_inserts;
uint32_t failed_updates;
uint32_t failed_deletes;
uint64_t num_collisions; 
uint16_t max_collisions; 
uint8_t num_used_masks; 
uint64_t num_shadow_writes; 
};
typedef struct cam_arg_t cam_arg_t;
int cam_arg_create(cam_arg_t **out_cam_arg);
void cam_arg_init(cam_arg_t *out_cam_arg);
size_t cam_arg_size(void);
void cam_arg_destroy(cam_arg_t *cam_arg);
int cam_arg_set_format(cam_arg_t *cam_arg, char *format);
void cam_arg_set_inst_ctx(cam_arg_t *cam_arg, void *inst_ctx);
void cam_arg_set_hw_write_function(cam_arg_t *cam_arg, void (*hw_write_function)(void*, uint32_t, uint32_t));
void cam_arg_set_hw_read_function(cam_arg_t *cam_arg, void (*hw_read_function)(void*, uint32_t, uint32_t*));
int cam_arg_set_hw_io(cam_arg_t *cam_arg,
unsigned hw_block,
void (*hw_write_function)(void*, uint32_t, uint32_t),
void (*hw_read_function)(void*, uint32_t, uint32_t*));
void cam_arg_set_num_entries(cam_arg_t *cam_arg, uint32_t num_entries);
void cam_arg_set_engine_lookup_rate(struct cam_arg_t *cam_arg, float lookup_rate);
void cam_arg_set_lookup_interface_freq(struct cam_arg_t *cam_arg, float freq);
void cam_arg_set_ram_freq(struct cam_arg_t *cam_arg, float freq);
void cam_arg_set_response_width(struct cam_arg_t *cam_arg, uint16_t response_width);
void cam_arg_force_prio_width(struct cam_arg_t *cam_arg, uint8_t prio_width);
void cam_arg_force_num_pcs(struct cam_arg_t *cam_arg, unsigned num_pcs);
void cam_arg_set_key_width(struct cam_arg_t *cam_arg, uint16_t key_width);
void cam_arg_set_fingerprint_width(struct cam_arg_t *cam_arg, uint16_t fingerprint_width);
void cam_arg_set_num_masks(struct cam_arg_t *cam_arg, uint8_t num_masks);
void cam_arg_force_num_units(struct cam_arg_t *cam_arg, uint16_t num_units);
void cam_arg_force_mem_type(struct cam_arg_t *cam_arg, bool uram);
void cam_arg_set_max_num_brams(struct cam_arg_t *cam_arg, uint16_t max_num_brams);
void cam_arg_set_max_num_urams(struct cam_arg_t *cam_arg, uint16_t max_num_urams);
void cam_arg_set_max_macro_height(struct cam_arg_t *cam_arg, uint8_t max_macro_height);
void cam_arg_set_device_arch(struct cam_arg_t *cam_arg, bool versal);
void cam_arg_force_hbm(struct cam_arg_t *cam_arg);
void cam_arg_set_narrow_key_width(struct cam_arg_t *cam_arg, uint16_t narrow_key_width);
void cam_arg_set_max_hw_writes(struct cam_arg_t *cam_arg, uint16_t max_hw_writes);
void cam_arg_set_flow_control(struct cam_arg_t *cam_arg, bool flow_control);
void cam_arg_set_aging(struct cam_arg_t *cam_arg, bool aging);
void cam_arg_set_default_response(struct cam_arg_t *cam_arg, const uint8_t *default_response);
void cam_arg_set_narrow_default_response(struct cam_arg_t *cam_arg, const uint8_t *narrow_default_response);
void cam_arg_set_vcid(struct cam_arg_t* cam_arg, uint8_t vcid);
void cam_arg_set_seg(struct cam_arg_t* cam_arg, uint16_t segment_id);
void cam_arg_set_hw_write_sequence_functions(cam_arg_t *cam_arg, void (*start_function)(void*),
void (*end_function)(void*));
void cam_arg_set_debug_flags(cam_arg_t *cam_arg, uint32_t debug_flags);
void cam_arg_set_optimization_flags(cam_arg_t *cam_arg, uint32_t optimization_flags);
void cam_arg_enable_options(cam_arg_t *cam_arg);
void cam_arg_force_asic_ram(struct cam_arg_t *cam_arg);
void cam_arg_force_dram(struct cam_arg_t *cam_arg);
void cam_arg_set_ram_size(struct cam_arg_t *cam_arg, uint32_t size);
void cam_arg_set_hash_function(struct cam_arg_t *cam_arg, uint8_t function);
void cam_arg_set_siphash_key(struct cam_arg_t *cam_arg, uint64_t k0, uint64_t k1);
void cam_arg_set_num_banks(struct cam_arg_t *cam_arg, uint8_t num_banks);
void cam_arg_set_channel_width(struct cam_arg_t *cam_arg, uint16_t width);
void cam_arg_set_replication(struct cam_arg_t *cam_arg, unsigned replication);
enum cam_arg_update_mode {
CAM_UPDATE_SOFTWARE = 0,
CAM_UPDATE_HARDWARE = 1
};
void cam_arg_set_update_mode(struct cam_arg_t *cam_arg, enum cam_arg_update_mode update_mode);
void cam_arg_set_generation_number_granularity(struct cam_arg_t *cam_arg, uint16_t granularity);
void cam_arg_calc_heap_size(struct cam_arg_t *cam_arg, bool calculate);
void cam_arg_set_error_print_function(struct cam_arg_t *cam_arg, void (*error_print_function)(void *, char*));
void cam_arg_set_info_print_function(struct cam_arg_t *cam_arg, void (*info_print_function)(void *, char*));
void cam_arg_set_malloc_function(struct cam_arg_t* cam_arg, void* (*malloc_function)(size_t size));
void cam_arg_set_posix_memalign_function(struct cam_arg_t* cam_arg,
int (*posix_memalign_function)(void** ptr, size_t align_size, size_t num));
void cam_arg_set_realloc_function(struct cam_arg_t* cam_arg,
void* (*realloc_function)(void *ptr, size_t size));
void cam_arg_set_calloc_function(struct cam_arg_t* cam_arg, void* (*calloc_function)(size_t num, size_t size));
void cam_arg_set_free_function(struct cam_arg_t* cam_arg, void (*free_function)(void* ptr));
const char *cam_error_string(int error_code);
void cam_print_error(int error_code);
typedef struct cam_options_t cam_options_t;
int cam_options_create(cam_options_t** out_cam_options);
size_t cam_options_size(void);
void cam_options_init(cam_options_t *out_options);
void cam_options_destroy(cam_options_t *cam_options);
void cam_options_set_narrow_key(struct cam_options_t *cam_options, bool narrow);
void cam_options_set_precomputed_hash_value(struct cam_options_t *cam_options, uint8_t hash_value[32]);
void cam_options_clear_precomputed_hash_value(struct cam_options_t *cam_options);
void cam_options_set_single_segment_search(struct cam_options_t *options, uint8_t segment);
void cam_options_clear_single_segment_search(struct cam_options_t *options);
void cam_options_set_debug_flags(struct cam_options_t* options, uint32_t debug_flags);
void cam_options_clear_debug_flags(struct cam_options_t *options);
#ifdef __cplusplus
}
#endif
#endif
#ifdef __cplusplus
extern "C" {
#endif
struct bcam;
int bcam_create(const cam_arg_t *cam_arg, struct bcam **out_bcam);
int bcam_insert(struct bcam *bcam, const uint8_t key[], const uint8_t response[], ...);
int bcam_update(struct bcam *bcam, const uint8_t key[], const uint8_t response[], ...);
int bcam_get_by_response(struct bcam *bcam, const uint8_t response[], const uint8_t response_mask[], uint32_t *pos,
uint8_t out_key[], ...);
int bcam_get_by_key_and_response(struct bcam *bcam,
const uint8_t key[], const uint8_t key_mask[],
const uint8_t response[], const uint8_t response_mask[],
uint32_t *pos,
uint8_t out_key[], uint8_t out_response[], ...);
int bcam_get_by_key(struct bcam *bcam, const uint8_t key[], uint8_t response[], ...);
int bcam_delete(struct bcam *bcam, const uint8_t key[], ...);
int bcam_delete_all(struct bcam *bcam, ...);
int bcam_read_and_clear_ecc_counters(struct bcam *bcam, uint32_t *corrected_single_bit_errors,
uint32_t *detected_double_bit_errors);
int bcam_read_and_clear_ecc_addresses(struct bcam *bcam, uint32_t *failing_address_single_bit_error,
uint32_t *failing_address_double_bit_error);
int bcam_set_ecc_test(struct bcam *bcam, bool inject_single_bit_errors,
bool inject_double_bit_errors);
int bcam_destroy(struct bcam *bcam);
#define BCAM_STATS_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP 2
#define BCAM_STATS_DRAM_RATE 3
#define BCAM_STATS_SW 4
#define BCAM_STATS_DRAM_SNAPSHOT 5
struct cam_dram_rate {
uint32_t axis_ws; 
uint32_t reads; 
uint32_t writes; 
uint32_t lookup_responses; 
};
struct cam_dram_snapshot {
uint32_t outstanding_reads; 
uint32_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaalatency; 
};
union bcam_stats {
struct cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup;
struct cam_dram_rate dram_rate;
struct cam_dram_snapshot dram_snapshot;
struct cam_sw sw;
struct bcam_reserved {
uint8_t resv[512];
} reserved;
};
int bcam_get_stats(const struct bcam *bcam, uint64_t stats_group, union bcam_stats *stats);
#ifdef __cplusplus
}
#endif
#endif
#ifndef aaaaaa1aaaH
#define aaaaaa1aaaH
#define aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaS 256
#define aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaS 32
#define aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaS 256
#define aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO 4
#define aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaS 32
#define aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaS 5
#define aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO 1
#define aaaaaa1aaaBCAM_FILL_RATIO 0.95
#define aaaaaa1aaaDRAMBCAM_FILL_RATIO_SOFTWARE 0.9
#define aaaaaa1aaaDRAMBCAM_FILL_RATIO_HARDWARE 0.95
#define aaaaaa1aaaDRAMBCAM_MAX_LIST_SIZE 1024
#define aaaaaa1aaa2W_aaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa 0.5
#define aaaaaa1aaa3W_aaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa 0.9
#define aaaaaa1aaaHaa1aaaREPLICATION_RATE 18.75
#define aaaaaa1aaaDDR_DRAM_REPLICATION_RATE 13.5
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaWORD 0x04
#define aaaaaa1aaaCA_WORD 0x08
#define aaaaaa1aaaECC_WORD 0x04
#define aaaaaa1aaaSM_WORD 0x80
#define aaaaaa1aaaaaaaaaaaaaaa1aaaWORD 0x80
#define aaaaaa1aaaaa1aaaWORD 0x08
#define aaaaaa1aaaaaaa1aaaWORD 0x100
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa 0x000100
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb5aaa 0x000100
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb5aaa 0x000104
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaRESP_WIDTH 0x000108
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaP_UNITS 0x00010c
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaFACTOR 0x000110
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaRAM_WIDTH 0x000114
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaRAM_DEPTH 0x000118
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaINST_TYPE 0x00011c
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaa6aaa 0x000120
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb5aaaS 0x000124
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaBUILD_NUM 0x000128
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaASIC 0x00012c
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb5aaaS 0x000130
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaCACHE_EN 0x000134
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaAGING_EN 0x000138
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaSTATS_EN 0x00013c
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaPOS 0x000140
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb5aaa 0x000160
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaVERSION 0x000180
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaSCRATCH 0x000184
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
#define aaaaaa1aaaDRAMBCAM_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa1US 0
#define aaaaaa1aaaDRAMBCAM_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa10US 1
#define aaaaaa1aaaDRAMBCAM_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa100US 2
#define aaaaaa1aaaDRAMBCAM_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa1MS 3
#define aaaaaa1aaaDRAMBCAM_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa10MS 4
#define aaaaaa1aaaDRAMBCAM_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa100MS 5
#define aaaaaa1aaaDRAMBCAM_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa1S 6
#define aaaaaa1aaaDRAMBCAM_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaNO_SAMPLE 7
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaR_MASK 0x00000fff
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaR_MASK 0xfffff000
#define aaaaaa1bbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaR_aaaaaaaaaaaaaaaaaaaaaa1aaa 12
#define aaaaaa1aaaHA_BASE 0x01000
#define aaaaaa1aaaHA_MASK 0x01800
#define aaaaaa1aaaHD_BASE 0x01800
#define aaaaaa1aaaHD_MASK 0x01800
#define aaaaaa1aaaDRAMBCAM_SIPHASH_V0_LO_aaaaaaaaaaaaaaaaaaaaa1aaa 0x200
#define aaaaaa1aaaDRAMBCAM_SIPHASH_V0_HI_aaaaaaaaaaaaaaaaaaaaa1aaa 0x204
#define aaaaaa1aaaDRAMBCAM_SIPHASH_V1_LO_aaaaaaaaaaaaaaaaaaaaa1aaa 0x208
#define aaaaaa1aaaDRAMBCAM_SIPHASH_V1_HI_aaaaaaaaaaaaaaaaaaaaa1aaa 0x20c
#define aaaaaa1aaaDRAMBCAM_SIPHASH_V2_LO_aaaaaaaaaaaaaaaaaaaaa1aaa 0x210
#define aaaaaa1aaaDRAMBCAM_SIPHASH_V2_HI_aaaaaaaaaaaaaaaaaaaaa1aaa 0x214
#define aaaaaa1aaaDRAMBCAM_SIPHASH_V3_LO_aaaaaaaaaaaaaaaaaaaaa1aaa 0x218
#define aaaaaa1aaaDRAMBCAM_SIPHASH_V3_HI_aaaaaaaaaaaaaaaaaaaaa1aaa 0x21c
#define aaaaaa1aaaDRAMBCAM_STAT_SAMP 0xCC
#define aaaaaa1aaaDRAMBCAM_DATA_WRITE_START_aaaaaaaaaaaaaaaaaaaaa1aaa 0x00
#define aaaaaa1aaaDRAMBCAM_DATA_READ_START_aaaaaaaaaaaaaaaaaaaaa1aaa 0xa0
#define aaaaaa1aaaDRAMBCAM_ADDRESS_aaaaaaaaaaaaaaaaaaaaa1aaa 0x80
#define aaaaaa1aaaDRAMBCAM_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaa 0x84
#define aaaaaa1aaaDRAMBCAM_SLVERR_ADDRESS_aaaaaaaaaaaaaaaaaaaaa1aaa 0x8c
#define aaaaaa1aaaDRAMBCAM_NARROW_DEF_RESP_ENABLE_aaaaaaaaaaaaaaaaaaaaa1aaa 0x8c
#define aaaaaa1aaaDRAMBCAM_NARROW_DEF_RESP_DATA_START_aaaaaaaaaaaaaaaaaaaaa1aaa 0x200
#endif
#ifndef _CAM_CONFIGP_H_
#define _CAM_CONFIGP_H_
#ifndef _CAMP_H_
#define _CAMP_H_
#ifndef _VBCAM_H_
#define _VBCAM_H_
#ifdef __cplusplus
extern "C" {
#endif
struct vbcam;
int vbcam_create(const cam_arg_t *cam_arg, struct vbcam **out_vbcam);
int vbcam_insert(struct vbcam* vbcam, const uint8_t key[], const uint8_t response[], const cam_options_t *options);
int vbcam_update(struct vbcam *vbcam, const uint8_t key[], const uint8_t response[], const cam_options_t *options);
int vbcam_get_by_response(struct vbcam *vbcam, const uint8_t response[],
const uint8_t response_mask[], uint32_t *pos,
uint8_t out_key[], const cam_options_t *options);
int vbcam_get_by_key(struct vbcam *vbcam, const uint8_t key[], uint8_t response[], const cam_options_t *options);
int vbcam_delete(struct vbcam *vbcam, const uint8_t key[], const cam_options_t *options);
int vbcam_compute_hash_value(const struct vbcam *vbcam, const uint8_t key[], uint8_t hash_value[32],
const cam_options_t *options);
int vbcam_get_segment(const struct vbcam *vbcam, const uint8_t hash_value[32], uint16_t *segment);
int vbcam_delete_all(struct vbcam* vbcam, const cam_options_t *options);
int vbcam_destroy(struct vbcam *vbcam);
int vbcam_read_and_clear_ecc_counters(struct vbcam *vbcam, uint32_t *corrected_single_bit_errors,
uint32_t *detected_double_bit_errors);
int vbcam_read_and_clear_ecc_addresses(struct vbcam *vbcam, uint32_t *failing_address_single_bit_error,
uint32_t *failing_address_double_bit_error);
int vbcam_set_ecc_test(struct vbcam* vbcam, bool inject_single_bit_errors,
bool inject_double_bit_errors);
typedef struct {
void *ctx;
int16_t segment;
} segment_ctx_t;
#ifdef __cplusplus
}
#endif
#endif
#define CAM_DRAMBCAM_HW_VERSION_MAJOR 3 
#define CAM_DRAMBCAM_HW_VERSION_MEDIUM 0 
#define CAM_SW_VERSION_MAJOR 2
#define CAM_SW_VERSION_MINOR 6
#define CAM_SW_VERSION_PATCH 0
#define CAM_BUILD_NUMBER 3971855
#define CAM_MIN_KEY_WIDTH 10
#define CAM_MAX_KEY_WIDTH_MEM ((CAM_MAX_KEY_WIDTH + 31) / 32)
#define CAM_MIN_PRIO_WIDTH 0
#define CAM_MAX_PRIO_WIDTH 32
#define CAM_MIN_RESPONSE_WIDTH 1
#define CAM_MAX_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa (CAM_MAX_PRIO_WIDTH + CAM_MAX_RESPONSE_WIDTH)
#define CAM_MAX_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaMEM ((CAM_MAX_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa + 31) / 32)
#define CAM_AGING_BITS (5 + 1 + 1)
#define CAM_MAX_FREQ_FPGA 600
#define CAM_MAX_FREQ_ASIC 800
#define CAM_RAM_HI_FREQ 312
#define CAM_LOGIC_HI_FREQ 330
#define CAM_BRAM_DEPTH2_MAX_FREQ 400
#define CAM_BRAM_DEPTH4_MAX_FREQ 330
#define CAM_URAM_DEPTH_HI_FREQ 400
#define CAM_LRAM_DEPTH_WIDTH64 64
#define CAM_BRAM_DEPTH_WIDTH64 512
#define CAM_URAM_DEPTH_WIDTH64 4096
#define CAM_LRAM_DEPTH_MIN CAM_LRAM_DEPTH_WIDTH64
#define CAM_BRAM_DEPTH_MIN CAM_BRAM_DEPTH_WIDTH64
#define CAM_URAM_DEPTH_MIN (CAM_URAM_DEPTH_WIDTH64 / 2)
#define CAM_URAM_DEPTH_MAX_LO_FREQ (8 * CAM_URAM_DEPTH_MIN)
#define CAM_URAM_DEPTH_MAX_HI_FREQ (4 * CAM_URAM_DEPTH_MIN)
#define CAM_MAX_NUM_LRAMS 32768
#define CAM_MIN_REPLICATION 1
#define CAM_MAX_REPLICATION 16
typedef struct {
uint32_t word[CAM_MAX_KEY_WIDTH_MEM];
} aaaaaaaaaaaaa1aaat;
typedef struct {
uint32_t word[CAM_MAX_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaMEM];
} aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat;
#define aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaa128 128
#define aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaMEM_128 ((aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaa128 + 7) / 8)
#define CAM_MAX_SEGMENT_HASH_ENTRIES 256 
#define CAM_HASH_VAL_SIZE_IN_BYTES 4 
#define CAM_MAX_SEGMENT_HASH_ENTRIES_WIDTH 8
#define CAM_MAX_VC_SEGMENTS 256
#define CAM_MAX_VC_SEGMENTS_MEM ((CAM_MAX_VC_SEGMENTS + 7) / 8)
#define CAM_MAX_VCS 128 
#define CAM_MAX_NUM_FIELDS 32
#define CAM_MAX_COMPLEXITY ((uint64_t) 1 << CAM_MAX_NUM_FIELDS)
#define CAM_ARG_FORMAT_LEN 1024
#define CAM_MAX_GEN_NUMBER_GRANULARITY 256
#ifndef NULL_CHECK
#define NULL_CHECK(ptr) if (ptr == NULL) return CAM_ERROR_NULL_POINTER
#endif
typedef enum {
AUTO, URAM, BRAM, LRAM
} cam_mem_type_t;
typedef struct {
int16_t vcid; 
uint8_t bit_map[CAM_MAX_VC_SEGMENTS_MEM]; 
}vc_cam_segment_map_t;
typedef void* (*cam_malloc_func)(size_t sz); 
typedef void* (*cam_realloc_func)(void* ptr, size_t sz); 
typedef void* (*cam_calloc_func)(size_t num, size_t size);
typedef void (*cam_free_func)(void* ptr); 
typedef int (*cam_posix_memalign_func)(void** ptr, size_t align_size, size_t size); 
#define MAX_HW_BLOCKS 2
struct cam_arg_t {
uint32_t num_entries;
uint16_t num_units;
uint8_t num_slots;
unsigned num_pcs; 
cam_mem_type_t mem_type;
int16_t priority_width;
uint16_t response_width;
float lookup_interface_freq;
float engine_lookup_rate;
bool hbm;
bool ddr_dram;
bool asic_ram;
bool public_r_size;
int32_t r_size;
int8_t num_phys_banks; 
int32_t channel_width; 
int32_t replication;
enum cam_arg_update_mode update_mode;
uint16_t max_num_brams;
uint16_t max_num_urams;
uint8_t max_macro_height;
bool versal;
float ram_freq;
char format[CAM_ARG_FORMAT_LEN];
uint16_t key_width;
uint16_t fingerprint_width;
uint8_t num_masks;
uint16_t narrow_key_width;
bool flow_control;
bool aging;
uint8_t default_response[sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat)];
uint8_t narrow_default_response[sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat)];
struct {
void (*hw_write_function)(void*, uint32_t, uint32_t);
void (*hw_read_function)(void*, uint32_t, uint32_t*);
} io[MAX_HW_BLOCKS];
void (*hw_write_start_sequence_function)(void*);
void (*hw_write_end_sequence_function)(void*);
uint32_t debug_flags;
void (*error_print_function)(void*, char*);
void (*info_print_function)(void*, char*);
cam_malloc_func malloc_function;
cam_realloc_func realloc_function;
cam_free_func free_function;
cam_calloc_func calloc_function;
cam_posix_memalign_func posix_memalign_function;
vc_cam_segment_map_t vc_seg_map; 
segment_ctx_t segment_ctx;
uint8_t vc_id;
uint16_t max_hw_writes;
bool options; 
uint32_t optimization_flags;
bool calc_heap_size;
uint32_t max_tcam_heap_size; 
uint8_t hash_function; 
uint64_t hash_k0, hash_k1; 
uint16_t generation_number_granularity;
};
struct cam_options_t {
bool narrow; 
bool precomp_hash;
uint64_t hash_value;
bool search_single_segment;
uint8_t single_segment;
bool override_debug_flags;
uint32_t debug_flags;
};
void camp_arg_set_ram_size(struct cam_arg_t *cam_arg, uint32_t size);
void camp_arg_set_seg(struct cam_arg_t *cam_arg, uint16_t segment);
void camp_arg_set_vcid(struct cam_arg_t *cam_arg, uint8_t vcid);
void camp_arg_force_num_slots(struct cam_arg_t *cam_arg, uint8_t slots);
#ifndef _aaa1aaaT_
#define _aaa1aaaT_
typedef struct aaa1aaat aaa1aaat;
#endif
typedef struct {
aaa1aaat *phm;
uint32_t list;
uint64_t bucket;
aaaaaaaaaaaaa1aaat key;
aaaaaaaaaaaaa1aaat mask;
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa;
uint8_t narrow;
uint8_t narrow_element;
uint16_t fingerprint;
} cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat;
void cam_mask_key(aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaa1aaat *mask);
char *byte_arr_to_str(uint16_t bit_len, const uint8_t *src,
void *(*malloc_function)(size_t));
typedef enum {
DELETE, UPDATE, OTHER
} operation_t;
#endif
#ifndef _CAM_CONFIG_H_
#define _CAM_CONFIG_H_
#ifdef __cplusplus
extern "C" {
#endif
#ifndef _CAM_CONFIG_T_
#define _CAM_CONFIG_T_
typedef struct cam_config_t cam_config_t;
#endif
typedef enum {
TCAM = 1,
BCAM = 2,
STCAM = 3,
DRAMBCAM = 4,
COMPBCAM = 5,
CSTCAM = 6
} cam_instance_type_t;
int cam_config_create(const cam_arg_t *cam_arg, cam_instance_type_t cam_instance_type, cam_config_t **cam_config);
size_t cam_config_size(void);
int cam_config_init(const cam_arg_t *cam_arg,
cam_instance_type_t cam_instance_type, cam_config_t *cam_config);
void cam_config_destroy(cam_config_t *cam_config);
uint16_t cam_config_get_key_width(const cam_config_t *cam_config);
uint16_t cam_config_get_narrow_key_width(const cam_config_t *cam_config);
uint32_t cam_config_get_num_entries(const cam_config_t *cam_config);
uint8_t cam_config_get_num_masks(const cam_config_t *cam_config);
uint8_t cam_config_get_prio_width(const cam_config_t *cam_config);
uint16_t cam_config_get_response_width(const cam_config_t *cam_config);
uint8_t cam_config_get_fingerprint_width(const cam_config_t *cam_config);
uint16_t cam_config_get_num_units(const cam_config_t *cam_config);
uint8_t cam_config_get_num_slots(const cam_config_t *cam_config);
uint16_t cam_config_get_num_physical_units(const cam_config_t *cam_config);
uint16_t cam_config_get_list_length(const cam_config_t *cam_config);
uint32_t cam_config_get_num_lists(const cam_config_t *cam_config);
uint8_t cam_config_get_hash_function(const cam_config_t *cam_config);
uint16_t cam_config_get_latency(const cam_config_t *cam_config);
uint16_t cam_config_get_pipeline_capacity(const cam_config_t *cam_config);
uint16_t cam_config_get_num_lrams(const cam_config_t *cam_config);
uint16_t cam_config_get_num_brams(const cam_config_t *cam_config);
uint16_t cam_config_get_num_urams(const cam_config_t *cam_config);
uint8_t cam_config_get_num_ranges(const cam_config_t *cam_config);
bool cam_config_is_tcam_instance(const cam_config_t *cam_config);
bool cam_config_is_bcam_instance(const cam_config_t *cam_config);
bool cam_config_is_drambcam_instance(const cam_config_t *cam_config);
bool cam_config_is_lram_instance(const cam_config_t *cam_config);
bool cam_config_is_uram_instance(const cam_config_t *cam_config);
bool cam_config_is_ddr_dram_instance(const cam_config_t *cam_config);
bool cam_config_is_mixed_mode(const cam_config_t *cam_config);
bool cam_config_is_virtualized(const cam_config_t *cam_config);
void cam_config_get_default_response(const cam_config_t *cam_config, uint8_t *default_response);
void cam_config_get_narrow_default_response(const cam_config_t *cam_config, uint8_t *narrow_default_response);
bool cam_config_has_flow_control(const cam_config_t *cam_config);
bool cam_config_is_single_clock(const cam_config_t *cam_config);
int cam_config_get_range_start_pos(const cam_config_t *cam_config, uint8_t range_number,
uint16_t *start_pos);
int cam_config_get_range_width(const cam_config_t *cam_config, uint8_t range_number, uint8_t *width);
uint8_t cam_config_get_field_width(const cam_config_t *cam_config, uint8_t field_num);
uint8_t cam_config_get_num_pcs(const cam_config_t *cam_config);
uint8_t cam_config_get_replication(const cam_config_t *cam_config);
uint16_t cam_config_get_field_pos(const cam_config_t *cam_config, uint8_t field_num);
uint8_t cam_config_get_depth_cascade(const cam_config_t *cam_config);
uint16_t cam_config_get_channel_width(const cam_config_t *cam_config);
uint8_t cam_config_get_num_phys_banks(const cam_config_t * const cam_config);
uint32_t cam_config_calculate_heap_size(const cam_config_t *config);
char *cam_config_get_header(const cam_config_t *cam_config);
char *cam_config_get_values(const cam_config_t *cam_config);
char *cam_config_get_lookup_clock_info(const cam_config_t *cam_config);
char *cam_config_get_ram_clock_info(const cam_config_t *cam_config);
char *cam_config_get_tdm_info(const cam_config_t *cam_config);
char *cam_config_get_ram_utilization_info(const cam_config_t *cam_config);
char *cam_config_get_memory_units_info(const cam_config_t *cam_config);
void cam_config_print(const cam_config_t *cam_config);
#ifdef __cplusplus
}
#endif
#endif
#define CAM_CONFIG_MAX_RANGES 8
typedef enum {
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaR16 = 0, 
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaP128, 
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaB128, 
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaT64, 
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaC128, 
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaU128, 
} aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaatypes;
typedef struct {
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaatypes type;
uint8_t instance;
uint16_t start_pos;
uint16_t len;
} aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc;
typedef struct {
uint8_t replication;
float replication_rate;
uint8_t depth_cascade;
uint8_t max_units;
uint8_t min_depth_cascading;
uint8_t max_channels;
uint8_t num_consecutive_reads;
uint8_t num_pcs;
float fill_level;
} drambcam_t;
struct cam_config_t {
cam_arg_t arg;
uint16_t key_width;
uint16_t num_units;
uint8_t num_slots;
uint16_t num_physical_units;
uint16_t list_length;
uint32_t num_lists;
cam_mem_type_t mem_type;
uint8_t num_ranges;
uint16_t range_start_pos[CAM_CONFIG_MAX_RANGES];
uint8_t range_width[CAM_CONFIG_MAX_RANGES];
uint64_t complexity;
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc aaaaaaaaaaaaaaaaaa1aaa[CAM_MAX_NUM_FIELDS];
uint8_t num_fields;
uint16_t latency;
uint16_t pipeline_capacity;
uint8_t prio_width;
uint32_t ram_size;
cam_instance_type_t instance_type;
drambcam_t drambcam;
bool flow_control;
bool hw_stats_enabled; 
uint16_t segment; 
void *ctx;
};
#ifndef _CAM_CONFIG_T_
#define _CAM_CONFIG_T_
typedef struct cam_config_t cam_config_t;
#endif
int cam_config_get_aaaaaaaaaaaaaaaaaa1aaa(const cam_config_t *cam_config, uint8_t field_number, aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc *desc);
uint16_t cam_config_get_num_entries_per_unit(const cam_config_t *cam_config);
uint8_t cam_config_get_num_fields(const cam_config_t *cam_config);
uint32_t cam_config_get_num_entries(const cam_config_t *cam_config);
uint32_t cam_config_get_ram_size(const cam_config_t *cam_config);
uint16_t cam_config_get_segment(const cam_config_t *cam_config);
float cam_config_get_dram_fill_level(const cam_config_t *cam_config);
void cam_config_print(const cam_config_t *cam_config);
static inline void cam_hw_write(const struct cam_config_t *conf, uint32_t addr, uint32_t data)
{
conf->arg.io[0].hw_write_function(conf->ctx, addr, data);
}
static inline void cam_hw_read(const struct cam_config_t *conf, uint32_t addr, uint32_t *data)
{
conf->arg.io[0].hw_read_function(conf->ctx, addr, data);
}
#endif
#ifndef CLIENT_H
#define CLIENT_H
#ifndef aaa1aaaH
#define aaa1aaaH
#ifndef aaaa1aaaH
#define aaaa1aaaH
#ifndef aaaaaaaaaaaaaaa1aaaH
#define aaaaaaaaaaaaaaa1aaaH
#ifndef _aaaaaaaaaaaaaaa1aaaT_
#define _aaaaaaaaaaaaaaa1aaaT_
typedef struct aaaaaaaaaaaaaaa1aaat aaaaaaaaaaaaaaa1aaat;
#endif
size_t aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa(void);
void aaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(aaaaaaaaaaaaaaa1aaat *pointer_list, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *prio, const aaaaaaaaaaaaa1aaat *aaaaaaaaa1aaa,
const aaaaaaaaaaaaa1aaat *ternary_mask, bool narrow_key, uint16_t fingerprint);
uint64_t aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaabaaaaaaaaaaa4aaa(const aaaaaaaaaaaaaaa1aaat *pointer_list);
uint8_t aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(const struct aaaaaaaaaaaaaaa1aaat *pointer_list);
const aaaaaaaaaaaaa1aaat *aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaa1aaa(const aaaaaaaaaaaaaaa1aaat *pointer_list, uint8_t key_number);
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaa4aaa(const aaaaaaaaaaaaaaa1aaat *pointer_list, uint8_t key_number);
void aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(aaaaaaaaaaaaaaa1aaat *pointer_list, uint64_t bucket, bool is_direct_pointer_list, bool ternary_list);
void aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaall(aaaaaaaaaaaaaaa1aaat *pointer_list);
bool aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(const aaaaaaaaaaaaaaa1aaat *pointer_list);
const aaaaaaaaaaaaa1aaat *aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaternary_mask(const aaaaaaaaaaaaaaa1aaat *pointer_list, uint8_t key_number);
bool aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaanarrow_key(const aaaaaaaaaaaaaaa1aaat *pointer_list, uint8_t key_number);
uint16_t aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaafingerprint(const aaaaaaaaaaaaaaa1aaat *pointer_list, uint8_t key_number);
#endif
#ifndef _aaaa1aaaT_
#define _aaaa1aaaT_
typedef struct aaaa1aaat aaaa1aaat;
#endif
#ifndef _CLIENT_T_
#define _CLIENT_T_
typedef struct client_t client_t;
#endif
#define KEY_AND_MASK_WIDTH_MEM (CAM_MAX_KEY_WIDTH_MEM * 2)
typedef struct {
uint32_t word[KEY_AND_MASK_WIDTH_MEM]; 
} key_and_mask_t;
typedef struct {
bool direct_pointer;
uint16_t perfect_bucket;
} source_bucket_t;
struct aaaa1aaat {
source_bucket_t *source_bucket;
uint32_t *aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata;
uint32_t *valid_cache;
uint16_t *fingerprint;
bool flush;
client_t *client;
uint16_t unit;
uint8_t slot_number;
};
size_t aaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa(void);
size_t aaaa1aaasource_bucket_size(void);
bool aaaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(aaaa1aaat *km, client_t *client, uint16_t unit, uint8_t slot_number, bool flush);
void aaaa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(aaaa1aaat* km, cam_free_func free_function);
void aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaabcam(aaaa1aaat *km, const cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat *);
void aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, const aaaaaaaaaaaaaaa1aaat *pointer_list, uint8_t narrow, uint8_t narrow_element);
uint32_t aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaabaaaaaaaaaa4aaa(const aaaa1aaat *km);
void aaaa1bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaa1aaa(aaaa1aaat *km, void *ptr);
void *aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaa1aaa(aaaa1aaat *km);
bool aaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaafit_for_pointer_list(const aaaa1aaat *km, const aaaaaaaaaaaaaaa1aaat *pointer_list,
uint32_t *aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
void aaaa1aaaread(const aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, aaaaaaaaaaaaaaa1aaat *pointer_list);
void aaaa1bbbbbbbbbbbbbbbbb3aaa(aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
bool aaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(const aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
bool aaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaapresent(const aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, uint8_t narrow, uint8_t narrow_element);
void aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaabits(const aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, bool *wide_valid, bool *narrow1_valid,
bool *narrow0_valid);
bool aaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(const aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
bool aaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(const aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
uint32_t aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaabaaaaaaaaaaa4aaa(const aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
void aaaa1bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbb4aaa(aaaa1aaat *km);
void aaaa1bbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbb4aaa(aaaa1aaat *km);
void aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaa(aaaa1aaat *km);
void aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaelement(aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, uint8_t narrow, uint8_t narrow_element);
bool aaaa1aaaread_element_bcam(aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat *aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaout,
int* verify, uint8_t narrow,
uint8_t narrow_element);
bool aaaa1aaaread_element_tcam(aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, aaaaaaaaaaaaaaa1aaat *pointer_list,
int* verify, uint8_t narrow,
uint8_t narrow_element);
void aaaa1bbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaand_flush(aaaa1aaat *target_km, aaaa1aaat *source_km, uint32_t list);
void aaaa1bbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *prio, uint8_t narrow,
uint8_t narrow_element);
void aaaa1bbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *prio, uint8_t narrow,
uint8_t narrow_element);
void aaaa1bbbbbbbbbbbbbbbb3aaa(aaaa1aaat *target_km, const aaaa1aaat *source_km);
void aaaa1bbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaall(aaaa1aaat *km);
void get_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(const aaaa1aaat *km, uint32_t list_number, aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa,
uint8_t narrow, uint8_t narrow_element);
void get_key(const aaaa1aaat *km, uint32_t list_number, key_and_mask_t *key, uint8_t narrow, uint8_t narrow_element);
void set_key(const aaaa1aaat *km, uint32_t list_number, const key_and_mask_t *key,
uint8_t narrow, uint8_t narrow_element);
uint16_t calc_start_pos_gen_number(uint16_t width_wo_gen_num, uint16_t end_pos_w_gen_num, uint16_t granularity);
uint16_t calc_end_pos_gen_number(uint16_t width_wo_gen_num, uint16_t start_pos_w_gen_num, uint16_t granularity);
void set_generation_number(const aaaa1aaat *km, uint32_t list_number, uint8_t narrow, uint8_t narrow_element,
uint8_t generation_number);
uint8_t get_generation_number(const aaaa1aaat *km, uint32_t list_number, uint8_t narrow, uint8_t narrow_element);
void set_control_bits(const aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, uint8_t valid,
uint8_t narrow,
uint8_t narrow_element);
void set_valid_bit(const aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, uint32_t valid);
void flush(aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, bool init_clear,
int *verify, operation_t operation,
uint8_t narrow,
uint8_t narrow_element, bool bit511or255, bool wide2narrow);
void write_field_with_gen_number(uint32_t *target, uint16_t target_start_pos_w_gen_num,
uint16_t source_width_wo_gen_num, uint32_t * source, 
uint16_t target_pos_limit_w_gen_num, uint16_t granularity);
#endif
#ifndef _aaaaaaaaaaaaaaa1aaaT_
#define _aaaaaaaaaaaaaaa1aaaT_
typedef struct aaaaaaaaaaaaaaa1aaat aaaaaaaaaaaaaaa1aaat;
#endif
#ifndef _CLIENT_T_
#define _CLIENT_T_
typedef struct client_t client_t;
#endif
#ifndef _aaaa1aaaT_
#define _aaaa1aaaT_
typedef struct aaaa1aaat aaaa1aaat;
#endif
#ifndef _aa1aaaT_
#define _aa1aaaT_
typedef struct aa1aaat aa1aaat;
#endif
#ifndef _aaaaaaaaaaaa1aaaT_
#define _aaaaaaaaaaaa1aaaT_
typedef struct aaaaaaaaaaaa1aaat aaaaaaaaaaaa1aaat;
#endif
typedef enum {
aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaa = 0, aaa1aaaREAD = 1, aaa1bbbbbbbbbbbbbbbbbbbb3aaa = 2
} aaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaat;
struct aaa1aaat {
aaaa1aaat *km;
aa1aaat *bm;
aaaaaaaaaaaa1aaat *mm;
uint32_t number_of_keys;
client_t *client;
};
bool aaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabcam(aaa1aaat *phm, client_t *client, uint16_t unit, uint8_t slot_number);
void aaa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabcam(aaa1aaat* phm, cam_free_func free_function);
bool aaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(aaa1aaat *phm, client_t *client, uint16_t unit, uint8_t slot_number);
void aaa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(aaa1aaat* phm, cam_free_func free_function);
size_t aaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa(void);
bool aaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaa(aaa1aaat *phm, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaa1aaat *ternary_mask,
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response,
bool true_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaafit,
uint8_t recover_start_function);
uint32_t aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaatal_number_of_bucket_keys(const aaa1aaat *phm);
uint32_t aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaatal_number_of_aaaaaaaaa1aaas(const aaa1aaat *phm);
uint32_t aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_aaaaaaaaa1aaas(const aaa1aaat *phm);
uint32_t aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaatal_number_of_elements(const aaa1aaat *phm);
void aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(const aaa1aaat *phm);
void aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6aaa(aaa1aaat *phm, const aaaaaaaaaaaaa1aaat *mask,
uint16_t seed, uint8_t range_valid, uint8_t mask_id);
bool aaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaequal(const aaa1aaat *phm, const aaaaaaaaaaaaa1aaat *mask, uint8_t range_valid,
uint8_t mask_id);
bool aaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaavalid(const aaa1aaat *phm);
void aaa1bbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6aaa(const aaa1aaat *phm);
bool aaa1bbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaone_element(aaa1aaat *target_phm, aaa1aaat *source_phm);
void aaa1aaaread_mask(const aaa1aaat *phm, aaaaaaaaaaaaa1aaat *mask, uint8_t *range_valid,
uint8_t *mask_id);
uint32_t aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(const aaa1aaat *phm);
uint8_t aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(const aaa1aaat *phm);
bool aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(aaa1aaat *phm, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response_mask,
uint32_t *start_value,
aaaaaaaaaaaaa1aaat *aaaaaaaaa1aaa,
aaaaaaaaaaaaa1aaat *ternary_mask, uint8_t *narrow,
uint8_t *narrow_element, bool narrow_key, int *verify);
bool aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaabcam(aaa1aaat *phm, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response_mask,
uint32_t *start_value,
aaaaaaaaaaaaa1aaat *aaaaaaaaa1aaa,
aaaaaaaaaaaaa1aaat *ternary_mask, uint8_t *narrow,
uint8_t *narrow_element, bool narrow_key, int *verify);
uint16_t aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(const aaa1aaat *phm);
aaaa1aaat* aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaakm(const aaa1aaat *phm);
uint16_t aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaseed(const aaa1aaat *phm);
void aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(const aaa1aaat *phm, const aaaaaaaaaaaaa1aaat *key, aaaaaaaaaaaaa1aaat *masked_key);
bool aaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(aaa1aaat *phm, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaa1aaat *ternary_mask, aaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaat execute,
bool *unresolvable_collision_found, bool match_prio,
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *comp_prio, int *verify);
bool aaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup(const aaa1aaat *phm, const aaaaaaaaaaaaa1aaat *key, aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *out_prio_response);
int aaa1aaacheck_ternary_mask(const client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaa1aaat *ternary_mask,
const aaaaaaaaaaaaa1aaat *mask, uint8_t range_valid);
const client_t *aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaclient(const aaa1aaat *phm);
void phm_read_and_clear_recover_stats(uint8_t *highest_recover_function, uint8_t *highest_recover_seed_increment,
uint32_t *num_recovers);
bool aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(aaa1aaat *phm, const aaaaaaaaaaaaa1aaat *key, aaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaat execute,
bool match_response, aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response, uint64_t hash_value,
bool narrow_key, int *verify);
bool aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaa(aaa1aaat *phm, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response, uint64_t hash_value,
cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat *evicted_entry,
bool narrow_key);
bool aaa1aaaif_invalid_insert(aaa1aaat *phm, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response, uint64_t hash_value,
bool narrow_key,
bool pack_narrow);
bool aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup(const aaa1aaat *phm, const aaaaaaaaaaaaa1aaat *key, aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *out_prio_resp, bool narrow_key);
void aaa1bbbbbbbbbbbbbbbbbbb3aaa(const aaa1aaat *phm, const client_t *client);
uint32_t aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaafrom_hash_value(const aaa1aaat *phm, uint64_t hash_value, uint16_t *fingerprint);
bool aaa1aaaread_element(aaa1aaat *phm, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa,
cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat *aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaout, int *verify, uint8_t narrow,
uint8_t narrow_element);
bool aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaelement(aaa1aaat *phm, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, uint8_t narrow, uint8_t narrow_element);
void aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaall(aaa1aaat *phm, uint32_t* deletes);
uint32_t aaa1aaaadjust_list(const aaa1aaat *phm, uint32_t list);
#endif
#ifndef HTABLE_H
#define HTABLE_H
#include <math.h>
#ifndef _HTABLE_T_
#define _HTABLE_T_
typedef struct htable_t htable_t;
#endif
#define HTABLE_MAX_KEY_SIZE (CAM_MAX_KEY_WIDTH_MEM * 2)
#ifndef _HTABLE_KEY_T_
#define _HTABLE_KEY_T_
typedef struct
{
uint32_t word[HTABLE_MAX_KEY_SIZE];
} htable_key_t;
#endif
size_t htable_size(void);
void htable_free(htable_t *htable, cam_free_func free_function);
void htable_write(htable_t *htable, uint64_t hash_value, uint16_t value);
bool htable_init(htable_t* htable, uint32_t size, cam_calloc_func calloc_function);
void htable_inc(htable_t *htable, uint64_t hash_value);
void htable_num_entries_to_num_buckets(uint32_t num_entries,
uint32_t *num_buckets, uint8_t *log2_num_buckets);
void htable_read(const htable_t *htable, uint64_t hash_value, uint8_t *counter, uint16_t *value, bool *value_unknown);
void htable_dec(htable_t *htable, uint64_t hash_value, uint16_t value);
void htable_calc_stats(htable_t *htable, uint32_t *size, uint32_t *zeroes, uint32_t *ones, uint32_t *twoplussum,
uint32_t *onetwoeightplus, uint32_t *sumfirsthalf);
void htable_clear(htable_t *htable);
#endif
#ifndef _CLIENT_T_
#define _CLIENT_T_
typedef struct client_t client_t;
typedef struct comp_cam_client_t comp_cam_client_t;
#endif
#ifndef _aaa1aaaT_
#define _aaa1aaaT_
typedef struct aaa1aaat aaa1aaat;
#endif
#ifndef _aaaa1aaaT_
#define _aaaa1aaaT_
typedef struct aaaa1aaat aaaa1aaat;
#endif
#define CLOG2(N) ((N) == 1 ? 0 : 32 - __builtin_clz((uint32_t) ((N) - 1)))
#define BITS(N) (32 - __builtin_clz((uint32_t) (N)))
#define DIV_UP(N, S) (((N) + (S) - 1) / (S))
#define ROUND_UP(N, S) ((((N) + (S) - 1) / (S)) * (S))
typedef enum {
UNUSED = 0, OPEN = 1, CLOSED = 2, RECOVER = 3
} unit_mode_t;
typedef struct {
unit_mode_t unit_mode;
aaa1aaat *phm;
} unit_t;
struct client_t {
cam_config_t *conf;
unit_t unit[aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaS];
aaaa1aaat *test_km; 
uint64_t prev_hi_addr;
uint64_t prev_hi_data;
bool prev_hi_addr_unknown;
bool prev_hi_data_unknown;
htable_t *htable; 
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat default_response;
bool default_response_valid;
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat narrow_default_response; 
bool narrow_default_response_valid; 
cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat *overwrites; 
uint16_t num_overwrites; 
bool zero_unused; 
uint32_t num_entries; 
uint32_t narrow_num_entries; 
uint64_t num_inserts; 
uint64_t num_updates; 
uint64_t num_deletes; 
uint32_t failed_inserts; 
uint32_t failed_updates; 
uint32_t failed_deletes; 
uint64_t num_collisions; 
uint16_t max_collisions; 
uint8_t num_used_masks; 
uint64_t num_shadow_writes;
bool use_cue; 
};
int verify_config(client_t *client);
void write_mask(client_t *client, const aaaaaaaaaaaaa1aaat *mask, uint16_t unit,
uint8_t range_valid, uint8_t mask_id);
bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen_with_equal_mask(const client_t *client, uint16_t *start_value,
const aaaaaaaaaaaaa1aaat *mask,
uint8_t range_valid, uint8_t mask_id);
void set_unused(client_t *client, uint16_t unit);
bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaunused(const client_t *client, uint16_t *start_value);
void set_open(client_t *client, uint16_t unit);
void set_closed(client_t *client, uint16_t unit);
bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen_or_closed(const client_t *client, uint16_t *start_value);
size_t client_size(void);
#define CLIENT_MAX_OVERWRITES 512
size_t client_overwrite_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa(void);
int client_create_bcam(const cam_arg_t *cam_arg, cam_instance_type_t cam_instance_type, client_t **client);
int client_create_tcam(const cam_arg_t *cam_arg, client_t **client);
uint32_t client_calculate_heap_size(const cam_config_t *config,
cam_instance_type_t instance_type);
bool client_is_wide_instance(const client_t *client);
uint8_t client_get_client_number(const client_t *client);
uint16_t client_get_list_length(const client_t *client);
uint16_t client_get_num_units(const client_t *client);
uint32_t client_get_num_lists(const client_t *client);
bool client_is_overwritten(const client_t *client, const aaa1aaat *phm, uint32_t list);
void client_add_overwrite(client_t *client, const cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat *entry);
void client_inc_shadow_writes(client_t *client);
int client_get_widths(const client_t *client, uint16_t *key_width, uint16_t *response_width,
bool narrow_key);
uint8_t client_get_num_slots(const client_t *client);
uint16_t client_get_key_width(const client_t *client);
uint16_t client_get_narrow_key_width(const client_t *client);
uint8_t client_get_prio_width(const client_t *client);
uint16_t client_get_response_width(const client_t *client);
uint8_t client_get_fingerprint_width(const client_t *client);
uint16_t client_get_num_entries_per_unit(const client_t *client);
uint8_t client_get_num_fields(const client_t *client);
uint32_t client_get_num_entries(const client_t *client);
uint8_t client_get_num_masks(const client_t *client);
uint8_t client_get_num_ranges(const client_t *client);
int client_get_range_start_pos(const client_t *client, uint8_t range_number, uint16_t *start_pos);
int client_get_range_width(const client_t *client, uint8_t range_number, uint8_t *width);
int client_get_aaaaaaaaaaaaaaaaaa1aaa(const client_t *client, uint8_t field_number, aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc *desc);
void client_destroy_bcam(client_t *client);
void client_destroy_tcam(client_t *client);
void client_print(const client_t *client);
void client_table_print(const client_t *client);
int client_update_range_key(client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaa1aaat *ternary_mask,
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *key_prio,
const aaaaaaaaaaaaa1aaat *mask, uint8_t range_valid, uint8_t mask_id);
int client_delete_range_key(client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaa1aaat *ternary_mask,
const aaaaaaaaaaaaa1aaat *mask, uint8_t range_valid, uint8_t mask_id);
int client_read_prio_for_range_key(const client_t *client, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response,
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response_mask,
uint32_t *pos,
aaaaaaaaaaaaa1aaat *key, aaaaaaaaaaaaa1aaat *ternary_mask, aaaaaaaaaaaaa1aaat *mask, uint8_t *range_valid,
uint8_t *mask_id);
int client_read_response_for_key(const client_t *client, aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response, aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *prio_mask,
uint32_t *pos,
aaaaaaaaaaaaa1aaat *key,
aaaaaaaaaaaaa1aaat *mask, bool narrow_key);
int client_update_key(client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response, const aaaaaaaaaaaaa1aaat *mask,
const cam_options_t *options);
int client_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response, const aaaaaaaaaaaaa1aaat *mask,
const cam_options_t *options);
int client_delete_key(client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaa1aaat *mask, const cam_options_t *options);
int client_read_key(const client_t *client, const aaaaaaaaaaaaa1aaat *key, aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response, const aaaaaaaaaaaaa1aaat *mask,
const cam_options_t *options);
int client_read_range_key(const client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaa1aaat *ternary_mask,
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response, const aaaaaaaaaaaaa1aaat *mask, uint8_t range_valid,
uint8_t mask_id);
int client_lookup_tcam(client_t *client, const aaaaaaaaaaaaa1aaat *key, aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response);
int client_lookup_stcam(client_t *client, const aaaaaaaaaaaaa1aaat *key, aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response, bool narrow_key);
void client_print_prio(const client_t *client, uint32_t prio, uint32_t prio_mask);
aaa1aaat *client_get_recover_phm(const client_t *client);
aaaa1aaat *client_get_test_km(const client_t *client);
uint8_t client_get_num_ranges(const client_t *client);
bool client_is_tcam(const client_t *client);
bool client_is_bcam(const client_t *client);
bool client_is_drambcam(const client_t *client);
uint8_t client_get_num_pcs(const client_t *client);
uint8_t client_get_replication(const client_t *client);
uint8_t client_get_depth_cascade(const client_t *client);
uint8_t client_get_num_phys_banks(const client_t *client);
uint32_t client_get_ram_size(const client_t *client);
uint16_t client_get_channel_width(const client_t *client);
uint16_t client_get_dram_read_width(const client_t *client);
uint16_t client_get_segment(const client_t *client);
uint32_t client_get_num_lists_per_read(const client_t * const client);
bool client_is_mixed_mode(const client_t *client);
uint32_t client_get_current_num_entries(const client_t *client);
void client_drambaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(client_t *client, uint32_t address, uint32_t data[], uint8_t write_mask,
operation_t delete_oprn, bool bit511or255, uint16_t fingerprint);
void client_drambaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaread(client_t *client, uint32_t address, uint32_t data[]);
void client_hw_write(client_t *client, uint32_t address, uint64_t data);
void client_hw_read(client_t *client, uint32_t address, uint64_t *data);
void client_drambcam_hw_write_64(const client_t *client, uint32_t address, uint64_t data64);
void client_drambcam_hw_write_32(const client_t *client, uint32_t address, uint32_t data32);
htable_t *client_get_htable(const client_t *client);
aaa1aaat *client_get_phm(const client_t *client, uint16_t unit);
void client_get_default_response(const client_t *client, uint8_t *default_response, bool narrow_key);
int client_read_and_clear_ecc_counters(client_t *client, uint32_t *corrected_single_bit_errors,
uint32_t *detected_double_bit_errors);
int client_read_and_clear_ecc_addresses(client_t *client, uint32_t *failing_address_single_bit_error,
uint32_t *failing_address_double_bit_error);
int client_set_ecc_test(client_t *client,
bool inject_single_bit_errors,
bool inject_double_bit_errors);
void client_set_debug_flags(const client_t *client, uint32_t debug_flags);
uint32_t client_get_debug_flags(const client_t *client);
void client_print_error(const client_t *client, char *message);
void client_print_info(const client_t *client, char *message);
int client_read_config(client_t *client, cam_config_t *hw_config);
void client_start_serialize(const client_t *client);
void client_end_serialize(client_t *client);
void client_flush(const client_t *client);
cam_free_func client_get_free_function(const client_t* client);
cam_posix_memalign_func client_get_posix_memalign_function(const client_t* client);
cam_malloc_func client_get_malloc_function(const client_t* client);
cam_calloc_func client_get_calloc_function(const client_t* client);
cam_realloc_func client_get_realloc_function(const client_t* client);
int client_get_current_num_units(const client_t *client);
bool client_has_options(const client_t *client);
uint8_t client_get_hash_function(const client_t *client);
int client_read_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup_data(client_t *client, struct cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup *aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup);
int client_read_dram_rate_stats(client_t *client, struct cam_dram_rate *dram_rate);
int client_read_dram_snapshot_stats(client_t *client, struct cam_dram_snapshot *dram_snapshot);
void client_get_sw_stats(client_t *client, struct cam_sw *sw);
void client_delete_all(client_t *client);
uint16_t client_get_generation_number_granularity(const client_t *client);
#endif
#ifndef _aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaH
#define _aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaH
#include <assert.h>
#ifndef _MURMUR3_H_
#define _MURMUR3_H_
#ifdef __cplusplus
extern "C" {
#endif
void murmur3(const void *key, uint16_t len, uint32_t seed, uint32_t *hashv);
void murmur3_bucket(const void *key, uint16_t keylen, uint32_t num_buckets, uint32_t *hashv, uint32_t *bucket);
#ifdef __cplusplus
}
#endif
#endif 
#ifndef _TCAM_H_
#define _TCAM_H_
#ifdef __cplusplus
extern "C" {
#endif
struct tcam;
int
tcam_create(const cam_arg_t *cam_arg, struct tcam **out_tcam);
int tcam_insert(struct tcam *tcam, const uint8_t key[], const uint8_t mask[], uint32_t prio, const uint8_t response[]);
int tcam_update(struct tcam *tcam, const uint8_t key[], const uint8_t mask[], const uint8_t response[]);
int tcam_get_by_response(struct tcam *tcam, const uint8_t response[], const uint8_t response_mask[], uint32_t *pos,
uint8_t out_key[],
uint8_t out_mask[]);
int tcam_get_by_key(struct tcam *tcam, const uint8_t key[], const uint8_t mask[], uint32_t *prio, uint8_t response[]);
int tcam_lookup(struct tcam *tcam, const uint8_t key[], uint8_t response[]);
int tcam_delete_all(struct tcam *tcam);
int tcam_delete(struct tcam *tcam, const uint8_t key[], const uint8_t mask[]);
int tcam_read_and_clear_ecc_counters(struct tcam *tcam, uint32_t *corrected_single_bit_errors,
uint32_t *detected_double_bit_errors);
int tcam_read_and_clear_ecc_addresses(struct tcam *tcam, uint32_t *failing_address_single_bit_error,
uint32_t *failing_address_double_bit_error);
int tcam_set_ecc_test(struct tcam *tcam,
bool inject_single_bit_errors,
bool inject_double_bit_errors);
int tcam_destroy(struct tcam *tcam);
#define TCAM_STATS_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP 2
#define TCAM_STATS_SW 4
union tcam_stats {
struct cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup;
struct cam_sw sw;
struct tcam_reserved {
uint8_t resv[512];
} reserved;
};
int tcam_get_stats(struct tcam *tcam, uint64_t stats_group, union tcam_stats *stats);
#ifdef __cplusplus
}
#endif
#endif
#ifndef _aaaaa1aaaaaaaa1aaaH_
#define _aaaaa1aaaaaaaa1aaaH_
#ifndef _CLIENT_T_
#define _CLIENT_T_
typedef struct client_t client_t;
#endif
#define aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaSCOPE 64
struct aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaar16 {
uint16_t start;
uint16_t end;
};
struct aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaap128 {
uint8_t key[aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaMEM_128];
uint8_t len;
};
struct aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaab128 {
uint8_t key[aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaMEM_128];
uint8_t mask[aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaMEM_128];
};
struct aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat64 {
uint8_t key[aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaMEM_128 / 2];
uint8_t mask[aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaMEM_128 / 2];
};
struct aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaac128 {
uint8_t key[aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaMEM_128];
};
union aaaaaaaaaaa1aaa {
struct aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaar16 r16;
struct aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaap128 p128;
struct aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaab128 b128;
struct aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat64 t64;
struct aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaac128 c128;
};
struct aaaaa1aaastats {
uint16_t curr_num_entries;
uint16_t max_num_entries;
uint32_t curr_num_entrysets;
uint32_t max_num_entrysets;
uint16_t curr_num_masks;
uint16_t max_num_masks;
uint16_t curr_closed_masks;
uint16_t max_closed_masks;
uint16_t curr_open_masks;
uint16_t max_open_masks;
uint32_t curr_num_collsets;
uint32_t max_num_collsets;
};
struct set_expansion {
uint16_t num_relaxed_prefixes;
uint16_t num_ternary_permutations;
uint8_t k_combinations;
};
struct tcam {
uint16_t num_entries;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaby_fields;
struct set_expansion set_expansion;
uint16_t num_masks;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsols;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *open_probsol;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaainstance *mask_instances_by_mask;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaop *oparray;
uint8_t max_num_collisions;
uint32_t debug_mask;
client_t *client;
struct aaaaa1aaastats stats;
uint8_t do_refill;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *entries[];
};
int aaaaa1aaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaeate(client_t *client, const struct set_expansion *se,
struct tcam **out_tcam);
int aaaaa1aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(struct tcam *tcam);
void aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaastats(struct tcam *tcam);
#endif
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
void aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint2bit(uint8_t * dst, uint8_t dst_len_bytes, uint16_t dst_aaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabits, const uint8_t * src,
const uint16_t src_len_bits);
void aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaabits(uint8_t * dst, uint8_t dst_len_bytes,
uint16_t dst_aaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabits, uint16_t len_bits);
void aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint64(uint64_t dst[], uint16_t dst_aaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabits, const uint64_t *src, uint16_t src_aaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabits,
uint16_t src_len_bits);
uint16_t cam_get_num_ones(const aaaaaaaaaaaaa1aaat *data);
#ifndef mh_fatal
#define mh_fatal(msg) goto error 
#endif
#ifndef mh_malloc
#define mh_malloc(sz, malloc_function) malloc_function(sz) 
#endif
#ifndef mh_free
#define mh_free(ptr,sz,free_func) free_func(ptr) 
#endif
typedef void (ctor_f)(void *dst, const void *src);
typedef void (dtor_f)(void *elt);
typedef void (init_f)(void *elt);
typedef struct {
size_t sz;
init_f *init;
ctor_f *copy;
dtor_f *dtor;
} m_icd;
typedef struct {
unsigned i, n;
m_icd icd; 
char *d; 
} m_array;
typedef struct mh_handle {
struct mh_table *tbl;
void *prev; 
void *next; 
struct mh_handle *mh_handle_prev; 
struct mh_handle *mh_handle_next; 
void *key; 
unsigned keylen; 
unsigned hashv; 
} mh_handle;
typedef struct mh_bucket {
struct mh_handle *mh_handle_head;
unsigned count;
unsigned expand_mult;
} mh_bucket;
typedef struct mh_table {
mh_bucket *buckets;
unsigned num_buckets, log2_num_buckets;
unsigned num_items;
struct mh_handle *tail; 
ptrdiff_t hho; 
unsigned ideal_chain_maxlen;
unsigned nonideal_items;
unsigned ineff_expands, noexpand;
} mh_table;
#define MH_INITIAL_NUM_BUCKETS 32U 
#define MH_INITIAL_NUM_BUCKETS_LOG2 5U 
#define ELMT_FROM_HH(tbl,hhp) ((void*)(((char*)(hhp)) - ((tbl)->hho)))
#define MH_BKT_CAPACITY_THRESH 10U 
#define oom() goto error
#define MH_TO_BKT( hashv, num_bkts, bkt ) \
do { \
bkt = ((hashv) & ((num_bkts) - 1U)); \
} while(0)
#define MH_EXPAND_BUCKETS(tbl,free_func, malloc_func) \
do { \
unsigned _he_bkt; \
unsigned _he_bkt_i; \
struct mh_handle *_he_thh, *_he_hh_nxt; \
mh_bucket *_he_new_buckets, *_he_newbkt; \
_he_new_buckets = (mh_bucket*)mh_malloc( \
2UL * tbl->num_buckets * sizeof(struct mh_bucket), malloc_func); \
   if (!_he_new_buckets) { mh_fatal( "out of memory"); }                    \
memset(_he_new_buckets, 0, \
2UL * tbl->num_buckets * sizeof(struct mh_bucket)); \
tbl->ideal_chain_maxlen = \
(tbl->num_items >> (tbl->log2_num_buckets+1U)) + \
(((tbl->num_items & ((tbl->num_buckets*2U)-1U)) != 0U) ? 1U : 0U); \
tbl->nonideal_items = 0; \
for(_he_bkt_i = 0; _he_bkt_i < tbl->num_buckets; _he_bkt_i++) \
{ \
_he_thh = tbl->buckets[ _he_bkt_i ].mh_handle_head; \
while (_he_thh != NULL) { \
_he_hh_nxt = _he_thh->mh_handle_next; \
MH_TO_BKT( _he_thh->hashv, tbl->num_buckets*2U, _he_bkt); \
_he_newbkt = &(_he_new_buckets[ _he_bkt ]); \
if (++(_he_newbkt->count) > tbl->ideal_chain_maxlen) { \
tbl->nonideal_items++; \
_he_newbkt->expand_mult = _he_newbkt->count / \
tbl->ideal_chain_maxlen; \
} \
_he_thh->mh_handle_prev = NULL; \
_he_thh->mh_handle_next = _he_newbkt->mh_handle_head; \
if (_he_newbkt->mh_handle_head != NULL) { _he_newbkt->mh_handle_head->mh_handle_prev = \
_he_thh; } \
_he_newbkt->mh_handle_head = _he_thh; \
_he_thh = _he_hh_nxt; \
} \
} \
mh_free(tbl->buckets, tbl->num_buckets*sizeof(struct mh_bucket), free_func); \
tbl->num_buckets *= 2U; \
tbl->log2_num_buckets++; \
tbl->buckets = _he_new_buckets; \
tbl->ineff_expands = (tbl->nonideal_items > (tbl->num_items >> 1)) ? \
(tbl->ineff_expands+1U) : 0U; \
if (tbl->ineff_expands > 1U) { \
tbl->noexpand=1; \
}\
} while(0)
#define MH_MAKE_TABLE(mh_handle,head) \
do { \
(head)->mh_handle.tbl = (mh_table*)mh_malloc( \
sizeof(mh_table), malloc_function); \
 if (!((head)->mh_handle.tbl))  { mh_fatal( "out of memory"); }                    \
memset((head)->mh_handle.tbl, 0, sizeof(mh_table)); \
(head)->mh_handle.tbl->tail = &((head)->mh_handle); \
(head)->mh_handle.tbl->num_buckets = MH_INITIAL_NUM_BUCKETS; \
(head)->mh_handle.tbl->log2_num_buckets = MH_INITIAL_NUM_BUCKETS_LOG2; \
(head)->mh_handle.tbl->hho = (char*)(&(head)->mh_handle) - (char*)(head); \
(head)->mh_handle.tbl->buckets = (mh_bucket*)mh_malloc( \
MH_INITIAL_NUM_BUCKETS*sizeof(struct mh_bucket), malloc_function); \
 if (! (head)->mh_handle.tbl->buckets) { mh_fatal( "out of memory"); }             \
memset((head)->mh_handle.tbl->buckets, 0, \
MH_INITIAL_NUM_BUCKETS*sizeof(struct mh_bucket)); \
} while(0)
#define MH_SORT(head,cmpfcn) MH_SRT(mh_handle,head,cmpfcn)
#define MH_SRT(mh_handle,head,cmpfcn) \
do { \
unsigned _hs_i; \
unsigned _hs_looping,_hs_nmerges,_hs_insize,_hs_psize,_hs_qsize; \
struct mh_handle *_hs_p, *_hs_q, *_hs_e, *_hs_list, *_hs_tail; \
if (head != NULL) { \
_hs_insize = 1; \
_hs_looping = 1; \
_hs_list = &((head)->mh_handle); \
while (_hs_looping != 0U) { \
_hs_p = _hs_list; \
_hs_list = NULL; \
_hs_tail = NULL; \
_hs_nmerges = 0; \
while (_hs_p != NULL) { \
_hs_nmerges++; \
_hs_q = _hs_p; \
_hs_psize = 0; \
for ( _hs_i = 0; _hs_i < _hs_insize; _hs_i++ ) { \
_hs_psize++; \
_hs_q = (mh_handle*)((_hs_q->next != NULL) ? \
((void*)((char*)(_hs_q->next) + \
(head)->mh_handle.tbl->hho)) : NULL); \
if (! (_hs_q) ) { break; } \
} \
_hs_qsize = _hs_insize; \
while ((_hs_psize > 0U) || ((_hs_qsize > 0U) && (_hs_q != NULL))) {\
if (_hs_psize == 0U) { \
_hs_e = _hs_q; \
_hs_q = (mh_handle*)((_hs_q->next != NULL) ? \
((void*)((char*)(_hs_q->next) + \
(head)->mh_handle.tbl->hho)) : NULL); \
_hs_qsize--; \
} else if ( (_hs_qsize == 0U) || (_hs_q == NULL) ) { \
_hs_e = _hs_p; \
if (_hs_p != NULL){ \
_hs_p = (mh_handle*)((_hs_p->next != NULL) ? \
((void*)((char*)(_hs_p->next) + \
(head)->mh_handle.tbl->hho)) : NULL); \
} \
_hs_psize--; \
} else if (( \
cmpfcn(DECLTYPE(head)(ELMT_FROM_HH((head)->mh_handle.tbl,_hs_p)), \
DECLTYPE(head)(ELMT_FROM_HH((head)->mh_handle.tbl,_hs_q))) \
) <= 0) { \
_hs_e = _hs_p; \
if (_hs_p != NULL){ \
_hs_p = (mh_handle*)((_hs_p->next != NULL) ? \
((void*)((char*)(_hs_p->next) + \
(head)->mh_handle.tbl->hho)) : NULL); \
} \
_hs_psize--; \
} else { \
_hs_e = _hs_q; \
_hs_q = (mh_handle*)((_hs_q->next != NULL) ? \
((void*)((char*)(_hs_q->next) + \
(head)->mh_handle.tbl->hho)) : NULL); \
_hs_qsize--; \
} \
if ( _hs_tail != NULL ) { \
_hs_tail->next = ((_hs_e != NULL) ? \
ELMT_FROM_HH((head)->mh_handle.tbl,_hs_e) : NULL); \
} else { \
_hs_list = _hs_e; \
} \
if (_hs_e != NULL) { \
_hs_e->prev = ((_hs_tail != NULL) ? \
ELMT_FROM_HH((head)->mh_handle.tbl,_hs_tail) : NULL); \
} \
_hs_tail = _hs_e; \
} \
_hs_p = _hs_q; \
} \
if (_hs_tail != NULL){ \
_hs_tail->next = NULL; \
} \
if ( _hs_nmerges <= 1U ) { \
_hs_looping=0; \
(head)->mh_handle.tbl->tail = _hs_tail; \
DECLTYPE_ASSIGN(head,ELMT_FROM_HH((head)->mh_handle.tbl, _hs_list)); \
} \
_hs_insize *= 2U; \
} \
} \
} while (0)
#define DECLTYPE(x) (__typeof(x))
#define DECLTYPE_ASSIGN(dst,src) \
do { \
(dst) = DECLTYPE(dst)(src); \
} while(0)
#define MH_DEL_IN_BKT(mh_handle,head,hh_del) \
(head).count--; \
if ((head).mh_handle_head == hh_del) { \
(head).mh_handle_head = hh_del->mh_handle_next; \
} \
if (hh_del->mh_handle_prev) { \
hh_del->mh_handle_prev->mh_handle_next = hh_del->mh_handle_next; \
} \
if (hh_del->mh_handle_next) { \
hh_del->mh_handle_next->mh_handle_prev = hh_del->mh_handle_prev; \
}
#define MH_DELETE(mh_handle,head,delptr,free_func) \
do { \
struct mh_handle *_hd_hh_del; \
if ( ((delptr)->mh_handle.prev == NULL) && ((delptr)->mh_handle.next == NULL) ) { \
mh_free((head)->mh_handle.tbl->buckets, \
(head)->mh_handle.tbl->num_buckets*sizeof(struct mh_bucket), free_func); \
mh_free((head)->mh_handle.tbl, sizeof(mh_table), free_func); \
head = NULL; \
} else { \
unsigned _hd_bkt; \
_hd_hh_del = &((delptr)->mh_handle); \
if ((delptr) == ELMT_FROM_HH((head)->mh_handle.tbl,(head)->mh_handle.tbl->tail)) { \
(head)->mh_handle.tbl->tail = \
(mh_handle*)((ptrdiff_t)((delptr)->mh_handle.prev) + \
(head)->mh_handle.tbl->hho); \
} \
if ((delptr)->mh_handle.prev != NULL) { \
((mh_handle*)((ptrdiff_t)((delptr)->mh_handle.prev) + \
(head)->mh_handle.tbl->hho))->next = (delptr)->mh_handle.next; \
} else { \
DECLTYPE_ASSIGN(head,(delptr)->mh_handle.next); \
} \
if (_hd_hh_del->next != NULL) { \
((mh_handle*)((ptrdiff_t)_hd_hh_del->next + \
(head)->mh_handle.tbl->hho))->prev = \
_hd_hh_del->prev; \
} \
MH_TO_BKT( _hd_hh_del->hashv, (head)->mh_handle.tbl->num_buckets, _hd_bkt); \
MH_DEL_IN_BKT(mh_handle,(head)->mh_handle.tbl->buckets[_hd_bkt], _hd_hh_del); \
(head)->mh_handle.tbl->num_items--; \
} \
} while (0)
#define MH_ITER(mh_handle,head,el,tmp) \
for(((el)=(head)), ((tmp)=DECLTYPE(el)((head!=NULL)?(head)->mh_handle.next:NULL)); \
(el) != NULL; ((el)=(tmp)), ((tmp)=DECLTYPE(el)((tmp!=NULL)?(tmp)->mh_handle.next:NULL)))
#define MH_ADD_TO_BKT(head,addhh,free_func,malloc_func) \
do { \
head.count++; \
(addhh)->mh_handle_next = head.mh_handle_head; \
(addhh)->mh_handle_prev = NULL; \
if (head.mh_handle_head != NULL) { (head).mh_handle_head->mh_handle_prev = (addhh); } \
(head).mh_handle_head=addhh; \
if ((head.count >= ((head.expand_mult+1U) * MH_BKT_CAPACITY_THRESH)) \
&& ((addhh)->tbl->noexpand != 1U)) { \
MH_EXPAND_BUCKETS((addhh)->tbl,free_func, malloc_func); \
} \
} while(0)
#define MH_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaIN_BKT(tbl,mh_handle,head,keyptr,keylen_in,out) \
do { \
if (head.mh_handle_head != NULL) { DECLTYPE_ASSIGN(out,ELMT_FROM_HH(tbl,head.mh_handle_head)); } \
else { out=NULL; } \
while (out != NULL) { \
if ((out)->mh_handle.keylen == (keylen_in)) { \
if ((MH_KEYCMP((out)->mh_handle.key,keyptr,keylen_in)) == 0) { break; } \
} \
if ((out)->mh_handle.mh_handle_next != NULL) { DECLTYPE_ASSIGN(out,ELMT_FROM_HH(tbl,(out)->mh_handle.mh_handle_next)); } \
else { out = NULL; } \
} \
} while(0)
#define MH_KEYCMP(a,b,len) memcmp(a,b,(unsigned long)(len))
#define MH_FIND(mh_handle,head,keyptr,keylen,out) \
do { \
out=NULL; \
if (head != NULL) { \
uint32_t _hf_bkt,_hf_hashv; \
murmur3_bucket(keyptr,keylen, (head)->mh_handle.tbl->num_buckets, &_hf_hashv, &_hf_bkt); \
MH_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaIN_BKT((head)->mh_handle.tbl, mh_handle, (head)->mh_handle.tbl->buckets[ _hf_bkt ], \
keyptr,keylen,out); \
} \
} while (0)
#define MH_ADD(mh_handle,head,fieldname,keylen_in,add,free_func,malloc_func) \
MH_ADD_KEYPTR(mh_handle,head,&((add)->fieldname),keylen_in,add,free_func,malloc_func)
#define MH_ADD_KEYPTR(mh_handle,head,keyptr,keylen_in,add,free_func,malloc_func) \
do { \
uint32_t _ha_bkt; \
(add)->mh_handle.next = NULL; \
(add)->mh_handle.key = (char*)(keyptr); \
(add)->mh_handle.keylen = (unsigned)(keylen_in); \
if (!(head)) { \
head = (add); \
(head)->mh_handle.prev = NULL; \
MH_MAKE_TABLE(mh_handle,head); \
} else { \
(head)->mh_handle.tbl->tail->next = (add); \
(add)->mh_handle.prev = ELMT_FROM_HH((head)->mh_handle.tbl, (head)->mh_handle.tbl->tail); \
(head)->mh_handle.tbl->tail = &((add)->mh_handle); \
} \
(head)->mh_handle.tbl->num_items++; \
(add)->mh_handle.tbl = (head)->mh_handle.tbl; \
murmur3_bucket(keyptr,keylen_in, (head)->mh_handle.tbl->num_buckets, \
(uint32_t *)&((add)->mh_handle.hashv), &_ha_bkt); \
MH_ADD_TO_BKT((head)->mh_handle.tbl->buckets[_ha_bkt],&(add)->mh_handle, free_func, malloc_func); \
} while(0)
#define _SV(elt,list)
#define _NEXT(elt,list,next) ((elt)->next)
#define _NEXTASGN(elt,list,to,next) ((elt)->next)=(to)
#define _CASTASGN(a,b) (a)=(b)
#define LIST_SORT(list, cmp) \
LIST_SORT2(list, cmp, next)
#define LIST_SORT2(list, cmp, next) \
do { \
LDECLTYPE(list) _ls_p; \
LDECLTYPE(list) _ls_q; \
LDECLTYPE(list) _ls_e; \
LDECLTYPE(list) _ls_tail; \
int _ls_insize, _ls_nmerges, _ls_psize, _ls_qsize, _ls_i, _ls_looping; \
if (list) { \
_ls_insize = 1; \
_ls_looping = 1; \
while (_ls_looping) { \
_CASTASGN(_ls_p,list); \
list = NULL; \
_ls_tail = NULL; \
_ls_nmerges = 0; \
while (_ls_p) { \
_ls_nmerges++; \
_ls_q = _ls_p; \
_ls_psize = 0; \
for (_ls_i = 0; _ls_i < _ls_insize; _ls_i++) { \
_ls_psize++; \
_SV(_ls_q,list); _ls_q = _NEXT(_ls_q,list,next); \
if (!_ls_q) break; \
} \
_ls_qsize = _ls_insize; \
while (_ls_psize > 0 || (_ls_qsize > 0 && _ls_q)) { \
if (_ls_psize == 0) { \
_ls_e = _ls_q; _SV(_ls_q,list); _ls_q = \
_NEXT(_ls_q,list,next); _ls_qsize--; \
} else if (_ls_qsize == 0 || !_ls_q) { \
_ls_e = _ls_p; _SV(_ls_p,list); _ls_p = \
_NEXT(_ls_p,list,next); _ls_psize--; \
} else if (cmp(_ls_p,_ls_q) <= 0) { \
_ls_e = _ls_p; _SV(_ls_p,list); _ls_p = \
_NEXT(_ls_p,list,next); _ls_psize--; \
} else { \
_ls_e = _ls_q; _SV(_ls_q,list); _ls_q = \
_NEXT(_ls_q,list,next); _ls_qsize--; \
} \
if (_ls_tail) { \
_SV(_ls_tail,list); _NEXTASGN(_ls_tail,list,_ls_e,next); \
} else { \
_CASTASGN(list,_ls_e); \
} \
_ls_tail = _ls_e; \
} \
_ls_p = _ls_q; \
} \
if (_ls_tail) { \
_SV(_ls_tail,list); _NEXTASGN(_ls_tail,list,NULL,next); \
} \
if (_ls_nmerges <= 1) { \
_ls_looping=0; \
} \
_ls_insize *= 2; \
} \
} \
} while (0)
#define LIST_aaaaaaaaaaaaaaaaaaaaaaaa1aaa(head,el,counter) \
LIST_aaaaaaaaaaaaaaaaaaaaaaaa1aaa2(head,el,counter,next)
#define LIST_aaaaaaaaaaaaaaaaaaaaaaaa1aaa2(head,el,counter,next) \
{ \
counter = 0; \
LIST_FOREACH2(head,el,next){ ++counter; } \
}
#define LIST_PREPEND(head,add) \
LIST_PREPEND2(head,add,next)
#define LIST_PREPEND2(head,add,next) \
do { \
(add)->next = head; \
head = add; \
} while (0)
#define LIST_DELETE(head,del) \
LIST_DELETE2(head,del,next)
#define LIST_DELETE2(head,del,next) \
do { \
LDECLTYPE(head) _tmp; \
if ((head) == (del)) { \
(head)=(head)->next; \
} else { \
_tmp = head; \
while (_tmp->next && (_tmp->next != (del))) { \
_tmp = _tmp->next; \
} \
if (_tmp->next) { \
_tmp->next = ((del)->next); \
} \
} \
} while (0)
#define LIST_PREPEND_ELEM(head, el, add) \
do { \
LDECLTYPE(head) _tmp; \
assert(head != NULL); \
assert(el != NULL); \
assert(add != NULL); \
(add)->next = (el); \
if ((head) == (el)) { \
(head) = (add); \
} else { \
_tmp = head; \
while (_tmp->next && (_tmp->next != (el))) { \
_tmp = _tmp->next; \
} \
if (_tmp->next) { \
_tmp->next = (add); \
} \
} \
} while (0)
#define LIST_FOREACH2(head,el,next) \
for((el)=(head);(el);el=(el)->next)
#define LIST_FOREACH(head,el) \
LIST_FOREACH2(head,el,next)
#define LIST_FOREACH_SAFE(head,el,tmp) \
LIST_FOREACH_SAFE2(head,el,tmp,next)
#define LIST_FOREACH_SAFE2(head,el,tmp,next) \
for((el)=(head);(el) && (tmp = (el)->next, 1); (el) = tmp)
#define LDECLTYPE(x) __typeof(x)
#define LIST_APPEND(head,add) \
LIST_APPEND2(head,add,next)
#define LIST_APPEND2(head,add,next) \
do { \
LDECLTYPE(head) _tmp; \
(add)->next=NULL; \
if (head) { \
_tmp = head; \
while (_tmp->next) { _tmp = _tmp->next; } \
_tmp->next=(add); \
} else { \
(head)=(add); \
} \
} while (0)
#define array_init(a,_icd) do { \
memset(a,0,sizeof(m_array)); \
(a)->icd=*_icd; \
} while(0)
#define array_free(a, free_function) do { \
array_done(a, free_function); \
free_function(a); \
} while(0)
#define array_push_back(a,p,realloc_function) do { \
array_reserve(a,1,realloc_function); \
if ((a)->icd.copy) { (a)->icd.copy( _array_eltptr(a,(a)->i++), p); } \
else { memcpy(_array_eltptr(a,(a)->i++), p, (a)->icd.sz); }; \
} while(0)
#define array_erase(a,pos,len) do { \
if ((a)->icd.dtor) { \
size_t _ut_i; \
for(_ut_i=0; _ut_i < len; _ut_i++) { \
(a)->icd.dtor(array_eltptr((a),pos+_ut_i)); \
} \
} \
if ((a)->i > (pos+len)) { \
memmove( _array_eltptr((a),pos), _array_eltptr((a),pos+len), \
(((a)->i)-(pos+len))*((a)->icd.sz)); \
} \
(a)->i -= (len); \
} while(0)
#define array_done(a, free_function) do { \
if ((a)->n) { \
if ((a)->icd.dtor) { \
size_t _ut_i; \
for(_ut_i=0; _ut_i < (a)->i; _ut_i++) { \
(a)->icd.dtor(array_eltptr(a,_ut_i)); \
} \
} \
free_function((a)->d); \
} \
(a)->n=0; \
} while(0)
#define array_reserve(a,by,realloc_function) do { \
if (((a)->i+(by)) > ((a)->n)) { \
char *array_tmp; \
while(((a)->i+(by)) > ((a)->n)) { (a)->n = ((a)->n ? (2*(a)->n) : 8); } \
array_tmp=(char*)realloc_function((a)->d, (a)->n*(a)->icd.sz); \
if (array_tmp == NULL) oom(); \
(a)->d=array_tmp; \
} \
} while(0)
#define array_eltptr(a,j) (((j) < (a)->i) ? _array_eltptr(a,j) : NULL)
#define _array_eltptr(a,j) ((char*)((a)->d + ((a)->icd.sz*(j) )))
#define array_eltidx(a,e) (((char*)(e) >= (char*)((a)->d)) ? (((char*)(e) - (char*)((a)->d))/(size_t)(a)->icd.sz) : SIZE_MAX)
#define array_front(a) (((a)->i) ? (_array_eltptr(a,0)) : NULL)
#define array_next(a,e) (((e)==NULL) ? array_front(a) : ((((a)->i) > (array_eltidx(a,e)+1)) ? _array_eltptr(a,array_eltidx(a,e)+1) : NULL))
int cam_key2fields(struct tcam *tcam, union aaaaaaaaaaa1aaa fields[], const uint8_t key[]);
void cam_mask_fields(struct tcam *tcam, union aaaaaaaaaaa1aaa fields[]);
int cam_mask2fields(const client_t *client, union aaaaaaaaaaa1aaa fields[], const uint8_t mask[]);
int aaaaaaaaaaa1aaas2key(struct tcam *tcam, const union aaaaaaaaaaa1aaa fields[], uint8_t key[]);
int aaaaaaaaaaa1aaas2mask(struct tcam *tcam, const union aaaaaaaaaaa1aaa fields[], uint8_t mask[]);
int cam_check_fields(struct tcam *tcam, const union aaaaaaaaaaa1aaa fields[]);
#endif 
#ifndef aaaaaaaa1aaaH
#define aaaaaaaa1aaaH
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
#ifndef _SIPHASH_H_
#define _SIPHASH_H_
#ifdef __cplusplus
extern "C" {
#endif
uint64_t siphash(const uint8_t *in, const size_t inlen,
uint64_t k0, uint64_t k1,
uint8_t cROUNDS, uint8_t dROUNDS);
#define SIPaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaV0 (0x736f6d6570736575ULL)
#define SIPaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaV1 (0x646f72616e646f6dULL)
#define SIPaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaV2 (0x6c7967656e657261ULL)
#define SIPaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaV3 (0x7465646279746573ULL)
#ifdef __cplusplus
}
#endif
#endif 
#ifndef INCLUDED_CUE_OPS_H
#define INCLUDED_CUE_OPS_H
int cue_insert(client_t *client, const uint8_t key[], const uint8_t response[]);
int cue_update(client_t *client, const uint8_t key[], const uint8_t response[]);
int cue_delete(client_t *client, const uint8_t key[]);
int cue_get_by_key(client_t *client, const uint8_t key[], uint8_t response[]);
int cue_get_by_entry_index(client_t *client, unsigned index, uint8_t key[], uint8_t response[]);
int cue_clear(client_t *client);
int cue_iterate(client_t *client,
const uint8_t key[], const uint8_t key_mask[],
const uint8_t response[], const uint8_t response_mask[],
uint32_t *pos,
uint8_t out_key[],
uint8_t out_response[]);
struct cue_stats_counters {
unsigned timestamp;
unsigned delete_failed, delete_succeeded;
unsigned update_failed, update_succeeded;
unsigned aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaafailed, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaasucceeded;
};
union cue_stats {
struct cue_stats_counters counters;
struct cue_reserved {
uint8_t resv[512];
} reserved;
};
#define CUE_STATS_aaaaaaaaaaaaaaaaaaaaaaaa1aaaERS (0x2000)
int cue_get_stats(client_t *client, uint64_t stats_group, union cue_stats *stats);
#endif
static void bcam_print_entry(int error_code, const char* function, const struct bcam* bcam, const uint8_t key[],
const uint8_t response[], const cam_options_t *options, const char* match);
int bcam_create(const cam_arg_t* cam_arg, struct bcam** out_bcam)
{
NULL_CHECK(cam_arg);
int rc;
cam_arg_t cam_arg_copy = *cam_arg;
cam_instance_type_t type = BCAM;
if (cam_arg->hbm || cam_arg->ddr_dram)
{
type = DRAMBCAM;
}
if (cam_arg->calc_heap_size) {
cam_config_t *cam_conf_heap = alloca(cam_config_size());
rc = cam_config_init(cam_arg, type, cam_conf_heap);
if (rc) {
if ((cam_arg->debug_flags & CAM_DEBUG_NO_ERROR_MSG) == 0) {
cam_print_error(rc);
}
return rc;
}
const uint32_t client_heap_size = cam_config_calculate_heap_size(
cam_conf_heap);
return client_heap_size;
}
client_t *client;
rc = client_create_bcam(&cam_arg_copy, type, &client);
if (rc) {
if ((cam_arg->debug_flags & CAM_DEBUG_NO_ERROR_MSG) == 0) {
cam_print_error(rc);
}
return rc;
}
if (type == DRAMBCAM) {
if (client_get_hash_function(client) != 0) {
uint64_t v0 = SIPaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaV0 ^ cam_arg->hash_k0;
uint64_t v1 = SIPaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaV1 ^ cam_arg->hash_k1;
uint64_t v2 = SIPaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaV2 ^ cam_arg->hash_k0;
uint64_t v3 = SIPaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaV3 ^ cam_arg->hash_k1;
client_drambcam_hw_write_64(client, aaaaaa1aaaDRAMBCAM_SIPHASH_V0_LO_aaaaaaaaaaaaaaaaaaaaa1aaa, v0);
client_drambcam_hw_write_64(client, aaaaaa1aaaDRAMBCAM_SIPHASH_V1_LO_aaaaaaaaaaaaaaaaaaaaa1aaa, v1);
client_drambcam_hw_write_64(client, aaaaaa1aaaDRAMBCAM_SIPHASH_V2_LO_aaaaaaaaaaaaaaaaaaaaa1aaa, v2);
client_drambcam_hw_write_64(client, aaaaaa1aaaDRAMBCAM_SIPHASH_V3_LO_aaaaaaaaaaaaaaaaaaaaa1aaa, v3);
}
client_drambcam_hw_write_32(client, aaaaaa1aaaDRAMBCAM_STAT_SAMP, aaaaaa1aaaDRAMBCAM_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa10US);
}
*out_bcam = (struct bcam *)client;
   bcam_print_entry(0, "bcam_create", *out_bcam, NULL, NULL, NULL, "");
return 0;
}
#define OPTIONS_SETUP(lastarg) \
NULL_CHECK(bcam);\
cam_options_t *options = (cam_options_t *) alloca(cam_options_size());\
if (client_has_options((client_t *) bcam)) {\
va_list ap;\
va_start(ap, lastarg);\
options = va_arg(ap, cam_options_t *);\
va_end(ap);NULL_CHECK(options);\
} else {\
cam_options_init(options);\
}\
const uint32_t default_debug_flags = client_get_debug_flags((client_t *) bcam);\
if (options->override_debug_flags) {\
client_set_debug_flags((client_t *) bcam, options->debug_flags);\
}
int bcam_update(struct bcam *bcam, const uint8_t key[], const uint8_t response[], ...)
{
OPTIONS_SETUP(response);
NULL_CHECK(key);
NULL_CHECK(response);
if(((client_t *)bcam)->use_cue)
return cue_update((client_t *)bcam, key, response);
aaaaaaaaaaaaa1aaat new_key;
memset(&new_key, 0, sizeof(aaaaaaaaaaaaa1aaat));
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat new_response;
memset(&new_response, 0, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
uint16_t key_width;
uint16_t response_width;
int rc = client_get_widths((client_t *) bcam, &key_width, &response_width,
options->narrow);
if (rc == CAM_OK) {
cam_copy_bits((uint8_t *) &new_key.word[0], key, key_width);
cam_copy_bits((uint8_t *) &new_response.word[0], response,
response_width);
rc = client_update_key((client_t *) bcam, &new_key, &new_response, NULL,
options);
}
   bcam_print_entry(rc, "bcam_update", bcam, key, response, options, "");
if (options->override_debug_flags) 
client_set_debug_flags((client_t *) bcam, default_debug_flags);
return rc;
}
int bcam_insert(struct bcam *bcam, const uint8_t key[], const uint8_t response[], ...)
{
OPTIONS_SETUP(response);
NULL_CHECK(key);
NULL_CHECK(response);
if(((client_t *)bcam)->use_cue)
return cue_insert((client_t *)bcam, key, response);
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat new_response;
aaaaaaaaaaaaa1aaat new_key;
memset(&new_key, 0, sizeof(aaaaaaaaaaaaa1aaat));
memset(&new_response, 0, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
uint16_t key_width;
uint16_t response_width;
int rc = client_get_widths((client_t *) bcam, &key_width, &response_width,
options->narrow);
if (rc == CAM_OK) {
cam_copy_bits((uint8_t *) &new_key.word[0], key, key_width);
cam_copy_bits((uint8_t *) &new_response.word[0], response,
response_width);
rc = client_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa((client_t *) bcam, &new_key, &new_response, NULL,
options);
}
   bcam_print_entry(rc, "bcam_insert", bcam, key, response, options, "");
if (options->override_debug_flags) 
client_set_debug_flags((client_t *) bcam, default_debug_flags);
return rc;
}
static int get_by_key_response_internal(struct bcam *bcam,
const uint8_t key[], const uint8_t key_mask[],
const uint8_t response[], const uint8_t response_mask[],
uint32_t *pos,
uint8_t out_key[], uint8_t out_response[],
const cam_options_t *options)
{
if(((client_t *)bcam)->use_cue)
return cue_iterate((client_t *)bcam,
key, key_mask, response, response_mask,
pos, out_key, out_response);
aaaaaaaaaaaaa1aaat old_key;
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat new_response;
memset(&old_key, 0, sizeof(aaaaaaaaaaaaa1aaat));
memset(&new_response, 0, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
uint16_t key_width;
uint16_t response_width;
int rc = client_get_widths((client_t *) bcam, &key_width, &response_width, options->narrow);
if (rc) {
       bcam_print_entry(rc, "bcam_get_by_response", bcam, NULL, response, options, "");
return rc;
}
cam_copy_bits((uint8_t *) &new_response.word[0], response, response_width);
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat new_response_mask;
memset(&new_response_mask, 0, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
cam_copy_bits((uint8_t *) &new_response_mask.word[0], response_mask,
response_width);
uint8_t num_bytes = key_width / 8;
const uint16_t remaining_bits = key_width - num_bytes * 8;
int match;
do
{
aaaaaaaaaaaaa1aaat old_mask;
rc = client_read_response_for_key((client_t *) bcam, &new_response,
&new_response_mask, pos, &old_key, &old_mask, options->narrow);
if (rc && (rc != CAM_ERROR_FOUND_IN_SHADOW_BUT_NOT_IN_HW)) {
           bcam_print_entry(rc, "bcam_get_by_response", bcam, NULL, response,
                            options, "");
return rc;
}
match = 1;
if (key && key_mask)
{
const uint8_t *found_key = (const uint8_t *)&old_key;
int i;
for (i = 0; i < num_bytes; i++)
if((key[i] ^ found_key[i]) & key_mask[i])
match = 0;
if (remaining_bits > 0)
if((key[num_bytes] ^ found_key[num_bytes]) & key_mask[num_bytes])
match = 0;
}
} while(!match);
if (remaining_bits > 0)
{
out_key[num_bytes] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa8(out_key[num_bytes],
*((uint8_t *) &old_key + num_bytes), 0, remaining_bits);
}
memcpy(out_key, &old_key, num_bytes);
if (out_response != NULL)
{
bcam_get_by_key(bcam, out_key, out_response);
}
   bcam_print_entry(0, "bcam_get_by_response", bcam, out_key, response, options,
           "");
return rc;
}
int bcam_get_by_response(struct bcam *bcam,
const uint8_t response[], const uint8_t response_mask[],
uint32_t *pos,
uint8_t key[], ...)
{
OPTIONS_SETUP(key);
NULL_CHECK(bcam);
NULL_CHECK(response);
NULL_CHECK(response_mask);
NULL_CHECK(pos);
NULL_CHECK(key);
int rv = get_by_key_response_internal(bcam,
NULL, NULL,
response, response_mask,
pos,
key, NULL,
options);
if (options->override_debug_flags) 
client_set_debug_flags((client_t *) bcam, default_debug_flags);
return rv;
}
int bcam_get_by_key_and_response(struct bcam *bcam,
const uint8_t key[], const uint8_t key_mask[],
const uint8_t response[], const uint8_t response_mask[],
uint32_t *pos,
uint8_t out_key[], uint8_t out_response[], ...)
{
OPTIONS_SETUP(out_response);
NULL_CHECK(bcam);
NULL_CHECK(key);
NULL_CHECK(key_mask);
NULL_CHECK(response);
NULL_CHECK(response_mask);
NULL_CHECK(pos);
NULL_CHECK(out_key);
NULL_CHECK(out_response);
int rv = get_by_key_response_internal(bcam,
key, key_mask,
response, response_mask,
pos,
out_key, out_response,
options);
if (options->override_debug_flags) 
client_set_debug_flags((client_t *) bcam, default_debug_flags);
return rv;
}
int bcam_get_by_key(struct bcam *bcam, const uint8_t key[], uint8_t response[], ...)
{
OPTIONS_SETUP(response);
NULL_CHECK(key);
NULL_CHECK(response);
if(((client_t *)bcam)->use_cue)
return cue_get_by_key((client_t *)bcam, key, response);
uint16_t key_width;
uint16_t response_width;
bool using_default_response = false;
uint8_t num_bytes = 0;
uint16_t remaining_bits = 0;
;
int rc = client_get_widths((client_t *) bcam, &key_width, &response_width,
options->narrow);
if (rc) {
       bcam_print_entry(rc, "bcam_get_by_key", bcam, key, NULL, options, "");
goto end;
}
aaaaaaaaaaaaa1aaat new_key;
memset(&new_key, 0, sizeof(aaaaaaaaaaaaa1aaat));
cam_copy_bits((uint8_t *) &new_key.word[0], key, key_width);
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat idx;
rc = client_read_key((client_t *) bcam, &new_key, &idx, NULL, options);
if (rc == CAM_ERROR_KEY_NOT_FOUND) {
client_get_default_response((client_t *) bcam, (uint8_t *) &idx,
options->narrow);
using_default_response = true;
rc = 0;
}
if (rc && (rc != CAM_ERROR_FOUND_IN_SHADOW_BUT_NOT_IN_HW)) {
       bcam_print_entry(rc, "bcam_get_by_key", bcam, key, NULL, options, "");
goto end;
}
num_bytes = response_width / 8;
remaining_bits = response_width - num_bytes * 8;
if (remaining_bits > 0)
{
response[num_bytes] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa8(response[num_bytes],
*((uint8_t *) &idx + num_bytes), 0, remaining_bits);
}
memcpy(response, &idx, num_bytes);
if (using_default_response) {
rc = CAM_ERROR_KEY_NOT_FOUND;
       bcam_print_entry(0, "bcam_get_by_key", bcam, key, response, options, "DEFAULT_MATCH");
} else {
       bcam_print_entry(rc, "bcam_get_by_key", bcam, key, response, options, "KEY_MATCH");
}
end: if (options->override_debug_flags) 
client_set_debug_flags((client_t *) bcam, default_debug_flags);
return rc;
}
int bcam_delete(struct bcam *bcam, const uint8_t key[], ...)
{
OPTIONS_SETUP(key);
NULL_CHECK(bcam);
NULL_CHECK(key);
if(((client_t *)bcam)->use_cue)
return cue_delete((client_t *)bcam, key);
aaaaaaaaaaaaa1aaat new_key;
memset(&new_key, 0, sizeof(aaaaaaaaaaaaa1aaat));
uint16_t key_width;
uint16_t dummy_response_width;
int rc = client_get_widths((client_t *) bcam, &key_width,
&dummy_response_width,
options->narrow);
if (rc == CAM_OK) {
cam_copy_bits((uint8_t *) &new_key.word[0], key, key_width);
rc = client_delete_key((client_t *) bcam, &new_key, NULL, options);
}
   bcam_print_entry(rc, "bcam_delete", bcam, key, NULL, options, "");
if (options->override_debug_flags) 
client_set_debug_flags((client_t *) bcam, default_debug_flags);
return rc;
}
int bcam_delete_all(struct bcam *bcam, ...) {
OPTIONS_SETUP(bcam);
if(((client_t *)bcam)->use_cue)
return cue_clear((client_t *)bcam);
NULL_CHECK(bcam);
int rc = 0;
client_delete_all((client_t *) bcam);
   bcam_print_entry(rc, "bcam_delete_all", bcam, NULL, NULL, options, "");
if (options->override_debug_flags) 
client_set_debug_flags((client_t *) bcam, default_debug_flags);
return rc;
}
int bcam_read_and_clear_ecc_counters(struct bcam *bcam, uint32_t *corrected_single_bit_errors, uint32_t *detected_double_bit_errors)
{
NULL_CHECK(bcam);
NULL_CHECK(corrected_single_bit_errors);
NULL_CHECK(detected_double_bit_errors);
int rc = client_read_and_clear_ecc_counters((client_t *) bcam,
corrected_single_bit_errors, detected_double_bit_errors);
   bcam_print_entry(rc, "bcam_read_and_clear_ecc_counters", bcam, NULL, NULL, NULL, "");
return rc;
}
int bcam_read_and_clear_ecc_addresses(struct bcam *bcam, uint32_t *failing_address_single_bit_error, uint32_t *failing_address_double_bit_error)
{
NULL_CHECK(bcam);
NULL_CHECK(failing_address_single_bit_error);
NULL_CHECK(failing_address_double_bit_error);
int rc = client_read_and_clear_ecc_addresses((client_t *) bcam,
failing_address_single_bit_error,
failing_address_double_bit_error);
   bcam_print_entry(rc, "bcam_read_and_clear_ecc_addresses", bcam, NULL, NULL, NULL, "");
return rc;
}
int bcam_set_ecc_test(struct bcam *bcam, bool inject_single_bit_errors, bool inject_double_bit_errors)
{
NULL_CHECK(bcam);
int rc = client_set_ecc_test((client_t *) bcam, inject_single_bit_errors,
inject_double_bit_errors);
   bcam_print_entry(rc, "bcam_set_ecc_test", bcam, NULL, NULL, NULL, "");
return rc;
}
int bcam_destroy(struct bcam *bcam)
{
NULL_CHECK(bcam);
   bcam_print_entry(0, "bcam_destroy", bcam, NULL, NULL, NULL, "");
client_destroy_bcam((client_t *) bcam);
return 0;
}
int bcam_get_stats(const struct bcam *bcam, uint64_t group, union bcam_stats *stats) {
NULL_CHECK(bcam);
NULL_CHECK(stats);
const uint16_t MSG_SZ = 600;
int rc = 0;
if (group == BCAM_STATS_DRAM_RATE) {
rc = client_read_dram_rate_stats((client_t *) bcam, &stats->dram_rate);
if (rc) {
goto end;
}
} else if (group == BCAM_STATS_DRAM_SNAPSHOT) {
rc = client_read_dram_snapshot_stats((client_t *) bcam, &stats->dram_snapshot);
if (rc) {
goto end;
}
} else if (group == BCAM_STATS_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP) {
rc = client_read_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup_data((client_t *) bcam, &stats->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup);
if (rc) {
goto end;
}
} else if (group == BCAM_STATS_SW) {
client_get_sw_stats((client_t *) bcam, &stats->sw);
} else {
rc = CAM_ERROR_INVALID_ARG;
goto end;
}
if (client_get_debug_flags((client_t *) bcam) & CAM_DEBUG_STATS) {
char message[MSG_SZ];
if (group == BCAM_STATS_DRAM_RATE) {
           snprintf(message, sizeof(message), "reads = %" PRIu32, stats->dram_rate.reads);
client_print_info((client_t *) bcam, message);
           snprintf(message, sizeof(message), "writes = %" PRIu32, stats->dram_rate.writes);
client_print_info((client_t *) bcam, message);
           snprintf(message, sizeof(message), "axis_ws = %" PRIu32, stats->dram_rate.axis_ws);
client_print_info((client_t *) bcam, message);
} else if (group == BCAM_STATS_DRAM_SNAPSHOT) {
           snprintf(message, sizeof(message), "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaalatency = %" PRIu32, stats->dram_snapshot.aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaalatency);
client_print_info((client_t *) bcam, message);
           snprintf(message, sizeof(message), "outstanding_reads = %" PRIu32, stats->dram_snapshot.outstanding_reads);
client_print_info((client_t *) bcam, message);
} else if (group == BCAM_STATS_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP) {
char *key_str;
char *response_str;
const cam_malloc_func malloc_function = client_get_malloc_function((client_t*) bcam);
const cam_free_func free_function = client_get_free_function((client_t *) bcam);
const uint16_t key_width = client_get_key_width((client_t *) bcam);
const uint16_t response_width = client_get_response_width((client_t *) bcam);
key_str = byte_arr_to_str(key_width, stats->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup.key, malloc_function);
response_str = byte_arr_to_str(response_width, stats->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup.response, malloc_function);
           snprintf(message, sizeof(message), "last key = %s", key_str);
client_print_info((client_t *) bcam, message);
           snprintf(message, sizeof(message), "last response = %s", response_str);
client_print_info((client_t *) bcam, message);
           snprintf(message, sizeof(message), "last status = %" PRIu32, stats->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup.status);
client_print_info((client_t *) bcam, message);
free_function(key_str);
free_function(response_str);
} else if (group == BCAM_STATS_SW) {
snprintf(message, sizeof(message),
               "CAM_DEBUG_STATS  inserts = %" PRIu64 " (%0"PRIu32" fail)   collisions = %" PRIu64 "/%0"PRIu16" (total/max)",
stats->sw.num_inserts, stats->sw.failed_inserts, stats->sw.num_collisions,
stats->sw.max_collisions);
client_print_info((client_t *) bcam, message);
           snprintf(message, sizeof(message), "CAM_DEBUG_STATS  updates = %" PRIu64 " (%0"PRIu32" fail)",
stats->sw.num_updates, stats->sw.failed_updates);
client_print_info((client_t *) bcam, message);
           snprintf(message, sizeof(message), "CAM_DEBUG_STATS  deletes = %" PRIu64 " (%0"PRIu32" fail)",
stats->sw.num_deletes, stats->sw.failed_deletes);
client_print_info((client_t *) bcam, message);
           snprintf(message, sizeof(message), "CAM_DEBUG_STATS  shadow writes = %" PRIu64 "",
stats->sw.num_shadow_writes);
client_print_info((client_t *) bcam, message);
}
}
   end: bcam_print_entry(rc, "bcam_get_stats", bcam, NULL, NULL, NULL, "");
return rc;
}
static void bcam_print_entry(int error_code, const char *function, const struct bcam *bcam, const uint8_t key[],
const uint8_t response[], const cam_options_t *options, const char *match)
{
if (error_code && (client_get_debug_flags((client_t *) bcam) & CAM_DEBUG_NO_ERROR_MSG))
return;
if (!error_code && !(client_get_debug_flags((client_t *) bcam) & CAM_DEBUG_ARGS))
return;
uint16_t key_width = client_get_key_width((client_t *) bcam);
uint16_t response_width = client_get_response_width((client_t *) bcam);
cam_malloc_func malloc_function = client_get_malloc_function(
(client_t*) bcam);
int rc;
if (options != NULL) {
rc = client_get_widths((client_t *) bcam, &key_width, &response_width,
options->narrow);
assert(rc == 0);
}
const uint16_t MSG_SZ = 600;
char message[MSG_SZ];
char *key_str;
if (key != NULL)
{
key_str = byte_arr_to_str(key_width, key, malloc_function);
}
else
{
       key_str = (char *) "N/A";
}
char *response_str;
if (response != NULL)
{
response_str = byte_arr_to_str(response_width, response, malloc_function);
}
else
{
       response_str = (char *) "N/A";
}
   const char *narrow_str = "                ";
if ((options != NULL) && (options->narrow)) {
       narrow_str = "Options = Narrow";
}
const uint16_t HASH_SZ = 32;
char hash_str[HASH_SZ];
if ((options != NULL) && (options->precomp_hash == true)) {
       snprintf(hash_str, HASH_SZ, "hv = 0x%016" PRIX64, options->hash_value);
}
else
       snprintf(hash_str, HASH_SZ, "               ");
if (!error_code
&& (client_get_debug_flags((client_t *) bcam) & CAM_DEBUG_ARGS))
{
       snprintf(message, MSG_SZ, "%-20s  handle = %p  key = %s  response = %s %s %s %8s", function, (void *) bcam,
key_str,
response_str, narrow_str, hash_str, match);
client_print_info((client_t *) bcam, message);
}
if (error_code)
{
sprintf(message,
               "%-20s  handle = %p  key = %s  response = %s %s %s  %s\n\n%10s%-20s  num_entries = %0"PRIu32"  (%0"PRIu32" used)",
function, (void *) bcam,
key_str,
response_str, narrow_str, hash_str,
cam_error_string(error_code),
               " ",
               "bcam resources",
client_get_num_entries((client_t *) bcam),
client_get_current_num_entries((client_t *) bcam));
client_print_error((client_t *) bcam, message);
}
if (response != NULL)
{
cam_free_func free_function = client_get_free_function(
(client_t *) bcam);
free_function(response_str);
}
if (key != NULL)
{
cam_free_func free_function = client_get_free_function(
(client_t *) bcam);
free_function(key_str);
}
}
#ifndef _HCAM_DEVICE_H
#define _HCAM_DEVICE_H
int hcam_device_open(char *file_name);
int hcam_device_close(void);
void hcam_device_write(void *ctx, uint32_t address, uint32_t data);
void hcam_device_read(void *ctx, uint32_t address, uint32_t *data);
#endif
#ifndef HASH_H
#define HASH_H
typedef struct hash_t hash_t;
size_t hash_size(void);
void aaaaaaa1aaa(hash_t *hash, const aaaaaaaaaaaaa1aaat *key, const aaa1aaat *phm);
void hash_raw_init(hash_t *hash, const aaaaaaaaaaaaa1aaat *key, uint16_t seed, uint16_t key_width, uint32_t num_lists,
uint8_t num_slots);
uint64_t hash_calculate(hash_t *hash, unsigned width);
uint32_t hash_calculate_bucket(hash_t *hash);
uint32_t hash_calculate_list(hash_t *hash, uint8_t function);
void camlib_hashmsr_init(hash_t *hash, aaaaaaaaaaaaa1aaat *key, uint16_t seed, uint16_t key_width, uint32_t num_lists, uint8_t num_slots);
#endif
#ifndef INCLUDED_CUE_aaaaaaaaaaaaaaaaaaaaa1aaaS_H
#define INCLUDED_CUE_aaaaaaaaaaaaaaaaaaaaa1aaaS_H
#define CUE_ADDRESS_aaaaaaaaaaaaaaaaaaaaa1aaa (0x80) 
#define CUE_COMMAND_aaaaaaaaaaaaaaaaaaaaa1aaa (0x84)
#define CUE_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x98)
#define CUE_FILL_aaaaaaaaaaaaaaaaaaaaa1aaa (0x9c)
#define CUE_KEY_aaaaaaaaaaaaaaaaaaaaa1aaa (0x00)
#define CUE_RESPONSE_aaaaaaaaaaaaaaaaaaaaa1aaa (0x100)
#define CUE_MODE_aaaaaaaaaaaaaaaaaaaaa1aaa (0x1cc)
#define CUE_STATS_DELETE_FAILED_aaaaaaaaaaaaaaaaaaaaa1aaa (0x220)
#define CUE_STATS_DELETE_SUCCEEDED_aaaaaaaaaaaaaaaaaaaaa1aaa (0x224)
#define CUE_STATS_UPDATE_FAILED_aaaaaaaaaaaaaaaaaaaaa1aaa (0x228)
#define CUE_STATS_UPDATE_SUCCEEDED_aaaaaaaaaaaaaaaaaaaaa1aaa (0x22c)
#define CUE_STATS_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaFAILED_aaaaaaaaaaaaaaaaaaaaa1aaa (0x230)
#define CUE_STATS_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaSUCCEEDED_aaaaaaaaaaaaaaaaaaaaa1aaa (0x234)
enum cue_command {
CUE_COMMAND_INSERT = 0,
CUE_COMMAND_UPDATE = 1,
CUE_COMMAND_DELETE = 2,
CUE_COMMAND_GET_BY_KEY = 3,
CUE_COMMAND_GET_BY_INDEX= 4,
CUE_COMMAND_CLEAR = 5
};
enum cue_status {
CUE_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaLE = 0,
CUE_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaDUPLICATE = 1,
CUE_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaFULL = 2,
CUE_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaSUCCESS = 3,
CUE_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaNOT_FOUND = 4,
CUE_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaBUS_ERROR = 5,
CUE_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaBUSY = 6,
CUE_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaTIMEOUT = ~0 
};
#endif
static void client_drambcam_hw_read(const client_t *client, uint32_t address, uint32_t *data32)
{
cam_hw_read(client->conf, address, data32);
}
void client_drambcam_hw_write_64(const client_t *client, uint32_t address, uint64_t data64)
{
cam_hw_write(client->conf, address, data64 & 0xffffffff);
cam_hw_write(client->conf, address + 4, (data64 >> 32) & 0xffffffff);
}
void client_drambcam_hw_write_32(const client_t *client, uint32_t address, uint32_t data32) {
cam_hw_write(client->conf, address, data32);
}
#define aaaaaa1aaaDRAMBCAM_PARAM_KW_aaaaaaaaaaaaaaaaaaaaa1aaa 0x184
#define aaaaaa1aaaDRAMBCAM_PARAM_RW_aaaaaaaaaaaaaaaaaaaaa1aaa 0x188
#define aaaaaa1aaaDRAMBCAM_PARAM_NUM_PCS_aaaaaaaaaaaaaaaaaaaaa1aaa 0x190
#define aaaaaa1aaaDRAMBCAM_PARAM_VERSION_aaaaaaaaaaaaaaaaaaaaa1aaa 0x18c
#define aaaaaa1aaaDRAMBCAM_PARAM_FW_aaaaaaaaaaaaaaaaaaaaa1aaa 0x1b4
#define aaaaaa1aaaDRAMBCAM_PARAM_HASH_C_aaaaaaaaaaaaaaaaaaaaa1aaa 0x1b8
#define aaaaaa1aaaDRAMBCAM_PARAM_HASH_D_aaaaaaaaaaaaaaaaaaaaa1aaa 0x1bc
static int verify_drambcam_config(const client_t *client)
{
uint32_t data = 0;
bool err;
char sub_str[512];
char message[1024];
int rc = CAM_OK;
client_drambcam_hw_read(client, aaaaaa1aaaDRAMBCAM_PARAM_KW_aaaaaaaaaaaaaaaaaaaaa1aaa, &data);
err = client->conf->key_width != data;
if (err) {
rc = CAM_ERROR_CONFIGURATION;
       sprintf(message, "%-26sVerification of hardware/software parameters is enabled by default, and requires a hardware read function.", cam_error_string(rc));
client_print_error(client, message);
       sprintf(message, "%-26sUse 'cam_arg_set_hw_read_function' to specify the hardware read function.", cam_error_string(rc));
client_print_error(client, message);
       sprintf(message, "%-26sUse the debug switch 'CAM_DEBUG_SKIP_VERIFY_CONFIG' to disable verification of hardware/software parameters", cam_error_string(rc));
client_print_error(client, message);
}
if (err || (client_get_debug_flags(client) & CAM_DEBUG_VERBOSE_VERIFY)) {
if (err) {
rc = CAM_ERROR_CONFIGURATION;
}
       sprintf(sub_str, "KEY_WIDTH      = %"PRIu32" (expected %"PRIu16")",
data, client->conf->key_width);
       sprintf(message, "%-26s%-70s%s",
               err ? cam_error_string(rc) : "CAM_DEBUG_VERBOSE_VERIFY",
               sub_str, err ? "FAIL" : "OK");
if (err) {
client_print_error(client, message);
} else {
client_print_info(client, message);
}
}
client_drambcam_hw_read(client, aaaaaa1aaaDRAMBCAM_PARAM_RW_aaaaaaaaaaaaaaaaaaaaa1aaa, &data);
err = client->conf->arg.response_width != data;
if (err || (client_get_debug_flags(client) & CAM_DEBUG_VERBOSE_VERIFY)) {
if (err) {
rc = CAM_ERROR_CONFIGURATION;
}
       sprintf(sub_str, "RESPONSE_WIDTH = %"PRIu32" (expected %"PRIu16")",
data, client->conf->arg.response_width);
       sprintf(message, "%-26s%-70s%s",
               err ? cam_error_string(rc) : "CAM_DEBUG_VERBOSE_VERIFY",
               sub_str, err ? "FAIL" : "OK");
if (err) {
client_print_error(client, message);
} else {
client_print_info(client, message);
}
}
client_drambcam_hw_read(client, aaaaaa1aaaDRAMBCAM_PARAM_FW_aaaaaaaaaaaaaaaaaaaaa1aaa, &data);
err = client->conf->arg.fingerprint_width != data;
if (err || (client_get_debug_flags(client) & CAM_DEBUG_VERBOSE_VERIFY)) {
if (err) {
rc = CAM_ERROR_CONFIGURATION;
}
       sprintf(sub_str, "FINGERPRINT_WIDTH = %"PRIu32" (expected %"PRIu16")",
data, client->conf->arg.fingerprint_width);
       sprintf(message, "%-26s%-70s%s",
               err ? cam_error_string(rc) : "CAM_DEBUG_VERBOSE_VERIFY",
               sub_str, err ? "FAIL" : "OK");
if (err) {
client_print_error(client, message);
} else {
client_print_info(client, message);
}
}
const uint8_t cROUNDS = client->conf->arg.hash_function >> 4;
const uint8_t dROUNDS = client->conf->arg.hash_function & 0xf;
uint32_t hw_c, hw_d;
client_drambcam_hw_read(client, aaaaaa1aaaDRAMBCAM_PARAM_HASH_C_aaaaaaaaaaaaaaaaaaaaa1aaa, &hw_c);
err = cROUNDS != hw_c;
client_drambcam_hw_read(client, aaaaaa1aaaDRAMBCAM_PARAM_HASH_D_aaaaaaaaaaaaaaaaaaaaa1aaa, &hw_d);
err |= dROUNDS != hw_d;
if (err || (client_get_debug_flags(client) & CAM_DEBUG_VERBOSE_VERIFY)) {
if (err) {
rc = CAM_ERROR_CONFIGURATION;
}
       sprintf(sub_str, "HASH C/D       = %"PRIu32"/%"PRIu32" (expected %"PRIu8"/%"PRIu8")",
hw_c, hw_d, cROUNDS, dROUNDS);
       sprintf(message, "%-26s%-70s%s",
               err ? cam_error_string(rc) : "CAM_DEBUG_VERBOSE_VERIFY",
               sub_str, err ? "FAIL" : "OK");
if (err) {
client_print_error(client, message);
} else {
client_print_info(client, message);
}
}
client_drambcam_hw_read(client, aaaaaa1aaaDRAMBCAM_PARAM_VERSION_aaaaaaaaaaaaaaaaaaaaa1aaa, &data);
const uint8_t major = (data & 0xff00) >> 8;
const uint8_t medium = (data & 0x00f0) >> 4;
const uint8_t minor = data & 0xf;
const uint8_t expected_major = CAM_DRAMBCAM_HW_VERSION_MAJOR;
const uint8_t expected_medium = CAM_DRAMBCAM_HW_VERSION_MEDIUM;
err = (major != expected_major) || (medium != expected_medium);
if (err || (client_get_debug_flags(client) & CAM_DEBUG_VERBOSE_VERIFY)) {
if (err) {
rc = CAM_ERROR_CONFIGURATION;
}
       sprintf(sub_str, "HW version     = %d.%d%d (expected %d.%d to %d.%d)",
major, medium, minor,
expected_major, expected_medium * 10,
expected_major, expected_medium * 10 + 9);
       sprintf(message, "%-26s%-70s%s",
               err ? cam_error_string(rc) : "CAM_DEBUG_VERBOSE_VERIFY",
               sub_str, err ? "FAIL" : "OK");
if (err) {
client_print_error(client, message);
} else {
client_print_info(client, message);
}
}
if (client_get_debug_flags(client) & CAM_DEBUG_CONFIG) {
       sprintf(message, "HW Version %d.%d%d", major, medium, minor);
client_print_info(client, message);
}
return rc;
}
int client_create_bcam(const cam_arg_t *cam_conf_arg, cam_instance_type_t cam_instance_type, client_t **client)
{
assert(cam_instance_type != TCAM);
client_t *new_client = cam_conf_arg->malloc_function(sizeof(client_t));
if (new_client == NULL) {
return CAM_ERROR_MALLOC_FAILED;
}
cam_config_t *cam_conf;
int rc = cam_config_create(cam_conf_arg, cam_instance_type, &cam_conf);
if (rc) {
cam_conf_arg->free_function(new_client);
return rc;
}
new_client->conf = cam_conf;
if ((new_client->conf->instance_type != DRAMBCAM)) {
new_client->prev_hi_addr_unknown = true;
new_client->prev_hi_data_unknown = true;
new_client->prev_hi_addr = 0;
new_client->prev_hi_data = 0;
new_client->use_cue = 0;
} else {
uint32_t data = 0;
char message[500];
client_drambcam_hw_read(new_client, CUE_MODE_aaaaaaaaaaaaaaaaaaaaa1aaa, &data);
new_client->use_cue = (data != 0);
if (cam_conf->arg.debug_flags & CAM_DEBUG_CONFIG) {
           snprintf(message, sizeof message, "CUE: %sabled", new_client->use_cue ? "en" : "dis");
client_print_info(new_client, message);
}
}
if (cam_conf->arg.debug_flags & CAM_DEBUG_VERIFY_CONFIG) {
char message[500];
       sprintf(message, "The debug switch 'CAM_DEBUG_VERIFY_CONFIG' is deprecated.");
client_print_info(new_client, message);
       sprintf(message, "Verification of hardware/software parameters is enabled by default.");
client_print_info(new_client, message);
       sprintf(message, "Use the debug switch 'CAM_DEBUG_SKIP_VERIFY_CONFIG' to disable verification of hardware/software parameters");
client_print_info(new_client, message);
}
if (!(cam_conf->arg.debug_flags & CAM_DEBUG_SKIP_VERIFY_CONFIG)) {
if (cam_instance_type == DRAMBCAM) {
rc = verify_drambcam_config(new_client);
} else {
rc = verify_config(new_client);
}
if (rc) {
return rc;
}
}
if(!new_client->use_cue) {
new_client->htable = cam_conf_arg->malloc_function(htable_size());
if (new_client->htable == NULL) {
rc = CAM_ERROR_MALLOC_FAILED;
goto out_free_conf;
}
const uint32_t num_entries = cam_config_get_num_entries(cam_conf);
if (!htable_init(new_client->htable, num_entries, cam_conf_arg->calloc_function)) {
rc = CAM_ERROR_MALLOC_FAILED;
goto out_free_htable;
}
}
new_client->num_entries = 0;
new_client->narrow_num_entries = 0;
new_client->num_overwrites = 0;
new_client->zero_unused = false;
const uint16_t num_units = cam_config_get_num_units(new_client->conf);
const uint16_t num_slots = cam_config_get_num_slots(new_client->conf);
cam_free_func free_function = client_get_free_function(new_client);
if(!new_client->use_cue) {
new_client->test_km = NULL;
new_client->overwrites =
(cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat *) new_client->conf->arg.calloc_function(
CLIENT_MAX_OVERWRITES, sizeof(cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat));
if (new_client->overwrites == NULL) {
rc = CAM_ERROR_MALLOC_FAILED;
goto out_free_htable;
}
for (uint16_t i = 0; i < num_units; i++) {
new_client->unit[i].phm = new_client->conf->arg.malloc_function(aaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa());
if (new_client->unit[i].phm == NULL) {
for (uint16_t j = 0; j < i; j++) {
aaa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabcam(new_client->unit[j].phm, free_function);
}
aaaa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(new_client->test_km, free_function);
rc = CAM_ERROR_MALLOC_FAILED;
goto out_free_htable;
}
}
assert(num_units <= aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaS);
for (uint16_t i = 0; i < num_units; i++) {
const uint16_t physical_unit = i / num_slots;
const uint8_t slot_number = i - physical_unit * num_slots;
if (false
== aaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabcam(new_client->unit[i].phm, new_client, physical_unit, slot_number)) {
for (uint16_t j = 0; j < i; j++) {
aaa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabcam(new_client->unit[j].phm, free_function);
}
aaaa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(new_client->test_km, free_function);
rc = CAM_ERROR_MALLOC_FAILED;
goto out_free_htable;
}
new_client->unit[i].unit_mode = UNUSED;
}
}
new_client->num_inserts = 0;
new_client->num_updates = 0;
new_client->num_deletes = 0;
new_client->failed_inserts = 0;
new_client->failed_updates = 0;
new_client->failed_deletes = 0;
new_client->num_collisions = 0;
new_client->max_collisions = 0;
new_client->num_used_masks = 0;
new_client->num_shadow_writes = 0;
if(new_client->use_cue) {
if (!(cam_conf->arg.debug_flags & CAM_DEBUG_SKIP_MEM_INIT)) {
rc = cue_clear(new_client);
if(rc) goto out_free_conf;
}
} else {
uint32_t cnt1, cnt2;
if ((cam_conf_arg->segment_ctx.segment == -1) && (cam_instance_type != DRAMBCAM))
client_read_and_clear_ecc_counters(new_client, &cnt1, &cnt2);
}
*client = new_client;
return 0;
out_free_htable:
htable_free(new_client->htable, cam_conf_arg->free_function);
out_free_conf:
cam_conf_arg->free_function(new_client->conf);
cam_conf_arg->free_function(new_client);
return rc;
}
uint8_t client_get_num_masks(const client_t *client)
{
assert(client != NULL);
return cam_config_get_num_masks(client->conf);
}
bool client_has_options(const client_t *client)
{
return client->conf->arg.options;
}
static bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen_dec(const client_t *client, uint16_t *start_value)
{
assert(client != NULL);
assert(*start_value < client_get_num_units(client));
for (int32_t i = *start_value; i >= 0; i--) {
if ((client->unit[i].unit_mode == OPEN)) {
*start_value = i;
return true;
}
}
return false;
}
static bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen_with_equal_mask_dec(const client_t *client, uint16_t *start_value, const aaaaaaaaaaaaa1aaat *mask,
uint8_t range_valid, uint8_t mask_id)
{
assert(*start_value < client_get_num_units(client));
while (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen_dec(client, start_value)) {
assert((*start_value) < client_get_num_units(client));
const aaa1aaat *phm = client->unit[*start_value].phm;
assert(aaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaavalid(phm));
if (aaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaequal(phm, mask, range_valid, mask_id)) {
return true;
}
if (*start_value == 0)
return false;
(*start_value)--;
}
return false;
}
void client_inc_shadow_writes(client_t *client) {
client->num_shadow_writes++;
}
void client_destroy_bcam(client_t *client)
{
if (client == NULL) {
return;
}
assert(client->conf != NULL);
cam_free_func free_function = client_get_free_function(client);
if ((client_get_debug_flags(client) & CAM_DEBUG_STATS) && (client->conf->instance_type != TCAM)) {
char message[100];
snprintf(message, sizeof(message),
               "CAM_DEBUG_STATS  inserts = %" PRIu64 " (%0"PRIu32" fail)   collisions = %" PRIu64 "/%0"PRIu16" (total/max)",
client->num_inserts, client->failed_inserts,
client->num_collisions, client->max_collisions);
client_print_info(client, message);
       snprintf(message, sizeof(message), "CAM_DEBUG_STATS  updates = %" PRIu64 " (%0"PRIu32" fail)",
client->num_updates, client->failed_updates);
client_print_info(client, message);
       snprintf(message, sizeof(message), "CAM_DEBUG_STATS  deletes = %" PRIu64 " (%0"PRIu32" fail)",
client->num_deletes, client->failed_deletes);
client_print_info(client, message);
       snprintf(message, sizeof(message), "CAM_DEBUG_STATS  shadow writes = %" PRIu64 "", client->num_shadow_writes);
client_print_info(client, message);
}
if(!client->use_cue) {
const uint16_t num_units = cam_config_get_num_units(client->conf);
for (uint16_t i = 0; i < num_units; i++) {
aaa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabcam(client->unit[i].phm, free_function);
}
htable_free(client->htable, free_function);
if (client->test_km != NULL) {
aaaa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(client->test_km, free_function);
}
if (client->overwrites != NULL) {
free_function(client->overwrites);
}
}
cam_config_destroy(client->conf);
free_function(client);
}
uint8_t client_get_fingerprint_width(const client_t *client)
{
return cam_config_get_fingerprint_width(client->conf);
}
static int check_masked_key_bits(const aaaaaaaaaaaaa1aaat *mask, const aaaaaaaaaaaaa1aaat *key, uint16_t key_size)
{
const uint16_t number_of_words = key_size / 32;
for (uint8_t i = 0; i < number_of_words; i++) {
if ((mask->word[i] & key->word[i]) != key->word[i]) {
return CAM_ERROR_MASKED_KEY_BIT_IS_SET;
}
}
const uint8_t remaining_bits = key_size - number_of_words * 32;
if (remaining_bits > 0) {
const uint32_t remaining_key_bits = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(key->word[number_of_words], 0, remaining_bits);
const uint32_t remaining_mask_bits = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(mask->word[number_of_words], 0, remaining_bits);
if ((remaining_mask_bits & remaining_key_bits) != remaining_key_bits) {
return CAM_ERROR_MASKED_KEY_BIT_IS_SET;
}
}
return 0;
}
static uint64_t hash_key(const client_t *client,
const aaaaaaaaaaaaa1aaat *key,
bool narrow)
{
uint16_t kw = client->conf->arg.key_width;
if (narrow)
kw = client->conf->arg.narrow_key_width;
const uint16_t num_bytes = (kw + 7) / 8;
if (client->conf->arg.hash_function == 0) {
uint32_t hash_value32;
murmur3((const void *) key, num_bytes, 3, &hash_value32);
return hash_value32;
} else {
const uint8_t cROUNDS = client->conf->arg.hash_function >> 4;
const uint8_t dROUNDS = client->conf->arg.hash_function & 0xf;
return siphash((const uint8_t *) key, num_bytes,
client->conf->arg.hash_k0, client->conf->arg.hash_k1,
cROUNDS, dROUNDS);
}
}
static uint8_t cache_hit(const client_t *client, const aaaaaaaaaaaaa1aaat *key, bool *unit_valid,
uint16_t *unit, const cam_options_t *options, uint64_t *hash_value)
{
if (options->precomp_hash) {
*hash_value = options->hash_value;
} else {
*hash_value = hash_key(client, key, options->narrow);
}
uint8_t counter;
uint16_t value;
bool value_unknown;
htable_read(client->htable, *hash_value, &counter, &value, &value_unknown);
if (counter == 0)
return 0;
if (value_unknown)
*unit_valid = false;
else {
*unit_valid = true;
*unit = value;
}
return counter;
}
static bool db_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaa1aaat *mask, aaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaat execute,
bool match_response, aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response, uint8_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, bool unit_valid, uint16_t *unit,
uint64_t hash_value, bool narrow,
int *verify)
{
assert(client != NULL);
assert(
((execute != aaa1aaaREAD) && (verify == NULL)) || (execute == aaa1aaaREAD));
uint16_t open_unit = 0;
if (unit_valid)
open_unit = *unit;
const uint16_t num_units = client_get_num_units(client);
uint16_t loop = num_units;
const bool is_drambcam_or_bcam = (client->conf->instance_type == DRAMBCAM) || (client->conf->instance_type == BCAM);
while (loop) {
if (client->unit[open_unit].unit_mode == OPEN) {
aaa1aaat *phm = client->unit[open_unit].phm;
assert(aaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaavalid(phm));
bool mask_equal = true;
if (!(is_drambcam_or_bcam)) {
assert(mask!=NULL);
mask_equal = aaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaequal(phm, mask, 0, 0);
}
if (mask_equal) {
const bool status = aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(phm, key, execute, match_response, response, hash_value,
narrow,
verify);
if (status == true) {
*unit = open_unit;
return true;
}
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa == 1 && unit_valid)
return false;
}
}
if (open_unit == (num_units - 1))
open_unit = 0;
else
open_unit++;
loop--;
}
return false;
}
void client_delete_all(client_t *client) {
assert(client != NULL);
const uint32_t num_entries = client->num_entries;
uint32_t tot_deleted_keys = 0;
client->num_entries = 0;
client->narrow_num_entries = 0;
client->num_used_masks = 0;
const uint16_t num_units = client_get_num_units(client);
for (uint16_t i = 0; i < num_units; i++) {
if (client->unit[i].unit_mode == OPEN) {
aaa1aaat *phm = client->unit[i].phm;
uint32_t deleted_keys;
aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaall(phm, &deleted_keys);
tot_deleted_keys = tot_deleted_keys + deleted_keys;
if (client->conf->instance_type == STCAM)
aaa1bbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6aaa(phm);
set_unused(client, i);
}
}
client->num_deletes = client->num_deletes + tot_deleted_keys;
assert(num_entries == tot_deleted_keys);
assert(client->htable);
htable_clear(client->htable);
}
#define BITS(N) (32 - __builtin_clz((uint32_t) (N)))
static bool is_mask_under_filled(uint16_t num_units, uint32_t num_entries, uint32_t num_lists) {
if (num_units)
num_units--; 
if (num_units == 0)
return false;
uint32_t max_num_entries = num_lists * num_units;
if (num_units < 2) {
max_num_entries = 1 << (BITS(max_num_entries) - 1) / 2;
} else if (num_units == 2) {
max_num_entries = (uint32_t) (max_num_entries * aaaaaa1aaa2W_aaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa);
} else if (num_units == 3) {
max_num_entries = (uint32_t) (max_num_entries * aaaaaa1aaa3W_aaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa);
} else {
max_num_entries = (uint32_t) (max_num_entries * aaaaaa1aaaBCAM_FILL_RATIO);
}
if (num_entries <= max_num_entries)
return true;
return false;
}
static int aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaamulti_mask_key(client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response,
const aaaaaaaaaaaaa1aaat *mask, uint64_t hash_value);
int client_delete_key(client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaa1aaat *mask, const cam_options_t *options)
{
client->num_deletes++;
if (mask != NULL) {
const uint16_t key_width = cam_config_get_key_width(client->conf);
int status = check_masked_key_bits(mask, key, key_width);
if (status != 0) {
client->failed_deletes++;
return status;
}
}
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat del_prio;
uint16_t unit;
uint64_t hash_value;
bool unit_valid;
const uint8_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = cache_hit(client, key, &unit_valid, &unit, options, &hash_value);
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa == 0) {
client->failed_deletes++;
return CAM_ERROR_KEY_NOT_FOUND;
}
bool success = db_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(client, key, mask, aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaa, false, &del_prio, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, unit_valid,
&unit,
hash_value,
options->narrow, NULL);
if (!success) {
client->failed_deletes++;
return CAM_ERROR_KEY_NOT_FOUND;
}
htable_dec(client->htable, hash_value, unit);
client->num_entries--;
if (options->narrow) {
assert(client->narrow_num_entries > 0);
client->narrow_num_entries--;
}
if (mask != NULL) {
aaa1aaat *phm = client_get_phm(client, unit);
uint32_t number_of_keys = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(phm);
if (number_of_keys == 0) {
aaa1bbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6aaa(phm);
set_unused(client, unit);
uint16_t start_value = 0;
const bool found = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen_with_equal_mask(client,
&start_value, mask, 0, 0);
if (!found) {
assert(client->num_used_masks);
client->num_used_masks--;
return 0;
}
}
const uint32_t num_lists = client_get_num_lists(client);
uint16_t start_value = 0;
uint32_t num_entries_for_mask = 0;
uint16_t num_open = 0;
uint32_t fewest_num_entries = UINT32_MAX;
uint16_t fewest_num_entries_unit = 0;
while (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen_with_equal_mask(client, &start_value, mask, 0, 0)) {
aaa1aaat *phm = client_get_phm(client, start_value);
const uint32_t aaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaa4aaa = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(phm);
if (aaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaa4aaa < fewest_num_entries) {
fewest_num_entries = aaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaa4aaa;
fewest_num_entries_unit = start_value;
}
num_entries_for_mask = num_entries_for_mask + aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(phm);
num_open++;
start_value++;
}
assert(num_open > 0);
const bool under_filled = is_mask_under_filled(num_open, num_entries_for_mask, num_lists);
if (under_filled) {
cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat entry = { 0 };
int *verify = NULL;
aaa1aaat *aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaempty = client_get_phm(client, fewest_num_entries_unit);
set_closed(client, fewest_num_entries_unit);
bool pack_success = true;
for (uint32_t aaaaaaaaaa1aaa = 0; aaaaaaaaaa1aaa < num_lists; aaaaaaaaaa1aaa++) {
if (aaaa1aaaread_element_bcam(aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaempty->km, aaaaaaaaaa1aaa, &entry, verify, 0, 0)) {
aaaaaaaaaaaaa1aaat temp_key;
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat temp_response;
temp_key = entry.key;
temp_response = entry.aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa;
const uint32_t hash_value = hash_key(client, &temp_key, false);
if (0 == aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaamulti_mask_key(client, &temp_key, &temp_response, mask, hash_value)) {
const bool success = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaelement(aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaempty, aaaaaaaaaa1aaa, 0, 0);
assert(success);
} else {
pack_success = false;
break;
}
}
}
if (pack_success) {
assert(0 == aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaempty));
aaa1bbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6aaa(aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaempty);
set_unused(client, fewest_num_entries_unit);
} else {
set_open(client, fewest_num_entries_unit);
}
}
}
return 0;
}
int client_read_response_for_key(const client_t *client, aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response, aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response_mask,
uint32_t *start_value,
aaaaaaaaaaaaa1aaat *key, aaaaaaaaaaaaa1aaat *mask, bool narrow_key)
{
assert(!client_is_tcam(client));
assert(aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaS <= 256);
aaaaaaaaaaaaa1aaat ternary_mask;
uint32_t key_pos = (*start_value) & 0x00ffffff;
uint16_t unit = ((*start_value) & 0xff000000) >> 24;
uint8_t narrow = 0;
uint8_t narrow_element = 0;
if (client_is_mixed_mode(client)) {
if (unit & 0x80) {
if (!narrow_key)
return CAM_ERROR_INVALID_ARG;
narrow_element = 1;
}
unit = unit & 0x7f;
}
if (narrow_key)
narrow = 1;
int verify_result;
int *verify = NULL;
if ((client_get_debug_flags(client) & CAM_DEBUG_VERIFY_SHADOW) != 0) {
verify = &verify_result;
}
const uint16_t initial_unit = unit;
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen_or_closed(client, &unit)) {
if (unit > initial_unit)
key_pos = 0;
} else
return CAM_ERROR_KEY_NOT_FOUND;
while (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen_or_closed(client, &unit)) {
aaa1aaat *phm = client_get_phm(client, unit);
if (aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaabcam(phm, response, response_mask, &key_pos, key, &ternary_mask, &narrow, &narrow_element,
narrow_key, verify)) {
if (narrow && (narrow_element == 0)) {
narrow_element = 1;
} else {
key_pos++;
}
*start_value = (0x00ffffff & key_pos);
uint32_t temp = unit << 24;
if (client_is_mixed_mode(client))
{
if (narrow && (narrow_element == 1)) {
temp = temp | 0x80000000;
}
}
*start_value = *start_value | temp;
uint8_t range_valid = 0;
uint8_t mask_id = 0;
aaa1aaaread_mask(phm, mask, &range_valid, &mask_id);
if (verify)
return *verify;
return 0;
}
unit++;
key_pos = 0;
narrow_element = 0;
} 
return CAM_ERROR_KEY_NOT_FOUND;
}
static bool probe_and_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaawith_mask(client_t *client,
uint16_t except_unit, const aaaaaaaaaaaaa1aaat *key,
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response,
const aaaaaaaaaaaaa1aaat *mask, uint64_t hash_value, uint8_t *num_open,
uint32_t *num_entries_for_mask) {
const uint16_t num_units = client_get_num_units(client);
uint16_t start_value = num_units - 1;
*num_open = 0;
*num_entries_for_mask = 0;
while (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen_with_equal_mask_dec(client, &start_value, mask, 0, 0)) { 
aaa1aaat *phm = client_get_phm(client, start_value);
*num_entries_for_mask = *num_entries_for_mask
+ aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(phm);
(*num_open)++;
if (start_value != except_unit) {
bool success = aaa1aaaif_invalid_insert(phm, key, response,
hash_value,
false, false);
if (success) {
(*num_entries_for_mask)++;
htable_write(client->htable, hash_value, start_value);
return true;
}
}
if (start_value > 0)
start_value--;
else
break;
}
return false;
}
static bool probe_and_insert(client_t *client, uint16_t start_unit, uint16_t except_unit, const aaaaaaaaaaaaa1aaat *key,
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response, uint64_t hash_value, bool narrow_key)
{
uint16_t unit = start_unit;
const uint16_t num_units = client_get_num_units(client);
uint8_t start = 1;
if (narrow_key) 
start = 0;
for (uint8_t pack_narrow = start; pack_narrow <= 1; pack_narrow++) {
uint16_t loop = num_units;
while (loop) {
if (unit != except_unit) {
aaa1aaat *phm = client_get_phm(client, unit);
bool success = aaa1aaaif_invalid_insert(phm, key, response,
hash_value, narrow_key, pack_narrow);
if (success) {
htable_write(client->htable, hash_value, unit);
return true;
}
}
if (unit == (num_units - 1))
unit = 0;
else
unit++;
loop--;
} 
} 
return false;
}
static bool split_dual_narrow(client_t *client, uint16_t unit, uint64_t hash_value)
{
cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat read_entry = { 0 };
assert(client_is_drambcam(client));
aaa1aaat *phm = client_get_phm(client, unit);
uint16_t fingerprint;
uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaafrom_hash_value(phm, hash_value, &fingerprint);
if (client_is_overwritten(client, phm, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa)) {
return false;
}
for (uint8_t narrow_element = 0; narrow_element < 2; narrow_element++) {
bool success = aaa1aaaread_element(phm, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, &read_entry,
NULL, 1, narrow_element);
assert(success); 
aaaaaaaaaaaaa1aaat aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa;
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa;
memcpy(&aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, &read_entry.key, sizeof(aaaaaaaaaaaaa1aaat));
memcpy(&aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, &read_entry.aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
uint64_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaavalue = hash_key(client, &aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, true);
success = probe_and_insert(client, 0, unit, &aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa,
&aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaavalue, true);
if (success) {
success = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaelement(phm, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, 1,
narrow_element);
assert(success);
return true;
}
}
return false;
}
static void delete_overwrites(client_t *client, aaa1aaat *phm, uint32_t list, uint16_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaapos, uint8_t narrow,
uint8_t narrow_element)
{
assert(aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaapos < client->num_overwrites);
assert(phm != NULL);
for (int i = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaapos; i >= 0; i--) {
if (client->overwrites[i].phm == phm && client->overwrites[i].list == list
&& client->overwrites[i].narrow == narrow && client->overwrites[i].narrow_element == narrow_element) {
client->overwrites[i].phm = NULL;
}
}
}
bool client_is_overwritten(const client_t *client, const aaa1aaat *phm, uint32_t list)
{
for (int i = (client->num_overwrites - 1); i >= 0; i--) {
if (client->overwrites[i].phm == phm && client->overwrites[i].list == list)
return true;
}
return false;
}
void client_add_overwrite(client_t *client, const cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat *entry)
{
assert((!entry->narrow && entry->narrow_element == 0) || entry->narrow);
assert(client->num_overwrites < CLIENT_MAX_OVERWRITES);
client->overwrites[client->num_overwrites] = *entry;
client->num_overwrites++;
}
static inline void flush_and_empty_overwrites(client_t *client)
{
if (client->num_overwrites == 0)
return;
for (int i = (client->num_overwrites - 1); i >= 0; i--) {
const cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat *over = &client->overwrites[i];
if (over->phm != NULL) {
aaaa1aaat *km = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaakm(over->phm);
if (!(client->conf->instance_type == DRAMBCAM)) {
aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaelement(km, over->list,
over->narrow,
over->narrow_element);
}
aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaabcam(km, over);
const uint16_t phys_unit = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(over->phm);
const uint16_t num_slots = cam_config_get_num_slots(client->conf);
const uint8_t slot = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(over->phm);
htable_write(client->htable, over->bucket, phys_unit * num_slots + slot);
if (i > 0)
delete_overwrites(client, over->phm, over->list, i - 1,
over->narrow, over->narrow_element);
}
}
client->num_overwrites = 0;
}
static uint16_t compute_num_hw_write_operations(const client_t *client, uint16_t split_dual_narrows)
{
if (client_is_drambcam(client)) {
return client->num_overwrites * 33 + split_dual_narrows * 2 * 33; 
} else {
assert(split_dual_narrows == 0);
return (1 + (cam_config_get_list_length(client->conf) + 63) / 64 + 2) * client->num_overwrites; 
}
}
static int aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaasingle_mask_key(client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response,
bool narrow, uint64_t hash_value, uint16_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaastart_unit)
{
bool success;
client->num_overwrites = 0;
if (!client->zero_unused) {
uint16_t new_unit = 0;
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaunused(client, &new_unit)) {
write_mask(client, NULL, new_unit, 0, 0);
aaa1aaat *phm = client_get_phm(client, new_unit);
success = aaa1aaaif_invalid_insert(phm, key, response, hash_value,
narrow, false);
assert(success);
set_open(client, new_unit);
htable_write(client->htable, hash_value, new_unit);
return 0;
} else {
client->zero_unused = true;
}
}
cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat evicted_entry = { 0 };
const uint16_t num_units = client_get_num_units(client);
assert(num_units > 0);
bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaanarrow_key = narrow;
aaaaaaaaaaaaa1aaat aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa = *key;
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa = *response;
uint64_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaavalue = hash_value;
uint16_t collision_count = 0;
uint16_t split_dual_narrows = 0;
assert(aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaastart_unit < num_units);
uint16_t except_unit = num_units;
uint16_t unit = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaastart_unit;
const uint16_t max_hw_writes = client->conf->arg.max_hw_writes;
while (1) {
success = probe_and_insert(client, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaastart_unit, except_unit,
&aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, &aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa,
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaavalue,
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaanarrow_key);
if (success) {
flush_and_empty_overwrites(client);
return 0;
}
if (client->num_overwrites >= CLIENT_MAX_OVERWRITES) { 
return CAM_ERROR_FULL;
}
if (max_hw_writes > 0) { 
if (max_hw_writes <= compute_num_hw_write_operations(client, split_dual_narrows)) {
return CAM_ERROR_FULL;
}
}
client->num_collisions++; 
collision_count++;
if (collision_count > client->max_collisions) {
client->max_collisions = collision_count;
}
success = false;
for (uint8_t i = 0; i < num_units; i++) {
if (unit != except_unit) {
aaa1aaat *phm = client_get_phm(client, unit);
success = aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaa(phm, &aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, &aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa,
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaavalue, &evicted_entry,
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaanarrow_key);
if (success) {
break;
}
}
if (unit == (num_units - 1))
unit = 0;
else
unit++;
}
if (!success) {
const bool mixed_mode = client_is_mixed_mode(client);
if (!mixed_mode) { 
return CAM_ERROR_FULL;
}
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaanarrow_key) {
return CAM_ERROR_FULL;
}
if (client->num_overwrites >= CLIENT_MAX_OVERWRITES) { 
return CAM_ERROR_FULL;
}
if (max_hw_writes > 0) { 
if (max_hw_writes <= compute_num_hw_write_operations(client, split_dual_narrows)) {
return CAM_ERROR_FULL;
}
}
for (uint8_t i = 0; i < num_units; i++) {
if (unit != except_unit) {
assert(!aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaanarrow_key);
success = split_dual_narrow(client, unit, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaavalue);
if (success) { 
aaa1aaat *phm = client_get_phm(client, unit);
success = aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaa(phm, &aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, &aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaavalue,
&evicted_entry, false);
assert(success);
split_dual_narrows++;
break;
} else {
}
} 
if (unit == (num_units - 1))
unit = 0;
else
unit++;
} 
if (!success) { 
return CAM_ERROR_FULL;
}
} 
except_unit = unit;
assert(success);
if (success) {
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa = evicted_entry.key;
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa = evicted_entry.aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa;
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaanarrow_key = evicted_entry.narrow;
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaavalue = hash_key(client, &aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaanarrow_key);
}
if (unit == (num_units - 1))
unit = 0;
else
unit++;
} 
}
static int aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaamulti_mask_key(client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response,
const aaaaaaaaaaaaa1aaat *mask,
uint64_t hash_value)
{
client->num_overwrites = 0;
bool success;
cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat evicted_entry = { 0 };
const uint16_t num_units = client_get_num_units(client);
aaaaaaaaaaaaa1aaat aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa = *key;
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa = *response;
uint64_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaavalue = hash_value;
uint16_t collision_count = 0;
uint8_t num_open = 0;
uint16_t except_unit = num_units;
while (1) {
uint16_t start_value = num_units - 1;
num_open = 0;
uint32_t num_entries_for_mask = 0;
bool break_out = true;
bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaasuccess = false;
while (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen_with_equal_mask_dec(client, &start_value, mask, 0, 0)) { 
bool success = probe_and_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaawith_mask(client, except_unit,
&aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, &aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, mask,
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaavalue,
&num_open, &num_entries_for_mask);
if (success) {
flush_and_empty_overwrites(client);
return 0;
}
break_out = true;
if (num_open < 2)
break;
if (client->num_overwrites >= CLIENT_MAX_OVERWRITES) { 
break;
}
float fill_ratio = 0;
const uint32_t num_lists = client_get_num_lists(client);
if (num_open == 2)
fill_ratio = (float) aaaaaa1aaa2W_aaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa;
else if (num_open == 3)
fill_ratio = (float) aaaaaa1aaa3W_aaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa;
else
fill_ratio = (float) aaaaaa1aaaBCAM_FILL_RATIO;
if (num_entries_for_mask > fill_ratio * num_open * num_lists)
break;
break_out = false;
client->num_collisions++;
collision_count++;
if (collision_count > client->max_collisions) {
client->max_collisions = collision_count;
}
aaa1aaat *phm = client_get_phm(client, start_value);
const bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaasuccess = aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaa(phm, &aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa,
&aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaavalue,
&evicted_entry,
false);
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaasuccess) {
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaasuccess = true;
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa = evicted_entry.key;
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa = evicted_entry.aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa;
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaavalue = hash_key(client, &aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, false);
except_unit = start_value;
}
if (start_value > 0)
start_value--;
else
break;
}
if (break_out)
break;
if (!aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaasuccess)
break;
}
uint16_t new_unit = 0;
if (!aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaunused(client, &new_unit)) {
return CAM_ERROR_FULL;
}
if (num_open == 0) {
if ((client->conf->arg.optimization_flags & CAM_OPTIMIZE_MASKS) == 0) {
if (client->num_used_masks >= client_get_num_masks(client)) {
return CAM_ERROR_FULL;
}
}
client->num_used_masks++;
}
client->num_overwrites = 0;
write_mask(client, mask, new_unit, 0, 0);
aaa1aaat *phm = client->unit[new_unit].phm;
success = aaa1aaaif_invalid_insert(phm, key, response, hash_value, false, false);
assert(success);
set_open(client, new_unit);
htable_write(client->htable, hash_value, new_unit);
return 0;
}
static bool is_duplicate(client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaa1aaat *mask, const cam_options_t *options,
uint64_t *hash_value)
{
uint16_t unit;
bool unit_valid;
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat response;
const uint8_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = cache_hit(client, key, &unit_valid, &unit, options, hash_value);
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa > 0) {
const bool found = db_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(client, key, mask, aaa1aaaREAD,
false, &response, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, unit_valid, &unit, *hash_value,
options->narrow, NULL);
if (found)
return true;
}
return false;
}
int client_get_widths(const client_t *client, uint16_t *key_width, uint16_t *response_width,
bool narrow_key)
{
*key_width = client_get_key_width(client);
*response_width = client_get_response_width(client);
if (client_is_mixed_mode(client)) {
if (narrow_key) {
*key_width = client_get_narrow_key_width(client);
}
}
else if (narrow_key) {
return CAM_ERROR_WRONG_KEY_WIDTH;
}
return 0;
}
int client_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response, const aaaaaaaaaaaaa1aaat *mask,
const cam_options_t *options)
{
client->num_inserts++;
assert(((client->narrow_num_entries > 0) && client_is_mixed_mode(client)) || (client->narrow_num_entries == 0));
if ((client->conf->arg.optimization_flags & CAM_OPTIMIZE_ENTRIES) > 0) {
if (mask == NULL) {
float fill_ratio;
if (client_is_drambcam(client)) {
assert(client->conf->arg.update_mode == CAM_UPDATE_SOFTWARE);
fill_ratio = (float) aaaaaa1aaaDRAMBCAM_FILL_RATIO_SOFTWARE;
} else
fill_ratio = (float) aaaaaa1aaaBCAM_FILL_RATIO;
const uint8_t num_units = client_get_num_units(client);
const uint32_t max_entries = (uint32_t) (num_units * client_get_num_lists(client) * fill_ratio);
const uint32_t wide_entries = client->num_entries
- client->narrow_num_entries;
if ((wide_entries + (client->narrow_num_entries + 1) / 2)
>= max_entries) {
client->failed_inserts++;
return CAM_ERROR_FULL;
}
}
} else {
const uint32_t wide_entries = client->num_entries
- client->narrow_num_entries;
if ((wide_entries + (client->narrow_num_entries + 1) / 2)
>= client->conf->arg.num_entries) {
client->failed_inserts++;
return CAM_ERROR_FULL;
}
}
if (mask != NULL) {
const uint16_t key_width = cam_config_get_key_width(client->conf);
int status = check_masked_key_bits(mask, key, key_width);
if (status != 0) {
client->failed_inserts++;
return status;
}
}
uint64_t hash_value;
const bool duplicate = is_duplicate(client, key, mask, options, &hash_value);
if (duplicate) {
client->failed_inserts++;
return CAM_ERROR_DUPLICATE_FOUND;
}
htable_inc(client->htable, hash_value);
if (mask == NULL)
{
int rc = -1;
const uint16_t num_units = client_get_num_units(client);
assert(num_units > 0);
uint16_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaastart_unit = hash_value - hash_value / num_units * num_units;
for (uint8_t i = 0; i < num_units; i++) {
rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaasingle_mask_key(client, key, response,
options->narrow,
hash_value, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaastart_unit);
if (rc == 0)
break;
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaastart_unit == (num_units - 1))
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaastart_unit = 0;
else
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaastart_unit++;
}
if (rc == 0) {
client->num_entries++;
if (options->narrow)
client->narrow_num_entries++;
}
else
client->failed_inserts++;
return rc;
}
assert(!options->narrow);
int rc = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaamulti_mask_key(client, key, response, mask, hash_value);
if (rc == 0) {
client->num_entries++;
}
else
client->failed_inserts++;
return rc;
}
int client_update_key(client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response, const aaaaaaaaaaaaa1aaat *mask,
const cam_options_t *options)
{
client->num_updates++;
if (mask != NULL) {
const uint16_t key_width = cam_config_get_key_width(client->conf);
int status = check_masked_key_bits(mask, key, key_width);
if (status != 0) {
client->failed_updates++;
return status;
}
}
uint16_t read_unit;
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat comp_prio = *response;
uint64_t hash_value;
bool read_unit_valid;
const uint8_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = cache_hit(client, key, &read_unit_valid, &read_unit, options, &hash_value);
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa == 0) {
client->failed_updates++;
return CAM_ERROR_KEY_NOT_FOUND;
}
const bool found_in_db = db_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(client, key, mask, aaa1bbbbbbbbbbbbbbbbbbbb3aaa,
false, &comp_prio, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, read_unit_valid, &read_unit, hash_value,
options->narrow, NULL);
if (found_in_db) {
return 0;
}
client->failed_updates++;
return CAM_ERROR_KEY_NOT_FOUND;
}
int client_read_key(const client_t *client, const aaaaaaaaaaaaa1aaat *key, aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response, const aaaaaaaaaaaaa1aaat *mask,
const cam_options_t *options)
{
if (mask != NULL) {
const uint16_t key_width = cam_config_get_key_width(client->conf);
int status = check_masked_key_bits(mask, key, key_width);
if (status != 0)
return status;
}
uint16_t read_unit;
uint64_t hash_value;
bool read_unit_valid;
const uint8_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = cache_hit(client, key, &read_unit_valid,
&read_unit, options, &hash_value);
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa == 0)
return CAM_ERROR_KEY_NOT_FOUND;
int verify_result;
int *verify = NULL;
if ((client_get_debug_flags(client) & CAM_DEBUG_VERIFY_SHADOW) != 0) {
verify = &verify_result;
}
const bool found_in_db = db_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa((client_t *) client, key, mask, aaa1aaaREAD,
false, response, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, read_unit_valid, &read_unit,
hash_value, options->narrow, verify);
if (found_in_db) {
if (verify)
return *verify;
return 0;
}
return CAM_ERROR_KEY_NOT_FOUND;
}
int client_lookup_stcam(client_t *client, const aaaaaaaaaaaaa1aaat *key, aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *out_prio_resp, bool narrow_key)
{
assert(!client_is_tcam(client));
assert(client->conf->instance_type == STCAM);
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat lowest_prio;
memset(&lowest_prio, 0xff, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
uint16_t unit = 0;
const uint16_t response_width = client_get_response_width(client);
bool found = false;
while (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen_or_closed(client, &unit)) {
aaa1aaat *phm = client_get_phm(client, unit);
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat prio_resp;
memset(&prio_resp, 0, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
bool success = false;
success = aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup(phm, key, &prio_resp, narrow_key);
if (success) {
found = true;
const uint8_t prio_width = client_get_prio_width(client);
assert(prio_width <= 32);
if (prio_width > 0) {
uint32_t prio_resp_prio;
uint32_t lowest_prio_prio;
const uint16_t start_pos = response_width;
const uint16_t end_pos = start_pos + prio_width - 1;
cam_read_field((uint32_t *) &prio_resp, start_pos, end_pos,
&prio_resp_prio);
cam_read_field((uint32_t *) &lowest_prio, start_pos, end_pos,
&lowest_prio_prio);
if (prio_resp_prio <= lowest_prio_prio) {
lowest_prio = prio_resp;
}
} else {
*out_prio_resp = prio_resp;
return 0;
}
}
unit++;
}
if (found) {
*out_prio_resp = lowest_prio;
return 0;
}
return CAM_ERROR_KEY_NOT_FOUND;
}
int client_get_current_num_units(const client_t *client)
{
int units = 0;
const uint16_t num_units = client_get_num_units(client);
for (uint16_t unit = 0; unit < num_units; unit++) {
const aaa1aaat *phm = client->unit[unit].phm;
if (aaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaavalid(phm)) {
units++;
}
}
return units;
}
#define aaaaaa1aaaDRAMBCAM_AXIS_WS 0xD0
#define aaaaaa1aaaDRAMBCAM_READS 0xD4
#define aaaaaa1aaaDRAMBCAM_WRITES 0xD8
#define aaaaaa1aaaDRAMBCAM_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaLATENCY 0xDC
#define aaaaaa1aaaDRAMBCAM_OUTSTANDING_READS 0xE0
#define aaaaaa1aaaDRAMBCAM_LOOKUP_RESP_CNT 0xE4
int client_read_dram_rate_stats(client_t *client, struct cam_dram_rate *dram) {
if (!client_is_drambcam(client))
return CAM_ERROR_STATISTICS_NOT_AVAILABLE;
client_drambcam_hw_read(client, aaaaaa1aaaDRAMBCAM_AXIS_WS, &dram->axis_ws);
client_drambcam_hw_read(client, aaaaaa1aaaDRAMBCAM_READS, &dram->reads);
client_drambcam_hw_read(client, aaaaaa1aaaDRAMBCAM_WRITES, &dram->writes);
client_drambcam_hw_read(client, aaaaaa1aaaDRAMBCAM_LOOKUP_RESP_CNT, &dram->lookup_responses);
return 0;
}
int client_read_dram_snapshot_stats(client_t *client, struct cam_dram_snapshot *dram) {
if (!client_is_drambcam(client))
return CAM_ERROR_STATISTICS_NOT_AVAILABLE;
client_drambcam_hw_read(client, aaaaaa1aaaDRAMBCAM_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaLATENCY, &dram->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaalatency);
client_drambcam_hw_read(client, aaaaaa1aaaDRAMBCAM_OUTSTANDING_READS, &dram->outstanding_reads);
return 0;
}
#ifndef aaaaaaaaaaaa1aaaH
#define aaaaaaaaaaaa1aaaH
#ifndef _aaaaaaaaaaaa1aaaT_
#define _aaaaaaaaaaaa1aaaT_
typedef struct aaaaaaaaaaaa1aaat aaaaaaaaaaaa1aaat;
#endif
void aaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(aaaaaaaaaaaa1aaat *mm, client_t *client, uint16_t unit, uint8_t slot_number);
void aaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(aaaaaaaaaaaa1aaat *mm);
size_t aaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa(void);
bool aaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaavalid(const aaaaaaaaaaaa1aaat *mm);
void aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6aaa(aaaaaaaaaaaa1aaat *mm, const aaaaaaaaaaaaa1aaat *mask,
uint16_t seed, uint8_t range_valid, uint8_t mask_id);
void aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(const aaaaaaaaaaaa1aaat *mm, uint8_t *range_valid);
void aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(const aaaaaaaaaaaa1aaat *mm, const aaaaaaaaaaaaa1aaat *key, aaaaaaaaaaaaa1aaat *masked_key);
bool aaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaawide_search(const aaaaaaaaaaaa1aaat *mm);
void aaaaaaaaaaaa1bbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6aaa(aaaaaaaaaaaa1aaat *mm);
bool aaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaequal(const aaaaaaaaaaaa1aaat *mm, const aaaaaaaaaaaaa1aaat *mask, uint8_t range_valid,
uint8_t mask_id);
const client_t *aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaclient(const aaaaaaaaaaaa1aaat *mm);
void aaaaaaaaaaaa1aaaread_mask(const aaaaaaaaaaaa1aaat *mm, aaaaaaaaaaaaa1aaat *mask, uint8_t *range_valid,
uint8_t *mask_id);
void aaaaaaaaaaaa1bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6aaa(aaaaaaaaaaaa1aaat *mm);
uint16_t aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaseed(const aaaaaaaaaaaa1aaat *mm);
void aaaaaaaaaaaa1bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaseed(aaaaaaaaaaaa1aaat *mm, uint16_t seed);
uint8_t aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(const aaaaaaaaaaaa1aaat *mm);
uint16_t aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(const aaaaaaaaaaaa1aaat *mm);
#endif
static void set_key_prio_response_and_fp(const aaaa1aaat *km, uint32_t list_number, const key_and_mask_t *key,
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, uint16_t fingerprint) {
const uint16_t list_length = client_get_list_length(km->client);
uint16_t prio_field_end_pos = list_length - 2;
const uint16_t prio_width = client_get_prio_width(km->client);
assert(prio_width <= 32);
const uint16_t aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa = prio_width + client_get_response_width(km->client);
const uint16_t key_width = client_get_key_width(km->client);
const uint16_t number_of_word32s = list_length / 32;
uint32_t temp[CAM_MAX_KEY_WIDTH_MEM + CAM_MAX_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaMEM];
memset(temp, 0, (CAM_MAX_KEY_WIDTH_MEM + CAM_MAX_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaMEM) * sizeof(uint32_t));
memcpy(temp, key, (key_width + 7) / 8);
const uint16_t response_field_start_pos = prio_field_end_pos - aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa + 1;
cam_write_field(temp, response_field_start_pos, prio_field_end_pos, (uint32_t *) aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa,
prio_field_end_pos);
const uint32_t num_lists = client_get_num_lists(km->client);
assert(list_number < num_lists);
km->fingerprint[list_number] = fingerprint >> (16 - client_get_fingerprint_width(km->client));
temp[number_of_word32s] = temp[number_of_word32s] | 0x80000000;
client_inc_shadow_writes(km->client);
memcpy(&km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[list_number * number_of_word32s], temp, number_of_word32s * 4);
}
static void set_response(const aaaa1aaat *km, uint32_t list_number, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, uint8_t narrow,
uint8_t narrow_element)
{
const uint16_t granularity = client_get_generation_number_granularity(km->client);
uint8_t g = 0;
if (granularity)
g = 1;
const uint16_t list_length = client_get_list_length(km->client);
uint16_t prio_field_end_pos = list_length - 2 - g;
const uint8_t prio_width = client_get_prio_width(km->client);
assert(prio_width <= 32);
uint16_t response_width = client_get_response_width(km->client);
uint16_t aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa = prio_width + response_width;
const uint16_t number_of_word32s = list_length / 32;
const bool mixed_mode = client_is_mixed_mode(km->client);
assert((!mixed_mode && narrow == false) || mixed_mode);
if (mixed_mode) {
assert(!client_is_tcam(km->client));
if (narrow && (narrow_element == 0)) {
prio_field_end_pos = list_length / 2 - 3 - g;
} else {
prio_field_end_pos = list_length - 3 - g;
}
}
if (g == 1) {
const uint16_t start_pos = calc_start_pos_gen_number(aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa, prio_field_end_pos, granularity);
write_field_with_gen_number(&km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[list_number * number_of_word32s], start_pos, response_width,
(uint32_t *) aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, prio_field_end_pos, granularity);
} else {
const uint16_t response_field_start_pos = prio_field_end_pos - aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa + 1;
const uint16_t response_field_end_pos = response_field_start_pos + response_width - 1;
cam_write_field(&km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[list_number * number_of_word32s], response_field_start_pos,
response_field_end_pos, (uint32_t *) aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, prio_field_end_pos);
}
}
static void set_fingerprint(const aaaa1aaat *km, uint32_t list_number,
uint16_t fingerprint, uint8_t fp_width)
{
assert(!client_is_tcam(km->client));
assert(!client_is_mixed_mode(km->client));
assert(client_get_prio_width(km->client) == 0);
assert(list_number < client_get_num_lists(km->client));
assert(fp_width <= 16);
km->fingerprint[list_number] = fingerprint >> (16 - fp_width);
}
void aaaa1bbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, uint8_t narrow,
uint8_t narrow_element)
{
set_response(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, narrow, narrow_element);
if (km->flush == true) {
flush(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, false, false, UPDATE, narrow, narrow_element, false, false);
}
}
void aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaabcam(aaaa1aaat *km, const cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat *entry)
{
assert(!client_is_tcam(km->client));
bool wide2narrow = false;
const aaaaaaaaaaaaa1aaat *aaaaaaaaa1aaa = &entry->key;
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaptr = &entry->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa;
uint8_t narrow = entry->narrow;
uint8_t narrow_element = entry->narrow_element;
uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = entry->list;
const uint16_t granularity = client_get_generation_number_granularity(km->client);
if (client_is_mixed_mode(km->client)) {
bool wide_valid, narrow1_valid, narrow0_valid;
aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaabits(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, &wide_valid, &narrow1_valid, &narrow0_valid);
assert(!((narrow == 0) && narrow1_valid && narrow0_valid));
if (granularity) {
uint8_t generation_number;
const bool one_narrow_valid = narrow0_valid != narrow1_valid;
if ((narrow == 0) && one_narrow_valid) {
if (narrow0_valid) {
generation_number = get_generation_number(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, 1, 0);
} else {
generation_number = get_generation_number(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, 1, 1);
}
} else if (wide_valid && narrow) {
generation_number = get_generation_number(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, 0, 0);
} else {
generation_number = get_generation_number(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, narrow, narrow_element);
}
generation_number++;
set_generation_number(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, narrow, narrow_element, generation_number);
}
if (wide_valid && narrow) {
set_control_bits(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, 0, 0, 0);
wide2narrow = true;
}
set_response(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaptr, narrow, narrow_element);
set_key(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, (key_and_mask_t *) aaaaaaaaa1aaa, narrow, narrow_element);
} else { 
if (granularity) {
uint8_t generation_number = get_generation_number(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, narrow, narrow_element);
generation_number++;
set_generation_number(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, 0, 0, generation_number);
set_response(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaptr, narrow, narrow_element);
set_key(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, (key_and_mask_t *) aaaaaaaaa1aaa, narrow, narrow_element);
const uint8_t fp_width = client_get_fingerprint_width(km->client);
if (fp_width) {
set_fingerprint(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, entry->fingerprint, fp_width);
}
} else {
set_key_prio_response_and_fp(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, (key_and_mask_t *) aaaaaaaaa1aaa,
aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaptr,
entry->fingerprint);
}
} 
set_control_bits(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, 1, narrow, narrow_element);
if (km->flush == true) {
flush(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, false, false, OTHER, narrow, narrow_element, false, wide2narrow);
}
}
bool aaaa1aaaread_element_bcam(aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat *aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaout,
int *verify, uint8_t narrow,
uint8_t narrow_element)
{
assert(!client_is_tcam(km->client));
const bool present = aaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaapresent(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, narrow, narrow_element);
if (!present)
return false;
memset(aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaout, 0, sizeof *aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaout);
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaout->list = aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa;
get_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, &aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaout->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, narrow, narrow_element);
get_key(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, (key_and_mask_t *)&aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaout->key, narrow, narrow_element);
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaout->narrow = narrow;
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaout->narrow_element = narrow_element;
if (verify != NULL) {
flush(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, false, verify, OTHER, narrow, narrow_element,
false, false);
}
return true;
}
#ifndef aa1aaaH
#define aa1aaaH
#ifndef _aa1aaaT_
#define _aa1aaaT_
typedef struct aa1aaat aa1aaat;
#endif
size_t aa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa(void);
size_t aa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaabaaaaaaaaaa4aaa(void);
bool aa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(aa1aaat *bm, client_t *client, uint16_t unit, uint8_t slot_number, cam_malloc_func malloc_function);
void aa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(aa1aaat *bm, cam_free_func free_function);
bool aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(const aa1aaat *bm, uint32_t bucket);
bool aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(const aa1aaat *bm, uint32_t bucket);
bool aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(const aa1aaat *bm, uint32_t bucket);
uint8_t aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(const aa1aaat *bm, uint32_t bucket);
uint32_t aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(const aa1aaat *bm, uint32_t bucket);
void aa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(aa1aaat *bm, uint32_t bucket, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
void aa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaanext_key(aa1aaat *bm, uint32_t bucket);
void aa1bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaapointer(aa1aaat *bm, uint32_t bucket, uint8_t function);
void aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaapointer(aa1aaat *bm, uint32_t bucket, uint32_t new_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
uint8_t aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(const aa1aaat *bm, uint32_t bucket);
void aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaa(aa1aaat *bm);
void aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(aa1aaat *bm, uint32_t bucket);
void aa1bbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaand_flush(aa1aaat *target_bm, aa1aaat *source_bm, uint32_t bucket);
void aa1bbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaall(const aa1aaat *bm);
#endif
bool aaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabcam(aaa1aaat *phm, client_t *client, uint16_t unit, uint8_t slot_number)
{
assert(phm != NULL);
cam_malloc_func malloc_function = client_get_malloc_function(client);
phm->km = NULL;
phm->bm = NULL;
phm->mm = NULL;
phm->km = (aaaa1aaat *) malloc_function(aaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa());
if (phm->km == NULL) {
return false;
}
phm->mm = (aaaaaaaaaaaa1aaat *) malloc_function(aaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa());
if (phm->mm == NULL) {
return false;
}
if (!aaaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(phm->km, client, unit, slot_number, true)) {
return false;
}
aaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(phm->mm, client, unit, slot_number);
phm->number_of_keys = 0;
phm->client = client;
return true;
}
void aaa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabcam(aaa1aaat *phm, cam_free_func free_function)
{
if (phm == NULL) {
return;
}
aaaa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(phm->km, free_function);
free_function(phm->mm);
free_function(phm);
}
bool aaa1aaaread_element(aaa1aaat *phm, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa,
cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat *aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaout, int *verify, uint8_t narrow,
uint8_t narrow_element)
{
return aaaa1aaaread_element_bcam(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaout, verify, narrow, narrow_element);
}
static bool aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaand_read_element_bcam(const aaa1aaat *phm, uint32_t *start_value, aaaaaaaaaaaaa1aaat *key, aaaaaaaaaaaaa1aaat *ternary_mask,
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *priority,
uint64_t *bucket, int *verify, uint8_t *narrow, uint8_t *narrow_element)
{
assert(!client_is_tcam(phm->client));
assert(narrow != NULL);
assert(narrow_element != NULL);
cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat entry = { 0 };
const uint32_t segment_size = client_get_num_lists(phm->client);
const uint32_t max_start_value = segment_size - 1;
while (*start_value <= max_start_value) {
const uint32_t element = *start_value / segment_size;
const uint32_t aaaaaaaaaa1aaa = *start_value - element * segment_size;
if (aaaa1aaaread_element_bcam(phm->km, aaaaaaaaaa1aaa, &entry, verify, *narrow, *narrow_element)) {
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *priority_ptr = &entry.aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa;
memcpy(priority, priority_ptr, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
*key = entry.key;
*ternary_mask = entry.mask;
*bucket = entry.bucket;
return true;
} else {
if ((*narrow) && (*narrow_element == 0)) {
*narrow_element = 1;
} else if (*narrow) {
(*start_value)++;
*narrow_element = 0;
} else {
(*start_value)++;
}
}
}
return false;
}
bool aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaelement(aaa1aaat *phm, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, uint8_t narrow, uint8_t narrow_element)
{
if (aaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaapresent(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, narrow, narrow_element)) {
aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaelement(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, narrow, narrow_element);
phm->number_of_keys--;
return true;
}
return false;
}
void aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaall(aaa1aaat *phm, uint32_t *deletes) {
const uint32_t num_lists = client_get_num_lists(phm->client);
const bool mixed_mode = client_is_mixed_mode(phm->client);
*deletes = 0;
for (uint32_t i = 0; i < num_lists; i++) {
if (mixed_mode) {
bool wide_valid, narrow1_valid, narrow0_valid;
aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaabits(phm->km, i, &wide_valid, &narrow1_valid, &narrow0_valid);
if (wide_valid) {
const bool success = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaelement(phm, i, 0, 0);
assert(success);
(*deletes)++;
continue;
}
if (narrow0_valid) {
const bool success = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaelement(phm, i, 1, 0);
assert(success);
(*deletes)++;
}
if (narrow1_valid) {
const bool success = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaelement(phm, i, 1, 1);
assert(success);
(*deletes)++;
}
} else {
const bool success = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaelement(phm, i, 0, 0);
if (success)
(*deletes)++;
}
}
}
static uint32_t swap_hash_value32(const aaa1aaat *phm, uint32_t hash_value) {
const uint8_t murmur_slice = aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaseed(phm->mm) & 3; 
if (murmur_slice == 0)
return hash_value;
if (murmur_slice == 1) {
return __builtin_bswap32(hash_value);
}
const uint32_t low_temp = hash_value & 0xffff;
const uint32_t high_temp = hash_value >> 16;
const uint16_t swapped_low_temp = __builtin_bswap16(low_temp);
const uint16_t swapped_high_temp = __builtin_bswap16(high_temp);
const uint32_t double_swapped_temp = swapped_high_temp << 16 | swapped_low_temp;
if (murmur_slice == 2)
return double_swapped_temp;
if (murmur_slice == 3)
return __builtin_bswap32(double_swapped_temp);
assert(false);
return 0;
}
static uint64_t swap_hash_value64(const aaa1aaat *phm, uint64_t hash_value)
{
const uint8_t murmur_slice = aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaseed(phm->mm) & 3; 
switch(murmur_slice) {
case 0: return (hash_value >> 32) | (hash_value << 32);
case 1: return (hash_value >> 16) | (hash_value << 48);
case 2: return hash_value;
case 3: return (hash_value >> 48) | (hash_value << 16);
default: assert(0); return 0;
}
}
uint32_t aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaafrom_hash_value(const aaa1aaat *phm, uint64_t hash_value,
uint16_t *fingerprint)
{
uint32_t swapped_hash_value;
if (client_get_hash_function(phm->client) != 0) {
uint64_t tmp = swap_hash_value64(phm, hash_value);
swapped_hash_value = tmp;
*fingerprint = tmp >> 48;
} else {
swapped_hash_value = swap_hash_value32(phm, hash_value);
*fingerprint = 0;
}
return aaa1aaaadjust_list(phm, swapped_hash_value);
}
bool aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaa(aaa1aaat *phm, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response,
uint64_t hash_value,
cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat *evicted_entry, bool narrow_key)
{
cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat entry = { 0 };
uint32_t list;
const aaaaaaaaaaaaa1aaat *masked_key;
aaaaaaaaaaaaa1aaat m_key;
const bool is_drambcam = client_is_drambcam(phm->client);
if (!(is_drambcam || client_is_bcam(phm->client))) {
memset(&m_key, 0, sizeof(m_key));
aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->mm, key, &m_key);
masked_key = &m_key;
} else {
masked_key = key;
}
const uint32_t num_lists = client_get_num_lists(phm->client);
const uint32_t max_list = num_lists - 1;
uint16_t fingerprint = 0;
if (is_drambcam) {
list = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaafrom_hash_value(phm, hash_value, &fingerprint);
} else {
hash_t *hash = (hash_t *) alloca(hash_size());
uint32_t bucket_hash;
aaaaaaa1aaa(hash, masked_key, phm);
bucket_hash = hash_calculate_bucket(hash);
list = bucket_hash & max_list;
}
entry.bucket = hash_value;
entry.aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa = *response;
entry.key = *masked_key;
entry.fingerprint = fingerprint;
entry.list = list;
entry.phm = phm;
const bool overwritten = client_is_overwritten(phm->client, phm,
list);
if (overwritten) {
return false;
}
const bool mixed = client_is_mixed_mode(phm->client);
if (!mixed) {
assert(!narrow_key);
bool success = aaaa1aaaread_element_bcam(phm->km, list, evicted_entry, NULL, 0,
0);
assert(success);
client_add_overwrite(phm->client, &entry);
return true;
}
bool wide_valid, narrow1_valid, narrow0_valid;
uint8_t narrow = 0;
uint8_t narrow_element = 0;
aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaabits(phm->km, list, &wide_valid, &narrow1_valid,
&narrow0_valid);
assert(wide_valid || narrow1_valid || narrow0_valid); 
bool success = false;
if (!narrow_key && wide_valid) { 
success = aaaa1aaaread_element_bcam(phm->km, list, evicted_entry, NULL, 0, 0);
} else if (!narrow_key && !wide_valid && !narrow0_valid && narrow1_valid) { 
narrow = 1;
narrow_element = 1;
success = aaaa1aaaread_element_bcam(phm->km, list, evicted_entry, NULL, narrow,
narrow_element);
} else if (!narrow_key && !wide_valid && !narrow1_valid && narrow0_valid) { 
narrow = 1;
success = aaaa1aaaread_element_bcam(phm->km, list, evicted_entry, NULL, narrow,
narrow_element);
} else if (narrow_key && !wide_valid) { 
assert(narrow0_valid && narrow1_valid);
narrow = 1;
narrow_element = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(hash_value, 13, 1); 
success = aaaa1aaaread_element_bcam(phm->km, list, evicted_entry, NULL, narrow,
narrow_element);
} else if (!narrow_key && !wide_valid) { 
return false;
} else if (narrow_key && wide_valid) { 
narrow = 1;
narrow_element = 0;
success = aaaa1aaaread_element_bcam(phm->km, list, evicted_entry, NULL, 0, 0);
} else {
assert(false);
}
if (success) {
if (!narrow_key) {
narrow = 0;
narrow_element = 0;
}
entry.narrow = narrow;
entry.narrow_element = narrow_element;
client_add_overwrite(phm->client, &entry);
} else {
assert(false);
}
return true;
}
bool aaa1aaaif_invalid_insert(aaa1aaat *phm, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response, uint64_t hash_value,
bool narrow_key, bool pack_narrow)
{
cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat entry = { 0 };
uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa;
const aaaaaaaaaaaaa1aaat *masked_key;
aaaaaaaaaaaaa1aaat m_key;
const bool is_drambcam = client_is_drambcam(phm->client);
if (!(is_drambcam || client_is_bcam(phm->client))) {
memset(&m_key, 0, sizeof(m_key));
aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->mm, key, &m_key);
masked_key = &m_key;
} else {
masked_key = key;
}
uint16_t fingerprint = 0;
if (is_drambcam) {
aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaafrom_hash_value(phm, hash_value, &fingerprint);
} else {
hash_t *hash = (hash_t *) alloca(hash_size());
uint32_t bucket_hash;
aaaaaaa1aaa(hash, masked_key, phm);
bucket_hash = hash_calculate_bucket(hash);
aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = aaa1aaaadjust_list(phm, bucket_hash);
}
entry.bucket = hash_value;
entry.aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa = *response;
entry.key = *masked_key;
entry.narrow = narrow_key;
entry.fingerprint = fingerprint;
uint8_t narrow = 0;
uint8_t narrow_element = 0;
const bool mixed_mode = client_is_mixed_mode(phm->client);
assert((mixed_mode && narrow_key) || (!narrow_key));
const bool overwritten = client_is_overwritten(phm->client, phm,
aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
if (overwritten)
return false;
if (narrow_key) {
narrow = 1;
bool wide_valid, narrow1_valid, narrow0_valid;
aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaabits(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, &wide_valid,
&narrow1_valid, &narrow0_valid);
if (wide_valid)
return false;
if (!pack_narrow && (narrow0_valid || narrow1_valid))
return false;
if (narrow0_valid && narrow1_valid) {
return false;
}
if (narrow0_valid) {
narrow_element = 1;
}
}
else {
if (mixed_mode) {
bool wide_valid, narrow1_valid, narrow0_valid;
aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaabits(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, &wide_valid,
&narrow1_valid, &narrow0_valid);
if ((wide_valid || narrow0_valid || narrow1_valid))
return false;
} else if (!aaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa)) {
return false;
}
}
entry.list = aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa;
entry.narrow = narrow;
entry.narrow_element = narrow_element;
aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaabcam(phm->km, &entry);
phm->number_of_keys++;
return true;
}
bool aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(aaa1aaat *phm, const aaaaaaaaaaaaa1aaat *key, aaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaat execute,
bool match_prio, aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *comp_prio, uint64_t hash_value,
bool narrow_key, int *verify)
{
assert(
((execute != aaa1aaaREAD) && (verify == NULL)) || (execute == aaa1aaaREAD));
uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa;
const aaaaaaaaaaaaa1aaat *masked_key;
aaaaaaaaaaaaa1aaat m_key;
const bool is_drambcam = client_is_drambcam(phm->client);
const bool is_bcam = client_is_bcam(phm->client);
if (!(is_drambcam || is_bcam)) {
memset(&m_key, 0, sizeof(m_key));
aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->mm, key, &m_key);
masked_key = &m_key;
} else {
masked_key = key;
}
uint16_t fingerprint = 0;
if (is_drambcam) {
aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaafrom_hash_value(phm, hash_value, &fingerprint);
} else {
hash_t *hash = (hash_t *) alloca(hash_size());
aaaaaaa1aaa(hash, masked_key, phm);
const uint32_t bucket_hash = hash_calculate_bucket(hash);
aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = aaa1aaaadjust_list(phm, bucket_hash);
}
cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat entry = { 0 };
uint8_t max_elements = 1;
uint8_t narrow = 0;
const bool mixed_mode = client_is_mixed_mode(phm->client);
assert(!narrow_key || (narrow_key && mixed_mode));
if (mixed_mode) {
if (narrow_key) {
max_elements = 2;
narrow = 1;
}
}
for (uint8_t element = 0; element < max_elements; element++) {
if (aaaa1aaaread_element_bcam(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, &entry,
NULL, narrow, element)) {
const aaaaaaaaaaaaa1aaat *stored_key = &entry.key;
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *prio_ptr = &entry.aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa;
aaaaaaaaaaaaa1aaat m_stored_key;
const aaaaaaaaaaaaa1aaat *masked_stored_key;
if (is_bcam || is_drambcam) {
masked_stored_key = stored_key;
} else {
memset(&m_stored_key, 0, sizeof(m_stored_key));
aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->mm, stored_key, &m_stored_key);
masked_stored_key = &m_stored_key;
}
uint8_t j;
for (j = 0; j < CAM_MAX_KEY_WIDTH_MEM; j++) {
if (masked_stored_key->word[j] != masked_key->word[j]) {
break;
}
}
if (j != CAM_MAX_KEY_WIDTH_MEM)
continue;
assert(comp_prio != NULL);
if (match_prio) {
const int prio_memcmp_rc = memcmp(prio_ptr, comp_prio,
sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
if (prio_memcmp_rc != 0)
continue;
}
if (execute == aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaa) {
aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaelement(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, narrow, element);
assert(phm->number_of_keys > 0);
phm->number_of_keys--;
return true;
} else if (execute == aaa1aaaREAD) {
if (match_prio == false) {
*comp_prio = *prio_ptr;
}
if (verify) {
const bool success = aaaa1aaaread_element_bcam(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa,
&entry, verify, narrow, element);
assert(success);
}
return true;
} else if (execute == aaa1bbbbbbbbbbbbbbbbbbbb3aaa) {
aaaa1bbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, comp_prio, narrow,
element);
return true;
}
assert(false);
}
}
return false;
}
bool aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup(const aaa1aaat *phm, const aaaaaaaaaaaaa1aaat *key, aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *out_prio_resp, bool narrow_key)
{
assert(!client_is_tcam(phm->client));
uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa;
const aaaaaaaaaaaaa1aaat *masked_key;
aaaaaaaaaaaaa1aaat m_key;
const bool is_drambcam = client_is_drambcam(phm->client);
const bool is_bcam = client_is_bcam(phm->client);
assert(!(is_drambcam || is_bcam));
memset(&m_key, 0, sizeof(m_key));
aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->mm, key, &m_key);
masked_key = &m_key;
hash_t *hash = (hash_t *) alloca(hash_size());
aaaaaaa1aaa(hash, masked_key, phm);
const uint32_t bucket_hash = hash_calculate_bucket(hash);
aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = aaa1aaaadjust_list(phm, bucket_hash);
cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat entry = { 0 };
const bool mixed_mode = client_is_mixed_mode(phm->client);
assert(!narrow_key || (narrow_key && mixed_mode));
uint8_t max_elements = 1;
uint8_t narrow = 0;
if (mixed_mode) {
if (narrow_key) {
max_elements = 2;
narrow = 1;
}
}
for (uint8_t element = 0; element < max_elements; element++) {
if (aaaa1aaaread_element_bcam(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, &entry,
NULL, narrow, element)) {
const aaaaaaaaaaaaa1aaat *stored_key = &entry.key;
aaaaaaaaaaaaa1aaat m_stored_key;
memset(&m_stored_key, 0, sizeof(m_stored_key));
aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->mm, stored_key, &m_stored_key);
uint8_t j;
for (j = 0; j < CAM_MAX_KEY_WIDTH_MEM; j++) {
if (m_stored_key.word[j] != masked_key->word[j]) {
break;
}
}
if (j != CAM_MAX_KEY_WIDTH_MEM)
continue;
*out_prio_resp = entry.aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa;
return true;
} 
}
return false;
}
bool aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaabcam(aaa1aaat *phm, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response_mask,
uint32_t *start_value,
aaaaaaaaaaaaa1aaat *aaaaaaaaa1aaa,
aaaaaaaaaaaaa1aaat *ternary_mask, uint8_t *narrow,
uint8_t *narrow_element, bool narrow_key, int *verify)
{
assert(!client_is_tcam(phm->client));
uint64_t bucket;
const uint32_t number_of_keys = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(phm);
if (number_of_keys == 0) {
return false;
}
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat priority;
assert((narrow_key && (*narrow != 0)) || !narrow_key);
while (aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaand_read_element_bcam(phm, start_value, aaaaaaaaa1aaa,
ternary_mask, &priority, &bucket, NULL, narrow,
narrow_element)) {
assert((narrow_key && (*narrow != 0)) || !narrow_key);
bool match = true;
for (uint16_t i = 0; i < CAM_MAX_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaMEM; i++) {
if ((priority.word[i] & response_mask->word[i]) != (response->word[i] & response_mask->word[i])) {
match = false;
}
}
if (match) {
if (verify) {
const bool success = aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaand_read_element_bcam(phm, start_value,
aaaaaaaaa1aaa, ternary_mask, &priority, &bucket,
verify, narrow, narrow_element);
assert(success);
}
return true;
}
if ((*narrow != 0) && ((*narrow_element) == 0) && narrow_key) {
*narrow_element = 1;
} else {
(*start_value)++;
*narrow_element = 0;
}
}
return false;
}
aaaa1aaat* aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaakm(const aaa1aaat *phm)
{
return phm->km;
}
#define INVALID 0
#define FUNCTION 1
#define POINTER 2
typedef struct {
uint8_t mode;
union {
uint32_t function_value;
uint32_t pointer;
uint32_t invalid;
} fp;
} bucket_control_t;
typedef struct {
uint8_t number_of_keys;
bucket_control_t bucket_control;
} bucket_t;
struct aa1aaat {
bucket_t *bucket;
uint16_t unit;
uint8_t slot_number;
client_t *client;
};
size_t aa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa(void)
{
return sizeof(aa1aaat);
}
size_t aa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaabaaaaaaaaaa4aaa(void) {
return sizeof(bucket_t);
}
static void flush_bucket(const aa1aaat *bm, uint32_t bucket)
{
assert(client_is_tcam(bm->client));
const uint32_t num_lists = client_get_num_lists(bm->client);
const uint8_t num_slots = client_get_num_slots(bm->client);
const uint32_t physical_lists = num_slots * num_lists;
const uint8_t log2_physical_lists = CLOG2(physical_lists);
const uint32_t num_buckets = aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO * num_lists;
assert(bucket < num_buckets);
const uint32_t adjusted_bucket = num_buckets * bm->slot_number + bucket;
assert(adjusted_bucket < (physical_lists * aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO));
const uint32_t base = aaaaaa1aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa + bm->unit * aaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa;
const uint32_t address = base + (adjusted_bucket / 4) * aaaaaa1aaaaa1aaaWORD;
uint64_t data = 0;
for (uint8_t i = 0; i < 4; i++) {
uint32_t sub_bucket = (bucket / 4) * 4 + i;
uint8_t sub_word_pos = i * 16;
if (bm->bucket[sub_bucket].bucket_control.mode == POINTER) {
data = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa64(data, bm->bucket[sub_bucket].bucket_control.fp.pointer,
sub_word_pos, log2_physical_lists);
} else if (bm->bucket[sub_bucket].bucket_control.mode == FUNCTION) {
data = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa64(data, bm->bucket[sub_bucket].bucket_control.fp.function_value,
sub_word_pos, aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaS);
} else if (bm->bucket[sub_bucket].bucket_control.mode == INVALID) {
} else {
assert(false);
}
data = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa64(data, bm->bucket[sub_bucket].bucket_control.mode,
sub_word_pos + log2_physical_lists, 2);
}
client_hw_write(bm->client, address, data);
}
void aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaa(aa1aaat *bm)
{
assert(client_is_tcam(bm->client));
const uint32_t end_bucket = client_get_num_lists(bm->client) * aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO;
for (uint32_t j = 0; j < end_bucket; j++) {
bm->bucket[j].bucket_control.mode = INVALID;
bm->bucket[j].bucket_control.fp.invalid = 0;
bm->bucket[j].number_of_keys = 0;
}
if (!(client_get_debug_flags(bm->client) & CAM_DEBUG_SKIP_MEM_INIT)) {
for (uint16_t j = 0; j < end_bucket; j += 4) {
flush_bucket(bm, j);
}
}
}
bool aa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(aa1aaat *bm, client_t *client, uint16_t unit, uint8_t slot_number, cam_malloc_func malloc_function)
{
assert(client_is_tcam(client));
assert(unit < aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaS);
bm->bucket = malloc_function(aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO * client_get_num_lists(client) * sizeof(bucket_t));
if (bm->bucket == NULL)
{
return false;
}
bm->client = client;
bm->unit = unit;
bm->slot_number = slot_number;
aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaa(bm);
return true;
}
void aa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(aa1aaat *bm, cam_free_func free_function)
{
if (bm == NULL) {
return;
}
if (bm->bucket != NULL) {
free_function(bm->bucket);
}
free_function(bm);
}
bool aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(const aa1aaat *bm, uint32_t bucket)
{
assert(client_is_tcam(bm->client));
assert(bucket < aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO * client_get_num_lists(bm->client));
return (bm->bucket[bucket].bucket_control.mode == INVALID);
}
bool aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(const aa1aaat *bm, uint32_t bucket)
{
assert(client_is_tcam(bm->client));
assert(bucket < aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO * client_get_num_lists(bm->client));
return ((bm->bucket[bucket].bucket_control.mode == POINTER)); 
}
bool aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(const aa1aaat *bm, uint32_t bucket)
{
assert(client_is_tcam(bm->client));
assert(bucket < aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO * client_get_num_lists(bm->client));
return (bm->bucket[bucket].bucket_control.mode == FUNCTION);
}
uint8_t aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(const aa1aaat *bm, uint32_t bucket)
{
assert(client_is_tcam(bm->client));
assert(bucket < aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO * client_get_num_lists(bm->client));
return bm->bucket[bucket].number_of_keys;
}
uint32_t aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(const aa1aaat *bm, uint32_t bucket)
{
assert(client_is_tcam(bm->client));
assert(bucket < aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO * client_get_num_lists(bm->client));
assert(true == aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(bm, bucket));
return bm->bucket[bucket].bucket_control.fp.pointer;
}
uint8_t aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(const aa1aaat *bm, uint32_t bucket)
{
assert(client_is_tcam(bm->client));
assert(bucket < aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO * client_get_num_lists(bm->client));
assert(true == aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(bm, bucket));
return bm->bucket[bucket].bucket_control.fp.function_value;
}
void aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaapointer(aa1aaat *bm, uint32_t bucket, uint32_t new_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa)
{
assert(client_is_tcam(bm->client));
assert(bucket < aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO * client_get_num_lists(bm->client));
assert(aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(bm, bucket));
bm->bucket[bucket].bucket_control.mode = POINTER;
bm->bucket[bucket].bucket_control.fp.pointer = new_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa;
flush_bucket(bm, bucket);
}
void aa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(aa1aaat *bm, uint32_t bucket, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa)
{
assert(client_is_tcam(bm->client));
assert(bucket < aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO * client_get_num_lists(bm->client));
assert(aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(bm, bucket) == true);
bm->bucket[bucket].bucket_control.mode = POINTER;
bm->bucket[bucket].bucket_control.fp.pointer = aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa;
flush_bucket(bm, bucket);
bm->bucket[bucket].number_of_keys = 1;
}
void aa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaanext_key(aa1aaat *bm, uint32_t bucket)
{
assert(client_is_tcam(bm->client));
assert(bucket < aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO * client_get_num_lists(bm->client));
assert(aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(bm, bucket) == false);
bm->bucket[bucket].number_of_keys++;
}
void aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(aa1aaat *bm, uint32_t bucket)
{
assert(client_is_tcam(bm->client));
assert(bucket < aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO * client_get_num_lists(bm->client));
assert(aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(bm, bucket) == false);
bm->bucket[bucket].number_of_keys--;
if (bm->bucket[bucket].number_of_keys == 0) {
bm->bucket[bucket].bucket_control.mode = INVALID;
bm->bucket[bucket].bucket_control.fp.invalid = 0;
}
}
void aa1bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaapointer(aa1aaat *bm, uint32_t bucket, uint8_t function)
{
assert(client_is_tcam(bm->client));
assert(function < aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaS);
assert(bucket < aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO * client_get_num_lists(bm->client));
bm->bucket[bucket].bucket_control.fp.function_value = function;
bm->bucket[bucket].bucket_control.mode = FUNCTION;
flush_bucket(bm, bucket);
}
void aa1bbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaand_flush(aa1aaat *target_bm, aa1aaat *source_bm, uint32_t bucket)
{
assert(client_is_tcam(source_bm->client));
target_bm->bucket[bucket] = source_bm->bucket[bucket];
flush_bucket(target_bm, bucket);
}
void aa1bbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaall(const aa1aaat *bm)
{
assert(client_is_tcam(bm->client));
const uint16_t end_bucket = client_get_num_lists(bm->client) * aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO;
for (uint16_t j = 0; j < end_bucket; j += 4) {
flush_bucket(bm, j);
}
}
static void dummy_wr_function(void *ctx, uint32_t address, uint32_t data)
{
(void) ctx;
(void) address;
(void) data;
}
static void dummy_rd_function(void *ctx, uint32_t address, uint32_t *data)
{
(void) ctx;
(void) address;
(void) data;
}
static void default_error_print_function(void *inst_ctx, char *message)
{
(void) inst_ctx; 
   fprintf(stderr, "** Error: %s\n", message);
}
static void default_info_print_function(void *inst_ctx, char *message)
{
(void) inst_ctx; 
   fprintf(stdout, "** Info:  %s\n", message);
}
int cam_arg_create(struct cam_arg_t **out_cam_arg)
{
struct cam_arg_t *cam_arg;
cam_arg = malloc(cam_arg_size());
if (cam_arg == NULL)
return CAM_ERROR_NOMEM;
cam_arg_init(cam_arg);
*out_cam_arg = cam_arg;
return 0;
}
void cam_arg_init(struct cam_arg_t* out_cam_arg)
{
int i;
memset(out_cam_arg, 0, cam_arg_size());
out_cam_arg->ram_freq = 600.0;
out_cam_arg->lookup_interface_freq = 15.0;
out_cam_arg->engine_lookup_rate = 15.0;
for(i = 0; i < MAX_HW_BLOCKS; i++) {
out_cam_arg->io[i].hw_read_function = &dummy_rd_function;
out_cam_arg->io[i].hw_write_function = &dummy_wr_function;
}
out_cam_arg->priority_width = -1;
out_cam_arg->mem_type = AUTO;
out_cam_arg->max_num_brams = 720;
out_cam_arg->max_num_urams = 320;
out_cam_arg->max_macro_height = 4;
out_cam_arg->versal = false;
out_cam_arg->r_size = -1;
out_cam_arg->segment_ctx.segment = -1;
out_cam_arg->vc_seg_map.vcid = -1;
out_cam_arg->error_print_function = &default_error_print_function;
out_cam_arg->info_print_function = &default_info_print_function;
out_cam_arg->malloc_function = malloc;
out_cam_arg->posix_memalign_function = NULL;
out_cam_arg->realloc_function = realloc;
out_cam_arg->calloc_function = calloc;
out_cam_arg->free_function = free;
out_cam_arg->channel_width = -1;
out_cam_arg->num_phys_banks = -1;
out_cam_arg->replication = -1;
out_cam_arg->update_mode = CAM_UPDATE_SOFTWARE;
out_cam_arg->max_tcam_heap_size = UINT32_MAX;
}
size_t cam_arg_size(void)
{
return sizeof(cam_arg_t);
}
void cam_arg_destroy(struct cam_arg_t *cam_arg)
{
free(cam_arg);
}
int cam_arg_set_format(struct cam_arg_t *cam_arg, char *format)
{
if ((strlen(format) + 1) > sizeof(cam_arg->format))
return CAM_ERROR_FORMAT_SYNTAX;
strcpy(cam_arg->format, format);
return 0;
}
void cam_arg_set_inst_ctx(struct cam_arg_t *cam_arg, void *inst_ctx)
{
cam_arg->segment_ctx.ctx = inst_ctx;
}
void cam_arg_set_hw_write_function(struct cam_arg_t *cam_arg, void (*hw_write_function)(void*, uint32_t, uint32_t))
{
cam_arg->io[0].hw_write_function = hw_write_function;
}
void cam_arg_set_hw_read_function(struct cam_arg_t *cam_arg, void (*hw_read_function)(void*, uint32_t, uint32_t*))
{
cam_arg->io[0].hw_read_function = hw_read_function;
}
int cam_arg_set_hw_io(cam_arg_t *cam_arg,
unsigned hw_block,
void (*hw_write_function)(void*, uint32_t, uint32_t),
void (*hw_read_function)(void*, uint32_t, uint32_t*))
{
if(hw_block > MAX_HW_BLOCKS)
return CAM_ERROR_INVALID_ARG;
cam_arg->io[hw_block].hw_write_function = hw_write_function;
cam_arg->io[hw_block].hw_read_function = hw_read_function;
return 0;
}
void cam_arg_set_hw_write_sequence_functions(cam_arg_t *cam_arg, void (*start_function)(void*),
void (*end_function)(void*))
{
cam_arg->hw_write_start_sequence_function = start_function;
cam_arg->hw_write_end_sequence_function = end_function;
}
void cam_arg_set_flow_control(struct cam_arg_t *cam_arg, bool flow_control)
{
cam_arg->flow_control = flow_control;
}
void cam_arg_set_aging(struct cam_arg_t *cam_arg, bool aging)
{
cam_arg->aging = aging;
}
void cam_arg_set_num_entries(struct cam_arg_t *cam_arg, uint32_t num_entries)
{
cam_arg->num_entries = num_entries;
}
void cam_arg_set_ram_freq(struct cam_arg_t *cam_arg, float freq)
{
cam_arg->ram_freq = freq;
}
void cam_arg_set_lookup_interface_freq(struct cam_arg_t *cam_arg, float freq)
{
cam_arg->lookup_interface_freq = freq;
}
void cam_arg_set_engine_lookup_rate(struct cam_arg_t *cam_arg, float lookup_rate)
{
cam_arg->engine_lookup_rate = lookup_rate;
}
void cam_arg_set_response_width(struct cam_arg_t *cam_arg, uint16_t response_width)
{
cam_arg->response_width = response_width;
}
void cam_arg_set_key_width(struct cam_arg_t *cam_arg, uint16_t key_width)
{
cam_arg->key_width = key_width;
}
void cam_arg_set_fingerprint_width(struct cam_arg_t *cam_arg, uint16_t fingerprint_width)
{
cam_arg->fingerprint_width = fingerprint_width;
}
void cam_arg_set_narrow_key_width(struct cam_arg_t *cam_arg, uint16_t narrow_key_width)
{
cam_arg->narrow_key_width = narrow_key_width;
}
void cam_arg_set_num_masks(struct cam_arg_t *cam_arg, uint8_t num_masks)
{
cam_arg->num_masks = num_masks;
}
void cam_arg_force_prio_width(struct cam_arg_t *cam_arg, uint8_t prio_width)
{
cam_arg->priority_width = prio_width;
}
void cam_arg_force_num_units(struct cam_arg_t *cam_arg, uint16_t num_units)
{
cam_arg->num_units = num_units;
}
void camp_arg_force_num_slots(struct cam_arg_t *cam_arg, uint8_t num_slots)
{
cam_arg->num_slots = num_slots;
}
void cam_arg_force_num_pcs(struct cam_arg_t *cam_arg, unsigned num_pcs)
{
cam_arg->num_pcs = num_pcs;
}
void cam_arg_set_generation_number_granularity(struct cam_arg_t *cam_arg, uint16_t granularity) {
cam_arg->generation_number_granularity = granularity;
}
void cam_arg_force_mem_type(struct cam_arg_t *cam_arg, bool uram)
{
bool lutram = false;
if (uram)
cam_arg->mem_type = URAM;
else if (!uram && lutram)
cam_arg->mem_type = LRAM;
else
cam_arg->mem_type = BRAM;
}
void cam_arg_set_max_num_brams(struct cam_arg_t *cam_arg, uint16_t max_num_brams)
{
cam_arg->max_num_brams = max_num_brams;
}
void cam_arg_set_max_num_urams(struct cam_arg_t *cam_arg, uint16_t max_num_urams)
{
cam_arg->max_num_urams = max_num_urams;
}
void cam_arg_set_max_macro_height(struct cam_arg_t *cam_arg, uint8_t max_macro_height)
{
cam_arg->max_macro_height = max_macro_height;
}
void cam_arg_set_device_arch(struct cam_arg_t *cam_arg, bool versal)
{
cam_arg->versal = versal;
}
void cam_arg_force_hbm(struct cam_arg_t *cam_arg)
{
cam_arg->hbm = true;
}
void cam_arg_set_debug_flags(cam_arg_t *cam_arg, uint32_t debug_flags) {
cam_arg->debug_flags = debug_flags;
}
void cam_arg_set_optimization_flags(cam_arg_t *cam_arg, uint32_t optimization_flags)
{
cam_arg->optimization_flags = optimization_flags;
}
void cam_arg_set_error_print_function(struct cam_arg_t *cam_arg, void (*error_print_function)(void*, char*))
{
cam_arg->error_print_function = error_print_function;
}
void cam_arg_set_info_print_function(struct cam_arg_t *cam_arg, void (*info_print_function)(void*, char*))
{
cam_arg->info_print_function = info_print_function;
}
void cam_arg_set_malloc_function(struct cam_arg_t* cam_arg, void* (*malloc_function)(size_t size))
{
cam_arg->malloc_function = malloc_function;
}
void cam_arg_set_posix_memalign_function(struct cam_arg_t* cam_arg,
int (*posix_memalign_function)(void** ptr, size_t align_size, size_t num)) {
cam_arg->posix_memalign_function = posix_memalign_function;
}
void cam_arg_set_realloc_function(struct cam_arg_t* cam_arg,
void* (*realloc_function)(void *ptr, size_t size)) {
cam_arg->realloc_function = realloc_function;
}
void cam_arg_set_calloc_function(struct cam_arg_t* cam_arg, void* (*calloc_function)(size_t num, size_t size))
{
cam_arg->calloc_function = calloc_function;
}
void cam_arg_set_free_function(struct cam_arg_t* cam_arg, void (*free_function)(void* ptr))
{
cam_arg->free_function = free_function;
}
void camp_arg_set_ram_size(struct cam_arg_t *cam_arg, uint32_t size)
{
cam_arg->public_r_size = false;
cam_arg->r_size = size;
}
void cam_arg_set_ram_size(struct cam_arg_t *cam_arg, uint32_t size)
{
cam_arg->public_r_size = true;
cam_arg->r_size = size;
}
void cam_arg_set_channel_width(struct cam_arg_t *cam_arg, uint16_t width) {
cam_arg->channel_width = width;
}
void cam_arg_set_replication(struct cam_arg_t *cam_arg, unsigned replication) {
cam_arg->replication = replication;
}
void cam_arg_set_update_mode(struct cam_arg_t *cam_arg, enum cam_arg_update_mode update_mode) {
cam_arg->update_mode = update_mode;
}
void cam_arg_calc_heap_size(struct cam_arg_t *cam_arg, bool calculate) {
cam_arg->calc_heap_size = calculate;
}
void cam_arg_set_num_banks(struct cam_arg_t *cam_arg, uint8_t num_banks) {
cam_arg->num_phys_banks = num_banks;
}
void cam_arg_set_default_response(struct cam_arg_t *cam_arg, const uint8_t *default_response)
{
memset(cam_arg->default_response, 0, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
cam_copy_bits(cam_arg->default_response, default_response, cam_arg->response_width);
}
void cam_arg_set_narrow_default_response(struct cam_arg_t *cam_arg, const uint8_t *narrow_default_response)
{
memset(cam_arg->narrow_default_response, 0, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
cam_copy_bits(cam_arg->narrow_default_response, narrow_default_response, cam_arg->response_width);
}
void cam_arg_set_max_hw_writes(struct cam_arg_t *cam_arg, uint16_t max_hw_writes)
{
cam_arg->max_hw_writes = max_hw_writes;
}
void camp_arg_set_seg(struct cam_arg_t *cam_arg, uint16_t segment)
{
assert(segment < CAM_MAX_VC_SEGMENTS); 
cam_arg->segment_ctx.segment = segment;
}
void camp_arg_set_vcid(struct cam_arg_t *cam_arg, uint8_t vcid)
{
cam_arg->vc_id = vcid;
}
void cam_arg_set_vcid(struct cam_arg_t* cam_arg, uint8_t vcid)
{
cam_arg->vc_seg_map.vcid = vcid;
}
void cam_arg_enable_options(struct cam_arg_t *cam_arg)
{
cam_arg->options = true;
}
void cam_arg_set_seg(struct cam_arg_t* cam_arg, uint16_t segment_id)
{
uint32_t byte = segment_id / 8;
uint32_t bit = segment_id % 8;
if (byte < CAM_MAX_VC_SEGMENTS_MEM)
{
cam_arg->vc_seg_map.bit_map[byte] |= cam_arg->vc_seg_map.bit_map[byte] | (1 << bit);
}
}
void cam_arg_force_dram(struct cam_arg_t *cam_arg)
{
cam_arg->ddr_dram = true;
}
void cam_arg_force_asic_ram(struct cam_arg_t *cam_arg)
{
cam_arg->asic_ram = true;
}
void cam_arg_set_hash_function(struct cam_arg_t *cam_arg, uint8_t function) {
cam_arg->hash_function = function;
}
void cam_arg_set_siphash_key(struct cam_arg_t *cam_arg, uint64_t k0, uint64_t k1) {
cam_arg->hash_k0 = k0;
cam_arg->hash_k1 = k1;
}
size_t cam_options_size(void)
{
return sizeof(cam_options_t);
}
void cam_options_init(cam_options_t *options)
{
memset(options, 0, cam_options_size());
}
int cam_options_create(struct cam_options_t** out_options)
{
struct cam_options_t* cam_options;
cam_options = malloc(cam_options_size());
if (cam_options == NULL)
return CAM_ERROR_NOMEM;
cam_options_init(cam_options);
*out_options = cam_options;
return 0;
}
void cam_options_destroy(struct cam_options_t *options)
{
free(options);
}
void cam_options_set_narrow_key(struct cam_options_t *options, bool narrow)
{
options->narrow = narrow;
}
void cam_options_set_precomputed_hash_value(struct cam_options_t* options, uint8_t hash_value[32])
{
options->precomp_hash = true;
memcpy(&options->hash_value, hash_value, CAM_HASH_VAL_SIZE_IN_BYTES);
}
void cam_options_clear_precomputed_hash_value(struct cam_options_t *options)
{
options->precomp_hash = false;
}
void cam_options_set_single_segment_search(struct cam_options_t* options, uint8_t segment) {
options->search_single_segment = true;
options->single_segment = segment;
}
void cam_options_clear_single_segment_search(struct cam_options_t *options) {
options->search_single_segment = false;
}
void cam_options_set_debug_flags(struct cam_options_t* options, uint32_t debug_flags) {
options->override_debug_flags = true;
options->debug_flags = debug_flags;
}
void cam_options_clear_debug_flags(struct cam_options_t *options) {
options->override_debug_flags = false;
}
const char *cam_error_string(int error_code)
{
   const char *err_txt[CAM_ERROR_FATAL_BASE_END + 1] = { "UNDEFINED ERROR" };
   err_txt[CAM_ERROR_FULL] = "CAM_ERROR_FULL";
   err_txt[CAM_ERROR_NO_OPEN] = "CAM_ERROR_NO_OPEN";
   err_txt[CAM_ERROR_INVALID_ARG] = "CAM_ERROR_INVALID_ARG";
   err_txt[CAM_ERROR_WRONG_KEY_WIDTH] = "CAM_ERROR_WRONG_KEY_WIDTH";
   err_txt[CAM_ERROR_TOO_MANY_INSTANCES] = "CAM_ERROR_TOO_MANY_INSTANCES";
   err_txt[CAM_ERROR_WRONG_PRIO_WIDTH] = "CAM_ERROR_WRONG_PRIO_WIDTH";
   err_txt[CAM_ERROR_WRONG_MAX] = "CAM_ERROR_WRONG_MAX";
   err_txt[CAM_ERROR_DUPLICATE_FOUND] = "CAM_ERROR_DUPLICATE_FOUND";
   err_txt[CAM_ERROR_WRONG_PREFIX] = "CAM_ERROR_WRONG_PREFIX";
   err_txt[CAM_ERROR_WRONG_PREFIX_MASK] = "CAM_ERROR_WRONG_PREFIX_MASK";
   err_txt[CAM_ERROR_WRONG_RANGE] = "CAM_ERROR_WRONG_RANGE";
   err_txt[CAM_ERROR_WRONG_RANGE_MASK] = "CAM_ERROR_WRONG_RANGE_MASK";
   err_txt[CAM_ERROR_WRONG_BIT_FIELD_MASK] = "CAM_ERROR_WRONG_BIT_FIELD_MASK";
   err_txt[CAM_ERROR_WRONG_CONST_FIELD_MASK] = "CAM_ERROR_WRONG_CONST_FIELD_MASK";
   err_txt[CAM_ERROR_WRONG_UNUSED_FIELD_MASK] = "CAM_ERROR_WRONG_UNUSED_FIELD_MASK";
   err_txt[CAM_ERROR_INVALID_TERNARY_FIELD_LEN] = "CAM_ERROR_INVALID_TERNARY_FIELD_LEN";
   err_txt[CAM_ERROR_TOO_HIGH_FREQUENCY] = "CAM_ERROR_TOO_HIGH_FREQUENCY";
   err_txt[CAM_ERROR_KEY_NOT_FOUND] = "CAM_NOT_FOUND";
   err_txt[CAM_ERROR_WRONG_MIN] = "CAM_ERROR_WRONG_MIN";
   err_txt[CAM_ERROR_WRONG_PRIO] = "CAM_ERROR_WRONG_PRIO";
   err_txt[CAM_ERROR_WRONG_LIST_LENGTH] = "CAM_ERROR_WRONG_LIST_LENGTH";
   err_txt[CAM_ERROR_WRONG_NUMBER_OF_SLOTS] = "CAM_ERROR_WRONG_NUMBER_OF_SLOTS";
   err_txt[CAM_ERROR_INVALID_MEM_TYPE] = "CAM_ERROR_INVALID_MEM_TYPE";
   err_txt[CAM_ERROR_WRONG_TERNARY_MASK] = "CAM_ERROR_WRONG_TERNARY_MASK";
   err_txt[CAM_ERROR_MASKED_KEY_BIT_IS_SET] = "CAM_ERROR_MASKED_KEY_BIT_IS_SET";
   err_txt[CAM_ERROR_INVALID_MODE] = "CAM_ERROR_INVALID_MODE";
   err_txt[CAM_ERROR_WRONG_RESPONSE_WIDTH] = "CAM_ERROR_WRONG_RESPONSE_SIZE";
   err_txt[CAM_ERROR_FORMAT_SYNTAX] = "CAM_ERROR_FORMAT_SYNTAX";
   err_txt[CAM_ERROR_TOO_MANY_FIELDS] = "CAM_ERROR_TOO_MANY_FIELDS";
   err_txt[CAM_ERROR_TOO_MANY_RANGES] = "CAM_ERROR_TOO_MANY_RANGES";
   err_txt[CAM_ERROR_INVALID_RANGE_LEN] = "CAM_ERROR_INVALID_RANGE_LEN";
   err_txt[CAM_ERROR_INVALID_RANGE_START] = "CAM_ERROR_INVALID_RANGE_START";
   err_txt[CAM_ERROR_INVALID_PREFIX_LEN] = "CAM_ERROR_INVALID_PREFIX_LEN";
   err_txt[CAM_ERROR_INVALID_PREFIX_START] = "CAM_ERROR_INVALID_PREFIX_START";
   err_txt[CAM_ERROR_INVALID_PREFIX_KEY] = "CAM_ERROR_INVALID_PREFIX_KEY";
   err_txt[CAM_ERROR_INVALID_BIT_FIELD_LEN] = "CAM_ERROR_INVALID_BIT_FIELD_LEN";
   err_txt[CAM_ERROR_INVALID_BIT_FIELD_START] = "CAM_ERROR_INVALID_BIT_FIELD_START";
   err_txt[CAM_ERROR_INVALID_CONST_FIELD_LEN] = "CAM_ERROR_INVALID_CONST_FIELD_LEN";
   err_txt[CAM_ERROR_INVALID_CONST_FIELD_START] = "CAM_ERROR_INVALID_CONST_FIELD_START";
   err_txt[CAM_ERROR_INVALID_UNUSED_FIELD_LEN] = "CAM_ERROR_INVALID_UNUSED_FIELD_LEN";
   err_txt[CAM_ERROR_INVALID_UNUSED_FIELD_START] = "CAM_ERROR_INVALID_UNUSED_FIELD_START";
   err_txt[CAM_ERROR_MAX_KEY_LEN_EXCEED] = "CAM_ERROR_MAX_KEY_LEN_EXCEED";
   err_txt[CAM_ERROR_INVALID_aaaaaaaaaaaaaa1aaaINDEX_WIDTH] = "CAM ERROR_INVALID_aaaaaaaaaaaaaa1aaaINDEX_WIDTH";
   err_txt[CAM_ERROR_TOO_MANY_UNITS] = "CAM ERROR_TOO_MANY_UNITS";
   err_txt[CAM_ERROR_NO_MASK] = "CAM_ERROR_NO_MASK";
   err_txt[CAM_ERROR_INVALID_MEMORY_WIDTH] = "CAM_ERROR_INVALID_MEMORY_WIDTH";
   err_txt[CAM_ERROR_NOMEM] = "CAM_ERROR_NOMEM";
   err_txt[CAM_ERROR_MALLOC_FAILED] = "CAM_ERROR_MALLOC_FAILED";
   err_txt[CAM_ERROR_UNSUPPORTED_COMMAND]    = "CAM_ERROR_UNSUPPORTED_COMMAND";
   err_txt[CAM_ERROR_ENVIRONMENT]            = "CAM_ERROR_ENVIRONMENT";
   err_txt[CAM_ERROR_UNSUPPORTED_CAM_TYPE]   = "CAM_ERROR_UNSUPPORTED_CAM_TYPE";
   err_txt[CAM_ERROR_NULL_POINTER]           = "CAM_ERROR_NULL_POINTER";
   err_txt[CAM_ERROR_TOO_MANY_PCS]           = "CAM_ERROR_TOO_MANY_PCS";
   err_txt[CAM_ERROR_CONFIGURATION]          = "CAM_ERROR_CONFIGURATION";
   err_txt[CAM_ERROR_ENVIRONMENT_FSMBUSY]    = "CAM_ERROR_ENVIRONMENT_FSMBUSY";
   err_txt[CAM_ERROR_ENVIRONMENT_POLLED_OUT] = "CAM_ERROR_ENVIRONMENT_POLLED_OUT";
   err_txt[CAM_ERROR_SEGMENT_aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaZERO]     = "CAM_ERROR_SEGMENT_aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaZERO";
   err_txt[CAM_ERROR_VC_UNSUPPORTED_COMMAND] = "CAM_ERROR_VC_UNSUPPORTED_COMMAND";
   err_txt[CAM_ERROR_WRONG_VIRTUAL_CAM_ID]   = "CAM_ERROR_WRONG_VIRTUAL_CAM_ID";
   err_txt[CAM_ERROR_WRONG_SEGMENT_NUMBER]   = "CAM_ERROR_WRONG_SEGMENT_NUMBER";
   err_txt[CAM_ERROR_TOO_MANY_RAMS]          = "CAM_ERROR_TOO_MANY_RAMS";
   err_txt[CAM_ERROR_FOUND_IN_SHADOW_BUT_NOT_IN_HW]= "CAM_ERROR_FOUND_IN_SHADOW_BUT_NOT_IN_HW";
   err_txt[CAM_ERROR_TOO_SMALL_HEAP]         = "CAM_ERROR_TOO_SMALL_HEAP";
   err_txt[CAM_ERROR_RAM_TOO_SMALL]          = "CAM_ERROR_RAM_TOO_SMALL";
   err_txt[CAM_ERROR_NOT_EMPTY]              = "CAM_ERROR_NOT_EMPTY";
   err_txt[CAM_ERROR_STATISTICS_NOT_AVAILABLE] = "CAM_ERROR_STATISTICS_NOT_AVAILABLE";
   err_txt[CAM_ERROR_TOO_MANY_ENTRIES]       = "CAM_ERROR_TOO_MANY_ENTRIES";
   err_txt[CAM_ERROR_FORMAT_COMPLEXITY]      = "CAM_ERROR_FORMAT_COMPLEXITY";
   err_txt[CAM_ERROR_INVALID_USER_PCS]       = "CAM_ERROR_INVALID_USER_PCS";
if (error_code < 0 || error_code > CAM_ERROR_FATAL_BASE_END) {
       return "UNDEFINED ERROR";
} else {
return err_txt[error_code];
}
}
void cam_print_error(int error_code)
{
const char *error_text = cam_error_string(error_code);
if (error_code >= CAM_ERROR_FATAL_BASE_START) {
       fprintf(stderr, "Fatal Error: %s (%d)\n", error_text, error_code);
} else {
       fprintf(stderr, "Error: %s (%d)\n", error_text, error_code);
}
}
void cam_mask_key(aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaa1aaat *mask)
{
for (uint8_t i = 0; i < CAM_MAX_KEY_WIDTH_MEM; i++) {
key->word[i] = key->word[i] & mask->word[i];
}
}
char *byte_arr_to_str(uint16_t bit_len, const uint8_t *src, void *(*malloc_function)(size_t))
{
assert(src != NULL);
uint16_t byte_len = (bit_len + 7) / 8;
uint8_t tailbits = bit_len % 8;
if (tailbits == 0)
tailbits = 8;
uint8_t tailmask = 0xff >> (8 - tailbits);
char *str = malloc_function(sizeof(char) * 500);
assert(str != NULL);
str[0] = '\0';
   sprintf(str + strlen(str), "0x");
for (int i = byte_len - 1; i >= 0; i--) {
if ((i == byte_len - 1) && (byte_len != (bit_len + 3) / 8)) {
           sprintf(str + strlen(str), "%1x", src[i] & tailmask);
} else {
           sprintf(str + strlen(str), "%02x", src[i] & tailmask);
}
tailmask = 0xff;
}
return str;
}
#ifndef COMP_BCAM_IP
#ifndef _aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaH_
#define _aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaH_
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaarelax_var_array {
uint8_t key[1];
};
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa;
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate_exact(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
void aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaparse_format(struct tcam *magg, const char *format);
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(aaaaaaaaaaaaa1aaat *exact_key, int indent);
#endif
#endif
#ifndef _CAM_LATENCY_H_
#define _CAM_LATENCY_H_
uint16_t cam_latency(cam_instance_type_t inst_type,
uint16_t num_physical_units,
uint8_t num_slots,
float lookup_rate,
float lookup_interface_freq,
float ram_freq,
uint16_t key_width,
uint16_t list_length,
uint16_t num_lists,
bool flow_control,
cam_mem_type_t mem_type,
bool versal,
bool virtual,
uint8_t max_macro_height,
bool asic);
uint16_t cam_pipeline_capacity(cam_instance_type_t instance_type,
uint16_t num_physical_units,
uint8_t num_slots,
float lookup_rate,
float lookup_interface_freq,
float ram_freq,
uint16_t key_width,
uint16_t list_length,
uint16_t num_lists,
bool flow_control,
cam_mem_type_t mem_type,
bool versal,
bool virtual,
uint8_t max_macro_height,
bool asic);
int cam_latency_ram(cam_mem_type_t mem_type,
bool ram_hi_freq,
int cascade_height);
#endif
#define CAM_CONFIG_MAX_RANGE_WIDTH 16
#define CAM_CONFIG_MAX_TCAM_ENTRIES (32 * 1024)
#define CAM_CONFIG_MAX_FINGERPRINT_WIDTH (16)
static uint16_t cam_config_max_mem_width(cam_instance_type_t instance_type)
{
if (instance_type == DRAMBCAM) {
return 1024;
} else {
return 2048;
}
}
static uint16_t get_num_rams(cam_mem_type_t mem_type, bool is_tcam,
uint16_t list_length, uint16_t mem_depth,
uint16_t num_physical_units)
{
uint16_t rams;
if (mem_type == URAM && mem_depth == CAM_URAM_DEPTH_MIN) {
if (is_tcam) {
rams = DIV_UP(list_length + 64, 128);
} else {
rams = DIV_UP(list_length, 128);
}
} else {
if (is_tcam) {
rams = DIV_UP(list_length + 64, 64);
} else {
rams = DIV_UP(list_length, 64);
}
}
uint16_t min_depth = mem_type == URAM ? CAM_URAM_DEPTH_MIN :
mem_type == BRAM ? CAM_BRAM_DEPTH_MIN : CAM_LRAM_DEPTH_MIN;
uint8_t cascading = mem_depth / min_depth;
if (mem_type == URAM && cascading > 1) {
cascading /= 2;
}
return num_physical_units * cascading * rams;
}
static int dimension(cam_mem_type_t mem_type, uint32_t mem_depth, bool virtual, cam_config_t *new_config)
{
new_config->mem_type = mem_type;
new_config->num_slots = 1 <<
(31 - __builtin_clz((uint32_t) (new_config->arg.ram_freq / new_config->arg.engine_lookup_rate)));
if (new_config->num_slots > aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaS) {
new_config->num_slots = aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaS;
}
uint32_t units_storage;
uint32_t units_fields;
uint32_t units_base;
new_config->num_physical_units = 0;
if (new_config->instance_type == TCAM) {
new_config->list_length = ROUND_UP(2 * new_config->key_width + new_config->prio_width +
new_config->arg.response_width + 1, 64);
new_config->num_lists = mem_depth / new_config->num_slots;
uint32_t num_entries_per_list = (uint32_t) (aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO * new_config->num_lists + 0.5);
units_storage = DIV_UP(new_config->arg.num_entries, num_entries_per_list);
units_fields = BITS(new_config->key_width) - 2 + BITS(new_config->arg.num_entries) - 2;
if (units_fields >= new_config->complexity) {
units_fields = new_config->complexity - 1;
}
if (units_storage + units_fields > new_config->arg.num_entries) {
units_storage = 0;
units_fields = new_config->arg.num_entries;
}
units_base = 1;
} else if (new_config->instance_type == BCAM || new_config->instance_type == COMPBCAM) {
uint16_t list_length;
list_length = new_config->key_width + new_config->prio_width + new_config->arg.response_width + 1;
if (new_config->arg.aging) {
list_length += CAM_AGING_BITS;
}
new_config->list_length = ROUND_UP(list_length, 64);
if (new_config->num_slots > 4) {
new_config->num_slots = 4;
}
if (new_config->arg.num_slots != 0) {
new_config->num_slots = new_config->arg.num_slots;
}
new_config->num_lists = mem_depth / new_config->num_slots;
if (new_config->num_lists == 0) {
return CAM_ERROR_RAM_TOO_SMALL; 
} else {
uint32_t num_entries_per_list = (uint32_t) (aaaaaa1aaaBCAM_FILL_RATIO * new_config->num_lists + 0.5);
units_storage = DIV_UP(new_config->arg.num_entries, num_entries_per_list);
}
if (units_storage < 4)
units_storage = 4;
if (units_storage > 4 && new_config->num_slots > 1) {
new_config->num_physical_units = DIV_UP(units_storage, new_config->num_slots);
new_config->num_slots = DIV_UP(4, new_config->num_physical_units);
units_storage = new_config->num_physical_units * new_config->num_slots;
new_config->num_lists = mem_depth / new_config->num_slots;
}
units_fields = 0;
units_base = 0;
} else if (new_config->instance_type == STCAM || new_config->instance_type == CSTCAM) {
uint16_t list_length;
list_length = new_config->key_width + new_config->prio_width + new_config->arg.response_width + 1;
if (new_config->arg.aging) {
list_length += CAM_AGING_BITS;
}
new_config->list_length = ROUND_UP(list_length, 64);
new_config->num_lists = mem_depth / new_config->num_slots;
const uint32_t units_per_level = new_config->arg.num_masks;
const uint32_t full_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaalevel_min_entries = units_per_level * 1;
const uint32_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaalevel_contribution = 1 << ((BITS(new_config->num_lists) - 1) / 2);
const uint32_t full_second_level_min_entries = units_per_level * aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaalevel_contribution;
const uint32_t second_level_contribution = (uint32_t) (aaaaaa1aaa2W_aaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa * 2 * new_config->num_lists
- aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaalevel_contribution);
const uint32_t full_third_level_min_entries = units_per_level
* (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaalevel_contribution + second_level_contribution);
const uint32_t third_level_contribution = (uint32_t) (3 * aaaaaa1aaa3W_aaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa * new_config->num_lists
- second_level_contribution - aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaalevel_contribution);
const uint32_t fourth_level_contribution = (uint32_t) (4 * aaaaaa1aaaBCAM_FILL_RATIO * new_config->num_lists
- third_level_contribution - second_level_contribution - aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaalevel_contribution);
if (new_config->arg.num_entries <= full_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaalevel_min_entries) {
units_storage = new_config->arg.num_entries;
} else if (new_config->arg.num_entries < full_second_level_min_entries) {
uint32_t num_second_level = DIV_UP(new_config->arg.num_entries - full_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaalevel_min_entries,
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaalevel_contribution);
const uint8_t log2 = CLOG2(new_config->num_lists);
const uint16_t min_second_level = 16/log2;
if (num_second_level < min_second_level)
num_second_level = min_second_level;
if (num_second_level > units_per_level)
num_second_level = units_per_level;
units_storage = units_per_level + num_second_level;
} else if (new_config->arg.num_entries < full_third_level_min_entries) {
const uint16_t num_third_level = DIV_UP(new_config->arg.num_entries - full_second_level_min_entries,
second_level_contribution);
units_storage = units_per_level * 2 + num_third_level;
} else {
const uint32_t rem_entries = new_config->arg.num_entries - full_third_level_min_entries;
if (rem_entries <= third_level_contribution) {
units_storage = units_per_level * 3;
} else if (rem_entries <= (third_level_contribution + fourth_level_contribution)) {
units_storage = units_per_level * 3 + 1;
} else { 
units_storage =
units_per_level * 3+ 1 +
DIV_UP((rem_entries - third_level_contribution-fourth_level_contribution),
((uint32_t)(aaaaaa1aaaBCAM_FILL_RATIO * new_config->num_lists + 0.5)));
}
}
#if 0
else if (new_config->arg.num_entries < full_fourth_level_min_entries) {
const uint16_t num_fourth_level = DIV_UP(new_config->arg.num_entries - full_third_level_min_entries,
third_level_contribution);
units_storage = units_per_level * 3 + num_fourth_level;
} else {
uint32_t num_entries_per_list = (uint32_t) (aaaaaa1aaaBCAM_FILL_RATIO * new_config->num_lists + 0.5);
uint32_t num_entries_per_level = new_config->arg.num_entries / units_per_level;
units_storage = units_per_level * DIV_UP(num_entries_per_level, num_entries_per_list);
const uint16_t skewed_storage = units_per_level - 1 +
DIV_UP(new_config->arg.num_entries - units_per_level - 1, num_entries_per_list);
if (skewed_storage > units_storage)
units_storage = skewed_storage;
if (units_storage < (units_per_level * 4))
units_storage = 4 * units_per_level;
}
#endif
units_fields = 0;
units_base = 0;
} else {
assert(false);
return CAM_ERROR_INVALID_MODE;
}
new_config->num_units = units_base + units_storage + units_fields;
if (new_config->arg.num_units != 0)
new_config->num_units = new_config->arg.num_units;
if (new_config->arg.num_slots != 0) {
new_config->num_slots = new_config->arg.num_slots;
new_config->num_lists = mem_depth / new_config->num_slots;
}
new_config->num_units = ROUND_UP(new_config->num_units, new_config->num_slots);
if (new_config->num_physical_units == 0)
new_config->num_physical_units = new_config->num_units / new_config->num_slots;
if (new_config->num_physical_units > aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaS) {
return CAM_ERROR_TOO_MANY_UNITS;
}
if (new_config->num_units > aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaS) {
return CAM_ERROR_TOO_MANY_UNITS;
}
new_config->latency = cam_latency(new_config->instance_type,
new_config->num_physical_units,
new_config->num_slots,
new_config->arg.engine_lookup_rate,
new_config->arg.lookup_interface_freq,
new_config->arg.ram_freq,
new_config->key_width,
new_config->list_length,
new_config->num_lists,
new_config->arg.flow_control,
new_config->mem_type,
new_config->arg.versal,
virtual,
new_config->arg.max_macro_height,
new_config->arg.asic_ram);
new_config->pipeline_capacity = cam_pipeline_capacity(new_config->instance_type,
new_config->num_physical_units,
new_config->num_slots,
new_config->arg.engine_lookup_rate,
new_config->arg.lookup_interface_freq,
new_config->arg.ram_freq,
new_config->key_width,
new_config->list_length,
new_config->num_lists,
new_config->arg.flow_control,
new_config->mem_type,
new_config->arg.versal,
virtual,
new_config->arg.max_macro_height,
new_config->arg.asic_ram);
uint16_t max_mem_width = cam_config_max_mem_width(new_config->instance_type);
if (new_config->list_length > max_mem_width) {
return CAM_ERROR_INVALID_MEMORY_WIDTH;
}
if (cam_config_get_num_lrams(new_config) > CAM_MAX_NUM_LRAMS ||
cam_config_get_num_brams(new_config) > new_config->arg.max_num_brams ||
cam_config_get_num_urams(new_config) > new_config->arg.max_num_urams) {
return CAM_ERROR_TOO_MANY_RAMS;
}
if (virtual && cam_config_get_num_lists(new_config) < CAM_MAX_VC_SEGMENTS) {
return CAM_ERROR_RAM_TOO_SMALL;
}
#if 0
   printf("mem_type = %s   mem_depth = %d   num_physical_units = %d\n",
          mem_type == LRAM ? "lutram" : mem_type == BRAM ? "bram" : "uram",
mem_depth,
new_config->num_units / new_config->num_slots);
#endif
return 0;
}
size_t cam_config_size(void) {
return sizeof(cam_config_t);
}
int cam_config_create(const cam_arg_t *cam_arg,
cam_instance_type_t cam_instance_type, cam_config_t **out_cam_config) {
struct cam_config_t *cam_config;
cam_config = cam_arg->malloc_function(cam_config_size());
if (cam_config == NULL)
return CAM_ERROR_NOMEM;
const int rc = cam_config_init(cam_arg, cam_instance_type, cam_config);
if (rc) {
cam_arg->free_function(cam_config);
return rc;
}
*out_cam_config = cam_config;
return 0;
}
static void print_invalid_mem_width_error(const cam_config_t *new_config, char *message) {
int rc = CAM_ERROR_INVALID_MEMORY_WIDTH;
uint16_t max_mem_width = cam_config_max_mem_width(new_config->instance_type);
sprintf(message,
           "'%s' The memory width '%d' required to store key%s%s, response%s and valid is larger than the maximum supported width %d",
cam_error_string(rc),
new_config->list_length,
           new_config->instance_type == TCAM ? ", mask" : "",
new_config->instance_type == TCAM ||
new_config->instance_type == STCAM ||
           new_config->instance_type == CSTCAM ? ", priority" : "",
           new_config->arg.aging ? ", aging" : "",
max_mem_width);
if ((new_config->arg.debug_flags & CAM_DEBUG_NO_ERROR_MSG) == 0) {
new_config->arg.error_print_function(new_config->ctx, message);
}
}
static void cam_config_print_args(const cam_arg_t *cam_arg, cam_config_t *cam_config) {
   char tag[100] = "CAM_DEBUG_CONFIG_ARGS";
   char message[2000] = "";
   sprintf(message, "%s: instance_type         %s", tag,
           cam_config->instance_type == TCAM ? "TCAM" :
           cam_config->instance_type == BCAM ? "BCAM" :
           cam_config->instance_type == STCAM ? "STCAM" :
           cam_config->instance_type == DRAMBCAM ? "DRAMBCAM" :
           cam_config->instance_type == COMPBCAM ? "CBCAM" :
           cam_config->instance_type == CSTCAM ? "CSTCAM" : "UNKNOWN");
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: num_entries           %"PRIu32"", tag, cam_arg->num_entries);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: num_units             %d", tag, cam_arg->num_units);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: format                %s", tag, cam_arg->format);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: key_width             %d", tag, cam_arg->key_width);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: narrow_key_width      %d", tag, cam_arg->narrow_key_width);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: response_width        %d", tag, cam_arg->response_width);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: num_masks             %d", tag, cam_arg->num_masks);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: priority_width        %d", tag, cam_arg->priority_width);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: engine_lookup_rate    %g", tag, cam_arg->engine_lookup_rate);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: lookup_interface_freq %g", tag, cam_arg->lookup_interface_freq);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: ram_freq              %g", tag, cam_arg->ram_freq);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: num_slots             %d", tag, cam_arg->num_slots);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: optimization_flags    0x%08" PRIX32, tag, cam_arg->optimization_flags);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: mem_type              %s", tag,
           cam_arg->mem_type == AUTO ? "AUTO" :
           cam_arg->mem_type == URAM ? "URAM" :
           cam_arg->mem_type == BRAM ? "BRAM" :
           cam_arg->mem_type == LRAM ? "LUTRAM" : "UNKNOWN");
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: asic_ram              %s", tag, cam_arg->asic_ram ? "TRUE" : "FALSE");
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: hbm                   %s", tag, cam_arg->hbm ? "TRUE" : "FALSE");
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: ddr_dram              %s", tag, cam_arg->ddr_dram ? "TRUE" : "FALSE");
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: num_phys_banks        %d", tag, cam_arg->num_phys_banks);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: channel_width         %"PRIi32"", tag, cam_arg->channel_width);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: public_r_size         %s", tag, cam_arg->public_r_size ? "TRUE" : "FALSE");
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: r_size                %"PRIi32"", tag, cam_arg->r_size);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: max_macro_height      %"PRIu8"", tag, cam_arg->max_macro_height);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: flow_control          %s", tag, cam_arg->flow_control ? "TRUE" : "FALSE");
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: aging                 %s", tag, cam_arg->aging ? "TRUE" : "FALSE");
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: options               %s", tag, cam_arg->options ? "TRUE" : "FALSE");
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: vc_id                 %"PRIu8"", tag, cam_arg->vc_id);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: vc_seg_map.vcid       %"PRIi16"", tag, cam_arg->vc_seg_map.vcid);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: segment_ctx.segment   %"PRIi16"", tag, cam_arg->segment_ctx.segment);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: max_hw_writes         %"PRIu16"", tag, cam_arg->max_hw_writes);
cam_config->arg.info_print_function(cam_config->ctx, message);
#if 0
This is not compliant C code. A function pointer can not be used with %p.
Function pointer must be made to string using a loop
   sprintf(message, "%s: hw_write_function     %p", tag, cam_arg->io[0].hw_write_function);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: hw_read_function      %p", tag, cam_arg->io[0].hw_read_function);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: error_print_function  %p", tag, cam_arg->error_print_function);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: info_print_function   %p", tag, cam_arg->info_print_function);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: malloc_function       %p", tag, cam_arg->malloc_function);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: realloc_function      %p", tag, cam_arg->realloc_function);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: calloc_function       %p", tag, cam_arg->calloc_function);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: free_function         %p", tag, cam_arg->free_function);
cam_config->arg.info_print_function(cam_config->ctx, message);
#endif
   sprintf(message, "%s: calc_heap_size        %s", tag, cam_arg->calc_heap_size ? "TRUE" : "FALSE");
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: max_tcam_heap_size    %"PRIu32"", tag, cam_arg->max_tcam_heap_size);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "%s: debug_flags           0x%08" PRIX32, tag, cam_arg->debug_flags);
cam_config->arg.info_print_function(cam_config->ctx, message);
}
static int cam_error(const cam_config_t *cam_config, int error_code, const char *fmt, ...) {
if((cam_config->arg.debug_flags & CAM_DEBUG_NO_ERROR_MSG) == 0) {
char message[2000];
va_list args;
va_start(args, fmt);
       int len1 = snprintf(message, sizeof message, "%s: ", cam_error_string(error_code));
vsnprintf(message + len1, sizeof message - len1, fmt, args);
va_end(args);
cam_config->arg.error_print_function(cam_config->ctx, message);
}
return error_code;
}
static int dimension_dram(const cam_arg_t *cam_arg, cam_config_t *new_config) {
char message[2000];
int rc;
if (new_config->arg.hbm) {
new_config->drambcam.replication_rate = aaaaaa1aaaHaa1aaaREPLICATION_RATE;
new_config->drambcam.max_units = 4;
new_config->drambcam.min_depth_cascading = 4;
new_config->drambcam.max_channels = 32;
new_config->arg.channel_width = 256; 
new_config->ram_size = 512 * 1024; 
new_config->arg.num_phys_banks = 16; 
} else if (new_config->arg.ddr_dram) {
new_config->drambcam.replication_rate = aaaaaa1aaaDDR_DRAM_REPLICATION_RATE;
new_config->drambcam.max_units = 4;
new_config->drambcam.min_depth_cascading = 1;
new_config->drambcam.max_channels = 1;
if (new_config->arg.channel_width < 0) {
new_config->arg.channel_width = 512;
}
if (!((new_config->arg.channel_width == 256)
|| (new_config->arg.channel_width == 512))) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                            "Channel width must be 256 or 512 bits");
}
if (new_config->arg.num_phys_banks < 0) {
new_config->arg.num_phys_banks = 8;
}
if (!((new_config->arg.num_phys_banks == 4)
|| (new_config->arg.num_phys_banks == 8)
|| (new_config->arg.num_phys_banks == 16) || (new_config->arg.num_phys_banks == 32)
|| (new_config->arg.num_phys_banks == 64))) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                            "Number of banks must be between 4-64 and a power of 2");
}
}
if ((new_config->arg.r_size >= 0)) {
new_config->ram_size = new_config->arg.r_size;
}
new_config->num_slots = 1;
uint8_t control_width = 1;
if (cam_arg->narrow_key_width > 0) {
control_width = 2;
}
const uint16_t response_size = new_config->arg.response_width + control_width;
uint8_t response_log2 = CLOG2(response_size);
if (new_config->arg.generation_number_granularity > 0) {
const uint8_t gen_number_bits = (1 << response_log2) / new_config->arg.generation_number_granularity;
response_log2 = CLOG2(response_log2 + gen_number_bits);
}
if ((response_log2) > new_config->arg.channel_width) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                        "Response + control transaction '%d' is wider than channel width (%d)",
response_log2, new_config->arg.channel_width);
}
const uint16_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa = new_config->arg.response_width + new_config->key_width + control_width;
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa > aaaaaa1aaaDRAMBCAM_MAX_LIST_SIZE) {
new_config->list_length = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa;
rc = CAM_ERROR_INVALID_MEMORY_WIDTH;
print_invalid_mem_width_error(new_config, message);
return rc;
}
uint8_t log2 = CLOG2(aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa);
if (new_config->arg.generation_number_granularity > 0) {
const uint8_t gen_number_bits = (1 << log2) / new_config->arg.generation_number_granularity;
log2 = CLOG2(aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa + gen_number_bits);
}
if (cam_arg->narrow_key_width > 0) {
const uint16_t narrow_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa = new_config->arg.response_width + new_config->arg.narrow_key_width
+ control_width;
uint8_t narrow_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa = CLOG2(narrow_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa);
if (new_config->arg.generation_number_granularity > 0) {
const uint8_t gen_number_bits = (1 << narrow_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa)
/ new_config->arg.generation_number_granularity;
narrow_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa = CLOG2(narrow_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa + gen_number_bits);
}
if (log2 <= 8) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                            "Mixed mode does not make sense for key width (%d) and response width (%d)",
cam_arg->key_width, cam_arg->response_width);
}
if (cam_arg->narrow_key_width >= cam_arg->key_width) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                            "Narrow key width '%d' is not narrower than wide key width (%d)",
cam_arg->narrow_key_width, cam_arg->key_width);
}
#if 0
if ((1 << narrow_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa) > new_config->arg.channel_width) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                            "Narrow entry '%d' is wider than channel width (%d)",
1 << narrow_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, new_config->arg.channel_width);
}
#endif
if (narrow_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa >= log2) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                            "Mixed mode not supported, narrow entry size and entry size are equal");
}
if ((new_config->arg.narrow_key_width < CAM_MIN_KEY_WIDTH) ||
(new_config->arg.narrow_key_width > CAM_MAX_KEY_WIDTH)) {
return cam_error(new_config, CAM_ERROR_MAX_KEY_LEN_EXCEED,
                            "Narrow key width '%d' out of supported range %d-%d",
new_config->arg.narrow_key_width, CAM_MIN_KEY_WIDTH, CAM_MAX_KEY_WIDTH);
}
}
if (log2 < 9)
log2 = 9;
new_config->list_length = 1 << log2;
new_config->drambcam.num_consecutive_reads = new_config->list_length
/ new_config->arg.channel_width;
if (new_config->arg.ddr_dram) {
if ((new_config->arg.r_size >= 0)
&& (new_config->arg.public_r_size)) {
const uint64_t bits_per_bank = (8UL * 1024
* (uint64_t) new_config->arg.r_size)
/ new_config->arg.num_phys_banks;
const uint64_t temp_size = bits_per_bank
/ new_config->arg.channel_width;
new_config->ram_size = (uint32_t) temp_size;
}
}
#if 0
if (new_config->arg.hbm) {
if ((new_config->arg.r_size >= 0)
&& (new_config->arg.public_r_size)) {
if (!((new_config->arg.r_size == (1024*1024)) || (new_config->arg.r_size == (2048*1024)))) {
return cam_error(new_config, CAM_ERROR_INVALID_MEM_TYPE,
                                   "HBM size '%"PRIu32"' is invalid. Allowed sizes are 512MB/PC or 1024MB/PC",
new_config->arg.r_size);
}
new_config->ram_size = new_config->arg.r_size;
}
}
#endif
if(new_config->arg.replication > 0) {
new_config->drambcam.replication = new_config->arg.replication;
} else {
new_config->drambcam.replication = (uint8_t) ((new_config->arg.engine_lookup_rate
+ (new_config->drambcam.replication_rate - 0.01)) / new_config->drambcam.replication_rate);
if (new_config->drambcam.replication == 0)
new_config->drambcam.replication = 1;
if ((new_config->drambcam.replication
< (new_config->arg.num_phys_banks
/ new_config->drambcam.min_depth_cascading))
&& (new_config->drambcam.replication > 2)) {
uint8_t log2 = CLOG2(new_config->drambcam.replication);
new_config->drambcam.replication = 1 << log2;
} else if ((new_config->drambcam.replication
> (new_config->arg.num_phys_banks
/ new_config->drambcam.min_depth_cascading))
&& (new_config->drambcam.replication
< (2
* (new_config->arg.num_phys_banks
/ new_config->drambcam.min_depth_cascading))))
{
new_config->drambcam.replication = 2
* (new_config->arg.num_phys_banks
/ new_config->drambcam.min_depth_cascading);
}
}
switch(new_config->arg.update_mode) {
case CAM_UPDATE_SOFTWARE:
new_config->drambcam.fill_level = (float) aaaaaa1aaaDRAMBCAM_FILL_RATIO_SOFTWARE;
break;
case CAM_UPDATE_HARDWARE:
new_config->drambcam.fill_level = (float) aaaaaa1aaaDRAMBCAM_FILL_RATIO_HARDWARE;
break;
default: assert(0);
}
uint32_t storage_capacity = (uint32_t) (new_config->arg.num_phys_banks * new_config->ram_size
* new_config->drambcam.fill_level + 0.5);
uint32_t num_entries_per_pc = storage_capacity / new_config->drambcam.num_consecutive_reads;
new_config->drambcam.num_pcs = DIV_UP(new_config->arg.num_entries * new_config->drambcam.replication, num_entries_per_pc);
assert(new_config->drambcam.num_pcs > 0);
bool exit_for = false;
uint8_t depth_cascade;
for (depth_cascade = new_config->drambcam.min_depth_cascading;
depth_cascade <= (new_config->arg.num_phys_banks /
new_config->drambcam.replication);
depth_cascade = depth_cascade * 2) {
const uint16_t units = (new_config->drambcam.num_pcs
* new_config->arg.num_phys_banks)
/ (new_config->drambcam.replication * depth_cascade);
if ((units / 4) < 2) {
exit_for = true;
break;
}
}
new_config->drambcam.depth_cascade =
new_config->drambcam.min_depth_cascading;
if (depth_cascade > new_config->drambcam.min_depth_cascading)
new_config->drambcam.depth_cascade = depth_cascade / 2;
if (exit_for) {
new_config->drambcam.depth_cascade = depth_cascade;
}
new_config->num_lists = new_config->ram_size
* new_config->drambcam.depth_cascade
/ new_config->drambcam.num_consecutive_reads;
if (new_config->num_lists > (1 << 24)) {
return cam_error(new_config, CAM_ERROR_INVALID_MEM_TYPE,
                        "DRAM size '%"PRIu32"' is too large", new_config->ram_size);
}
if(new_config->arg.ddr_dram) {
uint16_t units_storage = (new_config->drambcam.num_pcs
* new_config->arg.num_phys_banks)
/ (new_config->drambcam.replication
* new_config->drambcam.depth_cascade);
if (units_storage < 4)
{
assert(
new_config->drambcam.depth_cascade
== new_config->drambcam.min_depth_cascading);
units_storage = 4;
new_config->drambcam.num_pcs = (new_config->drambcam.replication
* new_config->drambcam.depth_cascade * units_storage
+ (new_config->arg.num_phys_banks - 1))
/ new_config->arg.num_phys_banks;
}
new_config->num_units = units_storage;
} else {
new_config->num_units = 4;
uint64_t ram_size_afl = (uint64_t) (new_config->ram_size * 1024ULL * new_config->drambcam.fill_level + 0.5);
uint64_t num_entries = new_config->arg.num_entries;
uint64_t es = new_config->list_length / 8;
uint64_t replication = new_config->drambcam.replication; 
unsigned num_pcs = 1;
while((num_pcs <= new_config->drambcam.max_channels) &&
((num_pcs * ram_size_afl) < (2 * num_entries * es * replication))) {
num_pcs *= 2;
}
unsigned user_pcs = new_config->arg.num_pcs;
if (user_pcs > 0) {
if (user_pcs != (unsigned)(1 << CLOG2(user_pcs))) {
return cam_error(new_config, CAM_ERROR_INVALID_USER_PCS,
                                "The requested number of (pseudo) channels = '%d' is not a power of 2",
user_pcs);
}
if (user_pcs < num_pcs) {
return cam_error(new_config, CAM_ERROR_INVALID_USER_PCS,
                                "The requested number of (pseudo) channels = '%d' is less than the minimum required %d",
user_pcs, num_pcs);
}
new_config->drambcam.num_pcs = user_pcs;
unsigned factor = user_pcs / num_pcs;
new_config->num_lists /= factor;
} else {
new_config->drambcam.num_pcs = num_pcs;
}
}
if (new_config->num_units > new_config->drambcam.max_units) {
return cam_error(new_config, CAM_ERROR_TOO_MANY_UNITS,
                        "The required number of logical memory units '%d' is larger than the maximum supported %d",
new_config->num_units, new_config->drambcam.max_units);
}
if (new_config->drambcam.num_pcs > new_config->drambcam.max_channels) {
return cam_error(new_config, CAM_ERROR_TOO_MANY_PCS,
                        "The required number of (pseudo) channels = '%d' is larger than the maximum supported %d",
new_config->drambcam.num_pcs, new_config->drambcam.max_channels);
}
if (new_config->arg.hbm) {
if ((new_config->key_width + new_config->arg.response_width + 1) > 512) {
uint32_t NUM_ENTRIES_MAX = (uint32_t) (((new_config->drambcam.num_pcs * new_config->drambcam.fill_level
* new_config->ram_size * 8 * 1024) / 1024));
if (new_config->arg.num_entries > NUM_ENTRIES_MAX) {
return cam_error(new_config, CAM_ERROR_TOO_MANY_ENTRIES,
               "Maximum size for NUM_ENTRIES when %dM HBM is selected and (KEY_WIDTH + RESP_WIDTH + 1) is greater than 512 is %d",
(new_config->ram_size == (1024*1024) ? 512:1024), NUM_ENTRIES_MAX);
}
}
if ((new_config->key_width + new_config->arg.response_width + 1) < 513) {
uint32_t NUM_ENTRIES_MAX = (uint32_t) (((new_config->drambcam.num_pcs * new_config->drambcam.fill_level
* new_config->ram_size * 8 * 1024) / 512));
if (new_config->arg.num_entries > NUM_ENTRIES_MAX) {
return cam_error(new_config, CAM_ERROR_TOO_MANY_ENTRIES,
               "Maximum size for NUM_ENTRIES when %dM HBM is selected and (KEY_WIDTH + RESP_WIDTH + 1) is lesser than 512 is %d",
(new_config->ram_size == (1024*1024) ? 512:1024), NUM_ENTRIES_MAX);
}
}
}
return 0;
}
static int dimension_bram_uram(cam_config_t *new_config) {
char message[2000];
int rc = CAM_ERROR_TOO_MANY_UNITS;
bool virtual = new_config->arg.vc_seg_map.vcid != -1;
cam_mem_type_t mem_type = new_config->arg.mem_type;
bool auto_mem_type = mem_type == AUTO;
bool auto_mem_depth = new_config->arg.r_size == -1;
if ((new_config->arg.r_size >= 0)) {
new_config->ram_size = new_config->arg.r_size;
}
if (!auto_mem_type && !auto_mem_depth) {
rc = dimension(mem_type, new_config->ram_size, virtual, new_config);
if (rc) {
if (rc == CAM_ERROR_INVALID_MEMORY_WIDTH) {
print_invalid_mem_width_error(new_config, message);
}
return rc;
}
}
uint16_t num_physical_units_lram = UINT16_MAX;
uint16_t num_physical_units_bram = UINT16_MAX;
uint16_t num_physical_units_uram = UINT16_MAX;
uint16_t num_rams_lram = UINT16_MAX;
uint16_t num_rams_bram = UINT16_MAX;
uint16_t num_rams_uram = UINT16_MAX;
uint32_t mem_depth_lram = 0;
uint32_t mem_depth_bram = 0;
uint32_t mem_depth_uram = 0;
uint32_t mem_depth = 0;
const bool optimize_ram = ((new_config->arg.optimization_flags & CAM_OPTIMIZE_RAM) != 0);
const bool optimize_logic = ((new_config->arg.optimization_flags & CAM_OPTIMIZE_LOGIC) != 0);
bool too_wide = false;
bool too_many_rams = false;
bool too_many_units = false;
assert(!(optimize_ram && optimize_logic));
#if 0
if (auto_mem_type || (mem_type == LRAM && auto_mem_depth)) {
mem_type = LRAM;
uint32_t mem_depth_min = new_config->ram_size;
uint32_t mem_depth_max = new_config->ram_size;
if (auto_mem_depth) {
mem_depth_min = CAM_LRAM_DEPTH_MIN;
mem_depth_max = 4 * CAM_LRAM_DEPTH_MIN;
}
for (uint32_t mem_depth = mem_depth_min; mem_depth <= mem_depth_max; mem_depth *= 2) {
rc = dimension(mem_type, mem_depth, virtual, new_config);
too_wide = too_wide || rc == CAM_ERROR_INVALID_MEMORY_WIDTH;
too_many_rams = too_many_rams || rc == CAM_ERROR_TOO_MANY_RAMS;
too_many_units = too_many_units || rc == CAM_ERROR_TOO_MANY_UNITS;
if (!rc) {
const uint16_t num_rams = get_num_rams(mem_type, new_config->instance_type == TCAM,
new_config->list_length, mem_depth,
new_config->num_physical_units);
const float delta_rams = num_rams - num_rams_lram;
const float delta_physical_units = new_config->num_physical_units - num_physical_units_lram;
const float ram_improvement = -(delta_rams / num_rams_lram);
const float physical_units_improvement = -(delta_physical_units / num_physical_units_lram);
const float tot_improvement = ram_improvement + 3 * physical_units_improvement;
bool update_values = false;
if (optimize_logic) {
if (new_config->num_physical_units < num_physical_units_lram) {
update_values = true;
} else if ((new_config->num_physical_units == num_physical_units_lram) &&
(num_rams < num_rams_lram)) {
update_values = true;
}
} else if (optimize_ram) {
if (num_rams < num_rams_lram) {
update_values = true;
} else if ((num_rams == num_rams_lram) &&
(new_config->num_physical_units < num_physical_units_lram)) {
update_values = true;
}
} else if (!optimize_ram && !optimize_logic) {
if (tot_improvement > 0) {
update_values = true;
}
} else {
assert(false);
}
if (update_values) {
num_physical_units_lram = new_config->num_physical_units;
mem_depth_lram = mem_depth;
num_rams_lram = num_rams;
}
}
}
}
#endif
if (auto_mem_type || (mem_type == BRAM && auto_mem_depth)) {
mem_type = BRAM;
uint32_t mem_depth_min = new_config->ram_size;
uint32_t mem_depth_max = new_config->ram_size;
if (auto_mem_depth) {
mem_depth_min = CAM_BRAM_DEPTH_MIN;
if (new_config->arg.ram_freq <= CAM_BRAM_DEPTH4_MAX_FREQ) {
mem_depth_max = 4 * CAM_BRAM_DEPTH_MIN;
} else if (new_config->arg.ram_freq <= CAM_BRAM_DEPTH2_MAX_FREQ) {
mem_depth_max = 2 * CAM_BRAM_DEPTH_MIN;
} else {
mem_depth_max = CAM_BRAM_DEPTH_MIN;
}
}
for (uint32_t mem_depth = mem_depth_min; mem_depth <= mem_depth_max; mem_depth *= 2) {
rc = dimension(mem_type, mem_depth, virtual, new_config);
too_wide = too_wide || rc == CAM_ERROR_INVALID_MEMORY_WIDTH;
too_many_rams = too_many_rams || rc == CAM_ERROR_TOO_MANY_RAMS;
too_many_units = too_many_units || rc == CAM_ERROR_TOO_MANY_UNITS;
if (!rc) {
const uint16_t num_rams = get_num_rams(mem_type, new_config->instance_type == TCAM,
new_config->list_length, mem_depth,
new_config->num_physical_units);
const float delta_rams = num_rams - num_rams_bram;
const float delta_physical_units = new_config->num_physical_units - num_physical_units_bram;
const float ram_improvement = -(delta_rams / num_rams_bram);
const float physical_units_improvement = -(delta_physical_units / num_physical_units_bram);
const float tot_improvement = ram_improvement + 3 * physical_units_improvement;
bool update_values = false;
if (optimize_logic) {
if (new_config->num_physical_units
< num_physical_units_bram) {
update_values = true;
} else if ((new_config->num_physical_units
== num_physical_units_bram)
&& (num_rams < num_rams_bram)) {
update_values = true;
}
} else if (optimize_ram) {
if ((num_rams < num_rams_bram)) {
update_values = true;
} else if ((num_rams == num_rams_bram)
&& (new_config->num_physical_units
< num_physical_units_bram)) {
update_values = true;
}
} else if (!optimize_ram && !optimize_logic) {
if (tot_improvement > 0) {
update_values = true;
}
} else {
assert(false);
}
if (update_values) {
num_physical_units_bram = new_config->num_physical_units;
mem_depth_bram = mem_depth;
num_rams_bram = num_rams;
}
}
}
}
if (auto_mem_type || (mem_type == URAM && auto_mem_depth)) {
mem_type = URAM;
uint32_t mem_depth_min = new_config->ram_size;
uint32_t mem_depth_max = new_config->ram_size;
if (auto_mem_depth) {
mem_depth_min = CAM_URAM_DEPTH_MIN;
mem_depth_max = new_config->arg.ram_freq > CAM_URAM_DEPTH_HI_FREQ ? CAM_URAM_DEPTH_MAX_HI_FREQ : CAM_URAM_DEPTH_MAX_LO_FREQ;
}
for (uint32_t mem_depth = mem_depth_min; mem_depth <= mem_depth_max; mem_depth *= 2) {
if ((new_config->instance_type == COMPBCAM || new_config->instance_type == CSTCAM) &&
mem_depth == CAM_URAM_DEPTH_MIN) {
continue;
}
rc = dimension(mem_type, mem_depth, virtual, new_config);
too_wide = too_wide || rc == CAM_ERROR_INVALID_MEMORY_WIDTH;
too_many_rams = too_many_rams || rc == CAM_ERROR_TOO_MANY_RAMS;
too_many_units = too_many_units || rc == CAM_ERROR_TOO_MANY_UNITS;
if (!rc) {
const uint16_t num_rams = get_num_rams(mem_type, new_config->instance_type == TCAM,
new_config->list_length, mem_depth,
new_config->num_physical_units);
const float delta_rams = num_rams - num_rams_uram;
const float delta_physical_units = new_config->num_physical_units - num_physical_units_uram;
const float ram_improvement = -(delta_rams / num_rams_uram);
const float physical_units_improvement = -(delta_physical_units / num_physical_units_uram);
const float tot_improvement = ram_improvement + 2 * physical_units_improvement;
bool update_values = false;
if (optimize_logic) {
if (new_config->num_physical_units
< num_physical_units_uram) {
update_values = true;
} else if ((new_config->num_physical_units
== num_physical_units_uram)
&& (num_rams < num_rams_uram)) {
update_values = true;
}
} else if (optimize_ram) {
if ((num_rams < num_rams_uram)) {
update_values = true;
} else if ((num_rams == num_rams_uram)
&& (new_config->num_physical_units
< num_physical_units_uram)) {
update_values = true;
}
} else if (!optimize_ram && !optimize_logic) {
if (tot_improvement > 0) {
update_values = true;
}
} else {
assert(false);
}
if (update_values) {
num_physical_units_uram = new_config->num_physical_units;
mem_depth_uram = mem_depth;
num_rams_uram = num_rams;
}
}
}
}
if (auto_mem_type || auto_mem_depth) {
if (num_physical_units_lram == UINT16_MAX &&
num_physical_units_bram == UINT16_MAX &&
num_physical_units_uram == UINT16_MAX) {
if (too_wide) {
rc = CAM_ERROR_INVALID_MEMORY_WIDTH;
print_invalid_mem_width_error(new_config, message);
} else if (too_many_units && !too_many_rams) {
rc = CAM_ERROR_TOO_MANY_UNITS;
} else {
rc = CAM_ERROR_TOO_MANY_RAMS;
}
return rc;
}
mem_type = URAM;
mem_depth = mem_depth_uram;
const float ram_size_lram = num_rams_lram * CAM_LRAM_DEPTH_WIDTH64;
const float ram_size_bram = num_rams_bram * CAM_BRAM_DEPTH_WIDTH64;
const float ram_size_uram = num_rams_uram * CAM_URAM_DEPTH_WIDTH64;
const float delta_lram_size = ram_size_lram - ram_size_uram;
const float delta_bram_size = ram_size_bram - ram_size_uram;
const float delta_physical_units_lram = num_physical_units_lram - num_physical_units_uram;
const float delta_physical_units_bram = num_physical_units_bram - num_physical_units_uram;
const float ram_improvement_lram = -(delta_lram_size / ram_size_uram);
const float ram_improvement_bram = -(delta_bram_size / ram_size_uram);
const float physical_units_improvement_lram = -(delta_physical_units_lram / num_physical_units_uram);
const float physical_units_improvement_bram = -(delta_physical_units_bram / num_physical_units_uram);
const float tot_improvement_lram = ram_improvement_lram + 1 * physical_units_improvement_lram;
const float tot_improvement_bram = ram_improvement_bram + 1 * physical_units_improvement_bram;
if (optimize_logic &&
num_physical_units_lram < num_physical_units_bram &&
num_physical_units_lram < num_physical_units_uram) {
mem_type = LRAM;
mem_depth = mem_depth_lram;
} else if (optimize_logic &&
num_physical_units_bram <= num_physical_units_uram) {
mem_type = BRAM;
mem_depth = mem_depth_bram;
} else if (optimize_ram &&
ram_size_lram < ram_size_bram &&
ram_size_lram < ram_size_uram) {
mem_type = LRAM;
mem_depth = mem_depth_lram;
} else if (optimize_ram &&
ram_size_bram <= ram_size_uram) {
mem_type = BRAM;
mem_depth = mem_depth_bram;
} else if (tot_improvement_lram > 0 &&
tot_improvement_lram > tot_improvement_bram) {
mem_type = LRAM;
mem_depth = mem_depth_lram;
} else if (tot_improvement_bram > 0) {
mem_type = BRAM;
mem_depth = mem_depth_bram;
}
rc = dimension(mem_type, mem_depth, virtual, new_config);
if (rc) {
if (rc == CAM_ERROR_INVALID_MEMORY_WIDTH) {
print_invalid_mem_width_error(new_config, message);
}
return rc;
}
}
if (new_config->num_units > aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaS) {
return cam_error(new_config, CAM_ERROR_TOO_MANY_UNITS,
                        "The required number of logical memory units '%d' is larger than the maximum supported %d",
new_config->num_units, aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaS);
}
if ((new_config->num_physical_units) > aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaS) {
return cam_error(new_config, CAM_ERROR_TOO_MANY_UNITS,
                        "The required number of physical memory units '%d' is larger than the maximum supported %d",
new_config->num_units / new_config->num_slots, aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaS);
}
if (virtual && cam_config_get_num_lists(new_config) < CAM_MAX_VC_SEGMENTS) {
return cam_error(new_config, CAM_ERROR_RAM_TOO_SMALL,
                        "The RAM depth '%"PRIu32"' is not large enough to be divided into virtual segments (%"PRIu16" required)",
cam_config_get_num_lists(new_config), (uint16_t) CAM_MAX_VC_SEGMENTS);
}
return 0;
}
int cam_config_init(const cam_arg_t *cam_arg, cam_instance_type_t cam_instance_type,
cam_config_t *cam_config)
{
cam_config_t *new_config = alloca(cam_config_size());
memset(new_config, 0, cam_config_size());
new_config->arg = *cam_arg;
new_config->instance_type = cam_instance_type;
assert(!((new_config->arg.segment_ctx.segment >= 0) && (new_config->arg.vc_seg_map.vcid != -1)));
if ((new_config->arg.segment_ctx.segment >= 0) || (new_config->arg.vc_seg_map.vcid != -1))
new_config->ctx = &(new_config->arg.segment_ctx);
else
new_config->ctx = new_config->arg.segment_ctx.ctx;
if ((cam_arg->debug_flags & CAM_DEBUG_CONFIG_ARGS) != 0) {
cam_config_print_args(cam_arg, new_config);
}
int rc;
char format_str[sizeof(cam_arg->format)];
strcpy(format_str, cam_arg->format);
char *str = format_str;
char *saveptr = format_str;
if (new_config->arg.r_size >= 0 && new_config->arg.public_r_size)
{
if (!((new_config->arg.segment_ctx.segment == -1)
&& ((new_config->arg.asic_ram) || (new_config->arg.ddr_dram) || (new_config->arg.hbm)))) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                            "RAM size cannot be changed");
}
} else if ((new_config->arg.r_size < 0) && (new_config->arg.asic_ram || new_config->arg.ddr_dram)) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                        "RAM size must be specified");
}
if (new_config->arg.r_size >= 0) {
if ((__builtin_popcount(new_config->arg.r_size) != 1)
|| (new_config->arg.r_size == 0)) {
return cam_error(new_config, CAM_ERROR_INVALID_MEM_TYPE,
                            "RAM size '%"PRIi32"' is not a power of 2",
new_config->arg.r_size);
}
}
if (((new_config->arg.generation_number_granularity > 0) && (new_config->instance_type != DRAMBCAM))
|| ((new_config->arg.generation_number_granularity != 256)
&& (new_config->arg.generation_number_granularity > 0))) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                        "Generation numbers only supported for dram bcam with granularity 256 bits");
}
if ((new_config->arg.hash_function > 0) && (new_config->instance_type != DRAMBCAM)) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                        "Hash function can only be changed for dram bcam");
}
if ((new_config->arg.fingerprint_width > 0)
&& ((new_config->instance_type != DRAMBCAM) || (cam_arg->narrow_key_width > 0))) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                        "Fingerprints can only be enabled for dram bcam without mixed mode");
}
if (new_config->arg.fingerprint_width > CAM_CONFIG_MAX_FINGERPRINT_WIDTH) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                        "Fingerprints can be at most %d bits wide", CAM_CONFIG_MAX_FINGERPRINT_WIDTH);
}
if (new_config->arg.channel_width >= 0 && !new_config->arg.ddr_dram) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                        "Channel width can only be changed for DDR-DRAM");
}
if (new_config->arg.num_phys_banks >= 0 && !new_config->arg.ddr_dram) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                        "Number of banks can only be changed for DDR-DRAM");
}
if (new_config->arg.replication != -1) {
if (new_config->instance_type != DRAMBCAM) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                            "Replication factor can only be changed for DRAM");
}
if ((new_config->arg.replication < CAM_MIN_REPLICATION) ||
(new_config->arg.replication > CAM_MAX_REPLICATION)) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                            "Replication factor %d outside valid range %d-%d",
new_config->arg.replication, CAM_MIN_REPLICATION, CAM_MAX_REPLICATION);
}
}
if (new_config->arg.update_mode != CAM_UPDATE_SOFTWARE) {
if (new_config->instance_type != DRAMBCAM) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                            "Update mode can only be changed for DRAM");
}
if (new_config->arg.update_mode != CAM_UPDATE_HARDWARE) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                            "Bad update mode %d", new_config->arg.update_mode);
}
}
if (new_config->arg.hbm && new_config->arg.ddr_dram) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                        "Both DDR-DRAM and HBM cannot be specified");
}
if ((new_config->arg.hbm || new_config->arg.ddr_dram)
&& new_config->arg.asic_ram) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                        "Both DRAM and ASIC RAM cannot be specified");
}
if (new_config->arg.num_entries == 0) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                        "CAM can not have 0 entries");
}
if ((cam_arg->num_entries > CAM_CONFIG_MAX_TCAM_ENTRIES) && cam_instance_type == TCAM) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                        "Number of entries '%"PRIu32"' larger than the maxium supported %d for TCAM",
cam_arg->num_entries, CAM_CONFIG_MAX_TCAM_ENTRIES);
}
if (new_config->instance_type == STCAM || new_config->instance_type == CSTCAM) {
if (new_config->arg.num_masks < 1) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                            "Number of masks '%d' is outside the supported range (1-255)",
new_config->arg.num_masks);
}
if (new_config->arg.num_masks > new_config->arg.num_entries) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                            "Number of masks '%d' cannnot be greater than number of entries (%d)",
new_config->arg.num_masks, new_config->arg.num_entries);
}
} else {
if (new_config->arg.num_masks != 0) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                            "Number of masks '%d' is not allowed (must be '0')",
new_config->arg.num_masks);
}
}
if (!(cam_instance_type == DRAMBCAM) && (cam_arg->narrow_key_width > 0)) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                        "Mixed mode only allowed for DRAM");
}
if ((cam_instance_type != BCAM) && (cam_instance_type != DRAMBCAM) && cam_arg->options) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                        "Options can only be enabled for DRAM");
}
if ((new_config->arg.optimization_flags
& (CAM_OPTIMIZE_RAM | CAM_OPTIMIZE_LOGIC))
&& (new_config->instance_type == DRAMBCAM)) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                        "Illegal optimization flags for DRAM BCAM");
}
if ((new_config->arg.optimization_flags & CAM_OPTIMIZE_ENTRIES) &&
(new_config->instance_type == TCAM)) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                        "Illegal optimization flag 'CAM_OPTIMIZE_ENTRIES' for TCAM");
}
if ((new_config->arg.optimization_flags & CAM_OPTIMIZE_MASKS) &&
(new_config->instance_type != STCAM) && (new_config->instance_type != CSTCAM)) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                        "Optimization flag 'CAM_OPTIMIZE_MASKS' only allowed for STCAMs");
}
if ((new_config->arg.optimization_flags & CAM_OPTIMIZE_RAM) &&
(new_config->arg.optimization_flags & CAM_OPTIMIZE_LOGIC)) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                        "Logic and RAM cannot be reduced at the same time");
}
if (new_config->arg.optimization_flags >= 16) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                        "Invalid optimization flags");
}
if (new_config->arg.io[0].hw_write_function == NULL) {
return cam_error(new_config, CAM_ERROR_NULL_POINTER,
                        "The hardware write function is undefined.");
}
if (new_config->arg.io[0].hw_read_function == NULL) {
return cam_error(new_config, CAM_ERROR_NULL_POINTER,
                        "The hardware read function is undefined.");
}
if ((cam_instance_type != DRAMBCAM && cam_instance_type != BCAM)
&& ((new_config->arg.hw_write_start_sequence_function != NULL)
|| (new_config->arg.hw_write_end_sequence_function != NULL))) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                        "hw_write_start_sequence_function or hw_write_end_sequence_function are defined but are only supported for bcam / hbm bcam.");
}
if ((cam_instance_type == DRAMBCAM) && (new_config->arg.mem_type != AUTO)) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                        "cam_arg_force_mem_type not supported for hbm");
}
if ((cam_instance_type == BCAM) || (cam_instance_type == DRAMBCAM)) {
if (new_config->arg.vc_seg_map.vcid >= 0) {
if (new_config->arg.vc_seg_map.vcid >= CAM_MAX_VCS) {
return cam_error(new_config, CAM_ERROR_WRONG_VIRTUAL_CAM_ID,
                                "The virtual cam id '%d' is too large (max %d).",
new_config->arg.vc_seg_map.vcid, CAM_MAX_VCS-1);
}
if (new_config->arg.options) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                                "Options should not be enabled for vbcam.");
}
uint8_t val = 0;
for (uint32_t x = 0; x < CAM_MAX_VC_SEGMENTS_MEM; x++) {
val |= new_config->arg.vc_seg_map.bit_map[x] & 0xff;
}
if (val == 0) {
return cam_error(new_config, CAM_ERROR_SEGMENT_aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaZERO,
                                "No segments are specified for the virtual cam.");
}
}
if (new_config->arg.segment_ctx.segment >= 0) {
new_config->segment = new_config->arg.segment_ctx.segment;
}
}
if (new_config->instance_type != TCAM) {
if (cam_arg->format[0] != 0) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                            "Format string can only be defined for TCAM");
}
new_config->key_width = cam_arg->key_width;
} else { 
if (cam_arg->key_width > 0) {
return cam_error(new_config, CAM_ERROR_INVALID_ARG,
                            "key width '%d' is not allowed for TCAM (must be '0')", cam_arg->key_width);
}
uint16_t start = 0;
new_config->complexity = 1;
uint64_t prev_complexity = 1;
while (1) {
uint16_t cnt;
char type;
           char *field = strtok_r(str, ":", &saveptr);
if (field == NULL)
break;
str = NULL; 
           rc = sscanf(field, "%hu%c", &cnt, &type);
if (rc != 2) {
rc = CAM_ERROR_FORMAT_SYNTAX;
return rc;
}
if (new_config->num_fields >= CAM_MAX_NUM_FIELDS) {
rc = CAM_ERROR_TOO_MANY_FIELDS;
return rc;
}
switch (type) {
case 'r':
if (new_config->num_ranges == CAM_CONFIG_MAX_RANGES) {
rc = CAM_ERROR_TOO_MANY_RANGES;
return rc;
}
if (cnt < 1 || cnt > CAM_CONFIG_MAX_RANGE_WIDTH) {
rc = CAM_ERROR_INVALID_RANGE_LEN;
return rc;
}
new_config->aaaaaaaaaaaaaaaaaa1aaa[new_config->num_fields].type = aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaR16;
new_config->aaaaaaaaaaaaaaaaaa1aaa[new_config->num_fields].instance = new_config->num_ranges;
new_config->range_start_pos[new_config->num_ranges] = start;
new_config->range_width[new_config->num_ranges] = cnt;
new_config->num_ranges++;
new_config->complexity *= 2;
break;
case 'p':
if (cnt == 0 || cnt > aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaa128) {
rc = CAM_ERROR_INVALID_PREFIX_LEN;
return rc;
}
new_config->aaaaaaaaaaaaaaaaaa1aaa[new_config->num_fields].type = aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaP128;
new_config->complexity *= (cnt + 1);
break;
case 'b':
if (cnt == 0 || cnt > aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaa128) {
rc = CAM_ERROR_INVALID_BIT_FIELD_LEN;
return rc;
}
new_config->aaaaaaaaaaaaaaaaaa1aaa[new_config->num_fields].type = aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaB128;
new_config->complexity *= 2;
break;
case 't': {
if (cnt == 0 || cnt > aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaa128 / 8) {
rc = CAM_ERROR_INVALID_TERNARY_FIELD_LEN;
return rc;
}
uint8_t field = new_config->num_fields;
new_config->aaaaaaaaaaaaaaaaaa1aaa[field].type = aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaT64;
new_config->complexity *= 1 << cnt;
break;
}
case 'c':
if (cnt == 0 || cnt > aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaa128) {
rc = CAM_ERROR_INVALID_CONST_FIELD_LEN;
return rc;
}
new_config->aaaaaaaaaaaaaaaaaa1aaa[new_config->num_fields].type = aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaC128;
break;
case 'u':
if (cnt == 0 || cnt > aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaa128) {
rc = CAM_ERROR_INVALID_UNUSED_FIELD_LEN;
return rc;
}
new_config->aaaaaaaaaaaaaaaaaa1aaa[new_config->num_fields].type = aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaU128;
break;
default:
rc = CAM_ERROR_FORMAT_SYNTAX;
return rc;
}
if (new_config->complexity < prev_complexity) {
new_config->complexity = UINT64_MAX;
}
prev_complexity = new_config->complexity;
new_config->aaaaaaaaaaaaaaaaaa1aaa[new_config->num_fields].len = cnt;
new_config->aaaaaaaaaaaaaaaaaa1aaa[new_config->num_fields].start_pos = start;
new_config->num_fields++;
new_config->key_width += cnt;
start += cnt;
}
if (new_config->complexity > CAM_MAX_COMPLEXITY) {
rc = CAM_ERROR_FORMAT_COMPLEXITY;
return rc;
}
} 
if ((new_config->key_width < CAM_MIN_KEY_WIDTH) || (new_config->key_width > CAM_MAX_KEY_WIDTH)) {
return cam_error(new_config, CAM_ERROR_MAX_KEY_LEN_EXCEED,
                        "Key width '%d' out of supported range %d-%d",
new_config->key_width, CAM_MIN_KEY_WIDTH, CAM_MAX_KEY_WIDTH);
}
if(new_config->instance_type != DRAMBCAM) {
int MAX_FREQ_LIMIT = new_config->arg.asic_ram ? CAM_MAX_FREQ_ASIC : CAM_MAX_FREQ_FPGA;
if (new_config->arg.engine_lookup_rate > MAX_FREQ_LIMIT) {
return cam_error(new_config, CAM_ERROR_TOO_HIGH_FREQUENCY,
                            "Lookup rate '%g Msps' exceeds the maximum supported (%d Msps)",
new_config->arg.engine_lookup_rate, MAX_FREQ_LIMIT);
}
if (new_config->arg.engine_lookup_rate > new_config->arg.lookup_interface_freq) {
return cam_error(new_config, CAM_ERROR_TOO_HIGH_FREQUENCY,
                            "Lookup rate '%g Msps' exceeds the lookup interface frequency (%g MHz)",
new_config->arg.engine_lookup_rate, new_config->arg.lookup_interface_freq);
}
if (new_config->arg.lookup_interface_freq > MAX_FREQ_LIMIT) {
return cam_error(new_config, CAM_ERROR_TOO_HIGH_FREQUENCY,
                            "Lookup interface frequency '%g MHz' exceeds the maximum supported (%d MHz)",
new_config->arg.lookup_interface_freq, MAX_FREQ_LIMIT);
}
if (new_config->arg.lookup_interface_freq > new_config->arg.ram_freq) {
return cam_error(new_config, CAM_ERROR_TOO_HIGH_FREQUENCY,
                            "Lookup interface frequency '%g MHz' exceeds the RAM frequency (%g MHz)",
new_config->arg.lookup_interface_freq, new_config->arg.ram_freq);
}
if (new_config->arg.ram_freq > MAX_FREQ_LIMIT) {
return cam_error(new_config, CAM_ERROR_TOO_HIGH_FREQUENCY,
                            "RAM clock frequency '%g MHz' exceeds the maximum supported (%d MHz)",
new_config->arg.ram_freq, MAX_FREQ_LIMIT);
}
}
if (new_config->instance_type == TCAM ||
new_config->instance_type == STCAM ||
new_config->instance_type == CSTCAM) {
int16_t default_priority_width;
if (new_config->instance_type == TCAM) {
default_priority_width = CLOG2(new_config->arg.num_entries);
} else {
default_priority_width = CLOG2(new_config->arg.num_masks);
}
if (new_config->arg.priority_width >= 0) {
if (new_config->arg.priority_width >= default_priority_width &&
new_config->arg.priority_width <= CAM_MAX_PRIO_WIDTH) {
new_config->prio_width = new_config->arg.priority_width;
} else {
return cam_error(new_config, CAM_ERROR_WRONG_PRIO_WIDTH,
                                "Priority width '%d' is out of supported range %d-%d",
new_config->arg.priority_width,
default_priority_width, CAM_MAX_PRIO_WIDTH);
}
} else {
new_config->prio_width = default_priority_width;
}
} else {
if (new_config->arg.priority_width > 0) {
return cam_error(new_config, CAM_ERROR_WRONG_PRIO_WIDTH,
                                "Priority width '%d' is not supported for BCAM (must be '0')",
new_config->arg.priority_width);
}
}
if ((new_config->arg.response_width > CAM_MAX_RESPONSE_WIDTH) ||
(new_config->arg.response_width < CAM_MIN_RESPONSE_WIDTH)) {
return cam_error(new_config, CAM_ERROR_WRONG_RESPONSE_WIDTH,
                        "Response width '%d' out of supported range %d-%d",
new_config->arg.response_width,
CAM_MIN_RESPONSE_WIDTH, CAM_MAX_RESPONSE_WIDTH);
}
if (new_config->instance_type == DRAMBCAM) {
rc = dimension_dram(cam_arg, new_config);
if(rc) return rc;
} else {
rc = dimension_bram_uram(new_config);
if(rc) return rc;
}
*cam_config = *new_config;
if ((cam_config->arg.segment_ctx.segment >= 0) || (cam_config->arg.vc_seg_map.vcid != -1))
cam_config->ctx = &(cam_config->arg.segment_ctx);
if (new_config->arg.debug_flags & CAM_DEBUG_CONFIG) {
cam_config_print(new_config);
}
return 0;
}
void cam_config_destroy(cam_config_t *cam_config)
{
cam_free_func free_function = cam_config->arg.free_function;
free_function(cam_config);
}
uint16_t cam_config_get_key_width(const cam_config_t *cam_config)
{
return cam_config->key_width;
}
uint8_t cam_config_get_num_pcs(const cam_config_t *cam_config)
{
return cam_config->drambcam.num_pcs;
}
float cam_config_get_dram_fill_level(const cam_config_t *cam_config)
{
return cam_config->drambcam.fill_level;
}
uint8_t cam_config_get_prio_width(const cam_config_t *cam_config)
{
return cam_config->prio_width;
}
uint16_t cam_config_get_response_width(const cam_config_t *cam_config)
{
return cam_config->arg.response_width;
}
uint8_t cam_config_get_fingerprint_width(const cam_config_t *cam_config)
{
return cam_config->arg.fingerprint_width;
}
uint16_t cam_config_get_narrow_key_width(const cam_config_t *cam_config)
{
return cam_config->arg.narrow_key_width;
}
uint16_t cam_config_get_num_units(const cam_config_t * cam_config)
{
return cam_config->num_units;
}
uint8_t cam_config_get_num_slots(const cam_config_t * cam_config)
{
return cam_config->num_slots;
}
uint16_t cam_config_get_num_physical_units(const cam_config_t * cam_config)
{
return cam_config->num_physical_units;
}
uint16_t cam_config_get_list_length(const cam_config_t * cam_config)
{
return cam_config->list_length;
}
uint8_t cam_config_get_num_ranges(const cam_config_t * cam_config)
{
return cam_config->num_ranges;
}
uint32_t cam_config_get_num_lists(const cam_config_t * cam_config)
{
return cam_config->num_lists;
}
uint8_t cam_config_get_num_fields(const cam_config_t * cam_config)
{
return cam_config->num_fields;
}
uint16_t cam_config_get_latency(const cam_config_t *cam_config)
{
return cam_config->latency;
}
uint16_t cam_config_get_pipeline_capacity(const cam_config_t *cam_config)
{
return cam_config->pipeline_capacity;
}
static uint16_t cam_config_get_num_rams(const cam_config_t *cam_config)
{
const bool is_tcam = cam_config->instance_type == TCAM;
const uint32_t mem_depth = cam_config->num_slots * cam_config->num_lists;
return get_num_rams(cam_config->mem_type, is_tcam,
cam_config->list_length, mem_depth,
cam_config->num_physical_units);
}
uint16_t cam_config_get_num_lrams(const cam_config_t *cam_config)
{
uint16_t num_rams = 0;
if (cam_config->mem_type == LRAM) {
num_rams += 64 * cam_config_get_num_rams(cam_config);
}
if (cam_config->num_slots > 1 && (cam_config->instance_type == TCAM ||
cam_config->instance_type == STCAM ||
cam_config->instance_type == CSTCAM)) {
num_rams += (1 + cam_config->key_width) * cam_config->num_physical_units;
}
return num_rams;
}
uint16_t cam_config_get_num_brams(const cam_config_t *cam_config)
{
uint16_t num_rams = 0;
if (cam_config->mem_type == BRAM) {
num_rams += cam_config_get_num_rams(cam_config);
}
return num_rams;
}
uint16_t cam_config_get_num_urams(const cam_config_t *cam_config)
{
uint16_t num_rams = 0;
if (cam_config->mem_type == URAM) {
num_rams += cam_config_get_num_rams(cam_config);
}
if (cam_config_is_virtualized(cam_config) &&
cam_config_is_bcam_instance(cam_config)) {
num_rams += 1;
}
return num_rams;
}
uint32_t cam_config_get_num_entries(const cam_config_t *cam_config)
{
return cam_config->arg.num_entries;
}
uint16_t cam_config_get_num_entries_per_unit(const cam_config_t *cam_config)
{
assert(cam_config->instance_type == TCAM);
return aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO * cam_config->num_lists;
}
uint8_t cam_config_get_num_masks(const cam_config_t *cam_config)
{
if (cam_config->arg.optimization_flags & CAM_OPTIMIZE_MASKS)
return cam_config_get_num_units(cam_config);
else
return cam_config->arg.num_masks;
}
int cam_config_get_aaaaaaaaaaaaaaaaaa1aaa(const cam_config_t *cam_config, uint8_t field_number, aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc *desc)
{
if (field_number >= cam_config->num_fields)
return CAM_ERROR_TOO_MANY_FIELDS;;
*desc = cam_config->aaaaaaaaaaaaaaaaaa1aaa[field_number];
return 0;
}
int cam_config_get_range_start_pos(const cam_config_t *cam_config, uint8_t range_number,
uint16_t *start_pos)
{
if (range_number >= cam_config->num_ranges)
return CAM_ERROR_TOO_MANY_RANGES;;
*start_pos = cam_config->range_start_pos[range_number];
return 0;
}
int cam_config_get_range_width(const cam_config_t *cam_config, uint8_t range_number, uint8_t *width)
{
if (range_number >= cam_config->num_ranges)
return CAM_ERROR_TOO_MANY_RANGES;;
*width = cam_config->range_width[range_number];
return 0;
}
bool cam_config_is_lram_instance(const cam_config_t *cam_config)
{
return cam_config->mem_type == LRAM;
}
bool cam_config_is_uram_instance(const cam_config_t *cam_config)
{
return cam_config->mem_type == URAM;
}
bool cam_config_is_ddr_dram_instance(const cam_config_t *cam_config) {
return (cam_config->arg.ddr_dram);
}
bool cam_config_is_mixed_mode(const cam_config_t *cam_config)
{
return (cam_config->arg.narrow_key_width > 0);
}
bool cam_config_is_tcam_instance(const cam_config_t *cam_config)
{
return (cam_config->instance_type == TCAM);
}
bool cam_config_is_bcam_instance(const cam_config_t *cam_config)
{
return (cam_config->instance_type == BCAM);
}
bool cam_config_is_drambcam_instance(const cam_config_t *cam_config)
{
return (cam_config->instance_type == DRAMBCAM);
}
bool cam_config_is_virtualized(const cam_config_t *cam_config) {
return cam_config->arg.vc_seg_map.vcid != -1;
}
uint8_t cam_config_get_replication(const cam_config_t *cam_config)
{
return cam_config->drambcam.replication;
}
uint8_t cam_config_get_num_phys_banks(const cam_config_t *cam_config)
{
return cam_config->arg.num_phys_banks;
}
uint16_t cam_config_get_channel_width(const cam_config_t *cam_config) {
return cam_config->arg.channel_width;
}
uint32_t cam_config_get_ram_size(const cam_config_t *cam_config)
{
return cam_config->ram_size;
}
uint16_t cam_config_get_segment(const cam_config_t *cam_config)
{
return cam_config->segment;
}
bool cam_config_is_single_clock(const cam_config_t *cam_config)
{
return (cam_config->arg.ram_freq == cam_config->arg.lookup_interface_freq);
}
bool cam_config_has_flow_control(const cam_config_t *cam_config)
{
return cam_config->arg.flow_control;
}
void cam_config_get_default_response(const cam_config_t *cam_config, uint8_t *default_response)
{
memcpy(default_response, cam_config->arg.default_response, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
}
void cam_config_get_narrow_default_response(const cam_config_t *cam_config, uint8_t *narrow_default_response)
{
memcpy(narrow_default_response, cam_config->arg.narrow_default_response, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
}
uint8_t cam_config_get_field_width(const cam_config_t *cam_config, uint8_t field_num) {
const char *format = cam_config->arg.format;
size_t i = 0;
if (field_num > 0) {
int cnt = 0;
for (i = 0; i < strlen(format); i++) {
if (format[i] == ':') {
cnt++;
if (cnt == field_num) {
i++;
break;
}
}
}
}
uint8_t val = strtoul(&format[i], NULL, 10);
return val;
}
uint16_t cam_config_get_field_pos(const cam_config_t *cam_config, uint8_t field_num) {
uint16_t pos = 0;
for (int field = 0; field < field_num; field++) {
pos += cam_config_get_field_width(cam_config, field);
}
return pos;
}
uint8_t cam_config_get_depth_cascade(const cam_config_t *cam_config) {
return cam_config->drambcam.depth_cascade;
}
uint32_t cam_config_calculate_heap_size(const cam_config_t *config) {
if (config->instance_type == COMPBCAM)
return 0;
const uint16_t list_length = cam_config_get_list_length(config);
const uint32_t num_entries = cam_config_get_num_entries(config);
const uint32_t num_lists = cam_config_get_num_lists(config);
const uint8_t num_units = cam_config_get_num_units(config);
uint32_t heap_size = client_size() + sizeof(cam_config_t);
uint8_t tcam = 1;
if (config->instance_type != TCAM) {
tcam = 0;
uint32_t num_buckets;
uint8_t log2_num_buckets;
htable_num_entries_to_num_buckets(num_entries, &num_buckets,
&log2_num_buckets);
const uint32_t bloom_hash_table_size = htable_size()
+ num_buckets * sizeof(uint16_t);
heap_size = heap_size + bloom_hash_table_size;
heap_size = heap_size
+ client_overwrite_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa() * CLIENT_MAX_OVERWRITES;
}
uint8_t bits_per_list = 1;
if (cam_config_is_mixed_mode(config))
bits_per_list = 4;
const uint32_t aaaa1aaaheap_size = aaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa()
+ num_lists * sizeof(uint32_t) * list_length / 32
+ num_lists * sizeof(uint16_t) 
+ (bits_per_list * num_lists + 31) / 32 * sizeof(uint32_t)
+ tcam * num_lists * aaaa1aaasource_bucket_size();
heap_size = heap_size + tcam * aaaa1aaaheap_size;
const uint32_t aa1aaaheap_size = aa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa()
+ aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO * num_lists * aa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaabaaaaaaaaaa4aaa();
const uint32_t aaa1aaaheap_size = aaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa() + tcam * aa1aaaheap_size + aaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa()
+ aaaa1aaaheap_size;
heap_size = heap_size + aaa1aaaheap_size * num_units;
return heap_size;
}
char* cam_config_get_header(const cam_config_t *cam_config)
{
   char num_entries_info[20] = "    Depth (fixed)";
if (cam_config->arg.optimization_flags & CAM_OPTIMIZE_MASKS) {
if (cam_config->instance_type == STCAM || cam_config->instance_type == CSTCAM) {
           sprintf(num_entries_info, "    Depth (up to)");
}
}
if (cam_config->arg.optimization_flags & CAM_OPTIMIZE_ENTRIES) {
uint32_t num_entries = (uint32_t) (cam_config_get_num_units(cam_config) *
cam_config->num_lists * aaaaaa1aaaBCAM_FILL_RATIO + 0.5);
if (num_entries > cam_config->arg.num_entries) {
if (cam_config->instance_type == BCAM || cam_config->instance_type == COMPBCAM) {
               sprintf(num_entries_info, "Depth (optimized)");
}
if (cam_config->instance_type == STCAM || cam_config->instance_type == CSTCAM) {
               sprintf(num_entries_info, "    Depth (up to)");
}
}
}
static char message[150];
   sprintf(message, "%s x Width (Key  %s+ Response %s+ Valid + Unused)",
num_entries_info,
           cam_config->instance_type == TCAM ? "+ Mask " : "",
           cam_config->instance_type == TCAM || cam_config->instance_type == STCAM || cam_config->instance_type == CSTCAM ? "+ Priority " :
           cam_config->arg.aging ? "+ Aging " : "");
return &message[0];
}
char* cam_config_get_values(const cam_config_t *cam_config)
{
static char message[150];
uint32_t mem_depth;
mem_depth = cam_config->num_slots * cam_config->num_lists;
uint32_t mem_width = cam_config->list_length;
if (cam_config->instance_type != TCAM && cam_config->mem_type == URAM && mem_depth == CAM_URAM_DEPTH_MIN) {
mem_width = 128 * DIV_UP(mem_width, 128);
}
uint8_t control = 1;
if (cam_config_is_mixed_mode(cam_config))
control = 2;
int32_t unused = mem_width - cam_config_get_key_width(cam_config) - cam_config_get_response_width(cam_config)
- control;
if (cam_config->instance_type == TCAM) {
unused -= cam_config_get_key_width(cam_config);
}
if (cam_config->instance_type == TCAM || cam_config->instance_type == STCAM || cam_config->instance_type == CSTCAM) {
unused -= cam_config_get_prio_width(cam_config);
}
if (cam_config->arg.aging) {
unused -= CAM_AGING_BITS;
}
char mask[10];
if (cam_config->instance_type == TCAM) {
       sprintf(mask, " + %3d ", cam_config_get_key_width(cam_config));
} else {
mask[0] = '\0';
}
char prio[13];
if (cam_config->instance_type == TCAM || cam_config->instance_type == STCAM || cam_config->instance_type == CSTCAM) {
       sprintf(prio, "+   %2d     ", cam_config_get_prio_width(cam_config));
} else if (cam_config->arg.aging) {
       sprintf(prio, "+  %d    ", CAM_AGING_BITS);
} else {
prio[0] = '\0';
}
uint32_t num_entries = cam_config->arg.num_entries;
if (cam_config->arg.optimization_flags & CAM_OPTIMIZE_ENTRIES) {
num_entries = (uint32_t) (cam_config_get_num_units(cam_config) *
cam_config->num_lists * aaaaaa1aaaBCAM_FILL_RATIO + 0.5);
}
   sprintf(message, "%17"PRIu32" x %5"PRIu32" (%4"PRIu16"%s +   %4"PRIu16"   %s+   %"PRIu8"   +    %3"PRIi32")",
num_entries,
mem_width,
cam_config_get_key_width(cam_config),
&mask[0],
cam_config_get_response_width(cam_config),
&prio[0],
control,
unused);
return &message[0];
}
static int gcd_cam(const int a, const int b)
{
if (b == 0)
return a;
return gcd_cam(b, a % b);
}
char* cam_config_get_lookup_clock_info(const cam_config_t *cam_config)
{
static char message[150];
int rate_gcd = gcd_cam((int) (cam_config->arg.lookup_interface_freq * 1E6),
(int) (cam_config->arg.engine_lookup_rate * 1E6));
int min_gcd = (int) (cam_config->arg.lookup_interface_freq * 1E6) / 1024;
if (rate_gcd < min_gcd) {
rate_gcd = min_gcd;
}
int rate_cal_len = (int) (cam_config->arg.lookup_interface_freq * 1E6) / rate_gcd;
int rate_cal_lookups = (int) (cam_config->arg.engine_lookup_rate * 1E6) / rate_gcd;
if (rate_gcd < min_gcd) {
rate_cal_lookups++;
}
   sprintf(message, " %.8g MHz (%d lookup%s every",
cam_config->arg.lookup_interface_freq, rate_cal_lookups,
           rate_cal_lookups == 1 ? "" : "s");
if (rate_cal_len == 1) {
       sprintf(&message[strlen(message)], " cycle");
} else {
       sprintf(&message[strlen(message)], " %d cycles", rate_cal_len);
if (rate_cal_lookups != 1) {
int rate_gap = cam_config->arg.flow_control ? 0 :
rate_cal_len / ((int) (cam_config->arg.engine_lookup_rate * 1E6) / rate_gcd) - 1;
           sprintf(&message[strlen(message)], ", minimum gap %d", rate_gap);
}
}
   sprintf(&message[strlen(message)], ") response flow control %s",
           cam_config->arg.flow_control ? "enabled" : "disabled");
return &message[0];
}
char* cam_config_get_ram_clock_info(const cam_config_t *cam_config)
{
float scrub_bw = 0;
if (cam_config->mem_type == BRAM || cam_config->mem_type == URAM) {
if (cam_config->arg.aging) {
scrub_bw = (float) round(cam_config->arg.engine_lookup_rate / (32 * cam_config->num_physical_units));
} else {
scrub_bw = (float) (round(0.01 * cam_config->num_slots * cam_config->num_lists) / 10);
}
}
float lookup_bw = cam_config->arg.engine_lookup_rate * cam_config->num_slots;
float control_bw = cam_config->arg.ram_freq - lookup_bw - scrub_bw;
   char sub_str[100] = "";
if (control_bw < 0) {
       sprintf(sub_str, ") + Scrubbing %.2g MHz (oversubscribed)", scrub_bw);
} else {
       sprintf(sub_str, " + Scrubbing %.2g MHz + Control %.8g MHz)", scrub_bw, control_bw);
}
static char message[250];
   sprintf(message, " %.8g MHz (Lookups %d x %.8g Msps = %.8g MHz%s",
cam_config->arg.ram_freq,
cam_config->num_slots,
cam_config->arg.engine_lookup_rate,
lookup_bw,
sub_str);
return &message[0];
}
char* cam_config_get_tdm_info(const cam_config_t *cam_config)
{
float lookup_bw = cam_config->arg.engine_lookup_rate * cam_config->num_slots;
uint8_t num_slots = 1 <<
(31 - __builtin_clz((uint32_t) (cam_config->arg.ram_freq / cam_config->arg.engine_lookup_rate)));
if (num_slots > aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaS) {
num_slots = aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaS;
}
static char message[150];
   sprintf(message, " %d", cam_config->num_slots);
if (cam_config->num_slots == aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaS &&
(cam_config->arg.ram_freq - lookup_bw) > 0) {
       sprintf(&message[strlen(message)], " (capped at maximum value '%d')",
aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaS);
} else if ((cam_config->instance_type == BCAM || cam_config->instance_type == COMPBCAM) &&
num_slots > cam_config->num_slots) {
       sprintf(&message[strlen(message)], " (capped at '%d' because no more hash lookups needed)",
cam_config->num_slots);
}
return &message[0];
}
char* cam_config_get_ram_utilization_info(const cam_config_t *cam_config)
{
static char message[150];
uint16_t used = cam_config_get_key_width(cam_config) + cam_config_get_response_width(cam_config) + 1;
if (cam_config->instance_type == TCAM) {
used += cam_config_get_key_width(cam_config);
}
if (cam_config->instance_type == TCAM || cam_config->instance_type == STCAM ||
cam_config->instance_type == STCAM) {
used += cam_config_get_prio_width(cam_config);
}
if (cam_config->arg.aging) {
used += CAM_AGING_BITS;
}
uint32_t num_entries = cam_config->arg.num_entries;
uint32_t num_entries_max = (uint32_t) (cam_config_get_num_units(cam_config) * cam_config->num_lists
* aaaaaa1aaaBCAM_FILL_RATIO);
   char num_entries_info[20] = "";
if (cam_config->instance_type == STCAM || cam_config->instance_type == CSTCAM) {
if (cam_config->arg.optimization_flags & CAM_OPTIMIZE_MASKS) {
           sprintf(num_entries_info, "(up to) ");
}
if (cam_config->arg.optimization_flags & CAM_OPTIMIZE_ENTRIES) {
           sprintf(num_entries_info, "(up to) ");
num_entries = num_entries_max;
}
}
if (cam_config->instance_type == BCAM || cam_config->instance_type == COMPBCAM) {
if (cam_config->arg.num_entries == num_entries_max) {
           sprintf(num_entries_info, "(max) ");
}
if (cam_config->arg.optimization_flags & CAM_OPTIMIZE_ENTRIES) {
           sprintf(num_entries_info, "(max) ");
num_entries = num_entries_max;
}
}
float depth_util = (float) ((100.0 * num_entries) / (cam_config_get_num_units(cam_config) * cam_config->num_lists));
float width_util = (float) ((100.0 * used) / cam_config->list_length);
float total_util = (float) ((100.0 * num_entries * used)
/ (cam_config_get_num_units(cam_config) * cam_config->num_lists * cam_config->list_length));
   sprintf(message, " Depth %s%.0f%% (%"PRIu32" / %"PRIu32") x Width %.0f%% (%"PRIu16" / %"PRIu16") = Total %.0f%%",
num_entries_info, depth_util, num_entries, cam_config_get_num_units(cam_config) * cam_config->num_lists,
width_util, used, cam_config->list_length, total_util);
return &message[0];
}
char* cam_config_get_memory_units_info(const cam_config_t *cam_config)
{
static char message[150];
   sprintf(message, " %d logical / %d physical",
cam_config_get_num_units(cam_config),
cam_config_get_num_physical_units(cam_config));
return &message[0];
}
static char* get_generation_info(const cam_config_t *cam_config)
{
static char message[150];
   const char *mem_type_str = "";
const char *optimize_str;
if (cam_config->arg.mem_type == AUTO)
       mem_type_str = "AUTO RAM type";
else if (cam_config->arg.mem_type == URAM)
       mem_type_str = "Forced URAM";
else if (cam_config->arg.mem_type == BRAM)
       mem_type_str = "Forced BRAM";
else if (cam_config->arg.mem_type == LRAM)
       mem_type_str = "Forced LUTRAM";
else
assert(false);
if ((cam_config->arg.optimization_flags & CAM_OPTIMIZE_RAM) == CAM_OPTIMIZE_RAM)
       optimize_str = "RAM";
else if ((cam_config->arg.optimization_flags & CAM_OPTIMIZE_LOGIC) == CAM_OPTIMIZE_LOGIC)
       optimize_str = "LOGIC";
else
       optimize_str = "AUTO";
   sprintf(message, " %s and %s optimization",
mem_type_str, optimize_str);
char *message_pos = &message[0];
if (cam_config->arg.optimization_flags & CAM_OPTIMIZE_ENTRIES) {
message_pos += strlen(message_pos);
       sprintf(message_pos, ", OPTIMIZE_ENTRIES");
}
if (cam_config->arg.optimization_flags & CAM_OPTIMIZE_MASKS) {
message_pos += strlen(message_pos);
       sprintf(message_pos, ", OPTIMIZE_MASKS");
}
return &message[0];
}
void cam_config_print(const cam_config_t *cam_config)
{
char message[256 * 6];
char sub_str[256 * 5];
char *message_pos;
uint8_t width;
   const char *padding = "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
int col[3] = { 15, 62, 22 };
if (cam_config->instance_type == TCAM) {
col[1] += 7;
}
if (cam_config->instance_type == TCAM || cam_config->instance_type == STCAM ||
cam_config->instance_type == CSTCAM) {
col[1] += 11;
}
if (cam_config->arg.aging) {
col[1] += 8;
}
if ((cam_config->arg.optimization_flags & CAM_OPTIMIZE_MASKS)
||
((cam_config->instance_type == STCAM || cam_config->instance_type == CSTCAM) &&
(cam_config->arg.optimization_flags & CAM_OPTIMIZE_ENTRIES))) {
col[0] += 8;
}
   sprintf(message, "+%-.*s+%-.*s+%-.*s+", col[0], padding, col[1], padding, col[2], padding);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "|%-*s| %s |%-*s|",
           col[0], " Instance Type",
cam_config_get_header(cam_config),
           col[2], " Memory Primitives");
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "+%-.*s+%-.*s+%-.*s+", col[0], padding, col[1], padding, col[2], padding);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(sub_str, " %d-Mask %sSTCAM",
cam_config_get_num_masks(cam_config),
(cam_config->arg.optimization_flags & CAM_OPTIMIZE_MASKS) ||
           (cam_config->arg.optimization_flags & CAM_OPTIMIZE_ENTRIES) ? "(up to) " : "");
   char ram_type[32] = "";
int ram_count = 0;
if (cam_config->instance_type == DRAMBCAM) {
if (cam_config->arg.hbm) {
           sprintf(ram_type, "HBM512K");
} else {
           sprintf(ram_type, "DDR-DRAM");
}
ram_count = cam_config_get_num_pcs(cam_config);
} else {
if (cam_config_get_num_lrams(cam_config) != 0) {
           sprintf(ram_type, "LUTRAM");
ram_count = cam_config_get_num_lrams(cam_config);
} else if (cam_config_get_num_brams(cam_config) != 0) {
           sprintf(ram_type, "RAMB36E2");
ram_count = cam_config_get_num_brams(cam_config);
} else if (cam_config_get_num_urams(cam_config) != 0) {
           sprintf(ram_type, "URAM288_BASE");
ram_count = cam_config_get_num_urams(cam_config);
}
}
   sprintf(message, "|%-*s| %s | %12s x %5d |",
col[0],
           cam_config->instance_type == TCAM ? " TCAM" :
           (cam_config->instance_type == STCAM || cam_config->instance_type == CSTCAM) ? sub_str : " BCAM",
cam_config_get_values(cam_config),
ram_type,
ram_count);
cam_config->arg.info_print_function(cam_config->ctx, message);
ram_count = 0;
if (cam_config_get_num_lrams(cam_config) != 0) {
if (cam_config_get_num_brams(cam_config) != 0) {
           sprintf(ram_type, "RAMB36E2");
ram_count = cam_config_get_num_brams(cam_config);
} else if (cam_config_get_num_urams(cam_config) != 0) {
           sprintf(ram_type, "URAM288_BASE");
ram_count = cam_config_get_num_urams(cam_config);
}
} else if (cam_config_get_num_brams(cam_config) != 0) {
if (cam_config_get_num_urams(cam_config) != 0) {
           sprintf(ram_type, "URAM288_BASE");
ram_count = cam_config_get_num_urams(cam_config);
}
}
if (ram_count != 0) {
       sprintf(message, "|%-*s|%-*s| %12s x %5d |",
               col[0], " ",
               col[1], " ",
ram_type,
ram_count);
cam_config->arg.info_print_function(cam_config->ctx, message);
}
   sprintf(message, "+%-.*s+%-.*s+%-.*s+", col[0], padding, col[1], padding, col[2], padding);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, " ");
cam_config->arg.info_print_function(cam_config->ctx, message);
if (cam_config->instance_type == TCAM) {
width = 17 + cam_config_get_num_fields(cam_config) * 9;
       sprintf(message, "+%-.*s+", width, padding);
cam_config->arg.info_print_function(cam_config->ctx, message);
       sprintf(sub_str, " Key format %s (%d bits)",
cam_config->arg.format,
cam_config_get_key_width(cam_config));
       sprintf(message, "|%-*s|", width, sub_str);
cam_config->arg.info_print_function(cam_config->ctx, message);
message_pos = &sub_str[0];
       sprintf(message_pos, "+-----------------");
message_pos += strlen(message_pos);
for (int f = cam_config_get_num_fields(cam_config) - 1; f >= 0; f--) {
           sprintf(message_pos, "+--------");
message_pos += strlen(message_pos);
}
       sprintf(message_pos, "+");
cam_config->arg.info_print_function(cam_config->ctx, sub_str);
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc aaaaaaaaaaaaaaaaaa1aaa;
message_pos = &message[0];
       sprintf(message_pos, "| Key field       ");
message_pos += strlen(message_pos);
for (int f = cam_config_get_num_fields(cam_config) - 1; f >= 0; f--) {
int r = cam_config_get_aaaaaaaaaaaaaaaaaa1aaa(cam_config, f, &aaaaaaaaaaaaaaaaaa1aaa);
assert(r == 0);
           sprintf(message_pos, "|  %3d%c  ", aaaaaaaaaaaaaaaaaa1aaa.len,
aaaaaaaaaaaaaaaaaa1aaa.type == aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaR16 ? 'r' :
aaaaaaaaaaaaaaaaaa1aaa.type == aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaP128 ? 'p' :
aaaaaaaaaaaaaaaaaa1aaa.type == aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaB128 ? 'b' :
aaaaaaaaaaaaaaaaaa1aaa.type == aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaT64 ? 't' :
aaaaaaaaaaaaaaaaaa1aaa.type == aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaC128 ? 'c' : 'u');
message_pos += strlen(message_pos);
}
       sprintf(message_pos, "|");
cam_config->arg.info_print_function(cam_config->ctx, message);
cam_config->arg.info_print_function(cam_config->ctx, sub_str);
message_pos = &message[0];
       sprintf(message_pos, "| Key bit pos     ");
message_pos += strlen(message_pos);
for (int f = cam_config_get_num_fields(cam_config) - 1; f >= 0; f--) {
int r = cam_config_get_aaaaaaaaaaaaaaaaaa1aaa(cam_config, f, &aaaaaaaaaaaaaaaaaa1aaa);
assert(r == 0);
           sprintf(message_pos, "|%3d  %3d",
aaaaaaaaaaaaaaaaaa1aaa.start_pos + aaaaaaaaaaaaaaaaaa1aaa.len - 1,
aaaaaaaaaaaaaaaaaa1aaa.start_pos);
message_pos += strlen(message_pos);
}
       sprintf(message_pos, "|");
cam_config->arg.info_print_function(cam_config->ctx, message);
cam_config->arg.info_print_function(cam_config->ctx, sub_str);
       sprintf(message, " ");
cam_config->arg.info_print_function(cam_config->ctx, message);
}
col[0] = 28;
col[1] = 83;
   sprintf(message, "+%-.*s+%-.*s+", col[0], padding, col[1], padding);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(sub_str, " %.8g Msps", cam_config->arg.engine_lookup_rate);
   sprintf(message, "|%-*s|%-*s|", col[0], " Lookup rate", col[1], sub_str);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "+%-.*s+%-.*s+", col[0], padding, col[1], padding);
cam_config->arg.info_print_function(cam_config->ctx, message);
if (cam_config->instance_type != DRAMBCAM) {
       sprintf(message, "|%-*s|%-*s|", col[0], " Lookup interface frequency", col[1],
cam_config_get_lookup_clock_info(cam_config));
cam_config->arg.info_print_function(cam_config->ctx, message);
       sprintf(message, "+%-.*s+%-.*s+", col[0], padding, col[1], padding);
cam_config->arg.info_print_function(cam_config->ctx, message);
       sprintf(message, "|%-*s|%-*s|", col[0], " TDM Factor", col[1],
cam_config_get_tdm_info(cam_config));
cam_config->arg.info_print_function(cam_config->ctx, message);
       sprintf(message, "+%-.*s+%-.*s+", col[0], padding, col[1], padding);
cam_config->arg.info_print_function(cam_config->ctx, message);
       sprintf(message, "|%-*s|%-*s|", col[0], " RAM clock frequency", col[1],
cam_config_get_ram_clock_info(cam_config));
cam_config->arg.info_print_function(cam_config->ctx, message);
       sprintf(message, "+%-.*s+%-.*s+", col[0], padding, col[1], padding);
cam_config->arg.info_print_function(cam_config->ctx, message);
       sprintf(message, "|%-*s|%-*s|", col[0], " Memory units", col[1],
cam_config_get_memory_units_info(cam_config));
cam_config->arg.info_print_function(cam_config->ctx, message);
       sprintf(message, "+%-.*s+%-.*s+", col[0], padding, col[1], padding);
cam_config->arg.info_print_function(cam_config->ctx, message);
       sprintf(message, "|%-*s|%-*s|", col[0], " RAM utilization", col[1],
cam_config_get_ram_utilization_info(cam_config));
cam_config->arg.info_print_function(cam_config->ctx, message);
       sprintf(message, "+%-.*s+%-.*s+", col[0], padding, col[1], padding);
cam_config->arg.info_print_function(cam_config->ctx, message);
       sprintf(message, "|%-*s|%-*s|", col[0], " Optimization settings", col[1],
get_generation_info(cam_config));
cam_config->arg.info_print_function(cam_config->ctx, message);
       sprintf(message, "+%-.*s+%-.*s+", col[0], padding, col[1], padding);
cam_config->arg.info_print_function(cam_config->ctx, message);
} else if (cam_config->instance_type == DRAMBCAM) {
char msg[32];
       sprintf(msg, " %d", cam_config->drambcam.depth_cascade);
       sprintf(message, "|%-*s|%-*s|", col[0], " Bank Depth Cascading", col[1],
msg);
cam_config->arg.info_print_function(cam_config->ctx, message);
       sprintf(message, "+%-.*s+%-.*s+", col[0], padding, col[1], padding);
cam_config->arg.info_print_function(cam_config->ctx, message);
       sprintf(msg, " %d", cam_config->drambcam.replication);
       sprintf(message, "|%-*s|%-*s|", col[0], " Replication Factor", col[1],
msg);
cam_config->arg.info_print_function(cam_config->ctx, message);
       sprintf(message, "+%-.*s+%-.*s+", col[0], padding, col[1], padding);
cam_config->arg.info_print_function(cam_config->ctx, message);
       sprintf(msg, " %2"PRIu16" x %9"PRIu32" x %4"PRIu16"", cam_config->num_units,
cam_config->num_lists, cam_config->list_length);
       sprintf(message, "|%-*s|%-*s|", col[0], " CT Organization", col[1],
msg);
cam_config->arg.info_print_function(cam_config->ctx, message);
       sprintf(message, "+%-.*s+%-.*s+", col[0], padding, col[1], padding);
cam_config->arg.info_print_function(cam_config->ctx, message);
       sprintf(msg, " %2"PRIu8" , %1"PRIu8" , %3"PRIi32"", cam_config->arg.num_phys_banks,
cam_config->drambcam.num_consecutive_reads,
cam_config->arg.channel_width);
       sprintf(message, "|%-*s|%-*s|", col[0],
               " Banks, Csc. Rds, Ch. Width",
col[1], msg);
cam_config->arg.info_print_function(cam_config->ctx, message);
       sprintf(message, "+%-.*s+%-.*s+", col[0], padding, col[1], padding);
cam_config->arg.info_print_function(cam_config->ctx, message);
}
   sprintf(sub_str, " %"PRIu32" Bytes", cam_config_calculate_heap_size(cam_config));
   sprintf(message, "|%-*s|%-*s|", col[0], " Shadow heap size", col[1],
sub_str);
cam_config->arg.info_print_function(cam_config->ctx, message);
   sprintf(message, "+%-.*s+%-.*s+", col[0], padding, col[1], padding);
cam_config->arg.info_print_function(cam_config->ctx, message);
const char *flag_str[32] = { NULL };
   flag_str[0]  = " CAM_DEBUG_NO_ERROR_MSG       (0x0001)";
   flag_str[1]  = " CAM_DEBUG_ARGS               (0x0002)";
   flag_str[2]  = " CAM_DEBUG_VERIFY_WR          (0x0004)";
   flag_str[3]  = " CAM_DEBUG_VERIFY_SHADOW      (0x0008)";
   flag_str[4]  = " CAM_DEBUG_VERBOSE_VERIFY     (0x0010)";
   flag_str[5]  = " CAM_DEBUG_SKIP_MEM_INIT      (0x0020)";
   flag_str[6]  = " CAM_DEBUG_CONFIG             (0x0040)";
   flag_str[7]  = " CAM_DEBUG_VERIFY_CONFIG      (0x0080) (deprecated)";
   flag_str[8]  = " CAM_DEBUG_KEY_MASKING        (0x0100)";
   flag_str[9]  = " CAM_DEBUG_STATS              (0x0200)";
   flag_str[10] = " CAM_DEBUG_SEGMENTS           (0x0400)";
   flag_str[11] = " CAM_DEBUG_SKIP_VERIFY_CONFIG (0x0080)";
   flag_str[12] = " CAM_DEBUG_SET_COVER          (0x1000)";
   flag_str[13] = " CAM_DEBUG_CONFIG_ARGS        (0x2000)";
   flag_str[16] = " CAM_DEBUG_HW_WR             (0x10000)";
   flag_str[17] = " CAM_DEBUG_HW_RD             (0x20000)";
   flag_str[18] = " CAM_DEBUG_HW_LOOKUP         (0x40000)";
bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa = true;
for (int i = 0; i < 32; i++) {
uint32_t flag = 1 << i;
if ((cam_config->arg.debug_flags & flag) != 0 &&
flag_str[i] != NULL) {
           sprintf(message, "|%-*s|%-*s|", col[0],
                   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa ? " Debug flags" : "",
col[1], flag_str[i]);
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa = false;
cam_config->arg.info_print_function(cam_config->ctx, message);
}
}
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa) {
       sprintf(message, "|%-*s|%-*s|", col[0],
               " Debug flags", col[1], " CAM_DEBUG_NONE");
cam_config->arg.info_print_function(cam_config->ctx, message);
}
   sprintf(message, "+%-.*s+%-.*s+", col[0], padding, col[1], padding);
cam_config->arg.info_print_function(cam_config->ctx, message);
char patch[10];
if (CAM_SW_VERSION_PATCH == 0)
patch[0] = '\0';
else
       sprintf(patch, ".%d", CAM_SW_VERSION_PATCH);
   sprintf(message, "SW Version %d.%d%s, Build %d", CAM_SW_VERSION_MAJOR,
CAM_SW_VERSION_MINOR, patch, CAM_BUILD_NUMBER);
cam_config->arg.info_print_function(cam_config->ctx, message);
}
static int cam_latency_rams_per_cr(cam_mem_type_t mem_type, bool versal,
cam_instance_type_t mode, int mem_width)
{
int mem_width64 = mode == TCAM ? (mem_width + 64 + 63) / 64 : (mem_width + 63) / 64;
int brams_per_cr = versal || mem_width64 > 12 ? 24 : 12;
int urams_per_cr = versal ? 24 : 16;
return mem_type == URAM ? urams_per_cr : brams_per_cr; 
}
static int cam_latency_rams_per_unit(cam_instance_type_t mode, cam_mem_type_t mem_type,
int mem_width, int mem_depth, int cascade_height)
{
int mem_width64 = mode == TCAM ? (mem_width + 64 + 63) / 64 : (mem_width + 63) / 64;
int mem_width128 = mode == TCAM ? (mem_width + 64 + 127) / 128 : (mem_width + 127) / 128;
return cascade_height * (mem_type == URAM && mem_depth == 2048 ? mem_width128 : mem_width64);
}
static int cam_latency_mirror(cam_instance_type_t mode, int p_mem_units, cam_mem_type_t mem_type, bool versal,
int mem_width, int mem_depth, int cascade_height, int max_macro_height)
{
int center_height = mem_width / 256;
int units_per_column = (max_macro_height * cam_latency_rams_per_cr(mem_type, versal, mode, mem_width) - center_height) /
cam_latency_rams_per_unit(mode, mem_type, mem_width, mem_depth, cascade_height);
return p_mem_units == 1 || units_per_column <= 1 ? 1 : 2;
}
static int cam_latency_cols(cam_instance_type_t mode, int p_mem_units, cam_mem_type_t mem_type, bool versal,
int mem_width, int mem_depth, int cascade_height, uint8_t max_macro_height)
{
int center_height = mem_width / 256;
int rams_per_clock_aaaaaaaaaaaaaaaaaaaaa1aaaion = cam_latency_rams_per_cr(mem_type, versal, mode, mem_width);
int units_per_column = (max_macro_height * rams_per_clock_aaaaaaaaaaaaaaaaaaaaa1aaaion - center_height) /
cam_latency_rams_per_unit(mode, mem_type, mem_width, mem_depth, cascade_height);
if (units_per_column < 1) {
units_per_column = 1;
}
return (p_mem_units + units_per_column - 1) / units_per_column;
}
static int cam_latency_rows(cam_instance_type_t mode, int p_mem_units, cam_mem_type_t mem_type, bool versal,
int mem_width, int mem_depth, int cascade_height, uint8_t max_macro_height)
{
int c = cam_latency_cols(mode, p_mem_units, mem_type, versal, mem_width,
mem_depth, cascade_height, max_macro_height);
int m = cam_latency_mirror(mode, p_mem_units, mem_type, versal, mem_width,
mem_depth, cascade_height, max_macro_height);
return (((p_mem_units + c - 1) / c) + m - 1) / m;
}
static int cam_latency_prio(cam_instance_type_t mode, int p_mem_units, cam_mem_type_t mem_type, bool versal,
int mem_width, int mem_depth, int cascade_height, uint8_t max_macro_height)
{
int tot_height = p_mem_units * cam_latency_rams_per_unit(mode, mem_type, mem_width,
mem_depth, cascade_height);
int cr_rams = cam_latency_rams_per_cr(mem_type, versal, mode, mem_width);
int tiles = (tot_height + cr_rams - 1) / cr_rams;
int columns = cam_latency_cols(mode, p_mem_units, mem_type, versal, mem_width,
mem_depth, cascade_height, max_macro_height);
return ((tiles + columns - 1) / columns) / 4;
}
static int cam_latency_hash(cam_instance_type_t mode, uint16_t key_width, int mem_width,
int cascade_height, int logic_hi_freq)
{
int aaaaaaaaaaaa1aaadivisor = mode == TCAM || mode == STCAM || mode == CSTCAM ? 2 : 1;
int mem_fanout = cascade_height * (mode == TCAM ? 128 : mem_width);
return key_width <= 160/aaaaaaaaaaaa1aaadivisor && mem_fanout < 256/aaaaaaaaaaaa1aaadivisor ? 0 + logic_hi_freq :
key_width <= 320/aaaaaaaaaaaa1aaadivisor && mem_fanout < 512/aaaaaaaaaaaa1aaadivisor ? 0 + 2*logic_hi_freq :
key_width <= 640/aaaaaaaaaaaa1aaadivisor && mem_fanout < 1024/aaaaaaaaaaaa1aaadivisor ? 1 + logic_hi_freq :
key_width <= 1280/aaaaaaaaaaaa1aaadivisor && mem_fanout < 2048/aaaaaaaaaaaa1aaadivisor ? 2 + logic_hi_freq : 3;
}
int cam_latency_ram(cam_mem_type_t mem_type, bool ram_hi_freq, int cascade_height)
{
return 1 + (mem_type != LRAM ? 1 : 0) + (cascade_height > 1 ? 1 : 0) + (mem_type == URAM && ram_hi_freq ? 1 :0);
}
static int cam_latency_array(cam_instance_type_t mode,
int p_mem_units,
uint16_t key_width,
cam_mem_type_t mem_type,
bool versal,
int mem_width,
int mem_depth,
int cascade_height,
int logic_hi_freq,
bool ram_hi_freq,
uint8_t max_macro_height)
{
int r = cam_latency_rows(mode, p_mem_units, mem_type, versal, mem_width, mem_depth, cascade_height, max_macro_height);
int c = cam_latency_cols(mode, p_mem_units, mem_type, versal, mem_width, mem_depth, cascade_height, max_macro_height);
int key_latency = p_mem_units > 1 ? (r + 1) / 2 - 1 : 0;
int h_latency = cam_latency_hash(mode, key_width, mem_width, cascade_height, logic_hi_freq);
int r_latency = cam_latency_ram(mem_type, ram_hi_freq, cascade_height);
int c_latency = 2;
int hash_module_latency = mode == TCAM ? 7 + (logic_hi_freq ? 1 : 0) + h_latency + 2*r_latency + c_latency :
(mode == STCAM || mode == CSTCAM) ? 4 + h_latency + r_latency + c_latency :
3 + h_latency + r_latency + c_latency;
int prio_multi_row = r > 2 ? 2 : r == 2 ? 1 : 0;
int prio_col_latency = c > 1 ? c : 0;
int mirror_latency = cam_latency_mirror(mode, p_mem_units, mem_type, versal, mem_width,
mem_depth, cascade_height, max_macro_height) == 2 ? 1 : 0;
int return_latency = c - 1;
return key_latency + hash_module_latency + prio_multi_row + prio_col_latency +
cam_latency_prio(mode, p_mem_units, mem_type, versal, mem_width, mem_depth, cascade_height, max_macro_height) + mirror_latency + return_latency;
}
static int cam_latency_virt(cam_instance_type_t mode, uint16_t key_width, int mem_width,
int logic_hi_freq, bool ram_hi_freq, bool virtual)
{
int cascade_height = 1;
int hash_latency = cam_latency_hash(mode, key_width, mem_width, cascade_height, logic_hi_freq);
int ram_latency = cam_latency_ram(URAM, ram_hi_freq, cascade_height);
return virtual ? hash_latency + 1 + ram_latency + 1 : 0;
}
static int cam_latency_core(cam_instance_type_t instance_type,
uint16_t num_physical_units,
uint8_t tdm_factor,
uint16_t key_width,
cam_mem_type_t mem_type,
bool versal,
uint16_t list_length,
uint16_t num_lists,
float ram_freq,
bool virtual,
uint8_t max_macro_height,
bool asic)
{
int mem_depth = num_lists * tdm_factor;
int mem_width = list_length;
int logic_hi_freq = !asic && (ram_freq > CAM_LOGIC_HI_FREQ) ? 1 : 0;
bool ram_hi_freq = ram_freq > CAM_RAM_HI_FREQ;
int cascade_height;
if (mem_type == BRAM) {
cascade_height = mem_depth / CAM_BRAM_DEPTH_MIN;
} else {
cascade_height = mem_depth / (2 * CAM_URAM_DEPTH_MIN);
}
if (cascade_height < 1) {
cascade_height = 1;
}
int v_latency = cam_latency_virt(instance_type, key_width, mem_width,
logic_hi_freq, ram_hi_freq, virtual);
int a_latency = cam_latency_array(instance_type, num_physical_units, key_width, mem_type,
versal, mem_width, mem_depth, cascade_height,
logic_hi_freq, ram_hi_freq, max_macro_height);
int latency = v_latency + a_latency;
return tdm_factor == 1 ? latency + 1 : 1 + latency + 1 + tdm_factor;
}
uint16_t cam_latency(cam_instance_type_t instance_type,
uint16_t num_physical_units,
uint8_t num_slots,
float lookup_rate,
float lookup_interface_freq,
float ram_freq,
uint16_t key_width,
uint16_t list_length,
uint16_t num_lists,
bool flow_control,
cam_mem_type_t mem_type,
bool versal,
bool virtual,
uint8_t max_macro_height,
bool asic)
{
(void) lookup_rate;
if (instance_type == DRAMBCAM) {
return 250;
}
int aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaa1aaa = instance_type == COMPBCAM || instance_type == CSTCAM ? 3 : 1;
int core_latency = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaa1aaa + cam_latency_core(instance_type, num_physical_units, num_slots,
key_width, mem_type, versal, list_length,
num_lists, ram_freq,
virtual, max_macro_height, asic);
int cdc;
cdc = flow_control ? 5 : 7;
int fifo_rd_en_latency = (instance_type == COMPBCAM || instance_type == CSTCAM) && !flow_control && num_slots > 1 ? (num_slots == 2 ? 1 : 2) : 0;
int fifo_output_aaaaaaaaaaaaaaaaaaaaa1aaa = 1;
int req_arbiter = 1;
int fifo_write = 1;
int phase_difference = 1;
int cycle_stealing;
cycle_stealing = (instance_type == COMPBCAM || instance_type == CSTCAM) && !flow_control ? num_slots - 1 : 0;
bool single_clock_mode = ram_freq == lookup_interface_freq ? true : false;
if (single_clock_mode) {
int input_aaaaaaaaaaaaaaaaaaaaa1aaa;
input_aaaaaaaaaaaaaaaaaaaaa1aaa = (instance_type == COMPBCAM || instance_type == CSTCAM) && !flow_control && num_slots > 1 ? 1 : 0;
int flow_control_fifo;
flow_control_fifo = flow_control ? 1+4 : 0;
return input_aaaaaaaaaaaaaaaaaaaaa1aaa + flow_control_fifo + cycle_stealing + 1 + core_latency + 1;
} else {
int core_cycles = cdc + fifo_rd_en_latency + fifo_output_aaaaaaaaaaaaaaaaaaaaa1aaa + req_arbiter + core_latency + fifo_write + phase_difference + cycle_stealing + 1;
float core_cycles_lookup_freq = (core_cycles*lookup_interface_freq) / ram_freq;
int core_cycles_lookup_freq_ceil = (int) core_cycles_lookup_freq;
if (core_cycles_lookup_freq != core_cycles_lookup_freq_ceil) {
core_cycles_lookup_freq_ceil++;
}
return fifo_write + core_cycles_lookup_freq_ceil + cdc;
}
}
uint16_t cam_pipeline_capacity(cam_instance_type_t instance_type,
uint16_t num_physical_units,
uint8_t num_slots,
float lookup_rate,
float lookup_interface_freq,
float ram_freq,
uint16_t key_width,
uint16_t list_length,
uint16_t num_lists,
bool flow_control,
cam_mem_type_t mem_type,
bool versal,
bool virtual,
uint8_t max_macro_height,
bool asic)
{
if (instance_type == DRAMBCAM) {
return 250;
}
int latency = cam_latency(instance_type, num_physical_units, num_slots, lookup_rate,
lookup_interface_freq, ram_freq, key_width,list_length,
num_lists, flow_control, mem_type,
versal, virtual, max_macro_height, asic);
bool single_clock = lookup_interface_freq == ram_freq;
if (single_clock) {
return latency / num_slots;
} else {
return (uint16_t) (latency / (lookup_interface_freq / lookup_rate));
}
}
size_t client_overwrite_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa(void) {
return sizeof(cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat);
}
size_t client_size(void) {
return sizeof(client_t);
}
bool client_is_wide_instance(const client_t *client)
{
if (cam_config_get_key_width(client->conf) > 160) {
return true;
}
return false;
}
void client_get_default_response(const client_t *client, uint8_t *default_response, bool narrow)
{
if (narrow) {
assert(client_is_mixed_mode(client));
cam_config_get_narrow_default_response(client->conf, default_response);
} else
cam_config_get_default_response(client->conf, default_response);
}
bool client_is_mixed_mode(const client_t *client)
{
assert(client != NULL);
return cam_config_is_mixed_mode(client->conf);
}
uint16_t client_get_generation_number_granularity(const client_t *client) {
assert(client != NULL);
return client->conf->arg.generation_number_granularity;
}
bool client_is_tcam(const client_t *client)
{
assert(client != NULL);
return cam_config_is_tcam_instance(client->conf);
}
bool client_is_bcam(const client_t *client)
{
assert(client != NULL);
return cam_config_is_bcam_instance(client->conf);
}
bool client_is_drambcam(const client_t *client)
{
assert(client != NULL);
return cam_config_is_drambcam_instance(client->conf);
}
uint8_t client_get_num_pcs(const client_t *client)
{
assert(client != NULL);
assert((client->conf->instance_type == DRAMBCAM));
return cam_config_get_num_pcs(client->conf);
}
uint8_t client_get_replication(const client_t *client)
{
assert(client != NULL);
assert((client->conf->instance_type == DRAMBCAM));
return cam_config_get_replication(client->conf);
}
uint8_t client_get_num_phys_banks(const client_t *client)
{
assert(client != NULL);
assert((client->conf->instance_type == DRAMBCAM));
return cam_config_get_num_phys_banks(client->conf);
}
uint8_t client_get_depth_cascade(const client_t *client)
{
assert(client != NULL);
assert((client->conf->instance_type == DRAMBCAM));
return cam_config_get_depth_cascade(client->conf);
}
uint32_t client_get_num_entries(const client_t *client)
{
assert(client != NULL);
return cam_config_get_num_entries(client->conf);
}
uint8_t client_get_num_slots(const client_t *client)
{
assert(client != NULL);
return cam_config_get_num_slots(client->conf);
}
uint16_t client_get_list_length(const client_t *client)
{
assert(client != NULL);
return cam_config_get_list_length(client->conf);
}
uint16_t client_get_num_units(const client_t *client)
{
assert(client != NULL);
return cam_config_get_num_units(client->conf);
}
htable_t *client_get_htable(const client_t *client)
{
return client->htable;
}
aaa1aaat *client_get_phm(const client_t *client, uint16_t unit)
{
assert(client != NULL);
assert(unit < client_get_num_units(client));
return client->unit[unit].phm;
}
void set_open(client_t *client, uint16_t unit)
{
assert(client != NULL);
assert(unit < client_get_num_units(client));
client->unit[unit].unit_mode = OPEN;
}
void set_closed(client_t *client, uint16_t unit) {
assert(client != NULL);
assert(unit < client_get_num_units(client));
client->unit[unit].unit_mode = CLOSED;
}
bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaunused(const client_t *client, uint16_t *start_value)
{
assert(client != NULL);
const uint16_t number_of_units = client_get_num_units(client);
for (uint16_t i = *start_value; i < number_of_units; i++) {
if (client->unit[i].unit_mode == UNUSED) {
*start_value = i;
return true;
}
}
return false;
}
void set_unused(client_t *client, uint16_t unit)
{
assert(client != NULL);
assert(unit < client_get_num_units(client));
client->unit[unit].unit_mode = UNUSED;
client->zero_unused = false;
}
static bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen(const client_t *client, uint16_t *start_value)
{
assert(client != NULL);
const uint16_t number_of_units = client_get_num_units(client);
for (uint16_t i = *start_value; i < number_of_units; i++) {
if ((client->unit[i].unit_mode == OPEN)) {
*start_value = i;
return true;
}
}
return false;
}
bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen_or_closed(const client_t *client, uint16_t *start_value)
{
assert(client != NULL);
const uint16_t number_of_units = client_get_num_units(client);
for (uint16_t i = *start_value; i < number_of_units; i++) {
if ((client->unit[i].unit_mode == OPEN) || (client->unit[i].unit_mode == CLOSED)) {
*start_value = i;
return true;
}
}
return false;
}
bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen_with_equal_mask(const client_t *client, uint16_t *start_value,
const aaaaaaaaaaaaa1aaat *mask,
uint8_t range_valid, uint8_t mask_id)
{
while (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen(client, start_value)) {
assert((*start_value) < client_get_num_units(client));
const aaa1aaat *phm = client->unit[*start_value].phm;
assert(aaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaavalid(phm));
if (aaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaequal(phm, mask, range_valid, mask_id)) {
return true;
}
(*start_value)++;
}
return false;
}
uint8_t client_get_num_ranges(const client_t *client)
{
return cam_config_get_num_ranges(client->conf);
}
void write_mask(client_t *client, const aaaaaaaaaaaaa1aaat *mask, uint16_t unit,
uint8_t range_valid, uint8_t mask_id)
{
assert(client != NULL);
aaa1aaat *phm = client_get_phm(client, unit);
aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6aaa(phm, mask, unit, range_valid, mask_id);
}
uint16_t client_get_narrow_key_width(const client_t *client)
{
return cam_config_get_narrow_key_width(client->conf);
}
uint16_t client_get_key_width(const client_t *client)
{
return cam_config_get_key_width(client->conf);
}
uint8_t client_get_prio_width(const client_t *client)
{
return cam_config_get_prio_width(client->conf);
}
uint16_t client_get_response_width(const client_t *client)
{
return cam_config_get_response_width(client->conf);
}
uint32_t client_get_num_lists(const client_t *client)
{
return cam_config_get_num_lists(client->conf);
}
uint32_t client_get_ram_size(const client_t *client)
{
return cam_config_get_ram_size(client->conf);
}
uint16_t client_get_channel_width(const client_t *client) {
return cam_config_get_channel_width(client->conf);
}
uint16_t client_get_segment(const client_t *client)
{
return cam_config_get_segment(client->conf);
}
void client_table_print(const client_t *client)
{
uint32_t number_of_entries = 0;
uint16_t start_value = 0;
while (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen_or_closed(client, &start_value)) {
const aaa1aaat *phm = client_get_phm(client, start_value);
const uint16_t number_of_keys = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(phm);
number_of_entries = number_of_entries + number_of_keys;
aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm);
start_value++;
}
printf(
           "\nNumber_of_entries = %"PRIu32"", number_of_entries);
}
void client_drambaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaread(client_t *client, uint32_t address, uint32_t data[])
{
cam_hw_write(client->conf, aaaaaa1aaaDRAMBCAM_ADDRESS_aaaaaaaaaaaaaaaaaaaaa1aaa, address);
cam_hw_write(client->conf, aaaaaa1aaaDRAMBCAM_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaa, 0);
const uint16_t list_length = client_get_list_length(client);
const uint16_t stop_slice = list_length / 256;
for (uint8_t slice = 0; slice < stop_slice; slice++) {
for (uint16_t j = 0; j < 8; j++) {
cam_hw_read(client->conf,
aaaaaa1aaaDRAMBCAM_DATA_READ_START_aaaaaaaaaaaaaaaaaaaaa1aaa + j * 4, &data[slice * 8 + j]);
}
}
}
void client_start_serialize(const client_t *client)
{
if (client->conf->arg.hw_write_start_sequence_function != NULL) {
client->conf->arg.hw_write_start_sequence_function(client->conf->ctx);
}
}
void client_end_serialize(client_t *client)
{
if (client->conf->arg.vc_seg_map.vcid != client->conf->arg.segment_ctx.segment) {
client->prev_hi_addr_unknown = true;
client->prev_hi_data_unknown = true;
}
if (client->conf->arg.hw_write_end_sequence_function != NULL) {
client->conf->arg.hw_write_end_sequence_function(client->conf->ctx);
}
}
#if 0
static bool has_generation_number(const client_t *client, uint8_t idx, uint32_t data, uint8_t *generation_number) {
uint16_t granularity = client_get_generation_number_granularity(client);
if (granularity == 0)
return false;
const uint16_t g = granularity / 32;
if (((idx - (idx / g) * g) == (g - 1))) {
*generation_number = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(data, 31, 1);
return true;
}
return false;
}
#endif
void client_drambaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(client_t *client, uint32_t address, uint32_t data[], uint8_t write_mask,
operation_t operation, bool bit511or255, uint16_t fingerprint)
{
cam_hw_write(client->conf, aaaaaa1aaaDRAMBCAM_ADDRESS_aaaaaaaaaaaaaaaaaaaaa1aaa, address);
uint8_t slice_shift = write_mask;
if (client->conf->arg.channel_width == 512) {
if ((slice_shift & 3) > 0)
slice_shift = slice_shift | 3;
if ((slice_shift & 12) > 0)
slice_shift = slice_shift | 12;
}
assert((slice_shift & 0xf) != 0);
uint8_t num_writes = 0;
for (uint8_t slice = 0; slice < 4; slice++) {
if ((slice_shift & 1) == 0) {
slice_shift = slice_shift >> 1;
continue;
}
slice_shift = slice_shift >> 1;
for (uint16_t i = 0; i < 8; i++) {
const uint32_t idx = slice * 8 + i;
const uint32_t aaaaaaaaaaaaaaaaaaaaa1aaa = num_writes * 8 + i;
cam_hw_write(client->conf,
aaaaaa1aaaDRAMBCAM_DATA_WRITE_START_aaaaaaaaaaaaaaaaaaaaa1aaa + aaaaaaaaaaaaaaaaaaaaa1aaa * 4, data[idx]);
#if 0
uint8_t generation_number;
if (has_generation_number(client, idx, data[idx], &generation_number)) {
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaagen_test) {
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaagen_test = false;
prev_gen = generation_number;
} else if (prev_gen != generation_number)
assert(false);
}
#endif
}
num_writes++;
}
uint32_t aaaaaaaaaaaaaaaaaaaaaaaaa1aaa = (write_mask << 4) | 1;
if (operation == UPDATE) {
assert(!bit511or255);
aaaaaaaaaaaaaaaaaaaaaaaaa1aaa = aaaaaaaaaaaaaaaaaaaaaaaaa1aaa | 4;
aaaaaaaaaaaaaaaaaaaaaaaaa1aaa = aaaaaaaaaaaaaaaaaaaaaaaaa1aaa | (client->conf->arg.vc_id << 8); 
} else if (operation == DELETE) {
aaaaaaaaaaaaaaaaaaaaaaaaa1aaa = aaaaaaaaaaaaaaaaaaaaaaaaa1aaa | 2; 
if (bit511or255) {
if ((write_mask == 0xf) || (write_mask == 0x3) || (write_mask == 0xc)) {
aaaaaaaaaaaaaaaaaaaaaaaaa1aaa = aaaaaaaaaaaaaaaaaaaaaaaaa1aaa | 8; 
} else {
assert(false);
}
}
aaaaaaaaaaaaaaaaaaaaaaaaa1aaa = aaaaaaaaaaaaaaaaaaaaaaaaa1aaa | (client->conf->arg.vc_id << 8); 
} else {
assert(!bit511or255);
assert(operation == OTHER);
}
aaaaaaaaaaaaaaaaaaaaaaaaa1aaa = aaaaaaaaaaaaaaaaaaaaaaaaa1aaa | (fingerprint << 16);
cam_hw_write(client->conf, aaaaaa1aaaDRAMBCAM_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaa, aaaaaaaaaaaaaaaaaaaaaaaaa1aaa);
if (client_get_debug_flags(client) & CAM_DEBUG_VERIFY_WR) {
char message[256];
uint32_t read_data[32];
client_drambaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaread(client, address, &read_data[0]);
uint8_t slice_shift = write_mask;
if (client->conf->arg.channel_width == 512) {
if ((slice_shift & 3) > 0)
slice_shift = slice_shift | 3;
if ((slice_shift & 12) > 0)
slice_shift = slice_shift | 12;
}
for (uint8_t slice = 0; slice < 4; slice++) {
if ((slice_shift & 1) == 0) {
slice_shift = slice_shift >> 1;
continue;
}
slice_shift = slice_shift >> 1;
for (uint16_t j = 0; j < 8; j++) {
const uint8_t idx = slice * 8 + j;
if (read_data[idx] != data[idx]) {
sprintf(message,
                           "CAM_DEBUG_VERIFY_WR      address = 0x%08" PRIx32 "  aaaaaaaaaaaaaaaaaaaaaaaaa1aaa = 0x%08" PRIx32 "  data 0x%02" PRIx8 " = 0x%08" PRIx32 "  expected data = 0x%08" PRIx32 "     FAIL",
address, aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, idx, read_data[idx], data[idx]);
client_print_error(client, message);
} else if (client_get_debug_flags(client) & CAM_DEBUG_VERBOSE_VERIFY) {
sprintf(message,
                           "CAM_DEBUG_VERIFY_WR      address = 0x%08" PRIx32 "  aaaaaaaaaaaaaaaaaaaaaaaaa1aaa = 0x%08" PRIx32 "  data 0x%02" PRIx8 " = 0x%08" PRIx32 "  expected data = 0x%08" PRIx32 "     OK",
address, aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, idx, read_data[idx], data[idx]);
client_print_info(client, message);
}
}
}
}
}
void client_hw_write(client_t *client, uint32_t address, uint64_t data)
{
uint32_t hi_addr = address & aaaaaa1bbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaR_MASK;
if (client->prev_hi_addr_unknown || (hi_addr != client->prev_hi_addr)) {
client->prev_hi_addr = hi_addr;
client->prev_hi_addr_unknown = false;
cam_hw_write(client->conf, aaaaaa1aaaHA_BASE, address >> aaaaaa1bbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaR_aaaaaaaaaaaaaaaaaaaaaa1aaa);
}
uint32_t hi_data = data >> 32;
if (client->prev_hi_data_unknown || (hi_data != client->prev_hi_data)) {
client->prev_hi_data = hi_data;
client->prev_hi_data_unknown = false;
cam_hw_write(client->conf, aaaaaa1aaaHD_BASE, hi_data);
}
uint32_t lo_addr = address & aaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaR_MASK;
cam_hw_write(client->conf, lo_addr, (uint32_t) data);
if (client_get_debug_flags(client) & CAM_DEBUG_VERIFY_WR) {
char message[500];
uint64_t read_data = 0;
client_hw_read(client, address, &read_data);
if (read_data != data) {
           sprintf(message, "CAM_DEBUG_VERIFY_WR      address = 0x%08" PRIx32 "  data = 0x%016" PRIx64 "  expected data = 0x%016" PRIx64 "     FAIL",
address, read_data, data);
client_print_error(client, message);
} else if (client_get_debug_flags(client) & CAM_DEBUG_VERBOSE_VERIFY) {
           sprintf(message, "CAM_DEBUG_VERIFY_WR      address = 0x%08" PRIx32 "  data = 0x%016" PRIx64 "  expected data = 0x%016" PRIx64 "     OK",
address, read_data, data);
client_print_info(client, message);
}
}
}
void client_hw_read(client_t *client, uint32_t address, uint64_t *data)
{
uint32_t lo_addr = address & aaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaR_MASK;
uint32_t hi_addr = address & aaaaaa1bbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaR_MASK;
if (client->prev_hi_addr_unknown || hi_addr != client->prev_hi_addr) {
client->prev_hi_addr = hi_addr;
client->prev_hi_addr_unknown = false;
cam_hw_write(client->conf, aaaaaa1aaaHA_BASE, address >> aaaaaa1bbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaR_aaaaaaaaaaaaaaaaaaaaaa1aaa);
}
uint32_t *data32 = (uint32_t *) data;
cam_hw_read(client->conf, lo_addr, data32);
lo_addr = (address + 4) & aaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaR_MASK;
hi_addr = (address + 4) & aaaaaa1bbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaR_MASK;
if (client->prev_hi_addr_unknown || hi_addr != client->prev_hi_addr) {
client->prev_hi_addr = hi_addr;
client->prev_hi_addr_unknown = false;
cam_hw_write(client->conf, aaaaaa1aaaHA_BASE, address >> aaaaaa1bbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaR_aaaaaaaaaaaaaaaaaaaaaa1aaa);
}
data32++;
cam_hw_read(client->conf, lo_addr, data32);
}
int client_read_and_clear_ecc_counters(client_t *client, uint32_t *corrected_single_bit_errors,
uint32_t *detected_double_bit_errors)
{
if (client_is_drambcam(client))
return CAM_ERROR_UNSUPPORTED_COMMAND;
uint64_t data = 0;
client_start_serialize(client);
client_hw_read(client, aaaaaa1aaaECC_BASE, &data);
client_end_serialize(client);
*corrected_single_bit_errors = data & 0xffffffff;
*detected_double_bit_errors = (data >> 32) & 0xffffffff;
return 0;
}
int client_read_and_clear_ecc_addresses(client_t *client,
uint32_t *failing_address_single_bit_error,
uint32_t *failing_address_double_bit_error)
{
if (client_is_drambcam(client))
return CAM_ERROR_UNSUPPORTED_COMMAND;
uint64_t data = 0;
client_start_serialize(client);
client_hw_read(client, aaaaaa1aaaECC_BASE + 2 * aaaaaa1aaaECC_WORD, &data);
client_end_serialize(client);
*failing_address_single_bit_error = data & 0xffffffff;
*failing_address_double_bit_error = (data >> 32) & 0xffffffff;
return 0;
}
int client_set_ecc_test(client_t *client,
bool inject_single_bit_errors,
bool inject_double_bit_errors)
{
if (client_is_drambcam(client))
return CAM_ERROR_UNSUPPORTED_COMMAND;
uint64_t data = (inject_single_bit_errors ? 1 : 0) +
(inject_double_bit_errors ? 2 : 0);
client_start_serialize(client);
client_hw_write(client, aaaaaa1aaaECC_BASE + 4 * aaaaaa1aaaECC_WORD, data);
client_end_serialize(client);
return 0;
}
void client_set_debug_flags(const client_t *client, uint32_t debug_flags)
{
client->conf->arg.debug_flags = debug_flags;
}
uint32_t client_get_debug_flags(const client_t *client)
{
return client->conf->arg.debug_flags;
}
uint8_t client_get_hash_function(const client_t *client) {
return client->conf->arg.hash_function;
}
void client_print_error(const client_t *client, char *message) {
client->conf->arg.error_print_function(client->conf->ctx, message);
}
void client_print_info(const client_t *client, char *message) {
client->conf->arg.info_print_function(client->conf->ctx, message);
}
int verify_config(client_t *client)
{
char sub_str[512];
char message[1024];
cam_config_t hw_conf;
cam_config_t *sw_conf = client->conf;
uint64_t data = 0;
int rc = CAM_OK;
client_start_serialize(client);
client_hw_read(client, aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb5aaa, &data);
hw_conf.key_width = data & 0xffffffff;
hw_conf.prio_width = (data >> 32) & 0xffffffff;
client_hw_read(client, aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaRESP_WIDTH, &data);
hw_conf.arg.response_width = data & 0xffffffff;
hw_conf.num_physical_units = (data >> 32) & 0xffffffff;
client_hw_read(client, aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaFACTOR, &data);
hw_conf.num_slots = data & 0xffffffff;
hw_conf.num_units = hw_conf.num_physical_units * hw_conf.num_slots;
hw_conf.list_length = (data >> 32) & 0xffffffff;
client_hw_read(client, aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaRAM_DEPTH, &data);
if (hw_conf.num_slots != 0) {
hw_conf.num_lists = (data & 0xffffffff) / hw_conf.num_slots;
} else {
hw_conf.num_lists = 0;
}
hw_conf.instance_type = (cam_instance_type_t) ((data >> 32) & 0xffffffff);
client_hw_read(client, aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaa6aaa, &data);
hw_conf.num_ranges = (data >> 32) & 0xffffffff;
for (int r = 0; r < CAM_CONFIG_MAX_RANGES; r += 2) {
client_hw_read(client, aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaPOS + r * aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaWORD, &data);
hw_conf.range_start_pos[r] = data & 0xffffffff;
hw_conf.range_start_pos[r + 1] = (data >> 32) & 0xffffffff;
}
for (int r = 0; r < CAM_CONFIG_MAX_RANGES; r += 2) {
client_hw_read(client, aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb5aaa + r * aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaWORD, &data);
hw_conf.range_width[r] = data & 0xffffffff;
hw_conf.range_width[r + 1] = (data >> 32) & 0xffffffff;
}
client_hw_read(client, aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaBUILD_NUM, &data);
const uint32_t build_num = data & 0xffffffff;
const bool asic = (data >> 32) == 1;
client_hw_read(client, aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaAGING_EN, &data);
hw_conf.hw_stats_enabled = (data >> 32) == 1;
sw_conf->hw_stats_enabled = hw_conf.hw_stats_enabled;
client_hw_read(client, aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaVERSION, &data);
const uint8_t major = (data & 0xff00) >> 8;
const uint8_t minor = (data & 0x00f0) >> 4;
const uint8_t patch = data & 0xf;
char patch_str[10];
if (patch == 0)
patch_str[0] = '\0';
else
       sprintf(patch_str, ".%d", patch);
bool err = (major != CAM_SW_VERSION_MAJOR) || (minor > CAM_SW_VERSION_MINOR);
if (err) {
rc = CAM_ERROR_CONFIGURATION;
       sprintf(message, "%-26sVerification of hardware/software parameters is enabled by default, and requires a hardware read function.", cam_error_string(rc));
client_print_error(client, message);
       sprintf(message, "%-26sUse 'cam_arg_set_hw_read_function' to specify the hardware read function.", cam_error_string(rc));
client_print_error(client, message);
       sprintf(message, "%-26sUse the debug switch 'CAM_DEBUG_SKIP_VERIFY_CONFIG' to disable verification of hardware/software parameters", cam_error_string(rc));
client_print_error(client, message);
}
if (err || (client_get_debug_flags(client) & CAM_DEBUG_VERBOSE_VERIFY)) {
if (err) {
rc = CAM_ERROR_CONFIGURATION;
}
       sprintf(sub_str, "HW version     = %d.%d%s (expected %d.0 to %d.%d)",
major, minor, patch_str,
CAM_SW_VERSION_MAJOR, CAM_SW_VERSION_MAJOR, CAM_SW_VERSION_MINOR);
       sprintf(message, "%-26s%-70s%s",
               err ? cam_error_string(rc) : "CAM_DEBUG_VERBOSE_VERIFY",
               sub_str, err ? "FAIL" : "OK");
if (err) {
client_print_error(client, message);
} else {
client_print_info(client, message);
}
}
err = sw_conf->instance_type != hw_conf.instance_type;
if (err || (client_get_debug_flags(client) & CAM_DEBUG_VERBOSE_VERIFY)) {
if (err) {
rc = CAM_ERROR_CONFIGURATION;
}
const char *sw_inst;
switch (sw_conf->instance_type) {
case TCAM:
           sw_inst = "TCAM";
break;
case BCAM:
           sw_inst = "BCAM";
break;
case STCAM:
           sw_inst = "STCAM";
break;
case DRAMBCAM:
           sw_inst = "DRAMBCAM";
break;
case COMPBCAM:
           sw_inst = "CBCAM";
break;
case CSTCAM:
           sw_inst = "CSTCAM";
break;
default :
           sw_inst = "UNKNOWN";
break;
}
const char *hw_inst;
switch (hw_conf.instance_type) {
case TCAM:
           hw_inst = "TCAM";
break;
case BCAM:
           hw_inst = "BCAM";
break;
case STCAM:
           hw_inst = "STCAM";
break;
case DRAMBCAM:
           hw_inst = "DRAMBCAM";
break;
case COMPBCAM:
           hw_inst = "CBCAM";
break;
case CSTCAM:
           hw_inst = "CSTCAM";
break;
default :
           hw_inst = "UNKNOWN";
break;
}
       sprintf(sub_str, "TYPE           = %s (expected %s)",
hw_inst, sw_inst);
       sprintf(message, "%-26s%-70s%s",
               err ? cam_error_string(rc) : "CAM_DEBUG_VERBOSE_VERIFY",
               sub_str, err ? "FAIL" : "OK");
if (err) {
client_print_error(client, message);
} else {
client_print_info(client, message);
}
}
err = sw_conf->key_width != hw_conf.key_width;
if (err || (client_get_debug_flags(client) & CAM_DEBUG_VERBOSE_VERIFY)) {
if (err) {
rc = CAM_ERROR_CONFIGURATION;
}
       sprintf(sub_str, "KEY_WIDTH      = %d (expected %d)",
hw_conf.key_width, sw_conf->key_width);
       sprintf(message, "%-26s%-70s%s",
               err ? cam_error_string(rc) : "CAM_DEBUG_VERBOSE_VERIFY",
               sub_str, err ? "FAIL" : "OK");
if (err) {
client_print_error(client, message);
} else {
client_print_info(client, message);
}
}
err = sw_conf->arg.response_width != hw_conf.arg.response_width;
if (err || (client_get_debug_flags(client) & CAM_DEBUG_VERBOSE_VERIFY)) {
if (err) {
rc = CAM_ERROR_CONFIGURATION;
}
       sprintf(sub_str, "RESPONSE_WIDTH = %d (expected %d)",
hw_conf.arg.response_width, sw_conf->arg.response_width);
       sprintf(message, "%-26s%-70s%s",
               err ? cam_error_string(rc) : "CAM_DEBUG_VERBOSE_VERIFY",
               sub_str, err ? "FAIL" : "OK");
if (err) {
client_print_error(client, message);
} else {
client_print_info(client, message);
}
}
if (sw_conf->instance_type == TCAM || sw_conf->instance_type == STCAM) {
err = sw_conf->prio_width != hw_conf.prio_width;
if (err || (client_get_debug_flags(client) & CAM_DEBUG_VERBOSE_VERIFY)) {
if (err) {
rc = CAM_ERROR_CONFIGURATION;
}
           sprintf(sub_str, "PRIORITY_WIDTH = %d (expected %d)",
hw_conf.prio_width, sw_conf->prio_width);
           sprintf(message, "%-26s%-70s%s",
                   err ? cam_error_string(rc) : "CAM_DEBUG_VERBOSE_VERIFY",
                   sub_str, err ? "FAIL" : "OK");
if (err) {
client_print_error(client, message);
} else {
client_print_info(client, message);
}
}
}
if (sw_conf->instance_type == TCAM) {
err = sw_conf->num_ranges != hw_conf.num_ranges;
if (err || (client_get_debug_flags(client) & CAM_DEBUG_VERBOSE_VERIFY)) {
if (err) {
rc = CAM_ERROR_CONFIGURATION;
}
           sprintf(sub_str, "NUM_RANGES     = %d (expected %d)",
hw_conf.num_ranges, sw_conf->num_ranges);
           sprintf(message, "%-26s%-70s%s",
                   err ? cam_error_string(rc) : "CAM_DEBUG_VERBOSE_VERIFY",
                   sub_str, err ? "FAIL" : "OK");
if (err) {
client_print_error(client, message);
} else {
client_print_info(client, message);
}
}
for (int r = 0; r < sw_conf->num_ranges; r++) {
err = sw_conf->range_width[r] != hw_conf.range_width[r];
if (err || (client_get_debug_flags(client) & CAM_DEBUG_VERBOSE_VERIFY)) {
if (err) {
rc = CAM_ERROR_CONFIGURATION;
}
               sprintf(sub_str, "RANGE_WIDTH[%d] = %d (expected %d)",
r, hw_conf.range_width[r], sw_conf->range_width[r]);
               sprintf(message, "%-26s%-70s%s",
                       err ? cam_error_string(rc) : "CAM_DEBUG_VERBOSE_VERIFY",
                       sub_str, err ? "FAIL" : "OK");
if (err) {
client_print_error(client, message);
} else {
client_print_info(client, message);
}
}
}
for (int r = 0; r < sw_conf->num_ranges; r++) {
err = sw_conf->range_start_pos[r] != hw_conf.range_start_pos[r];
if (err || (client_get_debug_flags(client) & CAM_DEBUG_VERBOSE_VERIFY)) {
if (err) {
rc = CAM_ERROR_CONFIGURATION;
}
               sprintf(sub_str, "RANGE_POS[%d]   = %d (expected %d)",
r, hw_conf.range_start_pos[r], sw_conf->range_start_pos[r]);
               sprintf(message, "%-26s%-70s%s",
                       err ? cam_error_string(rc) : "CAM_DEBUG_VERBOSE_VERIFY",
                       sub_str, err ? "FAIL" : "OK");
if (err) {
client_print_error(client, message);
} else {
client_print_info(client, message);
}
}
}
}
err = sw_conf->list_length != hw_conf.list_length;
if (err || (client_get_debug_flags(client) & CAM_DEBUG_VERBOSE_VERIFY)) {
if (err) {
rc = CAM_ERROR_CONFIGURATION;
}
       sprintf(sub_str, "RAM_WIDTH      = %d (expected %d)",
hw_conf.list_length, sw_conf->list_length);
       sprintf(message, "%-26s%-70s%s",
               err ? cam_error_string(rc) : "CAM_DEBUG_VERBOSE_VERIFY",
               sub_str, err ? "FAIL" : "OK");
if (err) {
client_print_error(client, message);
} else {
client_print_info(client, message);
}
}
err = sw_conf->num_lists != hw_conf.num_lists;
if (err || (client_get_debug_flags(client) & CAM_DEBUG_VERBOSE_VERIFY)) {
if (err) {
rc = CAM_ERROR_CONFIGURATION;
}
       sprintf(sub_str, "RAM_DEPTH      = %"PRIu32" (expected %"PRIu32")",
hw_conf.num_lists * hw_conf.num_slots,
sw_conf->num_lists * sw_conf->num_slots);
       sprintf(message, "%-26s%-70s%s",
               err ? cam_error_string(rc) : "CAM_DEBUG_VERBOSE_VERIFY",
               sub_str, err ? "FAIL" : "OK");
if (err) {
client_print_error(client, message);
} else {
client_print_info(client, message);
}
}
err = sw_conf->num_physical_units != hw_conf.num_physical_units;
if (err || (client_get_debug_flags(client) & CAM_DEBUG_VERBOSE_VERIFY)) {
if (err) {
rc = CAM_ERROR_CONFIGURATION;
}
       sprintf(sub_str, "P_MEM_UNITS    = %d (expected %d)",
hw_conf.num_physical_units, sw_conf->num_physical_units);
       sprintf(message, "%-26s%-70s%s",
               err ? cam_error_string(rc) : "CAM_DEBUG_VERBOSE_VERIFY",
               sub_str, err ? "FAIL" : "OK");
if (err) {
client_print_error(client, message);
} else {
client_print_info(client, message);
}
}
err = sw_conf->num_slots != hw_conf.num_slots;
if (err || (client_get_debug_flags(client) & CAM_DEBUG_VERBOSE_VERIFY)) {
if (err) {
rc = CAM_ERROR_CONFIGURATION;
}
       sprintf(sub_str, "TDM_FACTOR     = %d (expected %d)",
hw_conf.num_slots, sw_conf->num_slots);
       sprintf(message, "%-26s%-70s%s",
               err ? cam_error_string(rc) : "CAM_DEBUG_VERBOSE_VERIFY",
               sub_str, err ? "FAIL" : "OK");
if (err) {
client_print_error(client, message);
} else {
client_print_info(client, message);
}
}
const uint32_t addr = aaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaSCRATCH;
const uint64_t test_data = build_num >= 3163136 || build_num == 0 ? 0xfedcba9876543210 : 0xabcd0123;
uint64_t read_data = 0;
client_hw_write(client, addr, test_data);
client_hw_read(client, addr, &read_data);
err = read_data != test_data;
if (err || (client_get_debug_flags(client) & CAM_DEBUG_VERBOSE_VERIFY)) {
if (err) {
rc = CAM_ERROR_CONFIGURATION;
}
       sprintf(sub_str, "Scratch read-back = 0x%016" PRIx64 " (expected 0x%016" PRIx64 ")",
read_data, test_data);
       sprintf(message, "%-26s%-70s%s",
               err ? cam_error_string(rc) : "CAM_DEBUG_VERBOSE_VERIFY",
               sub_str, err ? "FAIL" : "OK");
if (err) {
client_print_error(client, message);
} else {
client_print_info(client, message);
}
}
client_end_serialize(client);
if (client_get_debug_flags(client) & CAM_DEBUG_CONFIG) {
       sprintf(message, "HW Version %"PRIu8".%"PRIu8"%s, Build %"PRIu32"  %s",
               major, minor, patch_str, build_num, asic ? "ASIC" : "");
client_print_info(client, message);
}
return rc;
}
void client_flush(const client_t *client)
{
assert(client != NULL);
char message[500];
if (client_get_debug_flags(client) & CAM_DEBUG_ARGS) {
       sprintf(message, "CAM_DEBUG_ARGS  memory rewrite");
client_print_info(client, message);
}
const uint16_t num_units = cam_config_get_num_units(client->conf);
for (uint16_t i = 0; i < num_units; i++) {
aaa1bbbbbbbbbbbbbbbbbbb3aaa(client->unit[i].phm, client);
}
}
cam_free_func client_get_free_function(const client_t* client)
{
return(client->conf->arg.free_function);
}
cam_posix_memalign_func client_get_posix_memalign_function(const client_t* client) {
return (client->conf->arg.posix_memalign_function);
}
cam_malloc_func client_get_malloc_function(const client_t* client)
{
return(client->conf->arg.malloc_function);
}
cam_realloc_func client_get_realloc_function(const client_t* client) {
return (client->conf->arg.realloc_function);
}
cam_calloc_func client_get_calloc_function(const client_t* client)
{
return(client->conf->arg.calloc_function);
}
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa (0x100)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa (0x104)
#define aaaaaaaaaaaaaaaaaaaa1aaaRESP_WIDTH (0x108)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaaS (0x10C)
#define aaaaaaaaaaaaaaaaaaaa1aaaTIME_SLOTS (0x110)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaa1aaaDATA (0x114)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaR (0x118)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa (0x11C)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaa4aaa (0x120)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaS (0x130)
#define aaaaaaaaaaaaaaaaaaaa1aaaCACHE_EN (0x134)
#define aaaaaaaaaaaaaaaaaaaa1aaaSBITERR_CNT (0x300)
#define aaaaaaaaaaaaaaaaaaaa1aaaDBITERR_CNT (0x304)
#define aaaaaaaaaaaaaaaaaaaa1aaaSBITERR_FFA (0x308)
#define aaaaaaaaaaaaaaaaaaaa1aaaDBITERR_FFA (0x30C)
#define aaaaaaaaaaaaaaaaaaaa1aaaECC_TEST (0x310)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x20000)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP_KEY (0x400)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP_RESPONSE (0x480)
#define aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP_STATUS (0x500)
int client_read_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup_data(client_t *client, struct cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup *aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup) {
if (client_is_drambcam(client))
return CAM_ERROR_STATISTICS_NOT_AVAILABLE;
if (!client->conf->hw_stats_enabled)
return CAM_ERROR_STATISTICS_NOT_AVAILABLE;
const uint8_t key_num_words64 = client->conf->key_width / 64;
client_start_serialize(client);
for (uint8_t i = 0; i < key_num_words64; i++) {
client_hw_read(client, aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP_KEY + i * 8, (uint64_t *) &(aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup->key[i * 8]));
}
const uint8_t key_rem_bits = cam_config_get_key_width(client->conf) - key_num_words64 * 64;
if (key_rem_bits) {
uint64_t rem_word64 = 0;
client_hw_read(client, aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP_KEY + key_num_words64 * 8, &rem_word64);
cam_write_field8((uint8_t *) &aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup->key[key_num_words64 * 8], (uint8_t *) &rem_word64, 0, key_rem_bits);
}
const uint8_t response_num_words64 = cam_config_get_response_width(client->conf) / 64;
for (uint8_t i = 0; i < response_num_words64; i++) {
client_hw_read(client, aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP_RESPONSE + i * 8,
(uint64_t *) &(aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup->response[i * 8]));
}
const uint8_t response_rem_bits = cam_config_get_response_width(client->conf) - response_num_words64 * 64;
if (response_rem_bits) {
uint64_t rem_word64 = 0;
client_hw_read(client, aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP_RESPONSE + response_num_words64 * 8, &rem_word64);
cam_write_field8((uint8_t *) &aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup->response[response_num_words64 * 8], (uint8_t *) &rem_word64, 0,
response_rem_bits);
}
uint64_t status;
client_hw_read(client, aaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP_STATUS, &status);
client_end_serialize(client);
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup->status = status & 0xffffffff;
return 0;
}
uint32_t client_get_current_num_entries(const client_t *client)
{
uint32_t number_of_entries = 0;
uint16_t start_value = 0;
while (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen_or_closed(client, &start_value)) {
const aaa1aaat *phm = client_get_phm(client, start_value);
const uint32_t number_of_keys = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(phm);
number_of_entries = number_of_entries + number_of_keys;
start_value++;
}
if (!client_is_tcam(client))
assert(client->num_entries == number_of_entries);
return number_of_entries;
}
static uint16_t get_number_of_unused_units(const client_t *client)
{
assert(client != NULL);
const uint16_t number_of_units = client_get_num_units(client);
uint16_t count = 0;
for (uint16_t i = 0; i < number_of_units; i++) {
if (client->unit[i].unit_mode == UNUSED) {
count++;
}
}
return count;
}
void client_print(const client_t *client)
{
int entries = 0;
const uint8_t num_slots = client_get_num_slots(client);
const uint32_t max_lists = client_get_num_lists(client);
   printf("\nLUnit\tMode\tMask\t\t\t\t\t\t\t\t\t\t\tSize\tKeys\tRValid\tMaskId\tSeed\tPUnit\tSlot");
const uint16_t num_units = client_get_num_units(client);
for (uint16_t unit = 0; unit < num_units; unit++) {
const aaa1aaat *phm = client->unit[unit].phm;
const uint8_t slot_number = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(phm);
const uint16_t physical_unit = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(phm);
       printf("\n%d\t", unit);
if (client->unit[unit].unit_mode == UNUSED) {
           printf("UNUSED\t\t");
           printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%d\t%d", physical_unit, slot_number);
} else if (client->unit[unit].unit_mode == RECOVER) {
           printf("REHASH\t\t");
           printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%d\t%d", physical_unit, slot_number);
} else if (client->unit[unit].unit_mode == CLOSED) {
           printf("CLOSED\t");
} else if (client->unit[unit].unit_mode == OPEN) {
           printf("OPEN\t");
}
if (aaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaavalid(phm)) {
aaaaaaaaaaaaa1aaat mask;
memset(&mask, 0, sizeof(aaaaaaaaaaaaa1aaat));
uint8_t range_valid, mask_id;
aaa1aaaread_mask(phm, &mask, &range_valid, &mask_id);
const uint16_t seed = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaseed(phm);
for (int8_t j = 9; j >= 0; j--) {
               printf("%08"PRIx32"", mask.word[j]);
}
           printf("\t%"PRIu32"\t%"PRIu32"", max_lists, aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(phm));
entries += aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(phm);
           printf("\t%d\t%d\t%d\t%d\t%d", range_valid, mask_id, seed, physical_unit, slot_number);
}
}
   printf("\nNumber of physical units = %d, Number of slots = %d\n",
(num_units - 1) / num_slots + 1, num_slots);
   printf("\nNumber of logical units = %d", num_units);
   printf("\nNumber of entries = %d, number of unused units = %d\n", entries, get_number_of_unused_units(client));
}
void client_get_sw_stats(client_t *client, struct cam_sw *sw) {
sw->num_entries = client->num_entries;
sw->narrow_num_entries = client->num_entries;
sw->num_inserts = client->num_inserts;
sw->num_updates = client->num_updates;
sw->num_deletes = client->num_deletes;
sw->failed_inserts = client->failed_inserts;
sw->failed_updates = client->failed_updates;
sw->failed_deletes = client->failed_deletes;
sw->num_collisions = client->num_collisions;
sw->max_collisions = client->max_collisions;
sw->num_used_masks = client->num_used_masks;
sw->num_shadow_writes = client->num_shadow_writes;
}
#define CUE_POLL_aaaaaaaaaaaaaaaaaaaaaaaa1aaa (300000)
static int cue_translate(enum cue_status result)
{
switch(result) {
case CUE_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaDUPLICATE: return CAM_ERROR_DUPLICATE_FOUND;
case CUE_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaFULL: return CAM_ERROR_FULL;
case CUE_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaSUCCESS: return 0;
case CUE_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaNOT_FOUND: return CAM_ERROR_KEY_NOT_FOUND;
case CUE_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaBUS_ERROR: return CAM_ERROR_ENVIRONMENT;
case CUE_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaTIMEOUT: return CAM_ERROR_ENVIRONMENT_POLLED_OUT;
default:
assert(0);
return CAM_ERROR_ENVIRONMENT;
}
}
static uint32_t cue_read(client_t *client, uint32_t address)
{
uint32_t data = 0;
cam_hw_read(client->conf, address, &data);
return data;
}
static void cue_write(client_t *client, uint32_t address, uint32_t data)
{
cam_hw_write(client->conf, address, data);
}
static int cue_printf(client_t *client, const char *fmt, ...)
{
char buffer[4096];
va_list args;
va_start(args, fmt);
int rc = vsnprintf(buffer, sizeof buffer, fmt, args);
va_end(args);
client->conf->arg.info_print_function(client->conf->arg.segment_ctx.ctx, buffer);
return rc;
}
static enum cue_status cue_poll(client_t *client)
{
unsigned timeout = CUE_POLL_aaaaaaaaaaaaaaaaaaaaaaaa1aaa;
enum cue_status result;
do {
result = cue_read(client, CUE_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaa1aaa);
timeout--;
} while((result == CUE_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaBUSY) && (timeout > 0));
if(timeout == 0)
return CUE_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaTIMEOUT;
else
return result;
}
static void cue_write_bits(client_t *client, unsigned address,
unsigned n_bits, const uint8_t bits[])
{
const uint32_t *bits32 = (const uint32_t *)bits;
unsigned bytes = (n_bits + 7) / 8;
unsigned aaaaaaaaaaaaaaaaaaaaaa1aaa;
for(aaaaaaaaaaaaaaaaaaaaaa1aaa = 0; (aaaaaaaaaaaaaaaaaaaaaa1aaa + 3) < bytes; aaaaaaaaaaaaaaaaaaaaaa1aaa += 4)
cue_write(client, address + aaaaaaaaaaaaaaaaaaaaaa1aaa, *bits32++);
if(aaaaaaaaaaaaaaaaaaaaaa1aaa < bytes) {
uint32_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaword = 0;
unsigned addr_ofs = aaaaaaaaaaaaaaaaaaaaaa1aaa;
for(; aaaaaaaaaaaaaaaaaaaaaa1aaa < bytes; aaaaaaaaaaaaaaaaaaaaaa1aaa++) {
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaword = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaword | (bits[aaaaaaaaaaaaaaaaaaaaaa1aaa] << (8 * (aaaaaaaaaaaaaaaaaaaaaa1aaa - addr_ofs)));
}
cue_write(client, address + addr_ofs, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaword);
}
}
static void cue_read_bits(client_t *client, unsigned address,
unsigned n_bits, uint8_t bits[])
{
uint32_t *bits32 = (uint32_t *)bits;
unsigned bytes = (n_bits + 7) / 8;
unsigned aaaaaaaaaaaaaaaaaaaaaa1aaa;
for(aaaaaaaaaaaaaaaaaaaaaa1aaa = 0; (aaaaaaaaaaaaaaaaaaaaaa1aaa + 3) < bytes; aaaaaaaaaaaaaaaaaaaaaa1aaa += 4)
*bits32++ = cue_read(client, address + aaaaaaaaaaaaaaaaaaaaaa1aaa);
if(aaaaaaaaaaaaaaaaaaaaaa1aaa < bytes) {
uint32_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaword = cue_read(client, address + aaaaaaaaaaaaaaaaaaaaaa1aaa);
for(; aaaaaaaaaaaaaaaaaaaaaa1aaa < bytes; aaaaaaaaaaaaaaaaaaaaaa1aaa++) {
bits[aaaaaaaaaaaaaaaaaaaaaa1aaa] = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaword & 255;
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaword = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaword >> 8;
}
}
}
static void cue_set_key(client_t *client, const uint8_t key[])
{
cue_write_bits(client, CUE_KEY_aaaaaaaaaaaaaaaaaaaaa1aaa, client_get_key_width(client), key);
}
static void cue_set_response(client_t *client, const uint8_t response[])
{
cue_write_bits(client, CUE_RESPONSE_aaaaaaaaaaaaaaaaaaaaa1aaa, client_get_response_width(client), response);
}
static void cue_get_key(client_t *client, uint8_t key[])
{
cue_read_bits(client, CUE_KEY_aaaaaaaaaaaaaaaaaaaaa1aaa, client_get_key_width(client), key);
}
static void cue_get_response(client_t *client, uint8_t response[])
{
cue_read_bits(client, CUE_RESPONSE_aaaaaaaaaaaaaaaaaaaaa1aaa, client_get_response_width(client), response);
}
static void cue_verify(client_t *client, const uint8_t key[], const uint8_t response[])
{
const cam_malloc_func malloc_function = client_get_malloc_function(client);
const cam_free_func free_function = client_get_free_function(client);
const uint16_t key_width = client_get_key_width(client);
const uint16_t response_width = client_get_response_width(client);
char *key_str = byte_arr_to_str(key_width, key, malloc_function);
char *response_str = byte_arr_to_str(response_width, response, malloc_function);
   cue_printf(client, "CAM_DEBUG_VERIFY_WR: Key: %s", key_str);
   cue_printf(client, "CAM_DEBUG_VERIFY_WR: Response: %s", response_str);
free_function(key_str);
uint8_t verify_response[CAM_MAX_RESPONSE_WIDTH / 8];
int gbk_result = cue_get_by_key(client, key, verify_response);
if(gbk_result == 0) {
char *gbk_response_str = byte_arr_to_str(response_width, verify_response, malloc_function);
       cue_printf(client, "CAM_DEBUG_VERIFY_WR: Readback: %s", gbk_response_str);
       cue_printf(client, "CAM_DEBUG_VERIFY_WR: Result: %s",
                  strcmp(response_str, gbk_response_str) ? "FAILED" : "OK");
free_function(gbk_response_str);
} else {
       cue_printf(client, "CAM_DEBUG_VERIFY_WR: get_by_key: %s", cam_error_string(gbk_result));
}
free_function(response_str);
}
int cue_get_by_entry_index(client_t *client, unsigned index, uint8_t key[], uint8_t response[])
{
const unsigned num_lists = client_get_num_lists(client);
const unsigned addr_mask = num_lists - 1;
const unsigned addr_bits = CLOG2(num_lists);
const unsigned table_pos = ROUND_UP(addr_bits, 4);
const unsigned table = index >> addr_bits;
assert(table < 4);
uint32_t index_encoded = (index & addr_mask) | (table << table_pos);
cue_write(client, CUE_KEY_aaaaaaaaaaaaaaaaaaaaa1aaa, index_encoded);
cue_write(client, CUE_COMMAND_aaaaaaaaaaaaaaaaaaaaa1aaa, CUE_COMMAND_GET_BY_INDEX);
enum cue_status result = cue_poll(client);
if(result == CUE_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaSUCCESS) {
cue_get_key(client, key);
cue_get_response(client, response);
}
return cue_translate(result);
}
int cue_insert(client_t *client, const uint8_t key[], const uint8_t response[])
{
cue_set_key(client, key);
cue_set_response(client, response);
cue_write(client, CUE_COMMAND_aaaaaaaaaaaaaaaaaaaaa1aaa, CUE_COMMAND_INSERT);
enum cue_status result = cue_poll(client);
if((result == CUE_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaSUCCESS) &&
(client_get_debug_flags(client) & CAM_DEBUG_VERIFY_WR))
cue_verify(client, key, response);
return cue_translate(result);
}
int cue_update(client_t *client, const uint8_t key[], const uint8_t response[])
{
cue_set_key(client, key);
cue_set_response(client, response);
cue_write(client, CUE_COMMAND_aaaaaaaaaaaaaaaaaaaaa1aaa, CUE_COMMAND_UPDATE);
enum cue_status result = cue_poll(client);
return cue_translate(result);
}
int cue_delete(client_t *client, const uint8_t key[])
{
cue_set_key(client, key);
cue_write(client, CUE_COMMAND_aaaaaaaaaaaaaaaaaaaaa1aaa, CUE_COMMAND_DELETE);
enum cue_status result = cue_poll(client);
return cue_translate(result);
}
int cue_get_by_key(client_t *client, const uint8_t key[], uint8_t response[])
{
cue_set_key(client, key);
cue_write(client, CUE_COMMAND_aaaaaaaaaaaaaaaaaaaaa1aaa, CUE_COMMAND_GET_BY_KEY);
enum cue_status result = cue_poll(client);
if(result == CUE_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaSUCCESS) {
cue_get_response(client, response);
}
return cue_translate(result);
}
int cue_clear(client_t *client)
{
cue_write(client, CUE_COMMAND_aaaaaaaaaaaaaaaaaaaaa1aaa, CUE_COMMAND_CLEAR);
enum cue_status result = cue_poll(client);
return cue_translate(result);
}
int cue_iterate(client_t *client,
const uint8_t key[], const uint8_t key_mask[],
const uint8_t response[], const uint8_t response_mask[],
uint32_t *pos,
uint8_t out_key[],
uint8_t out_response[])
{
aaaaaaaaaaaaa1aaat hw_key;
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat hw_response;
uint32_t index = *pos;
bool match;
int rv = 0;
const unsigned max_index = client_get_num_units(client) * client_get_num_lists(client);
const unsigned key_width = client_get_key_width(client);
const unsigned response_width = client_get_response_width(client);
uint8_t key_bytes = key_width / 8;
const uint16_t key_remaining_bits = key_width - key_bytes * 8;
uint8_t response_bytes = response_width / 8;
const uint16_t response_remaining_bits = response_width - response_bytes * 8;
do {
match = 0;
rv = cue_get_by_entry_index(client, index,
(uint8_t *)&hw_key, (uint8_t *)&hw_response);
if(rv != CAM_ERROR_KEY_NOT_FOUND) {
if(rv) return rv;
match = 1;
if (key && key_mask)
{
const uint8_t *found_key = (const uint8_t *)&hw_key;
int i;
for (i = 0; i < key_bytes; i++)
if((key[i] ^ found_key[i]) & key_mask[i])
match = 0;
if (key_remaining_bits > 0)
if((key[key_bytes] ^ found_key[key_bytes]) & key_mask[key_bytes])
match = 0;
}
if (response && response_mask)
{
const uint8_t *found_response = (const uint8_t *)&hw_response;
int i;
for (i = 0; i < response_bytes; i++)
if((response[i] ^ found_response[i]) & response_mask[i])
match = 0;
if (response_remaining_bits > 0)
if((response[response_bytes] ^ found_response[response_bytes]) & response_mask[response_bytes])
match = 0;
}
}
index++;
} while((match == 0) && (index < max_index));
if(index >= max_index)
rv = CAM_ERROR_KEY_NOT_FOUND;
if (rv == 0)
{
*pos = index;
if (out_key)
{
cam_copy_bits(out_key, (const uint8_t *)&hw_key, key_width);
}
if (out_response)
{
cam_copy_bits(out_response, (const uint8_t *)&hw_response, response_width);
}
}
return rv;
}
static inline unsigned cue_counter_timestamp(uint32_t value)
{
return (value >> 26) & 0x3f;
}
static inline unsigned cue_counter_value(uint32_t value)
{
return (value & 0x3ffffff) * 16;
}
static int cue_get_counters(client_t *client, struct cue_stats_counters *counters)
{
uint32_t counter;
int i;
for(i = 0; i < 2; i++) {
counter = cue_read(client, CUE_STATS_DELETE_FAILED_aaaaaaaaaaaaaaaaaaaaa1aaa);
counters->delete_failed = cue_counter_value(counter);
counters->timestamp = cue_counter_timestamp(counter);
counters->delete_succeeded = cue_counter_value(cue_read(client, CUE_STATS_DELETE_SUCCEEDED_aaaaaaaaaaaaaaaaaaaaa1aaa));
counters->update_failed = cue_counter_value(cue_read(client, CUE_STATS_UPDATE_FAILED_aaaaaaaaaaaaaaaaaaaaa1aaa));
counters->update_succeeded = cue_counter_value(cue_read(client, CUE_STATS_UPDATE_SUCCEEDED_aaaaaaaaaaaaaaaaaaaaa1aaa));
counters->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaafailed = cue_counter_value(cue_read(client, CUE_STATS_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaFAILED_aaaaaaaaaaaaaaaaaaaaa1aaa));
counter = cue_read(client, CUE_STATS_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaSUCCEEDED_aaaaaaaaaaaaaaaaaaaaa1aaa);
counters->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaasucceeded = cue_counter_value(counter);
if(counters->timestamp == cue_counter_timestamp(counter))
return 0;
}
return CAM_ERROR_ENVIRONMENT;
}
int cue_get_stats(client_t *client, uint64_t stats_group, union cue_stats *stats)
{
if((client == NULL) ||
(stats == NULL))
return CAM_ERROR_INVALID_ARG;
memset(stats, 0, sizeof *stats);
switch(stats_group) {
case CUE_STATS_aaaaaaaaaaaaaaaaaaaaaaaa1aaaERS: return cue_get_counters(client, &stats->counters);
default: return CAM_ERROR_INVALID_ARG;
}
}
#ifndef XOR0_H
#define XOR0_H
#define XOR0(INST) {\
INST[1][0] = INST[0][1] ^ INST[0][14] ^ INST[0][31];\
INST[1][1] = INST[0][14] ^ INST[0][112];\
INST[1][2] = INST[0][112] ^ INST[0][31];\
INST[1][3] = INST[0][31] ^ INST[0][137];\
INST[1][4] = INST[0][137] ^ INST[0][86];\
INST[1][5] = INST[0][86] ^ INST[0][100];\
INST[1][6] = INST[0][100] ^ INST[0][109];\
INST[1][7] = INST[0][109] ^ INST[0][103];\
INST[1][8] = INST[0][103] ^ INST[0][84];\
INST[1][9] = INST[0][84] ^ INST[0][42];\
INST[1][10] = INST[0][42] ^ INST[0][131];\
INST[1][11] = INST[0][131] ^ INST[0][141];\
INST[1][12] = INST[0][141] ^ INST[0][16];\
INST[1][13] = INST[0][16] ^ INST[0][2];\
INST[1][14] = INST[0][2] ^ INST[0][89];\
INST[1][15] = INST[0][89] ^ INST[0][76];\
INST[1][16] = INST[0][76] ^ INST[0][69];\
INST[1][17] = INST[0][69] ^ INST[0][101];\
INST[1][18] = INST[0][101] ^ INST[0][46];\
INST[1][19] = INST[0][46] ^ INST[0][126];\
INST[1][20] = INST[0][126] ^ INST[0][33];\
INST[1][21] = INST[0][33] ^ INST[0][110];\
INST[1][22] = INST[0][110] ^ INST[0][25];\
INST[1][23] = INST[0][25] ^ INST[0][133];\
INST[1][24] = INST[0][133] ^ INST[0][93];\
INST[1][25] = INST[0][93] ^ INST[0][117];\
INST[1][26] = INST[0][117] ^ INST[0][91];\
INST[1][27] = INST[0][91] ^ INST[0][50];\
INST[1][28] = INST[0][50] ^ INST[0][5];\
INST[1][29] = INST[0][5] ^ INST[0][71];\
INST[1][30] = INST[0][71] ^ INST[0][61];\
INST[1][31] = INST[0][61] ^ INST[0][95];\
INST[1][32] = INST[0][95] ^ INST[0][124];\
INST[1][33] = INST[0][124] ^ INST[0][102];\
INST[1][34] = INST[0][102] ^ INST[0][3];\
INST[1][35] = INST[0][3] ^ INST[0][29];\
INST[1][36] = INST[0][29] ^ INST[0][116];\
INST[1][37] = INST[0][116] ^ INST[0][162];\
INST[1][38] = INST[0][162] ^ INST[0][44];\
INST[1][39] = INST[0][44] ^ INST[0][70];\
INST[1][40] = INST[0][70] ^ INST[0][35];\
INST[1][41] = INST[0][35] ^ INST[0][159];\
INST[1][42] = INST[0][159] ^ INST[0][129];\
INST[1][43] = INST[0][129] ^ INST[0][57];\
INST[1][44] = INST[0][57] ^ INST[0][127];\
INST[1][45] = INST[0][127] ^ INST[0][24];\
INST[1][46] = INST[0][24] ^ INST[0][132];\
INST[1][47] = INST[0][132] ^ INST[0][58];\
INST[1][48] = INST[0][58] ^ INST[0][62];\
INST[1][49] = INST[0][62] ^ INST[0][147];\
INST[1][50] = INST[0][147] ^ INST[0][149];\
INST[1][51] = INST[0][149] ^ INST[0][99];\
INST[1][52] = INST[0][99] ^ INST[0][138];\
INST[1][53] = INST[0][138] ^ INST[0][64];\
INST[1][54] = INST[0][64] ^ INST[0][0];\
INST[1][55] = INST[0][0] ^ INST[0][96];\
INST[1][56] = INST[0][96] ^ INST[0][163];\
INST[1][57] = INST[0][163] ^ INST[0][6];\
INST[1][58] = INST[0][6] ^ INST[0][155];\
INST[1][59] = INST[0][155] ^ INST[0][136];\
INST[1][60] = INST[0][136] ^ INST[0][144];\
INST[1][61] = INST[0][144] ^ INST[0][40];\
INST[1][62] = INST[0][40] ^ INST[0][11];\
INST[1][63] = INST[0][11] ^ INST[0][152];\
INST[1][64] = INST[0][152] ^ INST[0][39];\
INST[1][65] = INST[0][39] ^ INST[0][13];\
INST[1][66] = INST[0][13] ^ INST[0][140];\
INST[1][67] = INST[0][140] ^ INST[0][75];\
INST[1][68] = INST[0][75] ^ INST[0][139];\
INST[1][69] = INST[0][139] ^ INST[0][142];\
INST[1][70] = INST[0][142] ^ INST[0][111];\
INST[1][71] = INST[0][111] ^ INST[0][167];\
INST[1][72] = INST[0][167] ^ INST[0][122];\
INST[1][73] = INST[0][122] ^ INST[0][87];\
INST[1][74] = INST[0][87] ^ INST[0][156];\
INST[1][75] = INST[0][156] ^ INST[0][37];\
INST[1][76] = INST[0][37] ^ INST[0][114];\
INST[1][77] = INST[0][114] ^ INST[0][107];\
INST[1][78] = INST[0][107] ^ INST[0][97];\
INST[1][79] = INST[0][97] ^ INST[0][74];\
INST[1][80] = INST[0][74] ^ INST[0][165];\
INST[1][81] = INST[0][165] ^ INST[0][145];\
INST[1][82] = INST[0][145] ^ INST[0][78];\
INST[1][83] = INST[0][78] ^ INST[0][34];\
INST[1][84] = INST[0][34] ^ INST[0][65];\
INST[1][85] = INST[0][65] ^ INST[0][83];\
INST[1][86] = INST[0][83] ^ INST[0][166];\
INST[1][87] = INST[0][166] ^ INST[0][7];\
INST[1][88] = INST[0][7] ^ INST[0][72];\
INST[1][89] = INST[0][72] ^ INST[0][134];\
INST[1][90] = INST[0][134] ^ INST[0][43];\
INST[1][91] = INST[0][43] ^ INST[0][118];\
INST[1][92] = INST[0][118] ^ INST[0][15];\
INST[1][93] = INST[0][15] ^ INST[0][146];\
INST[1][94] = INST[0][146] ^ INST[0][23];\
INST[1][95] = INST[0][23] ^ INST[0][4];\
INST[1][96] = INST[0][4] ^ INST[0][9];\
INST[1][97] = INST[0][9] ^ INST[0][121];\
INST[1][98] = INST[0][121] ^ INST[0][108];\
INST[1][99] = INST[0][108] ^ INST[0][130];\
INST[1][100] = INST[0][130] ^ INST[0][135];\
INST[1][101] = INST[0][135] ^ INST[0][68];\
INST[1][102] = INST[0][68] ^ INST[0][32];\
INST[1][103] = INST[0][32] ^ INST[0][88];\
INST[1][104] = INST[0][88] ^ INST[0][157];\
INST[1][105] = INST[0][157] ^ INST[0][80];\
INST[1][106] = INST[0][80] ^ INST[0][38];\
INST[1][107] = INST[0][38] ^ INST[0][164];\
INST[1][108] = INST[0][164] ^ INST[0][98];\
INST[1][109] = INST[0][98] ^ INST[0][18];\
INST[1][110] = INST[0][18] ^ INST[0][53];\
INST[1][111] = INST[0][53] ^ INST[0][20];\
INST[1][112] = INST[0][20] ^ INST[0][151];\
INST[1][113] = INST[0][151] ^ INST[0][41];\
INST[1][114] = INST[0][41] ^ INST[0][82];\
INST[1][115] = INST[0][82] ^ INST[0][63];\
INST[1][116] = INST[0][63] ^ INST[0][161];\
INST[1][117] = INST[0][161] ^ INST[0][94];\
INST[1][118] = INST[0][94] ^ INST[0][26];\
INST[1][119] = INST[0][26] ^ INST[0][10];\
INST[1][120] = INST[0][10] ^ INST[0][104];\
INST[1][121] = INST[0][104] ^ INST[0][115];\
INST[1][122] = INST[0][115] ^ INST[0][54];\
INST[1][123] = INST[0][54] ^ INST[0][56];\
INST[1][124] = INST[0][56] ^ INST[0][105];\
INST[1][125] = INST[0][105] ^ INST[0][22];\
INST[1][126] = INST[0][22] ^ INST[0][30];\
INST[1][127] = INST[0][30] ^ INST[0][119];\
INST[1][128] = INST[0][119] ^ INST[0][73];\
INST[1][129] = INST[0][73] ^ INST[0][150];\
INST[1][130] = INST[0][150] ^ INST[0][66];\
INST[1][131] = INST[0][66] ^ INST[0][128];\
INST[1][132] = INST[0][128] ^ INST[0][77];\
INST[1][133] = INST[0][77] ^ INST[0][125];\
INST[1][134] = INST[0][125] ^ INST[0][79];\
INST[1][135] = INST[0][79] ^ INST[0][85];\
INST[1][136] = INST[0][85] ^ INST[0][123];\
INST[1][137] = INST[0][123] ^ INST[0][19];\
INST[1][138] = INST[0][19] ^ INST[0][148];\
INST[1][139] = INST[0][148] ^ INST[0][143];\
INST[1][140] = INST[0][143] ^ INST[0][67];\
INST[1][141] = INST[0][67] ^ INST[0][59];\
INST[1][142] = INST[0][59] ^ INST[0][106];\
INST[1][143] = INST[0][106] ^ INST[0][92];\
INST[1][144] = INST[0][92] ^ INST[0][120];\
INST[1][145] = INST[0][120] ^ INST[0][154];\
INST[1][146] = INST[0][154] ^ INST[0][28];\
INST[1][147] = INST[0][28] ^ INST[0][55];\
INST[1][148] = INST[0][55] ^ INST[0][90];\
INST[1][149] = INST[0][90] ^ INST[0][81];\
INST[1][150] = INST[0][81] ^ INST[0][12];\
INST[1][151] = INST[0][12] ^ INST[0][45];\
INST[1][152] = INST[0][45] ^ INST[0][52];\
INST[1][153] = INST[0][52] ^ INST[0][60];\
INST[1][154] = INST[0][60] ^ INST[0][160];\
INST[1][155] = INST[0][160] ^ INST[0][158];\
INST[1][156] = INST[0][158] ^ INST[0][113];\
INST[1][157] = INST[0][113] ^ INST[0][17];\
INST[1][158] = INST[0][17] ^ INST[0][153];\
INST[1][159] = INST[0][153] ^ INST[0][36];\
INST[1][160] = INST[0][36] ^ INST[0][21];\
INST[1][161] = INST[0][21] ^ INST[0][49];\
INST[1][162] = INST[0][49] ^ INST[0][51];\
INST[1][163] = INST[0][51] ^ INST[0][27];\
INST[1][164] = INST[0][27] ^ INST[0][8];\
INST[1][165] = INST[0][8] ^ INST[0][47];\
INST[1][166] = INST[0][47] ^ INST[0][48];\
INST[1][167] = INST[0][48] ^ INST[0][1];\
}
#endif
#ifndef XOR1_H
#define XOR1_H
#define XOR1(INST) {\
INST[0][0] = INST[1][106] ^ INST[1][32] ^ INST[1][73];\
INST[0][1] = INST[1][32] ^ INST[1][5];\
INST[0][2] = INST[1][5] ^ INST[1][73];\
INST[0][3] = INST[1][73] ^ INST[1][123];\
INST[0][4] = INST[1][123] ^ INST[1][63];\
INST[0][5] = INST[1][63] ^ INST[1][36];\
INST[0][6] = INST[1][36] ^ INST[1][125];\
INST[0][7] = INST[1][125] ^ INST[1][35];\
INST[0][8] = INST[1][35] ^ INST[1][167];\
INST[0][9] = INST[1][167] ^ INST[1][117];\
INST[0][10] = INST[1][117] ^ INST[1][137];\
INST[0][11] = INST[1][137] ^ INST[1][48];\
INST[0][12] = INST[1][48] ^ INST[1][2];\
INST[0][13] = INST[1][2] ^ INST[1][24];\
INST[0][14] = INST[1][24] ^ INST[1][135];\
INST[0][15] = INST[1][135] ^ INST[1][152];\
INST[0][16] = INST[1][152] ^ INST[1][74];\
INST[0][17] = INST[1][74] ^ INST[1][147];\
INST[0][18] = INST[1][147] ^ INST[1][38];\
INST[0][19] = INST[1][38] ^ INST[1][139];\
INST[0][20] = INST[1][139] ^ INST[1][21];\
INST[0][21] = INST[1][21] ^ INST[1][52];\
INST[0][22] = INST[1][52] ^ INST[1][44];\
INST[0][23] = INST[1][44] ^ INST[1][102];\
INST[0][24] = INST[1][102] ^ INST[1][87];\
INST[0][25] = INST[1][87] ^ INST[1][114];\
INST[0][26] = INST[1][114] ^ INST[1][93];\
INST[0][27] = INST[1][93] ^ INST[1][105];\
INST[0][28] = INST[1][105] ^ INST[1][66];\
INST[0][29] = INST[1][66] ^ INST[1][146];\
INST[0][30] = INST[1][146] ^ INST[1][17];\
INST[0][31] = INST[1][17] ^ INST[1][77];\
INST[0][32] = INST[1][77] ^ INST[1][165];\
INST[0][33] = INST[1][165] ^ INST[1][142];\
INST[0][34] = INST[1][142] ^ INST[1][109];\
INST[0][35] = INST[1][109] ^ INST[1][157];\
INST[0][36] = INST[1][157] ^ INST[1][94];\
INST[0][37] = INST[1][94] ^ INST[1][60];\
INST[0][38] = INST[1][60] ^ INST[1][31];\
INST[0][39] = INST[1][31] ^ INST[1][161];\
INST[0][40] = INST[1][161] ^ INST[1][127];\
INST[0][41] = INST[1][127] ^ INST[1][86];\
INST[0][42] = INST[1][86] ^ INST[1][79];\
INST[0][43] = INST[1][79] ^ INST[1][37];\
INST[0][44] = INST[1][37] ^ INST[1][88];\
INST[0][45] = INST[1][88] ^ INST[1][26];\
INST[0][46] = INST[1][26] ^ INST[1][148];\
INST[0][47] = INST[1][148] ^ INST[1][129];\
INST[0][48] = INST[1][129] ^ INST[1][11];\
INST[0][49] = INST[1][11] ^ INST[1][150];\
INST[0][50] = INST[1][150] ^ INST[1][104];\
INST[0][51] = INST[1][104] ^ INST[1][99];\
INST[0][52] = INST[1][99] ^ INST[1][13];\
INST[0][53] = INST[1][13] ^ INST[1][78];\
INST[0][54] = INST[1][78] ^ INST[1][50];\
INST[0][55] = INST[1][50] ^ INST[1][72];\
INST[0][56] = INST[1][72] ^ INST[1][3];\
INST[0][57] = INST[1][3] ^ INST[1][47];\
INST[0][58] = INST[1][47] ^ INST[1][144];\
INST[0][59] = INST[1][144] ^ INST[1][64];\
INST[0][60] = INST[1][64] ^ INST[1][62];\
INST[0][61] = INST[1][62] ^ INST[1][163];\
INST[0][62] = INST[1][163] ^ INST[1][61];\
INST[0][63] = INST[1][61] ^ INST[1][56];\
INST[0][64] = INST[1][56] ^ INST[1][65];\
INST[0][65] = INST[1][65] ^ INST[1][59];\
INST[0][66] = INST[1][59] ^ INST[1][97];\
INST[0][67] = INST[1][97] ^ INST[1][128];\
INST[0][68] = INST[1][128] ^ INST[1][95];\
INST[0][69] = INST[1][95] ^ INST[1][70];\
INST[0][70] = INST[1][70] ^ INST[1][113];\
INST[0][71] = INST[1][113] ^ INST[1][98];\
INST[0][72] = INST[1][98] ^ INST[1][6];\
INST[0][73] = INST[1][6] ^ INST[1][141];\
INST[0][74] = INST[1][141] ^ INST[1][89];\
INST[0][75] = INST[1][89] ^ INST[1][156];\
INST[0][76] = INST[1][156] ^ INST[1][76];\
INST[0][77] = INST[1][76] ^ INST[1][84];\
INST[0][78] = INST[1][84] ^ INST[1][69];\
INST[0][79] = INST[1][69] ^ INST[1][75];\
INST[0][80] = INST[1][75] ^ INST[1][29];\
INST[0][81] = INST[1][29] ^ INST[1][162];\
INST[0][82] = INST[1][162] ^ INST[1][0];\
INST[0][83] = INST[1][0] ^ INST[1][85];\
INST[0][84] = INST[1][85] ^ INST[1][7];\
INST[0][85] = INST[1][7] ^ INST[1][136];\
INST[0][86] = INST[1][136] ^ INST[1][16];\
INST[0][87] = INST[1][16] ^ INST[1][51];\
INST[0][88] = INST[1][51] ^ INST[1][122];\
INST[0][89] = INST[1][122] ^ INST[1][92];\
INST[0][90] = INST[1][92] ^ INST[1][153];\
INST[0][91] = INST[1][153] ^ INST[1][124];\
INST[0][92] = INST[1][124] ^ INST[1][9];\
INST[0][93] = INST[1][9] ^ INST[1][8];\
INST[0][94] = INST[1][8] ^ INST[1][10];\
INST[0][95] = INST[1][10] ^ INST[1][96];\
INST[0][96] = INST[1][96] ^ INST[1][138];\
INST[0][97] = INST[1][138] ^ INST[1][166];\
INST[0][98] = INST[1][166] ^ INST[1][159];\
INST[0][99] = INST[1][159] ^ INST[1][118];\
INST[0][100] = INST[1][118] ^ INST[1][115];\
INST[0][101] = INST[1][115] ^ INST[1][160];\
INST[0][102] = INST[1][160] ^ INST[1][34];\
INST[0][103] = INST[1][34] ^ INST[1][28];\
INST[0][104] = INST[1][28] ^ INST[1][131];\
INST[0][105] = INST[1][131] ^ INST[1][145];\
INST[0][106] = INST[1][145] ^ INST[1][140];\
INST[0][107] = INST[1][140] ^ INST[1][71];\
INST[0][108] = INST[1][71] ^ INST[1][68];\
INST[0][109] = INST[1][68] ^ INST[1][158];\
INST[0][110] = INST[1][158] ^ INST[1][121];\
INST[0][111] = INST[1][121] ^ INST[1][90];\
INST[0][112] = INST[1][90] ^ INST[1][46];\
INST[0][113] = INST[1][46] ^ INST[1][81];\
INST[0][114] = INST[1][81] ^ INST[1][110];\
INST[0][115] = INST[1][110] ^ INST[1][33];\
INST[0][116] = INST[1][33] ^ INST[1][82];\
INST[0][117] = INST[1][82] ^ INST[1][58];\
INST[0][118] = INST[1][58] ^ INST[1][120];\
INST[0][119] = INST[1][120] ^ INST[1][112];\
INST[0][120] = INST[1][112] ^ INST[1][15];\
INST[0][121] = INST[1][15] ^ INST[1][23];\
INST[0][122] = INST[1][23] ^ INST[1][100];\
INST[0][123] = INST[1][100] ^ INST[1][103];\
INST[0][124] = INST[1][103] ^ INST[1][22];\
INST[0][125] = INST[1][22] ^ INST[1][155];\
INST[0][126] = INST[1][155] ^ INST[1][164];\
INST[0][127] = INST[1][164] ^ INST[1][132];\
INST[0][128] = INST[1][132] ^ INST[1][83];\
INST[0][129] = INST[1][83] ^ INST[1][108];\
INST[0][130] = INST[1][108] ^ INST[1][43];\
INST[0][131] = INST[1][43] ^ INST[1][80];\
INST[0][132] = INST[1][80] ^ INST[1][154];\
INST[0][133] = INST[1][154] ^ INST[1][107];\
INST[0][134] = INST[1][107] ^ INST[1][126];\
INST[0][135] = INST[1][126] ^ INST[1][133];\
INST[0][136] = INST[1][133] ^ INST[1][40];\
INST[0][137] = INST[1][40] ^ INST[1][45];\
INST[0][138] = INST[1][45] ^ INST[1][18];\
INST[0][139] = INST[1][18] ^ INST[1][130];\
INST[0][140] = INST[1][130] ^ INST[1][41];\
INST[0][141] = INST[1][41] ^ INST[1][39];\
INST[0][142] = INST[1][39] ^ INST[1][12];\
INST[0][143] = INST[1][12] ^ INST[1][25];\
INST[0][144] = INST[1][25] ^ INST[1][101];\
INST[0][145] = INST[1][101] ^ INST[1][19];\
INST[0][146] = INST[1][19] ^ INST[1][143];\
INST[0][147] = INST[1][143] ^ INST[1][14];\
INST[0][148] = INST[1][14] ^ INST[1][4];\
INST[0][149] = INST[1][4] ^ INST[1][134];\
INST[0][150] = INST[1][134] ^ INST[1][116];\
INST[0][151] = INST[1][116] ^ INST[1][67];\
INST[0][152] = INST[1][67] ^ INST[1][42];\
INST[0][153] = INST[1][42] ^ INST[1][57];\
INST[0][154] = INST[1][57] ^ INST[1][55];\
INST[0][155] = INST[1][55] ^ INST[1][149];\
INST[0][156] = INST[1][149] ^ INST[1][30];\
INST[0][157] = INST[1][30] ^ INST[1][53];\
INST[0][158] = INST[1][53] ^ INST[1][119];\
INST[0][159] = INST[1][119] ^ INST[1][20];\
INST[0][160] = INST[1][20] ^ INST[1][151];\
INST[0][161] = INST[1][151] ^ INST[1][1];\
INST[0][162] = INST[1][1] ^ INST[1][27];\
INST[0][163] = INST[1][27] ^ INST[1][91];\
INST[0][164] = INST[1][91] ^ INST[1][111];\
INST[0][165] = INST[1][111] ^ INST[1][49];\
INST[0][166] = INST[1][49] ^ INST[1][54];\
INST[0][167] = INST[1][54] ^ INST[1][106];\
}
#endif
#ifndef XOR2_H
#define XOR2_H
#define XOR2(INST) {\
INST[1][0] = INST[0][33] ^ INST[0][165] ^ INST[0][119];\
INST[1][1] = INST[0][165] ^ INST[0][77];\
INST[1][2] = INST[0][77] ^ INST[0][119];\
INST[1][3] = INST[0][119] ^ INST[0][111];\
INST[1][4] = INST[0][111] ^ INST[0][42];\
INST[1][5] = INST[0][42] ^ INST[0][139];\
INST[1][6] = INST[0][139] ^ INST[0][57];\
INST[1][7] = INST[0][57] ^ INST[0][20];\
INST[1][8] = INST[0][20] ^ INST[0][133];\
INST[1][9] = INST[0][133] ^ INST[0][154];\
INST[1][10] = INST[0][154] ^ INST[0][94];\
INST[1][11] = INST[0][94] ^ INST[0][81];\
INST[1][12] = INST[0][81] ^ INST[0][80];\
INST[1][13] = INST[0][80] ^ INST[0][62];\
INST[1][14] = INST[0][62] ^ INST[0][67];\
INST[1][15] = INST[0][67] ^ INST[0][157];\
INST[1][16] = INST[0][157] ^ INST[0][6];\
INST[1][17] = INST[0][6] ^ INST[0][44];\
INST[1][18] = INST[0][44] ^ INST[0][88];\
INST[1][19] = INST[0][88] ^ INST[0][74];\
INST[1][20] = INST[0][74] ^ INST[0][89];\
INST[1][21] = INST[0][89] ^ INST[0][72];\
INST[1][22] = INST[0][72] ^ INST[0][136];\
INST[1][23] = INST[0][136] ^ INST[0][53];\
INST[1][24] = INST[0][53] ^ INST[0][91];\
INST[1][25] = INST[0][91] ^ INST[0][130];\
INST[1][26] = INST[0][130] ^ INST[0][24];\
INST[1][27] = INST[0][24] ^ INST[0][117];\
INST[1][28] = INST[0][117] ^ INST[0][56];\
INST[1][29] = INST[0][56] ^ INST[0][76];\
INST[1][30] = INST[0][76] ^ INST[0][120];\
INST[1][31] = INST[0][120] ^ INST[0][84];\
INST[1][32] = INST[0][84] ^ INST[0][118];\
INST[1][33] = INST[0][118] ^ INST[0][54];\
INST[1][34] = INST[0][54] ^ INST[0][66];\
INST[1][35] = INST[0][66] ^ INST[0][51];\
INST[1][36] = INST[0][51] ^ INST[0][61];\
INST[1][37] = INST[0][61] ^ INST[0][55];\
INST[1][38] = INST[0][55] ^ INST[0][34];\
INST[1][39] = INST[0][34] ^ INST[0][129];\
INST[1][40] = INST[0][129] ^ INST[0][128];\
INST[1][41] = INST[0][128] ^ INST[0][1];\
INST[1][42] = INST[0][1] ^ INST[0][104];\
INST[1][43] = INST[0][104] ^ INST[0][22];\
INST[1][44] = INST[0][22] ^ INST[0][2];\
INST[1][45] = INST[0][2] ^ INST[0][71];\
INST[1][46] = INST[0][71] ^ INST[0][113];\
INST[1][47] = INST[0][113] ^ INST[0][87];\
INST[1][48] = INST[0][87] ^ INST[0][15];\
INST[1][49] = INST[0][15] ^ INST[0][110];\
INST[1][50] = INST[0][110] ^ INST[0][161];\
INST[1][51] = INST[0][161] ^ INST[0][90];\
INST[1][52] = INST[0][90] ^ INST[0][163];\
INST[1][53] = INST[0][163] ^ INST[0][26];\
INST[1][54] = INST[0][26] ^ INST[0][12];\
INST[1][55] = INST[0][12] ^ INST[0][142];\
INST[1][56] = INST[0][142] ^ INST[0][127];\
INST[1][57] = INST[0][127] ^ INST[0][45];\
INST[1][58] = INST[0][45] ^ INST[0][82];\
INST[1][59] = INST[0][82] ^ INST[0][112];\
INST[1][60] = INST[0][112] ^ INST[0][65];\
INST[1][61] = INST[0][65] ^ INST[0][92];\
INST[1][62] = INST[0][92] ^ INST[0][121];\
INST[1][63] = INST[0][121] ^ INST[0][11];\
INST[1][64] = INST[0][11] ^ INST[0][46];\
INST[1][65] = INST[0][46] ^ INST[0][85];\
INST[1][66] = INST[0][85] ^ INST[0][38];\
INST[1][67] = INST[0][38] ^ INST[0][50];\
INST[1][68] = INST[0][50] ^ INST[0][41];\
INST[1][69] = INST[0][41] ^ INST[0][78];\
INST[1][70] = INST[0][78] ^ INST[0][0];\
INST[1][71] = INST[0][0] ^ INST[0][100];\
INST[1][72] = INST[0][100] ^ INST[0][103];\
INST[1][73] = INST[0][103] ^ INST[0][4];\
INST[1][74] = INST[0][4] ^ INST[0][106];\
INST[1][75] = INST[0][106] ^ INST[0][107];\
INST[1][76] = INST[0][107] ^ INST[0][125];\
INST[1][77] = INST[0][125] ^ INST[0][14];\
INST[1][78] = INST[0][14] ^ INST[0][123];\
INST[1][79] = INST[0][123] ^ INST[0][52];\
INST[1][80] = INST[0][52] ^ INST[0][59];\
INST[1][81] = INST[0][59] ^ INST[0][108];\
INST[1][82] = INST[0][108] ^ INST[0][147];\
INST[1][83] = INST[0][147] ^ INST[0][105];\
INST[1][84] = INST[0][105] ^ INST[0][153];\
INST[1][85] = INST[0][153] ^ INST[0][18];\
INST[1][86] = INST[0][18] ^ INST[0][160];\
INST[1][87] = INST[0][160] ^ INST[0][109];\
INST[1][88] = INST[0][109] ^ INST[0][135];\
INST[1][89] = INST[0][135] ^ INST[0][68];\
INST[1][90] = INST[0][68] ^ INST[0][73];\
INST[1][91] = INST[0][73] ^ INST[0][36];\
INST[1][92] = INST[0][36] ^ INST[0][17];\
INST[1][93] = INST[0][17] ^ INST[0][138];\
INST[1][94] = INST[0][138] ^ INST[0][152];\
INST[1][95] = INST[0][152] ^ INST[0][27];\
INST[1][96] = INST[0][27] ^ INST[0][37];\
INST[1][97] = INST[0][37] ^ INST[0][97];\
INST[1][98] = INST[0][97] ^ INST[0][155];\
INST[1][99] = INST[0][155] ^ INST[0][95];\
INST[1][100] = INST[0][95] ^ INST[0][101];\
INST[1][101] = INST[0][101] ^ INST[0][124];\
INST[1][102] = INST[0][124] ^ INST[0][167];\
INST[1][103] = INST[0][167] ^ INST[0][23];\
INST[1][104] = INST[0][23] ^ INST[0][39];\
INST[1][105] = INST[0][39] ^ INST[0][131];\
INST[1][106] = INST[0][131] ^ INST[0][35];\
INST[1][107] = INST[0][35] ^ INST[0][144];\
INST[1][108] = INST[0][144] ^ INST[0][9];\
INST[1][109] = INST[0][9] ^ INST[0][60];\
INST[1][110] = INST[0][60] ^ INST[0][93];\
INST[1][111] = INST[0][93] ^ INST[0][49];\
INST[1][112] = INST[0][49] ^ INST[0][32];\
INST[1][113] = INST[0][32] ^ INST[0][151];\
INST[1][114] = INST[0][151] ^ INST[0][3];\
INST[1][115] = INST[0][3] ^ INST[0][43];\
INST[1][116] = INST[0][43] ^ INST[0][64];\
INST[1][117] = INST[0][64] ^ INST[0][102];\
INST[1][118] = INST[0][102] ^ INST[0][149];\
INST[1][119] = INST[0][149] ^ INST[0][140];\
INST[1][120] = INST[0][140] ^ INST[0][126];\
INST[1][121] = INST[0][126] ^ INST[0][115];\
INST[1][122] = INST[0][115] ^ INST[0][99];\
INST[1][123] = INST[0][99] ^ INST[0][83];\
INST[1][124] = INST[0][83] ^ INST[0][146];\
INST[1][125] = INST[0][146] ^ INST[0][69];\
INST[1][126] = INST[0][69] ^ INST[0][137];\
INST[1][127] = INST[0][137] ^ INST[0][145];\
INST[1][128] = INST[0][145] ^ INST[0][116];\
INST[1][129] = INST[0][116] ^ INST[0][29];\
INST[1][130] = INST[0][29] ^ INST[0][122];\
INST[1][131] = INST[0][122] ^ INST[0][25];\
INST[1][132] = INST[0][25] ^ INST[0][162];\
INST[1][133] = INST[0][162] ^ INST[0][28];\
INST[1][134] = INST[0][28] ^ INST[0][16];\
INST[1][135] = INST[0][16] ^ INST[0][98];\
INST[1][136] = INST[0][98] ^ INST[0][164];\
INST[1][137] = INST[0][164] ^ INST[0][70];\
INST[1][138] = INST[0][70] ^ INST[0][5];\
INST[1][139] = INST[0][5] ^ INST[0][48];\
INST[1][140] = INST[0][48] ^ INST[0][58];\
INST[1][141] = INST[0][58] ^ INST[0][141];\
INST[1][142] = INST[0][141] ^ INST[0][21];\
INST[1][143] = INST[0][21] ^ INST[0][30];\
INST[1][144] = INST[0][30] ^ INST[0][47];\
INST[1][145] = INST[0][47] ^ INST[0][19];\
INST[1][146] = INST[0][19] ^ INST[0][96];\
INST[1][147] = INST[0][96] ^ INST[0][143];\
INST[1][148] = INST[0][143] ^ INST[0][150];\
INST[1][149] = INST[0][150] ^ INST[0][31];\
INST[1][150] = INST[0][31] ^ INST[0][40];\
INST[1][151] = INST[0][40] ^ INST[0][79];\
INST[1][152] = INST[0][79] ^ INST[0][156];\
INST[1][153] = INST[0][156] ^ INST[0][75];\
INST[1][154] = INST[0][75] ^ INST[0][132];\
INST[1][155] = INST[0][132] ^ INST[0][148];\
INST[1][156] = INST[0][148] ^ INST[0][10];\
INST[1][157] = INST[0][10] ^ INST[0][7];\
INST[1][158] = INST[0][7] ^ INST[0][8];\
INST[1][159] = INST[0][8] ^ INST[0][134];\
INST[1][160] = INST[0][134] ^ INST[0][159];\
INST[1][161] = INST[0][159] ^ INST[0][114];\
INST[1][162] = INST[0][114] ^ INST[0][86];\
INST[1][163] = INST[0][86] ^ INST[0][63];\
INST[1][164] = INST[0][63] ^ INST[0][166];\
INST[1][165] = INST[0][166] ^ INST[0][13];\
INST[1][166] = INST[0][13] ^ INST[0][158];\
INST[1][167] = INST[0][158] ^ INST[0][33];\
}
#endif
#ifndef XOR3_H
#define XOR3_H
#define XOR3(INST) {\
INST[0][0] = INST[1][22] ^ INST[1][106] ^ INST[1][121];\
INST[0][1] = INST[1][106] ^ INST[1][14];\
INST[0][2] = INST[1][14] ^ INST[1][121];\
INST[0][3] = INST[1][121] ^ INST[1][135];\
INST[0][4] = INST[1][135] ^ INST[1][125];\
INST[0][5] = INST[1][125] ^ INST[1][122];\
INST[0][6] = INST[1][122] ^ INST[1][43];\
INST[0][7] = INST[1][43] ^ INST[1][148];\
INST[0][8] = INST[1][148] ^ INST[1][95];\
INST[0][9] = INST[1][95] ^ INST[1][115];\
INST[0][10] = INST[1][115] ^ INST[1][2];\
INST[0][11] = INST[1][2] ^ INST[1][25];\
INST[0][12] = INST[1][25] ^ INST[1][109];\
INST[0][13] = INST[1][109] ^ INST[1][139];\
INST[0][14] = INST[1][139] ^ INST[1][66];\
INST[0][15] = INST[1][66] ^ INST[1][147];\
INST[0][16] = INST[1][147] ^ INST[1][105];\
INST[0][17] = INST[1][105] ^ INST[1][70];\
INST[0][18] = INST[1][70] ^ INST[1][167];\
INST[0][19] = INST[1][167] ^ INST[1][119];\
INST[0][20] = INST[1][119] ^ INST[1][68];\
INST[0][21] = INST[1][68] ^ INST[1][4];\
INST[0][22] = INST[1][4] ^ INST[1][32];\
INST[0][23] = INST[1][32] ^ INST[1][64];\
INST[0][24] = INST[1][64] ^ INST[1][134];\
INST[0][25] = INST[1][134] ^ INST[1][133];\
INST[0][26] = INST[1][133] ^ INST[1][124];\
INST[0][27] = INST[1][124] ^ INST[1][8];\
INST[0][28] = INST[1][8] ^ INST[1][15];\
INST[0][29] = INST[1][15] ^ INST[1][76];\
INST[0][30] = INST[1][76] ^ INST[1][30];\
INST[0][31] = INST[1][30] ^ INST[1][151];\
INST[0][32] = INST[1][151] ^ INST[1][144];\
INST[0][33] = INST[1][144] ^ INST[1][131];\
INST[0][34] = INST[1][131] ^ INST[1][54];\
INST[0][35] = INST[1][54] ^ INST[1][145];\
INST[0][36] = INST[1][145] ^ INST[1][61];\
INST[0][37] = INST[1][61] ^ INST[1][6];\
INST[0][38] = INST[1][6] ^ INST[1][129];\
INST[0][39] = INST[1][129] ^ INST[1][16];\
INST[0][40] = INST[1][16] ^ INST[1][50];\
INST[0][41] = INST[1][50] ^ INST[1][9];\
INST[0][42] = INST[1][9] ^ INST[1][123];\
INST[0][43] = INST[1][123] ^ INST[1][11];\
INST[0][44] = INST[1][11] ^ INST[1][87];\
INST[0][45] = INST[1][87] ^ INST[1][28];\
INST[0][46] = INST[1][28] ^ INST[1][96];\
INST[0][47] = INST[1][96] ^ INST[1][18];\
INST[0][48] = INST[1][18] ^ INST[1][19];\
INST[0][49] = INST[1][19] ^ INST[1][31];\
INST[0][50] = INST[1][31] ^ INST[1][157];\
INST[0][51] = INST[1][157] ^ INST[1][63];\
INST[0][52] = INST[1][63] ^ INST[1][160];\
INST[0][53] = INST[1][160] ^ INST[1][117];\
INST[0][54] = INST[1][117] ^ INST[1][60];\
INST[0][55] = INST[1][60] ^ INST[1][150];\
INST[0][56] = INST[1][150] ^ INST[1][86];\
INST[0][57] = INST[1][86] ^ INST[1][146];\
INST[0][58] = INST[1][146] ^ INST[1][156];\
INST[0][59] = INST[1][156] ^ INST[1][45];\
INST[0][60] = INST[1][45] ^ INST[1][69];\
INST[0][61] = INST[1][69] ^ INST[1][97];\
INST[0][62] = INST[1][97] ^ INST[1][130];\
INST[0][63] = INST[1][130] ^ INST[1][159];\
INST[0][64] = INST[1][159] ^ INST[1][10];\
INST[0][65] = INST[1][10] ^ INST[1][103];\
INST[0][66] = INST[1][103] ^ INST[1][7];\
INST[0][67] = INST[1][7] ^ INST[1][161];\
INST[0][68] = INST[1][161] ^ INST[1][53];\
INST[0][69] = INST[1][53] ^ INST[1][38];\
INST[0][70] = INST[1][38] ^ INST[1][137];\
INST[0][71] = INST[1][137] ^ INST[1][55];\
INST[0][72] = INST[1][55] ^ INST[1][138];\
INST[0][73] = INST[1][138] ^ INST[1][33];\
INST[0][74] = INST[1][33] ^ INST[1][82];\
INST[0][75] = INST[1][82] ^ INST[1][126];\
INST[0][76] = INST[1][126] ^ INST[1][104];\
INST[0][77] = INST[1][104] ^ INST[1][37];\
INST[0][78] = INST[1][37] ^ INST[1][62];\
INST[0][79] = INST[1][62] ^ INST[1][59];\
INST[0][80] = INST[1][59] ^ INST[1][99];\
INST[0][81] = INST[1][99] ^ INST[1][149];\
INST[0][82] = INST[1][149] ^ INST[1][35];\
INST[0][83] = INST[1][35] ^ INST[1][24];\
INST[0][84] = INST[1][24] ^ INST[1][52];\
INST[0][85] = INST[1][52] ^ INST[1][116];\
INST[0][86] = INST[1][116] ^ INST[1][73];\
INST[0][87] = INST[1][73] ^ INST[1][127];\
INST[0][88] = INST[1][127] ^ INST[1][80];\
INST[0][89] = INST[1][80] ^ INST[1][0];\
INST[0][90] = INST[1][0] ^ INST[1][17];\
INST[0][91] = INST[1][17] ^ INST[1][158];\
INST[0][92] = INST[1][158] ^ INST[1][40];\
INST[0][93] = INST[1][40] ^ INST[1][20];\
INST[0][94] = INST[1][20] ^ INST[1][136];\
INST[0][95] = INST[1][136] ^ INST[1][132];\
INST[0][96] = INST[1][132] ^ INST[1][12];\
INST[0][97] = INST[1][12] ^ INST[1][39];\
INST[0][98] = INST[1][39] ^ INST[1][101];\
INST[0][99] = INST[1][101] ^ INST[1][163];\
INST[0][100] = INST[1][163] ^ INST[1][47];\
INST[0][101] = INST[1][47] ^ INST[1][23];\
INST[0][102] = INST[1][23] ^ INST[1][67];\
INST[0][103] = INST[1][67] ^ INST[1][34];\
INST[0][104] = INST[1][34] ^ INST[1][21];\
INST[0][105] = INST[1][21] ^ INST[1][111];\
INST[0][106] = INST[1][111] ^ INST[1][3];\
INST[0][107] = INST[1][3] ^ INST[1][5];\
INST[0][108] = INST[1][5] ^ INST[1][93];\
INST[0][109] = INST[1][93] ^ INST[1][110];\
INST[0][110] = INST[1][110] ^ INST[1][51];\
INST[0][111] = INST[1][51] ^ INST[1][107];\
INST[0][112] = INST[1][107] ^ INST[1][44];\
INST[0][113] = INST[1][44] ^ INST[1][58];\
INST[0][114] = INST[1][58] ^ INST[1][153];\
INST[0][115] = INST[1][153] ^ INST[1][74];\
INST[0][116] = INST[1][74] ^ INST[1][140];\
INST[0][117] = INST[1][140] ^ INST[1][108];\
INST[0][118] = INST[1][108] ^ INST[1][85];\
INST[0][119] = INST[1][85] ^ INST[1][162];\
INST[0][120] = INST[1][162] ^ INST[1][100];\
INST[0][121] = INST[1][100] ^ INST[1][81];\
INST[0][122] = INST[1][81] ^ INST[1][113];\
INST[0][123] = INST[1][113] ^ INST[1][75];\
INST[0][124] = INST[1][75] ^ INST[1][90];\
INST[0][125] = INST[1][90] ^ INST[1][88];\
INST[0][126] = INST[1][88] ^ INST[1][49];\
INST[0][127] = INST[1][49] ^ INST[1][165];\
INST[0][128] = INST[1][165] ^ INST[1][46];\
INST[0][129] = INST[1][46] ^ INST[1][79];\
INST[0][130] = INST[1][79] ^ INST[1][143];\
INST[0][131] = INST[1][143] ^ INST[1][1];\
INST[0][132] = INST[1][1] ^ INST[1][56];\
INST[0][133] = INST[1][56] ^ INST[1][94];\
INST[0][134] = INST[1][94] ^ INST[1][13];\
INST[0][135] = INST[1][13] ^ INST[1][166];\
INST[0][136] = INST[1][166] ^ INST[1][155];\
INST[0][137] = INST[1][155] ^ INST[1][128];\
INST[0][138] = INST[1][128] ^ INST[1][27];\
INST[0][139] = INST[1][27] ^ INST[1][71];\
INST[0][140] = INST[1][71] ^ INST[1][142];\
INST[0][141] = INST[1][142] ^ INST[1][98];\
INST[0][142] = INST[1][98] ^ INST[1][84];\
INST[0][143] = INST[1][84] ^ INST[1][26];\
INST[0][144] = INST[1][26] ^ INST[1][114];\
INST[0][145] = INST[1][114] ^ INST[1][118];\
INST[0][146] = INST[1][118] ^ INST[1][112];\
INST[0][147] = INST[1][112] ^ INST[1][41];\
INST[0][148] = INST[1][41] ^ INST[1][42];\
INST[0][149] = INST[1][42] ^ INST[1][152];\
INST[0][150] = INST[1][152] ^ INST[1][141];\
INST[0][151] = INST[1][141] ^ INST[1][91];\
INST[0][152] = INST[1][91] ^ INST[1][48];\
INST[0][153] = INST[1][48] ^ INST[1][78];\
INST[0][154] = INST[1][78] ^ INST[1][120];\
INST[0][155] = INST[1][120] ^ INST[1][57];\
INST[0][156] = INST[1][57] ^ INST[1][72];\
INST[0][157] = INST[1][72] ^ INST[1][65];\
INST[0][158] = INST[1][65] ^ INST[1][77];\
INST[0][159] = INST[1][77] ^ INST[1][164];\
INST[0][160] = INST[1][164] ^ INST[1][83];\
INST[0][161] = INST[1][83] ^ INST[1][92];\
INST[0][162] = INST[1][92] ^ INST[1][36];\
INST[0][163] = INST[1][36] ^ INST[1][89];\
INST[0][164] = INST[1][89] ^ INST[1][102];\
INST[0][165] = INST[1][102] ^ INST[1][29];\
INST[0][166] = INST[1][29] ^ INST[1][154];\
INST[0][167] = INST[1][154] ^ INST[1][22];\
}
#endif
#ifndef SBOX4_H
#define SBOX4_H
#define SBOX4(INST) {\
uint8_t N0;\
uint8_t N1;\
uint8_t N2;\
uint8_t N3;\
uint8_t N4;\
uint8_t N5;\
uint8_t N6;\
uint8_t N7;\
uint8_t N8;\
uint8_t N9;\
uint8_t N10;\
uint8_t N11;\
uint8_t N12;\
uint8_t N13;\
N0 = ~INST[0][105];\
N1 = N0 & INST[0][79];\
N2 = N0 & INST[0][140];\
N3 = N1 | N2;\
N4 = INST[0][79] & INST[0][140];\
N5 = INST[0][105] & INST[0][79];\
N6 = ~INST[0][140];\
N7 = N6 & INST[0][105];\
N8 = N5 | N7;\
N9 = N6 & INST[0][79];\
N10 = N0 & INST[0][79];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][79];\
INST[1][0]= N12 | N13;\
INST[1][1]= N8 | N9;\
INST[1][2]= N3 | N4;\
N0 = ~INST[0][76];\
N1 = N0 & INST[0][141];\
N2 = N0 & INST[0][157];\
N3 = N1 | N2;\
N4 = INST[0][141] & INST[0][157];\
N5 = INST[0][76] & INST[0][141];\
N6 = ~INST[0][157];\
N7 = N6 & INST[0][76];\
N8 = N5 | N7;\
N9 = N6 & INST[0][141];\
N10 = N0 & INST[0][141];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][141];\
INST[1][3]= N12 | N13;\
INST[1][4]= N8 | N9;\
INST[1][5]= N3 | N4;\
N0 = ~INST[0][38];\
N1 = N0 & INST[0][135];\
N2 = N0 & INST[0][18];\
N3 = N1 | N2;\
N4 = INST[0][135] & INST[0][18];\
N5 = INST[0][38] & INST[0][135];\
N6 = ~INST[0][18];\
N7 = N6 & INST[0][38];\
N8 = N5 | N7;\
N9 = N6 & INST[0][135];\
N10 = N0 & INST[0][135];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][135];\
INST[1][6]= N12 | N13;\
INST[1][7]= N8 | N9;\
INST[1][8]= N3 | N4;\
N0 = ~INST[0][161];\
N1 = N0 & INST[0][143];\
N2 = N0 & INST[0][28];\
N3 = N1 | N2;\
N4 = INST[0][143] & INST[0][28];\
N5 = INST[0][161] & INST[0][143];\
N6 = ~INST[0][28];\
N7 = N6 & INST[0][161];\
N8 = N5 | N7;\
N9 = N6 & INST[0][143];\
N10 = N0 & INST[0][143];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][143];\
INST[1][9]= N12 | N13;\
INST[1][10]= N8 | N9;\
INST[1][11]= N3 | N4;\
N0 = ~INST[0][67];\
N1 = N0 & INST[0][117];\
N2 = N0 & INST[0][146];\
N3 = N1 | N2;\
N4 = INST[0][117] & INST[0][146];\
N5 = INST[0][67] & INST[0][117];\
N6 = ~INST[0][146];\
N7 = N6 & INST[0][67];\
N8 = N5 | N7;\
N9 = N6 & INST[0][117];\
N10 = N0 & INST[0][117];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][117];\
INST[1][12]= N12 | N13;\
INST[1][13]= N8 | N9;\
INST[1][14]= N3 | N4;\
N0 = ~INST[0][13];\
N1 = N0 & INST[0][12];\
N2 = N0 & INST[0][113];\
N3 = N1 | N2;\
N4 = INST[0][12] & INST[0][113];\
N5 = INST[0][13] & INST[0][12];\
N6 = ~INST[0][113];\
N7 = N6 & INST[0][13];\
N8 = N5 | N7;\
N9 = N6 & INST[0][12];\
N10 = N0 & INST[0][12];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][12];\
INST[1][15]= N12 | N13;\
INST[1][16]= N8 | N9;\
INST[1][17]= N3 | N4;\
N0 = ~INST[0][97];\
N1 = N0 & INST[0][54];\
N2 = N0 & INST[0][74];\
N3 = N1 | N2;\
N4 = INST[0][54] & INST[0][74];\
N5 = INST[0][97] & INST[0][54];\
N6 = ~INST[0][74];\
N7 = N6 & INST[0][97];\
N8 = N5 | N7;\
N9 = N6 & INST[0][54];\
N10 = N0 & INST[0][54];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][54];\
INST[1][18]= N12 | N13;\
INST[1][19]= N8 | N9;\
INST[1][20]= N3 | N4;\
N0 = ~INST[0][92];\
N1 = N0 & INST[0][118];\
N2 = N0 & INST[0][107];\
N3 = N1 | N2;\
N4 = INST[0][118] & INST[0][107];\
N5 = INST[0][92] & INST[0][118];\
N6 = ~INST[0][107];\
N7 = N6 & INST[0][92];\
N8 = N5 | N7;\
N9 = N6 & INST[0][118];\
N10 = N0 & INST[0][118];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][118];\
INST[1][21]= N12 | N13;\
INST[1][22]= N8 | N9;\
INST[1][23]= N3 | N4;\
N0 = ~INST[0][128];\
N1 = N0 & INST[0][160];\
N2 = N0 & INST[0][42];\
N3 = N1 | N2;\
N4 = INST[0][160] & INST[0][42];\
N5 = INST[0][128] & INST[0][160];\
N6 = ~INST[0][42];\
N7 = N6 & INST[0][128];\
N8 = N5 | N7;\
N9 = N6 & INST[0][160];\
N10 = N0 & INST[0][160];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][160];\
INST[1][24]= N12 | N13;\
INST[1][25]= N8 | N9;\
INST[1][26]= N3 | N4;\
N0 = ~INST[0][19];\
N1 = N0 & INST[0][123];\
N2 = N0 & INST[0][108];\
N3 = N1 | N2;\
N4 = INST[0][123] & INST[0][108];\
N5 = INST[0][19] & INST[0][123];\
N6 = ~INST[0][108];\
N7 = N6 & INST[0][19];\
N8 = N5 | N7;\
N9 = N6 & INST[0][123];\
N10 = N0 & INST[0][123];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][123];\
INST[1][27]= N12 | N13;\
INST[1][28]= N8 | N9;\
INST[1][29]= N3 | N4;\
N0 = ~INST[0][91];\
N1 = N0 & INST[0][115];\
N2 = N0 & INST[0][60];\
N3 = N1 | N2;\
N4 = INST[0][115] & INST[0][60];\
N5 = INST[0][91] & INST[0][115];\
N6 = ~INST[0][60];\
N7 = N6 & INST[0][91];\
N8 = N5 | N7;\
N9 = N6 & INST[0][115];\
N10 = N0 & INST[0][115];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][115];\
INST[1][30]= N12 | N13;\
INST[1][31]= N8 | N9;\
INST[1][32]= N3 | N4;\
N0 = ~INST[0][69];\
N1 = N0 & INST[0][34];\
N2 = N0 & INST[0][129];\
N3 = N1 | N2;\
N4 = INST[0][34] & INST[0][129];\
N5 = INST[0][69] & INST[0][34];\
N6 = ~INST[0][129];\
N7 = N6 & INST[0][69];\
N8 = N5 | N7;\
N9 = N6 & INST[0][34];\
N10 = N0 & INST[0][34];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][34];\
INST[1][33]= N12 | N13;\
INST[1][34]= N8 | N9;\
INST[1][35]= N3 | N4;\
N0 = ~INST[0][163];\
N1 = N0 & INST[0][83];\
N2 = N0 & INST[0][0];\
N3 = N1 | N2;\
N4 = INST[0][83] & INST[0][0];\
N5 = INST[0][163] & INST[0][83];\
N6 = ~INST[0][0];\
N7 = N6 & INST[0][163];\
N8 = N5 | N7;\
N9 = N6 & INST[0][83];\
N10 = N0 & INST[0][83];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][83];\
INST[1][36]= N12 | N13;\
INST[1][37]= N8 | N9;\
INST[1][38]= N3 | N4;\
N0 = ~INST[0][159];\
N1 = N0 & INST[0][61];\
N2 = N0 & INST[0][52];\
N3 = N1 | N2;\
N4 = INST[0][61] & INST[0][52];\
N5 = INST[0][159] & INST[0][61];\
N6 = ~INST[0][52];\
N7 = N6 & INST[0][159];\
N8 = N5 | N7;\
N9 = N6 & INST[0][61];\
N10 = N0 & INST[0][61];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][61];\
INST[1][39]= N12 | N13;\
INST[1][40]= N8 | N9;\
INST[1][41]= N3 | N4;\
N0 = ~INST[0][80];\
N1 = N0 & INST[0][48];\
N2 = N0 & INST[0][84];\
N3 = N1 | N2;\
N4 = INST[0][48] & INST[0][84];\
N5 = INST[0][80] & INST[0][48];\
N6 = ~INST[0][84];\
N7 = N6 & INST[0][80];\
N8 = N5 | N7;\
N9 = N6 & INST[0][48];\
N10 = N0 & INST[0][48];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][48];\
INST[1][42]= N12 | N13;\
INST[1][43]= N8 | N9;\
INST[1][44]= N3 | N4;\
N0 = ~INST[0][134];\
N1 = N0 & INST[0][122];\
N2 = N0 & INST[0][130];\
N3 = N1 | N2;\
N4 = INST[0][122] & INST[0][130];\
N5 = INST[0][134] & INST[0][122];\
N6 = ~INST[0][130];\
N7 = N6 & INST[0][134];\
N8 = N5 | N7;\
N9 = N6 & INST[0][122];\
N10 = N0 & INST[0][122];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][122];\
INST[1][45]= N12 | N13;\
INST[1][46]= N8 | N9;\
INST[1][47]= N3 | N4;\
N0 = ~INST[0][62];\
N1 = N0 & INST[0][27];\
N2 = N0 & INST[0][3];\
N3 = N1 | N2;\
N4 = INST[0][27] & INST[0][3];\
N5 = INST[0][62] & INST[0][27];\
N6 = ~INST[0][3];\
N7 = N6 & INST[0][62];\
N8 = N5 | N7;\
N9 = N6 & INST[0][27];\
N10 = N0 & INST[0][27];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][27];\
INST[1][48]= N12 | N13;\
INST[1][49]= N8 | N9;\
INST[1][50]= N3 | N4;\
N0 = ~INST[0][46];\
N1 = N0 & INST[0][21];\
N2 = N0 & INST[0][154];\
N3 = N1 | N2;\
N4 = INST[0][21] & INST[0][154];\
N5 = INST[0][46] & INST[0][21];\
N6 = ~INST[0][154];\
N7 = N6 & INST[0][46];\
N8 = N5 | N7;\
N9 = N6 & INST[0][21];\
N10 = N0 & INST[0][21];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][21];\
INST[1][51]= N12 | N13;\
INST[1][52]= N8 | N9;\
INST[1][53]= N3 | N4;\
N0 = ~INST[0][99];\
N1 = N0 & INST[0][29];\
N2 = N0 & INST[0][81];\
N3 = N1 | N2;\
N4 = INST[0][29] & INST[0][81];\
N5 = INST[0][99] & INST[0][29];\
N6 = ~INST[0][81];\
N7 = N6 & INST[0][99];\
N8 = N5 | N7;\
N9 = N6 & INST[0][29];\
N10 = N0 & INST[0][29];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][29];\
INST[1][54]= N12 | N13;\
INST[1][55]= N8 | N9;\
INST[1][56]= N3 | N4;\
N0 = ~INST[0][26];\
N1 = N0 & INST[0][158];\
N2 = N0 & INST[0][132];\
N3 = N1 | N2;\
N4 = INST[0][158] & INST[0][132];\
N5 = INST[0][26] & INST[0][158];\
N6 = ~INST[0][132];\
N7 = N6 & INST[0][26];\
N8 = N5 | N7;\
N9 = N6 & INST[0][158];\
N10 = N0 & INST[0][158];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][158];\
INST[1][57]= N12 | N13;\
INST[1][58]= N8 | N9;\
INST[1][59]= N3 | N4;\
N0 = ~INST[0][126];\
N1 = N0 & INST[0][152];\
N2 = N0 & INST[0][72];\
N3 = N1 | N2;\
N4 = INST[0][152] & INST[0][72];\
N5 = INST[0][126] & INST[0][152];\
N6 = ~INST[0][72];\
N7 = N6 & INST[0][126];\
N8 = N5 | N7;\
N9 = N6 & INST[0][152];\
N10 = N0 & INST[0][152];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][152];\
INST[1][60]= N12 | N13;\
INST[1][61]= N8 | N9;\
INST[1][62]= N3 | N4;\
N0 = ~INST[0][166];\
N1 = N0 & INST[0][153];\
N2 = N0 & INST[0][11];\
N3 = N1 | N2;\
N4 = INST[0][153] & INST[0][11];\
N5 = INST[0][166] & INST[0][153];\
N6 = ~INST[0][11];\
N7 = N6 & INST[0][166];\
N8 = N5 | N7;\
N9 = N6 & INST[0][153];\
N10 = N0 & INST[0][153];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][153];\
INST[1][63]= N12 | N13;\
INST[1][64]= N8 | N9;\
INST[1][65]= N3 | N4;\
N0 = ~INST[0][50];\
N1 = N0 & INST[0][2];\
N2 = N0 & INST[0][131];\
N3 = N1 | N2;\
N4 = INST[0][2] & INST[0][131];\
N5 = INST[0][50] & INST[0][2];\
N6 = ~INST[0][131];\
N7 = N6 & INST[0][50];\
N8 = N5 | N7;\
N9 = N6 & INST[0][2];\
N10 = N0 & INST[0][2];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][2];\
INST[1][66]= N12 | N13;\
INST[1][67]= N8 | N9;\
INST[1][68]= N3 | N4;\
N0 = ~INST[0][95];\
N1 = N0 & INST[0][68];\
N2 = N0 & INST[0][145];\
N3 = N1 | N2;\
N4 = INST[0][68] & INST[0][145];\
N5 = INST[0][95] & INST[0][68];\
N6 = ~INST[0][145];\
N7 = N6 & INST[0][95];\
N8 = N5 | N7;\
N9 = N6 & INST[0][68];\
N10 = N0 & INST[0][68];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][68];\
INST[1][69]= N12 | N13;\
INST[1][70]= N8 | N9;\
INST[1][71]= N3 | N4;\
N0 = ~INST[0][20];\
N1 = N0 & INST[0][149];\
N2 = N0 & INST[0][24];\
N3 = N1 | N2;\
N4 = INST[0][149] & INST[0][24];\
N5 = INST[0][20] & INST[0][149];\
N6 = ~INST[0][24];\
N7 = N6 & INST[0][20];\
N8 = N5 | N7;\
N9 = N6 & INST[0][149];\
N10 = N0 & INST[0][149];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][149];\
INST[1][72]= N12 | N13;\
INST[1][73]= N8 | N9;\
INST[1][74]= N3 | N4;\
N0 = ~INST[0][1];\
N1 = N0 & INST[0][98];\
N2 = N0 & INST[0][23];\
N3 = N1 | N2;\
N4 = INST[0][98] & INST[0][23];\
N5 = INST[0][1] & INST[0][98];\
N6 = ~INST[0][23];\
N7 = N6 & INST[0][1];\
N8 = N5 | N7;\
N9 = N6 & INST[0][98];\
N10 = N0 & INST[0][98];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][98];\
INST[1][75]= N12 | N13;\
INST[1][76]= N8 | N9;\
INST[1][77]= N3 | N4;\
N0 = ~INST[0][162];\
N1 = N0 & INST[0][106];\
N2 = N0 & INST[0][136];\
N3 = N1 | N2;\
N4 = INST[0][106] & INST[0][136];\
N5 = INST[0][162] & INST[0][106];\
N6 = ~INST[0][136];\
N7 = N6 & INST[0][162];\
N8 = N5 | N7;\
N9 = N6 & INST[0][106];\
N10 = N0 & INST[0][106];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][106];\
INST[1][78]= N12 | N13;\
INST[1][79]= N8 | N9;\
INST[1][80]= N3 | N4;\
N0 = ~INST[0][65];\
N1 = N0 & INST[0][66];\
N2 = N0 & INST[0][47];\
N3 = N1 | N2;\
N4 = INST[0][66] & INST[0][47];\
N5 = INST[0][65] & INST[0][66];\
N6 = ~INST[0][47];\
N7 = N6 & INST[0][65];\
N8 = N5 | N7;\
N9 = N6 & INST[0][66];\
N10 = N0 & INST[0][66];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][66];\
INST[1][81]= N12 | N13;\
INST[1][82]= N8 | N9;\
INST[1][83]= N3 | N4;\
N0 = ~INST[0][9];\
N1 = N0 & INST[0][4];\
N2 = N0 & INST[0][103];\
N3 = N1 | N2;\
N4 = INST[0][4] & INST[0][103];\
N5 = INST[0][9] & INST[0][4];\
N6 = ~INST[0][103];\
N7 = N6 & INST[0][9];\
N8 = N5 | N7;\
N9 = N6 & INST[0][4];\
N10 = N0 & INST[0][4];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][4];\
INST[1][84]= N12 | N13;\
INST[1][85]= N8 | N9;\
INST[1][86]= N3 | N4;\
N0 = ~INST[0][109];\
N1 = N0 & INST[0][56];\
N2 = N0 & INST[0][124];\
N3 = N1 | N2;\
N4 = INST[0][56] & INST[0][124];\
N5 = INST[0][109] & INST[0][56];\
N6 = ~INST[0][124];\
N7 = N6 & INST[0][109];\
N8 = N5 | N7;\
N9 = N6 & INST[0][56];\
N10 = N0 & INST[0][56];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][56];\
INST[1][87]= N12 | N13;\
INST[1][88]= N8 | N9;\
INST[1][89]= N3 | N4;\
N0 = ~INST[0][111];\
N1 = N0 & INST[0][150];\
N2 = N0 & INST[0][45];\
N3 = N1 | N2;\
N4 = INST[0][150] & INST[0][45];\
N5 = INST[0][111] & INST[0][150];\
N6 = ~INST[0][45];\
N7 = N6 & INST[0][111];\
N8 = N5 | N7;\
N9 = N6 & INST[0][150];\
N10 = N0 & INST[0][150];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][150];\
INST[1][90]= N12 | N13;\
INST[1][91]= N8 | N9;\
INST[1][92]= N3 | N4;\
N0 = ~INST[0][16];\
N1 = N0 & INST[0][51];\
N2 = N0 & INST[0][85];\
N3 = N1 | N2;\
N4 = INST[0][51] & INST[0][85];\
N5 = INST[0][16] & INST[0][51];\
N6 = ~INST[0][85];\
N7 = N6 & INST[0][16];\
N8 = N5 | N7;\
N9 = N6 & INST[0][51];\
N10 = N0 & INST[0][51];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][51];\
INST[1][93]= N12 | N13;\
INST[1][94]= N8 | N9;\
INST[1][95]= N3 | N4;\
N0 = ~INST[0][100];\
N1 = N0 & INST[0][59];\
N2 = N0 & INST[0][8];\
N3 = N1 | N2;\
N4 = INST[0][59] & INST[0][8];\
N5 = INST[0][100] & INST[0][59];\
N6 = ~INST[0][8];\
N7 = N6 & INST[0][100];\
N8 = N5 | N7;\
N9 = N6 & INST[0][59];\
N10 = N0 & INST[0][59];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][59];\
INST[1][96]= N12 | N13;\
INST[1][97]= N8 | N9;\
INST[1][98]= N3 | N4;\
N0 = ~INST[0][17];\
N1 = N0 & INST[0][147];\
N2 = N0 & INST[0][89];\
N3 = N1 | N2;\
N4 = INST[0][147] & INST[0][89];\
N5 = INST[0][17] & INST[0][147];\
N6 = ~INST[0][89];\
N7 = N6 & INST[0][17];\
N8 = N5 | N7;\
N9 = N6 & INST[0][147];\
N10 = N0 & INST[0][147];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][147];\
INST[1][99]= N12 | N13;\
INST[1][100]= N8 | N9;\
INST[1][101]= N3 | N4;\
N0 = ~INST[0][33];\
N1 = N0 & INST[0][63];\
N2 = N0 & INST[0][144];\
N3 = N1 | N2;\
N4 = INST[0][63] & INST[0][144];\
N5 = INST[0][33] & INST[0][63];\
N6 = ~INST[0][144];\
N7 = N6 & INST[0][33];\
N8 = N5 | N7;\
N9 = N6 & INST[0][63];\
N10 = N0 & INST[0][63];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][63];\
INST[1][102]= N12 | N13;\
INST[1][103]= N8 | N9;\
INST[1][104]= N3 | N4;\
N0 = ~INST[0][125];\
N1 = N0 & INST[0][44];\
N2 = N0 & INST[0][35];\
N3 = N1 | N2;\
N4 = INST[0][44] & INST[0][35];\
N5 = INST[0][125] & INST[0][44];\
N6 = ~INST[0][35];\
N7 = N6 & INST[0][125];\
N8 = N5 | N7;\
N9 = N6 & INST[0][44];\
N10 = N0 & INST[0][44];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][44];\
INST[1][105]= N12 | N13;\
INST[1][106]= N8 | N9;\
INST[1][107]= N3 | N4;\
N0 = ~INST[0][36];\
N1 = N0 & INST[0][53];\
N2 = N0 & INST[0][148];\
N3 = N1 | N2;\
N4 = INST[0][53] & INST[0][148];\
N5 = INST[0][36] & INST[0][53];\
N6 = ~INST[0][148];\
N7 = N6 & INST[0][36];\
N8 = N5 | N7;\
N9 = N6 & INST[0][53];\
N10 = N0 & INST[0][53];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][53];\
INST[1][108]= N12 | N13;\
INST[1][109]= N8 | N9;\
INST[1][110]= N3 | N4;\
N0 = ~INST[0][139];\
N1 = N0 & INST[0][142];\
N2 = N0 & INST[0][14];\
N3 = N1 | N2;\
N4 = INST[0][142] & INST[0][14];\
N5 = INST[0][139] & INST[0][142];\
N6 = ~INST[0][14];\
N7 = N6 & INST[0][139];\
N8 = N5 | N7;\
N9 = N6 & INST[0][142];\
N10 = N0 & INST[0][142];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][142];\
INST[1][111]= N12 | N13;\
INST[1][112]= N8 | N9;\
INST[1][113]= N3 | N4;\
N0 = ~INST[0][127];\
N1 = N0 & INST[0][41];\
N2 = N0 & INST[0][94];\
N3 = N1 | N2;\
N4 = INST[0][41] & INST[0][94];\
N5 = INST[0][127] & INST[0][41];\
N6 = ~INST[0][94];\
N7 = N6 & INST[0][127];\
N8 = N5 | N7;\
N9 = N6 & INST[0][41];\
N10 = N0 & INST[0][41];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][41];\
INST[1][114]= N12 | N13;\
INST[1][115]= N8 | N9;\
INST[1][116]= N3 | N4;\
N0 = ~INST[0][6];\
N1 = N0 & INST[0][77];\
N2 = N0 & INST[0][7];\
N3 = N1 | N2;\
N4 = INST[0][77] & INST[0][7];\
N5 = INST[0][6] & INST[0][77];\
N6 = ~INST[0][7];\
N7 = N6 & INST[0][6];\
N8 = N5 | N7;\
N9 = N6 & INST[0][77];\
N10 = N0 & INST[0][77];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][77];\
INST[1][117]= N12 | N13;\
INST[1][118]= N8 | N9;\
INST[1][119]= N3 | N4;\
N0 = ~INST[0][138];\
N1 = N0 & INST[0][39];\
N2 = N0 & INST[0][49];\
N3 = N1 | N2;\
N4 = INST[0][39] & INST[0][49];\
N5 = INST[0][138] & INST[0][39];\
N6 = ~INST[0][49];\
N7 = N6 & INST[0][138];\
N8 = N5 | N7;\
N9 = N6 & INST[0][39];\
N10 = N0 & INST[0][39];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][39];\
INST[1][120]= N12 | N13;\
INST[1][121]= N8 | N9;\
INST[1][122]= N3 | N4;\
N0 = ~INST[0][155];\
N1 = N0 & INST[0][22];\
N2 = N0 & INST[0][88];\
N3 = N1 | N2;\
N4 = INST[0][22] & INST[0][88];\
N5 = INST[0][155] & INST[0][22];\
N6 = ~INST[0][88];\
N7 = N6 & INST[0][155];\
N8 = N5 | N7;\
N9 = N6 & INST[0][22];\
N10 = N0 & INST[0][22];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][22];\
INST[1][123]= N12 | N13;\
INST[1][124]= N8 | N9;\
INST[1][125]= N3 | N4;\
N0 = ~INST[0][43];\
N1 = N0 & INST[0][102];\
N2 = N0 & INST[0][57];\
N3 = N1 | N2;\
N4 = INST[0][102] & INST[0][57];\
N5 = INST[0][43] & INST[0][102];\
N6 = ~INST[0][57];\
N7 = N6 & INST[0][43];\
N8 = N5 | N7;\
N9 = N6 & INST[0][102];\
N10 = N0 & INST[0][102];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][102];\
INST[1][126]= N12 | N13;\
INST[1][127]= N8 | N9;\
INST[1][128]= N3 | N4;\
N0 = ~INST[0][37];\
N1 = N0 & INST[0][120];\
N2 = N0 & INST[0][96];\
N3 = N1 | N2;\
N4 = INST[0][120] & INST[0][96];\
N5 = INST[0][37] & INST[0][120];\
N6 = ~INST[0][96];\
N7 = N6 & INST[0][37];\
N8 = N5 | N7;\
N9 = N6 & INST[0][120];\
N10 = N0 & INST[0][120];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][120];\
INST[1][129]= N12 | N13;\
INST[1][130]= N8 | N9;\
INST[1][131]= N3 | N4;\
N0 = ~INST[0][151];\
N1 = N0 & INST[0][93];\
N2 = N0 & INST[0][119];\
N3 = N1 | N2;\
N4 = INST[0][93] & INST[0][119];\
N5 = INST[0][151] & INST[0][93];\
N6 = ~INST[0][119];\
N7 = N6 & INST[0][151];\
N8 = N5 | N7;\
N9 = N6 & INST[0][93];\
N10 = N0 & INST[0][93];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][93];\
INST[1][132]= N12 | N13;\
INST[1][133]= N8 | N9;\
INST[1][134]= N3 | N4;\
N0 = ~INST[0][30];\
N1 = N0 & INST[0][64];\
N2 = N0 & INST[0][32];\
N3 = N1 | N2;\
N4 = INST[0][64] & INST[0][32];\
N5 = INST[0][30] & INST[0][64];\
N6 = ~INST[0][32];\
N7 = N6 & INST[0][30];\
N8 = N5 | N7;\
N9 = N6 & INST[0][64];\
N10 = N0 & INST[0][64];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][64];\
INST[1][135]= N12 | N13;\
INST[1][136]= N8 | N9;\
INST[1][137]= N3 | N4;\
N0 = ~INST[0][55];\
N1 = N0 & INST[0][78];\
N2 = N0 & INST[0][112];\
N3 = N1 | N2;\
N4 = INST[0][78] & INST[0][112];\
N5 = INST[0][55] & INST[0][78];\
N6 = ~INST[0][112];\
N7 = N6 & INST[0][55];\
N8 = N5 | N7;\
N9 = N6 & INST[0][78];\
N10 = N0 & INST[0][78];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][78];\
INST[1][138]= N12 | N13;\
INST[1][139]= N8 | N9;\
INST[1][140]= N3 | N4;\
N0 = ~INST[0][104];\
N1 = N0 & INST[0][58];\
N2 = N0 & INST[0][15];\
N3 = N1 | N2;\
N4 = INST[0][58] & INST[0][15];\
N5 = INST[0][104] & INST[0][58];\
N6 = ~INST[0][15];\
N7 = N6 & INST[0][104];\
N8 = N5 | N7;\
N9 = N6 & INST[0][58];\
N10 = N0 & INST[0][58];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][58];\
INST[1][141]= N12 | N13;\
INST[1][142]= N8 | N9;\
INST[1][143]= N3 | N4;\
N0 = ~INST[0][165];\
N1 = N0 & INST[0][82];\
N2 = N0 & INST[0][25];\
N3 = N1 | N2;\
N4 = INST[0][82] & INST[0][25];\
N5 = INST[0][165] & INST[0][82];\
N6 = ~INST[0][25];\
N7 = N6 & INST[0][165];\
N8 = N5 | N7;\
N9 = N6 & INST[0][82];\
N10 = N0 & INST[0][82];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][82];\
INST[1][144]= N12 | N13;\
INST[1][145]= N8 | N9;\
INST[1][146]= N3 | N4;\
N0 = ~INST[0][167];\
N1 = N0 & INST[0][75];\
N2 = N0 & INST[0][101];\
N3 = N1 | N2;\
N4 = INST[0][75] & INST[0][101];\
N5 = INST[0][167] & INST[0][75];\
N6 = ~INST[0][101];\
N7 = N6 & INST[0][167];\
N8 = N5 | N7;\
N9 = N6 & INST[0][75];\
N10 = N0 & INST[0][75];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][75];\
INST[1][147]= N12 | N13;\
INST[1][148]= N8 | N9;\
INST[1][149]= N3 | N4;\
N0 = ~INST[0][114];\
N1 = N0 & INST[0][73];\
N2 = N0 & INST[0][86];\
N3 = N1 | N2;\
N4 = INST[0][73] & INST[0][86];\
N5 = INST[0][114] & INST[0][73];\
N6 = ~INST[0][86];\
N7 = N6 & INST[0][114];\
N8 = N5 | N7;\
N9 = N6 & INST[0][73];\
N10 = N0 & INST[0][73];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][73];\
INST[1][150]= N12 | N13;\
INST[1][151]= N8 | N9;\
INST[1][152]= N3 | N4;\
N0 = ~INST[0][133];\
N1 = N0 & INST[0][31];\
N2 = N0 & INST[0][156];\
N3 = N1 | N2;\
N4 = INST[0][31] & INST[0][156];\
N5 = INST[0][133] & INST[0][31];\
N6 = ~INST[0][156];\
N7 = N6 & INST[0][133];\
N8 = N5 | N7;\
N9 = N6 & INST[0][31];\
N10 = N0 & INST[0][31];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][31];\
INST[1][153]= N12 | N13;\
INST[1][154]= N8 | N9;\
INST[1][155]= N3 | N4;\
N0 = ~INST[0][137];\
N1 = N0 & INST[0][87];\
N2 = N0 & INST[0][70];\
N3 = N1 | N2;\
N4 = INST[0][87] & INST[0][70];\
N5 = INST[0][137] & INST[0][87];\
N6 = ~INST[0][70];\
N7 = N6 & INST[0][137];\
N8 = N5 | N7;\
N9 = N6 & INST[0][87];\
N10 = N0 & INST[0][87];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][87];\
INST[1][156]= N12 | N13;\
INST[1][157]= N8 | N9;\
INST[1][158]= N3 | N4;\
N0 = ~INST[0][5];\
N1 = N0 & INST[0][121];\
N2 = N0 & INST[0][71];\
N3 = N1 | N2;\
N4 = INST[0][121] & INST[0][71];\
N5 = INST[0][5] & INST[0][121];\
N6 = ~INST[0][71];\
N7 = N6 & INST[0][5];\
N8 = N5 | N7;\
N9 = N6 & INST[0][121];\
N10 = N0 & INST[0][121];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][121];\
INST[1][159]= N12 | N13;\
INST[1][160]= N8 | N9;\
INST[1][161]= N3 | N4;\
N0 = ~INST[0][10];\
N1 = N0 & INST[0][116];\
N2 = N0 & INST[0][110];\
N3 = N1 | N2;\
N4 = INST[0][116] & INST[0][110];\
N5 = INST[0][10] & INST[0][116];\
N6 = ~INST[0][110];\
N7 = N6 & INST[0][10];\
N8 = N5 | N7;\
N9 = N6 & INST[0][116];\
N10 = N0 & INST[0][116];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][116];\
INST[1][162]= N12 | N13;\
INST[1][163]= N8 | N9;\
INST[1][164]= N3 | N4;\
N0 = ~INST[0][164];\
N1 = N0 & INST[0][90];\
N2 = N0 & INST[0][40];\
N3 = N1 | N2;\
N4 = INST[0][90] & INST[0][40];\
N5 = INST[0][164] & INST[0][90];\
N6 = ~INST[0][40];\
N7 = N6 & INST[0][164];\
N8 = N5 | N7;\
N9 = N6 & INST[0][90];\
N10 = N0 & INST[0][90];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[0][90];\
INST[1][165]= N12 | N13;\
INST[1][166]= N8 | N9;\
INST[1][167]= N3 | N4;\
}
#endif
#ifndef XOR5_H
#define XOR5_H
#define XOR5(INST) {\
INST[0][0] = INST[1][63] ^ INST[1][96] ^ INST[1][25];\
INST[0][1] = INST[1][96] ^ INST[1][153];\
INST[0][2] = INST[1][153] ^ INST[1][25];\
INST[0][3] = INST[1][25] ^ INST[1][12];\
INST[0][4] = INST[1][12] ^ INST[1][61];\
INST[0][5] = INST[1][61] ^ INST[1][5];\
INST[0][6] = INST[1][5] ^ INST[1][99];\
INST[0][7] = INST[1][99] ^ INST[1][137];\
INST[0][8] = INST[1][137] ^ INST[1][92];\
INST[0][9] = INST[1][92] ^ INST[1][23];\
INST[0][10] = INST[1][23] ^ INST[1][154];\
INST[0][11] = INST[1][154] ^ INST[1][33];\
INST[0][12] = INST[1][33] ^ INST[1][161];\
INST[0][13] = INST[1][161] ^ INST[1][55];\
INST[0][14] = INST[1][55] ^ INST[1][16];\
INST[0][15] = INST[1][16] ^ INST[1][64];\
INST[0][16] = INST[1][64] ^ INST[1][130];\
INST[0][17] = INST[1][130] ^ INST[1][110];\
INST[0][18] = INST[1][110] ^ INST[1][155];\
INST[0][19] = INST[1][155] ^ INST[1][21];\
INST[0][20] = INST[1][21] ^ INST[1][71];\
INST[0][21] = INST[1][71] ^ INST[1][60];\
INST[0][22] = INST[1][60] ^ INST[1][158];\
INST[0][23] = INST[1][158] ^ INST[1][116];\
INST[0][24] = INST[1][116] ^ INST[1][127];\
INST[0][25] = INST[1][127] ^ INST[1][3];\
INST[0][26] = INST[1][3] ^ INST[1][139];\
INST[0][27] = INST[1][139] ^ INST[1][54];\
INST[0][28] = INST[1][54] ^ INST[1][1];\
INST[0][29] = INST[1][1] ^ INST[1][84];\
INST[0][30] = INST[1][84] ^ INST[1][57];\
INST[0][31] = INST[1][57] ^ INST[1][90];\
INST[0][32] = INST[1][90] ^ INST[1][48];\
INST[0][33] = INST[1][48] ^ INST[1][149];\
INST[0][34] = INST[1][149] ^ INST[1][115];\
INST[0][35] = INST[1][115] ^ INST[1][7];\
INST[0][36] = INST[1][7] ^ INST[1][24];\
INST[0][37] = INST[1][24] ^ INST[1][70];\
INST[0][38] = INST[1][70] ^ INST[1][143];\
INST[0][39] = INST[1][143] ^ INST[1][74];\
INST[0][40] = INST[1][74] ^ INST[1][78];\
INST[0][41] = INST[1][78] ^ INST[1][135];\
INST[0][42] = INST[1][135] ^ INST[1][52];\
INST[0][43] = INST[1][52] ^ INST[1][4];\
INST[0][44] = INST[1][4] ^ INST[1][126];\
INST[0][45] = INST[1][126] ^ INST[1][91];\
INST[0][46] = INST[1][91] ^ INST[1][165];\
INST[0][47] = INST[1][165] ^ INST[1][40];\
INST[0][48] = INST[1][40] ^ INST[1][56];\
INST[0][49] = INST[1][56] ^ INST[1][68];\
INST[0][50] = INST[1][68] ^ INST[1][87];\
INST[0][51] = INST[1][87] ^ INST[1][2];\
INST[0][52] = INST[1][2] ^ INST[1][8];\
INST[0][53] = INST[1][8] ^ INST[1][141];\
INST[0][54] = INST[1][141] ^ INST[1][44];\
INST[0][55] = INST[1][44] ^ INST[1][34];\
INST[0][56] = INST[1][34] ^ INST[1][167];\
INST[0][57] = INST[1][167] ^ INST[1][27];\
INST[0][58] = INST[1][27] ^ INST[1][113];\
INST[0][59] = INST[1][113] ^ INST[1][29];\
INST[0][60] = INST[1][29] ^ INST[1][46];\
INST[0][61] = INST[1][46] ^ INST[1][41];\
INST[0][62] = INST[1][41] ^ INST[1][42];\
INST[0][63] = INST[1][42] ^ INST[1][142];\
INST[0][64] = INST[1][142] ^ INST[1][22];\
INST[0][65] = INST[1][22] ^ INST[1][160];\
INST[0][66] = INST[1][160] ^ INST[1][145];\
INST[0][67] = INST[1][145] ^ INST[1][85];\
INST[0][68] = INST[1][85] ^ INST[1][132];\
INST[0][69] = INST[1][132] ^ INST[1][103];\
INST[0][70] = INST[1][103] ^ INST[1][65];\
INST[0][71] = INST[1][65] ^ INST[1][133];\
INST[0][72] = INST[1][133] ^ INST[1][53];\
INST[0][73] = INST[1][53] ^ INST[1][134];\
INST[0][74] = INST[1][134] ^ INST[1][86];\
INST[0][75] = INST[1][86] ^ INST[1][151];\
INST[0][76] = INST[1][151] ^ INST[1][114];\
INST[0][77] = INST[1][114] ^ INST[1][0];\
INST[0][78] = INST[1][0] ^ INST[1][152];\
INST[0][79] = INST[1][152] ^ INST[1][147];\
INST[0][80] = INST[1][147] ^ INST[1][117];\
INST[0][81] = INST[1][117] ^ INST[1][97];\
INST[0][82] = INST[1][97] ^ INST[1][58];\
INST[0][83] = INST[1][58] ^ INST[1][95];\
INST[0][84] = INST[1][95] ^ INST[1][66];\
INST[0][85] = INST[1][66] ^ INST[1][35];\
INST[0][86] = INST[1][35] ^ INST[1][164];\
INST[0][87] = INST[1][164] ^ INST[1][77];\
INST[0][88] = INST[1][77] ^ INST[1][82];\
INST[0][89] = INST[1][82] ^ INST[1][32];\
INST[0][90] = INST[1][32] ^ INST[1][125];\
INST[0][91] = INST[1][125] ^ INST[1][36];\
INST[0][92] = INST[1][36] ^ INST[1][108];\
INST[0][93] = INST[1][108] ^ INST[1][10];\
INST[0][94] = INST[1][10] ^ INST[1][162];\
INST[0][95] = INST[1][162] ^ INST[1][112];\
INST[0][96] = INST[1][112] ^ INST[1][28];\
INST[0][97] = INST[1][28] ^ INST[1][159];\
INST[0][98] = INST[1][159] ^ INST[1][111];\
INST[0][99] = INST[1][111] ^ INST[1][59];\
INST[0][100] = INST[1][59] ^ INST[1][73];\
INST[0][101] = INST[1][73] ^ INST[1][109];\
INST[0][102] = INST[1][109] ^ INST[1][80];\
INST[0][103] = INST[1][80] ^ INST[1][128];\
INST[0][104] = INST[1][128] ^ INST[1][121];\
INST[0][105] = INST[1][121] ^ INST[1][50];\
INST[0][106] = INST[1][50] ^ INST[1][88];\
INST[0][107] = INST[1][88] ^ INST[1][148];\
INST[0][108] = INST[1][148] ^ INST[1][89];\
INST[0][109] = INST[1][89] ^ INST[1][94];\
INST[0][110] = INST[1][94] ^ INST[1][93];\
INST[0][111] = INST[1][93] ^ INST[1][136];\
INST[0][112] = INST[1][136] ^ INST[1][72];\
INST[0][113] = INST[1][72] ^ INST[1][39];\
INST[0][114] = INST[1][39] ^ INST[1][69];\
INST[0][115] = INST[1][69] ^ INST[1][18];\
INST[0][116] = INST[1][18] ^ INST[1][138];\
INST[0][117] = INST[1][138] ^ INST[1][156];\
INST[0][118] = INST[1][156] ^ INST[1][163];\
INST[0][119] = INST[1][163] ^ INST[1][76];\
INST[0][120] = INST[1][76] ^ INST[1][19];\
INST[0][121] = INST[1][19] ^ INST[1][98];\
INST[0][122] = INST[1][98] ^ INST[1][146];\
INST[0][123] = INST[1][146] ^ INST[1][11];\
INST[0][124] = INST[1][11] ^ INST[1][15];\
INST[0][125] = INST[1][15] ^ INST[1][107];\
INST[0][126] = INST[1][107] ^ INST[1][140];\
INST[0][127] = INST[1][140] ^ INST[1][6];\
INST[0][128] = INST[1][6] ^ INST[1][120];\
INST[0][129] = INST[1][120] ^ INST[1][129];\
INST[0][130] = INST[1][129] ^ INST[1][123];\
INST[0][131] = INST[1][123] ^ INST[1][166];\
INST[0][132] = INST[1][166] ^ INST[1][150];\
INST[0][133] = INST[1][150] ^ INST[1][14];\
INST[0][134] = INST[1][14] ^ INST[1][101];\
INST[0][135] = INST[1][101] ^ INST[1][157];\
INST[0][136] = INST[1][157] ^ INST[1][49];\
INST[0][137] = INST[1][49] ^ INST[1][37];\
INST[0][138] = INST[1][37] ^ INST[1][119];\
INST[0][139] = INST[1][119] ^ INST[1][13];\
INST[0][140] = INST[1][13] ^ INST[1][30];\
INST[0][141] = INST[1][30] ^ INST[1][100];\
INST[0][142] = INST[1][100] ^ INST[1][81];\
INST[0][143] = INST[1][81] ^ INST[1][17];\
INST[0][144] = INST[1][17] ^ INST[1][118];\
INST[0][145] = INST[1][118] ^ INST[1][45];\
INST[0][146] = INST[1][45] ^ INST[1][20];\
INST[0][147] = INST[1][20] ^ INST[1][47];\
INST[0][148] = INST[1][47] ^ INST[1][106];\
INST[0][149] = INST[1][106] ^ INST[1][102];\
INST[0][150] = INST[1][102] ^ INST[1][131];\
INST[0][151] = INST[1][131] ^ INST[1][38];\
INST[0][152] = INST[1][38] ^ INST[1][75];\
INST[0][153] = INST[1][75] ^ INST[1][104];\
INST[0][154] = INST[1][104] ^ INST[1][31];\
INST[0][155] = INST[1][31] ^ INST[1][43];\
INST[0][156] = INST[1][43] ^ INST[1][62];\
INST[0][157] = INST[1][62] ^ INST[1][105];\
INST[0][158] = INST[1][105] ^ INST[1][9];\
INST[0][159] = INST[1][9] ^ INST[1][79];\
INST[0][160] = INST[1][79] ^ INST[1][124];\
INST[0][161] = INST[1][124] ^ INST[1][51];\
INST[0][162] = INST[1][51] ^ INST[1][67];\
INST[0][163] = INST[1][67] ^ INST[1][144];\
INST[0][164] = INST[1][144] ^ INST[1][26];\
INST[0][165] = INST[1][26] ^ INST[1][83];\
INST[0][166] = INST[1][83] ^ INST[1][122];\
INST[0][167] = INST[1][122] ^ INST[1][63];\
}
#endif
#ifndef XOR6_H
#define XOR6_H
#define XOR6(INST) {\
INST[1][0] = INST[0][118] ^ INST[0][65] ^ INST[0][80];\
INST[1][1] = INST[0][65] ^ INST[0][5];\
INST[1][2] = INST[0][5] ^ INST[0][80];\
INST[1][3] = INST[0][80] ^ INST[0][22];\
INST[1][4] = INST[0][22] ^ INST[0][31];\
INST[1][5] = INST[0][31] ^ INST[0][34];\
INST[1][6] = INST[0][34] ^ INST[0][53];\
INST[1][7] = INST[0][53] ^ INST[0][13];\
INST[1][8] = INST[0][13] ^ INST[0][149];\
INST[1][9] = INST[0][149] ^ INST[0][152];\
INST[1][10] = INST[0][152] ^ INST[0][157];\
INST[1][11] = INST[0][157] ^ INST[0][141];\
INST[1][12] = INST[0][141] ^ INST[0][147];\
INST[1][13] = INST[0][147] ^ INST[0][129];\
INST[1][14] = INST[0][129] ^ INST[0][9];\
INST[1][15] = INST[0][9] ^ INST[0][93];\
INST[1][16] = INST[0][93] ^ INST[0][47];\
INST[1][17] = INST[0][47] ^ INST[0][71];\
INST[1][18] = INST[0][71] ^ INST[0][19];\
INST[1][19] = INST[0][19] ^ INST[0][114];\
INST[1][20] = INST[0][114] ^ INST[0][162];\
INST[1][21] = INST[0][162] ^ INST[0][134];\
INST[1][22] = INST[0][134] ^ INST[0][140];\
INST[1][23] = INST[0][140] ^ INST[0][12];\
INST[1][24] = INST[0][12] ^ INST[0][128];\
INST[1][25] = INST[0][128] ^ INST[0][69];\
INST[1][26] = INST[0][69] ^ INST[0][87];\
INST[1][27] = INST[0][87] ^ INST[0][70];\
INST[1][28] = INST[0][70] ^ INST[0][17];\
INST[1][29] = INST[0][17] ^ INST[0][166];\
INST[1][30] = INST[0][166] ^ INST[0][137];\
INST[1][31] = INST[0][137] ^ INST[0][83];\
INST[1][32] = INST[0][83] ^ INST[0][135];\
INST[1][33] = INST[0][135] ^ INST[0][86];\
INST[1][34] = INST[0][86] ^ INST[0][46];\
INST[1][35] = INST[0][46] ^ INST[0][126];\
INST[1][36] = INST[0][126] ^ INST[0][25];\
INST[1][37] = INST[0][25] ^ INST[0][143];\
INST[1][38] = INST[0][143] ^ INST[0][110];\
INST[1][39] = INST[0][110] ^ INST[0][148];\
INST[1][40] = INST[0][148] ^ INST[0][94];\
INST[1][41] = INST[0][94] ^ INST[0][120];\
INST[1][42] = INST[0][120] ^ INST[0][59];\
INST[1][43] = INST[0][59] ^ INST[0][58];\
INST[1][44] = INST[0][58] ^ INST[0][23];\
INST[1][45] = INST[0][23] ^ INST[0][151];\
INST[1][46] = INST[0][151] ^ INST[0][99];\
INST[1][47] = INST[0][99] ^ INST[0][18];\
INST[1][48] = INST[0][18] ^ INST[0][44];\
INST[1][49] = INST[0][44] ^ INST[0][78];\
INST[1][50] = INST[0][78] ^ INST[0][39];\
INST[1][51] = INST[0][39] ^ INST[0][165];\
INST[1][52] = INST[0][165] ^ INST[0][50];\
INST[1][53] = INST[0][50] ^ INST[0][48];\
INST[1][54] = INST[0][48] ^ INST[0][74];\
INST[1][55] = INST[0][74] ^ INST[0][32];\
INST[1][56] = INST[0][32] ^ INST[0][66];\
INST[1][57] = INST[0][66] ^ INST[0][3];\
INST[1][58] = INST[0][3] ^ INST[0][142];\
INST[1][59] = INST[0][142] ^ INST[0][68];\
INST[1][60] = INST[0][68] ^ INST[0][40];\
INST[1][61] = INST[0][40] ^ INST[0][103];\
INST[1][62] = INST[0][103] ^ INST[0][37];\
INST[1][63] = INST[0][37] ^ INST[0][67];\
INST[1][64] = INST[0][67] ^ INST[0][55];\
INST[1][65] = INST[0][55] ^ INST[0][20];\
INST[1][66] = INST[0][20] ^ INST[0][62];\
INST[1][67] = INST[0][62] ^ INST[0][2];\
INST[1][68] = INST[0][2] ^ INST[0][112];\
INST[1][69] = INST[0][112] ^ INST[0][98];\
INST[1][70] = INST[0][98] ^ INST[0][95];\
INST[1][71] = INST[0][95] ^ INST[0][82];\
INST[1][72] = INST[0][82] ^ INST[0][6];\
INST[1][73] = INST[0][6] ^ INST[0][105];\
INST[1][74] = INST[0][105] ^ INST[0][124];\
INST[1][75] = INST[0][124] ^ INST[0][15];\
INST[1][76] = INST[0][15] ^ INST[0][102];\
INST[1][77] = INST[0][102] ^ INST[0][21];\
INST[1][78] = INST[0][21] ^ INST[0][139];\
INST[1][79] = INST[0][139] ^ INST[0][111];\
INST[1][80] = INST[0][111] ^ INST[0][8];\
INST[1][81] = INST[0][8] ^ INST[0][92];\
INST[1][82] = INST[0][92] ^ INST[0][49];\
INST[1][83] = INST[0][49] ^ INST[0][52];\
INST[1][84] = INST[0][52] ^ INST[0][119];\
INST[1][85] = INST[0][119] ^ INST[0][35];\
INST[1][86] = INST[0][35] ^ INST[0][30];\
INST[1][87] = INST[0][30] ^ INST[0][89];\
INST[1][88] = INST[0][89] ^ INST[0][136];\
INST[1][89] = INST[0][136] ^ INST[0][28];\
INST[1][90] = INST[0][28] ^ INST[0][138];\
INST[1][91] = INST[0][138] ^ INST[0][131];\
INST[1][92] = INST[0][131] ^ INST[0][56];\
INST[1][93] = INST[0][56] ^ INST[0][26];\
INST[1][94] = INST[0][26] ^ INST[0][88];\
INST[1][95] = INST[0][88] ^ INST[0][90];\
INST[1][96] = INST[0][90] ^ INST[0][27];\
INST[1][97] = INST[0][27] ^ INST[0][51];\
INST[1][98] = INST[0][51] ^ INST[0][158];\
INST[1][99] = INST[0][158] ^ INST[0][117];\
INST[1][100] = INST[0][117] ^ INST[0][163];\
INST[1][101] = INST[0][163] ^ INST[0][4];\
INST[1][102] = INST[0][4] ^ INST[0][16];\
INST[1][103] = INST[0][16] ^ INST[0][29];\
INST[1][104] = INST[0][29] ^ INST[0][130];\
INST[1][105] = INST[0][130] ^ INST[0][75];\
INST[1][106] = INST[0][75] ^ INST[0][100];\
INST[1][107] = INST[0][100] ^ INST[0][125];\
INST[1][108] = INST[0][125] ^ INST[0][72];\
INST[1][109] = INST[0][72] ^ INST[0][81];\
INST[1][110] = INST[0][81] ^ INST[0][109];\
INST[1][111] = INST[0][109] ^ INST[0][122];\
INST[1][112] = INST[0][122] ^ INST[0][76];\
INST[1][113] = INST[0][76] ^ INST[0][73];\
INST[1][114] = INST[0][73] ^ INST[0][64];\
INST[1][115] = INST[0][64] ^ INST[0][41];\
INST[1][116] = INST[0][41] ^ INST[0][106];\
INST[1][117] = INST[0][106] ^ INST[0][14];\
INST[1][118] = INST[0][14] ^ INST[0][97];\
INST[1][119] = INST[0][97] ^ INST[0][38];\
INST[1][120] = INST[0][38] ^ INST[0][153];\
INST[1][121] = INST[0][153] ^ INST[0][24];\
INST[1][122] = INST[0][24] ^ INST[0][113];\
INST[1][123] = INST[0][113] ^ INST[0][42];\
INST[1][124] = INST[0][42] ^ INST[0][133];\
INST[1][125] = INST[0][133] ^ INST[0][96];\
INST[1][126] = INST[0][96] ^ INST[0][127];\
INST[1][127] = INST[0][127] ^ INST[0][91];\
INST[1][128] = INST[0][91] ^ INST[0][10];\
INST[1][129] = INST[0][10] ^ INST[0][121];\
INST[1][130] = INST[0][121] ^ INST[0][123];\
INST[1][131] = INST[0][123] ^ INST[0][154];\
INST[1][132] = INST[0][154] ^ INST[0][61];\
INST[1][133] = INST[0][61] ^ INST[0][161];\
INST[1][134] = INST[0][161] ^ INST[0][150];\
INST[1][135] = INST[0][150] ^ INST[0][160];\
INST[1][136] = INST[0][160] ^ INST[0][155];\
INST[1][137] = INST[0][155] ^ INST[0][101];\
INST[1][138] = INST[0][101] ^ INST[0][144];\
INST[1][139] = INST[0][144] ^ INST[0][104];\
INST[1][140] = INST[0][104] ^ INST[0][1];\
INST[1][141] = INST[0][1] ^ INST[0][115];\
INST[1][142] = INST[0][115] ^ INST[0][63];\
INST[1][143] = INST[0][63] ^ INST[0][45];\
INST[1][144] = INST[0][45] ^ INST[0][79];\
INST[1][145] = INST[0][79] ^ INST[0][107];\
INST[1][146] = INST[0][107] ^ INST[0][164];\
INST[1][147] = INST[0][164] ^ INST[0][156];\
INST[1][148] = INST[0][156] ^ INST[0][108];\
INST[1][149] = INST[0][108] ^ INST[0][36];\
INST[1][150] = INST[0][36] ^ INST[0][60];\
INST[1][151] = INST[0][60] ^ INST[0][77];\
INST[1][152] = INST[0][77] ^ INST[0][84];\
INST[1][153] = INST[0][84] ^ INST[0][159];\
INST[1][154] = INST[0][159] ^ INST[0][145];\
INST[1][155] = INST[0][145] ^ INST[0][167];\
INST[1][156] = INST[0][167] ^ INST[0][54];\
INST[1][157] = INST[0][54] ^ INST[0][132];\
INST[1][158] = INST[0][132] ^ INST[0][116];\
INST[1][159] = INST[0][116] ^ INST[0][85];\
INST[1][160] = INST[0][85] ^ INST[0][11];\
INST[1][161] = INST[0][11] ^ INST[0][7];\
INST[1][162] = INST[0][7] ^ INST[0][43];\
INST[1][163] = INST[0][43] ^ INST[0][57];\
INST[1][164] = INST[0][57] ^ INST[0][146];\
INST[1][165] = INST[0][146] ^ INST[0][0];\
INST[1][166] = INST[0][0] ^ INST[0][33];\
INST[1][167] = INST[0][33] ^ INST[0][118];\
}
#endif
#ifndef XOR7_H
#define XOR7_H
#define XOR7(INST) {\
INST[0][0] = INST[1][47] ^ INST[1][23] ^ INST[1][104];\
INST[0][1] = INST[1][23] ^ INST[1][35];\
INST[0][2] = INST[1][35] ^ INST[1][104];\
INST[0][3] = INST[1][104] ^ INST[1][146];\
INST[0][4] = INST[1][146] ^ INST[1][67];\
INST[0][5] = INST[1][67] ^ INST[1][129];\
INST[0][6] = INST[1][129] ^ INST[1][89];\
INST[0][7] = INST[1][89] ^ INST[1][159];\
INST[0][8] = INST[1][159] ^ INST[1][10];\
INST[0][9] = INST[1][10] ^ INST[1][24];\
INST[0][10] = INST[1][24] ^ INST[1][147];\
INST[0][11] = INST[1][147] ^ INST[1][137];\
INST[0][12] = INST[1][137] ^ INST[1][64];\
INST[0][13] = INST[1][64] ^ INST[1][143];\
INST[0][14] = INST[1][143] ^ INST[1][93];\
INST[0][15] = INST[1][93] ^ INST[1][158];\
INST[0][16] = INST[1][158] ^ INST[1][44];\
INST[0][17] = INST[1][44] ^ INST[1][128];\
INST[0][18] = INST[1][128] ^ INST[1][82];\
INST[0][19] = INST[1][82] ^ INST[1][37];\
INST[0][20] = INST[1][37] ^ INST[1][119];\
INST[0][21] = INST[1][119] ^ INST[1][66];\
INST[0][22] = INST[1][66] ^ INST[1][71];\
INST[0][23] = INST[1][71] ^ INST[1][27];\
INST[0][24] = INST[1][27] ^ INST[1][34];\
INST[0][25] = INST[1][34] ^ INST[1][121];\
INST[0][26] = INST[1][121] ^ INST[1][118];\
INST[0][27] = INST[1][118] ^ INST[1][98];\
INST[0][28] = INST[1][98] ^ INST[1][139];\
INST[0][29] = INST[1][139] ^ INST[1][111];\
INST[0][30] = INST[1][111] ^ INST[1][8];\
INST[0][31] = INST[1][8] ^ INST[1][5];\
INST[0][32] = INST[1][5] ^ INST[1][108];\
INST[0][33] = INST[1][108] ^ INST[1][14];\
INST[0][34] = INST[1][14] ^ INST[1][11];\
INST[0][35] = INST[1][11] ^ INST[1][124];\
INST[0][36] = INST[1][124] ^ INST[1][65];\
INST[0][37] = INST[1][65] ^ INST[1][21];\
INST[0][38] = INST[1][21] ^ INST[1][22];\
INST[0][39] = INST[1][22] ^ INST[1][100];\
INST[0][40] = INST[1][100] ^ INST[1][92];\
INST[0][41] = INST[1][92] ^ INST[1][50];\
INST[0][42] = INST[1][50] ^ INST[1][153];\
INST[0][43] = INST[1][153] ^ INST[1][79];\
INST[0][44] = INST[1][79] ^ INST[1][80];\
INST[0][45] = INST[1][80] ^ INST[1][150];\
INST[0][46] = INST[1][150] ^ INST[1][60];\
INST[0][47] = INST[1][60] ^ INST[1][133];\
INST[0][48] = INST[1][133] ^ INST[1][77];\
INST[0][49] = INST[1][77] ^ INST[1][20];\
INST[0][50] = INST[1][20] ^ INST[1][39];\
INST[0][51] = INST[1][39] ^ INST[1][13];\
INST[0][52] = INST[1][13] ^ INST[1][61];\
INST[0][53] = INST[1][61] ^ INST[1][154];\
INST[0][54] = INST[1][154] ^ INST[1][157];\
INST[0][55] = INST[1][157] ^ INST[1][106];\
INST[0][56] = INST[1][106] ^ INST[1][125];\
INST[0][57] = INST[1][125] ^ INST[1][18];\
INST[0][58] = INST[1][18] ^ INST[1][144];\
INST[0][59] = INST[1][144] ^ INST[1][7];\
INST[0][60] = INST[1][7] ^ INST[1][117];\
INST[0][61] = INST[1][117] ^ INST[1][102];\
INST[0][62] = INST[1][102] ^ INST[1][145];\
INST[0][63] = INST[1][145] ^ INST[1][84];\
INST[0][64] = INST[1][84] ^ INST[1][1];\
INST[0][65] = INST[1][1] ^ INST[1][3];\
INST[0][66] = INST[1][3] ^ INST[1][6];\
INST[0][67] = INST[1][6] ^ INST[1][134];\
INST[0][68] = INST[1][134] ^ INST[1][90];\
INST[0][69] = INST[1][90] ^ INST[1][105];\
INST[0][70] = INST[1][105] ^ INST[1][110];\
INST[0][71] = INST[1][110] ^ INST[1][51];\
INST[0][72] = INST[1][51] ^ INST[1][152];\
INST[0][73] = INST[1][152] ^ INST[1][156];\
INST[0][74] = INST[1][156] ^ INST[1][107];\
INST[0][75] = INST[1][107] ^ INST[1][33];\
INST[0][76] = INST[1][33] ^ INST[1][40];\
INST[0][77] = INST[1][40] ^ INST[1][70];\
INST[0][78] = INST[1][70] ^ INST[1][95];\
INST[0][79] = INST[1][95] ^ INST[1][120];\
INST[0][80] = INST[1][120] ^ INST[1][96];\
INST[0][81] = INST[1][96] ^ INST[1][160];\
INST[0][82] = INST[1][160] ^ INST[1][58];\
INST[0][83] = INST[1][58] ^ INST[1][17];\
INST[0][84] = INST[1][17] ^ INST[1][113];\
INST[0][85] = INST[1][113] ^ INST[1][15];\
INST[0][86] = INST[1][15] ^ INST[1][78];\
INST[0][87] = INST[1][78] ^ INST[1][88];\
INST[0][88] = INST[1][88] ^ INST[1][130];\
INST[0][89] = INST[1][130] ^ INST[1][38];\
INST[0][90] = INST[1][38] ^ INST[1][116];\
INST[0][91] = INST[1][116] ^ INST[1][101];\
INST[0][92] = INST[1][101] ^ INST[1][12];\
INST[0][93] = INST[1][12] ^ INST[1][16];\
INST[0][94] = INST[1][16] ^ INST[1][45];\
INST[0][95] = INST[1][45] ^ INST[1][122];\
INST[0][96] = INST[1][122] ^ INST[1][91];\
INST[0][97] = INST[1][91] ^ INST[1][115];\
INST[0][98] = INST[1][115] ^ INST[1][148];\
INST[0][99] = INST[1][148] ^ INST[1][52];\
INST[0][100] = INST[1][52] ^ INST[1][72];\
INST[0][101] = INST[1][72] ^ INST[1][114];\
INST[0][102] = INST[1][114] ^ INST[1][155];\
INST[0][103] = INST[1][155] ^ INST[1][32];\
INST[0][104] = INST[1][32] ^ INST[1][41];\
INST[0][105] = INST[1][41] ^ INST[1][48];\
INST[0][106] = INST[1][48] ^ INST[1][103];\
INST[0][107] = INST[1][103] ^ INST[1][166];\
INST[0][108] = INST[1][166] ^ INST[1][56];\
INST[0][109] = INST[1][56] ^ INST[1][76];\
INST[0][110] = INST[1][76] ^ INST[1][112];\
INST[0][111] = INST[1][112] ^ INST[1][81];\
INST[0][112] = INST[1][81] ^ INST[1][135];\
INST[0][113] = INST[1][135] ^ INST[1][55];\
INST[0][114] = INST[1][55] ^ INST[1][94];\
INST[0][115] = INST[1][94] ^ INST[1][109];\
INST[0][116] = INST[1][109] ^ INST[1][42];\
INST[0][117] = INST[1][42] ^ INST[1][167];\
INST[0][118] = INST[1][167] ^ INST[1][151];\
INST[0][119] = INST[1][151] ^ INST[1][75];\
INST[0][120] = INST[1][75] ^ INST[1][28];\
INST[0][121] = INST[1][28] ^ INST[1][132];\
INST[0][122] = INST[1][132] ^ INST[1][85];\
INST[0][123] = INST[1][85] ^ INST[1][131];\
INST[0][124] = INST[1][131] ^ INST[1][163];\
INST[0][125] = INST[1][163] ^ INST[1][53];\
INST[0][126] = INST[1][53] ^ INST[1][73];\
INST[0][127] = INST[1][73] ^ INST[1][161];\
INST[0][128] = INST[1][161] ^ INST[1][97];\
INST[0][129] = INST[1][97] ^ INST[1][162];\
INST[0][130] = INST[1][162] ^ INST[1][126];\
INST[0][131] = INST[1][126] ^ INST[1][54];\
INST[0][132] = INST[1][54] ^ INST[1][4];\
INST[0][133] = INST[1][4] ^ INST[1][36];\
INST[0][134] = INST[1][36] ^ INST[1][30];\
INST[0][135] = INST[1][30] ^ INST[1][99];\
INST[0][136] = INST[1][99] ^ INST[1][149];\
INST[0][137] = INST[1][149] ^ INST[1][164];\
INST[0][138] = INST[1][164] ^ INST[1][57];\
INST[0][139] = INST[1][57] ^ INST[1][49];\
INST[0][140] = INST[1][49] ^ INST[1][9];\
INST[0][141] = INST[1][9] ^ INST[1][127];\
INST[0][142] = INST[1][127] ^ INST[1][142];\
INST[0][143] = INST[1][142] ^ INST[1][136];\
INST[0][144] = INST[1][136] ^ INST[1][46];\
INST[0][145] = INST[1][46] ^ INST[1][62];\
INST[0][146] = INST[1][62] ^ INST[1][68];\
INST[0][147] = INST[1][68] ^ INST[1][0];\
INST[0][148] = INST[1][0] ^ INST[1][31];\
INST[0][149] = INST[1][31] ^ INST[1][19];\
INST[0][150] = INST[1][19] ^ INST[1][165];\
INST[0][151] = INST[1][165] ^ INST[1][26];\
INST[0][152] = INST[1][26] ^ INST[1][86];\
INST[0][153] = INST[1][86] ^ INST[1][87];\
INST[0][154] = INST[1][87] ^ INST[1][59];\
INST[0][155] = INST[1][59] ^ INST[1][69];\
INST[0][156] = INST[1][69] ^ INST[1][43];\
INST[0][157] = INST[1][43] ^ INST[1][25];\
INST[0][158] = INST[1][25] ^ INST[1][2];\
INST[0][159] = INST[1][2] ^ INST[1][123];\
INST[0][160] = INST[1][123] ^ INST[1][74];\
INST[0][161] = INST[1][74] ^ INST[1][63];\
INST[0][162] = INST[1][63] ^ INST[1][138];\
INST[0][163] = INST[1][138] ^ INST[1][83];\
INST[0][164] = INST[1][83] ^ INST[1][140];\
INST[0][165] = INST[1][140] ^ INST[1][141];\
INST[0][166] = INST[1][141] ^ INST[1][29];\
INST[0][167] = INST[1][29] ^ INST[1][47];\
}
#endif
#ifndef XOR8_H
#define XOR8_H
#define XOR8(INST) {\
INST[1][0] = INST[0][44] ^ INST[0][118] ^ INST[0][59];\
INST[1][1] = INST[0][118] ^ INST[0][134];\
INST[1][2] = INST[0][134] ^ INST[0][59];\
INST[1][3] = INST[0][59] ^ INST[0][139];\
INST[1][4] = INST[0][139] ^ INST[0][150];\
INST[1][5] = INST[0][150] ^ INST[0][51];\
INST[1][6] = INST[0][51] ^ INST[0][60];\
INST[1][7] = INST[0][60] ^ INST[0][132];\
INST[1][8] = INST[0][132] ^ INST[0][89];\
INST[1][9] = INST[0][89] ^ INST[0][166];\
INST[1][10] = INST[0][166] ^ INST[0][144];\
INST[1][11] = INST[0][144] ^ INST[0][75];\
INST[1][12] = INST[0][75] ^ INST[0][162];\
INST[1][13] = INST[0][162] ^ INST[0][115];\
INST[1][14] = INST[0][115] ^ INST[0][63];\
INST[1][15] = INST[0][63] ^ INST[0][68];\
INST[1][16] = INST[0][68] ^ INST[0][14];\
INST[1][17] = INST[0][14] ^ INST[0][143];\
INST[1][18] = INST[0][143] ^ INST[0][102];\
INST[1][19] = INST[0][102] ^ INST[0][126];\
INST[1][20] = INST[0][126] ^ INST[0][34];\
INST[1][21] = INST[0][34] ^ INST[0][153];\
INST[1][22] = INST[0][153] ^ INST[0][40];\
INST[1][23] = INST[0][40] ^ INST[0][24];\
INST[1][24] = INST[0][24] ^ INST[0][45];\
INST[1][25] = INST[0][45] ^ INST[0][27];\
INST[1][26] = INST[0][27] ^ INST[0][104];\
INST[1][27] = INST[0][104] ^ INST[0][131];\
INST[1][28] = INST[0][131] ^ INST[0][120];\
INST[1][29] = INST[0][120] ^ INST[0][72];\
INST[1][30] = INST[0][72] ^ INST[0][54];\
INST[1][31] = INST[0][54] ^ INST[0][0];\
INST[1][32] = INST[0][0] ^ INST[0][160];\
INST[1][33] = INST[0][160] ^ INST[0][112];\
INST[1][34] = INST[0][112] ^ INST[0][79];\
INST[1][35] = INST[0][79] ^ INST[0][64];\
INST[1][36] = INST[0][64] ^ INST[0][36];\
INST[1][37] = INST[0][36] ^ INST[0][77];\
INST[1][38] = INST[0][77] ^ INST[0][38];\
INST[1][39] = INST[0][38] ^ INST[0][127];\
INST[1][40] = INST[0][127] ^ INST[0][121];\
INST[1][41] = INST[0][121] ^ INST[0][17];\
INST[1][42] = INST[0][17] ^ INST[0][28];\
INST[1][43] = INST[0][28] ^ INST[0][52];\
INST[1][44] = INST[0][52] ^ INST[0][43];\
INST[1][45] = INST[0][43] ^ INST[0][86];\
INST[1][46] = INST[0][86] ^ INST[0][142];\
INST[1][47] = INST[0][142] ^ INST[0][37];\
INST[1][48] = INST[0][37] ^ INST[0][70];\
INST[1][49] = INST[0][70] ^ INST[0][99];\
INST[1][50] = INST[0][99] ^ INST[0][18];\
INST[1][51] = INST[0][18] ^ INST[0][113];\
INST[1][52] = INST[0][113] ^ INST[0][94];\
INST[1][53] = INST[0][94] ^ INST[0][154];\
INST[1][54] = INST[0][154] ^ INST[0][135];\
INST[1][55] = INST[0][135] ^ INST[0][88];\
INST[1][56] = INST[0][88] ^ INST[0][80];\
INST[1][57] = INST[0][80] ^ INST[0][141];\
INST[1][58] = INST[0][141] ^ INST[0][129];\
INST[1][59] = INST[0][129] ^ INST[0][33];\
INST[1][60] = INST[0][33] ^ INST[0][93];\
INST[1][61] = INST[0][93] ^ INST[0][108];\
INST[1][62] = INST[0][108] ^ INST[0][138];\
INST[1][63] = INST[0][138] ^ INST[0][65];\
INST[1][64] = INST[0][65] ^ INST[0][53];\
INST[1][65] = INST[0][53] ^ INST[0][26];\
INST[1][66] = INST[0][26] ^ INST[0][167];\
INST[1][67] = INST[0][167] ^ INST[0][107];\
INST[1][68] = INST[0][107] ^ INST[0][41];\
INST[1][69] = INST[0][41] ^ INST[0][159];\
INST[1][70] = INST[0][159] ^ INST[0][165];\
INST[1][71] = INST[0][165] ^ INST[0][62];\
INST[1][72] = INST[0][62] ^ INST[0][3];\
INST[1][73] = INST[0][3] ^ INST[0][39];\
INST[1][74] = INST[0][39] ^ INST[0][151];\
INST[1][75] = INST[0][151] ^ INST[0][74];\
INST[1][76] = INST[0][74] ^ INST[0][122];\
INST[1][77] = INST[0][122] ^ INST[0][146];\
INST[1][78] = INST[0][146] ^ INST[0][147];\
INST[1][79] = INST[0][147] ^ INST[0][55];\
INST[1][80] = INST[0][55] ^ INST[0][61];\
INST[1][81] = INST[0][61] ^ INST[0][42];\
INST[1][82] = INST[0][42] ^ INST[0][123];\
INST[1][83] = INST[0][123] ^ INST[0][8];\
INST[1][84] = INST[0][8] ^ INST[0][136];\
INST[1][85] = INST[0][136] ^ INST[0][109];\
INST[1][86] = INST[0][109] ^ INST[0][157];\
INST[1][87] = INST[0][157] ^ INST[0][13];\
INST[1][88] = INST[0][13] ^ INST[0][152];\
INST[1][89] = INST[0][152] ^ INST[0][49];\
INST[1][90] = INST[0][49] ^ INST[0][46];\
INST[1][91] = INST[0][46] ^ INST[0][98];\
INST[1][92] = INST[0][98] ^ INST[0][25];\
INST[1][93] = INST[0][25] ^ INST[0][84];\
INST[1][94] = INST[0][84] ^ INST[0][32];\
INST[1][95] = INST[0][32] ^ INST[0][95];\
INST[1][96] = INST[0][95] ^ INST[0][124];\
INST[1][97] = INST[0][124] ^ INST[0][5];\
INST[1][98] = INST[0][5] ^ INST[0][137];\
INST[1][99] = INST[0][137] ^ INST[0][58];\
INST[1][100] = INST[0][58] ^ INST[0][69];\
INST[1][101] = INST[0][69] ^ INST[0][103];\
INST[1][102] = INST[0][103] ^ INST[0][9];\
INST[1][103] = INST[0][9] ^ INST[0][117];\
INST[1][104] = INST[0][117] ^ INST[0][100];\
INST[1][105] = INST[0][100] ^ INST[0][76];\
INST[1][106] = INST[0][76] ^ INST[0][2];\
INST[1][107] = INST[0][2] ^ INST[0][22];\
INST[1][108] = INST[0][22] ^ INST[0][125];\
INST[1][109] = INST[0][125] ^ INST[0][105];\
INST[1][110] = INST[0][105] ^ INST[0][96];\
INST[1][111] = INST[0][96] ^ INST[0][133];\
INST[1][112] = INST[0][133] ^ INST[0][31];\
INST[1][113] = INST[0][31] ^ INST[0][81];\
INST[1][114] = INST[0][81] ^ INST[0][29];\
INST[1][115] = INST[0][29] ^ INST[0][156];\
INST[1][116] = INST[0][156] ^ INST[0][83];\
INST[1][117] = INST[0][83] ^ INST[0][4];\
INST[1][118] = INST[0][4] ^ INST[0][163];\
INST[1][119] = INST[0][163] ^ INST[0][19];\
INST[1][120] = INST[0][19] ^ INST[0][130];\
INST[1][121] = INST[0][130] ^ INST[0][10];\
INST[1][122] = INST[0][10] ^ INST[0][119];\
INST[1][123] = INST[0][119] ^ INST[0][11];\
INST[1][124] = INST[0][11] ^ INST[0][116];\
INST[1][125] = INST[0][116] ^ INST[0][7];\
INST[1][126] = INST[0][7] ^ INST[0][20];\
INST[1][127] = INST[0][20] ^ INST[0][73];\
INST[1][128] = INST[0][73] ^ INST[0][114];\
INST[1][129] = INST[0][114] ^ INST[0][85];\
INST[1][130] = INST[0][85] ^ INST[0][158];\
INST[1][131] = INST[0][158] ^ INST[0][92];\
INST[1][132] = INST[0][92] ^ INST[0][47];\
INST[1][133] = INST[0][47] ^ INST[0][71];\
INST[1][134] = INST[0][71] ^ INST[0][90];\
INST[1][135] = INST[0][90] ^ INST[0][128];\
INST[1][136] = INST[0][128] ^ INST[0][48];\
INST[1][137] = INST[0][48] ^ INST[0][140];\
INST[1][138] = INST[0][140] ^ INST[0][35];\
INST[1][139] = INST[0][35] ^ INST[0][155];\
INST[1][140] = INST[0][155] ^ INST[0][12];\
INST[1][141] = INST[0][12] ^ INST[0][23];\
INST[1][142] = INST[0][23] ^ INST[0][148];\
INST[1][143] = INST[0][148] ^ INST[0][82];\
INST[1][144] = INST[0][82] ^ INST[0][110];\
INST[1][145] = INST[0][110] ^ INST[0][78];\
INST[1][146] = INST[0][78] ^ INST[0][30];\
INST[1][147] = INST[0][30] ^ INST[0][97];\
INST[1][148] = INST[0][97] ^ INST[0][161];\
INST[1][149] = INST[0][161] ^ INST[0][145];\
INST[1][150] = INST[0][145] ^ INST[0][57];\
INST[1][151] = INST[0][57] ^ INST[0][21];\
INST[1][152] = INST[0][21] ^ INST[0][1];\
INST[1][153] = INST[0][1] ^ INST[0][67];\
INST[1][154] = INST[0][67] ^ INST[0][149];\
INST[1][155] = INST[0][149] ^ INST[0][111];\
INST[1][156] = INST[0][111] ^ INST[0][66];\
INST[1][157] = INST[0][66] ^ INST[0][6];\
INST[1][158] = INST[0][6] ^ INST[0][106];\
INST[1][159] = INST[0][106] ^ INST[0][91];\
INST[1][160] = INST[0][91] ^ INST[0][50];\
INST[1][161] = INST[0][50] ^ INST[0][87];\
INST[1][162] = INST[0][87] ^ INST[0][101];\
INST[1][163] = INST[0][101] ^ INST[0][16];\
INST[1][164] = INST[0][16] ^ INST[0][164];\
INST[1][165] = INST[0][164] ^ INST[0][15];\
INST[1][166] = INST[0][15] ^ INST[0][56];\
INST[1][167] = INST[0][56] ^ INST[0][44];\
}
#endif
#ifndef SBOX9_H
#define SBOX9_H
#define SBOX9(INST) {\
uint8_t N0;\
uint8_t N1;\
uint8_t N2;\
uint8_t N3;\
uint8_t N4;\
uint8_t N5;\
uint8_t N6;\
uint8_t N7;\
uint8_t N8;\
uint8_t N9;\
uint8_t N10;\
uint8_t N11;\
uint8_t N12;\
uint8_t N13;\
N0 = ~INST[1][131];\
N1 = N0 & INST[1][4];\
N2 = N0 & INST[1][39];\
N3 = N1 | N2;\
N4 = INST[1][4] & INST[1][39];\
N5 = INST[1][131] & INST[1][4];\
N6 = ~INST[1][39];\
N7 = N6 & INST[1][131];\
N8 = N5 | N7;\
N9 = N6 & INST[1][4];\
N10 = N0 & INST[1][4];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[1][4];\
INST[0][0]= N12 | N13;\
INST[0][1]= N8 | N9;\
INST[0][2]= N3 | N4;\
N0 = ~INST[1][61];\
N1 = N0 & INST[1][151];\
N2 = N0 & INST[1][166];\
N3 = N1 | N2;\
N4 = INST[1][151] & INST[1][166];\
N5 = INST[1][61] & INST[1][151];\
N6 = ~INST[1][166];\
N7 = N6 & INST[1][61];\
N8 = N5 | N7;\
N9 = N6 & INST[1][151];\
N10 = N0 & INST[1][151];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[1][151];\
INST[0][3]= N12 | N13;\
INST[0][4]= N8 | N9;\
INST[0][5]= N3 | N4;\
N0 = ~INST[1][89];\
N1 = N0 & INST[1][57];\
N2 = N0 & INST[1][98];\
N3 = N1 | N2;\
N4 = INST[1][57] & INST[1][98];\
N5 = INST[1][89] & INST[1][57];\
N6 = ~INST[1][98];\
N7 = N6 & INST[1][89];\
N8 = N5 | N7;\
N9 = N6 & INST[1][57];\
N10 = N0 & INST[1][57];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[1][57];\
INST[0][6]= N12 | N13;\
INST[0][7]= N8 | N9;\
INST[0][8]= N3 | N4;\
N0 = ~INST[1][154];\
N1 = N0 & INST[1][155];\
N2 = N0 & INST[1][17];\
N3 = N1 | N2;\
N4 = INST[1][155] & INST[1][17];\
N5 = INST[1][154] & INST[1][155];\
N6 = ~INST[1][17];\
N7 = N6 & INST[1][154];\
N8 = N5 | N7;\
N9 = N6 & INST[1][155];\
N10 = N0 & INST[1][155];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[1][155];\
INST[0][9]= N12 | N13;\
INST[0][10]= N8 | N9;\
INST[0][11]= N3 | N4;\
N0 = ~INST[1][21];\
N1 = N0 & INST[1][49];\
N2 = N0 & INST[1][73];\
N3 = N1 | N2;\
N4 = INST[1][49] & INST[1][73];\
N5 = INST[1][21] & INST[1][49];\
N6 = ~INST[1][73];\
N7 = N6 & INST[1][21];\
N8 = N5 | N7;\
N9 = N6 & INST[1][49];\
N10 = N0 & INST[1][49];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[1][49];\
INST[0][12]= N12 | N13;\
INST[0][13]= N8 | N9;\
INST[0][14]= N3 | N4;\
N0 = ~INST[1][110];\
N1 = N0 & INST[1][91];\
N2 = N0 & INST[1][45];\
N3 = N1 | N2;\
N4 = INST[1][91] & INST[1][45];\
N5 = INST[1][110] & INST[1][91];\
N6 = ~INST[1][45];\
N7 = N6 & INST[1][110];\
N8 = N5 | N7;\
N9 = N6 & INST[1][91];\
N10 = N0 & INST[1][91];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[1][91];\
INST[0][15]= N12 | N13;\
INST[0][16]= N8 | N9;\
INST[0][17]= N3 | N4;\
N0 = ~INST[1][60];\
N1 = N0 & INST[1][95];\
N2 = N0 & INST[1][113];\
N3 = N1 | N2;\
N4 = INST[1][95] & INST[1][113];\
N5 = INST[1][60] & INST[1][95];\
N6 = ~INST[1][113];\
N7 = N6 & INST[1][60];\
N8 = N5 | N7;\
N9 = N6 & INST[1][95];\
N10 = N0 & INST[1][95];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[1][95];\
INST[0][18]= N12 | N13;\
INST[0][19]= N8 | N9;\
INST[0][20]= N3 | N4;\
N0 = ~INST[1][125];\
N1 = N0 & INST[1][75];\
N2 = N0 & INST[1][143];\
N3 = N1 | N2;\
N4 = INST[1][75] & INST[1][143];\
N5 = INST[1][125] & INST[1][75];\
N6 = ~INST[1][143];\
N7 = N6 & INST[1][125];\
N8 = N5 | N7;\
N9 = N6 & INST[1][75];\
N10 = N0 & INST[1][75];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[1][75];\
INST[0][21]= N12 | N13;\
INST[0][22]= N8 | N9;\
INST[0][23]= N3 | N4;\
N0 = ~INST[1][28];\
N1 = N0 & INST[1][158];\
N2 = N0 & INST[1][100];\
N3 = N1 | N2;\
N4 = INST[1][158] & INST[1][100];\
N5 = INST[1][28] & INST[1][158];\
N6 = ~INST[1][100];\
N7 = N6 & INST[1][28];\
N8 = N5 | N7;\
N9 = N6 & INST[1][158];\
N10 = N0 & INST[1][158];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[1][158];\
INST[0][24]= N12 | N13;\
INST[0][25]= N8 | N9;\
INST[0][26]= N3 | N4;\
N0 = ~INST[1][2];\
N1 = N0 & INST[1][34];\
N2 = N0 & INST[1][120];\
N3 = N1 | N2;\
N4 = INST[1][34] & INST[1][120];\
N5 = INST[1][2] & INST[1][34];\
N6 = ~INST[1][120];\
N7 = N6 & INST[1][2];\
N8 = N5 | N7;\
N9 = N6 & INST[1][34];\
N10 = N0 & INST[1][34];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[1][34];\
INST[0][27]= N12 | N13;\
INST[0][28]= N8 | N9;\
INST[0][29]= N3 | N4;\
N0 = ~INST[1][5];\
N1 = N0 & INST[1][157];\
N2 = N0 & INST[1][52];\
N3 = N1 | N2;\
N4 = INST[1][157] & INST[1][52];\
N5 = INST[1][5] & INST[1][157];\
N6 = ~INST[1][52];\
N7 = N6 & INST[1][5];\
N8 = N5 | N7;\
N9 = N6 & INST[1][157];\
N10 = N0 & INST[1][157];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[1][157];\
INST[0][30]= N12 | N13;\
INST[0][31]= N8 | N9;\
INST[0][32]= N3 | N4;\
N0 = ~INST[1][56];\
N1 = N0 & INST[1][99];\
N2 = N0 & INST[1][32];\
N3 = N1 | N2;\
N4 = INST[1][99] & INST[1][32];\
N5 = INST[1][56] & INST[1][99];\
N6 = ~INST[1][32];\
N7 = N6 & INST[1][56];\
N8 = N5 | N7;\
N9 = N6 & INST[1][99];\
N10 = N0 & INST[1][99];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[1][99];\
INST[0][33]= N12 | N13;\
INST[0][34]= N8 | N9;\
INST[0][35]= N3 | N4;\
N0 = ~INST[1][106];\
N1 = N0 & INST[1][149];\
N2 = N0 & INST[1][26];\
N3 = N1 | N2;\
N4 = INST[1][149] & INST[1][26];\
N5 = INST[1][106] & INST[1][149];\
N6 = ~INST[1][26];\
N7 = N6 & INST[1][106];\
N8 = N5 | N7;\
N9 = N6 & INST[1][149];\
N10 = N0 & INST[1][149];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[1][149];\
INST[0][36]= N12 | N13;\
INST[0][37]= N8 | N9;\
INST[0][38]= N3 | N4;\
N0 = ~INST[1][138];\
N1 = N0 & INST[1][62];\
N2 = N0 & INST[1][127];\
N3 = N1 | N2;\
N4 = INST[1][62] & INST[1][127];\
N5 = INST[1][138] & INST[1][62];\
N6 = ~INST[1][127];\
N7 = N6 & INST[1][138];\
N8 = N5 | N7;\
N9 = N6 & INST[1][62];\
N10 = N0 & INST[1][62];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[1][62];\
INST[0][39]= N12 | N13;\
INST[0][40]= N8 | N9;\
INST[0][41]= N3 | N4;\
N0 = ~INST[1][80];\
N1 = N0 & INST[1][87];\
N2 = N0 & INST[1][47];\
N3 = N1 | N2;\
N4 = INST[1][87] & INST[1][47];\
N5 = INST[1][80] & INST[1][87];\
N6 = ~INST[1][47];\
N7 = N6 & INST[1][80];\
N8 = N5 | N7;\
N9 = N6 & INST[1][87];\
N10 = N0 & INST[1][87];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[1][87];\
INST[0][42]= N12 | N13;\
INST[0][43]= N8 | N9;\
INST[0][44]= N3 | N4;\
N0 = ~INST[1][147];\
N1 = N0 & INST[1][11];\
N2 = N0 & INST[1][68];\
N3 = N1 | N2;\
N4 = INST[1][11] & INST[1][68];\
N5 = INST[1][147] & INST[1][11];\
N6 = ~INST[1][68];\
N7 = N6 & INST[1][147];\
N8 = N5 | N7;\
N9 = N6 & INST[1][11];\
N10 = N0 & INST[1][11];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[1][11];\
INST[0][45]= N12 | N13;\
INST[0][46]= N8 | N9;\
INST[0][47]= N3 | N4;\
N0 = ~INST[1][55];\
N1 = N0 & INST[1][167];\
N2 = N0 & INST[1][83];\
N3 = N1 | N2;\
N4 = INST[1][167] & INST[1][83];\
N5 = INST[1][55] & INST[1][167];\
N6 = ~INST[1][83];\
N7 = N6 & INST[1][55];\
N8 = N5 | N7;\
N9 = N6 & INST[1][167];\
N10 = N0 & INST[1][167];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[1][167];\
INST[0][48]= N12 | N13;\
INST[0][49]= N8 | N9;\
INST[0][50]= N3 | N4;\
N0 = ~INST[1][8];\
N1 = N0 & INST[1][132];\
N2 = N0 & INST[1][104];\
N3 = N1 | N2;\
N4 = INST[1][132] & INST[1][104];\
N5 = INST[1][8] & INST[1][132];\
N6 = ~INST[1][104];\
N7 = N6 & INST[1][8];\
N8 = N5 | N7;\
N9 = N6 & INST[1][132];\
N10 = N0 & INST[1][132];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[1][132];\
INST[0][51]= N12 | N13;\
INST[0][52]= N8 | N9;\
INST[0][53]= N3 | N4;\
N0 = ~INST[1][148];\
N1 = N0 & INST[1][107];\
N2 = N0 & INST[1][109];\
N3 = N1 | N2;\
N4 = INST[1][107] & INST[1][109];\
N5 = INST[1][148] & INST[1][107];\
N6 = ~INST[1][109];\
N7 = N6 & INST[1][148];\
N8 = N5 | N7;\
N9 = N6 & INST[1][107];\
N10 = N0 & INST[1][107];\
N11 = N0 & N6;\
N12 = N10 | N11;\
N13 = N6 & INST[1][107];\
INST[0][54]= N12 | N13;\
INST[0][55]= N8 | N9;\
INST[0][56]= N3 | N4;\
INST[0][57]= ((~INST[1][31] & INST[1][97]) | (~INST[1][31] & ~INST[1][15])) | (~INST[1][15] & INST[1][97]);\
INST[0][58]= ((INST[1][31] & INST[1][97]) | (~INST[1][15] & INST[1][31])) | (~INST[1][15] & INST[1][97]);\
INST[0][59]= ((~INST[1][31] & INST[1][97]) | (~INST[1][31] & INST[1][15])) | (INST[1][97] & INST[1][15]);\
\
INST[0][60]= ((~INST[1][115] & INST[1][105]) | (~INST[1][115] & ~INST[1][54])) | (~INST[1][54] & INST[1][105]);\
INST[0][61]= ((INST[1][115] & INST[1][105]) | (~INST[1][54] & INST[1][115])) | (~INST[1][54] & INST[1][105]);\
INST[0][62]= ((~INST[1][115] & INST[1][105]) | (~INST[1][115] & INST[1][54])) | (INST[1][105] & INST[1][54]);\
\
INST[0][63]= ((~INST[1][114] & INST[1][18]) | (~INST[1][114] & ~INST[1][16])) | (~INST[1][16] & INST[1][18]);\
INST[0][64]= ((INST[1][114] & INST[1][18]) | (~INST[1][16] & INST[1][114])) | (~INST[1][16] & INST[1][18]);\
INST[0][65]= ((~INST[1][114] & INST[1][18]) | (~INST[1][114] & INST[1][16])) | (INST[1][18] & INST[1][16]);\
}
#endif
#ifndef FUN_SEL_H
#define FUN_SEL_H
const uint8_t fun_sel[32][11] = {\
{25, 43, 15, 6, 36, 2, 28, 18, 34, 33, 35},\
{4, 10, 3, 8, 14, 39, 26, 19, 9, 22, 42},\
{32, 16, 23, 41, 31, 30, 29, 27, 17, 38, 20},\
{13, 0, 40, 7, 37, 12, 11, 1, 5, 21, 24},\
{9, 3, 5, 42, 8, 23, 30, 1, 6, 36, 31},\
{33, 39, 37, 35, 16, 7, 38, 4, 26, 25, 13},\
{21, 29, 2, 19, 18, 22, 10, 11, 40, 17, 12},\
{32, 15, 41, 24, 27, 0, 43, 14, 34, 20, 28},\
{21, 16, 15, 33, 19, 24, 23, 25, 6, 28, 11},\
{20, 12, 37, 9, 41, 18, 5, 22, 38, 42, 3},\
{27, 4, 32, 14, 30, 36, 2, 8, 35, 13, 43},\
{17, 0, 1, 39, 40, 31, 10, 29, 34, 7, 26},\
{34, 32, 42, 26, 33, 18, 37, 19, 30, 10, 21},\
{2, 38, 23, 29, 41, 24, 28, 12, 0, 16, 6},\
{5, 4, 35, 31, 8, 14, 27, 1, 20, 25, 36},\
{15, 13, 17, 7, 3, 9, 39, 40, 11, 22, 43},\
{28, 23, 21, 2, 29, 33, 7, 5, 25, 20, 27},\
{1, 32, 4, 22, 34, 16, 17, 14, 40, 31, 37},\
{6, 11, 10, 26, 18, 42, 36, 30, 0, 19, 8},\
{3, 24, 41, 35, 43, 13, 39, 12, 15, 9, 38},\
{5, 33, 3, 30, 17, 18, 11, 2, 10, 43, 19},\
{1, 20, 14, 16, 40, 31, 38, 23, 8, 28, 34},\
{7, 41, 35, 39, 36, 0, 22, 27, 12, 15, 9},\
{26, 25, 21, 6, 32, 4, 24, 13, 42, 37, 29},\
{26, 39, 11, 21, 8, 43, 9, 40, 17, 7, 1},\
{6, 24, 37, 33, 2, 42, 41, 20, 12, 25, 34},\
{10, 35, 19, 30, 28, 31, 4, 32, 5, 3, 22},\
{13, 18, 23, 15, 16, 0, 14, 36, 38, 27, 29},\
{6, 5, 3, 26, 12, 7, 28, 21, 14, 25, 36},\
{24, 8, 41, 30, 2, 9, 11, 42, 31, 13, 0},\
{35, 16, 43, 33, 22, 37, 27, 20, 23, 17, 18},\
{1, 38, 10, 19, 40, 4, 34, 32, 15, 39, 29},\
};
#endif
#define HASH_KEY_WIDTH 160
#define HASH_SEED_WIDTH 8
#define HASH_KEY_SIZE (HASH_KEY_WIDTH + HASH_SEED_WIDTH)
#define HASH_KEY_WORDS ((HASH_KEY_SIZE + 31) / 32) 
#define HASH_SLICES ((CAM_MAX_KEY_WIDTH + HASH_KEY_WIDTH - 1) / HASH_KEY_WIDTH)
struct hash_t {
uint32_t key[HASH_SLICES][HASH_KEY_WORDS];
uint8_t slices;
uint8_t bs[2][HASH_KEY_SIZE];
bool slice_calculated;
uint8_t log2_physical_lists;
uint8_t log2_physical_buckets;
};
size_t hash_size(void)
{
return sizeof(hash_t);
}
void hash_raw_init(hash_t *hash, const aaaaaaaaaaaaa1aaat *key, uint16_t seed, uint16_t key_width,
uint32_t num_lists, uint8_t num_slots)
{
const uint8_t hash_slices = (key_width + HASH_KEY_WIDTH - 1) / HASH_KEY_WIDTH;
hash->slices = hash_slices;
for (int i = 0; i < key_width / HASH_KEY_WIDTH; i++) {
memcpy(&hash->key[i], &key->word[i * HASH_KEY_WIDTH / 32], HASH_KEY_WIDTH / 8);
hash->key[i][HASH_KEY_WORDS - 1] = seed & 0xff;
}
for (int i = key_width / HASH_KEY_WIDTH; i < hash_slices; i++) {
memset(&hash->key[i], 0, HASH_KEY_WIDTH / 8);
memcpy(&hash->key[i], &key->word[i * HASH_KEY_WIDTH / 32], (key_width - i * HASH_KEY_WIDTH + 7) / 8);
hash->key[i][HASH_KEY_WORDS - 1] = seed & 0xff;
}
hash->slice_calculated = false;
const uint32_t num_buckets = aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO * num_lists;
const uint32_t physical_lists = num_slots * num_lists;
const uint32_t physical_buckets = num_slots * num_buckets;
hash->log2_physical_lists = CLOG2(physical_lists);
hash->log2_physical_buckets = CLOG2(physical_buckets);
}
void aaaaaaa1aaa(hash_t *hash, const aaaaaaaaaaaaa1aaat *key, const aaa1aaat *phm)
{
const uint16_t seed = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaseed(phm);
const client_t *client = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaclient(phm);
const uint16_t key_width = client_get_key_width(client);
const uint32_t num_lists = client_get_num_lists(client);
const uint8_t num_slots = client_get_num_slots(client);
hash_raw_init(hash, key, seed, key_width, num_lists, num_slots);
}
static void calc_bit_slice(hash_t *hash, uint8_t slice)
{
const uint8_t sbox3x2[64] = { 9, 12, 15, 13, 10, 8, 11, 14, 33, 36, 39, 37, 34, 32, 35, 38, 57, 60, 63, 61, 58, 56,
59, 62, 41, 44, 47, 45, 42, 40, 43, 46, 17, 20, 23, 21, 18, 16, 19, 22, 1, 4, 7, 5, 2, 0, 3, 6, 25, 28, 31,
29, 26, 24, 27, 30, 49, 52, 55, 53, 50, 48, 51, 54 };
uint32_t *key = hash->key[slice];
uint16_t bit_counter = 0;
while (bit_counter < HASH_KEY_SIZE) {
const uint16_t word_pos = bit_counter / 32;
const uint16_t bit_pos = bit_counter - word_pos * 32;
uint8_t sbox_value;
if (bit_pos <= (32 - 6)) {
sbox_value = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(key[word_pos], bit_pos, 6);
} else {
assert(word_pos < 10);
const uint8_t sbox_value_lo = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(key[word_pos], bit_pos, 32 - bit_pos);
const uint8_t sbox_value_hi = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(key[word_pos + 1], 0, 6 - (32 - bit_pos));
sbox_value = (sbox_value_hi << (32 - bit_pos)) + sbox_value_lo;
assert(sbox_value < 64);
}
const uint8_t sbox_result = sbox3x2[sbox_value];
for (uint8_t j = 0; j < 6; j++) {
hash->bs[0][bit_counter + j] = (sbox_result >> (j)) & 1;
}
bit_counter = bit_counter + 6;
}
XOR0(hash->bs);
XOR1(hash->bs);
XOR2(hash->bs);
XOR3(hash->bs);
SBOX4(hash->bs);
XOR5(hash->bs);
XOR6(hash->bs);
XOR7(hash->bs);
XOR8(hash->bs);
SBOX9(hash->bs);
}
static void calculate_bit_slice(hash_t *hash)
{
assert(!hash->slice_calculated);
uint8_t xor_hash[HASH_KEY_SIZE] = { 0 };
for (int slice = 0; slice < hash->slices; slice++) {
calc_bit_slice(hash, slice);
if (hash->slices == 1) {
break;
}
for (uint16_t i = 0; i < HASH_KEY_SIZE; i++) {
xor_hash[i] ^= hash->bs[0][i];
}
}
if (hash->slices > 1) {
for (uint16_t i = 0; i < HASH_KEY_SIZE; i++) {
hash->bs[0][i] = xor_hash[i];
}
}
hash->slice_calculated = true;
}
uint32_t hash_calculate_list(hash_t *hash, uint8_t function)
{
assert(function < aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaS);
assert(hash != NULL);
if (!hash->slice_calculated) {
calculate_bit_slice(hash);
}
uint32_t list = 0;
for (uint8_t i = 0; i < hash->log2_physical_lists; i++) {
list = list << 1;
uint8_t fixed_function = function;
uint8_t fixed_log2_list = i;
if (i >= 11) {
if (function == 0)
fixed_function = 1;
else
fixed_function = function - 1;
fixed_log2_list = i - 11;
}
assert(fixed_log2_list < 11);
const uint16_t bit = fun_sel[fixed_function][fixed_log2_list] + hash->log2_physical_buckets;
list = list | (hash->bs[0][bit] & 1);
}
return list;
}
uint64_t hash_calculate(hash_t *hash, unsigned width)
{
assert(hash != NULL);
if (!hash->slice_calculated) {
calculate_bit_slice(hash);
}
uint32_t result[2] = { 0, 0 };
for (uint8_t bit = 0; bit < width; bit++) {
unsigned word = bit / 32;
uint8_t bit_within_word = bit - (word * 32);
result[word] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa(result[word], hash->bs[0][bit], bit_within_word, 1);
}
return (((uint64_t)result[1]) << 32) | result[0];
}
uint32_t hash_calculate_bucket(hash_t *hash)
{
return hash_calculate(hash, hash->log2_physical_buckets);
}
#define aaaaaaaaaaaaaaaaaaaaaaaa1aaaER_MAX 31
#define aaaaaaaaaaaaaaaaaaaaaaaa1aaaER_WIDTH 5
#define aaaaaaaaaaaaaaaaaaaaaaaa1aaaER_MASK 0xf400
#define VALUE_MASK 0x07ff
#define VALUE_MAX 2046
#define VALUE_UNKNOWN 2047
struct htable_t
{
uint16_t *entries;
uint8_t width;
uint32_t size;
};
size_t htable_size(void)
{
return sizeof(htable_t);
}
void htable_free(htable_t *htable, cam_free_func free_function)
{
if (htable == NULL)
return;
if (htable->entries != NULL)
{
free_function(htable->entries);
}
free_function(htable);
}
void htable_num_entries_to_num_buckets(uint32_t num_entries,
uint32_t *num_buckets, uint8_t *log2_num_buckets) {
uint8_t i;
for (i = 1; i < 32; i++) {
if (((num_entries - 1) >> i) == 0) {
break;
}
}
assert(i < 30);
*log2_num_buckets = i + 2; 
*num_buckets = 1 << (*log2_num_buckets);
}
bool htable_init(htable_t *htable, uint32_t num_entries,
cam_calloc_func calloc_function)
{
assert(VALUE_MAX >= (aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaS - 1));
htable_num_entries_to_num_buckets(num_entries, &htable->size,
&htable->width);
htable->entries = calloc_function(htable->size, sizeof(uint16_t));
if (htable->entries == NULL)
{
return false;
}
return true;
}
void htable_clear(htable_t *htable) {
memset(htable->entries, 0, htable->size * sizeof(uint16_t));
}
void htable_inc(htable_t *htable, uint64_t hash_value)
{
assert(htable != NULL);
uint64_t cut_hash_value = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa64(hash_value, 0, htable->width);
assert(cut_hash_value < htable->size);
uint16_t entry = htable->entries[cut_hash_value];
uint16_t count = entry >> (16-aaaaaaaaaaaaaaaaaaaaaaaa1aaaER_WIDTH);
if (count < aaaaaaaaaaaaaaaaaaaaaaaa1aaaER_MAX)
{
count++;
count = count << (16-aaaaaaaaaaaaaaaaaaaaaaaa1aaaER_WIDTH);
entry = (entry & VALUE_MASK) | count;
htable->entries[cut_hash_value] = entry;
}
}
void htable_write(struct htable_t *htable, uint64_t hash_value, uint16_t value)
{
assert(htable != NULL);
assert((value <= VALUE_MAX) || (value == VALUE_UNKNOWN));
uint8_t old_counter;
uint16_t old_value;
bool value_unknown;
htable_read(htable, hash_value, &old_counter, &old_value, &value_unknown);
assert(old_counter > 0);
const uint16_t entry = (old_counter << (16 - aaaaaaaaaaaaaaaaaaaaaaaa1aaaER_WIDTH)) + value;
uint64_t cut_hash_value = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa64(hash_value, 0, htable->width);
assert(cut_hash_value < htable->size);
htable->entries[cut_hash_value] = entry;
}
void htable_read(const struct htable_t *htable, uint64_t hash_value, uint8_t *counter, uint16_t *value,
bool *value_unknown)
{
assert(htable != NULL);
uint64_t cut_hash_value = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa64(hash_value, 0, htable->width);
assert(cut_hash_value < htable->size);
const uint16_t entry = htable->entries[cut_hash_value];
*value_unknown = true;
*counter = entry >> (16 - aaaaaaaaaaaaaaaaaaaaaaaa1aaaER_WIDTH);
*value = entry & VALUE_MASK;
if (*counter > 0 && *value != VALUE_UNKNOWN) {
*value_unknown = false;
}
}
static void dec(htable_t *htable, uint64_t hash_value)
{
assert(htable != NULL);
uint64_t cut_hash_value = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa64(hash_value, 0, htable->width);
assert(cut_hash_value < htable->size);
assert(cut_hash_value < htable->size);
uint16_t entry = htable->entries[cut_hash_value];
uint16_t count = entry >> (16-aaaaaaaaaaaaaaaaaaaaaaaa1aaaER_WIDTH);
assert(count > 0);
if (count < aaaaaaaaaaaaaaaaaaaaaaaa1aaaER_MAX)
{
count--;
count = count << (16-aaaaaaaaaaaaaaaaaaaaaaaa1aaaER_WIDTH);
entry = (entry & VALUE_MASK) | count;
htable->entries[cut_hash_value] = entry;
}
}
void htable_dec(htable_t *htable, uint64_t hash_value, uint16_t value)
{
uint8_t old_counter;
uint16_t old_value;
bool value_unknown;
assert((value <= VALUE_MAX) || (value == VALUE_UNKNOWN));
htable_read(htable, hash_value, &old_counter, &old_value, &value_unknown);
if (old_counter > 1) {
if ((old_value == value) && !value_unknown) {
htable_write(htable, hash_value, VALUE_UNKNOWN);
}
}
dec(htable, hash_value);
}
void htable_calc_stats(htable_t *htable, uint32_t *size, uint32_t *zeroes, uint32_t *ones, uint32_t *twoplussum,
uint32_t *onetwoeightplus, uint32_t *sumfirsthalf)
{
uint32_t counts[5] = { 0, 0, 0, 0, 0 };
for (uint32_t i = 0; i < htable->size; i++)
{
uint8_t counter;
uint16_t value;
bool value_unknown;
htable_read(htable, i, &counter, &value, &value_unknown);
if (counter == 0)
{
counts[0]++;
}
else if (counter == 1) {
counts[1]++;
}
else
{
counts[2] = counts[2] + counter;
if (counter >= 128)
counts[3]++;
}
if ((i < htable->size / 2) && (counter > 0))
counts[4] = counts[4] + counter;
}
*size = htable->size;
*zeroes = counts[0];
*ones = counts[1];
*twoplussum = counts[2];
*onetwoeightplus = counts[3];
*sumfirsthalf = counts[4];
}
size_t aaaa1aaasource_bucket_size(void) {
return sizeof(source_bucket_t);
}
size_t aaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa(void)
{
return sizeof(aaaa1aaat);
}
static uint16_t get_key_size(const aaaa1aaat *km)
{
const uint16_t key_width = client_get_key_width(km->client);
if (client_is_tcam(km->client)) {
return 2 * key_width; 
} 
return key_width; 
}
static uint8_t calc_write_mask(const client_t * client, uint8_t narrow,
uint8_t narrow_element, bool wide2narrow){
const uint16_t list_length = client_get_list_length(client);
assert((list_length == 1024) || (list_length == 512));
uint8_t write_mask = 0;
if (list_length == 1024) {
write_mask = 0xf;
if (narrow && !wide2narrow) {
if (narrow_element == 0)
write_mask = 3;
else
write_mask = 12;
}
} else { 
write_mask = 3;
if (narrow && !wide2narrow) {
if (narrow_element == 0)
write_mask = 1;
else
write_mask = 2;
}
}
assert(write_mask != 0);
return write_mask;
}
#define DRAM_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaTABLE_POS (24)
static void flush_drambcam_km(aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, int *verify,
operation_t operation, uint8_t narrow,
uint8_t narrow_element, bool bit511or255, bool wide2narrow)
{
assert((operation != DELETE) || (((operation == DELETE) && bit511or255) || !bit511or255));
assert(!wide2narrow || (wide2narrow && (narrow != 0)));
const uint32_t num_lists = client_get_num_lists(km->client);
assert(aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa < num_lists);
const uint16_t list_length = client_get_list_length(km->client);
const uint16_t number_of_word32s = list_length / 32;
const uint16_t segment = client_get_segment(km->client);
assert(segment < CAM_MAX_VC_SEGMENTS);
const uint32_t start_word32 = aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa * number_of_word32s;
const uint8_t write_mask = calc_write_mask(km->client, narrow, narrow_element, wide2narrow);
const uint32_t address = (km->unit << DRAM_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaTABLE_POS)
+ aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa
+ segment * num_lists;
client_start_serialize(km->client);
if (verify == NULL) {
client_drambaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(km->client, address, &km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[start_word32], write_mask,
operation, bit511or255, km->fingerprint[aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa]);
} else {
*verify = 0;
char message[256];
uint32_t read_data[32];
client_drambaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaread(km->client, address, &read_data[0]);
uint8_t slice_shift = write_mask;
const uint16_t bank_width = client_get_channel_width(km->client);
if (bank_width == 512) {
if ((slice_shift & 3) > 0)
slice_shift = slice_shift | 3;
if ((slice_shift & 12) > 0)
slice_shift = slice_shift | 12;
}
for (uint8_t slice = 0; slice < 4; slice++) {
if ((slice_shift & 1) == 0) {
slice_shift = slice_shift >> 1;
continue;
}
slice_shift = slice_shift >> 1;
for (uint8_t j = 0; j < 8; j++) {
const uint8_t idx = slice * 8 + j;
const uint32_t data = km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[start_word32 + idx];
if (read_data[idx] != data) {
sprintf(message,
                       "CAM_DEBUG_VERIFY_SHADOW  address = 0x%08" PRIx32 "  data %x= 0x%08" PRIx32 " expected data %x= 0x%08" PRIx32 "     FAIL",
address, idx, read_data[idx], idx, data);
client_print_error(km->client, message);
*verify = CAM_ERROR_FOUND_IN_SHADOW_BUT_NOT_IN_HW;
} else if (client_get_debug_flags(
km->client) & CAM_DEBUG_VERBOSE_VERIFY) {
sprintf(message,
                       "CAM_DEBUG_VERIFY_SHADOW  address = 0x%08" PRIx32 "  data %x= 0x%08" PRIx32 " expected data %x= 0x%08" PRIx32 "     OK",
address, idx, read_data[idx], idx, data);
client_print_info(km->client, message);
}
}
}
}
client_end_serialize(km->client);
}
void flush(aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, bool init_clear,
int *verify, operation_t operation,
uint8_t narrow,
uint8_t narrow_element, bool bit511or255, bool wide2narrow)
{
if (client_is_drambcam(km->client)) {
flush_drambcam_km(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, verify, operation, narrow, narrow_element, bit511or255, wide2narrow);
return;
}
const uint32_t num_lists = client_get_num_lists(km->client);
assert(aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa < num_lists);
const uint16_t list_length = client_get_list_length(km->client);
const uint16_t number_of_word32s = list_length / 32;
assert(number_of_word32s >= 2);
const uint32_t list_start_word32 = aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa * number_of_word32s;
assert(km->slot_number < aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaS);
const uint32_t adj_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = num_lists * km->slot_number + aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa;
assert(adj_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa < (num_lists * client_get_num_slots(km->client)));
const uint32_t ram_size = client_get_ram_size(km->client);
const uint16_t segment = client_get_segment(km->client);
assert (!(ram_size == 0 && segment > 0));
assert((adj_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa < ram_size) || (ram_size == 0));
assert(segment < CAM_MAX_VC_SEGMENTS);
const uint32_t base = aaaaaa1aaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa + km->unit * aaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa + adj_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa * aaaaaa1aaaaaaa1aaaWORD +
segment * ram_size * aaaaaa1aaaaaaa1aaaWORD;
uint16_t start_word = 0;
if (!init_clear && (km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[list_start_word32 + number_of_word32s - 1] & 0x80000000) == 0) {
start_word = number_of_word32s - 2;
}
uint32_t debug_flags = client_get_debug_flags(km->client);
uint8_t num_rw_passes;
if (verify != NULL) {
num_rw_passes = 1;
} else if (verify == NULL && !(debug_flags & CAM_DEBUG_VERIFY_WR)) {
num_rw_passes = 1;
} else {
num_rw_passes = 2;
}
client_start_serialize(km->client);
for (uint8_t rw_pass = 0; rw_pass < num_rw_passes; rw_pass++) {
if (num_rw_passes == 2) {
if (rw_pass == 0){
client_set_debug_flags(km->client, debug_flags & (CAM_DEBUG_VERIFY_WR ^ UINT32_MAX));
} else {
client_set_debug_flags(km->client, debug_flags);
}
}
for (uint16_t word_count = start_word; word_count < number_of_word32s; word_count += 2) {
uint64_t data;
data = km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[list_start_word32 + word_count + 1];
data = data << 32;
data |= km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[list_start_word32 + word_count];
if (rw_pass == 0 && verify == NULL) {
client_hw_write(km->client, base + word_count * 4, data);
} else {
if (verify != NULL) {
*verify = 0; 
}
uint64_t hw_word;
client_hw_read(km->client, base + word_count * 4, &hw_word);
char message[500];
               const char *flag_str[2] = {"CAM_DEBUG_VERIFY_SHADOW", "CAM_DEBUG_VERIFY_WR    "};
               const char *reference_str[2] = {"  shadow", "expected"};
uint8_t str_index = verify != NULL ? 0 : 1;
if (hw_word != data) {
sprintf(message,
                           "%s  address = 0x%08" PRIx32 "  data = 0x%016" PRIx64 "  %s data = 0x%016" PRIx64 "     FAIL",
flag_str[str_index], base + word_count * 4, hw_word, reference_str[str_index], data);
client_print_error(km->client, message);
if (verify != NULL) {
*verify = CAM_ERROR_FOUND_IN_SHADOW_BUT_NOT_IN_HW;
}
} else if (client_get_debug_flags(km->client) & CAM_DEBUG_VERBOSE_VERIFY) {
sprintf(message,
                           "%s  address = 0x%08" PRIx32 "  data = 0x%016" PRIx64 "  %s data = 0x%016" PRIx64 "     OK",
flag_str[str_index], base + word_count * 4, hw_word, reference_str[str_index], data);
client_print_info(km->client, message);
}
}
}
}
client_end_serialize(km->client);
}
bool aaaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(aaaa1aaat *km, client_t *client, uint16_t unit, uint8_t slot_number, bool flush_to_hw)
{
assert(unit < aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaS);
const uint32_t num_lists = client_get_num_lists(client);
const uint16_t list_length = client_get_list_length(client);
cam_free_func free_function = client_get_free_function(client);
cam_calloc_func calloc_function = client_get_calloc_function(client);
cam_posix_memalign_func posix_memalign_function = client_get_posix_memalign_function(client);
assert(list_length >= 32);
assert((list_length - (list_length / 32 * 32)) == 0);
if (posix_memalign_function == NULL) {
km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata = calloc_function(num_lists, sizeof(uint32_t) * list_length / 32);
if (km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata == NULL)
return false;
km->fingerprint = calloc_function(num_lists, sizeof *km->fingerprint);
if (km->fingerprint == NULL) {
free_function(km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata);
return false;
}
} else {
int rc = posix_memalign_function((void **) &km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata, 64,
num_lists * sizeof(uint32_t) * list_length / 32);
if (rc) {
return false;
}
rc = posix_memalign_function((void **) &km->fingerprint,
64, num_lists * sizeof *km->fingerprint);
if(rc) {
free_function(km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata);
return false;
}
memset(km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata, 0, num_lists * sizeof(uint32_t) * list_length / 32);
}
uint8_t bits_per_list = 1;
if (client_is_mixed_mode(client)) {
bits_per_list = 4;
assert(!client_is_tcam(client));
}
km->valid_cache = calloc_function((bits_per_list * num_lists + 31) / 32, sizeof(uint32_t));
if (km->valid_cache == NULL) {
free_function(km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata);
free_function(km->fingerprint);
return false;
}
km->source_bucket = NULL;
if (client_is_tcam(client)) {
km->source_bucket = calloc_function(num_lists, sizeof(source_bucket_t));
if (km->source_bucket == NULL) {
free_function(km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata);
free_function(km->valid_cache);
free_function(km->fingerprint);
return false;
}
}
km->flush = flush_to_hw;
km->unit = unit;
km->client = client;
km->slot_number = slot_number;
const uint32_t end_list = num_lists - 1;
for (uint32_t i = 0; i <= end_list; i++) {
if (!(client_get_debug_flags(km->client) & CAM_DEBUG_SKIP_MEM_INIT)) {
flush(km, i, true, false, OTHER, 0, 0, false, false);
}
}
return true;
}
void aaaa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(aaaa1aaat *km, cam_free_func free_function)
{
if (km == NULL) {
return;
}
if (km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata != NULL) {
free_function(km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata);
}
if (km->fingerprint != NULL) {
free_function(km->fingerprint);
}
if (km->source_bucket != NULL) {
free_function(km->source_bucket);
}
if (km->valid_cache != NULL) {
free_function(km->valid_cache);
}
free_function(km);
}
void aaaa1bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbb4aaa(aaaa1aaat *km)
{
km->flush = true;
}
void aaaa1bbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbb4aaa(aaaa1aaat *km)
{
km->flush = false;
}
void set_valid_bit(const aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, uint32_t valid)
{
assert(!client_is_mixed_mode(km->client));
assert(aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa < client_get_num_lists(km->client));
assert(valid < 2);
uint8_t g = 0;
if (client_get_generation_number_granularity(km->client))
g = 1;
const uint16_t list_length = client_get_list_length(km->client);
const uint8_t number_of_word32s = list_length / 32;
const uint32_t word32 = aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa * number_of_word32s;
km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[word32 + number_of_word32s - 1] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa(
km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[word32 + number_of_word32s - 1], valid, 31 - g, 1);
const uint32_t valid_entry = aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa / 32;
const uint32_t start = aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa - valid_entry * 32;
km->valid_cache[valid_entry] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa(km->valid_cache[valid_entry], valid, start, 1);
}
void aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaabits(const aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, bool *wide_valid, bool *narrow1_valid,
bool *narrow0_valid)
{
assert(client_is_mixed_mode(km->client));
assert(!client_is_tcam(km->client));
assert(aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa < client_get_num_lists(km->client));
*wide_valid = false;
*narrow1_valid = false;
*narrow0_valid = false;
const uint32_t valid_entry = aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa / (32 / 4);
const uint32_t start = aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa - valid_entry * (32 / 4);
const uint8_t status = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(km->valid_cache[valid_entry], start * 4 + 1, 3);
assert (status != 6);
assert(status != 7);
if ((status & 6) == 2) {
*wide_valid = true;
return;
}
if ((status & 6) == 4) {
*narrow1_valid = true;
}
if ((status & 1) == 1) {
*narrow0_valid = true;
}
}
void set_control_bits(const aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, uint8_t valid,
uint8_t narrow,
uint8_t narrow_element)
{
assert(!client_is_tcam(km->client));
assert(aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa < client_get_num_lists(km->client));
assert(valid < 2);
assert(narrow < 2);
assert(narrow_element < 2);
if (!client_is_mixed_mode(km->client)) {
set_valid_bit(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, valid);
return;
}
const uint16_t list_length = client_get_list_length(km->client);
const uint8_t number_of_word32s = list_length / 32;
const uint32_t word32 = aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa * number_of_word32s;
const uint32_t valid_entry = aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa / (32 / 4); 
const uint32_t start = aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa - valid_entry * (32 / 4); 
uint8_t g = 0;
if (client_get_generation_number_granularity(km->client))
g = 1;
if (narrow && (narrow_element == 0)) {
assert(2 != aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(km->valid_cache[valid_entry], start * 4 + 1, 3));
km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[word32 + number_of_word32s / 2 - 1] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa(
km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[word32 + number_of_word32s / 2 - 1], valid, 31 - g, 1);
km->valid_cache[valid_entry] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa(km->valid_cache[valid_entry], valid, start * 4 + 1, 1);
} else if (narrow && (narrow_element == 1)) {
assert(2 != aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(km->valid_cache[valid_entry], start * 4 + 1, 3));
km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[word32 + number_of_word32s - 1] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa(
km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[word32 + number_of_word32s - 1], valid << 1, 30 - g, 2);
km->valid_cache[valid_entry] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa(km->valid_cache[valid_entry], valid << 1, start * 4 + 2, 2);
} else if (!narrow) {
if (valid) {
km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[word32 + number_of_word32s - 1] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa(
km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[word32 + number_of_word32s - 1], 1, 30 - g, 2);
km->valid_cache[valid_entry] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa(km->valid_cache[valid_entry], 1, start * 4 + 2, 2);
} else {
km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[word32 + number_of_word32s - 1] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa(
km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[word32 + number_of_word32s - 1], 0, 30 - g, 2);
km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[word32 + number_of_word32s / 2 - 1] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa(
km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[word32 + number_of_word32s / 2 - 1], 0, 31 - g, 1);
km->valid_cache[valid_entry] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa(km->valid_cache[valid_entry], 0, start * 4 + 1, 3);
}
}
}
static bool get_bit511or255(const aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa)
{
assert(client_is_mixed_mode(km->client));
assert(!client_is_tcam(km->client));
assert(aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa < client_get_num_lists(km->client));
uint8_t g = 0;
if (client_get_generation_number_granularity(km->client)) {
g = 1;
}
const uint16_t list_length = client_get_list_length(km->client);
const uint8_t number_of_word32s = list_length / 32;
const uint32_t word32 = aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa * number_of_word32s;
uint32_t bit511or255 = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[word32 + number_of_word32s / 2 - 1], 31 - g, 1);
if (bit511or255)
return true;
return false;
}
void write_field_with_gen_number(uint32_t *target, uint16_t target_start_pos_w_gen_num,
uint16_t source_width_wo_gen_num, uint32_t * source, 
uint16_t target_pos_limit_w_gen_num, uint16_t granularity)
{
assert(source_width_wo_gen_num);
uint16_t distance = granularity
- (target_start_pos_w_gen_num - (target_start_pos_w_gen_num / granularity) * granularity) - 1;
if (distance > source_width_wo_gen_num)
distance = source_width_wo_gen_num;
uint16_t write_pos = target_start_pos_w_gen_num;
uint16_t consumed_bits = 0;
bool break_out = false;
uint32_t temp[(CAM_MAX_GEN_NUMBER_GRANULARITY + 31) / 32];
while(1) {
if ((consumed_bits + distance) >= source_width_wo_gen_num) {
distance = source_width_wo_gen_num - consumed_bits;
break_out = true;
}
cam_read_field(source, consumed_bits, consumed_bits + distance - 1, temp);
cam_write_field(target, write_pos, write_pos + distance - 1, temp, target_pos_limit_w_gen_num);
if (break_out)
break;
write_pos = write_pos + distance + 1;
consumed_bits = consumed_bits + distance;
distance = granularity - (write_pos - (write_pos / granularity) * granularity) - 1;
}
}
static void write_only_gen_number(uint32_t *target, uint16_t start_pos_w_gen_num, uint16_t end_pos_w_gen_num,
uint16_t pos_limit_w_gen_num, uint8_t generation_number, uint16_t granularity) {
assert(start_pos_w_gen_num <= end_pos_w_gen_num);
uint16_t distance = granularity - (start_pos_w_gen_num - (start_pos_w_gen_num / granularity) * granularity) - 1;
uint16_t write_pos = start_pos_w_gen_num;
while (1) {
if ((write_pos + distance) > end_pos_w_gen_num) {
break;
}
const uint32_t gen_num = generation_number;
cam_write_field(target, write_pos + distance, write_pos + distance, (uint32_t *) &gen_num, pos_limit_w_gen_num);
write_pos = write_pos + distance + 1;
distance = granularity - (write_pos - (write_pos / granularity) * granularity) - 1;
}
}
uint16_t calc_start_pos_gen_number(uint16_t width_wo_gen_num, uint16_t end_pos_w_gen_num, uint16_t granularity)
{
assert(width_wo_gen_num);
uint16_t distance = (end_pos_w_gen_num
- (end_pos_w_gen_num / granularity) * granularity) + 1;
if (distance >= width_wo_gen_num) {
distance = width_wo_gen_num;
const uint16_t result = end_pos_w_gen_num - width_wo_gen_num + 1;
return result;
}
uint16_t consumed_bits = 0;
uint16_t read_pos = end_pos_w_gen_num;
while(1) {
if ((consumed_bits + distance) >= width_wo_gen_num) {
distance = width_wo_gen_num - consumed_bits;
const uint16_t result = read_pos - distance + 1;
return result;
}
consumed_bits = consumed_bits + distance;
read_pos = read_pos - distance - 1;
distance = (read_pos - (read_pos / granularity) * granularity) + 1;
}
}
uint16_t calc_end_pos_gen_number(uint16_t width_wo_gen_num, uint16_t start_pos_w_gen_num, uint16_t granularity)
{
assert(width_wo_gen_num);
uint16_t distance = granularity - (start_pos_w_gen_num - (start_pos_w_gen_num / granularity) * granularity) - 1;
if (distance >= width_wo_gen_num) {
distance = width_wo_gen_num;
const uint16_t result = start_pos_w_gen_num + distance - 1;
return result;
}
uint16_t consumed_bits = 0;
uint16_t read_pos = start_pos_w_gen_num;
while(1) {
if (consumed_bits + distance >= width_wo_gen_num) {
distance = width_wo_gen_num - consumed_bits;
const uint16_t result = read_pos + distance - 1;
return result;
}
consumed_bits = consumed_bits + distance;
read_pos = read_pos + distance + 1;
distance = granularity - (read_pos - (read_pos / granularity) * granularity) - 1;
}
}
static void read_field_with_gen_number(uint32_t *source, uint16_t source_start_pos_w_gen_num,
uint16_t target_width_wo_gen_num,
uint32_t * target, uint16_t granularity) {
assert(target_width_wo_gen_num);
uint16_t distance = granularity
- (source_start_pos_w_gen_num - (source_start_pos_w_gen_num / granularity) * granularity) - 1;
if (distance > target_width_wo_gen_num) {
distance = target_width_wo_gen_num;
}
uint16_t consumed_bits = 0;
uint16_t read_pos = source_start_pos_w_gen_num;
bool break_out = false;
uint32_t temp[(CAM_MAX_GEN_NUMBER_GRANULARITY + 31) / 32];
while (1) {
if ((consumed_bits + distance) >= target_width_wo_gen_num) {
distance = target_width_wo_gen_num - consumed_bits;
break_out = true;
}
cam_read_field(source, read_pos, read_pos + distance - 1, temp);
cam_write_field(target, consumed_bits, consumed_bits + distance - 1, temp, target_width_wo_gen_num);
if (break_out)
break;
consumed_bits = consumed_bits + distance;
read_pos = read_pos + distance + 1;
distance = granularity - (read_pos - (read_pos / granularity) * granularity)
- 1;
}
}
uint8_t get_generation_number(const aaaa1aaat *km, uint32_t list_number, uint8_t narrow, uint8_t narrow_element) {
assert(client_get_generation_number_granularity(km->client));
assert(client_is_drambcam(km->client));
const uint16_t list_length = client_get_list_length(km->client);
const uint8_t number_of_word32s = list_length / 32;
const bool mixed_mode = client_is_mixed_mode(km->client);
uint16_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaend_pos = list_length - 1;
if (mixed_mode) {
if ((narrow != 0) && (narrow_element == 0)) {
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaend_pos = list_length / 2 - 1;
}
}
uint32_t generation_number;
cam_read_field(&km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[list_number * number_of_word32s], aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaend_pos, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaend_pos,
&generation_number);
return generation_number;
}
void set_generation_number(const aaaa1aaat *km, uint32_t list_number, uint8_t narrow, uint8_t narrow_element,
uint8_t generation_number) {
const uint16_t granularity = client_get_generation_number_granularity(km->client);
assert(granularity);
assert(client_is_drambcam(km->client));
const uint16_t list_length = client_get_list_length(km->client);
const uint8_t number_of_word32s = list_length / 32;
const bool mixed_mode = client_is_mixed_mode(km->client);
uint16_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaend_pos = list_length - 1;
if (mixed_mode) {
if ((narrow != 0) && (narrow_element == 0)) {
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaend_pos = list_length / 2 - 1;
}
}
write_only_gen_number(&km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[list_number * number_of_word32s], 0, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaend_pos, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaend_pos,
generation_number, granularity);
}
void set_key(const aaaa1aaat *km, uint32_t list_number, const key_and_mask_t *key,
uint8_t narrow, uint8_t narrow_element)
{
uint8_t g = 0;
const uint16_t granularity = client_get_generation_number_granularity(km->client);
if (granularity)
g = 1;
uint16_t key_size = get_key_size(km);
const uint16_t list_length = client_get_list_length(km->client);
const uint16_t number_of_word32s = list_length / 32;
uint16_t prio_end_pos = list_length - 3 - g;
const bool mixed_mode = client_is_mixed_mode(km->client);
uint16_t key_start_pos = 0;
assert((!mixed_mode && narrow == false) || mixed_mode);
if (mixed_mode) {
assert(!client_is_tcam(km->client));
if (narrow != 0) {
key_size = client_get_narrow_key_width(km->client);
}
if ((narrow != 0) && (narrow_element == 0)) {
prio_end_pos = list_length / 2 - 3 - g;
} else if ((narrow != 0) && (narrow_element == 1)) {
key_start_pos = list_length / 2;
prio_end_pos = list_length - 3 - g;
} else if (narrow == 0) {
prio_end_pos = list_length - 3 - g;
} else {
assert(false);
}
}
if (g == 1) {
write_field_with_gen_number(&km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[list_number * number_of_word32s], key_start_pos, key_size,
(uint32_t *) key,
prio_end_pos, granularity);
} else {
const uint16_t key_end_pos = key_start_pos + key_size - 1;
cam_write_field(&km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[list_number * number_of_word32s], key_start_pos, key_end_pos,
(uint32_t *) key,
prio_end_pos);
}
}
void get_key(const aaaa1aaat *km, uint32_t list_number, key_and_mask_t *key, uint8_t narrow, uint8_t narrow_element)
{
uint16_t key_size = get_key_size(km);
uint16_t key_start_pos = 0;
const uint16_t list_length = client_get_list_length(km->client);
const uint16_t number_of_word32s = list_length / 32;
if (client_is_mixed_mode(km->client)) {
assert(!client_is_tcam(km->client));
if (narrow != 0) {
key_size = client_get_narrow_key_width(km->client);
}
if ((narrow != 0) && (narrow_element == 1)) {
key_start_pos = list_length / 2;
}
}
const uint16_t key_end_pos = key_start_pos + key_size - 1;
const uint16_t granularity = client_get_generation_number_granularity(km->client);
if (granularity) {
read_field_with_gen_number(&km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[list_number * number_of_word32s], key_start_pos, key_size,
(uint32_t *) key, granularity);
} else {
cam_read_field(&km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[list_number * number_of_word32s], key_start_pos, key_end_pos,
(uint32_t *) key);
}
}
void get_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(const aaaa1aaat *km, uint32_t list_number, aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa,
uint8_t narrow, uint8_t narrow_element)
{
const uint16_t granularity = client_get_generation_number_granularity(km->client);
uint8_t g = 0;
if (granularity)
g = 1;
const uint16_t list_length = client_get_list_length(km->client);
uint16_t prio_field_end_pos = list_length - 2 - g;
const uint16_t prio_width = client_get_prio_width(km->client);
assert(prio_width <= 32);
const uint16_t aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa = prio_width + client_get_response_width(km->client);
const uint16_t number_of_word32s = list_length / 32;
const bool mixed_mode = client_is_mixed_mode(km->client);
assert((!mixed_mode && (narrow == 0)) || mixed_mode);
if (mixed_mode) {
assert(!client_is_tcam(km->client));
if (narrow && (narrow_element == 0)) {
prio_field_end_pos = list_length / 2 - 3 - g;
} else {
prio_field_end_pos = list_length - 3 - g;
}
}
if (g) {
const uint16_t response_field_start_pos = calc_start_pos_gen_number(aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa,
prio_field_end_pos,
granularity);
read_field_with_gen_number(&km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[list_number * number_of_word32s], response_field_start_pos,
aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa, (uint32_t *) aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, granularity);
} else {
const uint16_t response_field_start_pos = prio_field_end_pos - aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa + 1;
cam_read_field(&km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[list_number * number_of_word32s], response_field_start_pos,
prio_field_end_pos,
(uint32_t *) aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa);
}
}
bool aaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(const aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa)
{
assert(aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa < client_get_num_lists(km->client));
uint32_t valid;
assert(!client_is_mixed_mode(km->client));
const uint32_t valid_entry = aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa / 32;
const uint32_t start = aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa - valid_entry * 32;
valid = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(km->valid_cache[valid_entry], start, 1);
if (valid)
return false;
return true;
}
void aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaelement(aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, uint8_t narrow, uint8_t narrow_element)
{
bool bit511or255 = false;
const bool mixed = client_is_mixed_mode(km->client);
if ((narrow == 0) && mixed) {
bit511or255 = get_bit511or255(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
if (client_get_generation_number_granularity(km->client) > 0) {
const uint8_t generation_number = get_generation_number(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, 0, 0);
set_generation_number(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, 0, 0, generation_number + 1);
}
}
if (mixed)
set_control_bits(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, 0, narrow, narrow_element);
else
set_valid_bit(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, 0);
assert(km->flush == true);
flush(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, false, false, DELETE, narrow, narrow_element, bit511or255, false);
}
bool aaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaapresent(const aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, uint8_t narrow, uint8_t narrow_element)
{
if (client_is_mixed_mode(km->client)) {
bool wide_valid, narrow1_valid, narrow0_valid;
aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaabits(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, &wide_valid, &narrow1_valid, &narrow0_valid);
if (narrow == 0 && wide_valid == false)
return false;
if (!(narrow == 0) && narrow_element == 0 && narrow0_valid == false)
return false;
if (!(narrow == 0) && narrow_element == 1 && narrow1_valid == false)
return false;
} else if (aaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa))
return false;
return true;
}
void aaaa1bbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaall(aaaa1aaat *km)
{
const uint32_t end_list = client_get_num_lists(km->client) - 1;
for (uint32_t i = 0; i <= end_list; i++) {
flush(km, i, true, false, OTHER, 0, 0, false, false);
}
}
#ifndef _aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaH
#define _aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaH
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaabaaaaaaaaaaa5aaa {
uint16_t id;
};
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa {
uint16_t num_entries;
uint16_t size;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaabaaaaaaaaaaa5aaa *data;
};
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *marr, void* (*malloc_function)(size_t));
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa5aaa(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *marr, cam_free_func free_function);
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *marr, uint16_t id,
void* (*realloc_function)(void*, size_t));
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaafind(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *marr, uint16_t id,
uint16_t *out_index);
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *marr, uint16_t id,
void* (*realloc_function)(void*, size_t));
#endif
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa* marr, void* (*malloc_function)(size_t))
{
marr->data = malloc_function(2 * sizeof(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaabaaaaaaaaaaa5aaa));
if (marr->data == NULL)
return CAM_ERROR_NOMEM;
marr->size = 2;
return 0;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa5aaa(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *marr, cam_free_func free_function)
{
free_function(marr->data);
return 0;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *marr, uint16_t id,
void* (*realloc_function)(void*, size_t))
{
int i;
if (marr->num_entries == marr->size) {
uint16_t new_size = marr->size + (marr->size >> 1);
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaabaaaaaaaaaaa5aaa *tmp =
realloc_function(marr->data,
new_size * sizeof(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaabaaaaaaaaaaa5aaa));
if (tmp == NULL)
return CAM_ERROR_NOMEM;
marr->data = tmp;
marr->size = new_size;
}
i = marr->num_entries;
marr->data[i].id = id;
marr->num_entries++;
return 0;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaafind(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *marr, uint16_t id, uint16_t * out_index)
{
int i;
for (i = 0; i < marr->num_entries; i++)
if (marr->data[i].id == id) {
*out_index = i;
return 0;
}
return -1;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *marr, uint16_t id,
void* (*realloc_function)(void*, size_t))
{
int rc;
uint16_t index;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaafind(marr, id, &index);
assert(rc == 0);
if (rc)
return rc;
marr->num_entries--;
if (index < marr->num_entries)
memmove(&marr->data[index], &marr->data[index + 1],
(marr->num_entries - index) * sizeof(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaabaaaaaaaaaaa5aaa));
uint16_t new_size = marr->size / 2;
if (new_size >= 2 && marr->num_entries < new_size) {
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaabaaaaaaaaaaa5aaa *tmp = realloc_function(marr->data,
new_size *
sizeof(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaabaaaaaaaaaaa5aaa));
if (tmp == NULL)
return CAM_ERROR_NOMEM;
marr->data = tmp;
marr->size = new_size;
}
return 0;
}
#ifndef _aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaH
#define _aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaH
#define aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaS 256
#define aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaRESVD_INSTANCE (aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaS - 1)
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa {
uint8_t use_range;
uint32_t tot_pop;
uint16_t max_pop;
uint16_t const_pop;
uint32_t active_fields;
aaaaaaaaaaaaa1aaat mask;
};
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaa {
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa mask;
mh_handle mh_handle;
};
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaainstance {
uint8_t instances[aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaS / 8];
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa mask;
mh_handle mh_handle;
};
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaeate_exact(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
void aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaarelax_key(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa *mask,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaarelax_var_array *relax_key);
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaarelax_fields(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaeate_hash(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
void aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaabaaaaaaaaaa5aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaabaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaamember(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa *mask,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaainstance(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa *mask,
uint8_t *instance);
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaput_instance(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa *mask,
uint8_t instance);
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaabaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaainstances(struct tcam *magg);
uint32_t aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaavalue(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa *mask);
void aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa *mask, int indent);
uint8_t aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaacalc_num_ones(uint8_t field_len, uint16_t max_combinations);
uint64_t aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaacalc_num_combinations(uint8_t len, uint8_t max_num_ones);
#endif
#ifndef _aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaH_
#define _aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaH_
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa {
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset;
uint8_t instance;
};
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa {
uint16_t id;
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat priority;
aaaaaaaaaaaaa1aaat exact_key;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa exact_mask;
uint32_t relax_fields;
uint32_t multiply_fields;
m_array *collsets;
uint16_t num_collsets;
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa current_entryset;
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa next_entryset;
uint8_t allocated;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaa *mask_by_mask;
mh_handle mh_handle;
union aaaaaaaaaaa1aaa fields[];
};
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa {
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *entry;
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa *next;
};
int aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaeate(struct tcam *magg, uint16_t id, const union aaaaaaaaaaa1aaa *fields,
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *priority,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa **me);
int aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
int aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaeate_collset(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
int aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
int aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me,
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset);
int aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me,
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset);
int aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me, int indent);
#endif
#ifndef _aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaH_
#define _aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaH_
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa {
uint8_t is_solved;
uint16_t num_entries;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *entryset_by_mask;
};
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate(struct tcam *magg,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem);
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa5aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem);
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaareset(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem);
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaawinner(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa **out_mes);
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaareduce(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
int indent);
#endif
#ifndef _aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaH_
#define _aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaH_
enum {
aaaaa1aaaOP_NOP = 0,
aaaaa1aaaOP_ADD,
aaaaa1aaaOP_DEL
};
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaop {
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *src_entryset;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *dst_entryset;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *dst_collset;
uint8_t src_instance;
uint8_t dst_instance;
uint8_t src_op;
uint8_t dst_op;
};
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaa {
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mask_list;
uint16_t num_masks;
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa *collision_list;
};
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa;
int aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate(struct tcam *magg,
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *solution);
int aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa5aaa(struct tcam *magg, struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *solution);
int aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(struct tcam *magg,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
int aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(struct tcam *magg, struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *solution,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa **out_mesli);
int aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6bbbbbbbbbbbbbbbbbb6aaa(struct tcam *magg,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa **out_mesli);
int aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa(struct tcam *magg,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa **out_mesli);
int aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol,
int max_num_masks);
#endif
#ifndef _aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaH_
#define _aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaH_
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa {
uint8_t is_solved;
uint8_t do_refill;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa problem;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaa curr_solution;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaa prev_solution;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *next;
};
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa **out_probsol);
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa5aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol);
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(struct tcam *magg);
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol,
int indent);
#endif
#ifndef _aaaaa1aaaDEBUG_H_
#define _aaaaa1aaaDEBUG_H_
#ifdef __cplusplus
extern "C" {
#endif
#define aaaaa1aaaDEBUG_NONE 0x0000
#define aaaaa1aaaDEBUG_TEST 0x0001
#define aaaaa1aaaDEBUG_PROBSOL 0x0002
#define aaaaa1aaaDEBUG_SET_COVER 0x0004
#define aaaaa1aaaDEBUG_ADD_DEL 0x0008
#define aaaaa1aaaDEBUG_HCAM 0x0010
#define aaaaa1aaaDEBUG_MASK_HASH 0x0020
#define aaaaa1aaaDEBUG_SORTEDSET 0x0040
#define aaaaa1aaaDEBUG_OPARRAY 0x0080
#define aaaaa1aaaDEBUG_INSTANCE 0x0100
#define aaaaa1aaaDEBUG_ENTRYSET 0x0200
#define aaaaa1aaaDEBUG_CONFIG 0x0400
#define aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa 0x1000
#define aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa 0x2000
#define aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaabaaaaaaaaaaa5bbbbbbbbbbbbbbbbbb5aaa 0x4000
#define aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa 0x8000
#define aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaabaaaaaaaaaaa5aaa 0x10000
#define aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaTABLE 0x20000
#define aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaDUMP 0x40000
int aaaaa1aaadebug_run(struct tcam *tcam);
int aaaaa1aaadebug_set_mask(struct tcam *tcam, uint32_t debug_flags);
uint32_t aaaaa1aaadebug_get_mask(struct tcam *tcam);
int aaaaa1aaadebug_dump(struct tcam *tcam);
int aaaaa1aaadebug_print(struct tcam *tcam, int indent);
void cam_mem_debug(struct tcam *tcam);
void cam_resource_debug(struct tcam *tcam);
#ifdef __cplusplus
}
#endif
#endif
#ifndef _aaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaH_
#define _aaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaH_
#define aaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaabaaaaaaaaaaa5aaaS 16
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaa {
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *buckets[aaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaabaaaaaaaaaaa5aaaS];
};
int aaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes, struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset);
int aaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaafind(struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes,
aaaaaaaaaaaaa1aaat *relax_key,
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa **out_collset);
int aaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa4aaa(struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes,
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset);
#endif
#ifndef _aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaH_
#define _aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaH_
#define aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaWEIGHT 1
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa {
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas;
uint16_t remaining_entries;
uint16_t num_populated;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *entryset;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *next;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaarelax_var_array relax_key;
};
int aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate(struct tcam *magg, struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa **collset);
int aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa5aaa(struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset, cam_free_func free_function);
int aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(struct tcam *magg, struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
int aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(struct tcam *magg, struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
int aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaafind(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me, struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa **collset);
int aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(struct tcam *magg, struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset,
int indent);
#endif
#ifndef _aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaH_
#define _aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaH_
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes, uint8_t mes_instance,
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset);
int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes, uint8_t mes_instance);
#endif
#ifndef _aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaH_
#define _aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaH_
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa {
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa mask;
uint32_t num_entries;
uint32_t weight;
uint32_t remaining_entries;
uint32_t remaining_weight;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaa collset_by_key;
mh_handle mh_handle;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *entryset_next;
uint8_t members[];
};
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa {
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *entryset;
uint8_t instance;
uint16_t weight;
uint16_t num_entries;
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa *aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *next;
};
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa;
int aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa *mask,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa **out_mes);
int aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa5aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes);
int aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
int aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
int aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaopen(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
int aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaasolved(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
int aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaopen(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
int aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaasolved(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
int aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaareset(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes);
int aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapopulate(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli,
uint16_t *num_populated);
int aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaabaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaamember(struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me);
int aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes,
int indent);
#endif
int
aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate(struct tcam *magg, struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa **out_collset)
{
int rc;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset;
cam_calloc_func calloc_function = client_get_calloc_function((client_t*) (magg->client));
collset = calloc_function(1, sizeof(struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa) + sizeof(aaaaaaaaaaaaa1aaat));
if (collset == NULL)
return CAM_ERROR_NOMEM;
cam_malloc_func malloc_function = client_get_malloc_function((client_t*) (magg->client));
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate(&collset->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas, malloc_function);
if (rc)
goto error;
magg->stats.curr_num_collsets++;
magg->stats.max_num_collsets = MAX(magg->stats.curr_num_collsets,
magg->stats.max_num_collsets);
*out_collset = collset;
return 0;
error:
(client_get_free_function((client_t*) (magg->client)))(collset);
return rc;
}
int
aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(struct tcam *magg, struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
int rc;
cam_realloc_func realloc_function = client_get_realloc_function(
(client_t*) (magg->client));
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(&collset->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas, me->id, realloc_function);
if (rc)
return rc;
me->num_collsets++;
return 0;
}
int
aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(struct tcam *magg, struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
int rc;
cam_realloc_func realloc_function = client_get_realloc_function(
(client_t*) (magg->client));
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(&collset->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas, me->id, realloc_function);
if (rc)
return rc;
me->num_collsets--;
return 0;
}
int
aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaafind(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me, struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa **out_collset)
{
int rc;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset;
aaaaaaaaaaaaa1aaat relax_key;
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaarelax_key(magg, me, &mes->mask,
(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaarelax_var_array *) &relax_key);
rc = aaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaafind(mes, &relax_key, &collset);
if (rc)
return rc;
*out_collset = collset;
if (collset == NULL)
return 1;
return 0;
}
int
aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa5aaa(struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset, cam_free_func free_function)
{
(void) aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa5aaa(&collset->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas, free_function);
free_function(collset);
return 0;
}
int
aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(struct tcam *magg, struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset, int indent)
{
   printf("%*caaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa %p num_entries %u\n", indent, ' ', (void *) collset,
collset->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas.num_entries);
if (!(magg->debug_mask & aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaabaaaaaaaaaaa5aaa))
return 0;
int i;
for (i = 0; i < collset->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas.num_entries; i++) {
uint16_t id = collset->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas.data[i].id;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me = magg->entries[id];
aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(me, indent + 2);
}
return 0;
}
int
aaaaa1aaadebug_run(struct tcam *magg)
{
int rc;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg);
if (rc)
return rc;
return 0;
}
int
aaaaa1aaadebug_set_mask(struct tcam *magg, uint32_t debug_flags)
{
magg->debug_mask = debug_flags;
return 0;
}
uint32_t
aaaaa1aaadebug_get_mask(struct tcam *magg)
{
return magg->debug_mask;
}
int
aaaaa1aaadebug_dump(struct tcam *magg)
{
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli;
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa *meli;
LIST_FOREACH(magg->probsols, probsol)
{
LIST_FOREACH(probsol->curr_solution.mask_list, mesli)
{
int num_entries = 0;
LIST_FOREACH(mesli->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa, meli)
num_entries++;
           printf("Mask %08x instance %u with %d entries use ranges %x:\n  ",
mesli->entryset->mh_handle.hashv,
mesli->instance, num_entries,
mesli->entryset->mask.use_range);
size_t i;
for (i = 0; i < sizeof(aaaaaaaaaaaaa1aaat) / 4; i++)
               printf("%08"PRIx32" ", mesli->entryset->mask.mask.word[i]);
           printf("\n");
LIST_FOREACH(mesli->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa, meli)
{
               printf("  Entry %p prio %"PRIu32" collset %p\n",
(void *) meli->entry, meli->entry->priority.word[0],
(void *) meli->entry->current_entryset.collset);
               printf("    K ");
for (i = 0; i < sizeof(aaaaaaaaaaaaa1aaat) / 4; i++)
                   printf("%08"PRIx32" ", meli->entry->exact_key.word[i]);
               printf("\n");
               printf("    M ");
for (i = 0; i < sizeof(aaaaaaaaaaaaa1aaat) / 4; i++)
                   printf("%08"PRIx32" ", meli->entry->exact_mask.mask.word[i]);
               printf("\n");
}
}
}
return 0;
}
int
aaaaa1aaadebug_print(struct tcam *magg, int indent)
{
if (!(magg->debug_mask & aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa))
return 0;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol;
LIST_FOREACH(magg->probsols, probsol)
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(magg, probsol, indent);
return 0;
}
void cam_mem_debug(struct tcam *tcam)
{
client_print(tcam->client);
}
void cam_resource_debug(struct tcam *tcam)
{
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaastats(tcam);
}
static void
aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas_copy(void *dst, const void *src)
{
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa **dp = (struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa **) dst;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa **sp = (struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa **) src;
*dp = *sp;
}
int
aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaeate(struct tcam *magg, uint16_t id, const union aaaaaaaaaaa1aaa *fields,
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *priority,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa **me_out)
{
int rc;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me;
const uint8_t num_fields = client_get_num_fields(magg->client);
cam_free_func free_function = client_get_free_function((client_t*) (magg->client));
cam_malloc_func malloc_function = client_get_malloc_function((client_t*) (magg->client));
cam_calloc_func calloc_function = client_get_calloc_function((client_t*) (magg->client));
me = calloc_function(1, sizeof(*me) + num_fields * sizeof(union aaaaaaaaaaa1aaa));
if (me == NULL)
return CAM_ERROR_NOMEM;
me->id = id;
memcpy(&me->fields, fields, num_fields * sizeof(union aaaaaaaaaaa1aaa));
me->priority = *priority;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate_exact(magg, me);
if (rc)
goto error;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaeate_exact(magg, me);
if (rc)
goto error;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaarelax_fields(magg, me);
if (rc)
goto error;
rc = aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaeate_collset(magg, me);
if (rc)
goto error;
rc = CAM_ERROR_NOMEM;
MH_ADD_KEYPTR(mh_handle, magg->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaby_fields, &me->fields, num_fields * sizeof(union aaaaaaaaaaa1aaa), me, free_function, malloc_function);
*me_out = me;
return 0;
error:
if (me->collsets)
(void) aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(magg, me);
free_function(me);
*me_out = NULL;
return rc;
}
int
aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
cam_free_func free_function = client_get_free_function((client_t*) (magg->client));
MH_DELETE(mh_handle, magg->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaby_fields, me, free_function);
magg->entries[me->id] = 0;
(void) aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(magg, me);
free_function(me);
return 0;
}
int
aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaeate_collset(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
m_icd ut_icd = { sizeof(struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *), NULL,
aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas_copy, NULL
};
cam_malloc_func malloc_function = client_get_malloc_function((client_t*) (magg->client));
me->collsets = malloc_function(sizeof(m_array));
if (me->collsets == NULL)
return CAM_ERROR_NOMEM;
array_init(me->collsets, &ut_icd);
me->num_collsets = 0;
return 0;
}
int
aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
cam_free_func free_function = client_get_free_function((client_t*) (magg->client));
array_free(me->collsets, free_function);
me->num_collsets = 0;
return 0;
}
int
aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me,
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset)
{
cam_realloc_func realloc_function = client_get_realloc_function(
(client_t*) (magg->client));
array_push_back(me->collsets, &collset, realloc_function);
return 0;
error:
return CAM_ERROR_NOMEM;
}
int
aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me,
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset)
{
(void) magg; 
size_t index = 0;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa **collsetp;
for (collsetp = (struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa **) array_front(me->collsets);
collsetp; collsetp = (struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa **)
array_next(me->collsets, collsetp)) {
if (*collsetp == collset) {
array_erase(me->collsets, index, 1);
break;
}
index++;
}
assert(collsetp);
return 0;
}
int aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me, int indent)
{
   printf("%*caaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa %p prio %"PRIu32"\n", indent, ' ',
(void *) me, me->priority.word[0]);
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(&me->exact_key, indent + 2);
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(&me->exact_mask, indent + 2);
return 0;
}
int
aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa *mask, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa **out_mes)
{
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes;
const uint32_t max_num_entries = client_get_num_entries(magg->client);
cam_free_func free_function = client_get_free_function((client_t*) (magg->client));
cam_calloc_func calloc_function = client_get_calloc_function((client_t*) (magg->client));
cam_malloc_func malloc_function = client_get_malloc_function((client_t*) (magg->client));
mes = calloc_function(1, sizeof(*mes) + max_num_entries / 8 + 1);
if (mes == 0)
return CAM_ERROR_NOMEM;
memcpy(&mes->mask, mask, sizeof(mes->mask));
int rc = CAM_ERROR_NOMEM;
MH_ADD(mh_handle, problem->entryset_by_mask, mask, sizeof(mes->mask), mes, free_function, malloc_function);
magg->stats.curr_num_entrysets++;
magg->stats.max_num_entrysets = MAX(magg->stats.curr_num_entrysets,
magg->stats.max_num_entrysets);
*out_mes = mes;
return 0;
error: free_function(mes);
return rc;
}
static int
aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb5aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes,
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset, cam_free_func free_function)
{
int rc;
rc = aaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa4aaa(mes, collset);
if (rc)
return rc;
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa5aaa(collset, free_function);
if (rc)
return rc;
magg->stats.curr_num_collsets--;
return 0;
}
int
aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa5aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes)
{
int i;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset, *tmp;
cam_free_func free_function = client_get_free_function(magg->client);
for (i = 0; i < aaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaabaaaaaaaaaaa5aaaS; i++) {
if (mes->collset_by_key.buckets[i] == NULL)
continue;
LIST_FOREACH_SAFE(mes->collset_by_key.buckets[i], collset, tmp)
(void) aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb5aaa(magg, mes, collset, free_function);
}
MH_DELETE(mh_handle, problem->entryset_by_mask, mes, free_function);
magg->stats.curr_num_entrysets--;
free_function(mes);
return 0;
}
static void
aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaamember_add(struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
mes->members[me->id / 8] |= 1 << me->id % 8;
}
static void
aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaamember_delete(struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
mes->members[me->id / 8] &= ~(1 << me->id % 8);
}
int
aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaabaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaamember(struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
return mes->members[me->id / 8] & (1 << me->id % 8);
}
static int
aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb5aaa(struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes,
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset)
{
int rc;
rc = aaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(mes, collset);
if (rc)
return rc;
collset->entryset = mes;
return 0;
}
int
aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
int rc;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset;
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaafind(magg, mes, me, &collset);
if (rc) {
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate(magg, &collset);
if (rc)
goto error;
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaarelax_key(magg, me, &mes->mask,
&collset->relax_key);
rc = aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb5aaa(mes, collset);
if (rc)
goto error;
}
if (problem->is_solved &&
collset->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas.num_entries >= magg->max_num_collisions)
return -1;
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg, collset, me);
if (rc)
goto error;
rc = aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg, me, collset);
if (rc)
goto error;
mes->num_entries++;
aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaamember_add(mes, me);
if (collset->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas.num_entries <= magg->max_num_collisions)
mes->weight += aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaWEIGHT;
return 0;
error:
return rc;
}
int
aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
(void) problem;
int rc;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset;
mes->num_entries--;
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaafind(magg, mes, me, &collset);
assert(rc == 0);
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(magg, collset, me);
if (rc)
return rc;
rc = aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(magg, me, collset);
if (rc)
return rc;
if (collset->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas.num_entries < magg->max_num_collisions)
mes->weight -= aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaWEIGHT;
if (collset->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas.num_entries == 0) {
cam_free_func free_function = client_get_free_function((client_t*) (magg->client));
rc = aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb5aaa(magg, mes, collset, free_function);
if (rc)
return rc;
}
aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaamember_delete(mes, me);
return 0;
}
int
aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaopen(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
int rc;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes = NULL;
assert(me->mask_by_mask);
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaa *mfh, *mfh_tmp;
MH_ITER(mh_handle, me->mask_by_mask, mfh, mfh_tmp)
{
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa *mask = &mfh->mask;
MH_FIND(mh_handle, problem->entryset_by_mask, mask, sizeof(*mask), mes);
if (mes == 0) {
rc = aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate(magg, problem, mask, &mes);
if (rc)
return rc;
}
rc = aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg, problem, mes, me);
if (rc)
return rc;
}
return 0;
}
int
aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaasolved(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
int rc;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes = NULL;
assert(me->mask_by_mask);
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaa *mfh, *mfh_tmp;
MH_ITER(mh_handle, me->mask_by_mask, mfh, mfh_tmp)
{
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa *mask = &mfh->mask;
MH_FIND(mh_handle, problem->entryset_by_mask, mask, sizeof(*mask), mes);
if (mes == 0)
continue;
rc = aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg, problem, mes, me);
if (rc == -1)
continue;
if (rc)
return rc;
return 0;
}
return -1;
}
int
aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaasolved(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
int rc;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes;
mes = me->current_entryset.mes;
rc = aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(magg, problem, mes, me);
if (rc)
return rc;
if (mes->num_entries == 0) {
rc = aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa5aaa(magg, problem, mes);
if (rc)
return rc;
}
return 0;
}
int
aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaopen(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
int rc;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes = NULL;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa *mask;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaeate_hash(magg, me);
if (rc)
return rc;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaa *mfh, *mfh_tmp;
MH_ITER(mh_handle, me->mask_by_mask, mfh, mfh_tmp)
{
mask = &mfh->mask;
MH_FIND(mh_handle, problem->entryset_by_mask, mask, sizeof(*mask), mes);
if (mes == NULL || !aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaabaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaamember(mes, me))
continue;
rc = aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(magg, problem, mes, me);
if (rc)
goto error;
if (mes->num_entries == 0) {
rc = aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa5aaa(magg, problem, mes);
if (rc)
goto error;
}
}
error:
(void) aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaabaaaaaaaaaa5aaa(magg, me);
return 0;
}
int aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapopulate(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli,
uint16_t * num_populated)
{
int bucket;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset;
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa *meli;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *best_me;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *best_collset;
cam_calloc_func calloc_function = client_get_calloc_function((client_t*) (magg->client));
*num_populated = 0;
for (bucket = 0; bucket < aaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaabaaaaaaaaaaa5aaaS; bucket++) {
if (mes->collset_by_key.buckets[bucket] == NULL)
continue;
LIST_FOREACH(mes->collset_by_key.buckets[bucket], collset)
{
collset->num_populated = 0;
}
}
while(true) {
uint32_t best_score = UINT32_MAX;
bool winner_found = false;
bool perfect_winner = false;
for (bucket = 0; bucket < aaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaabaaaaaaaaaaa5aaaS; bucket++) {
if (mes->collset_by_key.buckets[bucket] == NULL)
continue;
LIST_FOREACH(mes->collset_by_key.buckets[bucket], collset)
{
int i;
if (collset->num_populated >= 1)
continue;
uint16_t id;
for (i = 0; i < collset->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas.num_entries; i++) {
id = collset->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas.data[i].id;
me = magg->entries[id];
assert(me);
if (me->allocated)
continue;
if (me->num_collsets < best_score) {
winner_found = true;
best_score = me->num_collsets;
best_me = me;
best_collset = collset;
}
if (me->num_collsets == 1) {
perfect_winner = true;
break;
}
}
if (perfect_winner) {
break;
}
}
if (perfect_winner) {
break;
}
}
if (winner_found) {
best_me->next_entryset.collset = best_collset;
best_me->next_entryset.mes = mesli->entryset;
best_me->next_entryset.instance = mesli->instance;
best_me->allocated = 1;
best_collset->num_populated++;
meli = calloc_function(1, sizeof(*meli));
if (meli == NULL)
return CAM_ERROR_NOMEM;
meli->entry = best_me;
LIST_PREPEND2(mesli->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa, meli, next);
(*num_populated)++;
if (*num_populated == client_get_num_entries_per_unit(magg->client))
return 0;
} else {
break;
}
}
return 0;
}
int
aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaareset(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes)
{
(void) magg;
int i;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset;
mes->remaining_entries = mes->num_entries;
mes->remaining_weight = mes->weight;
for (i = 0; i < aaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaabaaaaaaaaaaa5aaaS; i++) {
if (mes->collset_by_key.buckets[i] == NULL)
continue;
LIST_FOREACH(mes->collset_by_key.buckets[i], collset)
collset->remaining_entries = collset->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas.num_entries;
}
return 0;
}
int
aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes, int indent)
{
   printf("%*caaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa %p num_entries %"PRIu32" weight %"PRIu32" max pop %"PRIu16" active fields %"PRIu8"\n",
indent, ' ',
(void *) mes, mes->num_entries, mes->weight, mes->mask.max_pop,
__builtin_popcount(mes->mask.active_fields));
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(&mes->mask, indent + 2);
if (magg->debug_mask & aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa) {
int i;
for (i = 0; i < aaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaabaaaaaaaaaaa5aaaS; i++) {
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset;
LIST_FOREACH(mes->collset_by_key.buckets[i], collset)
aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(magg, collset, indent + 2);
}
}
return 0;
}
int
aaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes,
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset)
{
uint32_t index, hash_tmp;
murmur3_bucket(&collset->relax_key, sizeof(aaaaaaaaaaaaa1aaat), aaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaabaaaaaaaaaaa5aaaS, &hash_tmp, &index);
LIST_PREPEND(mes->collset_by_key.buckets[index], collset);
return 0;
}
int
aaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaafind(struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes,
aaaaaaaaaaaaa1aaat *relax_key,
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa **out_collset)
{
uint32_t index, hash_tmp;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset;
murmur3_bucket(relax_key, sizeof(aaaaaaaaaaaaa1aaat), aaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaabaaaaaaaaaaa5aaaS, &hash_tmp, &index);
LIST_FOREACH(mes->collset_by_key.buckets[index], collset)
{
if (memcmp(&collset->relax_key, relax_key, sizeof(aaaaaaaaaaaaa1aaat)) == 0) {
*out_collset = collset;
return 0;
}
}
*out_collset = NULL;
return -1;
}
int
aaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa4aaa(struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes,
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset)
{
uint32_t index, hash_tmp;
murmur3_bucket(&collset->relax_key, sizeof(aaaaaaaaaaaaa1aaat), aaaaa1aaaaaaaaaaaabaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaabaaaaaaaaaaa5aaaS, &hash_tmp, &index);
LIST_DELETE(mes->collset_by_key.buckets[index], collset);
return 0;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes,
uint8_t mes_instance,
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset)
{
int rc;
aaaaaaaaaaaaa1aaat key;
aaaaaaaaaaaaa1aaat mask;
aaaaaaaaaaaaa1aaat ternary_mask;
memset(&key, 0, sizeof(key));
memset(&mask, 0, sizeof(mask));
memset(&ternary_mask, 0, sizeof(ternary_mask));
memcpy(&key, &me->exact_key.word[0], sizeof(aaaaaaaaaaaaa1aaat));
memcpy(&mask, &mes->mask.mask.word[0], sizeof(aaaaaaaaaaaaa1aaat));
memcpy(&ternary_mask, &me->exact_mask.mask.word[0],
sizeof(aaaaaaaaaaaaa1aaat));
const uint8_t num_fields = client_get_num_fields(magg->client);
int field;
for (field = 0; field < num_fields; field++) {
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc mfd;
rc = client_get_aaaaaaaaaaaaaaaaaa1aaa(magg->client, field, &mfd);
assert(rc == 0);
if (mfd.type != aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaR16 ||
(me->exact_mask.use_range &
1 << mfd.instance) == 0)
continue;
if (mes->mask.use_range & 1 << mfd.instance)
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint2bit((uint8_t *) &ternary_mask.word[0],
sizeof(aaaaaaaaaaaaa1aaat),
mfd.start_pos,
(uint8_t *) &me->fields[field].r16.end,
mfd.len);
else
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaabits((uint8_t *) &ternary_mask.word[0],
sizeof(aaaaaaaaaaaaa1aaat),
mfd.start_pos, mfd.len);
}
if (magg->debug_mask & aaaaa1aaaDEBUG_HCAM) {
size_t i;
       printf("A %05"PRIu32" %p %3"PRIu8" %"PRIx32" %"PRIu16" %"PRIu16" %"PRIu8" %p %"PRIx8":\n",
me->priority.word[0],
(void *) mes, mes_instance,
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaavalue(&mes->mask), magg->num_masks,
mes->mask.max_pop, __builtin_popcount(mes->mask.active_fields),
(void *) collset, mes->mask.use_range);
       printf("  K ");
for (i = 0; i < sizeof(aaaaaaaaaaaaa1aaat); i++)
           printf("%02x ", *(((char *) &key) + i) & 0xff);
       printf("\n  M ");
for (i = 0; i < sizeof(aaaaaaaaaaaaa1aaat); i++)
           printf("%02x ", *(((char *) &mask) + i) & 0xff);
       printf("\n  T ");
for (i = 0; i < sizeof(aaaaaaaaaaaaa1aaat); i++)
           printf("%02x ", *(((char *) &ternary_mask) + i) & 0xff);
       printf("\n");
}
#ifdef aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaERROR_INSERT
int err = random() & 0x3ff;
if (err == 0) {
rc = -1;
if (magg->debug_mask & aaaaa1aaaDEBUG_HCAM)
           printf("%d\n", rc);
return rc;
}
#endif
rc = client_update_range_key(magg->client, &key, &ternary_mask, &me->priority,
&mask, mes->mask.use_range, mes_instance);
if (rc == 0) {
me->current_entryset.mes = mes;
me->current_entryset.instance = mes_instance;
me->current_entryset.collset = collset;
return 0;
}
if (rc == CAM_ERROR_DUPLICATE_FOUND)
return rc;
assert(false);
return rc; 
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes, uint8_t mes_instance)
{
int rc;
aaaaaaaaaaaaa1aaat key;
aaaaaaaaaaaaa1aaat mask;
aaaaaaaaaaaaa1aaat ternary_mask;
memset(&key, 0, sizeof(key));
memset(&mask, 0, sizeof(mask));
memset(&ternary_mask, 0, sizeof(ternary_mask));
memcpy(&key, &me->exact_key.word[0], sizeof(aaaaaaaaaaaaa1aaat));
memcpy(&mask, &mes->mask.mask.word[0], sizeof(aaaaaaaaaaaaa1aaat));
memcpy(&ternary_mask, &me->exact_mask.mask.word[0],
sizeof(aaaaaaaaaaaaa1aaat));
const uint8_t num_fields = client_get_num_fields(magg->client);
int field;
for (field = 0; field < num_fields; field++) {
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc mfd;
rc = client_get_aaaaaaaaaaaaaaaaaa1aaa(magg->client, field, &mfd);
assert(rc == 0);
if (mfd.type != aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaR16 ||
(me->exact_mask.use_range &
1 << mfd.instance) == 0)
continue;
if (mes->mask.use_range & 1 << mfd.instance)
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint2bit((uint8_t *) &ternary_mask.word[0],
sizeof(aaaaaaaaaaaaa1aaat),
mfd.start_pos,
(uint8_t *) &me->fields[field].r16.end,
mfd.len);
else
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaabits((uint8_t *) &ternary_mask.word[0],
sizeof(aaaaaaaaaaaaa1aaat),
mfd.start_pos, mfd.len);
}
if (magg->debug_mask & aaaaa1aaaDEBUG_HCAM) {
size_t i;
       printf("D %05"PRIu32" %p %3"PRIu8" %"PRIx32" %"PRIu16" %"PRIu16" %"PRIu16" %"PRIx8":\n", me->priority.word[0],
(void *) mes, mes_instance,
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaavalue(&mes->mask), magg->num_masks,
mes->mask.max_pop, __builtin_popcount(mes->mask.active_fields),
mes->mask.use_range);
       printf("  K ");
for (i = 0; i < sizeof(aaaaaaaaaaaaa1aaat); i++)
           printf("%02x ", *(((char *) &key) + i) & 0xff);
       printf("\n  M ");
for (i = 0; i < sizeof(aaaaaaaaaaaaa1aaat); i++)
           printf("%02x ", *(((char *) &mask) + i) & 0xff);
       printf("\n  T ");
for (i = 0; i < sizeof(aaaaaaaaaaaaa1aaat); i++)
           printf("%02x ", *(((char *) &ternary_mask) + i) & 0xff);
       printf("\n");
}
#ifdef aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaERROR_INSERT
int err = random() & 0x3ff;
if (err == 0) {
rc = -1;
if (magg->debug_mask & aaaaa1aaaDEBUG_HCAM)
           printf("%d\n", rc);
return rc;
}
#endif
rc = client_delete_range_key(magg->client, &key, &ternary_mask, &mask,
mes->mask.use_range, mes_instance);
if (rc == 0)
return 0;
assert(false);
return rc; 
}
static int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaatest_prefix(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me, uint8_t index)
{
struct aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaab128 b128;
memset(&b128, 0, sizeof(b128));
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc mfd;
int rc = client_get_aaaaaaaaaaaaaaaaaa1aaa(magg->client, index, &mfd);
assert(rc == 0);
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint2bit(&b128.key[0], sizeof(aaaaaaaaaaaaa1aaat), 0,
&me->fields[index].p128.key[0],
mfd.len);
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaabits(&b128.mask[0], sizeof(aaaaaaaaaaaaa1aaat),
mfd.len -
me->fields[index].p128.len,
me->fields[index].p128.len);
int i;
for (i = 0; i < aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaMEM_128; i++)
if ((b128.key[i] & b128.mask[i]) != b128.key[i])
return CAM_ERROR_INVALID_PREFIX_KEY;
return 0;
}
static int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaa6aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me, uint8_t index)
{
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc mfd;
int rc = client_get_aaaaaaaaaaaaaaaaaa1aaa(magg->client, index, &mfd);
assert(rc == 0);
switch (mfd.type) {
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaR16:
if (me->fields[index].r16.start > me->fields[index].r16.end)
return CAM_ERROR_WRONG_RANGE;
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint2bit((uint8_t *) &me->exact_key.word[0], sizeof(aaaaaaaaaaaaa1aaat),
mfd.start_pos,
(uint8_t *) &me->fields[index].r16.start, mfd.len);
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaP128:
if (me->fields[index].p128.len > 128)
return CAM_ERROR_INVALID_PREFIX_LEN;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaatest_prefix(magg, me, index);
if (rc)
return rc;
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint2bit((uint8_t *) &me->exact_key.word[0], sizeof(aaaaaaaaaaaaa1aaat),
mfd.start_pos,
&me->fields[index].p128.key[0], mfd.len);
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaT64:
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint2bit((uint8_t *) &me->exact_key.word[0], sizeof(aaaaaaaaaaaaa1aaat),
mfd.start_pos,
&me->fields[index].t64.key[0], mfd.len);
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaB128:
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint2bit((uint8_t *) &me->exact_key.word[0], sizeof(aaaaaaaaaaaaa1aaat),
mfd.start_pos,
&me->fields[index].b128.key[0], mfd.len);
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaC128:
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint2bit((uint8_t *) &me->exact_key.word[0], sizeof(aaaaaaaaaaaaa1aaat),
mfd.start_pos,
&me->fields[index].c128.key[0], mfd.len);
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaU128:
break;
default:
assert(0);
}
return 0;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate_exact(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
int rc, i;
const uint8_t num_fields = client_get_num_fields(magg->client);
for (i = 0; i < num_fields; i++) {
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaa6aaa(magg, me, i);
if (rc)
return rc;
}
return 0;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(aaaaaaaaaaaaa1aaat *exact_key, int indent)
{
size_t i;
   printf("%*cK       ", indent, ' ');
for (i = 0; i < sizeof(aaaaaaaaaaaaa1aaat) / 4; i++) {
       printf("%08"PRIx32" ", exact_key->word[i]);
if (i && (i + 1) % 2 == 0)
           printf(": ");
}
   printf("\n");
return 0;
}
#define aaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaLEN_BIT_128 128
int
aaaaa1aaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaeate(client_t * client, const struct set_expansion *se,
struct tcam **out_tcam)
{
int rc;
struct tcam *magg;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol;
const uint32_t max_num_entries = client_get_num_entries(client);
cam_calloc_func calloc_function = client_get_calloc_function(client);
magg = calloc_function(1, sizeof(*magg) + max_num_entries *
sizeof(struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *));
if (magg == NULL)
return CAM_ERROR_NOMEM;
magg->oparray = calloc_function(max_num_entries,
sizeof(struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaop));
if (magg->oparray == NULL) {
rc = CAM_ERROR_NOMEM;
goto error;
}
magg->client = client;
magg->set_expansion = *se;
magg->max_num_collisions = 1;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate(magg, &probsol);
if (rc)
goto error;
magg->open_probsol = probsol;
LIST_APPEND(magg->probsols, probsol);
magg->do_refill = 0;
*out_tcam = magg;
return 0;
error:;
cam_free_func free_function = client_get_free_function(client);
if (magg->oparray != NULL)
free_function(magg->oparray);
client_destroy_tcam(magg->client);
free_function(magg);
return rc;
}
int
aaaaa1aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(struct tcam *magg)
{
int rc;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol, *tmp;
LIST_FOREACH_SAFE(magg->probsols, probsol, tmp)
{
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa5aaa(magg, probsol);
if (rc)
return rc;
}
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaabaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaainstances(magg);
if (rc)
return rc;
cam_free_func free_function = client_get_free_function((client_t*) (magg->client));
free_function(magg->oparray);
client_destroy_tcam(magg->client);
free_function(magg);
return 0;
}
void aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaastats(struct tcam *tcam)
{
   printf("Entries   = %u (peak %u)\n", tcam->stats.curr_num_entries, tcam->stats.max_num_entries);
   printf("Masks     = %u (peak %u)\n",
tcam->stats.curr_num_masks, tcam->stats.max_num_masks);
   printf("Masks closed = %u (peak %u) + open = %u (peak %u)\n",
tcam->stats.curr_closed_masks, tcam->stats.max_closed_masks,
tcam->stats.curr_open_masks, tcam->stats.max_open_masks);
   printf("Entrysets = %"PRIu32" (peak %"PRIu32")\n", tcam->stats.curr_num_entrysets, tcam->stats.max_num_entrysets);
   printf("Collsets  = %"PRIu32" (peak %"PRIu32")\n", tcam->stats.curr_num_collsets, tcam->stats.max_num_collsets);
}
void
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaarelax_key(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa *mask,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaarelax_var_array *relax_key)
{
size_t i;
uint8_t *sp = (uint8_t *) &me->exact_key.word[0];
uint8_t *m = (uint8_t *) &mask->mask.word[0];
uint8_t *dp = &relax_key->key[0];
for (i = 0; i < sizeof(aaaaaaaaaaaaa1aaat); i++) {
*dp = *sp & *m;
dp++;
sp++;
m++;
}
int field;
const uint8_t num_fields = client_get_num_fields(magg->client);
for (field = 0; field < num_fields; field++) {
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc mfd;
const int rc = client_get_aaaaaaaaaaaaaaaaaa1aaa(magg->client, field, &mfd);
assert(rc == 0);
if (mfd.type != aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaR16 ||
(mask->use_range &
1 << mfd.instance) == 0)
continue;
uint16_t range = 0;
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint2bit((uint8_t *) &relax_key->key[0],
sizeof(aaaaaaaaaaaaa1aaat),
mfd.start_pos,
(uint8_t *) &range,
mfd.len);
}
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaeate_exact(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
int field;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa *mask = &me->exact_mask;
struct aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat64 t64_zero;
memset(&t64_zero, 0, sizeof(t64_zero));
struct aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaab128 b128_zero;
memset(&b128_zero, 0, sizeof(b128_zero));
const uint8_t num_fields = client_get_num_fields(magg->client);
for (field = 0; field < num_fields; field++) {
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc mfd;
int rc = client_get_aaaaaaaaaaaaaaaaaa1aaa(magg->client, field, &mfd);
assert(rc == 0);
switch (mfd.type) {
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaR16:
mask->use_range |= 1 << mfd.instance;
if (me->fields[field].r16.start == me->fields[field].r16.end) {
if (mask->max_pop < mfd.len || (mask->max_pop == mfd.len && mask->tot_pop < mfd.len)) {
mask->max_pop = mfd.len;
mask->tot_pop = mfd.len;
}
mask->active_fields |= 1 << field;
}
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaP128:
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaabits((uint8_t *) &mask->mask.word[0], sizeof(aaaaaaaaaaaaa1aaat),
mfd.start_pos + mfd.len -
me->fields[field].p128.len,
me->fields[field].p128.len);
if (me->fields[field].p128.len > 0) {
mask->active_fields |= 1 << field;
if (mask->max_pop < me->fields[field].p128.len || (mask->max_pop == me->fields[field].p128.len && mask->tot_pop < mfd.len)) {
mask->max_pop = me->fields[field].p128.len;
mask->tot_pop = mfd.len;
}
}
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaT64:
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint2bit((uint8_t *) &mask->mask.word[0], sizeof(aaaaaaaaaaaaa1aaat),
mfd.start_pos,
&me->fields[field].t64.mask[0], mfd.len);
if (memcmp(&me->fields[field].t64.mask, &t64_zero,
sizeof(t64_zero.mask)) != 0) {
mask->active_fields |= 1 << field;
uint64_t *mask64 = (uint64_t *) &me->fields[field].t64.mask[0];
uint16_t t_pop = __builtin_popcountll(*mask64);
if (mask->max_pop < t_pop || (mask->max_pop == t_pop && mask->tot_pop < mfd.len)) {
mask->max_pop = t_pop;
mask->tot_pop = mfd.len;
}
}
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaB128:
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint2bit((uint8_t *) &mask->mask.word[0], sizeof(aaaaaaaaaaaaa1aaat),
mfd.start_pos,
&me->fields[field].b128.mask[0],
mfd.len);
if (memcmp(&me->fields[field].b128.mask, &b128_zero,
sizeof(b128_zero.mask)) != 0) {
mask->active_fields |= 1 << field;
if (mask->max_pop < mfd.len || (mask->max_pop == mfd.len && mask->tot_pop < mfd.len)) {
mask->max_pop = mfd.len;
mask->tot_pop = mfd.len;
}
}
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaC128:
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaabits((uint8_t *) &mask->mask.word[0], sizeof(aaaaaaaaaaaaa1aaat),
mfd.start_pos, mfd.len);
mask->const_pop += mfd.len;
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaU128:
break;
default:
assert(0);
}
}
return 0;
}
static void
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaeate_index2field(uint32_t mask_active_fields, uint8_t * index2field)
{
int i = 0;
memset(index2field, 0, CAM_MAX_NUM_FIELDS);
while (1) {
int field = __builtin_ffs(mask_active_fields);
if (field == 0)
return;
field--;
index2field[i] = field;
mask_active_fields ^= 1 << field;
i++;
assert(i <= CAM_MAX_NUM_FIELDS);
}
}
static inline uint8_t
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaindex2field(uint8_t index2field[], int index)
{
assert(index > 0 && index <= CAM_MAX_NUM_FIELDS);
return index2field[index - 1];
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaarelax_fields(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
int i;
struct aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat64 t64_zero;
memset(&t64_zero, 0, sizeof(t64_zero));
struct aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaab128 b128_zero;
memset(&b128_zero, 0, sizeof(b128_zero));
const uint8_t num_fields = client_get_num_fields(magg->client);
for (i = 0; i < num_fields; i++) {
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc mfd;
const int rc = client_get_aaaaaaaaaaaaaaaaaa1aaa(magg->client, i, &mfd);
assert(rc == 0);
switch (mfd.type) {
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaR16:
if (me->fields[i].r16.start == me->fields[i].r16.end)
me->relax_fields |= 1 << i;
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaP128:
if (me->fields[i].p128.len > 0) {
me->relax_fields |= 1 << i;
me->multiply_fields |= 1 << i;
}
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaT64:
if (memcmp(&me->fields[i].t64.mask, &t64_zero, sizeof(t64_zero.mask)) != 0) {
me->relax_fields |= 1 << i;
me->multiply_fields |= 1 << i;
}
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaB128:
if (memcmp(&me->fields[i].b128.mask, &b128_zero, sizeof(b128_zero.mask)) != 0)
me->relax_fields |= 1 << i;
break;
default:
break;
}
}
return 0;
}
static int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa *mask)
{
if (magg->debug_mask & aaaaa1aaaDEBUG_MASK_HASH) {
       printf("      max pop %2"PRIu16" tot pop %2"PRIu32"", mask->max_pop, mask->tot_pop);
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(mask, 0);
}
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaa *tmp;
cam_free_func free_function = client_get_free_function((client_t*) (magg->client));
cam_malloc_func malloc_function = client_get_malloc_function((client_t*) (magg->client));
cam_calloc_func calloc_function = client_get_calloc_function((client_t*) (magg->client));
MH_FIND(mh_handle, me->mask_by_mask, mask, sizeof(*mask), tmp);
if (tmp)
return 0;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaa *mask_hash = calloc_function(1, sizeof(*mask_hash));
if (mask_hash == NULL)
return CAM_ERROR_NOMEM;
memcpy(&mask_hash->mask, mask, sizeof(mask_hash->mask));
MH_ADD(mh_handle, me->mask_by_mask, mask, sizeof(mask_hash->mask), mask_hash, free_function, malloc_function);
return 0;
error:
return CAM_ERROR_NOMEM;
}
static int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa mask, uint32_t remain_fields);
static int combine(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa mask, uint32_t remain_fields, uint16_t incoming_pop,
const aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc *mfd,
uint64_t working_mask,
uint64_t original_mask, uint8_t start,
uint8_t end, uint8_t index, uint8_t r) {
if (index == r) { 
if ((working_mask | original_mask) != original_mask) {
return 0;
}
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint64((uint64_t *) &mask.mask.word[0], mfd->start_pos,
(uint64_t *) &working_mask, 0, mfd->len);
mask.max_pop = MAX(incoming_pop, __builtin_popcountll(working_mask));
int rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(magg, me, mask, remain_fields);
return rc;
}
const uint64_t start_mask = working_mask;
for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
working_mask = start_mask | (((const uint64_t) 1) << i); 
int rc = combine(magg, me, mask, remain_fields, incoming_pop, mfd,
working_mask, original_mask,
i + 1, end, index + 1, r);
if (rc)
return rc;
}
return 0;
}
static uint64_t fact(uint8_t n) {
uint64_t res = 1;
for (uint8_t i = 2; i <= n; i++)
res = res * i;
return res;
}
static uint64_t nCr(uint8_t n, uint8_t r) {
assert(r <= n);
return fact(n) / (fact(r) * fact(n - r));
}
uint64_t aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaacalc_num_combinations(uint8_t len,
uint8_t max_num_ones) {
uint64_t sum = 0;
for (uint8_t i = 1; i <= max_num_ones; i++) {
sum = sum + nCr(len, i);
}
if (max_num_ones < len) {
sum++; 
}
return sum;
}
#define MAX_ONES 8
uint8_t aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaacalc_num_ones(uint8_t field_len, uint16_t max_combinations) {
bool break_out = false;
uint8_t num_ones;
uint8_t max_num_ones = MAX_ONES;
if (field_len < MAX_ONES)
max_num_ones = field_len;
for (num_ones = 1; num_ones <= max_num_ones; num_ones++) {
uint64_t num_combinations = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaacalc_num_combinations(field_len,
num_ones);
if (num_combinations > max_combinations) {
break_out = true;
break;
}
}
if (!break_out)
return max_num_ones;
return num_ones - 1;
}
static int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa mask, uint32_t remain_fields)
{
uint16_t incoming_pop = mask.max_pop;
uint16_t incoming_tot = mask.tot_pop;
int i, rc;
if (remain_fields == 0) {
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(magg, me, &mask);
return rc;
}
int8_t field = __builtin_ffs(remain_fields) - 1;
remain_fields = remain_fields ^ (1 << field);
if (magg->debug_mask & aaaaa1aaaDEBUG_MASK_HASH)
       printf("    MULT field %"PRIi8" remain %0"PRIx32"\n", field, remain_fields);
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc mfd;
rc = client_get_aaaaaaaaaaaaaaaaaa1aaa(magg->client, field, &mfd);
assert(rc == 0);
switch (mfd.type) {
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaP128: {
uint8_t step = (mfd.len + magg->set_expansion.num_relaxed_prefixes - 1)
/ magg->set_expansion.num_relaxed_prefixes;
int16_t pre_start = mfd.len % step;
if (pre_start == 0) {
pre_start = step;
}
for (i = pre_start; i <= me->fields[field].p128.len; i += step) {
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaabits((uint8_t *) &mask.mask.word[0], sizeof(aaaaaaaaaaaaa1aaat),
mfd.start_pos + mfd.len - i, i);
if (incoming_pop < i || (incoming_pop == i && incoming_tot < mfd.len)) {
mask.max_pop = i;
mask.tot_pop = mfd.len;
}
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(magg, me, mask, remain_fields);
if (rc)
return rc;
}
break;
}
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaT64: {
uint64_t mask64;
memcpy(&mask64, &me->fields[field].t64.mask[0], sizeof(mask64));
uint8_t pop = __builtin_popcountll(mask64);
if (pop == 0)
break;
uint8_t num_ones = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaacalc_num_ones(mfd.len,
magg->set_expansion.num_ternary_permutations);
if (num_ones != mfd.len) {
rc = combine(magg, me, mask, remain_fields, incoming_pop, &mfd, 0,
mask64, 0,
mfd.len - 1, 0, mfd.len);
if (rc)
return rc;
}
for (uint8_t r = 1; r <= num_ones; r++) {
uint64_t t = 0;
rc = combine(magg, me, mask, remain_fields, incoming_pop, &mfd, t,
mask64,
0,
mfd.len-1, 0, r);
if (rc)
return rc;
}
break;
}
default:
assert(0);
}
return 0;
}
static void
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaa5aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa *mask, uint8_t field)
{
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc mfd;
const int rc = client_get_aaaaaaaaaaaaaaaaaa1aaa(magg->client, field, &mfd);
assert(rc == 0);
switch (mfd.type) {
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaR16:
mask->use_range ^= 1 << mfd.instance;
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaabits((uint8_t *) &mask->mask.word[0], sizeof(aaaaaaaaaaaaa1aaat),
mfd.start_pos, mfd.len);
if (mask->max_pop < 16 || (mask->max_pop == 16 && mask->tot_pop < 16)) {
mask->max_pop = 16;
mask->tot_pop = 16;
}
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaP128:
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaT64:
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaB128:
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint2bit((uint8_t *) &mask->mask.word[0], sizeof(aaaaaaaaaaaaa1aaat),
mfd.start_pos,
&me->fields[field].b128.mask[0],
mfd.len);
if (mask->max_pop < mfd.len || (mask->max_pop == mfd.len && mask->tot_pop < mfd.len)) {
mask->max_pop = mfd.len;
mask->tot_pop = mfd.len;
}
break;
default:
assert(0);
}
mask->active_fields |= 1 << field;
}
static int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaacombine(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa in_mask, uint8_t index2field[],
int n, int k)
{
int i, rc;
if (magg->debug_mask & aaaaa1aaaDEBUG_MASK_HASH)
       printf("  COMB n %d k %d\n", n, k);
for (i = n; i >= k; i--) {
if (k > 1) {
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa out_mask = in_mask;
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaa5aaa(magg, me, &out_mask,
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaindex2field(index2field, i));
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaacombine(magg, me, out_mask, index2field, i - 1,
k - 1);
if (rc)
return rc;
} else {
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa out_mask = in_mask;
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaa5aaa(magg, me, &out_mask,
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaindex2field(index2field, i));
if ((out_mask.active_fields & me->multiply_fields) == 0) {
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(magg, me, &out_mask);
if (rc)
return rc;
} else {
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(magg, me, out_mask,
out_mask.active_fields & me->multiply_fields);
if (rc)
return rc;
}
}
}
return 0;
}
static void
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaamandatory_fields(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa *mask)
{
int field;
const uint8_t num_fields = client_get_num_fields(magg->client);
for (field = 0; field < num_fields; field++) {
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc mfd;
const int rc = client_get_aaaaaaaaaaaaaaaaaa1aaa(magg->client, field, &mfd);
assert(rc == 0);
switch (mfd.type) {
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaR16:
mask->use_range |= 1 << mfd.instance;
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaP128:
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaC128:
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaabits((uint8_t*) &mask->mask.word[0], sizeof(aaaaaaaaaaaaa1aaat),
mfd.start_pos, mfd.len);
mask->const_pop += mfd.len;
break;
default:
break;
}
}
}
static int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaasort(void *a, void *b)
{
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaa *ha = (struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaa *) a;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaa *hb = (struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaa *) b;
if (__builtin_popcount(ha->mask.active_fields) > __builtin_popcount(hb->mask.active_fields))
return 1;
if (__builtin_popcount(ha->mask.active_fields) < __builtin_popcount(hb->mask.active_fields))
return -1;
if (ha->mask.max_pop < hb->mask.max_pop)
return 1;
if (ha->mask.max_pop > hb->mask.max_pop)
return -1;
if (ha->mask.tot_pop < hb->mask.tot_pop)
return 1;
if (ha->mask.tot_pop > hb->mask.tot_pop)
return -1;
return 0;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaeate_hash(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
int k, rc;
if (me->mask_by_mask)
return 0;
uint8_t index2field[CAM_MAX_NUM_FIELDS];
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaeate_index2field(me->relax_fields, &index2field[0]);
int num_fields_set = __builtin_popcount(me->relax_fields);
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa mask_template;
memset(&mask_template, 0, sizeof(mask_template));
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaamandatory_fields(magg, &mask_template);
for (k = 1; k <= magg->set_expansion.k_combinations; k++) {
if (magg->debug_mask & aaaaa1aaaDEBUG_MASK_HASH)
           printf("K-COMB %d\n", k);
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa mask = mask_template;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaacombine(magg, me, mask, index2field, num_fields_set, k);
if (rc)
goto error;
}
if (me->mask_by_mask == NULL)
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(magg, me, &mask_template);
MH_SORT(me->mask_by_mask, aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaasort);
return 0;
error:
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaabaaaaaaaaaa5aaa(magg, me);
return rc;
}
void
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaabaaaaaaaaaa5aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaa *mfh, *mfh_tmp;
MH_ITER(mh_handle, me->mask_by_mask, mfh, mfh_tmp)
{
cam_free_func free_function = client_get_free_function((client_t*) (magg->client));
MH_DELETE(mh_handle, me->mask_by_mask, mfh, free_function);
free_function(mfh);
}
me->mask_by_mask = NULL;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaabaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaamember(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa *mask,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaa *mfh;
assert(me->mask_by_mask);
MH_FIND(mh_handle, me->mask_by_mask, mask, sizeof(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa), mfh);
return mfh != NULL;
}
uint32_t
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaavalue(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa *mask)
{
uint32_t num_bkts = 1;
uint32_t hashv;
uint32_t bkt;
murmur3_bucket(mask, sizeof(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa), num_bkts, &hashv, &bkt);
bkt--;
return hashv;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaainstance(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa *mask,
uint8_t * instance)
{
int i;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaainstance *mai;
cam_calloc_func calloc_function = client_get_calloc_function(magg->client);
MH_FIND(mh_handle, magg->mask_instances_by_mask, mask, sizeof(*mask), mai);
if (mai == NULL) {
mai = calloc_function(1, sizeof(*mai));
if (mai == NULL)
return CAM_ERROR_NOMEM;
mai->mask = *mask;
cam_free_func free_function = client_get_free_function((client_t*) (magg->client));
cam_malloc_func malloc_function = client_get_malloc_function((client_t*) (magg->client));
MH_ADD(mh_handle, magg->mask_instances_by_mask, mask, sizeof(*mask), mai, free_function, malloc_function);
}
for (i = 0; i < aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaRESVD_INSTANCE; i++) {
if ((mai->instances[i / 8] & (1 << i % 8)) == 0) {
mai->instances[i / 8] |= 1 << i % 8;
*instance = i;
if (magg->debug_mask & aaaaa1aaaDEBUG_INSTANCE)
               printf("MASK INST GET %p hash %"PRIx32" instance %"PRIu8"\n", (void *) mask,
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaavalue(mask), *instance);
return 0;
}
}
return CAM_ERROR_TOO_MANY_INSTANCES;
error:;
cam_free_func free_function = client_get_free_function((client_t*) (magg->client));
free_function(mai);
return CAM_ERROR_NOMEM;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaput_instance(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa *mask,
uint8_t instance)
{
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaainstance *mai;
if (magg->debug_mask & aaaaa1aaaDEBUG_INSTANCE)
       printf("MASK INST PUT %p hash %"PRIx32" instance %"PRIu8"\n", (void *) mask,
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaavalue(mask), instance);
MH_FIND(mh_handle, magg->mask_instances_by_mask, mask, sizeof(*mask), mai);
assert(mai != NULL);
assert((mai->instances[instance / 8] & (1 << instance % 8)) != 0);
mai->instances[instance / 8] &= ~(1 << instance % 8);
return 0;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaabaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaainstances(struct tcam *magg)
{
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaainstance *mai, *mai_tmp;
MH_ITER(mh_handle, magg->mask_instances_by_mask, mai, mai_tmp)
{
cam_free_func free_function = client_get_free_function((client_t*) (magg->client));
MH_DELETE(mh_handle, magg->mask_instances_by_mask, mai, free_function);
free_function(mai);
}
return 0;
}
void
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa *mask, int indent)
{
size_t i;
   printf("%*cM %x : ", indent, ' ', mask->use_range);
for (i = 0; i < sizeof(aaaaaaaaaaaaa1aaat); i++) {
       printf("%02x ", *(((char *) &mask->mask.word[0]) + i) & 0xff);
if (i && (i + 1) % 8 == 0)
           printf(": ");
}
   printf("\n");
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem)
{
(void) magg;
memset(problem, 0, sizeof(*problem));
return 0;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa5aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem)
{
int rc;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes, *tmp;
LIST_FOREACH_SAFE2(problem->entryset_by_mask, mes, tmp, mh_handle.next)
{
rc = aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa5aaa(magg, problem, mes);
if (rc)
return rc;
}
return 0;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
int rc;
if (problem->is_solved) {
rc = aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaasolved(magg, problem, me);
if (rc)
return rc;
} else {
rc = aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaopen(magg, problem, me);
if (rc)
return rc;
}
return 0;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
int rc;
if (problem->is_solved) {
rc = aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaasolved(magg, problem, me);
if (rc)
return rc;
} else {
rc = aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaopen(magg, problem, me);
if (rc)
return rc;
}
problem->num_entries--;
return 0;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaareset(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem)
{
int rc;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes;
assert(problem->is_solved == 0);
LIST_FOREACH2(problem->entryset_by_mask, mes, mh_handle.next)
{
rc = aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaareset(magg, mes);
if (rc)
return rc;
}
LIST_FOREACH2(magg->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaby_fields, me, mh_handle.next)
me->allocated = 0;
return 0;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaawinner(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa **out_mes)
{
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes;
*out_mes = NULL;
uint32_t max_weight = 0;
uint16_t max_pop = 0;
LIST_FOREACH2(problem->entryset_by_mask, mes, mh_handle.next)
{
if (mes->remaining_weight < max_weight)
continue;
if (mes->remaining_weight == max_weight) {
const uint16_t max_entries_per_unit = client_get_num_entries_per_unit(magg->client);
if (mes->remaining_weight > max_entries_per_unit &&
mes->mask.max_pop >= max_pop)
continue;
if (mes->remaining_weight < max_entries_per_unit &&
mes->mask.max_pop <= max_pop)
continue;
}
*out_mes = mes;
max_weight = mes->remaining_weight;
max_pop = mes->mask.max_pop;
}
return 0;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaareduce(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
(void) problem;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa **collsetp;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes;
for (collsetp = (struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa **) array_front(me->collsets);
collsetp;
collsetp =
(struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa **) array_next(me->collsets, collsetp)) {
mes = (*collsetp)->entryset;
mes->remaining_entries--;
(*collsetp)->remaining_entries--;
if ((*collsetp)->remaining_entries < magg->max_num_collisions)
mes->remaining_weight -= aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaWEIGHT;
}
return 0;
}
static int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaasort(void *a, void *b)
{
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *ma = (struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *) a;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mb = (struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *) b;
if (ma->weight < mb->weight)
return 1;
if (ma->weight > mb->weight)
return -1;
return 0;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
int indent)
{
   printf("%*caaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa %p is_solved %u num_entries %u\n", indent, ' ',
(void *) problem, problem->is_solved, problem->num_entries);
if (!(magg->debug_mask & aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaabaaaaaaaaaaa5bbbbbbbbbbbbbbbbbb5aaa))
return 0;
MH_SORT(problem->entryset_by_mask, aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaasort);
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes;
LIST_FOREACH2(problem->entryset_by_mask, mes, mh_handle.next)
aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(magg, mes, indent + 2);
return 0;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa **out_probsol)
{
int rc;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol;
cam_calloc_func calloc_function = client_get_calloc_function((client_t*) (magg->client));
probsol = calloc_function(1, sizeof(*probsol));
if (probsol == NULL)
return CAM_ERROR_NOMEM;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate(magg, &probsol->problem);
if (rc)
goto error;
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate(magg, &probsol->curr_solution);
if (rc)
goto error;
*out_probsol = probsol;
return 0;
error:;
cam_free_func free_function = client_get_free_function((client_t*) (magg->client));
free_function(probsol);
return rc;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa5aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol)
{
int rc;
cam_free_func free_function = client_get_free_function((client_t*) (magg->client));
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa5aaa(magg, &probsol->curr_solution);
if (rc)
return rc;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa5aaa(magg, &probsol->problem);
if (rc)
return rc;
free_function(probsol);
return 0;
}
static int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaopen2solved(struct tcam *magg,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *open,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *solved,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli)
{
int rc;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes;
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa *meli;
magg->stats.curr_closed_masks++;
magg->stats.max_closed_masks = MAX(magg->stats.curr_closed_masks, magg->stats.max_closed_masks);
magg->stats.curr_open_masks = magg->num_masks - magg->stats.curr_closed_masks;
rc = aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate(magg, &solved->problem,
&mesli->entryset->mask, &mes);
if (rc)
return rc;
if (magg->debug_mask & aaaaa1aaaDEBUG_ENTRYSET) {
       printf("MASK open -> solved from %p to %p hash %"PRIx32" instance %"PRIu8" num_entries %"PRIu16"\n",
(void *) &mesli->entryset->mask, (void *) &mes->mask,
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaavalue(&mes->mask), mesli->instance,
mesli->num_entries);
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(&mes->mask, 2);
}
mesli->entryset = mes;
LIST_FOREACH(mesli->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa, meli)
{
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(magg, &open->problem, meli->entry);
if (rc)
return rc;
rc = aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg, &solved->problem, mes, meli->entry);
if (rc)
return rc;
solved->problem.num_entries++;
meli->entry->current_entryset.mes = mes;
}
LIST_DELETE(open->curr_solution.mask_list, mesli);
open->curr_solution.num_masks--;
LIST_APPEND(solved->curr_solution.mask_list, mesli);
solved->curr_solution.num_masks++;
return 0;
}
static int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaabaaaaaaaaaaa5aaa2solved(struct tcam *magg,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *open,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *solved)
{
int rc;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *prev_mes = NULL;
uint8_t prev_instance = 0;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaeate_hash(magg, me);
if (rc)
return rc;
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa(magg, solved, me, &mesli);
if (rc)
goto error;
if (mesli == NULL)
goto done;
rc = aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg, &solved->problem, mesli->entryset, me);
if (rc)
goto error;
solved->problem.num_entries++;
prev_mes = me->current_entryset.mes;
prev_instance = me->current_entryset.instance;
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg, mesli, me);
if (rc)
goto error;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(magg, me, prev_mes, prev_instance);
if (rc)
goto error;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *prev_mesli;
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(magg, &open->curr_solution, me, &prev_mesli);
if (rc)
goto error;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(magg, &open->problem, me);
if (rc)
goto error;
done:
error:
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaabaaaaaaaaaa5aaa(magg, me);
return rc;
}
static int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaall_entries2solved(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *open,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *solved)
{
int rc;
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa *meli, *meli_tmp;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli, *mesli_tmp;
LIST_FOREACH_SAFE(open->curr_solution.mask_list, mesli, mesli_tmp)
{
LIST_FOREACH_SAFE(mesli->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa, meli, meli_tmp)
{
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaabaaaaaaaaaaa5aaa2solved(magg, meli->entry, open, solved);
if (rc)
return rc;
}
}
return 0;
}
static int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaopen(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
int rc;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg, &probsol->problem, me);
if (rc)
return rc;
probsol->problem.num_entries++;
if (mesli == NULL) {
MH_FIND(mh_handle, probsol->problem.entryset_by_mask, &me->mask_by_mask->mask, sizeof(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa), mes);
assert(mes);
assert(me->mask_by_mask->mh_handle.prev == NULL);
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6bbbbbbbbbbbbbbbbbb6aaa(magg, probsol, mes, &mesli);
if (rc)
return rc;
}
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg, mesli, me);
if (rc)
return rc;
if (mesli->num_entries == client_get_num_entries_per_unit(magg->client)) {
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *solved;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate(magg, &solved);
if (rc)
return rc;
solved->is_solved = 1;
solved->problem.is_solved = 1;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaopen2solved(magg, probsol, solved, mesli);
if (rc)
return rc;
LIST_PREPEND_ELEM(magg->probsols, magg->open_probsol, solved);
}
return 0;
}
static int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaasolved(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
int rc;
assert(mesli != NULL);
rc = aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg, &probsol->problem, mesli->entryset, me);
if (rc)
return rc;
probsol->problem.num_entries++;
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg, mesli, me);
if (rc)
return rc;
return 0;
}
static int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaabest(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa **out_probsol,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa **out_mesli)
{
int rc;
const uint8_t max_entries_per_unit_bits = 32
- __builtin_clz((uint32_t) client_get_num_entries_per_unit(magg->client));
int bits;
int64_t space_left;
int64_t best_space = -1;
int best_pop = -1;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *best_probsol = NULL;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *best_mesli = NULL;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol;
LIST_FOREACH(magg->probsols, probsol)
{
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli;
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa(magg, probsol, me, &mesli);
if (rc)
return rc;
if (mesli == NULL)
continue;
bits = MIN(mesli->entryset->mask.const_pop, max_entries_per_unit_bits) +
mesli->entryset->mask.max_pop;
if (bits > 62)
bits = 62;
space_left = ((int64_t) 1 << bits) - mesli->num_entries;
if (space_left > best_space ||
(space_left == best_space && mesli->entryset->mask.max_pop > best_pop)) {
best_mesli = mesli;
best_probsol = probsol;
best_pop = mesli->entryset->mask.max_pop;
best_space = space_left;
}
}
if (best_mesli) {
*out_probsol = best_probsol;
*out_mesli = best_mesli;
} else {
*out_probsol = NULL;
*out_mesli = NULL;
}
return 0;
}
static int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaacompare(const void* a, const void* b)
{
int int_a = * ( (int*) a );
int int_b = * ( (int*) b );
if (int_a == int_b)
return 0;
else if (int_a > int_b)
return -1;
else
return 1;
}
static int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaatransform(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *open,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *solved, int force)
{
int rc;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli, *mesli_tmp;
const uint16_t max_num_masks = client_get_num_units(magg->client) - 1;
int max_entries[max_num_masks];
for (int i = 0; i < max_num_masks; i++)
max_entries[i] = 0;
int i = 0;
LIST_FOREACH_SAFE(open->curr_solution.mask_list, mesli, mesli_tmp)
{
max_entries[i] = mesli->num_entries;
i++;
}
qsort(max_entries, max_num_masks, sizeof(int), aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaacompare);
const uint16_t max_entries_per_unit = client_get_num_entries_per_unit(magg->client);
if (max_entries[0] == max_entries_per_unit) {
force = 0;
} else if (max_entries[0] < max_entries_per_unit && force <= 0) {
return 0;
}
int delete_limit = force > 0 ? max_entries[force-1] : max_entries[0];
int delete_count = 0;
LIST_FOREACH_SAFE(open->curr_solution.mask_list, mesli, mesli_tmp)
{
#if 1
if (mesli->num_entries < delete_limit)
continue;
#endif
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaopen2solved(magg, open, solved, mesli);
if (rc)
return rc;
if (force > 0) {
delete_count++;
if (force == delete_count)
return 0;
}
}
return 0;
}
#ifdef aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa
static int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa **out_probsol,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa **out_mesli,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa **out_me)
{
int rc;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *best_me = me;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *best_mesli = NULL;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *best_probsol = NULL;
int best_fields = __builtin_popcount(me->exact_mask.active_fields);
int best_max_pop = me->exact_mask.max_pop;
int best_tot_pop = me->exact_mask.tot_pop;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol;
LIST_FOREACH(magg->probsols, probsol) {
if (!probsol->is_solved)
continue;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli;
LIST_FOREACH(probsol->curr_solution.mask_list, mesli) {
if (mesli->num_entries != client_get_num_entries_per_unit(magg->client) ||
!aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaabaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaamember(&mesli->entryset->mask, me))
continue;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset;
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaafind(magg, mesli->entryset, me, &collset);
if (rc) {
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa *meli;
LIST_FOREACH(mesli->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa, meli) {
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaame = meli->entry;
int num_fields =
__builtin_popcount(aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaame->exact_mask.active_fields);
if (num_fields < best_fields)
continue;
if (num_fields == best_fields) {
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaame->exact_mask.max_pop < best_max_pop)
continue;
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaame->exact_mask.max_pop == best_max_pop &&
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaame->exact_mask.tot_pop < best_tot_pop)
continue;
}
best_fields = num_fields;
best_max_pop = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaame->exact_mask.max_pop;
best_tot_pop = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaame->exact_mask.tot_pop;
best_me = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaame;
best_mesli = mesli;
best_probsol = probsol;
}
} else {
uint16_t id = collset->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas.data[0].id;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaame = magg->entries[id];
int num_fields =
__builtin_popcount(aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaame->exact_mask.active_fields);
if (num_fields < best_fields)
continue;
if (num_fields == best_fields) {
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaame->exact_mask.max_pop < best_max_pop)
continue;
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaame->exact_mask.max_pop == best_max_pop &&
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaame->exact_mask.tot_pop < best_tot_pop)
continue;
}
best_fields = num_fields;
best_max_pop = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaame->exact_mask.max_pop;
best_tot_pop = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaame->exact_mask.tot_pop;
best_me = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaame;
best_mesli = mesli;
best_probsol = probsol;
}
}
}
if (best_me != me) {
*out_probsol = best_probsol;
*out_mesli = best_mesli;
*out_me = best_me;
} else {
*out_probsol = NULL;
*out_mesli = NULL;
*out_me = NULL;
}
return 0;
}
static int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadel_cuckoo(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
int rc;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg, me, mesli->entryset,
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaRESVD_INSTANCE, NULL);
if (rc)
return rc;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(magg, me, mesli->entryset,
mesli->instance);
if (rc)
return rc;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *tmp_mesli;
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(magg, &probsol->curr_solution,
me, &tmp_mesli);
if (rc)
return rc;
assert(tmp_mesli != NULL);
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(magg, &probsol->problem, me);
if (rc)
return rc;
return 0;
}
static int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb5aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
int rc;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli;
const uint16_t max_num_masks = client_get_num_units(magg->client) - 1;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaeate_hash(magg, me);
if (rc)
return rc;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaabest(magg, me, &probsol, &mesli);
if (rc)
goto error;
if (probsol == NULL) {
if (max_num_masks - magg->num_masks - 1 < 0) {
rc = CAM_ERROR_TOO_MANY_MASKS;
assert(0);
} else {
probsol = magg->open_probsol;
mesli = NULL;
}
}
if (probsol->is_solved) {
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaasolved(magg, probsol, mesli, me);
if (rc)
goto error;
} else {
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaopen(magg, probsol, mesli, me);
if (rc)
goto error;
}
error:
(void) aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaabaaaaaaaaaa5aaa(magg, me);
return 0;
}
#endif
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
int rc;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol;
const uint16_t max_num_masks = client_get_num_units(magg->client) - 1;
if (magg->do_refill) {
magg->do_refill = 0;
LIST_FOREACH(magg->probsols, probsol)
{
if (probsol->do_refill) {
probsol->do_refill = 0;
if (probsol->is_solved) {
if (magg->num_masks + magg->open_probsol->curr_solution.num_masks >
max_num_masks / 2) {
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaall_entries2solved(magg, magg->open_probsol,
probsol);
if (rc) {
return rc;
}
}
}
}
}
}
probsol = NULL;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli = NULL;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaeate_hash(magg, me);
if (rc)
return rc;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaabest(magg, me, &probsol, &mesli);
if (rc)
return rc;
#ifdef aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaame = NULL;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaames;
if (probsol == NULL) {
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaamesli;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(magg, me, &aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, &aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaamesli,
&aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaame);
if (rc)
return rc;
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaame) {
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaames = *aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaamesli->entryset;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadel_cuckoo(magg, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaamesli,
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaame);
if (rc)
return rc;
probsol = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa;
mesli = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaamesli;
}
}
#endif
bool new_mask_added = false;
if (probsol == NULL) {
if (max_num_masks - magg->num_masks - 1 < 0) {
rc = CAM_ERROR_NO_MASK;
goto error;
} else {
probsol = magg->open_probsol;
mesli = NULL;
new_mask_added = true;
}
}
if (probsol->is_solved) {
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaasolved(magg, probsol, mesli, me);
if (rc)
goto error;
} else {
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaopen(magg, probsol, mesli, me);
if (rc) {
goto error;
}
}
#ifdef aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaame != NULL) {
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb5aaa(magg, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaame);
if (rc)
return rc;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(magg, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaame, &aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaames,
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaRESVD_INSTANCE);
if (rc)
return rc;
}
#endif
if (!probsol->is_solved) {
const uint16_t number_of_free_masks = max_num_masks - magg->num_masks;
if (!new_mask_added || (magg->open_probsol->curr_solution.num_masks + 1 <
number_of_free_masks))
goto done;
int deficit_masks = magg->open_probsol->curr_solution.num_masks - number_of_free_masks;
if (deficit_masks > 0) {
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *solved;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate(magg, &solved);
if (rc)
return rc;
solved->is_solved = 1;
solved->problem.is_solved = 1;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaatransform(magg, magg->open_probsol, solved,
deficit_masks);
if (rc)
return rc;
LIST_PREPEND_ELEM(magg->probsols, magg->open_probsol, solved);
}
if (magg->open_probsol->curr_solution.num_masks > 1) {
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg);
if (rc)
goto error;
}
}
done:
error:
(void) aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaabaaaaaaaaaa5aaa(magg, me);
return rc;
}
static int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaasolved2open(struct tcam *magg,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *solved,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *open,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli)
{
magg->stats.curr_closed_masks--;
magg->stats.curr_open_masks = magg->num_masks - magg->stats.curr_closed_masks;
magg->stats.max_open_masks = MAX(magg->stats.curr_open_masks, magg->stats.max_open_masks);
int rc;
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa *meli;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa solved_mask = mesli->entryset->mask;
LIST_FOREACH(mesli->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa, meli)
{
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaeate_hash(magg, meli->entry);
if (rc)
return rc;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg, &open->problem, meli->entry);
if (rc)
return rc;
open->problem.num_entries++;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(magg, &solved->problem, meli->entry);
if (rc)
return rc;
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaabaaaaaaaaaa5aaa(magg, meli->entry);
}
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes;
MH_FIND(mh_handle, open->problem.entryset_by_mask, &solved_mask, sizeof(solved_mask), mes);
assert(mes);
if (magg->debug_mask & aaaaa1aaaDEBUG_ENTRYSET) {
       printf("MASK solved -> open from %p to %p hash %"PRIx32" instance %"PRIu8" num_entries %"PRIu16"\n",
(void *) &mesli->entryset->mask, (void *) &mes->mask,
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaavalue(&mes->mask), mesli->instance,
mesli->num_entries);
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(&mes->mask, 2);
}
mesli->entryset = mes;
LIST_FOREACH(mesli->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa, meli)
{
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset;
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaafind(magg, mes, meli->entry, &collset);
assert(rc == 0);
meli->entry->current_entryset.mes = mes;
meli->entry->current_entryset.collset = collset;
}
LIST_DELETE(solved->curr_solution.mask_list, mesli);
solved->curr_solution.num_masks--;
LIST_APPEND(open->curr_solution.mask_list, mesli);
open->curr_solution.num_masks++;
return 0;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
int rc;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli;
uint16_t min_entries = UINT16_MAX;
const uint16_t max_num_masks = client_get_num_units(magg->client) - 1;
LIST_FOREACH(magg->probsols, probsol)
{
LIST_FOREACH(probsol->curr_solution.mask_list, mesli)
{
if (probsol->is_solved && mesli->num_entries < min_entries)
min_entries = mesli->num_entries;
}
}
min_entries = MIN(min_entries, 3 * max_num_masks / 4);
LIST_FOREACH(magg->probsols, probsol)
{
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(magg, &probsol->curr_solution, me, &mesli);
if (rc == 0)
break;
}
assert(probsol!=NULL); 
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(magg, &probsol->problem, me);
if (rc)
return rc;
if (probsol->is_solved && mesli && (mesli->num_entries < min_entries)) {
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaasolved2open(magg, probsol, magg->open_probsol, mesli);
if (rc) {
return rc;
}
int cnt = 0;
LIST_aaaaaaaaaaaaaaaaaaaaaaaa1aaa(probsol->curr_solution.mask_list, mesli, cnt);
if (cnt == 0) {
LIST_DELETE(magg->probsols, probsol);
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa5aaa(magg, probsol);
if (rc) {
return rc;
}
}
} else {
if (probsol->is_solved)
probsol->do_refill = 1;
magg->do_refill = 1;
}
return 0;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(struct tcam *magg)
{
int rc;
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *open = magg->open_probsol;
const uint16_t max_num_masks = client_get_num_units(magg->client) - 1;
if (magg->debug_mask & aaaaa1aaaDEBUG_PROBSOL) {
       printf("Total entries %3u, closed entries %3d, open entries %3u\n",
magg->num_entries, magg->num_entries - open->problem.num_entries,
open->problem.num_entries);
       printf("Problem  with %3u entries in %2u masks, total masks %2u, free masks %2d\n",
open->problem.num_entries, open->curr_solution.num_masks,
magg->num_masks, max_num_masks - magg->num_masks);
}
aaaaa1aaadebug_print(magg, 0);
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg, open, max_num_masks - magg->num_masks - 1);
if (rc && rc != 1)
return rc;
if (magg->debug_mask & aaaaa1aaaDEBUG_PROBSOL)
       printf("Solution with %3u entries in %2u masks, total masks %2u, free masks %2d %s\n",
open->problem.num_entries, open->curr_solution.num_masks,
magg->num_masks,
max_num_masks - magg->num_masks,
              rc == 0 ? "committed" : "discarded");
return 0;
}
int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol, int indent)
{
   printf("%*caaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa %p is_solved %u\n", indent, ' ',
(void *) probsol, probsol->is_solved);
if (!(magg->debug_mask & aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa))
return 0;
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(magg, &probsol->problem, indent + 2);
return 0;
}
int
aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate(struct tcam *magg, struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *solution)
{
memset(solution, 0, sizeof(*solution));
const uint32_t max_num_entries = client_get_num_entries(magg->client);
memset(magg->oparray, 0, max_num_entries);
return 0;
}
int
aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa5aaa(struct tcam *magg, struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *solution)
{
int rc;
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa *meli, *meli_tmp;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli, *mesli_tmp;
cam_free_func free_function = client_get_free_function((client_t*) (magg->client));
LIST_FOREACH_SAFE(solution->mask_list, mesli, mesli_tmp)
{
LIST_FOREACH_SAFE(mesli->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa, meli, meli_tmp)
{
LIST_DELETE(mesli->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa, meli);
free_function(meli);
}
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaput_instance(magg, &mesli->entryset->mask,
mesli->instance);
if (rc)
return rc;
LIST_DELETE(solution->mask_list, mesli);
free_function(mesli);
}
memset(solution, 0, sizeof(*solution));
return 0;
}
static int
aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *problem,
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *solution,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes,
uint16_t * num_populated, uint8_t * instance)
{
int rc;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli;
cam_calloc_func calloc_function = client_get_calloc_function((client_t*) (magg->client));
mesli = calloc_function(1, sizeof(*mesli));
if (mesli == NULL)
return CAM_ERROR_NOMEM;
LIST_APPEND(solution->mask_list, mesli);
mesli->entryset = mes;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaainstance(magg, &mes->mask, &mesli->instance);
if (rc)
return rc;
*instance = mesli->instance;
rc = aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapopulate(magg, mes, mesli, num_populated);
if (rc)
return rc;
mesli->num_entries = *num_populated;
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa *meli;
LIST_FOREACH(mesli->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa, meli)
{
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaareduce(magg, problem, meli->entry);
if (rc)
return rc;
}
return 0;
}
static int
aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol)
{
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaop *op;
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa *meli;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli;
LIST_FOREACH(probsol->prev_solution.mask_list, mesli)
{
LIST_FOREACH(mesli->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa, meli)
{
op = &magg->oparray[meli->entry->id];
op->src_op = aaaaa1aaaOP_DEL;
op->src_entryset = mesli->entryset;
op->src_instance = mesli->instance;
}
}
LIST_FOREACH(probsol->curr_solution.mask_list, mesli)
{
LIST_FOREACH(mesli->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa, meli)
{
op = &magg->oparray[meli->entry->id];
op->dst_op = aaaaa1aaaOP_ADD;
op->dst_entryset = mesli->entryset;
op->dst_instance = mesli->instance;
op->dst_collset = meli->entry->next_entryset.collset;
}
}
return 0;
}
static int
aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaasort_cmp(struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *a,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *b)
{
if (a->weight < b->weight)
return -1;
if (a->weight == b->weight)
return 0;
return 1;
}
static int
aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaasort(struct tcam *magg, struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *solution)
{
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa *meli;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaop *op;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli;
LIST_FOREACH(solution->mask_list, mesli)
{
mesli->weight = 0;
LIST_FOREACH(mesli->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa, meli)
{
op = &magg->oparray[meli->entry->id];
if (op->src_op == aaaaa1aaaOP_DEL &&
op->dst_op == aaaaa1aaaOP_ADD &&
memcmp(&op->src_entryset->mask, &op->dst_entryset->mask,
sizeof(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa)) == 0 &&
op->src_instance == op->dst_instance) {
op->dst_op = aaaaa1aaaOP_NOP;
op->src_op = aaaaa1aaaOP_NOP;
}
if (op->dst_op == aaaaa1aaaOP_ADD)
mesli->weight++;
}
}
LIST_SORT(solution->mask_list, aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaasort_cmp);
if (magg->debug_mask & aaaaa1aaaDEBUG_OPARRAY) {
LIST_FOREACH(solution->mask_list, mesli)
{
LIST_FOREACH(mesli->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa, meli)
{
op = &magg->oparray[meli->entry->id];
if (op->dst_op == aaaaa1aaaOP_NOP && op->src_op == aaaaa1aaaOP_NOP)
continue;
               printf("O %05u : %u %p %3u: %u %p %3u\n",
meli->entry->id,
op->src_op, (void *) op->src_entryset, op->src_instance,
op->dst_op, (void *) op->dst_entryset, op->dst_instance);
}
}
}
return 0;
}
static int
aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbbbbbbbbbbbbbbb5aaa(struct tcam *magg,
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *solution,
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa *outer_meli,
int *out_added)
{
int rc = 0, added = 0;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaop *op;
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa *meli;
LIST_FOREACH(solution->collision_list, meli)
{
if (meli == outer_meli || meli->entry == NULL)
continue;
op = &magg->oparray[meli->entry->id];
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg, meli->entry,
op->dst_entryset, op->dst_instance, op->dst_collset);
if (rc == CAM_ERROR_DUPLICATE_FOUND)
continue;
if (rc)
goto error;
if (op->src_op == aaaaa1aaaOP_DEL) {
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(magg, meli->entry, op->src_entryset,
op->src_instance);
if (rc)
goto error;
}
meli->entry = NULL;
added++;
}
rc = 0;
error:
(*out_added) = added;
return rc;
}
static int
aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbbbbbbbbbbbbbbb5aaa(struct tcam *magg,
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *solution)
{
int rc = 0;
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa *meli;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaop *op;
LIST_FOREACH(solution->collision_list, meli)
{
if (meli->entry == NULL)
continue;
op = &magg->oparray[meli->entry->id];
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg, meli->entry, op->dst_entryset,
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaRESVD_INSTANCE, op->dst_collset);
if (rc)
goto error;
magg->num_masks++;
magg->stats.curr_num_masks = magg->num_masks;
magg->stats.max_num_masks = MAX(magg->stats.curr_num_masks, magg->stats.max_num_masks);
magg->stats.curr_open_masks = magg->num_masks - magg->stats.curr_closed_masks;
magg->stats.max_open_masks = MAX(magg->stats.curr_open_masks, magg->stats.max_open_masks);
if (op->src_op == aaaaa1aaaOP_DEL) {
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(magg, meli->entry, op->src_entryset,
op->src_instance);
if (rc)
goto error;
}
int added;
do {
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbbbbbbbbbbbbbbb5aaa(magg, solution, meli, &added);
if (rc)
goto error;
} while (added > 0);
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg, meli->entry, op->dst_entryset,
op->dst_instance, op->dst_collset);
if (rc)
goto error;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(magg, meli->entry, op->dst_entryset,
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaRESVD_INSTANCE);
if (rc)
goto error;
magg->num_masks--;
magg->stats.curr_num_masks = magg->num_masks;
magg->stats.curr_open_masks = magg->num_masks - magg->stats.curr_closed_masks;
meli->entry = NULL;
}
error:
return rc;
}
static int
aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(struct tcam *magg, struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *solution)
{
int rc;
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa *meli, *tmp;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaop *op;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli;
cam_calloc_func calloc_function = client_get_calloc_function((client_t*) (magg->client));
LIST_FOREACH(solution->mask_list, mesli)
{
LIST_FOREACH_SAFE(mesli->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa, meli, tmp)
{
op = &magg->oparray[meli->entry->id];
if (op->dst_op == aaaaa1aaaOP_ADD) {
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg, meli->entry, op->dst_entryset,
op->dst_instance, op->dst_collset);
if (rc == CAM_ERROR_DUPLICATE_FOUND) {
#if 0
                   printf("COL prepend\n");
int i;
                   printf("AA %05u %p %3u %x %u %u %p %x:\n", meli->entry->priority,
op->dst_entryset, op->dst_instance,
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaavalue(&op->dst_entryset->mask), magg->num_masks,
op->dst_entryset->mask.max_pop, op->dst_collset, op->dst_entryset->mask.use_range);
                   printf("  K ");
for (i = 0; i < sizeof(aaaaaaaaaaaaa1aaat); i++)
                       printf("%02x ", *(((char *) &meli->entry->exact_key.word[0]) + i) & 0xff);
                   printf("\n  M ");
for (i = 0; i < sizeof(aaaaaaaaaaaaa1aaat); i++)
                       printf("%02x ", *(((char *) &op->dst_entryset->mask.mask.word[0]) + i) & 0xff);
                   printf("\n  T ");
for (i = 0; i < sizeof(aaaaaaaaaaaaa1aaat); i++)
                       printf("%02x ", *(((char *) &meli->entry->exact_mask.mask.word[0]) + i) & 0xff);
                   printf("\n");
#endif
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa *coll;
coll = calloc_function(1, sizeof(*coll));
coll->entry = meli->entry;
LIST_PREPEND(solution->collision_list, coll);
continue;
}
if (rc)
goto error;
}
if (op->src_op == aaaaa1aaaOP_DEL) {
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(magg, meli->entry, op->src_entryset,
op->src_instance);
if (rc)
goto error;
}
}
}
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbbbbbbbbbbbbbbb5aaa(magg, solution);
if (rc)
goto error;
return 0;
error:;
cam_free_func free_function = client_get_free_function((client_t*) (magg->client));
LIST_FOREACH_SAFE(solution->collision_list, meli, tmp)
{
LIST_DELETE2(solution->collision_list, meli, next);
free_function(meli);
}
solution->collision_list = NULL;
return rc;
}
static int
aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaado(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol)
{
int rc;
uint16_t remaining_entries;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes;
uint8_t instance;
remaining_entries = probsol->problem.num_entries;
probsol->curr_solution.num_masks = 0;
while (remaining_entries > 0) {
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaawinner(magg, &probsol->problem, &mes);
if (rc)
return rc;
assert(mes);
uint16_t num_populated;
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg, &probsol->problem,
&probsol->curr_solution, mes, &num_populated,
&instance);
if (rc)
return rc;
assert(num_populated > 0);
remaining_entries -= num_populated;
probsol->curr_solution.num_masks++;
if (magg->debug_mask & aaaaa1aaaDEBUG_SET_COVER) {
printf(
                   "  Winner %2"PRIu16" is %08"PRIx32", instance %"PRIu8", weight %"PRIu32", remain weight %"PRIu32", entries %"PRIu32", remain %"PRIu32", max pop cnt %"PRIu16", tot pop cnt %"PRIu32", active %"PRIu32", populated %"PRIu16", total remain %"PRIu16" :\n",
probsol->curr_solution.num_masks,
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaavalue(&mes->mask), instance,
mes->weight, mes->remaining_weight,
mes->num_entries, mes->remaining_entries,
mes->mask.max_pop, mes->mask.tot_pop,
mes->mask.active_fields,
num_populated, remaining_entries);
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(&mes->mask, 4);
if (magg->debug_mask & aaaaa1aaaDEBUG_SORTEDSET) {
int i = 0;
LIST_FOREACH2(probsol->problem.entryset_by_mask, mes, mh_handle.next)
{
if (mes == probsol->problem.entryset_by_mask)
continue;
printf(
                           "                                   weight %"PRIu32", remain weight %"PRIu32", entries %"PRIu32", remain %"PRIu32", max pop cnt %"PRIu16" :\n",
mes->weight, mes->remaining_weight,
mes->num_entries, mes->remaining_entries,
mes->mask.max_pop);
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(&mes->mask, 4);
i++;
if (i == 9)
break;
}
}
}
}
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg, probsol);
if (rc)
return rc;
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaasort(magg, &probsol->curr_solution);
if (rc)
return rc;
return 0;
}
int
aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6bbbbbbbbbbbbbbbbbb6aaa(struct tcam *magg,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa **out_mesli)
{
int rc;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli;
cam_calloc_func calloc_function = client_get_calloc_function((client_t*) (magg->client));
mesli = calloc_function(1, sizeof(*mesli));
if (mesli == NULL)
return CAM_ERROR_NOMEM;
mesli->entryset = mes;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaainstance(magg, &mes->mask, &mesli->instance);
if (rc)
goto error;
LIST_APPEND(probsol->curr_solution.mask_list, mesli);
probsol->curr_solution.num_masks++;
magg->num_masks++;
magg->stats.curr_num_masks = magg->num_masks;
magg->stats.max_num_masks = MAX(magg->stats.curr_num_masks, magg->stats.max_num_masks);
magg->stats.curr_open_masks = magg->num_masks - magg->stats.curr_closed_masks;
magg->stats.max_open_masks = MAX(magg->stats.curr_open_masks, magg->stats.max_open_masks);
*out_mesli = mesli;
return 0;
error:;
cam_free_func free_function = client_get_free_function((client_t*) (magg->client));
free_function(mesli);
return rc;
}
int
aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa(struct tcam *magg,
struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa **out_mesli)
{
int rc;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset;
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa *meli;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli;
const uint8_t max_entries_per_unit_bits = 32
- __builtin_clz((uint32_t) client_get_num_entries_per_unit(magg->client));
int bits;
int64_t space_left;
int64_t best_space = -1;
int best_pop = -1;
*out_mesli = NULL;
LIST_FOREACH(probsol->curr_solution.mask_list, mesli)
{
if (!aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaabaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaamember(&mesli->entryset->mask, me))
continue;
if (mesli->num_entries == client_get_num_entries_per_unit(magg->client))
continue;
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaafind(magg, mesli->entryset, me, &collset);
if (rc) {
bits = MIN(mesli->entryset->mask.const_pop, max_entries_per_unit_bits) +
mesli->entryset->mask.max_pop;
if (bits > 62)
bits = 62;
space_left = ((int64_t) 1 << bits) - mesli->num_entries;
if (space_left > best_space) {
*out_mesli = mesli;
best_space = space_left;
}
continue;
}
if (probsol->is_solved) {
if (collset->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaas.num_entries < magg->max_num_collisions) {
bits = MIN(mesli->entryset->mask.const_pop, max_entries_per_unit_bits) +
mesli->entryset->mask.max_pop;
if (bits > max_entries_per_unit_bits)
bits = max_entries_per_unit_bits;
space_left = ((int64_t) 1 << bits) - mesli->num_entries;
if (space_left > best_space ||
(space_left == best_space &&
mesli->entryset->mask.max_pop > best_pop)) {
best_pop = mesli->entryset->mask.max_pop;
*out_mesli = mesli;
best_space = space_left;
}
continue;
}
} else {
int collisions = 0;
LIST_FOREACH(mesli->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa, meli)
{
if (collset == meli->entry->current_entryset.collset) {
collisions++;
if (collisions == magg->max_num_collisions) {
break;
}
}
}
if (collisions < magg->max_num_collisions) {
bits = MIN(mesli->entryset->mask.const_pop, max_entries_per_unit_bits) +
mesli->entryset->mask.max_pop;
if (bits > 62)
bits = 62;
space_left = ((int64_t) 1 << bits) - mesli->num_entries;
if (space_left > best_space) {
*out_mesli = mesli;
best_space = space_left;
}
continue;
}
}
}
return 0;
}
int
aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(struct tcam *magg,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli, struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me)
{
int rc;
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa *meli;
struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *collset;
cam_calloc_func calloc_function = client_get_calloc_function((client_t*) (magg->client));
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaafind(magg, mesli->entryset, me, &collset);
assert(rc == 0);
meli = calloc_function(1, sizeof(*meli));
if (meli == NULL)
return CAM_ERROR_NOMEM;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg, me, mesli->entryset, mesli->instance, collset);
if (rc) {
client_print(magg->client);
goto error;
}
meli->entry = me;
LIST_PREPEND2(mesli->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa, meli, next);
mesli->num_entries++;
return 0;
error:;
cam_free_func free_function = client_get_free_function((client_t*) (magg->client));
free_function(meli);
return rc;
}
int
aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(struct tcam *magg, struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaa *solution,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me,
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa **out_mesli)
{
int rc;
struct aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa *meli, *meli_tmp;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaa *mesli, *mesli_tmp;
cam_free_func free_function = client_get_free_function((client_t*) (magg->client));
rc = -1;
LIST_FOREACH_SAFE(solution->mask_list, mesli, mesli_tmp)
{
LIST_FOREACH_SAFE(mesli->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa, meli, meli_tmp)
{
if (meli->entry == me) {
LIST_DELETE2(mesli->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa, meli, next);
free_function(meli);
mesli->num_entries--;
(*out_mesli) = mesli;
rc = 0;
break;
}
}
if (mesli->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaa == NULL) {
solution->num_masks--;
magg->num_masks--;
magg->stats.curr_num_masks = magg->num_masks;
magg->stats.curr_open_masks = magg->num_masks - magg->stats.curr_closed_masks;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaput_instance(magg, &mesli->entryset->mask,
mesli->instance);
if (rc)
return rc;
LIST_DELETE2(solution->mask_list, mesli, next);
free_function(mesli);
(*out_mesli) = NULL;
break;
}
}
return rc;
}
int
aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(struct tcam *magg, struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa *probsol,
int max_num_masks)
{
int rc;
magg->num_masks -= probsol->curr_solution.num_masks;
magg->stats.curr_num_masks = magg->num_masks;
magg->stats.curr_open_masks = magg->num_masks - magg->stats.curr_closed_masks;
probsol->prev_solution = probsol->curr_solution;
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaeate(magg, &probsol->curr_solution);
if (rc)
return rc;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaareset(magg, &probsol->problem);
if (rc)
return rc;
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaado(magg, probsol);
if (rc)
return rc;
if (probsol->curr_solution.num_masks > probsol->prev_solution.num_masks ||
probsol->curr_solution.num_masks > max_num_masks) {
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa5aaa(magg, &probsol->curr_solution);
if (rc)
return rc;
probsol->curr_solution = probsol->prev_solution;
magg->num_masks += probsol->curr_solution.num_masks;
return 1;
}
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(magg, &probsol->curr_solution);
if (rc)
return rc;
rc = aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa5aaa(magg, &probsol->prev_solution);
if (rc)
return rc;
magg->num_masks += probsol->curr_solution.num_masks;
magg->stats.curr_num_masks = magg->num_masks;
magg->stats.max_num_masks = MAX(magg->stats.curr_num_masks, magg->stats.max_num_masks);
magg->stats.curr_open_masks = magg->num_masks - magg->stats.curr_closed_masks;
magg->stats.max_open_masks = MAX(magg->stats.curr_open_masks, magg->stats.max_open_masks);
return rc;
}
static inline uint8_t popcount128(uint64_t word[])
{
return __builtin_popcountll(word[0]) + __builtin_popcountll(word[1]);
}
static inline uint8_t ctz128(uint64_t word[])
{
if (word[0] != 0)
return __builtin_ctzll(word[0]);
if (word[1] == 0)
return 128;
return 64 + __builtin_ctzll(word[1]);
}
static inline void set128(uint64_t word[], uint8_t bits)
{
word[0] = UINT64_MAX;
if (bits <= 64) {
word[0] = word[0] >> (64 - bits);
word[1] = 0;
} else {
word[1] = UINT64_MAX >> (128 - bits);
}
}
void aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint2bit(uint8_t * dst, uint8_t dst_len_bytes, uint16_t dst_aaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabits, const uint8_t * src,
const uint16_t src_len_bits)
{
assert(dst_aaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabits < dst_len_bytes * 8);
assert(dst_aaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabits + src_len_bits <= dst_len_bytes * 8);
uint8_t bit_shift = dst_aaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabits % 8;
dst += dst_aaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabits / 8;
int16_t remain_bits = src_len_bits;
while (remain_bits > 0) {
uint8_t tmp = (*src);
if (remain_bits < 8)
tmp &= ~(0xff << remain_bits);
*dst |= tmp << bit_shift;
dst++;
remain_bits -= MIN(remain_bits, 8 - bit_shift);
if (remain_bits == 0)
return;
*dst |= tmp >> (8 - bit_shift);
remain_bits -= MIN(remain_bits, bit_shift);
src++;
}
assert(remain_bits == 0);
}
void aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint64(uint64_t dst[], uint16_t dst_aaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabits,
const uint64_t *src, uint16_t src_aaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabits,
uint16_t src_len_bits)
{
const uint8_t WORD = 64;
const uint8_t WORD_BYTES = WORD / 8;
uint8_t src_word = src_aaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabits / WORD;
src += WORD_BYTES * src_word;
uint8_t src_bit = src_aaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabits % WORD;
uint8_t dst_word = dst_aaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabits / WORD;
dst += WORD_BYTES * dst_word;
uint8_t dst_bit = dst_aaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabits % WORD;
uint16_t remaining_bits = src_len_bits;
uint64_t tmp = 0;
while (remaining_bits > 0) {
uint8_t src_len = MIN(remaining_bits, WORD - src_bit);
uint8_t dst_len = MIN(remaining_bits, WORD - dst_bit);
uint8_t len = MIN(src_len, dst_len);
tmp = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa64(*(uint64_t *) src, src_bit, len);
if (dst_bit == 0)
*dst = tmp;
else
*dst = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa64(*dst, tmp, dst_bit, len);
src_bit = src_bit + len;
if (src_bit >= WORD) {
src_bit -= WORD;
src += WORD_BYTES;
}
dst_bit = dst_bit + len;
if (dst_bit >= WORD) {
dst_bit -= WORD;
dst++;
}
remaining_bits -= len;
}
}
void aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaabits(uint8_t * dst, uint8_t dst_len_bytes,
uint16_t dst_aaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabits, uint16_t len_bits)
{
if (len_bits == 0)
return;
assert(dst_aaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabits < dst_len_bytes * 8);
assert(dst_aaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabits + len_bits <= dst_len_bytes * 8);
uint8_t bit_shift = dst_aaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabits % 8;
dst += dst_aaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaabits / 8;
int16_t remain_bits = len_bits;
while (remain_bits > 0) {
uint8_t tmp = 0xff;
if (remain_bits < 8)
tmp &= ~(0xff << remain_bits);
*dst |= tmp << bit_shift;
dst++;
remain_bits -= MIN(remain_bits, 8 - bit_shift);
if (remain_bits == 0)
return;
*dst |= tmp >> (8 - bit_shift);
remain_bits -= MIN(remain_bits, bit_shift);
}
assert(remain_bits == 0);
}
static int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbb5aaa(struct tcam *tcam, const union aaaaaaaaaaa1aaa fields[], uint8_t index,
uint8_t key[])
{
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc mfd;
const int rc = client_get_aaaaaaaaaaaaaaaaaa1aaa(tcam->client, index, &mfd);
assert(rc == 0);
switch (mfd.type) {
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaR16:
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint2bit(key, sizeof(aaaaaaaaaaaaa1aaat), mfd.start_pos,
(uint8_t *) &fields[index].r16.start, mfd.len);
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaP128:
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint2bit((uint8_t *) key, sizeof(aaaaaaaaaaaaa1aaat), mfd.start_pos,
&fields[index].p128.key[0], mfd.len);
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaT64:
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint2bit((uint8_t *) key, sizeof(aaaaaaaaaaaaa1aaat), mfd.start_pos, &fields[index].t64.key[0], mfd.len);
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaB128:
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint2bit((uint8_t *) key, sizeof(aaaaaaaaaaaaa1aaat), mfd.start_pos,
&fields[index].b128.key[0], mfd.len);
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaC128:
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint2bit((uint8_t *) key, sizeof(aaaaaaaaaaaaa1aaat), mfd.start_pos,
&fields[index].c128.key[0], mfd.len);
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaU128:
break;
default:
assert(0);
}
return 0;
}
static int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaternary_mask_copy(struct tcam *tcam, const union aaaaaaaaaaa1aaa fields[], uint8_t index,
uint8_t ternary_mask[])
{
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc mfd;
const int rc = client_get_aaaaaaaaaaaaaaaaaa1aaa(tcam->client, index, &mfd);
assert(rc == 0);
switch (mfd.type) {
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaR16:
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint2bit((uint8_t *) ternary_mask, sizeof(aaaaaaaaaaaaa1aaat), mfd.start_pos,
(uint8_t *) &fields[index].r16.end, mfd.len);
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaP128:
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaabits((uint8_t *) ternary_mask, sizeof(aaaaaaaaaaaaa1aaat),
mfd.start_pos + mfd.len - fields[index].p128.len, fields[index].p128.len);
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaT64:
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint2bit((uint8_t *) ternary_mask, sizeof(aaaaaaaaaaaaa1aaat), mfd.start_pos,
&fields[index].t64.mask[0], mfd.len);
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaB128:
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaauint2bit((uint8_t *) ternary_mask, sizeof(aaaaaaaaaaaaa1aaat), mfd.start_pos,
&fields[index].b128.mask[0], mfd.len);
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaC128:
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaabits((uint8_t *) ternary_mask, sizeof(aaaaaaaaaaaaa1aaat), mfd.start_pos, mfd.len);
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaU128:
break;
default:
assert(0);
}
return 0;
}
static int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbb5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa6aaafrom_ternary_mask(const aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc *mfd, union aaaaaaaaaaa1aaa fields[],
uint8_t index, const uint8_t ternary_mask[],
const client_t *client)
{
uint64_t temp[2];
uint64_t clr_bits[2] = { 0 };
uint64_t set_bits[2];
uint8_t num_ones;
uint8_t num_trailing_zeroes;
uint8_t verbose = (client_get_debug_flags(client) & CAM_DEBUG_NO_ERROR_MSG) == 0;
char message[500];
cam_malloc_func malloc_function = client_get_malloc_function(client);
uint16_t diff = 0;
uint64_t *w64 = NULL;
switch (mfd->type) {
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaR16:
memset(&fields[index].r16.end, 0, sizeof(fields[index].r16.end));
cam_read_field8((uint8_t *) &fields[index].r16.end, &ternary_mask[0], mfd->start_pos, mfd->len);
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaP128:
memset(temp, 0, sizeof(temp));
cam_read_field8((uint8_t *) temp, (uint8_t *) &ternary_mask[0],
mfd->start_pos, mfd->len);
num_trailing_zeroes = MIN(ctz128(temp), mfd->len);
num_ones = popcount128(temp);
assert(num_ones <= mfd->len);
diff = mfd->len - num_ones;
if (diff != num_trailing_zeroes) {
if (verbose) {
char *mask_value = byte_arr_to_str(mfd->len, (uint8_t *) temp, malloc_function);
               sprintf(message, "Mask check: In field %0d/bit %0d, format 'p%d' invalid mask '%s' expected '{p ones, %d-p zeroes}' p = 0..%d\n",
index, mfd->start_pos, mfd->len, mask_value, mfd->len, mfd->len);
client_print_error(client, message);
cam_free_func free_function = client_get_free_function(client);
free_function(mask_value);
}
return CAM_ERROR_INVALID_PREFIX_LEN;
}
fields[index].p128.len = num_ones;
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaT64:
memset(temp, 0, sizeof(temp));
cam_read_field8((uint8_t *) temp, (uint8_t *) &ternary_mask[0],
mfd->start_pos, mfd->len);
num_ones = popcount128(temp);
assert(num_ones <= mfd->len);
w64 = (uint64_t *) &fields[index].t64.mask[0];
*w64 = temp[0];
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaB128:
memset(temp, 0, sizeof(temp));
cam_read_field8((uint8_t *) temp, (uint8_t *) &ternary_mask[0],
mfd->start_pos, mfd->len);
num_ones = popcount128(temp);
if (num_ones != 0 && num_ones != mfd->len) {
if (verbose) {
set128(set_bits, mfd->len);
char *mask_value = byte_arr_to_str(mfd->len, (uint8_t *) temp, malloc_function);
char *expect_zero = byte_arr_to_str(mfd->len, (uint8_t *) clr_bits, malloc_function);
char *expect_one = byte_arr_to_str(mfd->len, (uint8_t *) set_bits, malloc_function);
               sprintf(message, "Mask check: In field %0d/bit %0d, format '%c%d' invalid mask '%s' expected '%s' or '%s'\n",
index, mfd->start_pos, 'b', mfd->len, mask_value, expect_zero, expect_one);
client_print_error(client, message);
cam_free_func free_function = client_get_free_function(client);
free_function(mask_value);
free_function(expect_zero);
free_function(expect_one);
}
return CAM_ERROR_WRONG_BIT_FIELD_MASK;
}
if (num_ones == mfd->len)
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaabits((uint8_t *) &fields[index].b128.mask[0],
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaMEM_128, 0, mfd->len);
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaC128:
memset(temp, 0, sizeof(temp));
cam_read_field8((uint8_t *) temp, (uint8_t *) &ternary_mask[0],
mfd->start_pos, mfd->len);
num_ones = popcount128(temp);
if (num_ones != mfd->len) {
if (verbose) {
set128(set_bits, mfd->len);
char *mask_value = byte_arr_to_str(mfd->len, (uint8_t *) temp, malloc_function);
char *expect_one = byte_arr_to_str(mfd->len, (uint8_t *) set_bits, malloc_function);
               sprintf(message, "Mask check: In field %0d/bit %0d, format '%c%d' invalid mask '%s' expected '%s'\n",
index, mfd->start_pos, 'c', mfd->len, mask_value, expect_one);
client_print_error(client, message);
cam_free_func free_function = client_get_free_function(client);
free_function(mask_value);
free_function(expect_one);
}
return CAM_ERROR_WRONG_CONST_FIELD_MASK;
}
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaU128:
break;
default:
assert(0);
}
return 0;
}
static int aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbb5aaa(struct tcam *tcam, union aaaaaaaaaaa1aaa fields[], uint8_t index, const uint8_t key[])
{
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc mfd;
const int rc = client_get_aaaaaaaaaaaaaaaaaa1aaa(tcam->client, index, &mfd);
assert(rc == 0);
switch (mfd.type) {
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaR16:
memset(&fields[index].r16.start, 0, sizeof(fields[index].r16.start));
cam_read_field8((uint8_t *) &fields[index].r16.start,
(uint8_t *) &key[0], mfd.start_pos, mfd.len);
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaP128:
memset(&fields[index].p128.key[0], 0, aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaMEM_128);
cam_read_field8((uint8_t *) &fields[index].p128.key[0],
(uint8_t *) &key[0], mfd.start_pos, mfd.len);
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaT64:
memset(&fields[index].t64.key[0], 0, aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaMEM_128 / 2);
cam_read_field8((uint8_t *) &fields[index].t64.key[0],
(uint8_t *) &key[0], mfd.start_pos, mfd.len);
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaB128:
memset(&fields[index].b128.key[0], 0, aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaMEM_128);
cam_read_field8((uint8_t *) &fields[index].b128.key[0],
(uint8_t *) &key[0], mfd.start_pos, mfd.len);
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaC128:
memset(&fields[index].c128.key[0], 0, aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaMEM_128);
cam_read_field8((uint8_t *) &fields[index].c128.key[0],
(uint8_t *) &key[0], mfd.start_pos, mfd.len);
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaU128:
break;
default:
assert(0);
}
return 0;
}
static int check_field(struct tcam *tcam, const union aaaaaaaaaaa1aaa fields[], uint8_t index)
{
uint64_t temp[2];
uint8_t num_ones;
uint64_t key_temp = 0;
uint64_t mask_temp = 0;
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc mfd;
const int rc = client_get_aaaaaaaaaaaaaaaaaa1aaa(tcam->client, index, &mfd);
assert(rc == 0);
uint8_t zeroes = 0;
switch (mfd.type) {
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaR16:
if (fields[index].r16.end < fields[index].r16.start) {
return CAM_ERROR_WRONG_RANGE;
}
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaP128:
memset(temp, 0, sizeof(temp));
zeroes = mfd.len - fields[index].p128.len;
if (zeroes > 0) {
cam_read_field8((uint8_t *) temp, fields[index].p128.key, 0, zeroes);
num_ones = popcount128(temp);
if (num_ones != 0)
return CAM_ERROR_MASKED_KEY_BIT_IS_SET;
}
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaT64:
cam_read_field8((uint8_t *) &key_temp, fields[index].t64.key, 0, mfd.len);
cam_read_field8((uint8_t *) &mask_temp, fields[index].t64.mask, 0, mfd.len);
if ((key_temp & mask_temp) != key_temp)
return CAM_ERROR_MASKED_KEY_BIT_IS_SET;
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaB128:
memset(temp, 0, sizeof(temp));
cam_read_field8((uint8_t *) temp, (uint8_t *) fields[index].b128.key, 0, mfd.len);
num_ones = popcount128(temp);
if ((fields[index].b128.mask[0] & 1) == 0) {
if (num_ones != 0)
return CAM_ERROR_MASKED_KEY_BIT_IS_SET;
}
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaC128:
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaU128:
break;
default:
assert(0);
}
return 0;
}
int cam_check_fields(struct tcam *tcam, const union aaaaaaaaaaa1aaa fields[])
{
const uint8_t num_fields = client_get_num_fields(tcam->client);
int i;
int rc;
for (i = 0; i < num_fields; i++) {
rc = check_field(tcam, fields, i);
if (rc)
return rc;
}
return 0;
}
int aaaaaaaaaaa1aaas2key(struct tcam *tcam, const union aaaaaaaaaaa1aaa fields[], uint8_t key[])
{
memset(key, 0, sizeof(aaaaaaaaaaaaa1aaat));
const uint8_t num_fields = client_get_num_fields(tcam->client);
int i;
int rc;
for (i = 0; i < num_fields; i++) {
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbb5aaa(tcam, fields, i, key);
if (rc)
return rc;
}
return 0;
}
int aaaaaaaaaaa1aaas2mask(struct tcam *tcam, const union aaaaaaaaaaa1aaa fields[], uint8_t mask[])
{
memset(mask, 0, sizeof(aaaaaaaaaaaaa1aaat));
const uint8_t num_fields = client_get_num_fields(tcam->client);
int i;
int rc;
for (i = 0; i < num_fields; i++) {
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaternary_mask_copy(tcam, fields, i, mask);
if (rc)
return rc;
}
return 0;
}
int cam_key2fields(struct tcam *tcam, union aaaaaaaaaaa1aaa fields[], const uint8_t key[])
{
const uint8_t num_fields = client_get_num_fields(tcam->client);
int i;
int rc;
for (i = 0; i < num_fields; i++) {
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbb5aaa(tcam, fields, i, key);
if (rc)
return rc;
}
return 0;
}
int cam_mask2fields(const client_t *client, union aaaaaaaaaaa1aaa fields[], const uint8_t mask[])
{
const uint8_t num_fields = client_get_num_fields(client);
int i;
int rc;
for (i = 0; i < num_fields; i++) {
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc mfd;
rc = client_get_aaaaaaaaaaaaaaaaaa1aaa(client, i, &mfd);
assert(rc == 0);
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5bbbbbbbbbbbbbbbb5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa6aaafrom_ternary_mask(&mfd, fields, i, mask, client);
if (rc)
return rc;
}
return 0;
}
uint16_t cam_get_num_ones(const aaaaaaaaaaaaa1aaat *data)
{
uint16_t num_ones = 0;
for (uint8_t i = 0; i < CAM_MAX_KEY_WIDTH_MEM; i++) {
num_ones = num_ones + __builtin_popcount(data->word[i]);
}
return num_ones;
}
static void mask_field(struct tcam *tcam, union aaaaaaaaaaa1aaa fields[], uint8_t index)
{
uint64_t *key64;
uint64_t *mask64;
uint64_t mask128[2];
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc mfd;
const int rc = client_get_aaaaaaaaaaaaaaaaaa1aaa(tcam->client, index, &mfd);
assert(rc == 0);
switch (mfd.type) {
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaR16:
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaP128:
mask128[0] = 0;
mask128[1] = 0;
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaabits((uint8_t *) &mask128[0], 128 / 8,
mfd.len - fields[index].p128.len,
fields[index].p128.len);
key64 = (uint64_t *) fields[index].p128.key;
*key64 = *key64 & mask128[0];
key64++;
*key64 = *key64 & mask128[1];
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaT64:
key64 = (uint64_t *) fields[index].t64.key;
mask64 = (uint64_t *) fields[index].t64.mask;
*key64 = *key64 & *mask64;
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaB128:
key64 = (uint64_t *) fields[index].b128.key;
mask64 = (uint64_t *) fields[index].b128.mask;
*key64 = *key64 & *mask64;
key64++;
mask64++;
*key64 = *key64 & *mask64;
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaC128:
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaU128:
break;
default:
assert(0);
}
}
void cam_mask_fields(struct tcam *tcam, union aaaaaaaaaaa1aaa fields[])
{
const uint8_t num_fields = client_get_num_fields(tcam->client);
for (uint8_t i = 0; i < num_fields; i++) {
mask_field(tcam, fields, i);
}
}
typedef enum {
ALL, ONLY_VALID_BITS
} flush_mode_t;
typedef struct {
uint8_t valid;
uint16_t seed;
uint8_t range_valid;
aaaaaaaaaaaaa1aaat mask;
} mask_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat;
struct aaaaaaaaaaaa1aaat {
mask_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaat mask_entry;
client_t *client;
uint16_t unit;
uint8_t slot_number;
uint8_t mask_id;
};
size_t aaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa(void)
{
return sizeof(aaaaaaaaaaaa1aaat);
}
const client_t *aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaclient(const aaaaaaaaaaaa1aaat *mm)
{
assert(mm != NULL);
return mm->client;
}
uint16_t aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(const aaaaaaaaaaaa1aaat *mm)
{
assert(mm != NULL);
return mm->unit;
}
bool aaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaavalid(const aaaaaaaaaaaa1aaat *mm)
{
return mm->mask_entry.valid;
}
bool aaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaequal(const aaaaaaaaaaaa1aaat *mm, const aaaaaaaaaaaaa1aaat *mask, uint8_t range_valid,
uint8_t mask_id)
{
if (mm->mask_id != mask_id || mm->mask_entry.range_valid != range_valid) {
return false;
}
const int rc = memcmp(mask, &(mm->mask_entry.mask.word[0]), sizeof(aaaaaaaaaaaaa1aaat));
if (rc != 0)
return false;
return true;
}
void aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(const aaaaaaaaaaaa1aaat *mm, uint8_t *range_valid)
{
assert(aaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaavalid(mm));
*range_valid = mm->mask_entry.range_valid;
}
static void flush_mask_entry(const aaaaaaaaaaaa1aaat *mm, flush_mode_t flush_mode, uint64_t *hw_word_verify)
{
if (client_is_bcam(mm->client) || client_is_drambcam(mm->client))
return;
const uint16_t client_width = client_get_key_width(mm->client);
const uint32_t base = aaaaaa1aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa + mm->unit * aaaaaa1aaaaaaaaaaaabaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa + mm->slot_number * aaaaaa1aaaaaaaaaaaaaaa1aaaWORD;
uint64_t sw[16] = { 0 };
sw[15] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa64(sw[15], mm->mask_entry.seed, 32, 16);
sw[15] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa64(sw[15], mm->mask_entry.valid, 32 + 16, 1);
sw[15] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa64(sw[15], mm->mask_entry.range_valid, 32 + 16 + 1, 8);
uint8_t width32 = client_width / 32;
const uint8_t remaining_bits32 = client_width - width32 * 32;
if (remaining_bits32 > 0) {
width32++;
}
for (uint8_t i = 0; i < width32; i++) {
uint8_t dest_pos;
if ((i & 1) == 0) {
dest_pos = 0;
} else {
dest_pos = 32;
}
sw[i / 2] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa64(sw[i / 2], mm->mask_entry.mask.word[i], dest_pos, 32);
}
uint8_t width64 = (client_width + 63) / 64;
assert(width64 <= 16);
if (flush_mode == ONLY_VALID_BITS) {
client_hw_write(mm->client, base + 15 * 0x8, sw[15]);
return;
} else if (flush_mode == ALL) {
} else {
assert(false);
}
for (uint8_t i = 0; i < width64; i++) {
if (hw_word_verify == NULL) {
client_hw_write(mm->client, base + i * 0x8, sw[i]);
} else {
hw_word_verify[i] = sw[i];
}
}
if (hw_word_verify == NULL) {
client_hw_write(mm->client, base + 15 * 0x8, sw[15]);
} else {
hw_word_verify[15] = sw[15];
}
}
static void clear_mask(aaaaaaaaaaaa1aaat *mm)
{
memset(&mm->mask_entry.mask.word[0], 0, sizeof(aaaaaaaaaaaaa1aaat));
}
void aaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(aaaaaaaaaaaa1aaat *mm, client_t *client, uint16_t unit, uint8_t slot_number)
{
assert(client != NULL);
assert(unit < aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaS);
mm->client = client;
mm->unit = unit;
mm->slot_number = slot_number;
mm->mask_entry.valid = 0;
mm->mask_entry.seed = 0;
mm->mask_entry.range_valid = 0;
clear_mask(mm);
mm->mask_id = 0;
if (!(client_get_debug_flags(mm->client) & CAM_DEBUG_SKIP_MEM_INIT) ||
client_get_num_slots(client) == 1) {
flush_mask_entry(mm, ALL, NULL);
}
}
void aaaaaaaaaaaa1aaaread_mask(const aaaaaaaaaaaa1aaat *mm, aaaaaaaaaaaaa1aaat *mask, uint8_t *range_valid, uint8_t *mask_id)
{
*mask = mm->mask_entry.mask;
aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(mm, range_valid);
*mask_id = mm->mask_id;
}
uint16_t aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaseed(const aaaaaaaaaaaa1aaat *mm)
{
assert(aaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaavalid(mm));
return mm->mask_entry.seed;
}
uint8_t aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(const aaaaaaaaaaaa1aaat *mm)
{
return mm->slot_number;
}
void aaaaaaaaaaaa1bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaseed(aaaaaaaaaaaa1aaat *mm, uint16_t seed)
{
assert(!aaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaavalid(mm));
mm->mask_entry.seed = seed;
}
void aaaaaaaaaaaa1bbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6aaa(aaaaaaaaaaaa1aaat *mm)
{
assert(aaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaavalid(mm));
mm->mask_entry.valid = 0;
flush_mask_entry(mm, ONLY_VALID_BITS, NULL);
}
void aaaaaaaaaaaa1bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6aaa(aaaaaaaaaaaa1aaat *mm)
{
assert(!aaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaavalid(mm));
mm->mask_entry.valid = 1;
flush_mask_entry(mm, ONLY_VALID_BITS, NULL);
}
void aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6aaa(aaaaaaaaaaaa1aaat *mm, const aaaaaaaaaaaaa1aaat *mask, uint16_t seed,
uint8_t range_valid, uint8_t mask_id)
{
if (mask != NULL)
memcpy(&mm->mask_entry.mask, mask, sizeof(aaaaaaaaaaaaa1aaat));
mm->mask_entry.valid = 1;
mm->mask_entry.seed = seed;
assert((range_valid == 0) || client_is_tcam(mm->client));
mm->mask_entry.range_valid = range_valid;
mm->mask_id = mask_id;
flush_mask_entry(mm, ALL, NULL);
}
void aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(const aaaaaaaaaaaa1aaat *mm, const aaaaaaaaaaaaa1aaat *key, aaaaaaaaaaaaa1aaat *masked_key)
{
for (uint8_t i = 0; i < CAM_MAX_KEY_WIDTH_MEM; i++) {
masked_key->word[i] = mm->mask_entry.mask.word[i] & key->word[i];
}
}
void murmur3(const void * key, uint16_t len,
uint32_t seed, uint32_t * out)
{
const uint8_t * data = (const uint8_t*)key;
const uint16_t num_blocks = len / 4;
int i;
uint32_t hv = seed;
uint32_t c1 = 0xcc9e2d51;
uint32_t c2 = 0x1b873593;
const uint32_t * blocks = (const uint32_t *) (data + num_blocks * 4);
for (i = -num_blocks; i; i++)
{
uint32_t k1 = blocks[i];
k1 *= c1;
k1 = aaaaaaaa1aaarotate_left32(k1, 15);
k1 *= c2;
hv ^= k1;
hv = aaaaaaaa1aaarotate_left32(hv, 13);
hv = hv * 5 + 0xe6546b64;
}
const uint8_t * tail = (const uint8_t*) (data + num_blocks * 4);
uint32_t k1 = 0;
switch(len & 3)
{
case 3:
k1 ^= tail[2] << 16;
/* Falls through. */
case 2:
k1 ^= tail[1] << 8;
/* Falls through. */
case 1:
k1 ^= tail[0];
k1 *= c1;
k1 = aaaaaaaa1aaarotate_left32(k1, 15);
k1 *= c2;
hv ^= k1;
};
hv ^= len;
hv ^= hv >> 16;
hv *= 0x85ebca6b;
hv ^= hv >> 13;
hv *= 0xc2b2ae35;
hv ^= hv >> 16;
*out = hv;
}
void murmur3_bucket(const void *key, uint16_t keylen, uint32_t num_bkts, uint32_t *hashv, uint32_t *bucket)
{
murmur3(key, keylen, 3, hashv);
*bucket = *hashv & (num_bkts - 1);
}
size_t aaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa(void)
{
return sizeof(aaa1aaat);
}
void aaa1aaaread_mask(const aaa1aaat *phm, aaaaaaaaaaaaa1aaat *mask, uint8_t *range_valid, uint8_t *mask_id)
{
aaaaaaaaaaaa1aaaread_mask(phm->mm, mask, range_valid, mask_id);
}
void aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6aaa(aaa1aaat *phm, const aaaaaaaaaaaaa1aaat *mask,
uint16_t seed, uint8_t range_valid, uint8_t mask_id)
{
aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6aaa(phm->mm, mask, seed, range_valid, mask_id);
}
uint32_t aaa1aaaadjust_list(const aaa1aaat *phm, uint32_t list)
{
const uint32_t num_lists = client_get_num_lists(phm->client);
const uint32_t max_lists = num_lists - 1;
const uint32_t base_list = (list & max_lists);
return base_list;
}
void aaa1bbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6aaa(const aaa1aaat *phm)
{
aaaaaaaaaaaa1bbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6aaa(phm->mm);
}
void aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(const aaa1aaat *phm)
{
#if 0
assert(client_is_tcam(phm->client));
   printf("\nStart PHM");
const uint16_t unit = aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(phm->mm);
const uint8_t max_slots = client_get_num_slots(phm->client);
const uint8_t slot_number = aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(phm->mm);
   printf("\nUnit = %d, Max slots = %d, Slot number = %d", unit, max_slots,
slot_number);
if (aaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaavalid(phm->mm)) {
aaaaaaaaaaaaaaa1aaat *pointer_list = (aaaaaaaaaaaaaaa1aaat *) alloca(aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa());
const uint32_t segment_size = client_get_num_lists(phm->client);
const uint32_t end_aaaaaaaaaa1aaa = segment_size - 1;
uint8_t range_valid, mask_id;
aaaaaaaaaaaaa1aaat mask;
memset(&mask, 0, sizeof(aaaaaaaaaaaaa1aaat));
aaa1aaaread_mask(phm, &mask, &range_valid, &mask_id);
const uint16_t key_width = client_get_key_width(phm->client);
printf(
                   "\nRange valid = %d, Mask id = %d\nKey Width = %d Mask = ", range_valid,
mask_id, key_width);
for (int8_t j = 9; j >= 0; j--) {
           printf("%08"PRIx32"", mask.word[j]);
}
const uint32_t num_lists = client_get_num_lists(phm->client);
const uint32_t end_bucket = num_lists * aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO - 1;
uint32_t number_of_keys = 0;
uint32_t reverse_counter = 0;
       printf("\nBucket, mode number_of_keys, bloom");
for (uint32_t bucket = 0; bucket <= end_bucket; bucket++) {
number_of_keys = number_of_keys + aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(phm->bm, bucket);
if ((bucket % 16) == 0) {
               printf("\n%"PRIu32"-%"PRIu32"\t", bucket, bucket + 15);
}
if (aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->bm, bucket)) {
               printf("I,\t");
} else if (aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(phm->bm, bucket)) {
               printf("P%d, ", aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(phm->bm, bucket));
} else if (aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(phm->bm, bucket)) {
               printf("F%d, ", aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(phm->bm, bucket));
} else {
assert(false);
}
}
printf(
               "\nNumber of keys in bucket memory = %"PRIu32", number of keys using bloom filter = %"PRIu32", ratio = %"PRIu32"",
number_of_keys, reverse_counter, (reverse_counter * 100) / number_of_keys);
number_of_keys = 0;
       printf("\nAddr, no keys, (source bucket, function number, key, prio, ternary mask....");
for (uint32_t aaaaaaaaaa1aaa = 0; aaaaaaaaaa1aaa <= end_aaaaaaaaaa1aaa; aaaaaaaaaa1aaa++) {
           printf("\n%03"PRIu32", ", aaaaaaaaaa1aaa);
if (aaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->km, aaaaaaaaaa1aaa)) {
               printf("0");
} else {
               printf("1");
number_of_keys++;
if (aaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(phm->km, aaaaaaaaaa1aaa)) {
                   printf(", P");
                   printf("%04"PRIu32",     ", aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaabaaaaaaaaaaa4aaa(phm->km, aaaaaaaaaa1aaa));
const bool success = aaaa1aaaread_element_bcam(phm->km, aaaaaaaaaa1aaa,
pointer_list, NULL, 0, 0);
assert(success);
const aaaaaaaaaaaaa1aaat *aaaaaaaaa1aaa = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaa1aaa(pointer_list, 0);
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *prio_ptr = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaa4aaa(pointer_list, 0);
for (int8_t j = 9; j >= 0; j--) {
                       printf("%08"PRIx32"", aaaaaaaaa1aaa->word[j]);
}
                   printf(", %08"PRIx32"", prio_ptr->word[0]);
if (client_is_tcam(phm->client)) {
                       printf(",  ");
const aaaaaaaaaaaaa1aaat *ternary_mask = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaternary_mask(pointer_list, 0);
for (int8_t j = 9; j >= 0; j--) {
                           printf("%08"PRIx32"", ternary_mask->word[j]);
}
}
} else {
                   printf(", F");
const uint32_t bucket = aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaabaaaaaaaaaaa4aaa(phm->km, aaaaaaaaaa1aaa);
                   printf("%04"PRIu32", ", bucket);
const uint8_t function = aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(phm->bm, bucket);
                   printf("%02d, ", function);
const bool success = aaaa1aaaread_element_tcam(phm->km, aaaaaaaaaa1aaa,
pointer_list, NULL, 0, 0);
assert(success);
const aaaaaaaaaaaaa1aaat *aaaaaaaaa1aaa = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaa1aaa(pointer_list, 0);
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *prio_ptr = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaa4aaa(pointer_list, 0);
for (int8_t j = 9; j >= 0; j--) {
                       printf("%08"PRIx32"", aaaaaaaaa1aaa->word[j]);
}
                   printf(", %08"PRIx32"", prio_ptr->word[0]);
if (client_is_tcam(phm->client)) {
                       printf(",  ");
const aaaaaaaaaaaaa1aaat *ternary_mask = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaternary_mask(pointer_list, 0);
for (int8_t j = 9; j >= 0; j--) {
                           printf("%08"PRIx32"", ternary_mask->word[j]);
}
}
}
}
}
       printf("\nNumber of keys in key memory = %"PRIu32"", number_of_keys);
} else {
       printf("\nUnit not used");
}
   printf("\nEnd PHM\n");
#else
(void) phm; ; 
#endif
}
uint32_t aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(const aaa1aaat *phm)
{
return phm->number_of_keys;
}
uint8_t aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(const aaa1aaat *phm)
{
return aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(phm->mm);
}
uint16_t aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(const aaa1aaat *phm)
{
return aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(phm->mm);
}
bool aaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaequal(const aaa1aaat *phm, const aaaaaaaaaaaaa1aaat *mask, uint8_t range_valid,
uint8_t mask_id)
{
return aaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaequal(phm->mm, mask, range_valid, mask_id);
}
bool aaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaavalid(const aaa1aaat *phm)
{
return aaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaavalid(phm->mm);
}
uint16_t aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaseed(const aaa1aaat *phm)
{
return aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaseed(phm->mm);
}
void aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(const aaa1aaat *phm, const aaaaaaaaaaaaa1aaat *key, aaaaaaaaaaaaa1aaat *masked_key)
{
aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->mm, key, masked_key);
}
const client_t *aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaclient(const aaa1aaat *phm)
{
return phm->client;
}
void aaa1bbbbbbbbbbbbbbbbbbb3aaa(const aaa1aaat *phm, const client_t *client)
{
assert(phm != NULL);
aaaa1bbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaall(phm->km);
if (client_is_tcam(client)) {
aa1bbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaall(phm->bm);
}
}
#define MAX_ELEMENTS 32
struct aaaaaaaaaaaaaaa1aaat {
bool is_direct_pointer;
uint8_t number_of_keys;
uint64_t bucket; 
aaaaaaaaaaaaa1aaat aaaaaaaaa1aaas[MAX_ELEMENTS];
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat prios[MAX_ELEMENTS];
aaaaaaaaaaaaa1aaat ternary_masks[MAX_ELEMENTS];
bool narrow_keys[MAX_ELEMENTS];
uint16_t fingerprints[MAX_ELEMENTS];
};
size_t aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa(void)
{
return sizeof(aaaaaaaaaaaaaaa1aaat);
}
void aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(aaaaaaaaaaaaaaa1aaat *pointer_list, uint64_t bucket, bool is_direct_pointer, bool ternary_list)
{
pointer_list->bucket = bucket;
pointer_list->is_direct_pointer = is_direct_pointer;
pointer_list->number_of_keys = 0;
if (ternary_list) {
for (uint8_t i = 0; i < MAX_ELEMENTS; i++) {
memset(&(pointer_list->ternary_masks[i].word[0]), 0xff, sizeof(pointer_list->ternary_masks[i]));
}
}
}
void aaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(aaaaaaaaaaaaaaa1aaat *pointer_list, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *prio, const aaaaaaaaaaaaa1aaat *aaaaaaaaa1aaa,
const aaaaaaaaaaaaa1aaat *ternary_mask, bool narrow_key, uint16_t fingerprint)
{
uint8_t number_of_keys = pointer_list->number_of_keys;
assert(number_of_keys < MAX_ELEMENTS);
pointer_list->prios[number_of_keys] = *prio;
memcpy(&pointer_list->aaaaaaaaa1aaas[number_of_keys], aaaaaaaaa1aaa, sizeof(aaaaaaaaaaaaa1aaat));
if (ternary_mask != NULL) {
memcpy(&pointer_list->ternary_masks[number_of_keys], ternary_mask, sizeof(aaaaaaaaaaaaa1aaat));
}
pointer_list->narrow_keys[number_of_keys] = narrow_key;
pointer_list->fingerprints[number_of_keys] = fingerprint;
pointer_list->number_of_keys++;
}
void aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaall(aaaaaaaaaaaaaaa1aaat *pointer_list)
{
pointer_list->number_of_keys = 0;
}
uint8_t aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(const aaaaaaaaaaaaaaa1aaat *pointer_list)
{
return pointer_list->number_of_keys;
}
const aaaaaaaaaaaaa1aaat *aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaa1aaa(const aaaaaaaaaaaaaaa1aaat *pointer_list, uint8_t key_number)
{
assert(key_number < pointer_list->number_of_keys);
return &(pointer_list->aaaaaaaaa1aaas[key_number]);
}
const aaaaaaaaaaaaa1aaat *aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaternary_mask(const aaaaaaaaaaaaaaa1aaat *pointer_list, uint8_t key_number)
{
assert(key_number < pointer_list->number_of_keys);
return &(pointer_list->ternary_masks[key_number]);
}
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaa4aaa(const aaaaaaaaaaaaaaa1aaat *pointer_list, uint8_t key_number)
{
assert(key_number < pointer_list->number_of_keys);
return &(pointer_list->prios[key_number]);
}
bool aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaanarrow_key(const aaaaaaaaaaaaaaa1aaat *pointer_list, uint8_t key_number)
{
assert(key_number < pointer_list->number_of_keys);
return pointer_list->narrow_keys[key_number];
}
uint64_t aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaabaaaaaaaaaaa4aaa(const aaaaaaaaaaaaaaa1aaat *pointer_list)
{
return pointer_list->bucket;
}
bool aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(const aaaaaaaaaaaaaaa1aaat *pointer_list)
{
return pointer_list->is_direct_pointer;
}
uint16_t aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaafingerprint(const aaaaaaaaaaaaaaa1aaat *pointer_list, uint8_t key_number)
{
return pointer_list->fingerprints[key_number];
}
#include <ctype.h>
#if defined(__X86_64__) || defined(__x86_64__) || defined (__i386__) \
|| defined (__aarch64__) || defined (__arm64__)
#define UNALIGNED_LE_CPU
#endif
#define ROTL(x, b) (uint64_t)(((x) << (b)) | ((x) >> (64 - (b))))
#define U32TO8_LE(p, v) \
(p)[0] = (uint8_t)((v)); \
(p)[1] = (uint8_t)((v) >> 8); \
(p)[2] = (uint8_t)((v) >> 16); \
(p)[3] = (uint8_t)((v) >> 24);
#define U64TO8_LE(p, v) \
U32TO8_LE((p), (uint32_t)((v))); \
U32TO8_LE((p) + 4, (uint32_t)((v) >> 32));
#ifdef UNALIGNED_LE_CPU
#define U8TO64_LE(p) (*((uint64_t*)(p)))
#else
#define U8TO64_LE(p) \
(((uint64_t)((p)[0])) | ((uint64_t)((p)[1]) << 8) | \
((uint64_t)((p)[2]) << 16) | ((uint64_t)((p)[3]) << 24) | \
((uint64_t)((p)[4]) << 32) | ((uint64_t)((p)[5]) << 40) | \
((uint64_t)((p)[6]) << 48) | ((uint64_t)((p)[7]) << 56))
#endif
#define SIPROUND \
do { \
v0 += v1; \
v1 = ROTL(v1, 13); \
v1 ^= v0; \
v0 = ROTL(v0, 32); \
v2 += v3; \
v3 = ROTL(v3, 16); \
v3 ^= v2; \
v0 += v3; \
v3 = ROTL(v3, 21); \
v3 ^= v0; \
v2 += v1; \
v1 = ROTL(v1, 17); \
v1 ^= v2; \
v2 = ROTL(v2, 32); \
} while (0)
#if 0
#define DUMP_STATE(...) printf(__VA_ARGS__)
#else
#define DUMP_STATE(...) do {} while(0)
#endif
uint64_t siphash(const uint8_t *in, const size_t inlen,
uint64_t k0, uint64_t k1,
uint8_t cROUNDS, uint8_t dROUNDS) {
#ifndef UNALIGNED_LE_CPU
uint64_t hash;
uint8_t *out = (uint8_t*) &hash;
#endif
uint64_t v0 = SIPaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaV0;
uint64_t v1 = SIPaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaV1;
uint64_t v2 = SIPaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaV2;
uint64_t v3 = SIPaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaV3;
uint64_t m;
const uint8_t *end = in + inlen - (inlen % sizeof(uint64_t));
const int left = inlen & 7;
uint64_t b = ((uint64_t) inlen) << 56;
v3 ^= k1;
v2 ^= k0;
v1 ^= k1;
v0 ^= k0;
   DUMP_STATE("key: %016" PRIx64 ", %016" PRIx64 "\n",
k0, k1);
   DUMP_STATE("initial: %016" PRIx64 ", %016" PRIx64 ", %016" PRIx64 ", %016" PRIx64 "\n",
v0, v1, v2, v3);
for (; in != end; in += 8) {
m = U8TO64_LE(in);
       DUMP_STATE("msg blk: %016" PRIx64 "\n", m);
v3 ^= m;
       DUMP_STATE("after 1: %016" PRIx64 ", %016" PRIx64 ", %016" PRIx64 ", %016" PRIx64 "\n",
v0, v1, v2, v3);
for (uint8_t i = 0; i < cROUNDS; ++i) {
SIPROUND
;
}
       DUMP_STATE("after R: %016" PRIx64 ", %016" PRIx64 ", %016" PRIx64 ", %016" PRIx64 "\n",
v0, v1, v2, v3);
v0 ^= m;
       DUMP_STATE("after c: %016" PRIx64 ", %016" PRIx64 ", %016" PRIx64 ", %016" PRIx64 "\n",
v0, v1, v2, v3);
}
switch (left) {
case 7:
b |= ((uint64_t) in[6]) << 48; /* Falls through. */
case 6:
b |= ((uint64_t) in[5]) << 40; /* Falls through. */
case 5:
b |= ((uint64_t) in[4]) << 32; /* Falls through. */
case 4:
b |= ((uint64_t) in[3]) << 24; /* Falls through. */
case 3:
b |= ((uint64_t) in[2]) << 16; /* Falls through. */
case 2:
b |= ((uint64_t) in[1]) << 8; /* Falls through. */
case 1:
b |= ((uint64_t) in[0]);
break;
case 0:
break;
}
   DUMP_STATE("msg blk: %016" PRIx64 "\n", b);
v3 ^= b;
   DUMP_STATE("after 1: %016" PRIx64 ", %016" PRIx64 ", %016" PRIx64 ", %016" PRIx64 "\n",
v0, v1, v2, v3);
for (uint8_t i = 0; i < cROUNDS; ++i) {
SIPROUND
;
}
   DUMP_STATE("after R: %016" PRIx64 ", %016" PRIx64 ", %016" PRIx64 ", %016" PRIx64 "\n",
v0, v1, v2, v3);
v0 ^= b;
v2 ^= 0xff;
   DUMP_STATE("after c: %016" PRIx64 ", %016" PRIx64 ", %016" PRIx64 ", %016" PRIx64 "\n",
v0, v1, v2, v3);
for (uint8_t i = 0; i < dROUNDS; ++i) {
SIPROUND
;
}
   DUMP_STATE("after f: %016" PRIx64 ", %016" PRIx64 ", %016" PRIx64 ", %016" PRIx64 "\n",
v0, v1, v2, v3);
b = v0 ^ v1 ^ v2 ^ v3;
#ifndef UNALIGNED_LE_CPU
U64TO8_LE(out, b);
return hash;
#else
return b;
#endif
}
#ifndef _SSTCAM_H_
#define _SSTCAM_H_
#ifdef __cplusplus
extern "C" {
#endif
struct sstcam;
int sstcam_create(const cam_arg_t *cam_arg,
struct sstcam **out_stcam);
typedef uint16_t sstcam_mask_id_t;
#define SSTCAM_MASK_ID_NONE ((sstcam_mask_id_t) -1)
#define SSTCAM_MASK_MAX (64)
int sstcam_mask_alloc(struct sstcam *stcam,
const uint8_t mask[],
sstcam_mask_id_t *id);
int sstcam_mask_free(struct sstcam *stcam,
sstcam_mask_id_t id);
int sstcam_insert(struct sstcam *stcam,
const uint8_t key[],
sstcam_mask_id_t mask,
uint32_t priority,
const uint8_t response[]);
int sstcam_update(struct sstcam *stcam,
const uint8_t key[],
sstcam_mask_id_t mask,
const uint8_t response[]);
int sstcam_iterate(struct sstcam *stcam,
const uint8_t key[], const uint8_t key_mask[],
const uint8_t response[], const uint8_t response_mask[],
sstcam_mask_id_t mask,
uint32_t *pos,
uint8_t out_key[],
uint8_t out_response[],
sstcam_mask_id_t *out_mask,
uint32_t *out_priority);
int sstcam_delete(struct sstcam *stcam,
const uint8_t key[], sstcam_mask_id_t mask);
int sstcam_lookup(struct sstcam *stcam,
const uint8_t key[],
uint8_t response[]);
int sstcam_read_and_clear_ecc_counters(struct sstcam *stcam,
uint32_t *corrected_single_bit_errors,
uint32_t *detected_double_bit_errors);
int sstcam_read_and_clear_ecc_addresses(struct sstcam *stcam,
uint32_t *failing_address_single_bit_error,
uint32_t *failing_address_double_bit_error);
int sstcam_set_ecc_test(struct sstcam *stcam,
bool inject_single_bit_errors,
bool inject_double_bit_errors);
struct sstcam_stats_hits_per_mask {
uint32_t timestamp;
uint32_t hits[SSTCAM_MASK_MAX];
uint32_t misses;
};
struct sstcam_stats_backpressure {
uint32_t timestamp;
uint32_t request; 
};
union sstcam_stats {
struct sstcam_stats_hits_per_mask hits_per_mask;
struct sstcam_stats_backpressure backpressure;
struct sstcam_reserved {
uint8_t resv[512];
} reserved;
};
#define SSTCAM_STATS_HITS_PER_MASK (0x1000)
#define SSTCAM_STATS_BACKPRESSURE (0x1001)
int sstcam_get_stats(const struct sstcam *stcam, uint64_t stats_group, union sstcam_stats *stats);
void sstcam_destroy(struct sstcam *stcam);
#ifdef __cplusplus
}
#endif
#endif
#ifndef _SSTCAMP_H_
#define _SSTCAMP_H_
#ifndef SMH_aaaaaaaaaaaaaaaaaaaaa1aaaS_H
#define SMH_aaaaaaaaaaaaaaaaaaaaa1aaaS_H
#define SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaSCRATCH (0x2000)
#define SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaVERSION (0x2004)
#define SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaBUILD_NR (0x2008)
#define SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaHCM_SAMPLE_PERIOD (0x2100)
#define SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaREQ_WAIT_CYCLE_aaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x2104)
#define SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaHCM_SELECT (0x2108)
#define SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaHCM_aaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x210c)
#define SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaVALID_BASE (0x2110)
#define SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaVALID_WIDTH (8) 
#define SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaMCM_SELECT (0x2200)
#define SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaMISS_aaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x2204)
#define SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaMCM_BASE (0x2300)
#define SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaMCM_MASK_WIDTH (32) 
#define SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaPARAM_NUM_MASKS (0x2800)
#define SMH_HW_VERSION_MAJOR (1)
#define SMH_HW_VERSION_MEDIUM (0)
#define SMH_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa1US 0
#define SMH_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa10US 1
#define SMH_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa100US 2
#define SMH_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa1MS 3
#define SMH_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa10MS 4
#define SMH_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa100MS 5
#define SMH_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa1S 6
#define SMH_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaNO_SAMPLE 7
#endif 
struct stcam_mask {
aaaaaaaaaaaaa1aaat mask; 
int num_entries; 
int is_allocated; 
};
struct sstcam {
struct cam_arg_t arg; 
struct bcam *bcam; 
struct stcam_mask *masks; 
uint32_t mask_valid[SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaVALID_WIDTH];
uint32_t hw_mask_id_width;
};
#endif 
#define MASK_ID_WIDTH 10
static void *sstcam_malloc(const struct sstcam *stcam, size_t size)
{
return stcam->arg.malloc_function(size);
}
static void sstcam_free(const struct sstcam *stcam, void *ptr)
{
stcam->arg.free_function(ptr);
}
static int sstcam_printf(const struct sstcam *stcam, const char *fmt, ...)
{
char buffer[4096];
va_list args;
va_start(args, fmt);
int rc = vsnprintf(buffer, sizeof buffer, fmt, args);
va_end(args);
stcam->arg.info_print_function(stcam->arg.segment_ctx.ctx, buffer);
return rc;
}
static uint32_t sstcam_read(const struct sstcam *stcam, uint32_t addr)
{
uint32_t value;
stcam->arg.io[0].hw_read_function(stcam->arg.segment_ctx.ctx, addr, &value);
return value;
}
static void sstcam_write(const struct sstcam *stcam, uint32_t addr, uint32_t value)
{
stcam->arg.io[0].hw_write_function(stcam->arg.segment_ctx.ctx, addr, value);
}
static uint32_t ceil_log2(uint32_t value)
{
for(int i = 0; i < 31; i++)
if(((uint32_t) 1 << i) >= value)
return i;
assert(0);
return 0;
}
int sstcam_create(const cam_arg_t *cam_arg,
struct sstcam **out_stcam)
{
int rv;
struct sstcam *stcam;
struct cam_arg_t arg = *cam_arg;
struct cam_arg_t bcam_arg = arg;
cam_arg_set_num_masks(&bcam_arg, 0);
cam_arg_set_key_width(&bcam_arg, arg.key_width + MASK_ID_WIDTH);
if (cam_arg->calc_heap_size) {
size_t bcam_heap_size = bcam_create(&bcam_arg, NULL);
size_t our_heap_size = (sizeof *stcam) + (arg.num_masks * sizeof *stcam->masks);
return bcam_heap_size + our_heap_size;
}
stcam = arg.malloc_function(sizeof *stcam);
if(!stcam) return CAM_ERROR_MALLOC_FAILED;
memset(stcam, 0, sizeof *stcam);
stcam->arg = arg;
const uint32_t scratch_val = 0x1e958b48;
sstcam_write(stcam, SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaSCRATCH, scratch_val);
const uint32_t scratch_aaaaaaaaaaaaaaaaaaaaa1aaa = sstcam_read(stcam, SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaSCRATCH);
if(scratch_aaaaaaaaaaaaaaaaaaaaa1aaa != scratch_val) {
       sstcam_printf(stcam, "DRAM STCAM: Scratch readback failed: got 0x%x, expected 0x%x",
scratch_aaaaaaaaaaaaaaaaaaaaa1aaa, scratch_val);
rv = CAM_ERROR_CONFIGURATION;
goto out_error_1;
}
const uint32_t version = sstcam_read(stcam, SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaVERSION);
const uint32_t build = sstcam_read(stcam, SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaBUILD_NR);
const uint8_t major = (version & 0xff00) >> 8;
const uint8_t medium = (version & 0x00f0) >> 4;
const uint8_t minor = version & 0xf;
if (stcam->arg.debug_flags & CAM_DEBUG_VERBOSE_VERIFY) {
       sstcam_printf(stcam, "DRAM STCAM: HW version: %d.%d%d Build: %d",
major, medium, minor, build);
}
if ((major != SMH_HW_VERSION_MAJOR) ||
(medium != SMH_HW_VERSION_MEDIUM)) {
       sstcam_printf(stcam, "DRAM STCAM: Version mismatch: expected hardware version %d.%dx",
SMH_HW_VERSION_MAJOR, SMH_HW_VERSION_MEDIUM);
rv = CAM_ERROR_CONFIGURATION;
goto out_error_1;
}
const uint32_t num_masks = sstcam_read(stcam, SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaPARAM_NUM_MASKS);
stcam->hw_mask_id_width = ceil_log2(num_masks);
if (stcam->arg.debug_flags & CAM_DEBUG_VERBOSE_VERIFY) {
       sstcam_printf(stcam, "DRAM STCAM: Key width %d, n_masks %d",
stcam->arg.key_width, num_masks);
       sstcam_printf(stcam, "DRAM STCAM: Mask ID width %d (SW), %d (HW)",
MASK_ID_WIDTH, stcam->hw_mask_id_width);
}
cam_arg_set_key_width(&bcam_arg, stcam->arg.key_width + stcam->hw_mask_id_width);
cam_arg_set_num_masks(&stcam->arg, num_masks);
sstcam_write(stcam, SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaHCM_SAMPLE_PERIOD, SMH_aaaaaaaaaaaaaaaaaaaaaaaaaaa1aaa1S);
stcam->masks = sstcam_malloc(stcam, stcam->arg.num_masks * sizeof *stcam->masks);
if(!stcam->masks) {
rv = CAM_ERROR_MALLOC_FAILED;
goto out_error_1;
}
memset(stcam->masks, 0, stcam->arg.num_masks * sizeof *stcam->masks);
memset(stcam->mask_valid, 0, sizeof stcam->mask_valid);
for (int i = 0; i < SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaVALID_WIDTH; i++)
sstcam_write(stcam, SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaVALID_BASE + (4 * i), 0);
rv = bcam_create(&bcam_arg, &stcam->bcam);
if(rv) {
       sstcam_printf(stcam, "bcam_create failed: %d", rv);
goto out_error_2;
}
*out_stcam = stcam;
return 0;
out_error_2:
sstcam_free(stcam, stcam->masks);
out_error_1:
sstcam_free(stcam, stcam);
return rv;
}
void sstcam_destroy(struct sstcam *stcam)
{
sstcam_free(stcam, stcam->masks);
bcam_destroy(stcam->bcam);
sstcam_free(stcam, stcam);
}
static void sstcam_set_mask_valid(struct sstcam *stcam,
sstcam_mask_id_t mask,
int valid)
{
const uint32_t aaaaaaaaaaaaaaaaaaaaaa1aaa = mask / 32;
const uint32_t bit = 1 << (mask - (aaaaaaaaaaaaaaaaaaaaaa1aaa * 32));
if (valid)
stcam->mask_valid[aaaaaaaaaaaaaaaaaaaaaa1aaa] |= bit;
else
stcam->mask_valid[aaaaaaaaaaaaaaaaaaaaaa1aaa] &= ~bit;
sstcam_write(stcam,
SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaVALID_BASE + (4 * aaaaaaaaaaaaaaaaaaaaaa1aaa),
stcam->mask_valid[aaaaaaaaaaaaaaaaaaaaaa1aaa]);
}
static void sstcam_write_mask_to_hw(struct sstcam *stcam,
sstcam_mask_id_t id)
{
const int n_words = (stcam->arg.key_width + 31) / 32;
int i;
sstcam_write(stcam, SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaMCM_SELECT, id);
for (i = 0; i < n_words; i++)
sstcam_write(stcam,
SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaMCM_BASE + (sizeof(uint32_t) * i),
stcam->masks[id].mask.word[i]);
}
int sstcam_mask_alloc(struct sstcam *stcam,
const uint8_t mask[],
sstcam_mask_id_t *id)
{
int i;
for(i = 0; i < stcam->arg.num_masks; i++)
{
if (!stcam->masks[i].is_allocated)
break;
}
if (i == stcam->arg.num_masks)
return CAM_ERROR_FULL;
assert(stcam->masks[i].num_entries == 0);
stcam->masks[i].is_allocated = true;
cam_copy_bits((uint8_t *)&stcam->masks[i].mask, mask, stcam->arg.key_width);
sstcam_write_mask_to_hw(stcam, i);
sstcam_set_mask_valid(stcam, i, 1);
*id = i;
return 0;
}
int sstcam_mask_free(struct sstcam *stcam,
sstcam_mask_id_t id)
{
if (!stcam->masks[id].is_allocated)
return CAM_ERROR_INVALID_ARG;
if (stcam->masks[id].num_entries != 0)
return CAM_ERROR_NOT_EMPTY;
sstcam_set_mask_valid(stcam, id, 0);
stcam->masks[id].is_allocated = 0;
return 0;
}
static void sstcam_print_bits(const struct sstcam *stcam,
const char *label, size_t width, const uint8_t *data)
{
char *str = byte_arr_to_str(width, data, stcam->arg.malloc_function);
   sstcam_printf(stcam, "%s: %s", label, str);
sstcam_free(stcam, str);
}
static void sstcam_construct_key(struct sstcam *stcam,
aaaaaaaaaaaaa1aaat *key_out,
const uint8_t key_in[],
sstcam_mask_id_t mask)
{
const int n_words = (stcam->arg.key_width + 31) / 32;
int i;
uint32_t tmp[1] = { mask };
cam_copy_bits((uint8_t *)key_out, key_in, stcam->arg.key_width);
if (stcam->arg.debug_flags & CAM_DEBUG_ARGS)
{
       sstcam_printf(stcam, "Mask ID: 0x%x", mask);
       sstcam_print_bits(stcam, "Input key", stcam->arg.key_width, (uint8_t *)key_out);
       sstcam_print_bits(stcam, "Mask     ", stcam->arg.key_width, (uint8_t *)&(stcam->masks[mask].mask));
}
for (i = 0; i < n_words; i++)
key_out->word[i] &= stcam->masks[mask].mask.word[i];
cam_write_field(key_out->word, stcam->arg.key_width, stcam->arg.key_width + stcam->hw_mask_id_width,
tmp, stcam->arg.key_width + stcam->hw_mask_id_width);
if (stcam->arg.debug_flags & CAM_DEBUG_ARGS)
{
       sstcam_print_bits(stcam, "BCAM key ", stcam->arg.key_width + stcam->hw_mask_id_width, (uint8_t *)key_out);
}
}
int sstcam_insert(struct sstcam *stcam,
const uint8_t key[],
sstcam_mask_id_t mask,
uint32_t priority,
const uint8_t response[])
{
(void) priority; 
aaaaaaaaaaaaa1aaat bcam_key = {{0}};
int rv;
if ((stcam == NULL) ||
(key == NULL) ||
(response == NULL))
return CAM_ERROR_INVALID_ARG;
if (mask >= stcam->arg.num_masks)
return CAM_ERROR_INVALID_ARG;
if (!stcam->masks[mask].is_allocated)
return CAM_ERROR_INVALID_ARG;
sstcam_construct_key(stcam, &bcam_key, key, mask);
rv = bcam_insert(stcam->bcam, (const uint8_t *)&bcam_key, response);
if (rv == 0)
{
stcam->masks[mask].num_entries++;
}
return rv;
}
int sstcam_update(struct sstcam *stcam,
const uint8_t key[],
sstcam_mask_id_t mask,
const uint8_t response[])
{
aaaaaaaaaaaaa1aaat bcam_key = {{0}};
int rv;
if ((stcam == NULL) ||
(key == NULL) ||
(response == NULL))
return CAM_ERROR_INVALID_ARG;
if (mask >= stcam->arg.num_masks)
return CAM_ERROR_INVALID_ARG;
if (!stcam->masks[mask].is_allocated)
return CAM_ERROR_INVALID_ARG;
sstcam_construct_key(stcam, &bcam_key, key, mask);
rv = bcam_update(stcam->bcam, (const uint8_t *)&bcam_key, response);
return rv;
}
int sstcam_delete(struct sstcam *stcam,
const uint8_t key[],
sstcam_mask_id_t mask)
{
aaaaaaaaaaaaa1aaat bcam_key = {{0}};
int rv;
if ((stcam == NULL) ||
(key == NULL))
return CAM_ERROR_INVALID_ARG;
if (mask >= stcam->arg.num_masks)
return CAM_ERROR_INVALID_ARG;
if (!stcam->masks[mask].is_allocated)
return CAM_ERROR_INVALID_ARG;
sstcam_construct_key(stcam, &bcam_key, key, mask);
rv = bcam_delete(stcam->bcam, (const uint8_t *)&bcam_key);
if (rv == 0)
{
assert(stcam->masks[mask].num_entries > 0);
stcam->masks[mask].num_entries--;
}
return rv;
}
int sstcam_lookup(struct sstcam *stcam,
const uint8_t key[],
uint8_t response[])
{
aaaaaaaaaaaaa1aaat bcam_key = {{0}};
int rv;
int i;
if ((stcam == NULL) ||
(key == NULL) ||
(response == NULL))
return CAM_ERROR_INVALID_ARG;
for (i = 0; i < stcam->arg.num_masks; i++)
{
if(stcam->masks[i].num_entries == 0)
continue;
sstcam_construct_key(stcam, &bcam_key, key, i);
rv = bcam_get_by_key(stcam->bcam, (const uint8_t *)&bcam_key, response);
if (rv == 0)
return 0;
}
return CAM_ERROR_KEY_NOT_FOUND;
}
int sstcam_iterate(struct sstcam *stcam,
const uint8_t key[], const uint8_t key_mask[],
const uint8_t response[], const uint8_t response_mask[],
sstcam_mask_id_t mask,
uint32_t *pos,
uint8_t out_key[],
uint8_t out_response[],
sstcam_mask_id_t *out_mask,
uint32_t *out_priority)
{
aaaaaaaaaaaaa1aaat bcam_key, baaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa, baaaaaaaaaaaaa1aaaout;
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat baaaaaaaaaaaaaaaa1aaa, baaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, baaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaout;
if (stcam == NULL)
return CAM_ERROR_INVALID_ARG;
memset(&bcam_key, 0, sizeof bcam_key);
memset(&baaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa, 0, sizeof baaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa);
if (key && key_mask)
{
cam_copy_bits((uint8_t *)&bcam_key, key, stcam->arg.key_width);
cam_copy_bits((uint8_t *)&baaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa, key_mask, stcam->arg.key_width);
}
if (mask != SSTCAM_MASK_ID_NONE)
{
uint32_t tmp[1] = { mask };
if (mask >= stcam->arg.num_masks)
return CAM_ERROR_INVALID_ARG;
cam_write_field(bcam_key.word, stcam->arg.key_width, stcam->arg.key_width + stcam->hw_mask_id_width,
tmp, stcam->arg.key_width + stcam->hw_mask_id_width);
tmp[0] = ~0;
cam_write_field(baaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa.word, stcam->arg.key_width, stcam->arg.key_width + stcam->hw_mask_id_width,
tmp, stcam->arg.key_width + stcam->hw_mask_id_width);
}
memset(&baaaaaaaaaaaaaaaa1aaa, 0, sizeof baaaaaaaaaaaaaaaa1aaa);
memset(&baaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, 0, sizeof baaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
if (response && response_mask)
{
cam_copy_bits((uint8_t *)&baaaaaaaaaaaaaaaa1aaa, response, stcam->arg.response_width);
cam_copy_bits((uint8_t *)&baaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, response_mask, stcam->arg.response_width);
}
int rv = bcam_get_by_key_and_response(stcam->bcam,
(const uint8_t *)&bcam_key,
(const uint8_t *)&baaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaa,
(const uint8_t *)&baaaaaaaaaaaaaaaa1aaa,
(const uint8_t *)&baaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa,
pos,
(uint8_t *)&baaaaaaaaaaaaa1aaaout,
(uint8_t *)&baaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaout);
if (rv == 0)
{
if (out_key)
{
cam_copy_bits(out_key, (const uint8_t *)&baaaaaaaaaaaaa1aaaout, stcam->arg.key_width);
}
if (out_response)
{
cam_copy_bits(out_response, (const uint8_t *)&baaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaout, stcam->arg.response_width);
}
if (out_priority)
*out_priority = 0;
if (out_mask)
{
uint32_t tmp[1];
cam_read_field(baaaaaaaaaaaaa1aaaout.word,
stcam->arg.key_width, stcam->arg.key_width + stcam->hw_mask_id_width - 1,
tmp);
*out_mask = tmp[0];
}
}
return rv;
}
int sstcam_read_and_clear_ecc_counters(struct sstcam *stcam,
uint32_t *corrected_single_bit_errors,
uint32_t *detected_double_bit_errors)
{
(void) stcam; 
*corrected_single_bit_errors = 0;
*detected_double_bit_errors = 0;
return 0;
}
int sstcam_read_and_clear_ecc_addresses(struct sstcam *stcam,
uint32_t *failing_address_single_bit_error,
uint32_t *failing_address_double_bit_error)
{
(void) stcam; 
*failing_address_single_bit_error = 0;
*failing_address_double_bit_error = 0;
return 0;
}
int sstcam_set_ecc_test(struct sstcam *stcam,
bool inject_single_bit_errors,
bool inject_double_bit_errors)
{
(void) stcam;
(void) inject_single_bit_errors;
(void) inject_double_bit_errors;
return 0;
}
static inline unsigned sstcam_counter_timestamp(uint32_t value)
{
return (value >> 26) & 0x3f;
}
static inline unsigned sstcam_counter_value(uint32_t value)
{
return (value & 0x3ffffff) * 16;
}
static int sstcam_try_hits_and_misses(const struct sstcam *stcam, struct sstcam_stats_hits_per_mask *stats)
{
int i;
const uint32_t miss_counter = sstcam_read(stcam, SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaMISS_aaaaaaaaaaaaaaaaaaaaaaaa1aaa);
unsigned timestamp = sstcam_counter_timestamp(miss_counter);
stats->misses = sstcam_counter_value(miss_counter);
for (i = 0; i < stcam->arg.num_masks; i++)
{
sstcam_write(stcam, SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaHCM_SELECT, i);
const uint32_t hcm_val = sstcam_read(stcam, SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaHCM_aaaaaaaaaaaaaaaaaaaaaaaa1aaa);
const unsigned hcm_timestamp = sstcam_counter_timestamp(hcm_val);
if (hcm_timestamp != timestamp)
return -1;
stats->hits[i] = sstcam_counter_value(hcm_val);
}
stats->timestamp = timestamp;
return 0;
}
static int sstcam_hits_per_mask(const struct sstcam *stcam, struct sstcam_stats_hits_per_mask *stats)
{
if (sstcam_try_hits_and_misses(stcam, stats) == 0)
return 0;
if (sstcam_try_hits_and_misses(stcam, stats) == 0)
return 0;
return CAM_ERROR_ENVIRONMENT;
}
static int sstcam_backpressure(const struct sstcam *stcam, struct sstcam_stats_backpressure *stats)
{
const uint32_t req_counter = sstcam_read(stcam, SMH_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaREQ_WAIT_CYCLE_aaaaaaaaaaaaaaaaaaaaaaaa1aaa);
stats->timestamp = sstcam_counter_timestamp(req_counter);
stats->request = sstcam_counter_value(req_counter);
return 0;
}
int sstcam_get_stats(const struct sstcam *stcam, uint64_t stats_group, union sstcam_stats *stats)
{
if((stcam == NULL) ||
(stats == NULL))
return CAM_ERROR_INVALID_ARG;
memset(stats, 0, sizeof *stats);
switch(stats_group) {
case SSTCAM_STATS_HITS_PER_MASK: return sstcam_hits_per_mask(stcam, &stats->hits_per_mask);
case SSTCAM_STATS_BACKPRESSURE: return sstcam_backpressure(stcam, &stats->backpressure);
default: return CAM_ERROR_INVALID_ARG;
}
}
#ifndef _STCAM_H_
#define _STCAM_H_
#ifdef __cplusplus
extern "C" {
#endif
struct stcam;
int
stcam_create(const cam_arg_t *cam_arg, struct stcam **out_stcam);
int stcam_insert(struct stcam *stcam, const uint8_t key[], const uint8_t mask[], uint32_t priority,
const uint8_t response[]);
int stcam_update(struct stcam *stcam, const uint8_t key[], const uint8_t mask[], const uint8_t response[]);
int stcam_get_by_response(struct stcam *stcam, const uint8_t response[], const uint8_t response_mask[], uint32_t *pos,
uint8_t out_key[], uint8_t out_mask[]);
int stcam_get_by_key(struct stcam *stcam, const uint8_t key[], const uint8_t mask[], uint32_t *priority,
uint8_t response[]);
int stcam_delete(struct stcam *stcam, const uint8_t key[], const uint8_t mask[]);
int stcam_lookup(struct stcam *stcam, const uint8_t key[], uint8_t response[]);
int stcam_delete_all(struct stcam *stcam);
int stcam_read_and_clear_ecc_counters(struct stcam *stcam, uint32_t *corrected_single_bit_errors,
uint32_t *detected_double_bit_errors);
int stcam_read_and_clear_ecc_addresses(struct stcam *stcam, uint32_t *failing_address_single_bit_error,
uint32_t *failing_address_double_bit_error);
int stcam_set_ecc_test(struct stcam *stcam, bool inject_single_bit_errors, bool inject_double_bit_errors);
void stcam_destroy(struct stcam *stcam);
#define STCAM_STATS_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP 2
#define STCAM_STATS_SW 4
union stcam_stats {
struct cam_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup;
struct cam_sw sw;
struct stcam_reserved {
uint8_t resv[512];
} reserved;
};
int stcam_get_stats(const struct stcam *stcam, uint64_t stats_group, union stcam_stats *stats);
#ifdef __cplusplus
}
#endif
#endif
typedef struct client_t stcam;
static void stcam_print_entry(int error_code, const char *function, const struct stcam *stcam,
const uint8_t key[], const uint8_t mask[],
uint32_t *prio, const uint8_t response[], const char *match)
{
client_t * client = (client_t *) stcam;
if (error_code && (client_get_debug_flags(client) & CAM_DEBUG_NO_ERROR_MSG))
return;
if (!error_code && !(client_get_debug_flags(client) & CAM_DEBUG_ARGS))
return;
const uint16_t key_width = client_get_key_width(client);
const uint16_t prio_width = client_get_prio_width(client);
assert(prio_width <= 32);
const uint16_t response_width = client_get_response_width(client);
char message[1000];
cam_free_func free_function = client_get_free_function((client_t*) (client));
cam_malloc_func malloc_function = client_get_malloc_function(client);
char *key_str;
if (key != NULL) {
key_str = byte_arr_to_str(key_width, key, malloc_function);
} else {
       key_str = (char *) "N/A";
}
char *mask_str;
if (mask != NULL) {
mask_str = byte_arr_to_str(key_width, mask, malloc_function);
} else {
       mask_str = (char *) "N/A";
}
char *prio_str;
if (prio != NULL) {
prio_str = byte_arr_to_str(prio_width, (uint8_t *) prio, malloc_function);
} else {
       prio_str = (char *) "N/A";
}
char *response_str;
if (response != NULL) {
response_str = byte_arr_to_str(response_width, response, malloc_function);
} else {
       response_str = (char *) "N/A";
}
if (!error_code && (client_get_debug_flags(client) & CAM_DEBUG_ARGS)) {
       sprintf(message, "%-22s key  = %s  response = %s  priority = %s  %8s\n%32s mask = %s",
               function, key_str, response_str, prio_str, match, " ", mask_str);
client_print_info(client, message);
}
if (error_code) {
       sprintf(message, "%-22s key  = %s  response = %s  priority = %s   %8s\n%32s mask = %s\n\n%10s%-22s num_entries = %0"PRIu32"   (%0"PRIu32" used)\n%32s num_masks = %0"PRIu16"\n%32s num_units = %0"PRIu16"  (%0"PRIu16" used)",
function, key_str, response_str, prio_str, cam_error_string(error_code),
               " ", mask_str,
               " ",
               "stcam resources", client_get_num_entries(client), client_get_current_num_entries(client),
               " ", client_get_num_masks(client),
               " ", client_get_num_units(client), client_get_current_num_units(client));
client_print_error(client, message);
}
if (prio != NULL)
free_function(prio_str);
if (response != NULL)
free_function(response_str);
if (mask != NULL)
free_function(mask_str);
if (key != NULL)
free_function(key_str);
}
int
stcam_create(const cam_arg_t *cam_arg, struct stcam **out_stcam)
{
int rc;
if (cam_arg->calc_heap_size) {
cam_config_t *cam_conf_heap = alloca(cam_config_size());
rc = cam_config_init(cam_arg, STCAM, cam_conf_heap);
if (rc) {
if ((cam_arg->debug_flags & CAM_DEBUG_NO_ERROR_MSG) == 0) {
cam_print_error(rc);
}
return rc;
}
const uint32_t client_heap_size = cam_config_calculate_heap_size(
cam_conf_heap);
return client_heap_size;
}
cam_arg_t cam_arg_copy = *cam_arg;
client_t *client;
rc = client_create_bcam(&cam_arg_copy, STCAM, &client);
if (rc) {
if ((cam_arg->debug_flags & CAM_DEBUG_NO_ERROR_MSG) == 0) {
cam_print_error(rc);
}
return rc;
}
*out_stcam = (struct stcam*) client;
return 0;
}
int
stcam_update(struct stcam *stcam, const uint8_t key[], const uint8_t mask[], const uint8_t response[])
{
   stcam_print_entry(0, "stcam_update", stcam, key, mask, NULL, response, "");
aaaaaaaaaaaaa1aaat new_mask;
aaaaaaaaaaaaa1aaat new_key;
memset(&new_key, 0, sizeof(aaaaaaaaaaaaa1aaat));
memset(&new_mask, 0, sizeof(aaaaaaaaaaaaa1aaat));
const uint16_t key_width = client_get_key_width((client_t *) stcam);
cam_copy_bits((uint8_t *) &new_key.word[0], key, key_width);
cam_copy_bits((uint8_t *) &new_mask.word[0], mask, key_width);
if ((client_get_debug_flags((client_t *) stcam) & CAM_DEBUG_KEY_MASKING) == 0) {
cam_mask_key(&new_key, &new_mask);
}
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat new_response;
memset(&new_response, 0, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
const uint16_t response_width = client_get_response_width((client_t *) stcam);
cam_copy_bits((uint8_t *) &new_response.word[0], response, response_width);
cam_options_t *options = (cam_options_t *) alloca(cam_options_size());
cam_options_init(options);
const int rc = client_update_key((client_t *) stcam, &new_key, &new_response, &new_mask, options);
if (rc) {
       stcam_print_entry(rc, "stcam_update", stcam, key, mask, NULL, response, "");
}
return rc;
}
int stcam_insert(struct stcam *stcam, const uint8_t key[], const uint8_t mask[], uint32_t priority,
const uint8_t response[])
{
   stcam_print_entry(0, "stcam_insert", stcam, key, mask, &priority, response, "");
const uint8_t prio_width = client_get_prio_width((client_t *) stcam);
assert(prio_width <= 32);
const uint64_t prio_range = ((uint64_t) priority) >> prio_width;
if (prio_range > 0) {
       stcam_print_entry(CAM_ERROR_WRONG_PRIO_WIDTH, "stcam_insert", stcam, key, mask, &priority, response, "");
return CAM_ERROR_WRONG_PRIO_WIDTH;
}
aaaaaaaaaaaaa1aaat new_mask;
aaaaaaaaaaaaa1aaat new_key;
memset(&new_key, 0, sizeof(aaaaaaaaaaaaa1aaat));
memset(&new_mask, 0, sizeof(aaaaaaaaaaaaa1aaat));
const uint16_t key_width = client_get_key_width((client_t *) stcam);
cam_copy_bits((uint8_t *) &new_key.word[0], key, key_width);
cam_copy_bits((uint8_t *) &new_mask.word[0], mask, key_width);
if ((client_get_debug_flags((client_t *) stcam) & CAM_DEBUG_KEY_MASKING) == 0) {
cam_mask_key(&new_key, &new_mask);
}
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat prio_resp;
const uint16_t response_width = client_get_response_width((client_t *) stcam);
memset(&prio_resp, 0, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
cam_copy_bits((uint8_t *) &prio_resp.word[0], response, response_width);
if (prio_width > 0) {
const uint32_t new_prio = priority;
cam_write_field((uint32_t *) &prio_resp, response_width, response_width + prio_width - 1, &new_prio,
CAM_MAX_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa - 1);
}
cam_options_t *options = (cam_options_t *) alloca(cam_options_size());
cam_options_init(options);
const int rc = client_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa((client_t *) stcam, &new_key, &prio_resp, &new_mask, options);
if (rc) {
       stcam_print_entry(rc, "stcam_insert", stcam, key, mask, &priority, response, "");
}
return rc;
}
int
stcam_get_by_response(struct stcam *stcam, const uint8_t response[], const uint8_t response_mask[], uint32_t *pos,
uint8_t out_key[],
uint8_t out_mask[])
{
aaaaaaaaaaaaa1aaat old_mask, old_key;
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat new_response;
memset(&new_response, 0, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
const uint16_t response_width = client_get_response_width((client_t *) stcam);
cam_copy_bits((uint8_t *) &new_response.word[0], response, response_width);
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat new_response_mask;
memset(&new_response_mask, 0, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
cam_copy_bits((uint8_t *) &new_response_mask.word[0], response_mask, response_width);
const int rc = client_read_response_for_key((client_t *) stcam, &new_response, &new_response_mask, pos, &old_key,
&old_mask, false);
if (rc && (rc != CAM_ERROR_FOUND_IN_SHADOW_BUT_NOT_IN_HW)) {
       stcam_print_entry(rc, "stcam_get_by_response", stcam, NULL, NULL, NULL, response, "");
return rc;
}
const uint16_t key_width = client_get_key_width((client_t *) stcam);
uint8_t num_bytes = key_width / 8;
const uint16_t remaining_bits = key_width - num_bytes * 8;
if (remaining_bits > 0) {
out_key[num_bytes] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa8(out_key[num_bytes], *((uint8_t *) &old_key + num_bytes), 0, remaining_bits);
out_mask[num_bytes] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa8(out_mask[num_bytes], *((uint8_t *) &old_mask + num_bytes), 0, remaining_bits);
}
memcpy(out_key, &old_key, num_bytes);
memcpy(out_mask, &old_mask, num_bytes);
   stcam_print_entry(rc, "stcam_get_by_response", stcam, out_key, out_mask, NULL, response, "");
return rc;
}
int
stcam_get_by_key(struct stcam *stcam, const uint8_t key[], const uint8_t mask[], uint32_t *priority,
uint8_t response[])
{
aaaaaaaaaaaaa1aaat new_mask;
aaaaaaaaaaaaa1aaat new_key;
memset(&new_key, 0, sizeof(aaaaaaaaaaaaa1aaat));
memset(&new_mask, 0, sizeof(aaaaaaaaaaaaa1aaat));
const uint16_t key_width = client_get_key_width((client_t *) stcam);
cam_copy_bits((uint8_t *) &new_key.word[0], key, key_width);
cam_copy_bits((uint8_t *) &new_mask.word[0], mask, key_width);
if ((client_get_debug_flags((client_t *) stcam) & CAM_DEBUG_KEY_MASKING) == 0) {
cam_mask_key(&new_key, &new_mask);
}
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat old_response;
cam_options_t *options = (cam_options_t *) alloca(cam_options_size());
cam_options_init(options);
int rc = client_read_key((client_t *) stcam, &new_key, &old_response, &new_mask, options);
if (rc && (rc != CAM_ERROR_FOUND_IN_SHADOW_BUT_NOT_IN_HW)) {
       stcam_print_entry(rc, "stcam_get_by_key", stcam, key, mask, NULL, NULL, "");
return rc;
}
const uint16_t response_width = client_get_response_width((client_t *) stcam);
const uint8_t prio_width = client_get_prio_width((client_t *) stcam);
assert(prio_width <= 32);
if (prio_width) {
cam_read_field((uint32_t *) &old_response, response_width, response_width + prio_width - 1, priority);
} else {
*priority = 0;
}
const uint8_t num_bytes = response_width / 8;
const uint16_t remaining_bits = response_width - num_bytes * 8;
if (remaining_bits > 0) {
response[num_bytes] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa8(response[num_bytes], *((uint8_t *) &old_response + num_bytes), 0,
remaining_bits);
}
memcpy(response, &old_response, num_bytes);
   stcam_print_entry(rc, "stcam_get_by_key", stcam, key, mask, priority, response, "");
return rc;
}
int
stcam_delete(struct stcam *stcam, const uint8_t key[], const uint8_t mask[])
{
   stcam_print_entry(0, "stcam_delete", stcam, key, mask, NULL, NULL, "");
aaaaaaaaaaaaa1aaat new_mask;
aaaaaaaaaaaaa1aaat new_key;
memset(&new_key, 0, sizeof(aaaaaaaaaaaaa1aaat));
memset(&new_mask, 0, sizeof(aaaaaaaaaaaaa1aaat));
const uint16_t key_width = client_get_key_width((client_t *) stcam);
cam_copy_bits((uint8_t *) &new_key.word[0], key, key_width);
cam_copy_bits((uint8_t *) &new_mask.word[0], mask, key_width);
if ((client_get_debug_flags((client_t *) stcam) & CAM_DEBUG_KEY_MASKING) == 0) {
cam_mask_key(&new_key, &new_mask);
}
cam_options_t *options = (cam_options_t *) alloca(cam_options_size());
cam_options_init(options);
const int rc = client_delete_key((client_t *) stcam, &new_key, &new_mask, options);
if (rc) {
       stcam_print_entry(rc, "stcam_delete", stcam, key, mask, NULL, NULL, "");
}
return rc;
}
int stcam_delete_all(struct stcam *stcam) {
int rc = 0;
client_delete_all((client_t *) stcam);
   stcam_print_entry(rc, "stcam_delete_all", stcam, NULL, NULL, NULL, NULL, "");
return rc;
}
int stcam_lookup(struct stcam *stcam, const uint8_t key[], uint8_t response[])
{
int rc;
aaaaaaaaaaaaa1aaat new_key;
memset(&new_key, 0, sizeof(aaaaaaaaaaaaa1aaat));
const uint16_t key_width = client_get_key_width((client_t *) stcam);
cam_copy_bits((uint8_t *) &new_key.word[0], key, key_width);
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat prio_resp;
rc = client_lookup_stcam((client_t *) stcam, &new_key, &prio_resp, false);
if (rc == CAM_ERROR_KEY_NOT_FOUND) {
client_get_default_response((client_t *) stcam, (uint8_t *) &prio_resp, false);
}
else if (rc) {
       stcam_print_entry(rc, "stcam_lookup", stcam, key, NULL, NULL, NULL, "");
return rc;
}
const uint16_t response_width = client_get_response_width((client_t *) stcam);
const uint8_t num_bytes = response_width / 8;
const uint16_t remaining_bits = response_width - num_bytes * 8;
if (remaining_bits > 0) {
response[num_bytes] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa8(response[num_bytes], *((uint8_t *) &prio_resp + num_bytes), 0, remaining_bits);
}
memcpy(response, &prio_resp, num_bytes);
uint32_t prio;
const uint8_t prio_width = client_get_prio_width((client_t *) stcam);
assert(prio_width <= 32);
if (prio_width) {
cam_read_field((uint32_t *) &prio_resp, response_width, response_width + prio_width - 1, &prio);
} else {
prio = 0;
}
   stcam_print_entry(0, "stcam_lookup", stcam, key, NULL, &prio, response, rc ? "DEFAULT_MATCH" : "KEY_MATCH");
return rc;
}
int stcam_read_and_clear_ecc_counters(struct stcam *stcam,
uint32_t *corrected_single_bit_errors,
uint32_t *detected_double_bit_errors)
{
   stcam_print_entry(0, "stcam_read_and_clear_ecc_counters", stcam, NULL, NULL, NULL, NULL, "");
return client_read_and_clear_ecc_counters((client_t *) stcam,
corrected_single_bit_errors,
detected_double_bit_errors);
}
int stcam_read_and_clear_ecc_addresses(struct stcam *stcam,
uint32_t *failing_address_single_bit_error,
uint32_t *failing_address_double_bit_error)
{
   stcam_print_entry(0, "stcam_read_and_clear_ecc_addresses", stcam, NULL, NULL, NULL, NULL, "");
return client_read_and_clear_ecc_addresses((client_t *) stcam,
failing_address_single_bit_error,
failing_address_double_bit_error);
}
int stcam_set_ecc_test(struct stcam *stcam,
bool inject_single_bit_errors,
bool inject_double_bit_errors)
{
   stcam_print_entry(0, "stcam_set_ecc_test", stcam, NULL, NULL, NULL, NULL, "");
return client_set_ecc_test((client_t *) stcam,
inject_single_bit_errors,
inject_double_bit_errors);
}
void
stcam_destroy(struct stcam *stcam)
{
client_destroy_bcam((client_t *) stcam);
}
int stcam_get_stats(const struct stcam *stcam, uint64_t group, union stcam_stats *stats) {
NULL_CHECK(stcam);
NULL_CHECK(stats);
const uint16_t MSG_SZ = 600;
int rc = 0;
if (group == STCAM_STATS_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP) {
rc = client_read_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup_data((client_t *) stcam, &stats->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup);
if (rc) {
goto end;
}
} else if (group == STCAM_STATS_SW) {
client_get_sw_stats((client_t *) stcam, &stats->sw);
} else {
rc = CAM_ERROR_INVALID_ARG;
goto end;
}
if (client_get_debug_flags((client_t *) stcam) & CAM_DEBUG_STATS) {
char message[MSG_SZ];
if (group == STCAM_STATS_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP) {
char *key_str;
char *response_str;
const cam_malloc_func malloc_function = client_get_malloc_function((client_t*) stcam);
const cam_free_func free_function = client_get_free_function((client_t *) stcam);
const uint16_t key_width = client_get_key_width((client_t *) stcam);
const uint16_t response_width = client_get_response_width((client_t *) stcam);
key_str = byte_arr_to_str(key_width, stats->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup.key, malloc_function);
response_str = byte_arr_to_str(response_width, stats->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup.response, malloc_function);
           snprintf(message, sizeof(message), "last key = %s", key_str);
client_print_info((client_t *) stcam, message);
           snprintf(message, sizeof(message), "last response = %s", response_str);
client_print_info((client_t *) stcam, message);
           snprintf(message, sizeof(message), "last status = %" PRIu32, stats->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup.status);
client_print_info((client_t *) stcam, message);
free_function(key_str);
free_function(response_str);
} else if (group == STCAM_STATS_SW) {
snprintf(message, sizeof(message),
                   "CAM_DEBUG_STATS  inserts = %" PRIu64 " (%0"PRIu32" fail)   collisions = %" PRIu64 "/%0"PRIu16" (total/max)",
stats->sw.num_inserts, stats->sw.failed_inserts, stats->sw.num_collisions,
stats->sw.max_collisions);
client_print_info((client_t *) stcam, message);
           snprintf(message, sizeof(message), "CAM_DEBUG_STATS  updates = %" PRIu64 " (%0"PRIu32" fail)",
stats->sw.num_updates, stats->sw.failed_updates);
client_print_info((client_t *) stcam, message);
           snprintf(message, sizeof(message), "CAM_DEBUG_STATS  deletes = %" PRIu64 " (%0"PRIu32" fail)",
stats->sw.num_deletes, stats->sw.failed_deletes);
client_print_info((client_t *) stcam, message);
           snprintf(message, sizeof(message), "CAM_DEBUG_STATS  shadow writes = %" PRIu64 "",
stats->sw.num_shadow_writes);
client_print_info((client_t *) stcam, message);
           snprintf(message, sizeof(message), "CAM_DEBUG_STATS  used masks = %" PRIu16 "",
stats->sw.num_used_masks);
client_print_info((client_t *) stcam, message);
}
}
   end: stcam_print_entry(rc, "stcam_get_stats", stcam, NULL, NULL, NULL, NULL, "");
return rc;
}
static void tcam_print_entry(int error_code, const char *function, const struct tcam *tcam,
const uint8_t key[], const uint8_t mask[],
uint32_t *prio, const uint8_t response[], const char *match)
{
if (error_code && (client_get_debug_flags(tcam->client) & CAM_DEBUG_NO_ERROR_MSG))
return;
if (!error_code && !(client_get_debug_flags(tcam->client) & CAM_DEBUG_ARGS))
return;
const uint16_t key_width = client_get_key_width(tcam->client);
const uint16_t prio_width = client_get_prio_width(tcam->client);
assert(prio_width <= 32);
const uint16_t response_width = client_get_response_width(tcam->client);
char message[1000];
cam_free_func free_function = client_get_free_function(tcam->client);
cam_malloc_func malloc_function = client_get_malloc_function(tcam->client);
char *key_str;
if (key != NULL) {
key_str = byte_arr_to_str(key_width, key, malloc_function);
} else {
       key_str = (char *) "N/A";
}
char *mask_str;
if (mask != NULL) {
mask_str = byte_arr_to_str(key_width, mask, malloc_function);
} else {
       mask_str = (char *) "N/A";
}
char *prio_str;
if (prio != NULL) {
prio_str = byte_arr_to_str(prio_width, (uint8_t *) prio, malloc_function);
} else {
       prio_str = (char *) "N/A";
}
char *response_str;
if (response != NULL) {
response_str = byte_arr_to_str(response_width, response, malloc_function);
} else {
       response_str = (char *) "N/A";
}
if (!error_code && (client_get_debug_flags(tcam->client) & CAM_DEBUG_ARGS)) {
       sprintf(message, "%-22s key  = %s  response = %s  priority = %s  %8s\n%32s mask = %s",
               function, key_str, response_str, prio_str, match, " ", mask_str);
client_print_info(tcam->client, message);
}
if (error_code && ((client_get_debug_flags(tcam->client) & CAM_DEBUG_NO_ERROR_MSG) == 0)) {
       sprintf(message, "%-22s key  = %s  response = %s  priority = %s  %8s\n%32s mask = %s",
               function, key_str, response_str, prio_str, cam_error_string(error_code), " ", mask_str);
client_print_error(tcam->client, message);
}
if (prio != NULL)
free_function(prio_str);
if (response != NULL)
free_function(response_str);
if (mask != NULL)
free_function(mask_str);
if (key != NULL)
free_function(key_str);
}
static uint32_t calc_set_expansion(const cam_config_t *config,
struct set_expansion *se,
uint32_t max_combinations);
static uint32_t heap_size_set(uint32_t num_entries) {
return sizeof(struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa) + num_entries / 8 + 1;
}
static uint32_t heap_size_aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaeate(uint32_t num_entries) {
return sizeof(struct tcam) + num_entries * 8
+ num_entries * sizeof(struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaop)
+ sizeof(struct aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa);
}
static uint32_t heap_size_entry(uint8_t num_fields) {
return sizeof(struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa) + num_fields * sizeof(union aaaaaaaaaaa1aaa)
+ sizeof(m_array) + 56;
}
const uint32_t heap_size_key_in_set = sizeof(aaaaaaaaaaaaa1aaat)
+ sizeof(struct aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
static uint32_t heap_size_set_containing_all_keys(uint32_t num_entries) {
return heap_size_set(num_entries) + heap_size_key_in_set * num_entries;
}
static int tune_and_calculate_heap_size(const cam_arg_t *cam_arg,
struct set_expansion *out_se, uint32_t *out_heap_size) {
cam_config_t *cam_conf = alloca(cam_config_size());
int rc = cam_config_init(cam_arg, TCAM, cam_conf);
if (rc) {
return rc;
}
const uint32_t shadow_heap_size = cam_config_calculate_heap_size(cam_conf);
const uint32_t num_entries = cam_config_get_num_entries(cam_conf);
uint32_t max_heap_size;
if (cam_arg->max_tcam_heap_size == UINT32_MAX) {
max_heap_size = 128 * MAX(num_entries, 16) * 1024 - 1;
} else {
max_heap_size = cam_arg->max_tcam_heap_size * 1024;
}
const uint8_t num_fields = cam_config_get_num_fields(cam_conf);
const uint32_t set_independent_heap_size = shadow_heap_size
+ heap_size_entry(num_fields) * num_entries
+ heap_size_aaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaeate(num_entries);
if (max_heap_size <= set_independent_heap_size) {
return CAM_ERROR_TOO_SMALL_HEAP;
}
const uint32_t remaining_heap_size = max_heap_size
- set_independent_heap_size;
const uint32_t max_combinations = remaining_heap_size
/ heap_size_set_containing_all_keys(num_entries);
if (max_combinations == 0) {
return CAM_ERROR_TOO_SMALL_HEAP;
}
struct set_expansion se;
uint32_t num_sets = calc_set_expansion(cam_conf, &se, max_combinations);
if (num_sets == 0) {
return CAM_ERROR_TOO_SMALL_HEAP;
}
uint32_t heap_size = heap_size_set_containing_all_keys(num_entries)
* num_sets + set_independent_heap_size;
if (heap_size > max_heap_size) {
return CAM_ERROR_TOO_SMALL_HEAP;
}
*out_heap_size = heap_size;
*out_se = se;
if (cam_conf->arg.debug_flags & CAM_DEBUG_SET_COVER) {
const uint16_t MSG_SZ = 512;
char message[MSG_SZ];
snprintf(message, MSG_SZ,
               "\nCAM_DEBUG_SET_COVER  k-combinations = %"PRIu8", relaxed prefixes = %"PRIu16", ternary permutations = %"PRIu16",\nnum sets = %"PRIu32", shadow heap size = %"PRIu32", total heap size = %"PRIu32", max allowed total heap size = %"PRIu32"",
se.k_combinations, se.num_relaxed_prefixes,
se.num_ternary_permutations, num_sets, shadow_heap_size,
heap_size, max_heap_size);
cam_conf->arg.info_print_function(cam_conf->ctx, message);
}
return 0;
}
int
tcam_create(const cam_arg_t *cam_arg, struct tcam **out_tcam)
{
cam_arg_t cam_arg_copy = *cam_arg;
cam_arg_copy.debug_flags = cam_arg_copy.debug_flags & ~CAM_DEBUG_CONFIG;
uint32_t heap_size;
struct set_expansion se;
int rc = tune_and_calculate_heap_size(&cam_arg_copy, &se, &heap_size);
if (rc) {
if ((cam_arg->debug_flags & CAM_DEBUG_NO_ERROR_MSG) == 0) {
cam_print_error(rc);
}
return rc;
}
if (cam_arg->calc_heap_size) {
return heap_size;
}
cam_arg_copy.debug_flags = cam_arg->debug_flags;
struct tcam *tcam;
client_t *client;
rc = client_create_tcam(&cam_arg_copy, &client);
if (rc) {
if ((cam_arg->debug_flags & CAM_DEBUG_NO_ERROR_MSG) == 0) {
cam_print_error(rc);
}
return rc;
}
rc = aaaaa1aaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaeate(client, &se, &tcam);
if (rc) {
if ((client_get_debug_flags(client) & CAM_DEBUG_NO_ERROR_MSG) == 0) {
cam_print_error(rc);
}
return rc;
}
if ((client_get_debug_flags(client) & CAM_DEBUG_NO_ERROR_MSG) == 0) {
rc = aaaaa1aaadebug_set_mask(tcam, aaaaa1aaaDEBUG_TEST | aaaaa1aaaDEBUG_ADD_DEL);
} else {
rc = aaaaa1aaadebug_set_mask(tcam, aaaaa1aaaDEBUG_TEST);
}
if (rc)
return rc;
*out_tcam = tcam;
return 0;
}
int
tcam_insert(struct tcam *tcam, const uint8_t key[], const uint8_t mask[], uint32_t prio,
const uint8_t response[])
{
   tcam_print_entry(0, "tcam_insert", tcam, key, mask, &prio, response, "");
int rc;
union aaaaaaaaaaa1aaa fields[CAM_MAX_NUM_FIELDS];
memset(fields, 0, sizeof(union aaaaaaaaaaa1aaa) * CAM_MAX_NUM_FIELDS);
rc = cam_key2fields(tcam, &fields[0], key);
if (rc) {
tcam->client->failed_inserts++;
       tcam_print_entry(rc, "tcam_insert", tcam, key, mask, &prio, response, "");
return rc;
}
rc = cam_mask2fields(tcam->client, &fields[0], mask);
if (rc) {
tcam->client->failed_inserts++;
       tcam_print_entry(rc, "tcam_insert", tcam, key, mask, &prio, response, "");
return rc;
}
if ((client_get_debug_flags(tcam->client) & CAM_DEBUG_KEY_MASKING) == 0) {
cam_mask_fields(tcam, fields);
}
rc = cam_check_fields(tcam, fields);
if (rc) {
tcam->client->failed_inserts++;
       tcam_print_entry(rc, "tcam_insert", tcam, key, mask, &prio, response, "");
return rc;
}
const uint8_t prio_width = client_get_prio_width(tcam->client);
assert(prio_width <= 32);
const uint64_t prio_range = ((uint64_t) prio) >> prio_width;
if (prio_range > 0) {
tcam->client->failed_inserts++;
rc = CAM_ERROR_WRONG_PRIO_WIDTH;
       tcam_print_entry(rc, "tcam_insert", tcam, key, mask, &prio, response, "");
return rc;
}
const uint32_t max_num_entries = client_get_num_entries(tcam->client);
if (tcam->num_entries == max_num_entries) {
tcam->client->failed_inserts++;
rc = CAM_ERROR_FULL;
       tcam_print_entry(rc, "tcam_insert", tcam, key, mask, &prio, response, "");
return rc;
}
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me;
const uint8_t num_fields = client_get_num_fields(tcam->client);
MH_FIND(mh_handle, tcam->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaby_fields, fields, num_fields * sizeof(union aaaaaaaaaaa1aaa), me);
if (me != NULL) {
tcam->client->failed_inserts++;
rc = CAM_ERROR_DUPLICATE_FOUND;
       tcam_print_entry(rc, "tcam_insert", tcam, key, mask, &prio, response, "");
return rc;
}
uint16_t id;
for (id = 0; id < max_num_entries; id++) {
if (tcam->entries[id] == 0)
break;
}
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat prio_resp;
const uint16_t response_width = client_get_response_width(tcam->client);
memset(&prio_resp, 0, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
cam_copy_bits((uint8_t *) &prio_resp.word[0], response, response_width);
if (prio_width > 0) {
const uint32_t new_prio = prio;
cam_write_field((uint32_t *) &prio_resp, response_width, response_width + prio_width - 1, &new_prio,
CAM_MAX_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa - 1);
}
rc = aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaeate(tcam, id, &fields[0], &prio_resp, &me);
if (rc) {
tcam->client->failed_inserts++;
       tcam_print_entry(rc, "tcam_insert", tcam, key, mask, &prio, response, "");
return rc;
}
tcam->entries[me->id] = me;
tcam->num_entries++;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(tcam, me);
if (rc)
goto error;
tcam->client->num_inserts++;
tcam->client->num_entries++;
tcam->stats.curr_num_entries++;
tcam->stats.max_num_entries = MAX(tcam->stats.curr_num_entries,
tcam->stats.max_num_entries);
return rc;
error: (void) aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(tcam, me);
tcam->num_entries--;
tcam->client->failed_inserts++;
   tcam_print_entry(rc, "tcam_insert", tcam, key, mask, &prio, response, "");
return rc;
}
int
tcam_update(struct tcam *tcam, const uint8_t key[], const uint8_t mask[], const uint8_t response[])
{
   tcam_print_entry(0, "tcam_update", tcam, key, mask, NULL, response, "");
int rc;
union aaaaaaaaaaa1aaa fields[CAM_MAX_NUM_FIELDS];
memset(fields, 0, sizeof(union aaaaaaaaaaa1aaa) * CAM_MAX_NUM_FIELDS);
rc = cam_key2fields(tcam, fields, key);
if (rc) {
tcam->client->failed_updates++;
       tcam_print_entry(rc, "tcam_update", tcam, key, mask, NULL, response, "");
return rc;
}
rc = cam_mask2fields(tcam->client, fields, mask);
if (rc) {
tcam->client->failed_updates++;
       tcam_print_entry(rc, "tcam_update", tcam, key, mask, NULL, response, "");
return rc;
}
if ((client_get_debug_flags(tcam->client) & CAM_DEBUG_KEY_MASKING) == 0) {
cam_mask_fields(tcam, fields);
}
rc = cam_check_fields(tcam, fields);
if (rc) {
tcam->client->failed_updates++;
       tcam_print_entry(rc, "tcam_update", tcam, key, mask, NULL, response, "");
return rc;
}
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me;
const uint8_t num_fields = client_get_num_fields(tcam->client);
MH_FIND(mh_handle, tcam->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaby_fields, fields, num_fields * sizeof(union aaaaaaaaaaa1aaa), me);
if (me == NULL) {
tcam->client->failed_updates++;
rc = CAM_ERROR_KEY_NOT_FOUND;
       tcam_print_entry(rc, "tcam_update", tcam, key, mask, NULL, response, "");
return rc;
}
const uint16_t response_width = client_get_response_width(tcam->client);
cam_write_field((uint32_t *) &me->priority.word[0], 0, response_width - 1, (uint32_t *) response,
CAM_MAX_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa - 1);
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa(tcam, me, me->current_entryset.mes,
me->current_entryset.instance,
me->current_entryset.collset);
if (rc) {
tcam->client->failed_updates++;
       tcam_print_entry(rc, "tcam_update", tcam, key, mask, NULL, response, "");
return rc;
}
tcam->client->num_updates++;
return 0;
}
int
tcam_get_by_response(struct tcam *tcam, const uint8_t response[], const uint8_t response_mask[],
uint32_t *pos, uint8_t out_key[], uint8_t out_mask[])
{
int rc;
aaaaaaaaaaaaa1aaat old_key;
aaaaaaaaaaaaa1aaat ternary_mask;
aaaaaaaaaaaaa1aaat relaxed_mask;
uint8_t range_valid;
uint8_t mask_id;
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat new_response;
memset(&new_response, 0, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
const uint16_t response_width = client_get_response_width(tcam->client);
cam_copy_bits((uint8_t *) &new_response.word[0], response, response_width);
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat new_response_mask;
memset(&new_response_mask, 0, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
cam_copy_bits((uint8_t *) &new_response_mask.word[0], response_mask, response_width);
rc = client_read_prio_for_range_key(tcam->client, &new_response, &new_response_mask, pos, &old_key, &ternary_mask,
&relaxed_mask, &range_valid, &mask_id);
if (rc && (rc != CAM_ERROR_FOUND_IN_SHADOW_BUT_NOT_IN_HW))
return rc;
const uint8_t num_fields = client_get_num_fields(tcam->client);
const uint32_t num_entries = client_get_num_entries(tcam->client);
uint32_t i;
int found = 0;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me;
for (i = 0; i < num_entries; i++) {
if (tcam->entries[i] == 0)
continue;
me = tcam->entries[i];
bool match = true;
for (uint16_t i = 0; i < CAM_MAX_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaMEM; i++) {
if ((me->priority.word[i] & new_response_mask.word[i])
!= (new_response.word[i] & new_response_mask.word[i])) {
match = false;
}
}
if (match == false)
continue;
if (memcmp(&me->current_entryset.mes->mask.mask.word[0], &relaxed_mask, sizeof(aaaaaaaaaaaaa1aaat)))
continue;
if (me->current_entryset.instance != mask_id)
continue;
if (memcmp(&me->exact_key.word[0], &old_key, sizeof(aaaaaaaaaaaaa1aaat)))
continue;
if (me->current_entryset.mes->mask.use_range != range_valid)
continue;
int field;
for (field = 0; field < num_fields; field++) {
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc mfd;
const int rc2 = client_get_aaaaaaaaaaaaaaaaaa1aaa(tcam->client, field, &mfd);
assert(rc2 == 0);
if (mfd.type != aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaR16 || (range_valid & 1 << mfd.instance) == 0)
continue;
uint16_t end = 0;
cam_read_field8((uint8_t *) &end, (uint8_t *) &ternary_mask.word[0], mfd.start_pos,
mfd.len);
if (me->fields[field].r16.end != end)
goto cont;
}
found = 1;
break;
cont: continue;
}
if (!found) {
rc = CAM_ERROR_KEY_NOT_FOUND;
       tcam_print_entry(rc, "tcam_get_by_response", tcam, NULL, NULL, NULL, response, "");
return rc;
}
uint8_t temp_ternary_mask[CAM_MAX_KEY_WIDTH / 8 + 1];
uint8_t temp_key[CAM_MAX_KEY_WIDTH / 8 + 1];
memset(temp_key, 0, CAM_MAX_KEY_WIDTH / 8 + 1);
memset(temp_ternary_mask, 0, CAM_MAX_KEY_WIDTH / 8 + 1);
int rc2 = aaaaaaaaaaa1aaas2key(tcam, me->fields, temp_key);
assert(rc2 == 0);
rc2 = aaaaaaaaaaa1aaas2mask(tcam, me->fields, temp_ternary_mask);
assert(rc2 == 0);
const uint16_t key_width = client_get_key_width(tcam->client);
uint8_t num_bytes = key_width / 8;
assert(num_bytes > 0);
uint8_t rem_bits = key_width - num_bytes * 8;
if (rem_bits) {
out_key[num_bytes] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa8(out_key[num_bytes], temp_key[num_bytes], 0, rem_bits);
out_mask[num_bytes] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa8(out_mask[num_bytes], temp_ternary_mask[num_bytes], 0, rem_bits);
}
memcpy(out_key, temp_key, num_bytes);
memcpy(out_mask, temp_ternary_mask, num_bytes);
   tcam_print_entry(rc, "tcam_get_by_response", tcam, out_key, out_mask, NULL, response, "");
return rc;
}
int
tcam_get_by_key(struct tcam *tcam, const uint8_t key[], const uint8_t mask[], uint32_t * prio, uint8_t response[])
{
int rc;
union aaaaaaaaaaa1aaa fields[CAM_MAX_NUM_FIELDS];
memset(fields, 0, sizeof(union aaaaaaaaaaa1aaa) * CAM_MAX_NUM_FIELDS);
rc = cam_key2fields(tcam, fields, key);
if (rc) {
       tcam_print_entry(rc, "tcam_get_by_key", tcam, key, mask, NULL, NULL, "");
return rc;
}
rc = cam_mask2fields(tcam->client, fields, mask);
if (rc) {
       tcam_print_entry(rc, "tcam_get_by_key", tcam, key, mask, NULL, NULL, "");
return rc;
}
if ((client_get_debug_flags(tcam->client) & CAM_DEBUG_KEY_MASKING) == 0) {
cam_mask_fields(tcam, fields);
}
rc = cam_check_fields(tcam, fields);
if (rc) {
       tcam_print_entry(rc, "tcam_get_by_key", tcam, key, mask, NULL, NULL, "");
return rc;
}
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaa *mes;
const uint8_t num_fields = client_get_num_fields(tcam->client);
MH_FIND(mh_handle, tcam->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaby_fields, fields, num_fields * sizeof(union aaaaaaaaaaa1aaa), me);
if (me == NULL) {
rc = CAM_ERROR_KEY_NOT_FOUND;
       tcam_print_entry(rc, "tcam_get_by_key", tcam, key, mask, NULL, NULL, "");
return rc;
}
mes = me->current_entryset.mes;
aaaaaaaaaaaaa1aaat new_key;
aaaaaaaaaaaaa1aaat relaxed_mask;
aaaaaaaaaaaaa1aaat ternary_mask;
memset(&new_key, 0, sizeof(new_key));
memset(&relaxed_mask, 0, sizeof(relaxed_mask));
memset(&ternary_mask, 0, sizeof(ternary_mask));
memcpy(&new_key, &me->exact_key.word[0], sizeof(aaaaaaaaaaaaa1aaat));
memcpy(&relaxed_mask, &mes->mask.mask.word[0], sizeof(aaaaaaaaaaaaa1aaat));
memcpy(&ternary_mask, &me->exact_mask.mask.word[0],
sizeof(aaaaaaaaaaaaa1aaat));
int field;
for (field = 0; field < num_fields; field++) {
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc mfd;
rc = client_get_aaaaaaaaaaaaaaaaaa1aaa(tcam->client, field, &mfd);
assert(rc == 0);
if (mfd.type != aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaR16 ||
(me->exact_mask.use_range & 1 << mfd.instance) == 0) {
continue;
}
if (mes->mask.use_range & 1 << mfd.instance) {
const uint32_t end = me->fields[field].r16.end;
cam_write_field((uint32_t *) &ternary_mask.word[0], mfd.start_pos, mfd.len + mfd.start_pos - 1,
&end,
CAM_MAX_KEY_WIDTH - 1);
me->fields[field].r16.end = end & 0xffff;
} else {
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaabits((uint8_t *) &ternary_mask.word[0],
sizeof(aaaaaaaaaaaaa1aaat),
mfd.start_pos, mfd.len);
}
}
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat key_prio;
rc = client_read_range_key(tcam->client, &new_key, &ternary_mask, &key_prio, &relaxed_mask, mes->mask.use_range,
me->current_entryset.instance);
if (rc && (rc != CAM_ERROR_FOUND_IN_SHADOW_BUT_NOT_IN_HW)) {
       tcam_print_entry(rc, "tcam_get_by_key", tcam, key, mask, NULL, NULL, "");
return rc;
}
const uint16_t response_width = client_get_response_width(tcam->client);
const uint8_t prio_width = client_get_prio_width(tcam->client);
assert(prio_width <= 32);
if (prio_width) {
uint32_t temp_prio;
cam_read_field((uint32_t *) &key_prio, response_width, response_width + prio_width - 1, &temp_prio);
*prio = temp_prio;
} else {
*prio = 0;
}
const uint8_t num_bytes = response_width / 8;
const uint16_t remaining_bits = response_width - num_bytes * 8;
if (remaining_bits > 0) {
response[num_bytes] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa8(response[num_bytes], *((uint8_t *) &key_prio + num_bytes), 0, remaining_bits);
}
memcpy(response, &key_prio, num_bytes);
   tcam_print_entry(rc, "tcam_get_by_key", tcam, key, mask, prio, response, "");
return rc;
}
int
tcam_lookup(struct tcam *tcam, const uint8_t key[], uint8_t response[])
{
int rc;
aaaaaaaaaaaaa1aaat new_key;
memset(&new_key, 0, sizeof(aaaaaaaaaaaaa1aaat));
const uint16_t key_width = client_get_key_width(tcam->client);
cam_copy_bits((uint8_t *) &new_key.word[0], key, key_width);
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat prio_resp;
rc = client_lookup_tcam(tcam->client, &new_key, &prio_resp);
if (rc == CAM_ERROR_KEY_NOT_FOUND) {
client_get_default_response(tcam->client, (uint8_t *) &prio_resp, false);
}
else if (rc) {
       tcam_print_entry(rc, "tcam_lookup", tcam, key, NULL, NULL, NULL, "");
return rc;
}
const uint16_t response_width = client_get_response_width(tcam->client);
const uint8_t num_bytes = response_width / 8;
const uint16_t remaining_bits = response_width - num_bytes * 8;
if (remaining_bits > 0) {
response[num_bytes] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa8(response[num_bytes], *((uint8_t *) &prio_resp + num_bytes), 0, remaining_bits);
}
memcpy(response, &prio_resp, num_bytes);
uint32_t prio;
const uint8_t prio_width = client_get_prio_width(tcam->client);
assert(prio_width <= 32);
if (prio_width) {
cam_read_field((uint32_t *) &prio_resp, response_width, response_width + prio_width - 1, &prio);
} else {
prio = 0;
}
   tcam_print_entry(0, "tcam_lookup", tcam, key, NULL, &prio, response, rc ? "NO_MATCH" : "MATCH");
return rc;
}
int tcam_delete_all(struct tcam *tcam) {
uint8_t read_key[CAM_MAX_KEY_WIDTH / 8 + 1];
uint8_t read_ternary_mask[CAM_MAX_KEY_WIDTH / 8 + 1];
memset(read_key, 0, CAM_MAX_KEY_WIDTH / 8 + 1);
memset(read_ternary_mask, 0, CAM_MAX_KEY_WIDTH / 8 + 1);
uint8_t response[CAM_MAX_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa / 8 + 1];
memset(response, 0, CAM_MAX_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa / 8 + 1);
uint8_t response_mask[CAM_MAX_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa / 8 + 1];
memset(response_mask, 0, CAM_MAX_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa / 8 + 1);
uint32_t pos = 0;
int rc = 0;
while (rc == 0) {
rc = tcam_get_by_response(tcam, response, response_mask, &pos, read_key, read_ternary_mask);
if (rc == CAM_ERROR_KEY_NOT_FOUND) {
rc = 0;
break;
} else if (rc != 0) {
break;
}
rc = tcam_delete(tcam, read_key, read_ternary_mask);
if (rc != 0)
break;
pos = 0; 
}
   tcam_print_entry(rc, "tcam_delete_all", tcam, NULL, NULL, NULL, NULL, "");
return rc;
}
int
tcam_delete(struct tcam *tcam, const uint8_t key[], const uint8_t mask[])
{
   tcam_print_entry(0, "tcam_delete", tcam, key, mask, NULL, NULL, "");
int rc;
union aaaaaaaaaaa1aaa fields[CAM_MAX_NUM_FIELDS];
memset(fields, 0, sizeof(union aaaaaaaaaaa1aaa) * CAM_MAX_NUM_FIELDS);
rc = cam_key2fields(tcam, fields, key);
if (rc) {
tcam->client->failed_deletes++;
       tcam_print_entry(rc, "tcam_delete", tcam, key, mask, NULL, NULL, "");
return rc;
}
rc = cam_mask2fields(tcam->client, fields, mask);
if (rc) {
tcam->client->failed_deletes++;
       tcam_print_entry(rc, "tcam_delete", tcam, key, mask, NULL, NULL, "");
return rc;
}
if ((client_get_debug_flags(tcam->client) & CAM_DEBUG_KEY_MASKING) == 0) {
cam_mask_fields(tcam, fields);
}
rc = cam_check_fields(tcam, fields);
if (rc) {
tcam->client->failed_deletes++;
       tcam_print_entry(rc, "tcam_delete", tcam, key, mask, NULL, NULL, "");
return rc;
}
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me;
const uint8_t num_fields = client_get_num_fields(tcam->client);
MH_FIND(mh_handle, tcam->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaby_fields, fields, num_fields * sizeof(union aaaaaaaaaaa1aaa), me);
if (me == NULL) {
tcam->client->failed_deletes++;
rc = CAM_ERROR_KEY_NOT_FOUND;
       tcam_print_entry(rc, "tcam_delete", tcam, key, mask, NULL, NULL, "");
return rc;
}
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(tcam, me, me->current_entryset.mes, me->current_entryset.instance);
if (rc) {
tcam->client->failed_deletes++;
       tcam_print_entry(rc, "tcam_delete", tcam, key, mask, NULL, NULL, "");
return rc;
}
tcam->num_entries--;
tcam->client->num_entries--;
tcam->stats.curr_num_entries--;
rc = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa5aaa(tcam, me);
if (rc) {
tcam->client->failed_deletes++;
       tcam_print_entry(rc, "tcam_delete", tcam, key, mask, NULL, NULL, "");
return rc;
}
assert(me->num_collsets == 0);
rc = aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(tcam, me);
if (rc) {
tcam->client->failed_deletes++;
       tcam_print_entry(rc, "tcam_delete", tcam, key, mask, NULL, NULL, "");
return rc;
}
tcam->client->num_deletes++;
return 0;
}
static int
aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaaa4aaa(struct tcam *tcam, uint32_t id)
{
int rc;
struct aaaaa1aaaaaaaaaaaabaaaaaaaaaaa3aaa *me;
me = tcam->entries[id];
tcam->num_entries--;
tcam->client->num_entries--;
tcam->stats.curr_num_entries--;
rc = aaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(tcam, me);
if (rc)
return rc;
return rc;
}
int tcam_read_and_clear_ecc_counters(struct tcam *tcam,
uint32_t *corrected_single_bit_errors,
uint32_t *detected_double_bit_errors)
{
return client_read_and_clear_ecc_counters(tcam->client, corrected_single_bit_errors,
detected_double_bit_errors);
}
int tcam_read_and_clear_ecc_addresses(struct tcam *tcam,
uint32_t *failing_address_single_bit_error,
uint32_t *failing_address_double_bit_error)
{
return client_read_and_clear_ecc_addresses(tcam->client,
failing_address_single_bit_error,
failing_address_double_bit_error);
}
int tcam_set_ecc_test(struct tcam *tcam,
bool inject_single_bit_errors,
bool inject_double_bit_errors)
{
return client_set_ecc_test(tcam->client,
inject_single_bit_errors,
inject_double_bit_errors);
}
int
tcam_destroy(struct tcam *tcam)
{
uint16_t i;
   tcam_print_entry(0, "tcam_destroy", tcam, NULL, NULL, NULL, NULL, "");
const uint32_t num_entries = client_get_num_entries(tcam->client);
for (i = 0; i < num_entries; i++)
if (tcam->entries[i] != NULL)
(void) aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaabaaaaaaaaaaa4aaa(tcam, i);
return aaaaa1aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(tcam);
}
int tcam_get_stats(struct tcam *tcam, uint64_t group, union tcam_stats *stats) {
NULL_CHECK(tcam);
NULL_CHECK(stats);
const uint16_t MSG_SZ = 600;
int rc = 0;
if (group == TCAM_STATS_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP) {
rc = client_read_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup_data(tcam->client, &stats->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup);
if (rc) {
goto end;
}
} else if (group == TCAM_STATS_SW) {
client_get_sw_stats(tcam->client, &stats->sw);
} else {
rc = CAM_ERROR_INVALID_ARG;
goto end;
}
if (client_get_debug_flags(tcam->client) & CAM_DEBUG_STATS) {
char message[MSG_SZ];
if (group == TCAM_STATS_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaOKUP) {
char *key_str;
char *response_str;
const cam_malloc_func malloc_function = client_get_malloc_function(tcam->client);
const cam_free_func free_function = client_get_free_function(tcam->client);
const uint16_t key_width = client_get_key_width(tcam->client);
const uint16_t response_width = client_get_response_width(tcam->client);
key_str = byte_arr_to_str(key_width, stats->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup.key, malloc_function);
response_str = byte_arr_to_str(response_width, stats->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup.response, malloc_function);
           snprintf(message, sizeof(message), "last key = %s", key_str);
client_print_info(tcam->client, message);
           snprintf(message, sizeof(message), "last response = %s", response_str);
client_print_info(tcam->client, message);
           snprintf(message, sizeof(message), "last status = %" PRIu32, stats->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup.status);
client_print_info(tcam->client, message);
free_function(key_str);
free_function(response_str);
}
}
   end: tcam_print_entry(rc, "tcam_get_stats", tcam, NULL, NULL, NULL, NULL, "");
return rc;
}
static uint32_t get_multiplication_factor(const struct set_expansion *se,
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc *mfd) {
switch (mfd->type) {
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaC128:
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaU128:
return 0;
break;
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaP128: {
uint8_t m_factor = se->num_relaxed_prefixes;
if (mfd->len < m_factor)
m_factor = mfd->len;
return m_factor;
break;
}
case aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaT64: {
uint8_t num_ones = aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaacalc_num_ones(mfd->len,
se->num_ternary_permutations);
return aaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaacalc_num_combinations(mfd->len, num_ones);
break;
}
default:
return 1;
} 
}
static uint32_t tcam_combine(const cam_config_t *config,
const struct set_expansion *se, uint8_t data[],
uint8_t start,
uint8_t end, uint8_t index, uint8_t r) {
uint32_t sum;
if (index == r) { 
sum = 1;
for (int j = 0; j < r; j++) {
aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc mfd;
int rc = cam_config_get_aaaaaaaaaaaaaaaaaa1aaa(config, data[j], &mfd);
assert(rc == 0);
sum = sum * get_multiplication_factor(se, &mfd);
}
return sum;
}
sum = 0;
for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
data[index] = i;
sum = sum + tcam_combine(config, se, data, i + 1, end, index + 1, r);
}
return sum;
}
static uint32_t calc_num_sets(const cam_config_t *config,
const struct set_expansion *se) {
const uint8_t num_fields = cam_config_get_num_fields(config);
uint32_t sum = 1;
for (uint8_t r = 1; r <= se->k_combinations; r++) {
uint8_t data[r];
memset(data, 0, r);
sum = sum + tcam_combine(config, se, data, 0, num_fields - 1, 0, r);
}
return sum;
}
static void get_set_expansion(uint16_t effort, struct set_expansion *se) {
se->k_combinations = 1;
if (effort > 4) {
se->k_combinations = 2;
}
se->num_ternary_permutations = effort;
se->num_relaxed_prefixes = effort;
}
static uint32_t calc_set_expansion(const cam_config_t *config,
struct set_expansion *se, uint32_t max_sets) {
uint32_t num_sets = 0;
uint32_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaas = 0;
uint16_t effort;
for (effort = 1; effort <= 512; effort++) {
get_set_expansion(effort, se);
num_sets = calc_num_sets(config, se);
if (num_sets > max_sets) {
if (effort == 1)
return 0;
break;
}
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaas = num_sets;
}
get_set_expansion(effort - 1, se);
return aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbb3aaas;
}
int client_create_tcam(const cam_arg_t *cam_conf_arg, client_t **client)
{
client_t *new_client = cam_conf_arg->malloc_function(sizeof(client_t));
if (new_client == NULL) {
return CAM_ERROR_MALLOC_FAILED;
}
cam_config_t *cam_conf;
int rc = cam_config_create(cam_conf_arg, TCAM, &cam_conf);
if (rc) {
cam_conf_arg->free_function(new_client);
return rc;
}
new_client->conf = cam_conf;
new_client->prev_hi_addr_unknown = true;
new_client->prev_hi_data_unknown = true;
new_client->prev_hi_addr = 0;
new_client->prev_hi_data = 0;
if (cam_conf->arg.debug_flags & CAM_DEBUG_VERIFY_CONFIG) {
char message[500];
       sprintf(message, "The debug switch 'CAM_DEBUG_VERIFY_CONFIG' is deprecated.");
client_print_info(new_client, message);
       sprintf(message, "Verification of hardware/software parameters is enabled by default.");
client_print_info(new_client, message);
       sprintf(message, "Use the debug switch 'CAM_DEBUG_SKIP_VERIFY_CONFIG' to disable verification of hardware/software parameters");
client_print_info(new_client, message);
}
if (!(cam_conf->arg.debug_flags & CAM_DEBUG_SKIP_VERIFY_CONFIG)) {
rc = verify_config(new_client);
if (rc) {
return rc;
}
}
new_client->htable = NULL;
new_client->num_entries = 0;
new_client->narrow_num_entries = 0;
new_client->num_overwrites = 0;
new_client->zero_unused = false;
const uint16_t num_units = cam_config_get_num_units(new_client->conf);
const uint16_t num_slots = cam_config_get_num_slots(new_client->conf);
cam_free_func free_function = client_get_free_function(new_client);
new_client->test_km = NULL;
new_client->test_km = (aaaa1aaat *) new_client->conf->arg.malloc_function(aaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa());
new_client->overwrites = NULL;
if (new_client->test_km == NULL) {
rc = CAM_ERROR_MALLOC_FAILED;
goto out_free_conf;
}
if (!aaaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(new_client->test_km, new_client, 0, 0, false)) {
aaaa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(new_client->test_km, free_function);
rc = CAM_ERROR_MALLOC_FAILED;
goto out_free_conf;
}
for (uint16_t i = 0; i < num_units; i++) {
new_client->unit[i].phm = new_client->conf->arg.malloc_function(aaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa());
if (new_client->unit[i].phm == NULL) {
for (uint16_t j = 0; j < i; j++) {
aaa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(new_client->unit[j].phm, free_function);
}
aaaa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(new_client->test_km, free_function);
rc = CAM_ERROR_MALLOC_FAILED;
goto out_free_conf;
}
}
assert(num_units <= aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaS);
for (uint16_t i = 0; i < num_units; i++) {
const uint16_t physical_unit = i / num_slots;
const uint8_t slot_number = i - physical_unit * num_slots;
if (false
== aaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(new_client->unit[i].phm, new_client, physical_unit, slot_number)) {
for (uint16_t j = 0; j < i; j++) {
aaa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(new_client->unit[j].phm, free_function);
}
aaaa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(new_client->test_km, free_function);
rc = CAM_ERROR_MALLOC_FAILED;
goto out_free_conf;
}
new_client->unit[i].unit_mode = UNUSED;
}
new_client->unit[0].unit_mode = RECOVER;
new_client->num_inserts = 0;
new_client->num_updates = 0;
new_client->num_deletes = 0;
new_client->failed_inserts = 0;
new_client->failed_updates = 0;
new_client->failed_deletes = 0;
new_client->num_collisions = 0;
new_client->max_collisions = 0;
new_client->num_used_masks = 0;
new_client->num_shadow_writes = 0;
uint32_t cnt1, cnt2;
if (cam_conf_arg->segment_ctx.segment == -1)
client_read_and_clear_ecc_counters(new_client, &cnt1, &cnt2);
*client = new_client;
return 0;
out_free_conf:
cam_conf_arg->free_function(new_client->conf);
cam_conf_arg->free_function(new_client);
return rc;
}
uint16_t client_get_num_entries_per_unit(const client_t *client)
{
assert(client != NULL);
return cam_config_get_num_entries_per_unit(client->conf);
}
uint8_t client_get_num_fields(const client_t *client)
{
assert(client != NULL);
return cam_config_get_num_fields(client->conf);
}
int client_get_aaaaaaaaaaaaaaaaaa1aaa(const client_t *client, uint8_t field_number, aaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaadesc *desc)
{
assert(client != NULL);
return cam_config_get_aaaaaaaaaaaaaaaaaa1aaa(client->conf, field_number, desc);
}
aaa1aaat *client_get_recover_phm(const client_t *client)
{
assert(client_is_tcam(client));
return client->unit[0].phm;
}
aaaa1aaat *client_get_test_km(const client_t *client)
{
return client->test_km;
}
static bool is_closed(const client_t *client, uint16_t unit)
{
assert(client != NULL);
assert(unit < client_get_num_units(client));
if (client->unit[unit].unit_mode == CLOSED) {
return true;
}
return false;
}
static bool is_open(const client_t *client, uint16_t unit)
{
assert(client != NULL);
assert(unit < client_get_num_units(client));
if (client->unit[unit].unit_mode == OPEN) {
return true;
}
return false;
}
static bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaclosed(const client_t *client, uint16_t *start_value)
{
assert(client != NULL);
const uint16_t number_of_units = client_get_num_units(client);
for (uint16_t i = *start_value; i < number_of_units; i++) {
if (client->unit[i].unit_mode == CLOSED) {
*start_value = i;
return true;
}
}
return false;
}
static bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaclosed_with_equal_mask(const client_t *client, uint16_t *start_value,
const aaaaaaaaaaaaa1aaat *mask,
uint8_t range_valid, uint8_t mask_id)
{
uint16_t closed_unit = *start_value;
while (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaclosed(client, &closed_unit)) {
const aaa1aaat *phm = client->unit[closed_unit].phm;
assert(aaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaavalid(phm));
if (aaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaequal(phm, mask, range_valid, mask_id)) {
*start_value = closed_unit;
return true;
}
closed_unit++;
}
return false;
}
void client_destroy_tcam(client_t *client)
{
if (client == NULL) {
return;
}
assert(client->conf != NULL);
cam_free_func free_function = client_get_free_function(client);
const uint16_t num_units = cam_config_get_num_units(client->conf);
for (uint16_t i = 0; i < num_units; i++) {
aaa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(client->unit[i].phm, free_function);
}
if (client->test_km != NULL) {
aaaa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(client->test_km, free_function);
}
if (client->overwrites != NULL) {
free_function(client->overwrites);
}
cam_config_destroy(client->conf);
free_function(client);
}
int client_get_range_start_pos(const client_t *client, uint8_t range_number, uint16_t *start_pos)
{
return cam_config_get_range_start_pos(client->conf, range_number, start_pos);
}
int client_get_range_width(const client_t *client, uint8_t range_number, uint8_t *width)
{
return cam_config_get_range_width(client->conf, range_number, width);
}
static int add_key_to_open(client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaa1aaat *ternary_mask,
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response,
const aaaaaaaaaaaaa1aaat *mask, uint16_t *unit, uint8_t range_valid,
uint8_t mask_id)
{
assert(client != NULL);
uint16_t start_value = 0;
if (!aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen_with_equal_mask(client, &start_value, mask, range_valid, mask_id)) {
return CAM_ERROR_NO_OPEN;
}
aaa1aaat *phm = client_get_phm(client, start_value);
*unit = start_value;
bool success = aaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaa(phm, key, ternary_mask, response, false, 0);
if (success) {
return 0;
}
return CAM_ERROR_FULL;
}
static bool db_execute(client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaa1aaat *ternary_mask, const aaaaaaaaaaaaa1aaat *mask,
uint8_t range_valid, uint8_t mask_id, aaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaat execute, bool match_prio, aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *prio,
uint16_t *unit,
bool *unresolvable_collision, int *verify)
{
assert(client != NULL);
uint16_t open_unit = 0;
if (!aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen_with_equal_mask(client, &open_unit, mask, range_valid, mask_id)) {
*unresolvable_collision = false;
return false;
}
aaa1aaat *phm = client_get_phm(client, open_unit);
bool unresolvable_coll;
const bool status = aaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(phm, key, ternary_mask, execute,
&unresolvable_coll, match_prio, prio, verify);
if (status == true) {
*unit = open_unit;
return true;
}
if (unresolvable_coll) {
*unresolvable_collision = true;
return false;
}
uint16_t closed_unit = 0;
while (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaclosed_with_equal_mask(client, &closed_unit, mask, range_valid, mask_id)) {
aaa1aaat *phm = client_get_phm(client, closed_unit);
const bool status = aaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(phm, key, ternary_mask, execute,
&unresolvable_coll, match_prio, prio, verify);
if (status == true) {
*unit = closed_unit;
return true;
}
if (unresolvable_coll) {
*unresolvable_collision = true;
return false;
}
closed_unit++;
}
*unresolvable_collision = false;
return false;
}
static void move_from_open(client_t *client, uint16_t target, uint16_t source)
{
if (target == source) {
assert(is_open(client, source));
assert(is_open(client, target));
return;
}
assert(is_closed(client, target));
assert(is_open(client, source));
aaa1aaat *target_phm = client_get_phm(client, target);
aaa1aaat *source_phm = client_get_phm(client, source);
const bool success = aaa1bbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaone_element(target_phm, source_phm);
assert((success && (client->conf->instance_type == TCAM)) || (!(client->conf->instance_type == TCAM)));
}
int client_delete_range_key(client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaa1aaat *ternary_mask, const aaaaaaaaaaaaa1aaat *msk,
uint8_t range_valid, uint8_t mask_id)
{
int status = aaa1aaacheck_ternary_mask(client, key, ternary_mask, msk, range_valid);
if (status != 0) {
return status;
}
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat del_prio;
uint16_t unit;
bool collision_found;
bool success = db_execute(client, key, ternary_mask, msk, range_valid, mask_id, aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaa, false, &del_prio, &unit,
&collision_found,
NULL);
if (!success) {
return CAM_ERROR_KEY_NOT_FOUND;
}
uint16_t open_unit = 0;
if (!aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen_with_equal_mask(client, &open_unit, msk, range_valid, mask_id)) {
assert(false);
}
move_from_open(client, unit, open_unit);
aaa1aaat *open_phm = client_get_phm(client, open_unit);
uint16_t number_of_keys = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(open_phm);
if (number_of_keys == 0) {
uint16_t closed_unit = 0;
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaclosed_with_equal_mask(client, &closed_unit, msk, range_valid, mask_id)) {
set_open(client, closed_unit);
}
aaa1bbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6aaa(open_phm);
set_unused(client, open_unit);
}
return 0;
}
int client_read_prio_for_range_key(const client_t *client, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *prio, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *prio_mask,
uint32_t *start_value,
aaaaaaaaaaaaa1aaat *key, aaaaaaaaaaaaa1aaat *ternary_mask, aaaaaaaaaaaaa1aaat *mask, uint8_t *range_valid,
uint8_t *mask_id)
{
assert(client_is_tcam(client));
assert(aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaS <= 256);
uint32_t key_pos = (*start_value) & 0x00ffffff;
uint16_t unit = ((*start_value) & 0xff000000) >> 24;
int verify_result;
int *verify = NULL;
if ((client_get_debug_flags(client) & CAM_DEBUG_VERIFY_SHADOW) != 0) {
verify = &verify_result;
}
while (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen_or_closed(client, &unit)) {
aaa1aaat *phm = client_get_phm(client, unit);
uint8_t narrow = 0;
uint8_t narrow_element = 0;
if (aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(phm, prio, prio_mask, &key_pos, key, ternary_mask,
&narrow, &narrow_element, false, verify)) {
key_pos++;
*start_value = (unit << 24) + key_pos;
aaa1aaaread_mask(phm, mask, range_valid, mask_id);
if (verify) {
return *verify;
}
return 0;
}
unit++;
key_pos = 0;
}
return CAM_ERROR_KEY_NOT_FOUND;
}
static int add_key(client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaa1aaat *ternary_mask,
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *key_prio,
const aaaaaaaaaaaaa1aaat *mask, uint8_t range_valid, uint8_t mask_id);
int client_update_range_key(client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaa1aaat *ternary_mask,
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *key_prio,
const aaaaaaaaaaaaa1aaat *msk, uint8_t range_valid, uint8_t mask_id)
{
int status = aaa1aaacheck_ternary_mask(client, key, ternary_mask, msk, range_valid);
if (status != 0) {
return status;
}
uint16_t open_unit = 0;
if (!aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen_with_equal_mask(client, &open_unit, msk,
range_valid, mask_id)) {
status = add_key(client, key, ternary_mask, key_prio, msk,
range_valid, mask_id);
return status;
}
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat comp_prio = *key_prio;
uint16_t read_unit;
bool collisions_found;
const bool found_in_db = db_execute(client, key, ternary_mask, msk, range_valid, mask_id, aaa1bbbbbbbbbbbbbbbbbbbb3aaa, false,
&comp_prio, &read_unit,
&collisions_found, NULL);
if (found_in_db) {
return 0;
}
if (collisions_found) {
return CAM_ERROR_DUPLICATE_FOUND;
}
status = add_key(client, key, ternary_mask, key_prio, msk,
range_valid, mask_id);
return status;
}
int client_read_range_key(const client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaa1aaat *ternary_mask,
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *key_prio, const aaaaaaaaaaaaa1aaat *msk, uint8_t range_valid,
uint8_t mask_id)
{
int status = aaa1aaacheck_ternary_mask(client, key, ternary_mask, msk, range_valid);
if (status != 0) {
return status;
}
uint16_t read_unit;
bool collisions_found;
int verify_result;
int *verify = NULL;
if ((client_get_debug_flags(client) & CAM_DEBUG_VERIFY_SHADOW) != 0) {
verify = &verify_result;
}
const bool found_in_db = db_execute((client_t *) client, key, ternary_mask, msk, range_valid,
mask_id, aaa1aaaREAD,
false, key_prio, &read_unit, &collisions_found, verify);
if (found_in_db) {
if (verify)
return *verify;
return 0;
}
return CAM_ERROR_KEY_NOT_FOUND;
}
static int add_key(client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaa1aaat *ternary_mask,
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *key_prio,
const aaaaaaaaaaaaa1aaat *mask, uint8_t range_valid, uint8_t mask_id)
{
uint16_t unit;
const int status = add_key_to_open(client, key, ternary_mask, key_prio, mask,
&unit, range_valid,
mask_id);
if (status == 0) {
return 0;
}
else if (status == CAM_ERROR_FULL) {
uint16_t unit = 0;
bool success = aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen_with_equal_mask(client, &unit,
mask, range_valid, mask_id);
assert(success);
uint16_t new_unit = 0;
if (!aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaunused(client, &new_unit)) {
return CAM_ERROR_FULL;
}
write_mask(client, mask, new_unit, range_valid, mask_id);
set_closed(client, unit);
set_open(client, new_unit);
const int new_status = add_key_to_open(client, key, ternary_mask, key_prio, mask,
&new_unit,
range_valid, mask_id);
assert(new_status == 0);
return 0;
}
else if (status == CAM_ERROR_NO_OPEN) {
uint16_t start_value = 0;
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaunused(client, &start_value)) {
set_open(client, start_value);
write_mask(client, mask, start_value, range_valid, mask_id);
const int new_status = add_key_to_open(client, key, ternary_mask, key_prio, mask, &unit,
range_valid, mask_id);
assert(new_status == 0);
assert(unit == start_value);
return 0;
}
else {
return CAM_ERROR_FULL;
}
}
assert(false);
return status;
}
int client_lookup_tcam(client_t *client, const aaaaaaaaaaaaa1aaat *key, aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *out_prio_resp)
{
assert(client_is_tcam(client));
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat lowest_prio;
memset(&lowest_prio, 0xff, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
uint16_t unit = 0;
const uint16_t response_width = client_get_response_width(client);
bool found = false;
while (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaopen_or_closed(client, &unit)) {
aaa1aaat *phm = client_get_phm(client, unit);
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat prio_resp;
memset(&prio_resp, 0, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
bool success = false;
success = aaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup(phm, key, &prio_resp);
if (success) {
found = true;
const uint8_t prio_width = client_get_prio_width(client);
assert(prio_width <= 32);
if (prio_width > 0) {
uint32_t prio_resp_prio;
uint32_t lowest_prio_prio;
const uint16_t start_pos = response_width;
const uint16_t end_pos = start_pos + prio_width - 1;
cam_read_field((uint32_t *) &prio_resp, start_pos, end_pos,
&prio_resp_prio);
cam_read_field((uint32_t *) &lowest_prio, start_pos, end_pos,
&lowest_prio_prio);
if (prio_resp_prio <= lowest_prio_prio) {
lowest_prio = prio_resp;
}
} else {
*out_prio_resp = prio_resp;
return 0;
}
}
unit++;
}
if (found) {
*out_prio_resp = lowest_prio;
return 0;
}
return CAM_ERROR_KEY_NOT_FOUND;
}
void aaaa1bbbbbbbbbbbbbbbb3aaa(aaaa1aaat *target_km, const aaaa1aaat *source_km)
{
assert(client_is_tcam(target_km->client));
uint32_t *aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata = target_km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata;
uint16_t *fingerprint = target_km->fingerprint;
source_bucket_t *source_bucket = target_km->source_bucket;
uint32_t *valid_cache = target_km->valid_cache;
*target_km = *source_km;
target_km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata = aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata;
target_km->fingerprint = fingerprint;
target_km->source_bucket = source_bucket;
target_km->valid_cache = valid_cache;
const uint32_t num_lists = client_get_num_lists(source_km->client);
const uint16_t list_length = client_get_list_length(source_km->client);
const uint8_t number_of_word32s = list_length / 32;
memcpy(target_km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata, source_km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata,
number_of_word32s * sizeof(uint32_t) * num_lists);
memcpy(target_km->source_bucket, source_km->source_bucket, sizeof(source_bucket_t) * num_lists);
memcpy(target_km->fingerprint, source_km->fingerprint, num_lists * sizeof *target_km->fingerprint);
uint8_t bits_per_list = 1;
memcpy(target_km->valid_cache, source_km->valid_cache, sizeof(uint32_t) * ((bits_per_list * num_lists + 31) / 32));
}
static void set_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(const aaaa1aaat *km, uint32_t list_number, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa,
uint8_t narrow, uint8_t narrow_element)
{
assert(!client_get_generation_number_granularity(km->client));
const uint16_t list_length = client_get_list_length(km->client);
uint16_t prio_field_end_pos = list_length - 2;
const uint16_t prio_width = client_get_prio_width(km->client);
assert(prio_width <= 32);
const uint16_t aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa = prio_width + client_get_response_width(km->client);
const uint16_t number_of_word32s = list_length / 32;
const bool mixed_mode = client_is_mixed_mode(km->client);
assert((!mixed_mode && narrow == false) || mixed_mode);
if (mixed_mode) {
if (narrow && (narrow_element == 0)) {
prio_field_end_pos = list_length / 2 - 3;
} else {
prio_field_end_pos = list_length - 3;
}
}
const uint16_t response_field_start_pos = prio_field_end_pos - aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaa + 1;
cam_write_field(&km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[list_number * number_of_word32s], response_field_start_pos,
prio_field_end_pos, (uint32_t *) aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, prio_field_end_pos);
}
void aaaa1bbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa,
uint8_t narrow, uint8_t narrow_element)
{
assert(client_is_tcam(km->client));
set_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, narrow, narrow_element);
if (km->flush == true) {
flush(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, false, false, OTHER, narrow, narrow_element, false, false);
}
}
static void divide_key_and_mask(aaaaaaaaaaaaa1aaat *key, aaaaaaaaaaaaa1aaat *ternary_mask,
const key_and_mask_t *key_and_mask)
{
memset(&(key->word[0]), 0, sizeof(aaaaaaaaaaaaa1aaat));
memset(&(ternary_mask->word[0]), 0, sizeof(aaaaaaaaaaaaa1aaat));
for (uint16_t i = 0; i < KEY_AND_MASK_WIDTH_MEM; i++) {
uint32_t word = key_and_mask->word[i];
for (uint16_t shift = 0; shift < 16; shift++) {
uint16_t key_bit = word & 1;
uint16_t mask_bit = (word & 2) >> 1;
word = word >> 2;
const uint16_t hi = (i & 1) * 16;
key->word[i / 2] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa(key->word[i / 2], key_bit, hi + shift, 1);
ternary_mask->word[i / 2] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa(ternary_mask->word[i / 2], mask_bit, hi + shift, 1);
}
}
}
static void merge_key_and_mask(key_and_mask_t *key_and_mask, const aaaaaaaaaaaaa1aaat *aaaaaaaaa1aaa,
const aaaaaaaaaaaaa1aaat *ternary_mask)
{
memset(&(key_and_mask->word[0]), 0, sizeof(key_and_mask_t));
for (uint16_t i = 0; i < KEY_AND_MASK_WIDTH_MEM; i++) {
uint32_t key_word = aaaaaaaaa1aaa->word[i / 2];
uint32_t mask_word = ternary_mask->word[i / 2];
if ((i & 1) == 1) {
key_word = key_word >> 16;
mask_word = mask_word >> 16;
}
uint32_t new_word = 0;
uint32_t bit_mask = 1;
for (uint16_t shift = 0; shift < 16; shift++) {
new_word |= key_word & bit_mask;
key_word <<= 1;
bit_mask <<= 1;
mask_word <<= 1;
new_word |= mask_word & bit_mask;
bit_mask <<= 1;
}
key_and_mask->word[i] = new_word;
}
}
void aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, const aaaaaaaaaaaaaaa1aaat *pointer_list, uint8_t narrow, uint8_t narrow_element)
{
assert(client_is_tcam(km->client));
assert(aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(pointer_list) > 0);
bool wide2narrow = false;
const aaaaaaaaaaaaa1aaat *aaaaaaaaa1aaa = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaa1aaa(pointer_list, 0);
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaptr = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaa4aaa(pointer_list, 0);
set_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaptr, narrow, narrow_element);
const aaaaaaaaaaaaa1aaat *ternary_mask = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaternary_mask(pointer_list, 0);
key_and_mask_t new_key;
merge_key_and_mask(&new_key, aaaaaaaaa1aaa, ternary_mask);
set_key(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, &new_key, narrow, narrow_element);
if (aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(pointer_list)) {
km->source_bucket[aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa].direct_pointer = true;
} else {
km->source_bucket[aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa].direct_pointer = false;
}
const uint32_t temp_bucket = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaabaaaaaaaaaaa4aaa(pointer_list);
assert(temp_bucket <= UINT16_MAX);
km->source_bucket[aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa].perfect_bucket = temp_bucket;
set_valid_bit(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, 1);
if (km->flush == true) {
flush(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, false, false, OTHER, narrow, narrow_element, false, wide2narrow);
}
}
void aaaa1aaaread(const aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, aaaaaaaaaaaaaaa1aaat *pointer_list)
{
assert(client_is_tcam(km->client));
if (aaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa))
return;
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa;
memset(&aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, 0, sizeof(aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa));
key_and_mask_t aaaaaaaaa1aaa;
aaaaaaaaaaaaa1aaat ternary_mask;
memset(&aaaaaaaaa1aaa, 0, sizeof(aaaaaaaaa1aaa));
if (((aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(pointer_list)) && km->source_bucket[aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa].direct_pointer)
|| ((!aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(pointer_list)) && !km->source_bucket[aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa].direct_pointer)) {
const uint32_t temp_bucket = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaabaaaaaaaaaaa4aaa(pointer_list);
assert(temp_bucket <= UINT16_MAX);
if (km->source_bucket[aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa].perfect_bucket == temp_bucket) {
get_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, &aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, 0, 0);
get_key(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, &aaaaaaaaa1aaa, 0, 0);
aaaaaaaaaaaaa1aaat new_key;
divide_key_and_mask(&new_key, &ternary_mask, &aaaaaaaaa1aaa);
aaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(pointer_list, &aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, &new_key, &ternary_mask, false, 0);
}
}
}
void aaaa1bbbbbbbbbbbbbbbbb3aaa(aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa)
{
assert(client_is_tcam(km->client));
assert(!aaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa));
set_valid_bit(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, 0);
if (km->flush == true) {
flush(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, false, false, OTHER, 0, 0, false, false);
}
}
bool aaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(const aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa)
{
assert(client_is_tcam(km->client));
assert(aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa < client_get_num_lists(km->client));
if (aaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa))
return false;
return km->source_bucket[aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa].direct_pointer;
}
uint32_t aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaabaaaaaaaaaaa4aaa(const aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa)
{
assert(client_is_tcam(km->client));
assert(false == aaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa));
return km->source_bucket[aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa].perfect_bucket;
}
bool aaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaafit_for_pointer_list(const aaaa1aaat *km,
const aaaaaaaaaaaaaaa1aaat *pointer_list, uint32_t *aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa)
{
assert(client_is_tcam(km->client));
const uint32_t end_list = client_get_num_lists(km->client) - 1;
assert(*aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa <= end_list);
uint32_t list_number = *aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa;
assert(aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(pointer_list) == 1);
const uint32_t number_of_iterations = end_list + 1;
uint16_t i = 0;
while (i < number_of_iterations) {
if (list_number > end_list) {
list_number = 0;
}
if (aaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(km, list_number)) {
*aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = list_number;
return true;
}
list_number++;
i++;
}
return false;
}
void aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaa(aaaa1aaat *km)
{
assert(client_is_tcam(km->client));
const uint32_t end_list = client_get_num_lists(km->client) - 1;
for (uint32_t i = 0; i <= end_list; i++) {
set_valid_bit(km, i, 0);
if (!(client_get_debug_flags(km->client) & CAM_DEBUG_SKIP_MEM_INIT)) {
flush(km, i, false, false, OTHER, 0, 0, false, false);
}
}
}
bool aaaa1aaaread_element_tcam(aaaa1aaat *km, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, aaaaaaaaaaaaaaa1aaat *pointer_list,
int *verify, uint8_t narrow,
uint8_t narrow_element)
{
assert(client_is_tcam(km->client));
const bool present = aaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaapresent(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, narrow, narrow_element);
if (!present)
return false;
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa;
memset(&aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, 0, sizeof(aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa));
key_and_mask_t aaaaaaaaa1aaa;
memset(&aaaaaaaaa1aaa, 0, sizeof(aaaaaaaaa1aaa));
get_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, &aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, narrow, narrow_element);
aaaaaaaaaaaaa1aaat ternary_mask;
aaaaaaaaaaaaa1aaat new_key;
aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(pointer_list, km->source_bucket[aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa].perfect_bucket,
km->source_bucket[aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa].direct_pointer, true);
get_key(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, &aaaaaaaaa1aaa, narrow, narrow_element);
divide_key_and_mask(&new_key, &ternary_mask, &aaaaaaaaa1aaa);
aaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(pointer_list, &aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa, &new_key, &ternary_mask, false, 0);
if (verify != NULL) {
flush(km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, false, verify, OTHER, narrow, narrow_element,
false, false);
}
return true;
}
void aaaa1bbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaand_flush(aaaa1aaat *target_km, aaaa1aaat *source_km, uint32_t list)
{
assert(client_is_tcam(target_km->client));
const uint16_t list_length = client_get_list_length(target_km->client);
const uint16_t number_of_word32s = list_length / 32;
const uint32_t word32 = list * number_of_word32s;
memcpy(&target_km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[word32], &source_km->aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaadata[word32],
number_of_word32s * sizeof(uint32_t));
memcpy(&target_km->source_bucket[list], &source_km->source_bucket[list], sizeof(source_bucket_t));
if (aaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(source_km, list))
set_valid_bit(target_km, list, 0);
else
set_valid_bit(target_km, list, 1);
assert(target_km->flush == true);
flush(target_km, list, false, false, OTHER, 0, 0, false, false);
}
bool aaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(aaa1aaat *phm, client_t *client, uint16_t unit, uint8_t slot_number)
{
assert(phm != NULL);
cam_malloc_func malloc_function = client_get_malloc_function(client);
phm->km = NULL;
phm->mm = NULL;
phm->km = (aaaa1aaat *) malloc_function(aaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa());
if (phm->km == NULL) {
return false;
}
phm->bm = (aa1aaat *) malloc_function(aa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa());
if (phm->bm == NULL) {
return false;
}
phm->mm = (aaaaaaaaaaaa1aaat *) malloc_function(aaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa());
if (phm->mm == NULL) {
return false;
}
if (!aaaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(phm->km, client, unit, slot_number, true)) {
return false;
}
if (!aa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(phm->bm, client, unit, slot_number, malloc_function)) {
return false;
}
aaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(phm->mm, client, unit, slot_number);
phm->number_of_keys = 0;
phm->client = client;
return true;
}
void aaa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(aaa1aaat *phm, cam_free_func free_function)
{
if (phm == NULL) {
return;
}
aaaa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(phm->km, free_function);
aa1aaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(phm->bm, free_function);
free_function(phm->mm);
free_function(phm);
}
static bool aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaand_read_element_tcam(const aaa1aaat *phm, uint32_t *start_value, aaaaaaaaaaaaa1aaat *key, aaaaaaaaaaaaa1aaat *ternary_mask,
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *priority,
uint64_t *bucket, int *verify, uint8_t *narrow, uint8_t *narrow_element)
{
assert(client_is_tcam(phm->client));
assert(narrow != NULL);
assert(narrow_element != NULL);
aaaaaaaaaaaaaaa1aaat *pointer_list = (aaaaaaaaaaaaaaa1aaat *) alloca(aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa());
const uint32_t segment_size = client_get_num_lists(phm->client);
const uint32_t max_start_value = segment_size - 1;
while (*start_value <= max_start_value) {
const uint32_t element = *start_value / segment_size;
const uint32_t aaaaaaaaaa1aaa = *start_value - element * segment_size;
if (aaaa1aaaread_element_tcam(phm->km, aaaaaaaaaa1aaa, pointer_list, verify, *narrow, *narrow_element)) {
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *priority_ptr = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaa4aaa(pointer_list, 0);
memcpy(priority, priority_ptr, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
const aaaaaaaaaaaaa1aaat *aaaaaaaaa1aaa = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaa1aaa(pointer_list, 0);
memcpy(key, aaaaaaaaa1aaa, sizeof(aaaaaaaaaaaaa1aaat));
const aaaaaaaaaaaaa1aaat *read_ternary_mask = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaternary_mask(pointer_list, 0);
memcpy(ternary_mask, read_ternary_mask, sizeof(aaaaaaaaaaaaa1aaat));
*bucket = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaabaaaaaaaaaaa4aaa(pointer_list);
return true;
} else {
if ((*narrow) && (*narrow_element == 0)) {
*narrow_element = 1;
} else if (*narrow) {
(*start_value)++;
*narrow_element = 0;
} else {
(*start_value)++;
}
}
}
return false;
}
static uint32_t adjust_bucket(const aaa1aaat *phm, uint32_t bucket)
{
const uint32_t num_lists = client_get_num_lists(phm->client);
const uint32_t num_buckets = aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO * num_lists;
const uint32_t max_bucket = num_buckets - 1;
const uint32_t bucket_addr_mask = max_bucket;
const uint32_t adjusted_bucket = bucket & bucket_addr_mask;
return adjusted_bucket;
}
static bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa6aaa(bool test, aaa1aaat *phm, uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa,
const aaaaaaaaaaaaaaa1aaat *pointer_list)
{
assert(client_is_tcam(phm->client));
assert(1 == aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(pointer_list));
assert(false == aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(pointer_list));
const uint32_t end_list = client_get_num_lists(phm->client) - 1;
if (aaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa)) {
aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, pointer_list, 0, 0);
return true;
}
if (!aaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa)) {
return false;
}
const uint32_t my_bucket = aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaabaaaaaaaaaaa4aaa(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
aaaaaaaaaaaaaaa1aaat *copy_pointer_list = (aaaaaaaaaaaaaaa1aaat *) alloca(aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa());
aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(copy_pointer_list, my_bucket, true, true);
aaaa1aaaread(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, copy_pointer_list);
uint32_t target_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa + 1;
if (target_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa > end_list) {
target_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = 0;
}
if (false
== aaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaafit_for_pointer_list(phm->km, copy_pointer_list,
&target_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa)) {
return false;
}
aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(phm->km, target_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, copy_pointer_list, 0, 0);
if (test == false) {
aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaapointer(phm->bm, my_bucket, target_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
}
aaaa1bbbbbbbbbbbbbbbbb3aaa(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, pointer_list, 0, 0);
return true;
}
static bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(aaa1aaat *phm, uint32_t bucket, const aaaaaaaaaaaaaaa1aaat *pointer_list,
hash_t *hash, uint8_t *the_function)
{
assert(1 == aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(pointer_list));
const uint8_t function = aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(phm->bm, bucket);
*the_function = function;
uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = hash_calculate_list(hash, function);
aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = aaa1aaaadjust_list(phm, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
if (false
== aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa6aaa(false, phm, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, pointer_list)) {
return false;
}
aa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaanext_key(phm->bm, bucket);
return true;
}
static bool convert_to_function(bool test, aaa1aaat *phm, const aaaaaaaaaaaaaaa1aaat *pointer_list,
hash_t *new_key_hash, uint8_t *working_function)
{
assert(client_is_tcam(phm->client));
assert(1 == aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(pointer_list));
assert(*working_function < aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaS);
const uint32_t bucket = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaabaaaaaaaaaaa4aaa(pointer_list);
const uint8_t number_of_keys = aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(phm->bm, bucket);
uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(phm->bm, bucket);
aaaaaaaaaaaaaaa1aaat *read_pointer_list = (aaaaaaaaaaaaaaa1aaat *) alloca(aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa());
aaaaaaaaaaaaaaa1aaat *aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaapointer_list = (aaaaaaaaaaaaaaa1aaat *) alloca(aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa());
aaaa1aaat *original_km = NULL;
aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(read_pointer_list, bucket, true, true);
aaaa1aaaread(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, read_pointer_list);
assert(aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(read_pointer_list) == number_of_keys);
uint8_t function = *working_function;
uint8_t end_function;
if (test) {
original_km = phm->km;
phm->km = client_get_test_km(phm->client);
if (*working_function == 0) {
end_function = aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaS - 1;
} else {
end_function = *working_function - 1;
}
} else {
if (*working_function == (aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaS - 1)) {
end_function = 0;
} else {
end_function = *working_function + 1;
}
}
while (end_function != function)
{
bool success = true;
uint8_t key_number;
if (test) {
aaaa1bbbbbbbbbbbbbbbb3aaa(phm->km, original_km);
aaaa1bbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbb4aaa(phm->km);
}
hash_t *hash = (hash_t *) alloca(hash_size());
for (key_number = 0; key_number < number_of_keys; key_number++) {
const aaaaaaaaaaaaa1aaat *aaaaaaaaa1aaa = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaa1aaa(read_pointer_list, key_number);
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat prio;
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *prio_ptr = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaa4aaa(read_pointer_list, key_number);
memcpy(&prio, prio_ptr, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
const aaaaaaaaaaaaa1aaat *ternary_mask = NULL;
if (client_is_tcam(phm->client)) {
aaaaaaaaaaaaa1aaat masked_key;
memset(&masked_key, 0, sizeof(masked_key));
aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->mm, aaaaaaaaa1aaa, &masked_key);
aaaaaaa1aaa(hash, &masked_key, phm);
ternary_mask = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaternary_mask(read_pointer_list, key_number);
} else {
aaaaaaa1aaa(hash, aaaaaaaaa1aaa, phm);
}
uint32_t new_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = hash_calculate_list(hash, function);
new_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = aaa1aaaadjust_list(phm, new_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaapointer_list, bucket, false, true);
aaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaapointer_list, &prio, aaaaaaaaa1aaa, ternary_mask, false, 0);
if (false
== aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa6aaa(test, phm, new_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa,
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaapointer_list)) {
success = false;
break;
}
}
if (success) {
uint32_t new_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = hash_calculate_list(new_key_hash, function);
new_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = aaa1aaaadjust_list(phm, new_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
if (false
== aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa6aaa(test, phm, new_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa,
pointer_list)) {
assert(test);
function++;
if (function == aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaS) {
function = 0;
}
continue;
}
if (test) {
phm->km = original_km;
*working_function = function;
} else {
uint32_t direct_pointer = aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(phm->bm, bucket);
aa1bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaapointer(phm->bm, bucket, function);
aa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaanext_key(phm->bm, bucket);
aaaa1bbbbbbbbbbbbbbbbb3aaa(phm->km, direct_pointer);
}
return true;
} 
assert(test);
function++;
if (function == aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaS) {
function = 0;
}
}
if (test) {
phm->km = original_km;
}
return false;
}
static void get_pending_deletes(const aaa1aaat *phm, uint32_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaa, uint8_t *number_of_pending_deletes,
uint32_t pending_deletes[64])
{
assert(client_is_tcam(phm->client));
aaaaaaaaaaaaa1aaat key;
aaaaaaaaaaaaa1aaat ternary_mask;
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat priority;
uint64_t bucket;
uint32_t start_value = 0;
*number_of_pending_deletes = 0;
uint8_t narrow = 0;
uint8_t narrow_element = 0;
while (aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaand_read_element_tcam(phm, &start_value, &key, &ternary_mask,
&priority, &bucket, NULL, &narrow,
&narrow_element)) {
if (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaa == bucket) {
assert((*number_of_pending_deletes) < 64);
pending_deletes[*number_of_pending_deletes] = start_value;
(*number_of_pending_deletes)++;
}
start_value++;
}
}
static bool delete_element(aaa1aaat *phm, uint32_t *start_value)
{
assert(client_is_tcam(phm->client));
aaaaaaaaaaaaaaa1aaat *pointer_list = (aaaaaaaaaaaaaaa1aaat *) alloca(aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa());
const uint32_t segment_size = client_get_num_lists(phm->client);
const uint32_t max_start_value = segment_size - 1;
uint32_t element_counter = *start_value;
while (element_counter <= max_start_value) {
const uint32_t element = element_counter / segment_size;
const uint32_t aaaaaaaaaa1aaa = element_counter - element * segment_size ;
if (aaaa1aaaread_element_tcam(phm->km, aaaaaaaaaa1aaa, pointer_list, NULL, 0, 0)) {
const uint32_t bucket = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaabaaaaaaaaaaa4aaa(pointer_list);
aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->bm, bucket);
aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaelement(phm->km, aaaaaaaaaa1aaa, 0, 0);
*start_value = element_counter;
return true;
} else {
element_counter++;
}
}
return false;
}
static bool change_function(bool test, aaa1aaat *phm, const aaaaaaaaaaaaaaa1aaat *pointer_list,
hash_t *new_key_hash, uint8_t *working_function)
{
assert(client_is_tcam(phm->client));
assert(1 == aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(pointer_list));
assert(*working_function < aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaS);
const uint32_t bucket = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaabaaaaaaaaaaa4aaa(pointer_list);
const uint8_t number_of_keys = aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(phm->bm, bucket);
const uint32_t segment_size = client_get_num_lists(phm->client);
const uint32_t end_aaaaaaaaaa1aaa = segment_size - 1;
aaaaaaaaaaaaaaa1aaat *read_pointer_list = (aaaaaaaaaaaaaaa1aaat *) alloca(aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa());
aaaaaaaaaaaaaaa1aaat *aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaapointer_list = (aaaaaaaaaaaaaaa1aaat *) alloca(aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa());
aaaa1aaat *original_km = NULL;
aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(read_pointer_list, bucket, false, true);
for (uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = 0; aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa <= end_aaaaaaaaaa1aaa; aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa++) {
aaaa1aaaread(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, read_pointer_list);
}
uint32_t pending_deletes[64];
uint8_t number_of_pending_deletes;
get_pending_deletes(phm, bucket, &number_of_pending_deletes, pending_deletes);
uint8_t function = *working_function;
uint8_t end_function;
if (test) {
original_km = phm->km;
phm->km = client_get_test_km(phm->client);
if (function == 0) {
end_function = aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaS - 1;
} else {
end_function = function - 1;
}
} else {
if (function == (aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaS - 1)) {
end_function = 0;
} else {
end_function = function + 1;
}
}
while (end_function != function) {
bool success = true;
uint8_t key_number;
if (test) {
aaaa1bbbbbbbbbbbbbbbb3aaa(phm->km, original_km);
aaaa1bbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbb4aaa(phm->km);
}
hash_t *hash = (hash_t *) alloca(hash_size());
for (key_number = 0; key_number < number_of_keys; key_number++) {
const aaaaaaaaaaaaa1aaat *aaaaaaaaa1aaa = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaa1aaa(read_pointer_list, key_number);
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat prio;
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *prio_ptr = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaa4aaa(read_pointer_list, key_number);
memcpy(&prio, prio_ptr, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
const aaaaaaaaaaaaa1aaat *ternary_mask = NULL;
if (client_is_tcam(phm->client)) {
aaaaaaaaaaaaa1aaat masked_key;
memset(&masked_key, 0, sizeof(masked_key));
aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->mm, aaaaaaaaa1aaa, &masked_key);
aaaaaaa1aaa(hash, &masked_key, phm);
ternary_mask = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaternary_mask(read_pointer_list, key_number);
} else {
aaaaaaa1aaa(hash, aaaaaaaaa1aaa, phm);
}
assert(function < aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaS);
uint32_t new_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = hash_calculate_list(hash, function);
new_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = aaa1aaaadjust_list(phm, new_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaapointer_list, bucket, false, true);
aaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaapointer_list, &prio, aaaaaaaaa1aaa, ternary_mask, false, 0);
if (false
== aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa6aaa(test, phm, new_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa,
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaapointer_list)) {
success = false;
break;
}
}
if (success) {
assert(function < aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaS);
uint32_t new_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = hash_calculate_list(new_key_hash, function);
new_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = aaa1aaaadjust_list(phm, new_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
if (false
== aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa6aaa(test, phm, new_aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa,
pointer_list)) {
assert(test);
function++;
if (function == aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaS) {
function = 0;
}
continue;
}
if (test) {
phm->km = original_km;
*working_function = function;
} else {
aa1bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaapointer(phm->bm, bucket, function);
aa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaanext_key(phm->bm, bucket);
for (uint8_t i = 0; i < number_of_pending_deletes; i++) {
uint32_t start_value = pending_deletes[i];
const bool status = delete_element(phm, &start_value);
aa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaanext_key(phm->bm, bucket);
assert(status);
assert(start_value == pending_deletes[i]);
}
assert(aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(phm->bm, bucket) == (number_of_keys + 1));
}
return true;
} 
assert(test);
function++;
if (function == aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaS) {
function = 0;
}
}
if (test) {
phm->km = original_km;
}
return false;
}
static void delete_mask(aaa1aaat *phm)
{
assert(client_is_tcam(phm->client));
aaaaaaaaaaaa1bbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6aaa(phm->mm);
aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaa(phm->bm);
aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaa(phm->km);
phm->number_of_keys = 0;
}
static uint32_t get_max_number_of_keys(const aaa1aaat *phm)
{
const uint32_t num_lists = client_get_num_lists(phm->client);
return num_lists * aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO;
}
static void write_range_value(uint32_t *words, uint16_t start_pos, uint16_t end_pos, uint16_t range_value)
{
const uint16_t bit_diff = end_pos - start_pos + 1;
assert(bit_diff > 0);
assert(bit_diff <= 16);
uint8_t start_word = start_pos / 32;
uint8_t start_word_start = start_pos - start_word * 32;
uint8_t end_word = end_pos / 32;
uint8_t end_word_end = end_pos - end_word * 32;
uint8_t word_diff = end_word - start_word;
assert(word_diff < 2);
if (word_diff == 0) {
words[start_word] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa(words[start_word], range_value, start_word_start,
end_word_end - start_word_start + 1);
} else {
uint32_t value = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(range_value, 0, 32 - start_word_start);
words[start_word] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa(words[start_word], value, start_word_start, 32 - start_word_start);
value = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(range_value, 32 - start_word_start, bit_diff - (32 - start_word_start));
words[end_word] = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa(words[end_word], value, 0, bit_diff - (32 - start_word_start));
}
}
static uint16_t read_range_value(const uint32_t *words, uint16_t start_pos, uint16_t end_pos)
{
assert(start_pos <= end_pos);
const uint16_t bit_diff = end_pos - start_pos + 1;
assert(bit_diff <= 16);
uint8_t start_word = start_pos / 32;
uint8_t start_word_start = start_pos - start_word * 32;
uint8_t end_word = end_pos / 32;
uint8_t end_word_end = end_pos - end_word * 32;
uint8_t word_diff = end_word - start_word;
assert(word_diff < 2);
if (word_diff == 0) {
return aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(words[start_word], start_word_start, end_word_end - start_word_start + 1);
} else {
const uint32_t value0 = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(words[start_word], start_word_start, 32 - start_word_start);
const uint32_t value1 = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(words[end_word], 0, end_word_end + 1);
return aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa3aaa(value0, value1, 32 - start_word_start, end_word_end + 1);
}
}
int aaa1aaacheck_ternary_mask(const client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaa1aaat *ternary_mask,
const aaaaaaaaaaaaa1aaat *mask, uint8_t range_valid)
{
if (ternary_mask == NULL) {
return CAM_ERROR_WRONG_TERNARY_MASK;
}
aaaaaaaaaaaaa1aaat copy_key;
memcpy(&copy_key, key, sizeof(copy_key));
const uint8_t num_ranges = client_get_num_ranges(client);
for (uint8_t i = 0; i < num_ranges; i++) {
uint16_t start_pos;
int rc = client_get_range_start_pos(client, i, &start_pos);
assert(rc == 0);
uint8_t width;
rc = client_get_range_width(client, i, &width);
assert(rc == 0);
const uint16_t end_pos = start_pos + width - 1;
uint16_t range_start = read_range_value(&key->word[0], start_pos, end_pos);
uint16_t range_mask = read_range_value(&mask->word[0], start_pos, end_pos);
uint16_t range_end = read_range_value(&ternary_mask->word[0], start_pos, end_pos);
if (range_valid & (1 << i)) {
if (range_start > range_end)
return CAM_ERROR_WRONG_RANGE;
if (range_mask != 0)
return CAM_ERROR_WRONG_RANGE_MASK;
write_range_value(&copy_key.word[0], start_pos, end_pos, 0);
}
}
const uint16_t key_width = client_get_key_width(client);
uint16_t number_of_words = key_width / 32;
for (uint16_t i = 0; i < number_of_words; i++) {
if ((ternary_mask->word[i] & mask->word[i]) != mask->word[i])
return CAM_ERROR_WRONG_TERNARY_MASK;
if ((ternary_mask->word[i] & copy_key.word[i]) != copy_key.word[i]) {
return CAM_ERROR_MASKED_KEY_BIT_IS_SET;
}
}
const uint8_t remaining_bits = key_width - number_of_words * 32;
if (remaining_bits > 0) {
const uint32_t remaining_key_bits = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(copy_key.word[number_of_words], 0, remaining_bits);
const uint32_t remaining_mask_bits = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(mask->word[number_of_words], 0, remaining_bits);
const uint32_t remaining_ternary_mask_bits = aaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaa(ternary_mask->word[number_of_words], 0, remaining_bits);
if ((remaining_ternary_mask_bits & remaining_mask_bits) != remaining_mask_bits)
return CAM_ERROR_WRONG_TERNARY_MASK;
if ((remaining_ternary_mask_bits & remaining_key_bits) != remaining_key_bits) {
return CAM_ERROR_MASKED_KEY_BIT_IS_SET;
}
}
return 0;
}
static bool match_ternary_mask(const client_t *client, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaa1aaat *ternary_mask,
const aaaaaaaaaaaaa1aaat *aaaaaaaaa1aaa, uint8_t range_valid)
{
aaaaaaaaaaaaa1aaat copy_ternary_mask;
memcpy(&copy_ternary_mask, ternary_mask, sizeof(copy_ternary_mask));
const uint8_t num_ranges = client_get_num_ranges(client);
for (uint8_t i = 0; i < num_ranges; i++) {
uint16_t start_pos;
int rc = client_get_range_start_pos(client, i, &start_pos);
assert(rc == 0);
uint8_t width;
rc = client_get_range_width(client, i, &width);
assert(rc == 0);
const uint16_t end_pos = start_pos + width - 1;
uint16_t range_start = read_range_value(&aaaaaaaaa1aaa->word[0], start_pos, end_pos);
uint16_t compare = read_range_value(&key->word[0], start_pos, end_pos);
uint16_t range_end = read_range_value(&ternary_mask->word[0], start_pos, end_pos);
if (range_valid & (1 << i)) {
if ((compare < range_start) || (compare > range_end)) {
return false;
}
write_range_value(&copy_ternary_mask.word[0], start_pos, end_pos, 0);
}
}
uint16_t ternary_field_size = (client_get_key_width(client) + 31) / 32;
for (uint16_t i = 0; i < ternary_field_size; i++) {
uint32_t mask_word = copy_ternary_mask.word[i];
if ((aaaaaaaaa1aaa->word[i] & mask_word) != (mask_word & key->word[i])) {
return false;
}
}
return true;
}
static bool recover(aaa1aaat *phm, const aaaaaaaaaaaaa1aaat *add_aaaaaaaaa1aaa, const aaaaaaaaaaaaa1aaat *add_ternary_mask,
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *add_priority, uint32_t add_bucket);
bool aaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaa(aaa1aaat *phm, const aaaaaaaaaaaaa1aaat *key, const aaaaaaaaaaaaa1aaat *ternary_mask,
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *priority,
bool true_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaafit,
uint8_t recover_start_function)
{
assert(client_is_tcam(phm->client));
const int16_t margin = get_max_number_of_keys(phm) - phm->number_of_keys;
assert(margin >= 0);
if (margin == 0) {
return false;
}
uint32_t bucket;
aaaaaaaaaaaaaaa1aaat *pointer_list = (aaaaaaaaaaaaaaa1aaat *) alloca(aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa());
hash_t *hash = (hash_t *) alloca(hash_size());
aaaaaaaaaaaaa1aaat *aaaaaaaaa1aaa; 
uint32_t bucket_hash;
aaaaaaaaaaaaa1aaat masked_key;
memset(&masked_key, 0, sizeof(masked_key));
aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->mm, key, &masked_key);
aaaaaaa1aaa(hash, &masked_key, phm);
bucket_hash = hash_calculate_bucket(hash);
bucket = adjust_bucket(phm, bucket_hash);
aaaaaaaaa1aaa = (aaaaaaaaaaaaa1aaat *) key;
if (aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->bm, bucket)) {
uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa;
if (true_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaafit) {
aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = 0;
} else {
aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = aaa1aaaadjust_list(phm, bucket);
}
aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(pointer_list, bucket, true, true);
aaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(pointer_list, priority, aaaaaaaaa1aaa, ternary_mask, false, 0);
if (false == aaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaafit_for_pointer_list(phm->km, pointer_list, &aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa)) {
return recover(phm, aaaaaaaaa1aaa, ternary_mask, priority, bucket);
}
aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, pointer_list, 0, 0);
aa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->bm, bucket, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
} else if (aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(phm->bm, bucket)) {
if (2 > margin) {
return recover(phm, aaaaaaaaa1aaa, ternary_mask, priority, bucket);
}
aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(pointer_list, bucket, false, true);
aaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(pointer_list, priority, aaaaaaaaa1aaa, ternary_mask, false, 0);
uint8_t working_function = recover_start_function;
if (false == convert_to_function(true, phm, pointer_list, hash, &working_function)) {
return recover(phm, aaaaaaaaa1aaa, ternary_mask, priority, bucket);
}
if (false == convert_to_function(false, phm, pointer_list, hash, &working_function)) {
assert(false);
}
} else if (aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(phm->bm, bucket)) {
aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(pointer_list, bucket, false, true);
aaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(pointer_list, priority, aaaaaaaaa1aaa, ternary_mask, false, 0);
uint8_t the_function;
if (false == aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(phm, bucket, pointer_list, hash, &the_function)) {
const uint8_t number_of_keys = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(pointer_list);
if ((number_of_keys) > margin) {
return recover(phm, aaaaaaaaa1aaa, ternary_mask, priority, bucket);
}
the_function++;
if (the_function == aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaS) {
the_function = 0;
}
if (false == change_function(true, phm, pointer_list, hash, &the_function)) {
return recover(phm, aaaaaaaaa1aaa, ternary_mask, priority, bucket);
} else {
const bool status = change_function(false, phm, pointer_list, hash, &the_function);
assert(status);
phm->number_of_keys++;
return true;
}
}
} else {
assert(false);
}
phm->number_of_keys++;
return true;
}
bool aaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(aaa1aaat *phm, const aaaaaaaaaaaaa1aaat *key,
const aaaaaaaaaaaaa1aaat *ternary_mask,
aaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaat execute,
bool *unresolvable_collision_found,
bool match_prio,
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *comp_prio, int *verify)
{
assert(client_is_tcam(phm->client));
assert(
((execute != aaa1aaaREAD) && (verify == NULL)) || (execute == aaa1aaaREAD));
uint32_t bucket;
aaaaaaaaaaaaa1aaat masked_key;
memset(&masked_key, 0, sizeof(masked_key));
aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->mm, key, &masked_key);
hash_t *hash = (hash_t *) alloca(hash_size());
aaaaaaa1aaa(hash, &masked_key, phm);
uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = 0;
const uint32_t bucket_hash = hash_calculate_bucket(hash);
bucket = adjust_bucket(phm, bucket_hash);
if (aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->bm, bucket)) {
*unresolvable_collision_found = false;
return false;
} else if (aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(phm->bm, bucket)) {
aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(phm->bm, bucket);
} else if (aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(phm->bm, bucket)) {
const uint8_t function = aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(phm->bm, bucket);
aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = hash_calculate_list(hash, function);
aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = aaa1aaaadjust_list(phm, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
} else {
assert(false);
}
aaaaaaaaaaaaaaa1aaat *read_pointer_list = (aaaaaaaaaaaaaaa1aaat *) alloca(aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa());
bool unresolvable_collision = false;
if (aaaa1aaaread_element_tcam(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, read_pointer_list, NULL, 0,
0)) {
if (bucket != aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaabaaaaaaaaaaa4aaa(read_pointer_list)) {
*unresolvable_collision_found = false;
return false;
}
const aaaaaaaaaaaaa1aaat *stored_key = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaa1aaa(read_pointer_list, 0);
const aaaaaaaaaaaaa1aaat *stored_ternary_mask = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaternary_mask(read_pointer_list, 0);
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *prio_ptr = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaa4aaa(read_pointer_list, 0);
aaaaaaaaaaaaa1aaat masked_stored_key;
memset(&masked_stored_key, 0, sizeof(masked_stored_key));
aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->mm, stored_key, &masked_stored_key);
unresolvable_collision = true;
for (uint8_t j = 0; j < CAM_MAX_KEY_WIDTH_MEM; j++) {
if (masked_stored_key.word[j] != masked_key.word[j]) {
unresolvable_collision = false;
break;
}
}
bool exact_match = unresolvable_collision;
assert(ternary_mask != NULL);
const uint16_t ternary_field_size_word32 = client_get_key_width(phm->client) / 32;
for (uint8_t k = 0; k < ternary_field_size_word32; k++) {
if (!((stored_key->word[k] == key->word[k]) && (stored_ternary_mask->word[k] == ternary_mask->word[k]))) {
exact_match = false;
break;
}
}
if (match_prio) {
const int prio_memcmp_rc = memcmp(prio_ptr, comp_prio, sizeof(aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat));
if (prio_memcmp_rc != 0)
exact_match = false;
}
if (exact_match) {
if (execute == aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaa) {
aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->bm, bucket);
aaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaelement(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, 0, 0);
assert(phm->number_of_keys > 0);
phm->number_of_keys--;
return true;
} else if (execute == aaa1aaaREAD) {
if (match_prio == false) {
*comp_prio = *prio_ptr;
}
if (verify) {
const bool success = aaaa1aaaread_element_tcam(phm->km,
aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, read_pointer_list, verify, 0, 0);
assert(success);
}
return true;
} else if (execute == aaa1bbbbbbbbbbbbbbbbbbbb3aaa) {
aaaa1bbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, comp_prio, 0, 0);
return true;
}
assert(false);
}
}
if (unresolvable_collision) {
*unresolvable_collision_found = true;
}
else {
*unresolvable_collision_found = false;
}
return false;
}
bool aaa1bbbbbbbbbbbbbbbbbbbbbb3aaaokup(const aaa1aaat *phm, const aaaaaaaaaaaaa1aaat *key, aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *out_prio_resp)
{
assert(client_is_tcam(phm->client));
uint32_t bucket;
uint8_t range_valid;
aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(phm->mm, &range_valid);
aaaaaaaaaaaaa1aaat masked_key;
memset(&masked_key, 0, sizeof(masked_key));
aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->mm, key, &masked_key);
hash_t *hash = (hash_t *) alloca(hash_size());
aaaaaaa1aaa(hash, &masked_key, phm);
uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = 0;
const uint32_t bucket_hash = hash_calculate_bucket(hash);
bucket = adjust_bucket(phm, bucket_hash);
if (aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaa(phm->bm, bucket)) {
return false;
} else if (aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(phm->bm, bucket)) {
aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(phm->bm, bucket);
} else if (aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(phm->bm, bucket)) {
const uint8_t function = aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(phm->bm, bucket);
aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = hash_calculate_list(hash, function);
aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = aaa1aaaadjust_list(phm, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa);
} else {
assert(false);
}
aaaaaaaaaaaaaaa1aaat *read_pointer_list = (aaaaaaaaaaaaaaa1aaat *) alloca(aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa());
if (aaaa1aaaread_element_tcam(phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, read_pointer_list, NULL, 0,
0)) {
const aaaaaaaaaaaaa1aaat *aaaaaaaaa1aaa = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaa1aaa(read_pointer_list, 0);
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *prio_ptr = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaa4aaa(read_pointer_list, 0);
const aaaaaaaaaaaaa1aaat *ternary_mask = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaternary_mask(read_pointer_list, 0);
bool match = match_ternary_mask(phm->client, key, ternary_mask, aaaaaaaaa1aaa, range_valid);
if (match == true) {
*out_prio_resp = *prio_ptr;
return true;
}
} 
return false;
}
bool aaa1bbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaone_element(aaa1aaat *target_phm, aaa1aaat *source_phm)
{
assert(client_is_tcam(target_phm->client));
assert(target_phm != source_phm);
aaaaaaaaaaaaa1aaat aaaaaaaaa1aaa;
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat priority;
uint64_t bucket;
aaaaaaaaaaaaa1aaat ternary_mask;
uint32_t start_value = 0;
uint8_t narrow = 0;
uint8_t narrow_element = 0;
if (!aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaand_read_element_tcam(source_phm, &start_value, &aaaaaaaaa1aaa, &ternary_mask, &priority,
&bucket,
NULL, &narrow, &narrow_element)) {
assert(false);
}
if (!aaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaa(target_phm, &aaaaaaaaa1aaa, &ternary_mask, &priority, false, 0)) {
return false;
}
uint32_t new_start_value = start_value;
if (!delete_element(source_phm, &new_start_value)) {
assert(false);
}
assert(start_value == new_start_value);
assert(source_phm->number_of_keys > 0);
source_phm->number_of_keys--;
return true;
}
bool aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaa(aaa1aaat *phm, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *response_mask,
uint32_t *start_value,
aaaaaaaaaaaaa1aaat *aaaaaaaaa1aaa,
aaaaaaaaaaaaa1aaat *ternary_mask, uint8_t *narrow,
uint8_t *narrow_element, bool narrow_key, int *verify)
{
assert(client_is_tcam(phm->client));
uint64_t bucket;
const uint32_t number_of_keys = aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(phm);
if (number_of_keys == 0) {
return false;
}
aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat priority;
assert((narrow_key && (*narrow != 0)) || !narrow_key);
while (aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaand_read_element_tcam(phm, start_value, aaaaaaaaa1aaa,
ternary_mask, &priority, &bucket, NULL, narrow,
narrow_element)) {
assert((narrow_key && (*narrow != 0)) || !narrow_key);
bool match = true;
for (uint16_t i = 0; i < CAM_MAX_aaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaMEM; i++) {
if ((priority.word[i] & response_mask->word[i]) != (response->word[i] & response_mask->word[i])) {
match = false;
}
}
if (match) {
if (verify) {
const bool success = aaa1aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaand_read_element_tcam(phm, start_value,
aaaaaaaaa1aaa, ternary_mask, &priority, &bucket,
verify, narrow, narrow_element);
assert(success);
}
return true;
}
if ((*narrow != 0) && ((*narrow_element) == 0) && narrow_key) {
*narrow_element = 1;
} else {
(*start_value)++;
*narrow_element = 0;
}
}
return false;
}
static bool write_list(aaa1aaat *target_phm, aaaaaaaaaaaaaaa1aaat *read_pointer_list, uint8_t attempt)
{
const uint8_t largest_len = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(read_pointer_list);
for (uint8_t i = 0; i < largest_len; i++) {
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *priority = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaa4aaa(read_pointer_list, i);
const aaaaaaaaaaaaa1aaat *aaaaaaaaa1aaa = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaa1aaa(read_pointer_list, i);
const aaaaaaaaaaaaa1aaat *ternary_mask = aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaternary_mask(read_pointer_list, i);
if (false
== aaa1aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaa(target_phm, aaaaaaaaa1aaa, ternary_mask, priority,
true, attempt)) {
return false;
}
}
return true;
}
static bool aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaand_read_list(const aaa1aaat *source_phm, bool add_key,
const aaaaaaaaaaaaa1aaat *add_aaaaaaaaa1aaa,
const aaaaaaaaaaaaa1aaat *add_ternary_mask, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *add_priority, uint32_t add_bucket,
uint32_t *start_value, uint8_t *list_len, aaaaaaaaaaaaaaa1aaat *read_pointer_list)
{
assert(client_is_tcam(source_phm->client));
const uint32_t segment_size = client_get_num_lists(source_phm->client);
const uint32_t num_lists = client_get_num_lists(source_phm->client);
const uint32_t bucket_end_value = num_lists * aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO;
const uint32_t bucket_start_value = *start_value;
uint8_t largest_len = 0;
uint32_t largest_bucket = 0;
for (uint32_t bucket = bucket_start_value; bucket < bucket_end_value; bucket++) {
uint8_t number_of_keys = aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(source_phm->bm, bucket);
if ((bucket == add_bucket) && add_key) {
number_of_keys++;
}
if (*start_value > 0) {
if (number_of_keys == *list_len) {
largest_len = number_of_keys;
largest_bucket = bucket;
break;
}
}
else {
if (number_of_keys <= *list_len) {
if (number_of_keys > largest_len) {
largest_len = number_of_keys;
largest_bucket = bucket;
}
}
}
}
if (largest_len == 0) {
return false;
}
if (aa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(source_phm->bm, largest_bucket)) {
aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(read_pointer_list, largest_bucket, false, true);
const uint32_t end_aaaaaaaaaa1aaa = segment_size - 1;
for (uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = 0; aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa <= end_aaaaaaaaaa1aaa; aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa++) {
aaaa1aaaread(source_phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, read_pointer_list);
}
} else {
aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaaa3aaa(read_pointer_list, largest_bucket, true, true);
uint32_t aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa;
aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa = aa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaapointer(source_phm->bm, largest_bucket);
aaaa1aaaread(source_phm->km, aaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa, read_pointer_list);
}
if ((largest_bucket == add_bucket) && add_key) {
aaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa(read_pointer_list, add_priority, add_aaaaaaaaa1aaa, add_ternary_mask, false, 0);
}
assert(largest_len == aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaof_keys(read_pointer_list));
*list_len = largest_len;
*start_value = largest_bucket;
return true;
}
#define SEED_ATTEMPTS 256
static bool move_longest_list_first(aaa1aaat *target_phm, aaa1aaat *source_phm, bool add_key,
const aaaaaaaaaaaaa1aaat *add_aaaaaaaaa1aaa,
const aaaaaaaaaaaaa1aaat *add_ternary_mask, const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *add_priority,
uint32_t add_bucket,
uint8_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaatry, uint16_t seed_increment)
{
assert(!aaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaavalid(target_phm->mm));
aaaaaaaaaaaaa1aaat mask;
memset(&mask, 0, sizeof(aaaaaaaaaaaaa1aaat));
uint8_t range_valid;
uint8_t mask_id;
aaaaaaaaaaaa1aaaread_mask(source_phm->mm, &mask, &range_valid, &mask_id);
uint16_t source_seed = aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaseed(source_phm->mm);
source_seed = (source_seed + seed_increment) & 0xff;
aaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6aaa(target_phm, &mask, source_seed,
range_valid, mask_id);
uint32_t start_value = 0;
uint8_t list_len = UINT8_MAX;
aaaaaaaaaaaaaaa1aaat *read_pointer_list = alloca(aaaaaaaaaaaaaaa1aaaaaaaaaaaaaabaaaaaaaaaa3aaa());
while (list_len > 0) {
aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaall(read_pointer_list);
while (aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaand_read_list(source_phm, add_key, add_aaaaaaaaa1aaa, add_ternary_mask,
add_priority, add_bucket,
&start_value, &list_len,
read_pointer_list)) {
const bool success = write_list(target_phm, read_pointer_list, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaatry);
if (!success) {
delete_mask(target_phm);
return false;
}
aaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaall(read_pointer_list);
start_value++; 
}
start_value = 0;
list_len--; 
}
return true;
}
uint8_t highest_function = 0;
uint8_t highest_seed_increment = 0;
uint32_t num_rec = 0;
void phm_read_and_clear_recover_stats(uint8_t *highest_recover_function, uint8_t *highest_recover_seed_increment,
uint32_t *num_recovers)
{
*highest_recover_function = highest_function;
*highest_recover_seed_increment = highest_seed_increment;
*num_recovers = num_rec;
highest_function = 0;
highest_seed_increment = 0;
num_rec = 0;
}
static bool recover(aaa1aaat *phm, const aaaaaaaaaaaaa1aaat *add_aaaaaaaaa1aaa, const aaaaaaaaaaaaa1aaat *add_ternary_mask,
const aaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaat *add_priority, uint32_t add_bucket)
{
aaa1aaat *recover_phm = client_get_recover_phm(phm->client);
if (phm == recover_phm) {
return false;
}
if (aaaaaaaaaaaa1aaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaavalid(recover_phm->mm)) {
return false;
}
bool success = false;
uint8_t i;
num_rec++;
for (uint16_t seed_increment = 0; seed_increment < SEED_ATTEMPTS; seed_increment++) {
if (seed_increment > highest_seed_increment)
highest_seed_increment = seed_increment;
for (i = 0; i < aaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaS; i++) {
if (i > highest_function) {
highest_function = i;
}
success = move_longest_list_first(recover_phm, phm, true, add_aaaaaaaaa1aaa,
add_ternary_mask, add_priority,
add_bucket, i, seed_increment);
if (success) {
break;
} 
}
if (success)
break;
}
assert(success);
aaaaaaaaaaaa1bbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6aaa(phm->mm);
const uint32_t segment_size = client_get_num_lists(phm->client);
const uint32_t num_lists = client_get_num_lists(phm->client);
const uint32_t end_bucket = num_lists * aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO - 1;
for (uint32_t bucket = 0; bucket <= end_bucket; bucket++) {
aa1bbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaand_flush(phm->bm, recover_phm->bm, bucket);
}
const uint32_t end_list = segment_size - 1;
for (uint32_t list = 0; list <= end_list; list++) {
aaaa1bbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaand_flush(phm->km, recover_phm->km, list);
}
const uint16_t seed = aaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaseed(recover_phm->mm);
aaaaaaaaaaaa1bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaseed(phm->mm, seed);
aaaaaaaaaaaa1bbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaaaaaaaaaabaaaaaaaaaaa6aaa(phm->mm);
phm->number_of_keys = recover_phm->number_of_keys;
delete_mask(recover_phm);
return true;
}
#ifndef VC_HBMDEF_H
#define VC_HBMDEF_H
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaVIRTUAL_CONTAINER_aaaaaaaaaaaaaaaaaaaaaa1aaa (0x90) 
#define Haa1aaaBCAM_BASE_CNF_VC_WRITE_DATA_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x94) 
#define Haa1aaaBCAM_NUMBER_SEGMENTS 256
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaRD (0x1)
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaWR (0x0)
#define Haa1aaaBCAM_BASE_CNF_VC_WRITE_DATA_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaSHIFT_SEG_0 (0)
#define Haa1aaaBCAM_BASE_CNF_VC_WRITE_DATA_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaSHIFT_SEG_1 (8)
#define Haa1aaaBCAM_BASE_CNF_VC_WRITE_DATA_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaSHIFT_SEG_2 (16)
#define Haa1aaaBCAM_BASE_CNF_VC_WRITE_DATA_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaSHIFT_SEG_3 (24)
#define Haa1aaaBCAM_BASE_CNF_VC_WRITE_NUM_SEGS (4)
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x90) 
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa (0xffffffff)
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaSHIFT (0)
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaCNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x90) 
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaCNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaACCESS (XLNX_RW)
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa4aaa (0x1)
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaCNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa (0xffffff)
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaCNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaSHIFT (0)
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x90) 
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa (0xffffffff)
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaSHIFT (0)
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaINPUT_OUTPUT_SPEC_aaaaaaaaaaaaaaaaaaaaaa1aaa (0x90) 
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaINPUT_OUTPUT_SPEC_ACCESS (XLNX_RW)
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaINPUT_OUTPUT_SPEC_MASK (0x1)
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaINPUT_OUTPUT_SPEC_SHIFT (0)
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaSEGMENT_ADDRESS_aaaaaaaaaaaaaaaaaaaaaa1aaa (0x90) 
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaSEGMENT_ADDRESS_ACCESS (XLNX_RW)
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaSEGMENT_ADDRESS_MASK (0x1f00)
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaSEGMENT_ADDRESS_SHIFT (8)
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaVIRTUAL_CONTAINER_aaaaaaaaaaaaaaaaaaaaaa1aaa (0x90) 
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaVIRTUAL_CONTAINER_ACCESS (XLNX_RW)
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaVIRTUAL_CONTAINER_MASK (0xff0000)
#define Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaVIRTUAL_CONTAINER_SHIFT (16)
#define Haa1aaaBCAM_BASE_CNF_VC_WRITE_DATA_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa (0x94) 
#define Haa1aaaBCAM_BASE_CNF_VC_WRITE_DATA_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaa (0xffffffff)
#define Haa1aaaBCAM_BASE_CNF_VC_WRITE_DATA_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaSHIFT (0)
#define Haa1aaaBCAM_BASE_CNF_VC_WRITE_DATA_CNF_VC_WRITE_DATA_aaaaaaaaaaaaaaaaaaaaaa1aaa (0x94) 
#define Haa1aaaBCAM_BASE_CNF_VC_WRITE_DATA_CNF_VC_WRITE_DATA_ACCESS (XLNX_RW)
#define Haa1aaaBCAM_BASE_CNF_VC_WRITE_DATA_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa4aaa (0x1)
#define Haa1aaaBCAM_BASE_CNF_VC_WRITE_DATA_CNF_VC_WRITE_DATA_MASK (0xffffffff)
#define Haa1aaaBCAM_BASE_CNF_VC_WRITE_DATA_CNF_VC_WRITE_DATA_SHIFT (0)
#endif
typedef struct vbcam
{
cam_config_t *conf;
uint16_t seg_map[CAM_MAX_SEGMENT_HASH_ENTRIES]; 
struct bcam* bcam_hdl[CAM_MAX_VC_SEGMENTS]; 
segment_ctx_t *segment_ctx[CAM_MAX_VC_SEGMENTS]; 
} vbcam;
static void setup_segment_table(vbcam *vbcam);
static void download_drambcam_segment_table(const vbcam *vbcam);
static void download_xram_segment_table(const vbcam *vbcam);
static void vbcam_xram_hw_read(const vbcam* vbcam, uint32_t address, uint64_t *data);
static void vbcam_xram_hw_write(const vbcam* vbcam, uint32_t address, uint64_t data);
static struct bcam* get_bcam_handle(const vbcam* vbcam, uint8_t hash_value[32]);
static bool is_segment_used(const vbcam* vbcam, uint16_t segment)
{
const uint8_t byte = segment / 8;
const uint8_t bit = segment % 8;
return (0 < (vbcam->conf->arg.vc_seg_map.bit_map[byte] & (1 << bit)));
}
static void setup_segment_table(vbcam* vbcam)
{
uint16_t num_segs = 0; 
uint32_t allocated_segs[CAM_MAX_VC_SEGMENTS]; 
for (uint32_t seg_count = 0; seg_count < CAM_MAX_VC_SEGMENTS; seg_count++)
{
if (is_segment_used(vbcam, seg_count))
{
allocated_segs[num_segs] = seg_count;
num_segs++;
}
}
uint32_t num = 0;
for (uint32_t hash_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount = 0; hash_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount < CAM_MAX_SEGMENT_HASH_ENTRIES; hash_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount++)
{
num = num % num_segs;
vbcam->seg_map[hash_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount] = allocated_segs[num];
num++;
}
}
static void download_drambcam_segment_table(const vbcam* vbcam)
{
uint32_t vc_id, u32Byte;
uint32_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaar = 0x00;
vc_id = vbcam->conf->arg.vc_seg_map.vcid << Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaVIRTUAL_CONTAINER_SHIFT;
u32Byte = vc_id | aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb3aaar | Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaWR;
cam_hw_write(vbcam->conf, Haa1aaaBCAM_BASE_CNF_VC_aaaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, u32Byte);
bool print = false;
const uint8_t MSG_SZ = 100;
char message[MSG_SZ];
if (vbcam->conf->arg.debug_flags & CAM_DEBUG_SEGMENTS) {
print = true;
       snprintf(message, MSG_SZ, "\nCAM_DEBUG_SEGEMENTS  vc_id = 0x%04" PRIX16 ", segment table = \n", vbcam->conf->arg.vc_seg_map.vcid);
vbcam->conf->arg.info_print_function(vbcam->conf->ctx, message);
}
for (uint16_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount = 0; aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount < CAM_MAX_SEGMENT_HASH_ENTRIES; aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount += Haa1aaaBCAM_BASE_CNF_VC_WRITE_NUM_SEGS)
{
u32Byte = ((vbcam->seg_map[aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount] << Haa1aaaBCAM_BASE_CNF_VC_WRITE_DATA_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaSHIFT_SEG_0)
| (vbcam->seg_map[aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount + 1] << Haa1aaaBCAM_BASE_CNF_VC_WRITE_DATA_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaSHIFT_SEG_1)
| (vbcam->seg_map[aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount + 2] << Haa1aaaBCAM_BASE_CNF_VC_WRITE_DATA_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaSHIFT_SEG_2)
| (vbcam->seg_map[aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount + 3] << Haa1aaaBCAM_BASE_CNF_VC_WRITE_DATA_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaSHIFT_SEG_3));
cam_hw_write(vbcam->conf, Haa1aaaBCAM_BASE_CNF_VC_WRITE_DATA_aaaaaaaaaaaaaaaaaaaaa1aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaaaaaaaaaaa1aaa, u32Byte);
if (print) {
           snprintf(message, MSG_SZ, "hash entry 0x%04" PRIX16 "-0x%04" PRIX16 " = 0x%04" PRIX16 ", 0x%04" PRIX16 ", "
           "0x%04" PRIX16 ", 0x%04" PRIX16, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount + 3, vbcam->seg_map[aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount],
vbcam->seg_map[aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount + 1], vbcam->seg_map[aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount + 2], vbcam->seg_map[aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount + 3]);
vbcam->conf->arg.info_print_function(vbcam->conf->ctx, message);
}
}
}
static void vbcam_xram_hw_read(const vbcam* vbcam, uint32_t address, uint64_t *data)
{
uint32_t lo_addr = address & aaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaR_MASK;
cam_hw_write(vbcam->conf, aaaaaa1aaaHA_BASE, address >> aaaaaa1bbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaR_aaaaaaaaaaaaaaaaaaaaaa1aaa);
uint32_t *data32 = (uint32_t *) data;
cam_hw_read(vbcam->conf, lo_addr, data32);
lo_addr = (address + 4) & aaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaR_MASK;
cam_hw_write(vbcam->conf, aaaaaa1aaaHA_BASE, address >> aaaaaa1bbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaR_aaaaaaaaaaaaaaaaaaaaaa1aaa);
data32++;
cam_hw_read(vbcam->conf, lo_addr, data32);
}
static void vbcam_xram_hw_write(const vbcam* vbcam, uint32_t address, uint64_t data)
{
cam_hw_write(vbcam->conf, aaaaaa1aaaHA_BASE, address >> aaaaaa1bbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaR_aaaaaaaaaaaaaaaaaaaaaa1aaa);
uint32_t hi_data = data >> 32;
cam_hw_write(vbcam->conf, aaaaaa1aaaHD_BASE, hi_data);
uint32_t lo_addr = address & aaaaaa1bbbbbbbbbbbbbbbbbbbbbb3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb4aaaR_MASK;
cam_hw_write(vbcam->conf, lo_addr, (uint32_t) data);
if (vbcam->conf->arg.debug_flags & CAM_DEBUG_VERIFY_WR) {
char message[500];
uint64_t read_data = 0;
vbcam_xram_hw_read(vbcam, address, &read_data);
if (read_data != data) {
           sprintf(message, "CAM_DEBUG_VERIFY_WR      address = 0x%08" PRIx32 "  data = 0x%016" PRIx64 "  expected data = 0x%016" PRIx64 "     FAIL",
address, read_data, data);
vbcam->conf->arg.error_print_function(vbcam->conf->ctx, message);
} else if (vbcam->conf->arg.debug_flags & CAM_DEBUG_VERBOSE_VERIFY) {
           sprintf(message, "CAM_DEBUG_VERIFY_WR      address = 0x%08" PRIx32 "  data = 0x%016" PRIx64 "  expected data = 0x%016" PRIx64 "     OK",
address, read_data, data);
vbcam->conf->arg.info_print_function(vbcam->conf->ctx, message);
}
}
}
static void download_xram_segment_table(const vbcam* vbcam)
{
uint32_t vcid;
vcid = vbcam->conf->arg.vc_seg_map.vcid;
bool print = false;
const uint8_t MSG_SZ = 100;
char message[MSG_SZ];
if (vbcam->conf->arg.debug_flags & CAM_DEBUG_SEGMENTS)
print = true;
uint32_t base_addr = aaaaaa1aaaSM_BASE + vcid * CAM_MAX_SEGMENT_HASH_ENTRIES;
for (uint16_t aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount = 0; aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount < CAM_MAX_SEGMENT_HASH_ENTRIES; aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount += 8) {
uint64_t data = 0;
for (int8_t i = 7; i >= 0; i--) {
data = data << 8;
data |= vbcam->seg_map[aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount + i];
if (print) {
               snprintf(message, MSG_SZ, "CAM_DEBUG_SEGEMENTS  vcid = 0x%02" PRIx32 "  segment_table[ 0x%02" PRIx16 " ] = 0x%02" PRIx16,
vcid, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount + 7 - i, vbcam->seg_map[aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount + 7 - i]);
vbcam->conf->arg.info_print_function(vbcam->conf->ctx, message);
}
}
vbcam_xram_hw_write(vbcam, base_addr + aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1aaacount, data);
}
}
static struct bcam* get_bcam_handle(const vbcam* vbcam, uint8_t hash_value[32])
{
uint16_t segment;
const int rc = vbcam_get_segment(vbcam, hash_value, &segment);
assert(rc == 0);
struct bcam* bcam_hdl = vbcam->bcam_hdl[segment];
assert(bcam_hdl != NULL);
return bcam_hdl;
}
int vbcam_create(const cam_arg_t* cam_arg, struct vbcam** out_vbcam)
{
NULL_CHECK(cam_arg);
NULL_CHECK(out_vbcam);
if (cam_arg->calc_heap_size)
return CAM_ERROR_INVALID_ARG;
uint16_t hdl_seg_create;
vbcam *new_vbcam = cam_arg->calloc_function(1, sizeof(vbcam)); 
if (new_vbcam == NULL)
{
return CAM_ERROR_MALLOC_FAILED;
}
cam_arg_t* cam_arg_bcam_hdl = alloca(cam_arg_size());
cam_arg_init(cam_arg_bcam_hdl);
cam_config_t *cam_conf;
cam_instance_type_t instance_type = BCAM;
if (cam_arg->hbm || cam_arg->ddr_dram)
instance_type = DRAMBCAM;
int rc = cam_config_create(cam_arg, instance_type, &cam_conf);
if (rc != CAM_OK)
{
cam_arg->free_function(new_vbcam);
return rc;
}
new_vbcam->conf = cam_conf;
const uint16_t num_units = cam_config_get_num_units(cam_conf);
setup_segment_table(new_vbcam);
*cam_arg_bcam_hdl = *cam_arg;
if (instance_type == DRAMBCAM) {
cam_arg_enable_options(cam_arg_bcam_hdl); 
uint32_t ram_size = cam_config_get_ram_size(cam_conf);
camp_arg_set_ram_size(cam_arg_bcam_hdl, (ram_size / CAM_MAX_VC_SEGMENTS)); 
download_drambcam_segment_table(new_vbcam);
} else {
const uint32_t num_lists = cam_config_get_num_lists(cam_conf);
const uint8_t num_slots = cam_config_get_num_slots(cam_conf);
const bool is_uram = cam_config_is_uram_instance(cam_conf);
cam_arg_force_mem_type(cam_arg_bcam_hdl, is_uram);
camp_arg_set_ram_size(cam_arg_bcam_hdl, ((num_lists * num_slots) / CAM_MAX_VC_SEGMENTS)); 
camp_arg_force_num_slots(cam_arg_bcam_hdl, num_slots);
download_xram_segment_table(new_vbcam);
}
cam_arg_set_num_entries(cam_arg_bcam_hdl, (cam_arg->num_entries / CAM_MAX_VC_SEGMENTS));
cam_arg_force_num_units(cam_arg_bcam_hdl, num_units);
uint32_t hdl_count = 0;
camp_arg_set_vcid(cam_arg_bcam_hdl, cam_arg_bcam_hdl->vc_seg_map.vcid);
cam_arg_bcam_hdl->vc_seg_map.vcid = -1;
for (hdl_seg_create = 0; hdl_seg_create < CAM_MAX_VC_SEGMENTS; hdl_seg_create++)
{
if (is_segment_used(new_vbcam, hdl_seg_create))
{
if (hdl_count > 0)
{
cam_arg_bcam_hdl->debug_flags |= CAM_DEBUG_SKIP_VERIFY_CONFIG;
cam_arg_bcam_hdl->debug_flags &= (CAM_DEBUG_CONFIG ^ UINT32_MAX);
}
hdl_count++;
camp_arg_set_seg(cam_arg_bcam_hdl, hdl_seg_create);
rc = bcam_create(cam_arg_bcam_hdl, &(new_vbcam->bcam_hdl[hdl_seg_create]));
if (rc != CAM_OK)
{
cam_arg->free_function(new_vbcam->segment_ctx[hdl_seg_create]);
goto vc_cleanup;
}
}
}
*out_vbcam = new_vbcam;
return CAM_OK;
vc_cleanup:
for (uint16_t hdl_seg_destroy = 0; hdl_seg_destroy < hdl_seg_create; hdl_seg_destroy++)
{
if (is_segment_used(new_vbcam, hdl_seg_destroy))
{
if (new_vbcam->bcam_hdl[hdl_seg_destroy] != NULL)
{
bcam_destroy(new_vbcam->bcam_hdl[hdl_seg_destroy]);
cam_arg->free_function(new_vbcam->segment_ctx[hdl_seg_destroy]);
}
}
}
cam_arg->free_function(cam_conf);
cam_arg->free_function(new_vbcam);
return rc;
}
int vbcam_destroy(struct vbcam* vbcam)
{
NULL_CHECK(vbcam);
int return_rc = CAM_OK;
for (uint32_t segment = 0; segment < CAM_MAX_VC_SEGMENTS; segment++)
{
if (is_segment_used(vbcam, segment))
{
if (vbcam->bcam_hdl[segment] != NULL)
{
int rc = bcam_destroy(vbcam->bcam_hdl[segment]);
if (rc)
return_rc = rc;
vbcam->conf->arg.free_function(vbcam->segment_ctx[segment]);
}
}
}
cam_free_func free_function = vbcam->conf->arg.free_function;
cam_config_destroy(vbcam->conf);
free_function(vbcam);
return return_rc;
}
static int check_options(const struct vbcam* vbcam, const cam_options_t *options)
{
if ((vbcam->conf->instance_type != DRAMBCAM) && (options->narrow == true))
return CAM_ERROR_INVALID_ARG;
else
return 0;
}
#define OPTION_PROCESSING \
if (options == NULL) { \
cam_options_init(&new_options); \
} \
else { \
rc = check_options(vbcam, options); \
if (rc) \
return rc; \
new_options = *options; \
} \
if (!new_options.precomp_hash) { \
uint8_t hash_value[32]; \
vbcam_compute_hash_value(vbcam, key, hash_value, &new_options); \
cam_options_set_precomputed_hash_value(&new_options, hash_value); \
}
int vbcam_insert(struct vbcam* vbcam, const uint8_t key[], const uint8_t response[], const cam_options_t *options)
{
NULL_CHECK(vbcam);
NULL_CHECK(key);
int rc;
cam_options_t new_options;
OPTION_PROCESSING;
struct bcam *bcam_hdl = get_bcam_handle(vbcam, (uint8_t *) &(new_options.hash_value));
if (vbcam->conf->instance_type == DRAMBCAM)
rc = bcam_insert(bcam_hdl, key, response, &new_options);
else
rc = bcam_insert(bcam_hdl, key, response);
return rc;
}
int vbcam_compute_hash_value(const struct vbcam* vbcam, const uint8_t key[], uint8_t hash_value[32],
const cam_options_t *options)
{
NULL_CHECK(vbcam);
NULL_CHECK(key);
NULL_CHECK(hash_value);
int rc;
cam_options_t new_options;
if (options == NULL) {
cam_options_init(&new_options);
} else {
rc = check_options(vbcam, options);
if (rc)
return rc;
new_options = *options;
}
aaaaaaaaaaaaa1aaat new_key;
memset(&new_key, 0, sizeof(aaaaaaaaaaaaa1aaat));
uint16_t key_width;
if (new_options.narrow)
key_width = vbcam->conf->arg.narrow_key_width;
else
key_width = vbcam->conf->arg.key_width;
cam_copy_bits((uint8_t *) &new_key.word[0], key, key_width);
const uint16_t num_bytes = (key_width + 7) / 8;
memset(hash_value, 0, 32);
if (vbcam->conf->instance_type == DRAMBCAM) {
if (vbcam->conf->arg.hash_function == 0) {
murmur3((const void*) &new_key.word[0], num_bytes, 3, (uint32_t *) hash_value);
} else {
const uint8_t cROUNDS = vbcam->conf->arg.hash_function >> 4;
const uint8_t dROUNDS = vbcam->conf->arg.hash_function & 0xf;
*hash_value = siphash((const uint8_t *) &new_key.word[0], num_bytes,
vbcam->conf->arg.hash_k0, vbcam->conf->arg.hash_k1,
cROUNDS, dROUNDS);
}
} else {
assert(new_options.narrow == false);
hash_t *hash = (hash_t *) alloca(hash_size());
const uint16_t seed = 0xffff;
const uint32_t num_lists = (1 << (CAM_MAX_SEGMENT_HASH_ENTRIES_WIDTH)) / aaaaaa1aaaaaaaaaabaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa3aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa4aaaaaaaaaaaaabaaaaaaaaaaaaaaaaa5aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa5aaaRATIO;
const uint8_t num_slots = 1;
hash_raw_init(hash, &new_key, seed, key_width, num_lists, num_slots);
*((uint32_t *) hash_value) = hash_calculate_bucket(hash);
}
return 0;
}
#if(CAM_MAX_SEGMENT_HASH_ENTRIES_WIDTH != 8)
#error "CAM_MAX_SEGMENT_HASH_ENTRIES_WIDTH != 8"
#endif
int vbcam_get_segment(const struct vbcam* vbcam, const uint8_t hash_value[32], uint16_t* segment)
{
NULL_CHECK(vbcam);
NULL_CHECK(hash_value);
NULL_CHECK(segment);
uint32_t segment_hash_entry;
if (vbcam->conf->instance_type == DRAMBCAM) {
segment_hash_entry = hash_value[0] ^ hash_value[1] ^ hash_value[2] ^ hash_value[3];
} else {
segment_hash_entry = hash_value[0];
}
*segment = vbcam->seg_map[segment_hash_entry]; 
return 0;
}
int vbcam_update(struct vbcam* vbcam, const uint8_t key[], const uint8_t response[], const cam_options_t *options)
{
NULL_CHECK(vbcam);
NULL_CHECK(key);
int rc;
cam_options_t new_options;
OPTION_PROCESSING;
struct bcam *bcam_hdl = get_bcam_handle(vbcam, (uint8_t *) &(new_options.hash_value));
if (vbcam->conf->instance_type == DRAMBCAM)
rc = bcam_update(bcam_hdl, key, response, &new_options);
else
rc = bcam_update(bcam_hdl, key, response);
return rc;
}
#if(CAM_MAX_VC_SEGMENTS>256)
#error "CAM_MAX_VC_SEGMENTS > 256"
#endif
int vbcam_get_by_response(struct vbcam* vbcam, const uint8_t response[], const uint8_t response_mask[], uint32_t* pos,
uint8_t out_key[], const cam_options_t *options)
{
NULL_CHECK(vbcam);
int rc;
cam_options_t new_options;
if (options == NULL) {
cam_options_init(&new_options);
} else {
rc = check_options(vbcam, options);
if (rc)
return rc;
new_options = *options;
}
uint32_t start_seg_num;
uint32_t end_seg_num;
if (new_options.search_single_segment) {
start_seg_num = new_options.single_segment;
end_seg_num = start_seg_num;
} else {
start_seg_num = ((*pos) >> 16) & 0x000000ff;
end_seg_num = (CAM_MAX_VC_SEGMENTS - 1);
}
uint32_t new_pos = *pos & 0xff00ffff;
rc = CAM_ERROR_KEY_NOT_FOUND;
struct bcam* bcam_hdl;
const uint32_t debug_flags = vbcam->conf->arg.debug_flags;
const uint32_t debug_flags_no_error_msg = debug_flags | CAM_DEBUG_NO_ERROR_MSG;
for (uint16_t seg_num = start_seg_num; seg_num <= end_seg_num; seg_num++) {
if (is_segment_used(vbcam, seg_num)) {
bcam_hdl = vbcam->bcam_hdl[seg_num];
client_set_debug_flags((client_t *) bcam_hdl, debug_flags_no_error_msg);
rc = bcam_get_by_response(bcam_hdl, response, response_mask, &new_pos, out_key, &new_options);
client_set_debug_flags((client_t *) bcam_hdl, debug_flags);
if (rc == CAM_ERROR_KEY_NOT_FOUND) {
new_pos = 0; 
continue;
} else if ((rc == 0) || (rc == CAM_ERROR_FOUND_IN_SHADOW_BUT_NOT_IN_HW)) {
*pos = (seg_num << 16) | (new_pos & 0xff00ffff);
}
break;
}
}
if (rc && !(debug_flags & CAM_DEBUG_NO_ERROR_MSG)) {
if (rc != CAM_ERROR_KEY_NOT_FOUND)
cam_print_error(rc);
}
return rc;
}
int vbcam_delete_all(struct vbcam* vbcam, const cam_options_t *options) {
NULL_CHECK(vbcam);
int rc = 0;
cam_options_t new_options;
if (options == NULL) {
cam_options_init(&new_options);
} else {
rc = check_options(vbcam, options);
if (rc)
return rc;
new_options = *options;
}
uint32_t start_seg_num;
uint32_t end_seg_num;
if (new_options.search_single_segment) {
start_seg_num = new_options.single_segment;
end_seg_num = start_seg_num;
} else {
start_seg_num = 0;
end_seg_num = (CAM_MAX_VC_SEGMENTS - 1);
}
struct bcam* bcam_hdl;
for (uint16_t seg_num = start_seg_num; seg_num <= end_seg_num; seg_num++) {
if (is_segment_used(vbcam, seg_num)) {
bcam_hdl = vbcam->bcam_hdl[seg_num];
rc = bcam_delete_all(bcam_hdl, &new_options);
if (rc)
break;
}
}
return rc;
}
int vbcam_get_by_key(struct vbcam* vbcam, const uint8_t key[], uint8_t response[], const cam_options_t *options)
{
NULL_CHECK(vbcam);
NULL_CHECK(key);
int rc;
cam_options_t new_options;
OPTION_PROCESSING;
struct bcam *bcam_hdl = get_bcam_handle(vbcam, (uint8_t *) &(new_options.hash_value));
if (vbcam->conf->instance_type == DRAMBCAM)
rc = bcam_get_by_key(bcam_hdl, key, response, &new_options);
else
rc = bcam_get_by_key(bcam_hdl, key, response);
return rc;
}
int vbcam_delete(struct vbcam* vbcam, const uint8_t key[], const cam_options_t *options)
{
NULL_CHECK(vbcam);
NULL_CHECK(key);
int rc;
cam_options_t new_options;
OPTION_PROCESSING;
struct bcam *bcam_hdl = get_bcam_handle(vbcam, (uint8_t *) &(new_options.hash_value));
if (vbcam->conf->instance_type == DRAMBCAM)
rc = bcam_delete(bcam_hdl, key, &new_options);
else
rc = bcam_delete(bcam_hdl, key);
return rc;
}
int vbcam_read_and_clear_ecc_counters(struct vbcam* vbcam, uint32_t* corrected_single_bit_errors,
uint32_t* detected_double_bit_errors)
{
NULL_CHECK(vbcam);
for (uint16_t seg = 0; seg < CAM_MAX_VC_SEGMENTS; seg++) {
if (is_segment_used(vbcam, seg)) {
return bcam_read_and_clear_ecc_counters(vbcam->bcam_hdl[seg], corrected_single_bit_errors,
detected_double_bit_errors);
}
}
assert(false);
return 0;
}
int vbcam_read_and_clear_ecc_addresses(struct vbcam* vbcam, uint32_t* failing_address_single_bit_error,
uint32_t* failing_address_double_bit_error)
{
NULL_CHECK(vbcam);
for (uint16_t seg = 0; seg < CAM_MAX_VC_SEGMENTS; seg++) {
if (is_segment_used(vbcam, seg)) {
return bcam_read_and_clear_ecc_addresses(vbcam->bcam_hdl[seg], failing_address_single_bit_error,
failing_address_double_bit_error);
}
}
assert(false);
return 0;
}
int vbcam_set_ecc_test(struct vbcam* vbcam, bool inject_single_bit_errors,
bool inject_double_bit_errors)
{
NULL_CHECK(vbcam);
for (uint16_t seg = 0; seg < CAM_MAX_VC_SEGMENTS; seg++) {
if (is_segment_used(vbcam, seg)) {
return bcam_set_ecc_test(vbcam->bcam_hdl[seg], inject_single_bit_errors,
inject_double_bit_errors);
}
}
assert(false);
return 0;
}
