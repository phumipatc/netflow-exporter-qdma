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
 * Functions for DPI simulation
 *
 * @file cam_dpi.h
 *
 */


#ifndef _CAM_DPI_H_
#define _CAM_DPI_H_

#include "svdpi.h"
#include "bcam.h"
#include "vbcam.h"
#include "cbcam.h"
#include "tcam.h"
#include "stcam.h"
#include "cstcam.h"
#include "sstcam.h"

/* White-box access to CUE functions for now. This will change once
 * the CUE is split out into its own driver. */
#include "client.h"
#include "cue_ops.h"

#define XSTR(s) #s
#define STR(s) XSTR(s)

#ifndef DPI_PATH
#define DPI_PATH example_top.AXM
#endif

#ifdef __cplusplus
extern "C" {
#endif



/* Extern declaration required, because axi_lite_wr is a Verilog task (not a C function). */
extern void axi_lite_wr(uint32_t address, uint32_t data);

/* Extern declaration required, because axi_lite_rd is a Verilog task (not a C function). */
extern void axi_lite_rd(uint32_t address, uint32_t *data);




/**
 * Target specific function for hardware write.
 * In a real system this function performs the basic write to hardware.
 * For Verilog simulation the function calls a Verilog task via DPI.
 */
void hw_wr_function(void *ctx, uint32_t address, uint32_t data);


/**
 * Target specific function for virtualized hardware write for vbcam.
 * In a real system this function performs the basic write to hardware.
 * For Verilog simulation the function calls a Verilog task via DPI.
 */
void hw_wr_function_vbcam(void *ctx, uint32_t address, uint32_t data);


/**
 * Target specific function for hardware read.
 * In a real system this function performs the basic read from hardware.
 * For Verilog simulation the function calls a Verilog task via DPI.
 */
void hw_rd_function(void *ctx, uint32_t address, uint32_t *data);


/**
 * Target specific function for virtualized hardware read for vbcam.
 * In a real system this function performs the basic read from hardware.
 * For Verilog simulation the function calls a Verilog task via DPI.
 */
void hw_rd_function_vbcam(void *ctx, uint32_t address, uint32_t *data);


/**
 * Target specific function to start exclusive hardware access in virtualized mode.
 * A globally defined pthread_mutex is used in this example,
 * the mutex can also be passed via the ctx argument.
 */
void hw_wr_start_function(void* ctx);


/**
 * Target specific function to stop exclusive hardware access in virtualized mode.
 * A globally defined pthread_mutex is used in this example,
 * the mutex can also be passed via the ctx argument.
 */
void hw_wr_stop_function(void* ctx);


/**
 * Function that return a pointer to the hardware write function.
 * Required during configuration of the CAM instance.
 */
void (*get_hw_wr_function(void))(void *ctx, uint32_t address, uint32_t data);


/**
 * Function that return a pointer to the virtualized hardware write function for vbcam.
 * Required during configuration of the CAM instance.
 */
void (*get_hw_wr_function_vbcam(void))(void *ctx, uint32_t address, uint32_t data);


/**
 * Function that return a pointer to the hardware read function.
 * Required during configuration of the CAM instance.
 */
void (*get_hw_rd_function(void))(void *ctx, uint32_t address, uint32_t *data);


/**
 * Function that return a pointer to the virtualized hardware read function for vbcam.
 * Required during configuration of the CAM instance.
 */
void (*get_hw_rd_function_vbcam(void))(void *ctx, uint32_t address, uint32_t *data);


/**
 * Function that return a pointer to the hardware write start function for vbcam.
 * Required during configuration of the CAM instance.
 */
void (*get_hw_wr_start_function(void))(void *ctx);


/**
 * Function that return a pointer to the hardware write stop function for vbcam.
 * Required during configuration of the CAM instance.
 */
void (*get_hw_wr_stop_function(void))(void *ctx);


/**
 * Function that convert from C byte array to System Verilog bit array.
 */
void byte_arr2bit_arr(const uint16_t bit_len, const uint8_t byte_arr[], svBitVecVal* bit_arr);


/**
 * Function that convert from System Verilog bit array to C byte array.
 */
void bit_arr2byte_arr(const uint16_t bit_len, const svBitVecVal* bit_arr, uint8_t byte_arr[]);



/* cam_arg DPI functions */
void cam_arg_set_engine_lookup_rate_hz(struct cam_arg_t *cam_arg, uint32_t lookup_rate_hz);
void cam_arg_set_lookup_interface_freq_hz(struct cam_arg_t *cam_arg, uint32_t freq_hz);
void cam_arg_set_ram_freq_hz(struct cam_arg_t *cam_arg, uint32_t freq_hz);



/* bcam DPI functions */
int bcam_create_dpi(const cam_arg_t *cam_arg, struct bcam **out_bcam, int32_t *status);
int bcam_destroy_dpi(struct bcam *bcam, int32_t *status);
int bcam_insert_dpi(struct bcam *bcam, const uint8_t key[], const uint8_t response[],
                    const cam_options_t *options, int32_t *status);
int bcam_update_dpi(struct bcam *bcam, const uint8_t key[], const uint8_t response[],
                    const cam_options_t *options, int32_t *status);
int bcam_delete_dpi(struct bcam *bcam, const uint8_t key[], const cam_options_t *options,
                    int32_t *status);
int bcam_delete_all_dpi(struct bcam *bcam, const cam_options_t *options, int32_t *status);
int bcam_get_by_response_dpi(struct bcam *bcam, const uint8_t response[],
                             const uint8_t response_mask[], uint32_t *pos, uint8_t out_key[],
                             const cam_options_t *options, int32_t *status);
int bcam_get_by_key_dpi(struct bcam *bcam, const uint8_t key[], uint8_t response[],
                        const cam_options_t *options, int32_t *status);
int bcam_get_stats_last_lookup_dpi(struct bcam *bcam, struct cam_last_lookup *last_lookup,
                                   int32_t *status);
int bcam_get_stats_dram_rate_dpi(struct bcam *bcam, struct cam_dram_rate *dram_rate,
                                 int32_t *status);
int bcam_get_stats_dram_snapshot_dpi(struct bcam *bcam, struct cam_dram_snapshot *dram_snapshot,
                                     int32_t *status);
int bcam_get_stats_sw_dpi(struct bcam *bcam, struct cam_sw *sw_stats, int32_t *status);


/* vbcam DPI functions */
int vbcam_create_dpi(const cam_arg_t* cam_arg, struct vbcam** out_vbcam, int32_t* status);
int vbcam_destroy_dpi(struct vbcam* vbcam, int32_t* status);
int vbcam_insert_dpi(struct vbcam* vbcam, const uint8_t key[], const uint8_t response[],
                     const cam_options_t *options, int32_t* status);
int vbcam_update_dpi(struct vbcam* vbcam, const uint8_t key[], const uint8_t response[],
                     const cam_options_t *options, int32_t* status);
int vbcam_delete_dpi(struct vbcam* vbcam, const uint8_t key[], const cam_options_t *options,
                     int32_t* status);
int vbcam_delete_all_dpi(struct vbcam* vbcam, const cam_options_t *options, int32_t* status);
int vbcam_get_by_response_dpi(struct vbcam* vbcam, const uint8_t response[],
                              const uint8_t response_mask[], uint32_t* pos,uint8_t out_key[],
                              const cam_options_t *options, int32_t* status);
int vbcam_get_by_key_dpi(struct vbcam* vbcam, const uint8_t key[], uint8_t response[],
                         const cam_options_t *options, int32_t* status);



/* cbcam DPI functions */
int cbcam_create_dpi(const struct ccam_arg *ccam_arg, struct cbcam **out_cbcam,
                     int32_t *status);
int cbcam_init_dpi(const struct ccam_arg *ccam_arg, struct cbcam *cbcam, int32_t *status);
void cbcam_destroy_dpi(struct cbcam *cbcam);
int cbcam_insert_dpi(struct cbcam *cbcam, const uint8_t key[], const uint8_t response[],
                     int32_t *status);
int cbcam_update_dpi(struct cbcam *cbcam, const uint8_t key[], const uint8_t response[],
                     int32_t *status);
int cbcam_delete_dpi(struct cbcam *cbcam, const uint8_t key[], int32_t *status);
int cbcam_delete_all_dpi(struct cbcam *cbcam, int32_t *status);
int cbcam_get_by_key_dpi(struct cbcam *cbcam, const uint8_t key[], uint8_t response[],
                         int32_t *status);
int cbcam_get_by_response_dpi(struct cbcam *cbcam, const uint8_t in_response[],
                              const uint8_t response_mask[], uint32_t *pos, uint8_t out_key[],
                              uint8_t out_response[], int32_t *status);



/* tcam DPI functions */
int tcam_create_dpi(const cam_arg_t *cam_arg, struct tcam **out_tcam, int32_t *status);
int tcam_destroy_dpi(struct tcam *tcam, int32_t *status);
int tcam_insert_dpi(struct tcam *tcam, const uint8_t key[], const uint8_t mask[],
                    uint32_t prio, const uint8_t response[], int32_t *status);
int tcam_update_dpi(struct tcam *tcam, const uint8_t key[], const uint8_t mask[],
                    const uint8_t response[], int32_t *status);
int tcam_delete_dpi(struct tcam *tcam, const uint8_t key[], const uint8_t mask[],
                    int32_t *status);
int tcam_delete_all_dpi(struct tcam *tcam, int32_t *status);
int tcam_get_by_response_dpi(struct tcam *tcam, const uint8_t response[],
                             const uint8_t response_mask[], uint32_t *pos,
                             uint8_t out_key[], uint8_t out_mask[], int32_t *status);
int tcam_get_by_key_dpi(struct tcam *tcam, const uint8_t key[], const uint8_t mask[],
                        uint32_t *prio, uint8_t response[], int32_t *status);
int tcam_lookup_dpi(struct tcam *tcam, const uint8_t key[], uint8_t response[],
                    int32_t *status);
int tcam_get_stats_last_lookup_dpi(struct tcam *tcam, struct cam_last_lookup *last_lookup,
                                   int32_t *status);
int tcam_get_stats_sw_dpi(struct tcam *tcam, struct cam_sw *sw_stats, int32_t *status);



/* stcam DPI functions */
int stcam_create_dpi(const cam_arg_t *cam_arg, struct stcam **out_stcam, int32_t *status);
int stcam_insert_dpi(struct stcam *stcam, const uint8_t key[], const uint8_t mask[],
                     uint32_t prio, const uint8_t response[], int32_t *status);
int stcam_update_dpi(struct stcam *stcam, const uint8_t key[], const uint8_t mask[],
                     const uint8_t response[], int32_t *status);
int stcam_delete_dpi(struct stcam *stcam, const uint8_t key[], const uint8_t mask[],
                     int32_t *status);
int stcam_delete_all_dpi(struct stcam *stcam, int32_t *status);
int stcam_get_by_response_dpi(struct stcam *stcam, const uint8_t response[],
                              const uint8_t response_mask[], uint32_t *pos,
                              uint8_t out_key[], uint8_t out_mask[], int32_t *status);
int stcam_get_by_key_dpi(struct stcam *stcam, const uint8_t key[], const uint8_t mask[],
                         uint32_t *prio, uint8_t response[], int32_t *status);
int stcam_lookup_dpi(struct stcam *stcam, const uint8_t key[], uint8_t response[],
                     int32_t *status);
int stcam_get_stats_last_lookup_dpi(const struct stcam *stcam,
                                    struct cam_last_lookup *last_lookup, int32_t *status);
int stcam_get_stats_sw_dpi(const struct stcam *stcam, struct cam_sw *sw_stats,
                          int32_t *status);



/* sstcam DPI functions */
int sstcam_create_dpi(const cam_arg_t *cam_arg, struct sstcam **out_stcam,
                      int32_t *status);

void sstcam_destroy_dpi(struct sstcam *stcam);

int sstcam_mask_alloc_dpi(struct sstcam *stcam, const uint8_t mask[],
                          uint16_t *out_id, int32_t *status);

int sstcam_mask_free_dpi(struct sstcam *stcam, uint16_t id, int32_t *status);

int sstcam_insert_dpi(struct sstcam *stcam, const uint8_t key[],
                      uint16_t mask_id, uint32_t priority,
                      const uint8_t response[], int32_t *status);

int sstcam_update_dpi(struct sstcam *stcam, const uint8_t key[],
                      uint16_t mask_id, const uint8_t response[],
                      int32_t *status);

int sstcam_delete_dpi(struct sstcam *stcam, const uint8_t key[],
                      uint16_t mask_id, int32_t *status);

int sstcam_lookup_dpi(struct sstcam *stcam, const uint8_t key[],
                      uint8_t response[], int32_t *status);




/* cstcam DPI functions */
int cstcam_create_dpi(const struct ccam_arg *ccam_arg, struct cstcam **out_cstcam,
                      int32_t *status);
int cstcam_init_dpi(const struct ccam_arg *ccam_arg, struct cstcam *cstcam, int32_t *status);
void cstcam_destroy_dpi(struct cstcam *cstcam);
int cstcam_insert_dpi(struct cstcam *cstcam, const uint8_t key[], const uint8_t mask[],
                      uint32_t priority, const uint8_t response[], int32_t *status);
int cstcam_update_dpi(struct cstcam *cstcam, const uint8_t key[], const uint8_t mask[],
                      const uint8_t response[], int32_t *status);
int cstcam_delete_dpi(struct cstcam *cstcam, const uint8_t key[], const uint8_t mask[],
                      int32_t *status);
int cstcam_get_by_key_dpi(struct cstcam *cstcam, const uint8_t key[], const uint8_t mask[],
                          uint8_t out_response[], int32_t *status);
int cstcam_get_by_response_dpi(struct cstcam *cstcam, const uint8_t in_response[],
                               const uint8_t response_mask[], uint32_t *pos,
                               uint8_t out_key[], uint8_t out_mask[], uint8_t out_response[],
                               uint32_t *out_prio, int32_t *status);
int cstcam_mu_alloc_dpi(struct cstcam *cstcam, const uint8_t mask[], uint16_t mask_id,
                        int32_t *status);
int cstcam_mu_free_dpi(struct cstcam *cstcam, uint16_t mask_id, int32_t *status);
int cstcam_mask_alloc_dpi(struct cstcam *cstcam, const uint8_t mask[], uint32_t priority, uint16_t *mask_id,
                          int32_t *status);
int cstcam_mask_free_dpi(struct cstcam *cstcam, uint16_t mask_id, int32_t *status);


/* cbcam/cstcam DPI functions */
int ccam_get_stats_sw_dpi(const struct ccam *ccam, struct ccam_sw_stats *sw_stats,
                          int32_t *status);

int ccam_get_stats_rate_dpi(const struct ccam *ccam, struct ccam_rate_counters *rate_counters,
                            int32_t *status);

int ccam_get_stats_last_lookup_dpi(const struct ccam *ccam, struct ccam_last_lookup *last_lookup,
                                   int32_t *status);

int ccam_get_stats_iterations_dpi(const struct ccam *ccam, struct ccam_iteration_count *iterations,
                                  int32_t *status);

/* CUE DPI functions */
int cue_get_stats_counters_dpi(struct bcam *bcam, struct cue_stats_counters *sw_stats, int32_t *status);

#ifdef __cplusplus
}
#endif

#endif
