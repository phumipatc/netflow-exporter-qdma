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
//       Description: Declarations of the software API for Verilog DPI simulation
//                    Further information on the software functions are available in the software header files:
//                    sw/cam_src/inc/cam.h
//                    sw/cam_src/inc/bcam.h
//                    sw/cam_src/inc/vbcam.h
//                    sw/cam_src/inc/tcam.h
//                    sw/cam_src/inc/stcam.h
//                    sw/comp_bcam/inc/ccam.h
//                    sw/comp_bcam/inc/cbcam.h
//                    sw/comp_bcam/inc/cstcam.h
//
//////////////////////////////////////////////////////////////////////////////


`ifndef cam_DPI_PKG
`define cam_DPI_PKG

package cam_dpi_pkg;

`ifndef SYNTHESIS

// CAM API
// The functions are described in the file cam.h
import "DPI-C" context function int  cam_arg_create(inout chandle out_cam_arg);

import "DPI-C" context function void cam_arg_init(inout chandle out_cam_arg);

import "DPI-C" context function void cam_arg_destroy(chandle cam_arg);

import "DPI-C" context function int  cam_arg_set_format(chandle cam_arg, string format);

import "DPI-C" context function void cam_arg_set_inst_ctx(chandle cam_arg, chandle inst_ctx);

import "DPI-C" context function void cam_arg_set_hw_write_function(chandle cam_arg,
                                                                   chandle hw_write_function);

import "DPI-C" context function void cam_arg_set_hw_read_function(chandle cam_arg,
                                                                  chandle hw_read_function);

import "DPI-C" context function void cam_arg_set_num_entries(chandle cam_arg,
                                                             int unsigned num_entries);

import "DPI-C" context function void cam_arg_set_engine_lookup_rate_hz(chandle cam_arg,
                                                                       int unsigned lookup_rate_hz);

import "DPI-C" context function void cam_arg_set_num_banks(chandle cam_arg,
                                                                       int unsigned num_banks);

import "DPI-C" context function void cam_arg_set_lookup_interface_freq_hz(chandle cam_arg,
                                                                          int unsigned freq_hz);

import "DPI-C" context function void cam_arg_set_ram_freq_hz(chandle cam_arg, int unsigned freq_hz);

import "DPI-C" context function void cam_arg_set_response_width(chandle cam_arg,
                                                                shortint unsigned response_width);

import "DPI-C" context function void cam_arg_force_prio_width(chandle cam_arg, byte prio);

import "DPI-C" context function void cam_arg_set_key_width(chandle cam_arg,
                                                           shortint unsigned key_width);

import "DPI-C" context function void cam_arg_set_num_masks(chandle cam_arg, byte num_masks);

import "DPI-C" context function void cam_arg_force_num_units(chandle cam_arg,
                                                             shortint unsigned num_units);

import "DPI-C" context function void cam_arg_force_mem_type(chandle cam_arg, int uram);

import "DPI-C" context function void cam_arg_force_hbm(chandle cam_arg);

import "DPI-C" context function void cam_arg_force_dram(chandle cam_arg);

import "DPI-C" context function void cam_arg_force_asic_ram(chandle cam_arg);

import "DPI-C" context function void cam_arg_set_ram_size(chandle cam_arg, int unsigned size);

import "DPI-C" context function void cam_arg_set_max_macro_height(chandle cam_arg, byte max_macro_height);

import "DPI-C" context function void cam_arg_set_device_arch(chandle cam_arg, int versal);

import "DPI-C" context function void cam_arg_set_channel_width(chandle cam_arg, shortint unsigned width);

import "DPI-C" context function void cam_arg_set_narrow_key_width(chandle cam_arg,
                                                                  shortint unsigned narrow_key_width);

import "DPI-C" context function void cam_arg_set_max_hw_writes(chandle cam_arg,
                                                               shortint unsigned max_hw_writes);

import "DPI-C" context function void cam_arg_set_flow_control(chandle cam_arg, int flow_control);

import "DPI-C" context function void cam_arg_set_default_response(chandle cam_arg,
                                                                  chandle default_response);

import "DPI-C" context function void cam_arg_set_narrow_default_response(chandle cam_arg,
                                                                         chandle narrow_default_response);

import "DPI-C" context function void cam_arg_set_vcid(chandle cam_arg, byte vcid);

import "DPI-C" context function void cam_arg_set_seg(chandle cam_arg, shortint unsigned segment_id);

import "DPI-C" context function void cam_arg_set_hw_write_sequence_functions(chandle cam_arg,
                                                                             chandle start_function,
                                                                             chandle end_function);

import "DPI-C" context function void cam_arg_set_debug_flags(chandle cam_arg,
                                                             int unsigned debug_flags);

import "DPI-C" context function void cam_arg_set_optimization_flags(chandle cam_arg,
                                                                    int unsigned optimization_flags);

import "DPI-C" context function void cam_arg_enable_options(chandle cam_arg);

import "DPI-C" context function void cam_arg_set_error_print_function(chandle cam_arg,
                                                                      chandle error_print_function);

import "DPI-C" context function void cam_arg_set_info_print_function(chandle cam_arg,
                                                                     chandle info_print_function);

import "DPI-C" context function void cam_arg_set_malloc_function(chandle cam_arg,
                                                                 chandle malloc_function);

import "DPI-C" context function void cam_arg_set_calloc_function(chandle cam_arg,
                                                                 chandle calloc_function);

import "DPI-C" context function void cam_arg_set_free_function(chandle cam_arg,
                                                               chandle free_function);

import "DPI-C" context function void cam_arg_set_fingerprint_width(chandle cam_arg,
                                                                   shortint unsigned fingerprint_width);

import "DPI-C" context function void cam_arg_set_hash_function(chandle cam_arg,
                                                               byte hash_function);

import "DPI-C" context function void cam_arg_set_siphash_key(chandle cam_arg,
                                                             longint unsigned k0,
                                                             longint unsigned k1);

import "DPI-C" context function void cam_arg_set_generation_number_granularity(chandle cam_arg,
                                                                               shortint unsigned granularity);

import "DPI-C" context function void cam_arg_set_update_mode(chandle cam_arg, int update_mode);

import "DPI-C" context function string cam_error_string(int error_code);

import "DPI-C" context function void cam_print_error(int error_code);

import "DPI-C" context function int cam_options_create(inout chandle out_cam_options);

import "DPI-C" context function int unsigned cam_options_size();

import "DPI-C" context function void cam_options_init(inout chandle out_options);

import "DPI-C" context function void cam_options_destroy(chandle cam_options);

import "DPI-C" context function void cam_options_set_narrow_key(chandle cam_options, int narrow);

import "DPI-C" context function void cam_options_set_precomputed_hash_value(chandle cam_options,
                                                                            chandle hash_value);

import "DPI-C" context function void cam_options_clear_precomputed_hash_value(chandle cam_options);


// Min/max limits
localparam int CAM_MIN_KEY_WIDTH      = 10;
localparam int CAM_MAX_KEY_WIDTH      = 992;
localparam int CAM_MIN_RESPONSE_WIDTH = 1;
localparam int CAM_MAX_RESPONSE_WIDTH = 1024;

typedef struct {
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
    byte         key [(CAM_MAX_KEY_WIDTH + 7) / 8]; // The last lookup key
    byte         response [(CAM_MAX_RESPONSE_WIDTH + 7) / 8];
    int unsigned status; // Bit 0: Match, Bit 1: Double bit error
} cam_last_lookup_t;

typedef struct {
    int      unsigned num_entries;        // only used for bcam and stcam, this is the total
    int      unsigned narrow_num_entries; // Only used in mixed mode. The number of entries which are narrow.
                                          // The following equation is always true: wide entries + narrow entries = num_entries
    longint  unsigned num_inserts;        // bcam/stcam statistics
    longint  unsigned num_updates;        // bcam/stcam statistics
    longint  unsigned num_deletes;        // bcam/stcam statistics
    int      unsigned failed_inserts;     // bcam/stcam statistics
    int      unsigned failed_updates;     // bcam/stcam statistics
    int      unsigned failed_deletes;     // bcam/stcam statistics
    longint  unsigned num_collisions;     // bcam/stcam statistics
    shortint unsigned max_collisions;     // bcam/stcam statistics
    byte              num_used_masks;     // Only for stcam
    longint  unsigned num_shadow_writes;  // bcam/stcam statistics
} cam_sw_stats_t;



// CCAM API
localparam int CCAM_SW   = 0;
localparam int CCAM_RATE = 1;

// The structs are described in the file ccam.h
typedef struct {
                chandle      ctx;
                chandle      hw_write_function;
                chandle      hw_read_function;
                chandle      error_print_function;
                chandle      info_print_function;
                int unsigned debug_flags;
                int unsigned optimization_flags;
                } ccam_arg_t;

typedef struct {
                int     unsigned num_entries;    // Counter to record the current number of entries
                longint unsigned num_inserts;
                longint unsigned failed_inserts;
                longint unsigned num_updates;
                longint unsigned failed_updates;
                longint unsigned num_deletes;
                longint unsigned failed_deletes;
                longint unsigned poll_count;     // Total number of times the CPU read from HW and got BUSY
                int     unsigned num_masks;      // Counter to record the current number of masks. (always zero for cbcam)
} ccam_stats_t;

typedef struct {
                int     unsigned num_entries;    // Counter to record the current number of entries
                longint unsigned num_inserts;
                longint unsigned failed_inserts;
                longint unsigned num_updates;
                longint unsigned failed_updates;
                longint unsigned num_deletes;
                longint unsigned failed_deletes;
                longint unsigned poll_count;     // Total number of times the CPU read from HW and got BUSY
                int     unsigned num_masks;      // Counter to record the current number of masks. (always zero for cbcam)
} ccam_sw_stats_t;

typedef struct {
                int unsigned inserts;
                int unsigned lookup_request_wait_states;
                int unsigned lookups;
                int unsigned hits;
                int unsigned external_events;
} ccam_rate_counters_t;


// The functions are described in the file ccam.h
import "DPI-C" context task ccam_read_and_clear_ecc_counters(chandle ccam,
                                                             chandle corrected_single_bit_errors,
                                                             chandle detected_double_bit_errors);

import "DPI-C" context task ccam_read_and_clear_ecc_addresses(chandle ccam,
                                                              chandle failing_address_single_bit_error,
                                                              chandle failing_address_double_bit_error);

import "DPI-C" context task ccam_set_ecc_test(chandle ccam,
                                              int inject_single_bit_errors,
                                              int inject_double_bit_errors);

import "DPI-C" context task ccam_get_stats(chandle ccam, int stats_group, ccam_stats_t stats);

import "DPI-C" context task ccam_get_stats_sw_dpi(chandle ccam, inout ccam_sw_stats_t sw_stats,
                                                  inout int status);

import "DPI-C" context task ccam_get_stats_rate_dpi(chandle ccam, inout ccam_rate_counters_t rate_counters,
                                                    inout int status);

import "DPI-C" context task ccam_get_stats_last_lookup_dpi(chandle ccam, inout cam_last_lookup_t last_lookup,
                                                           inout int status);



// BCAM API
// The functions are described in the file bcam.h
typedef struct {
    // All three counters should be read from the same sample number otherwise read again
    int unsigned axis_ws; // Wait states on AXIS, the 6 msb bits is the sample number
    int unsigned reads;   // Total number of 64B dram reads since sample, the 6 msb bits is the sample number
    int unsigned writes;  // Total number of 64B dram writes since sample, the 6 msb bits is the sample number
    int unsigned lookup_responses; // Total lookup responses, the 6 msb bits is the sample number
} cam_dram_rate_t;

typedef struct {
    int unsigned outstanding_reads; // The current number of outstanding dram reads
    int unsigned last_latency;      // The dram read latency of the last dram read
} cam_dram_snapshot_t;


import "DPI-C" context task bcam_create(chandle cam_arg, inout chandle out_bcam);
import "DPI-C" context task bcam_create_dpi(chandle cam_arg, inout chandle out_bcam, inout int status);

import "DPI-C" context task bcam_destroy(chandle bcam);
import "DPI-C" context task bcam_destroy_dpi(chandle bcam, inout int status);

import "DPI-C" context task bcam_insert(chandle bcam, chandle key, chandle response, chandle options);
import "DPI-C" context task bcam_insert_dpi(chandle bcam, chandle key, chandle response, chandle options,
                                            inout int status);

import "DPI-C" context task bcam_update(chandle bcam, chandle key, chandle response, chandle options);
import "DPI-C" context task bcam_update_dpi(chandle bcam, chandle key, chandle response, chandle options,
                                            inout int status);

import "DPI-C" context task bcam_delete(chandle bcam, chandle key, chandle options);
import "DPI-C" context task bcam_delete_dpi(chandle bcam, chandle key, chandle options, inout int status);
import "DPI-C" context task bcam_delete_all_dpi(chandle bcam, chandle options, inout int status);

import "DPI-C" context task bcam_get_by_key(chandle bcam, chandle key, chandle response, chandle options);
import "DPI-C" context task bcam_get_by_key_dpi(chandle bcam, chandle key, chandle response, chandle options,
                                                inout int status);

import "DPI-C" context task bcam_get_by_response(chandle bcam, chandle response, chandle response_mask,
                                                 chandle pos, chandle out_key, chandle options);
import "DPI-C" context task bcam_get_by_response_dpi(chandle bcam, chandle response,
                                                     chandle response_mask, chandle pos,
                                                     chandle out_key, chandle options, inout int status);

import "DPI-C" context task bcam_read_and_clear_ecc_counters(chandle bcam,
                                                             chandle corrected_single_bit_errors,
                                                             chandle detected_double_bit_errors);

import "DPI-C" context task bcam_read_and_clear_ecc_addresses(chandle bcam,
                                                              chandle failing_address_single_bit_error,
                                                              chandle failing_address_double_bit_error);

import "DPI-C" context task bcam_set_ecc_test(chandle bcam,
                                              int inject_single_bit_errors,
                                              int inject_double_bit_errors);

import "DPI-C" context task bcam_get_stats_last_lookup_dpi(chandle bcam, inout cam_last_lookup_t last_lookup,
                                                           inout int status);

import "DPI-C" context task bcam_get_stats_dram_rate_dpi(chandle bcam, inout cam_dram_rate_t dram_rate,
                                                         inout int status);

import "DPI-C" context task bcam_get_stats_dram_snapshot_dpi(chandle bcam,
                                                             inout cam_dram_snapshot_t dram_snapshot,
                                                             inout int status);
import "DPI-C" context task bcam_get_stats_sw_dpi(chandle bcam, inout cam_sw_stats_t sw_stats, inout int status);



// VBCAM API
// The functions are described in the file vbcam.h
import "DPI-C" context task vbcam_create(chandle cam_arg, inout chandle out_vbcam);
import "DPI-C" context task vbcam_create_dpi(chandle cam_arg, inout chandle out_vbcam, inout int status);

import "DPI-C" context task vbcam_insert(chandle vbcam, chandle key, chandle response, chandle options);
import "DPI-C" context task vbcam_insert_dpi(chandle vbcam, chandle key, chandle response, chandle options,
                                             inout int status);

import "DPI-C" context task vbcam_update(chandle vbcam, chandle key, chandle response, chandle options);
import "DPI-C" context task vbcam_update_dpi(chandle vbcam, chandle key, chandle response, chandle options,
                                             inout int status);

import "DPI-C" context task vbcam_get_by_response(chandle vbcam, chandle response, chandle response_mask,
                                                  chandle pos, chandle out_key, chandle options);
import "DPI-C" context task vbcam_get_by_response_dpi(chandle vbcam, chandle response, chandle response_mask,
                                                      chandle pos, chandle out_key, chandle options,
                                                      inout int status);

import "DPI-C" context task vbcam_get_by_key(chandle vbcam, chandle key, chandle response, chandle options);
import "DPI-C" context task vbcam_get_by_key_dpi(chandle vbcam, chandle key, chandle response, chandle options,
                                                 inout int status);

import "DPI-C" context task vbcam_delete(chandle vbcam, chandle key, chandle options);
import "DPI-C" context task vbcam_delete_dpi(chandle vbcam, chandle key, chandle options, inout int status);

import "DPI-C" context task vbcam_delete_all_dpi(chandle vbcam, chandle options, inout int status);

import "DPI-C" context function int vbcam_compute_hash_value(chandle vbcam, chandle key,
                                                             chandle hash_value, chandle options);

import "DPI-C" context function int vbcam_get_segment(chandle vbcam, chandle hash_value,
                                                      inout shortint unsigned segment);

import "DPI-C" context task vbcam_destroy(chandle vbcam);
import "DPI-C" context task vbcam_destroy_dpi(chandle vbcam, inout int status);

import "DPI-C" context task vbcam_read_and_clear_ecc_counters(chandle vbcam,
                                                              chandle corrected_single_bit_errors,
                                                              chandle detected_double_bit_errors);
import "DPI-C" context task vbcam_read_and_clear_ecc_addresses(chandle vbcam,
                                                               chandle failing_address_single_bit_error,
                                                               chandle failing_address_double_bit_error);
import "DPI-C" context task vbcam_set_ecc_test(chandle vbcam,
                                               int inject_single_bit_errors,
                                               int inject_double_bit_errors);

import "DPI-C" context function void cam_options_set_single_segment_search(chandle cam_options, int narrow);




// CBCAM API
// The functions are described in the file cbcam.h
import "DPI-C" context function longint unsigned cbcam_size();

import "DPI-C" context task cbcam_create_dpi(ccam_arg_t ccam_arg, inout chandle out_cbcam, inout int status);

import "DPI-C" context function void cbcam_destroy_dpi(chandle cbcam);

import "DPI-C" context task cbcam_init_dpi(ccam_arg_t ccam_arg, inout chandle out_cbcam, inout int status);

import "DPI-C" context task cbcam_insert_dpi(chandle cbcam, chandle key, chandle response, inout int status);

import "DPI-C" context task cbcam_update_dpi(chandle cbcam, chandle key, chandle response, inout int status);

import "DPI-C" context task cbcam_delete_dpi(chandle cbcam, chandle key, inout int status);

import "DPI-C" context task cbcam_delete_all_dpi(chandle cbcam, inout int status);

import "DPI-C" context task cbcam_get_by_key_dpi(chandle cbcam, chandle key, chandle response, inout int status);

import "DPI-C" context task cbcam_get_by_response_dpi(chandle cbcam, chandle in_response, chandle response_mask,
                                                      chandle pos, chandle out_key, chandle out_response, inout int status);



// TCAM API
// The functions are described in the file tcam.h
import "DPI-C" context task tcam_create(chandle cam_arg, inout chandle out_tcam);
import "DPI-C" context task tcam_create_dpi(chandle cam_arg, inout chandle out_tcam, inout int status);

import "DPI-C" context task tcam_destroy(chandle tcam);
import "DPI-C" context task tcam_destroy_dpi(chandle tcam, inout int status);

import "DPI-C" context task tcam_insert(chandle tcam, chandle key, chandle mask,
                                        int unsigned prio, chandle response);
import "DPI-C" context task tcam_insert_dpi(chandle tcam, chandle key, chandle mask,
                                            int unsigned prio, chandle response, inout int status);

import "DPI-C" context task tcam_update(chandle tcam, chandle key, chandle mask, chandle response);
import "DPI-C" context task tcam_update_dpi(chandle tcam, chandle key, chandle mask, chandle response,
                                            inout int status);

import "DPI-C" context task tcam_delete(chandle tcam, chandle key, chandle mask);
import "DPI-C" context task tcam_delete_dpi(chandle tcam, chandle key, chandle mask, inout int status);
import "DPI-C" context task tcam_delete_all_dpi(chandle tcam, inout int status);

import "DPI-C" context function int tcam_lookup(chandle tcam, chandle key, chandle response);
import "DPI-C" context task tcam_lookup_dpi(chandle tcam, chandle key, chandle response,
                                            inout int status);

import "DPI-C" context task tcam_get_by_key(chandle tcam, chandle key, chandle mask,
                                            chandle prio, chandle response);
import "DPI-C" context task tcam_get_by_key_dpi(chandle tcam, chandle key, chandle mask,
                                                chandle prio, chandle response, inout int status);

import "DPI-C" context task tcam_get_by_response(chandle tcam, chandle response,
                                                 chandle response_mask, chandle pos,
                                                 chandle out_key, chandle out_mask);
import "DPI-C" context task tcam_get_by_response_dpi(chandle tcam, chandle response,
                                                     chandle response_mask, chandle pos,
                                                     chandle out_key, chandle out_mask,
                                                     inout int status);

import "DPI-C" context task tcam_read_and_clear_ecc_counters(chandle tcam,
                                                             chandle corrected_single_bit_errors,
                                                             chandle detected_double_bit_errors);

import "DPI-C" context task tcam_read_and_clear_ecc_addresses(chandle tcam,
                                                              chandle failing_address_single_bit_error,
                                                              chandle failing_address_double_bit_error);

import "DPI-C" context task tcam_set_ecc_test(chandle tcam,
                                              int inject_single_bit_errors,
                                              int inject_double_bit_errors);

import "DPI-C" context task tcam_get_stats_last_lookup_dpi(chandle tcam, inout cam_last_lookup_t last_lookup,
                                                           inout int status);

import "DPI-C" context task tcam_get_stats_sw_dpi(chandle tcam, inout cam_sw_stats_t sw_stats, inout int status);



// STCAM API
// The functions are described in the file stcam.h
import "DPI-C" context task stcam_create(chandle cam_arg, inout chandle out_stcam);
import "DPI-C" context task stcam_create_dpi(chandle cam_arg, inout chandle out_stcam, inout int status);

import "DPI-C" context function void stcam_destroy(chandle stcam);

import "DPI-C" context task stcam_insert(chandle stcam, chandle key, chandle mask,
                                         int unsigned prio, chandle response);
import "DPI-C" context task stcam_insert_dpi(chandle stcam, chandle key, chandle mask,
                                             int unsigned prio, chandle response, inout int status);

import "DPI-C" context task stcam_update(chandle stcam, chandle key, chandle mask, chandle response);
import "DPI-C" context task stcam_update_dpi(chandle stcam, chandle key, chandle mask, chandle response,
                                             inout int status);

import "DPI-C" context task stcam_delete(chandle stcam, chandle key, chandle mask);
import "DPI-C" context task stcam_delete_dpi(chandle stcam, chandle key, chandle mask, inout int status);
import "DPI-C" context task stcam_delete_all_dpi(chandle stcam, inout int status);

import "DPI-C" context function int stcam_lookup(chandle stcam, chandle key, chandle response);
import "DPI-C" context task stcam_lookup_dpi(chandle stcam, chandle key, chandle response,
                                             inout int status);

import "DPI-C" context task stcam_get_by_key(chandle stcam, chandle key, chandle mask,
                                             chandle prio, chandle response);
import "DPI-C" context task stcam_get_by_key_dpi(chandle stcam, chandle key, chandle mask,
                                                 chandle prio, chandle response, inout int status);

import "DPI-C" context task stcam_get_by_response(chandle stcam, chandle response,
                                                  chandle response_mask, chandle pos,
                                                  chandle out_key, chandle out_mask);
import "DPI-C" context task stcam_get_by_response_dpi(chandle stcam, chandle response,
                                                      chandle response_mask, chandle pos,
                                                      chandle out_key, chandle out_mask,
                                                      inout int status);

import "DPI-C" context task stcam_read_and_clear_ecc_counters(chandle stcam,
                                                              chandle corrected_single_bit_errors,
                                                              chandle detected_double_bit_errors);

import "DPI-C" context task stcam_read_and_clear_ecc_addresses(chandle stcam,
                                                               chandle failing_address_single_bit_error,
                                                               chandle failing_address_double_bit_error);
import "DPI-C" context task stcam_set_ecc_test(chandle stcam,
                                               int inject_single_bit_errors,
                                               int inject_double_bit_errors);

import "DPI-C" context task stcam_get_stats_last_lookup_dpi(chandle stcam, inout cam_last_lookup_t last_lookup,
                                                           inout int status);

import "DPI-C" context task stcam_get_stats_sw_dpi(chandle stcam, inout cam_sw_stats_t sw_stats, inout int status);



// SSTCAM API

// Max masks (should be 1024 for SMH 2.0) - matching sstcam.h for now
localparam SSTCAM_MASK_MAX = 64;

// Gather stats
localparam SSTCAM_STATS_HITS_PER_MASK = 64'h1000;
localparam SSTCAM_STATS_BACKPRESSURE  = 64'h1001;

// The structs below are described in the file sstcam.h

// Use to collect hits per mask
typedef struct {
    int unsigned timestamp;
    int unsigned hits_per_mask[SSTCAM_MASK_MAX];
    int unsigned misses;
    int unsigned reserved[128-(SSTCAM_MASK_MAX+2)];
} sstcam_stats_hits_per_mask_t;

// Used to collect request back-pressure
typedef struct {
    int unsigned timestamp;
    int unsigned request;
    int unsigned reserved[128-2];
} sstcam_stats_backpressure_t;


// The functions are described in the file sstcam.h
import "DPI-C" context task sstcam_create_dpi(chandle cam_arg, inout chandle out_stcam, inout int status);

import "DPI-C" context task sstcam_mask_alloc_dpi(chandle stcam, chandle mask, inout shortint unsigned out_id, inout int status);

import "DPI-C" context task sstcam_mask_free_dpi(chandle stcam, shortint unsigned id, inout int status);

import "DPI-C" context task sstcam_insert_dpi(chandle stcam, chandle key, shortint unsigned mask_id, int unsigned prio, chandle response, inout int status);

import "DPI-C" context task sstcam_update_dpi(chandle stcam, chandle key, shortint unsigned mask_id, chandle response, inout int status);

import "DPI-C" context task sstcam_delete_dpi(chandle stcam, chandle key, shortint unsigned mask_id, inout int status);

import "DPI-C" context task sstcam_lookup_dpi(chandle stcam, chandle key, chandle response, inout int status);

import "DPI-C" context task sstcam_get_stats(chandle stcam, longint unsigned stats_group, inout sstcam_stats_hits_per_mask_t stats);

import "DPI-C" context function void sstcam_destroy_dpi(chandle stcam);



// CSTCAM API
localparam int CSTCAM_MAX_MASKS = 64;

// The struct is described in the file cstcam.h
typedef struct {
    shortint unsigned mask_id[CSTCAM_MAX_MASKS];
    int      unsigned efficiency[CSTCAM_MAX_MASKS]; // Efficiency measured as hits per memory unit per second.
                                                    // E.g. metric[2] contains the efficiency for the mask_id stored in mask_id[2]
    byte num_masks;
} mask_efficiency_t;


// The functions are described in the file cstcam.h
import "DPI-C" context function longint unsigned cstcam_size();

import "DPI-C" context task cstcam_create_dpi(ccam_arg_t ccam_arg, inout chandle out_cstcam,
                                              inout int status);

import "DPI-C" context function void cstcam_destroy_dpi(chandle cstcam);

import "DPI-C" context task cstcam_init_dpi(ccam_arg_t ccam_arg, inout chandle out_cstcam,
                                            inout int status);

import "DPI-C" context task cstcam_insert_dpi(chandle cstcam, chandle key, chandle mask,
                                              int unsigned prio, chandle response, inout int status);

import "DPI-C" context task cstcam_update_dpi(chandle cstcam, chandle key, chandle mask,
                                              chandle response, inout int status);

import "DPI-C" context task cstcam_delete_dpi(chandle cstcam, chandle key, chandle mask,
                                              inout int status);

import "DPI-C" context task cstcam_get_by_key_dpi(chandle cstcam, chandle key, chandle mask,
                                                  chandle out_response, inout int status);

import "DPI-C" context task cstcam_get_by_response_dpi(chandle cstcam, chandle in_response,
                                                       chandle response_mask, chandle pos,
                                                       chandle out_key, chandle out_mask,
                                                       chandle out_response,
                                                       inout int unsigned out_prio, inout int status);

import "DPI-C" context task cstcam_get_stats(chandle cstcam, longint unsigned stats_group,
                                             mask_efficiency_t stats);

import "DPI-C" context task cstcam_mu_alloc_dpi(chandle cstcam, chandle mask,
                                                shortint unsigned mask_id, inout int status);

import "DPI-C" context task cstcam_mu_free_dpi(chandle cstcam, shortint unsigned mask_id,
                                               inout int status);

import "DPI-C" context task cstcam_mask_alloc_dpi(chandle cstcam, chandle mask,
                                                  inout shortint unsigned mask_id, inout int status);

import "DPI-C" context task cstcam_mask_free_dpi(chandle cstcam, shortint unsigned mask_id,
                                                 inout int status);

// CUE API
// For now this shares most functions with the BCAM API but that will change soon.
typedef struct {
    int unsigned timestamp;
    int unsigned delete_failed;
    int unsigned delete_succeeded;
    int unsigned update_failed;
    int unsigned update_succeeded;
    int unsigned insert_failed;
    int unsigned insert_succeeded;
    int unsigned reserved[128-7];
} cue_stats_counters_t;

import "DPI-C" context task cue_get_stats_counters_dpi(chandle bcam, inout cue_stats_counters_t sw_stats, inout int status);

// Utilities
// The functions are described in the file cam_util.[ch]
import "DPI-C" context function shortint unsigned get_key_len(string format);

import "DPI-C" context function chandle byte_arr_create(shortint unsigned bit_len);

import "DPI-C" context function void byte_arr_destroy(chandle byte_arr);

import "DPI-C" context function void str2byte_arr(shortint unsigned bit_len, string str,
                                                  chandle key_mask);

import "DPI-C" context function string byte_arr2str(shortint unsigned bit_len, chandle key_mask);

import "DPI-C" context function void byte_arr2bit_arr(shortint unsigned bit_len, chandle byte_arr,
                                                      inout bit[1024-1:0] bit_arr);

import "DPI-C" context function void bit_arr2byte_arr(shortint unsigned len, bit[1024-1:0] bit_arr,
                                                      chandle byte_arr);

import "DPI-C" context function chandle uint32_create();

import "DPI-C" context function void uint32_destroy(chandle num);

import "DPI-C" context function void uint32_set(chandle dst, int value);

import "DPI-C" context function int uint32_get(chandle dst);


// Helper functions used for specification of rd/wr operations.
// The function returns a pointer to the software wrapper used to call the Verilog task doing
// hardware rd/wr.
// The functions are defined in the file cam_dpi.[ch]
import "DPI-C" context function chandle get_hw_wr_function();
import "DPI-C" context function chandle get_hw_wr_function_vbcam();
import "DPI-C" context function chandle get_hw_rd_function();
import "DPI-C" context function chandle get_hw_rd_function_vbcam();
import "DPI-C" context function chandle get_hw_wr_start_function();
import "DPI-C" context function chandle get_hw_wr_stop_function();



// Optimization flags
localparam int CAM_OPTIMIZE_NONE    = 32'h00000000; // No optimizations
localparam int CAM_OPTIMIZE_RAM     = 32'h00000001; // The default hw generation balances logic and ram.
                                                    // Use this flag to reduce ram cost with a potentially higher logic cost.
                                                    // Reducing both ram and logic is not possible. Not supported for hbm
localparam int CAM_OPTIMIZE_LOGIC   = 32'h00000002; // The default hw generation balances logic and ram.
                                                    // Use this flag to reduce logic cost with a potentially higher ram cost.
                                                    // Reducing both ram and logic is not possible. Not supported for hbm
localparam int CAM_OPTIMIZE_ENTRIES = 32'h00000004; // This flag is only valid for stcam and bcam.
                                                    // The default behavior is to disallow more than num_entries to be
                                                    // inserted. This flag allows additional insertions if there is spare memory.
                                                    // When memory was allocated for num_entries, quantification effects might
                                                    // have created spare memory. For stcam, inserting excessive entries might
                                                    // compromise the number of masks that can be inserted. The stcam
                                                    // dimensioning algorithm uses a worst case distribution of entries over
                                                    // masks. The actual number of entries that can be inserted might
                                                    // be much higher than num_entries if the distribution is favorable.
localparam int CAM_OPTIMIZE_MASKS   = 32'h00000008; // This flag is only valid for stcam. The default behavior is to disallow more than num_masks to be
                                                    // inserted. This flag allows
                                                    // additional mask insertions. Inserting excessive masks may compromise
                                                    // how many entries that can be inserted.The stcam
                                                    // dimensioning algorithm uses a worst case distribution of entries over
                                                    // masks. The actual number of masks that can be inserted might
                                                    // be much higher than num_masks if the distribution is favorable.



// Debug flags
localparam int CAM_DEBUG_NONE               = 32'h0000_0000;  // Quiet, only software error messages are printed
localparam int CAM_DEBUG_NO_ERROR_MSG       = 32'h0000_0001;  // Disable software error messages printout
localparam int CAM_DEBUG_ARGS               = 32'h0000_0002;  // Software echoes input arguments
localparam int CAM_DEBUG_VERIFY_WR          = 32'h0000_0004;  // Software immediately reads back written data from
                                                              // hardware for verification. Mismatching data is
                                                              // reported with error message.
localparam int CAM_DEBUG_VERIFY_SHADOW      = 32'h0000_0008;  // 'get_by_response' and 'get_by_key' operations read
                                                              // data from hardware and verifies software shadow
                                                              // data
localparam int CAM_DEBUG_VERBOSE_VERIFY     = 32'h0000_0010;  // Enables printout of all verify operations,
                                                              // including correct compare. Applies to
                                                              // CAM_DEBUG_VERIFY_WR, CAM_DEBUG_VERIFY_SHADOW,
                                                              // and CAM_DEBUG_VERIFY_CONFIG.
localparam int CAM_DEBUG_SKIP_MEM_INIT      = 32'h0000_0020;  // Skip memory initialization, useful to speedup
                                                              // Verilog simulation
localparam int CAM_DEBUG_CONFIG             = 32'h0000_0040;  // Enable printout of configuration parameters for both
                                                              // software and Verilog hardware simulation
localparam int CAM_DEBUG_VERIFY_CONFIG      = 32'h0000_0080;  // DEPRECATED: Configuration parameters are automatically
                                                              // read from hardware for verification
localparam int CAM_DEBUG_KEY_MASKING        = 32'h0000_0100;  // Enable error check for the presence of key value '1'
                                                              // in masked (wildcarded) bit position.
                                                              // Applies stcam and tcam input arguments.
localparam int CAM_DEBUG_STATS              = 32'h0000_0200;  // Enable statistics printout in the 'bcam_destroy' and
                                                              // 'stcam_destroy' functions.
localparam int CAM_DEBUG_SEGMENTS           = 32'h0000_0400;  // Software prints segment map for virtualized bcam (vbcam)
localparam int CAM_DEBUG_SKIP_VERIFY_CONFIG = 32'h0000_0800;  // Skip verification of hardware/software configuration
                                                              // parameters
localparam int CAM_DEBUG_SET_COVER          = 32'h0000_1000;  // Software prints heap and set cover information for tcam
localparam int CAM_DEBUG_CONFIG_ARGS        = 32'h0000_2000;  // Software prints cam_arg values before creating the instance

localparam int CAM_DEBUG_HW_WR              = 32'h0001_0000;  // Verilog hardware prints write operations
localparam int CAM_DEBUG_HW_RD              = 32'h0002_0000;  // Verilog hardware prints read operations
localparam int CAM_DEBUG_HW_LOOKUP          = 32'h0004_0000;  // Verilog hardware prints lookup operations



// Error codes
localparam int CAM_ERROR_FULL                          = 1;
localparam int CAM_ERROR_NO_OPEN                       = 2;
localparam int CAM_ERROR_WRONG_KEY_WIDTH               = 5;
localparam int CAM_ERROR_TOO_MANY_INSTANCES            = 6;
localparam int CAM_ERROR_WRONG_BIT_FIELD_MASK          = 7;
localparam int CAM_ERROR_WRONG_CONST_FIELD_MASK        = 8;
localparam int CAM_ERROR_WRONG_UNUSED_FIELD_MASK       = 9;
localparam int CAM_ERROR_INVALID_TERNARY_FIELD_LEN     = 10;
localparam int CAM_ERROR_WRONG_PRIO_WIDTH              = 11;
localparam int CAM_ERROR_WRONG_MAX                     = 12;
localparam int CAM_ERROR_DUPLICATE_FOUND               = 13;
localparam int CAM_ERROR_WRONG_PREFIX                  = 14;
localparam int CAM_ERROR_WRONG_PREFIX_MASK             = 15;
localparam int CAM_ERROR_WRONG_RANGE                   = 16;
localparam int CAM_ERROR_WRONG_RANGE_MASK              = 17;
localparam int CAM_ERROR_KEY_NOT_FOUND                 = 18;
localparam int CAM_ERROR_WRONG_MIN                     = 19;
localparam int CAM_ERROR_WRONG_PRIO                    = 20;
localparam int CAM_ERROR_WRONG_LIST_LENGTH             = 21;
localparam int CAM_ERROR_WRONG_NUMBER_OF_SLOTS         = 22;
localparam int CAM_ERROR_INVALID_MEM_TYPE              = 23;
localparam int CAM_ERROR_TOO_HIGH_FREQUENCY            = 24;
localparam int CAM_ERROR_WRONG_TERNARY_MASK            = 25;
localparam int CAM_ERROR_MASKED_KEY_BIT_IS_SET         = 26;
localparam int CAM_ERROR_INVALID_MODE                  = 28;
localparam int CAM_ERROR_WRONG_RESPONSE_WIDTH          = 29;
localparam int CAM_ERROR_FORMAT_SYNTAX                 = 30; // Syntax error in format
localparam int CAM_ERROR_TOO_MANY_FIELDS               = 31; // Too many fields
localparam int CAM_ERROR_TOO_MANY_RANGES               = 32; // Too many ranges
localparam int CAM_ERROR_INVALID_RANGE_LEN             = 33; // Invalid range len
localparam int CAM_ERROR_INVALID_RANGE_START           = 34; // Range start + len exceeds key len
localparam int CAM_ERROR_INVALID_PREFIX_LEN            = 35; // Invalid prefix len
localparam int CAM_ERROR_INVALID_PREFIX_START          = 36; // Prefix start + len exceeds key len
localparam int CAM_ERROR_INVALID_PREFIX_KEY            = 37; // Prefix key longer than prefix len
localparam int CAM_ERROR_INVALID_BIT_FIELD_LEN         = 38; // Invalid bit len
localparam int CAM_ERROR_INVALID_BIT_FIELD_START       = 39; // Bit start + len exceeds key len
localparam int CAM_ERROR_INVALID_CONST_FIELD_LEN       = 40; // Invalid const len
localparam int CAM_ERROR_INVALID_CONST_FIELD_START     = 41; // Const start + len exceeds key len
localparam int CAM_ERROR_INVALID_UNUSED_FIELD_LEN      = 42; // Invalid unused len
localparam int CAM_ERROR_INVALID_UNUSED_FIELD_START    = 43; // Unused start + len exceeds key len
localparam int CAM_ERROR_MAX_KEY_LEN_EXCEED            = 44; // Sum of all field lengths exceeds key len
localparam int CAM_ERROR_INVALID_PRIO_AND_INDEX_WIDTH  = 45; // Prio width is too narrow or too wide
localparam int CAM_ERROR_TOO_MANY_UNITS                = 46; // Too many logical or physical memory units
localparam int CAM_ERROR_NO_MASK                       = 47; // Error during tcam_insert. The entry has not been inserted since
                                                             // hardware resources are partially depleted. It is possible to
                                                             // continue using the instance, inserting entries using already
                                                             // allocated resources, updating entries, get entries or delete entries.
localparam int CAM_ERROR_INVALID_MEMORY_WIDTH          = 48; // The memory structure defined by the combined key and response width is too wide
localparam int CAM_ERROR_UNSUPPORTED_COMMAND           = 49; // Unsupported Computational CAM command
localparam int CAM_ERROR_ENVIRONMENT                   = 50; // Computational CAM environment error at transport layer or IP non responsive
localparam int CAM_ERROR_UNSUPPORTED_CAM_TYPE          = 51; // API request for an unsupported cam type
localparam int CAM_ERROR_NULL_POINTER                  = 52; // Null pointer
localparam int CAM_ERROR_TOO_MANY_PCS                  = 53; // Too many pseudo-channels (PCs) are used
localparam int CAM_ERROR_CONFIGURATION                 = 54; // Hardware configuration parameters do not match software setttings
localparam int CAM_ERROR_ENVIRONMENT_FSMBUSY           = 55; // Computational BCAM FSM reporting busy
localparam int CAM_ERROR_ENVIRONMENT_POLLED_OUT        = 56; // Computational BCAM has polled stutus register beyond the max allowed
localparam int CAM_ERROR_SEGMENT_COUNT_ZERO            = 57; // Virtual BCAM has zero segments
localparam int CAM_ERROR_VC_UNSUPPORTED_COMMAND        = 58; // Unsupported Virtual container command
localparam int CAM_ERROR_WRONG_VIRTUAL_CAM_ID          = 59; // Wrong virtual BCAM identifier
localparam int CAM_ERROR_WRONG_SEGMENT_NUMBER          = 60; // Wrong segment number
localparam int CAM_ERROR_TOO_MANY_RAMS                 = 61; // Too many RAM instances are used
localparam int CAM_ERROR_FOUND_IN_SHADOW_BUT_NOT_IN_HW = 62; // Shadow and HW does not match
localparam int CAM_ERROR_TOO_SMALL_HEAP                = 63; // The provided max heap is not sufficiently large
localparam int CAM_ERROR_RAM_TOO_SMALL                 = 64; // The RAM is not large enough to be divided into virtual segments
localparam int CAM_ERROR_NOT_EMPTY                     = 65; // Still contains entries
localparam int CAM_ERROR_STATISTICS_NOT_AVAILABLE      = 66; // The hardware was not generated with statistics enabled
localparam int CAM_ERROR_FORMAT_COMPLEXITY             = 69; // Format string complexity too high
localparam int CAM_ERROR_MALLOC_FAILED                 = 198;
localparam int CAM_ERROR_NOMEM                         = 199;

enum {CAM_UPDATE_SOFTWARE=0, CAM_UPDATE_HARDWARE} cam_update_mode; 

`endif

endpackage

`endif

