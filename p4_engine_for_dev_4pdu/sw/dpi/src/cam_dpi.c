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

/*
 * @file cam_dpi.c
 *
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <pthread.h>

#include "cam_dpi.h"



/*
 * Globally defined mutex used for hardware access in virtualized mode.
 * The mutex can be implemented in other ways, and be passed via the ctx argument.
 * In case there are multiple cam instances, each instance need its own mutex.
 */
pthread_mutex_t hw_access_mutex = PTHREAD_MUTEX_INITIALIZER;



/* Extern declaration required, because axi_lite_wr is a Verilog task (not a C function). */
extern void axi_lite_wr(uint32_t address, uint32_t data);



/*
 * Target specific function for hardware write.
 * In a real system this function performs the basic write to hardware.
 * For Verilog simulation the function calls a Verilog task via DPI.
 */
void hw_wr_function(void *ctx, uint32_t address, uint32_t data)
{
    /*
      DESIGN SPECIFIC INFORMATION -- NEEDS MODIFICATION:
      Specify the Verilog module where the hardware write Verilog task is defined.
    */
    svScope g_scope;
    g_scope = svGetScopeFromName(STR(DPI_PATH));
    svSetScope(g_scope);

    /*
      DESIGN SPECIFIC INFORMATION -- NEEDS MODIFICATION:
      In this example ctx only contain base address information.
      Additional information, if needed, can also be passed via ctx.
    */
    uint32_t base_address = * (uint32_t *) ctx;

    /*
      DESIGN SPECIFIC INFORMATION -- NEEDS MODIFICATION:
      In this example a Verilog task named 'axi_lite_wr' is doing the
      hardware write. The task takes address and data as input.
      Another task name, and other arguments are possible.
    */
    axi_lite_wr(base_address + address, data);
}



/*
 * Target specific function for virtualized hardware write for vbcam.
 * In a real system this function performs the basic write to hardware.
 * For Verilog simulation the function calls a Verilog task via DPI.
 */
void hw_wr_function_vbcam(void *ctx, uint32_t address, uint32_t data)
{
    /*
      The ctx pointer must be of type segment_ctx_t.
    */
    segment_ctx_t *segment_ctx = (segment_ctx_t *) ctx;

    /*
      DESIGN SPECIFIC INFORMATION -- NEEDS MODIFICATION:
      Specify the Verilog module where the hardware write Verilog task is defined.
    */
    svScope g_scope;
    g_scope = svGetScopeFromName(STR(DPI_PATH));
    svSetScope(g_scope);

    /*
      DESIGN SPECIFIC INFORMATION -- NEEDS MODIFICATION:
      In this example the virtualized ctx only contain base address information.
      Additional information, if needed, can also be passed via ctx.
    */
    uint32_t base_address = * (uint32_t *) segment_ctx->ctx;

    /*
      DESIGN SPECIFIC INFORMATION -- NEEDS MODIFICATION:
      In this example a Verilog task named 'axi_lite_wr' is doing the
      hardware write. The task takes address and data as input.
      Another task name, and other arguments are possible.
    */
    axi_lite_wr(base_address + address, data);
}


/*
 * Target specific function for hardware read.
 * In a real system this function performs the basic read from hardware.
 * For Verilog simulation the function calls a Verilog task via DPI.
 */
void hw_rd_function(void *ctx, uint32_t address, uint32_t *data)
{
    /*
      DESIGN SPECIFIC INFORMATION -- NEEDS MODIFICATION:
      Specify the Verilog module where the hardware read Verilog task is defined.
    */
    svScope g_scope;
    g_scope = svGetScopeFromName(STR(DPI_PATH));
    svSetScope(g_scope);

    /*
      DESIGN SPECIFIC INFORMATION -- NEEDS MODIFICATION:
      In this example ctx only contain base address information.
      Additional information, if needed, can also be passed via ctx.
    */
    uint32_t base_address = * (uint32_t *) ctx;

    /*
      DESIGN SPECIFIC INFORMATION -- NEEDS MODIFICATION:
      In this example a Verilog task named 'axi_lite_rd' is doing the
      hardware write. The task takes address and data arguments.
      Another task name and other arguments are possible.
    */
    axi_lite_rd(base_address + address, data);
}



/*
 * Target specific function for virtualized hardware read for vbcam.
 * In a real system this function performs the basic read from hardware.
 * For Verilog simulation the function calls a Verilog task via DPI.
 */
void hw_rd_function_vbcam(void *ctx, uint32_t address, uint32_t *data)
{
    /*
      The ctx pointer must be of type segment_ctx_t.
    */
    segment_ctx_t *segment_ctx = (segment_ctx_t *) ctx;

    /*
      DESIGN SPECIFIC INFORMATION -- NEEDS MODIFICATION:
      Specify the Verilog module where the hardware read Verilog task is defined.
    */
    svScope g_scope;
    g_scope = svGetScopeFromName(STR(DPI_PATH));
    svSetScope(g_scope);

    /*
      DESIGN SPECIFIC INFORMATION -- NEEDS MODIFICATION:
      In this example the virtualized ctx only contain base address information.
      Additional information, if needed, can also be passed via ctx.
    */
    uint32_t base_address = * (uint32_t *) segment_ctx->ctx;

    /*
      DESIGN SPECIFIC INFORMATION -- NEEDS MODIFICATION:
      In this example a Verilog task named 'axi_lite_rd' is doing the
      hardware write. The task takes address and data arguments.
      Another task name and other arguments are possible.
    */
    axi_lite_rd(base_address + address, data);
}



/*
 * Target specific function to start exclusive hardware access in virtualized mode.
 * A globally defined pthread_mutex is used in this example,
 * the mutex can also be passed via the ctx argument.
 */
void hw_wr_start_function(void* ctx)
{
    (void) ctx; // remove unused parameter warning
    pthread_mutex_lock(&hw_access_mutex);
}



/*
 * Target specific function to stop exclusive hardware access in virtualized mode.
 * A globally defined pthread_mutex is used in this example,
 * the mutex can also be passed via the ctx argument.
 */
void hw_wr_stop_function(void* ctx)
{
    (void) ctx; // remove unused parameter warning
    pthread_mutex_unlock(&hw_access_mutex);
}



/*
 * Function that return a pointer to the hardware write function.
 * Required during configuration of the CAM instance.
 */
void (*get_hw_wr_function(void))(void *ctx, uint32_t address, uint32_t data)
{
    return &hw_wr_function;
}



/*
 * Function that return a pointer to the virtualized hardware write function for vbcam.
 * Required during configuration of the CAM instance.
 */
void (*get_hw_wr_function_vbcam(void))(void *ctx, uint32_t address, uint32_t data)
{
    return &hw_wr_function_vbcam;
}



/*
 * Function that return a pointer to the hardware read function.
 * Required during configuration of the CAM instance.
 */
void (*get_hw_rd_function(void))(void *ctx, uint32_t address, uint32_t *data)
{
    return &hw_rd_function;
}



/*
 * Function that return a pointer to the virtualized hardware read function for vbcam.
 * Required during configuration of the CAM instance.
 */
void (*get_hw_rd_function_vbcam(void))(void *ctx, uint32_t address, uint32_t *data)
{
    return &hw_rd_function_vbcam;
}



/*
 * Function that return a pointer to the hardware write start function for vbcam.
 * Required during configuration of the CAM instance.
 */
void (*get_hw_wr_start_function(void))(void *ctx)
{
    return &hw_wr_start_function;
}



/*
 * Function that return a pointer to the hardware write stop function for vbcam.
 * Required during configuration of the CAM instance.
 */
void (*get_hw_wr_stop_function(void))(void *ctx)
{
    return &hw_wr_stop_function;
}



/*
 * Function that convert from C byte array to System Verilog bit array.
 */
void byte_arr2bit_arr(const uint16_t bit_len, const uint8_t byte_arr[], svBitVecVal* bit_arr)
{
    uint8_t byte_len = (bit_len + 7) / 8;
    for (int b = 0; b < byte_len; b++) {
        svPutPartselBit(bit_arr, byte_arr[b], b*8, 8);
    }
}



/*
 * Function that convert from System Verilog bit array to C byte array.
 */
void bit_arr2byte_arr(const uint16_t bit_len, const svBitVecVal* bit_arr, uint8_t byte_arr[])
{
    uint8_t byte_len = (bit_len + 7) / 8;
    svBitVecVal byte = 0;
    for (int b = 0; b < byte_len; b++) {
        svGetPartselBit(&byte, bit_arr, b*8, 8);
        byte_arr[b] = byte;
    }
}



/* cam_arg DPI functions */
void cam_arg_set_engine_lookup_rate_hz(struct cam_arg_t *cam_arg, uint32_t lookup_rate_hz)
{
    cam_arg_set_engine_lookup_rate(cam_arg, lookup_rate_hz / (float) 1000000.0);
}

void cam_arg_set_lookup_interface_freq_hz(struct cam_arg_t *cam_arg, uint32_t freq_hz)
{
    cam_arg_set_lookup_interface_freq(cam_arg, freq_hz / (float) 1000000.0);
}

void cam_arg_set_ram_freq_hz(struct cam_arg_t *cam_arg, uint32_t freq_hz)
{
    cam_arg_set_ram_freq(cam_arg, freq_hz / (float) 1000000.0);
}



/* bcam DPI functions */
int bcam_create_dpi(const cam_arg_t *cam_arg, struct bcam **out_bcam, int32_t *status)
{
    *status = bcam_create(cam_arg, out_bcam);
    return 0;
}

int bcam_destroy_dpi(struct bcam *bcam, int32_t *status)
{
    *status = bcam_destroy(bcam);
    return 0;
}

int bcam_insert_dpi(struct bcam *bcam, const uint8_t key[], const uint8_t response[],
                    const cam_options_t *options, int32_t *status)
{
    *status = bcam_insert(bcam, key, response, options);
    return 0;
}

int bcam_update_dpi(struct bcam *bcam, const uint8_t key[], const uint8_t response[],
                    const cam_options_t *options, int32_t *status)
{
    *status = bcam_update(bcam, key, response, options);
    return 0;
}

int bcam_delete_dpi(struct bcam *bcam, const uint8_t key[], const cam_options_t *options,
                    int32_t *status)
{
    *status = bcam_delete(bcam, key, options);
    return 0;
}

int bcam_delete_all_dpi(struct bcam *bcam, const cam_options_t *options, int32_t *status)
{
    *status = bcam_delete_all(bcam, options);
    return 0;
}

int bcam_get_by_response_dpi(struct bcam *bcam, const uint8_t response[],
                             const uint8_t response_mask[], uint32_t *pos, uint8_t out_key[],
                             const cam_options_t *options, int32_t *status)
{
    *status = bcam_get_by_response(bcam, response, response_mask, pos, out_key, options);
    return 0;
}

int bcam_get_by_key_dpi(struct bcam *bcam, const uint8_t key[], uint8_t response[],
                        const cam_options_t *options, int32_t *status)
{
    *status = bcam_get_by_key(bcam, key, response, options);
    return 0;
}

int bcam_get_stats_last_lookup_dpi(struct bcam *bcam, struct cam_last_lookup *last_lookup,
                                   int32_t *status)
{
    *status = bcam_get_stats(bcam, BCAM_STATS_LAST_LOOKUP, (union bcam_stats *) last_lookup);
    return 0;
}

int bcam_get_stats_dram_rate_dpi(struct bcam *bcam, struct cam_dram_rate *dram_rate,
                                 int32_t *status)
{
    *status = bcam_get_stats(bcam, BCAM_STATS_DRAM_RATE, (union bcam_stats *) dram_rate);
    return 0;
}

int bcam_get_stats_dram_snapshot_dpi(struct bcam *bcam, struct cam_dram_snapshot *dram_snapshot,
                                     int32_t *status)
{
    *status = bcam_get_stats(bcam, BCAM_STATS_DRAM_SNAPSHOT, (union bcam_stats *) dram_snapshot);
    return 0;
}

int bcam_get_stats_sw_dpi(struct bcam *bcam, struct cam_sw *sw_stats, int32_t *status)
{
    *status = bcam_get_stats(bcam, BCAM_STATS_SW, (union bcam_stats *) sw_stats);
    return 0;
}



/* vbcam DPI functions */
int vbcam_create_dpi(const cam_arg_t* cam_arg, struct vbcam** out_vbcam, int32_t* status)
{
    *status = vbcam_create(cam_arg, out_vbcam);
    return 0;
}

int vbcam_destroy_dpi(struct vbcam* vbcam, int32_t* status)
{
    *status = vbcam_destroy(vbcam);
    return 0;
}

int vbcam_insert_dpi(struct vbcam* vbcam, const uint8_t key[], const uint8_t response[],
                     const cam_options_t *options, int32_t* status)
{
    *status = vbcam_insert(vbcam, key, response, options);
    return 0;
}

int vbcam_update_dpi(struct vbcam* vbcam, const uint8_t key[], const uint8_t response[],
                     const cam_options_t *options, int32_t* status)
{
    *status = vbcam_update(vbcam, key, response, options);
    return 0;
}

int vbcam_delete_dpi(struct vbcam* vbcam, const uint8_t key[], const cam_options_t *options,
                     int32_t* status)
{
    *status = vbcam_delete(vbcam, key, options);
    return 0;
}

int vbcam_delete_all_dpi(struct vbcam* vbcam, const cam_options_t *options, int32_t* status)
{
    *status = vbcam_delete_all(vbcam, options);
    return 0;
}

int vbcam_get_by_response_dpi(struct vbcam* vbcam, const uint8_t response[],
                              const uint8_t response_mask[], uint32_t* pos, uint8_t out_key[],
                              const cam_options_t *options, int32_t* status)
{
    *status = vbcam_get_by_response(vbcam, response, response_mask, pos, out_key, options);
    return 0;
}

int vbcam_get_by_key_dpi(struct vbcam* vbcam, const uint8_t key[], uint8_t response[],
                         const cam_options_t *options, int32_t* status)
{
    *status = vbcam_get_by_key(vbcam, key, response, options);
    return 0;
}




/* cbcam DPI functions */
int cbcam_create_dpi(const struct ccam_arg *ccam_arg, struct cbcam **out_cbcam,
                     int32_t *status)
{
    struct cbcam *cbcam;
  //cbcam = calloc(1, cbcam_size());
    cbcam = malloc(cbcam_size());
    if (cbcam == NULL) {
        *status = CAM_ERROR_MALLOC_FAILED;
        return CAM_ERROR_MALLOC_FAILED;
    }
    *status = cbcam_init(ccam_arg, cbcam);

    *out_cbcam = cbcam;
    return 0;
}

int cbcam_init_dpi(const struct ccam_arg *ccam_arg, struct cbcam *cbcam, int32_t *status)
{
    *status = cbcam_init(ccam_arg, cbcam);
    return 0;
}

void cbcam_destroy_dpi(struct cbcam *cbcam)
{
    free(cbcam);
}

int cbcam_insert_dpi(struct cbcam *cbcam, const uint8_t key[], const uint8_t response[],
                     int32_t *status)
{
    *status = cbcam_insert(cbcam, key, response);
    return 0;
}

int cbcam_update_dpi(struct cbcam *cbcam, const uint8_t key[], const uint8_t response[],
                     int32_t *status)
{
    *status = cbcam_update(cbcam, key, response);
    return 0;
}

int cbcam_delete_dpi(struct cbcam *cbcam, const uint8_t key[], int32_t *status)
{
    *status = cbcam_delete(cbcam, key);
    return 0;
}

int cbcam_delete_all_dpi(struct cbcam *cbcam, int32_t *status)
{
    *status = cbcam_delete_all(cbcam);
    return 0;
}

int cbcam_get_by_key_dpi(struct cbcam *cbcam, const uint8_t key[], uint8_t response[],
                         int32_t *status)
{
    *status = cbcam_get_by_key(cbcam, key, response);
    return 0;
}

int cbcam_get_by_response_dpi(struct cbcam *cbcam, const uint8_t in_response[],
                              const uint8_t response_mask[], uint32_t *pos,
                              uint8_t out_key[], uint8_t out_response[], int32_t *status)
{
    *status = cbcam_get_by_response(cbcam, in_response, response_mask, pos, out_key,
                                    out_response);
    return 0;
}




/* tcam DPI functions */
int tcam_create_dpi(const cam_arg_t *cam_arg, struct tcam **out_tcam, int32_t *status)
{
    *status = tcam_create(cam_arg, out_tcam);
    return 0;
}

int tcam_destroy_dpi(struct tcam *tcam, int32_t *status)
{
    *status = tcam_destroy(tcam);
    return 0;
}

int tcam_insert_dpi(struct tcam *tcam, const uint8_t key[], const uint8_t mask[],
                    uint32_t prio, const uint8_t response[], int32_t *status)
{
    *status = tcam_insert(tcam, key, mask, prio, response);
    return 0;
}

int tcam_update_dpi(struct tcam *tcam, const uint8_t key[], const uint8_t mask[],
                    const uint8_t response[], int32_t *status)
{
    *status = tcam_update(tcam, key, mask, response);
    return 0;
}

int tcam_delete_dpi(struct tcam *tcam, const uint8_t key[], const uint8_t mask[],
                    int32_t *status)
{
    *status = tcam_delete(tcam, key, mask);
    return 0;
}

int tcam_delete_all_dpi(struct tcam *tcam, int32_t *status)
{
    *status = tcam_delete_all(tcam);
    return 0;
}

int tcam_get_by_response_dpi(struct tcam *tcam, const uint8_t response[],
                             const uint8_t response_mask[], uint32_t *pos, uint8_t out_key[],
                             uint8_t out_mask[], int32_t *status)
{
    *status = tcam_get_by_response(tcam, response, response_mask, pos, out_key, out_mask);
    return 0;
}

int tcam_get_by_key_dpi(struct tcam *tcam, const uint8_t key[], const uint8_t mask[],
                        uint32_t *prio, uint8_t response[], int32_t *status)
{
    *status = tcam_get_by_key(tcam, key, mask, prio, response);
    return 0;
}

int tcam_lookup_dpi(struct tcam *tcam, const uint8_t key[], uint8_t response[],
                    int32_t *status)
{
    *status = tcam_lookup(tcam, key, response);
    return 0;
}

int tcam_get_stats_last_lookup_dpi(struct tcam *tcam, struct cam_last_lookup *last_lookup,
                                   int32_t *status)
{
    *status = tcam_get_stats(tcam, TCAM_STATS_LAST_LOOKUP, (union tcam_stats *) last_lookup);
    return 0;
}

int tcam_get_stats_sw_dpi(struct tcam *tcam, struct cam_sw *sw_stats, int32_t *status)
{
    *status = tcam_get_stats(tcam, TCAM_STATS_SW, (union tcam_stats *) sw_stats);
    return 0;
}



/* stcam DPI functions */
int stcam_create_dpi(const cam_arg_t *cam_arg, struct stcam **out_stcam, int32_t *status)
{
    *status = stcam_create(cam_arg, out_stcam);
    return 0;
}

int stcam_insert_dpi(struct stcam *stcam, const uint8_t key[], const uint8_t mask[],
                     uint32_t prio, const uint8_t response[], int32_t *status)
{
    *status = stcam_insert(stcam, key, mask, prio, response);
    return 0;
}

int stcam_update_dpi(struct stcam *stcam, const uint8_t key[], const uint8_t mask[],
                     const uint8_t response[], int32_t *status)
{
    *status = stcam_update(stcam, key, mask, response);
    return 0;
}

int stcam_delete_dpi(struct stcam *stcam, const uint8_t key[], const uint8_t mask[],
                     int32_t *status)
{
    *status = stcam_delete(stcam, key, mask);
    return 0;
}

int stcam_delete_all_dpi(struct stcam *stcam, int32_t *status)
{
    *status = stcam_delete_all(stcam);
    return 0;
}

int stcam_get_by_response_dpi(struct stcam *stcam, const uint8_t response[],
                               const uint8_t response_mask[], uint32_t *pos,
                               uint8_t out_key[], uint8_t out_mask[], int32_t *status)
{
    *status = stcam_get_by_response(stcam, response, response_mask, pos, out_key, out_mask);
    return 0;
}

int stcam_get_by_key_dpi(struct stcam *stcam, const uint8_t key[], const uint8_t mask[],
                          uint32_t *prio, uint8_t response[], int32_t *status)
{
    *status = stcam_get_by_key(stcam, key, mask, prio, response);
    return 0;
}

int stcam_lookup_dpi(struct stcam *stcam, const uint8_t key[], uint8_t response[],
                      int32_t *status)
{
    *status = stcam_lookup(stcam, key, response);
    return 0;
}

int stcam_get_stats_last_lookup_dpi(const struct stcam *stcam, struct cam_last_lookup *last_lookup,
                                   int32_t *status)
{
    *status = stcam_get_stats(stcam, STCAM_STATS_LAST_LOOKUP, (union stcam_stats *) last_lookup);
    return 0;
}

int stcam_get_stats_sw_dpi(const struct stcam *stcam, struct cam_sw *sw_stats, int32_t *status)
{
    *status = stcam_get_stats(stcam, STCAM_STATS_SW, (union stcam_stats *) sw_stats);
    return 0;
}



/* cstcam DPI functions */
int cstcam_create_dpi(const struct ccam_arg *ccam_arg, struct cstcam **out_cstcam,
                      int32_t *status)
{
    struct cstcam *cstcam;
    cstcam = malloc(cstcam_size());
    if (cstcam == NULL) {
        *status = CAM_ERROR_MALLOC_FAILED;
        return CAM_ERROR_MALLOC_FAILED;
    }
    *status = cstcam_init(ccam_arg, cstcam);

    *out_cstcam = cstcam;
    return 0;
}

int cstcam_init_dpi(const struct ccam_arg *ccam_arg, struct cstcam *cstcam, int32_t *status)
{
    *status = cstcam_init(ccam_arg, cstcam);
    return 0;
}

void cstcam_destroy_dpi(struct cstcam *cstcam)
{
    free(cstcam);
}



int cstcam_insert_dpi(struct cstcam *cstcam, const uint8_t key[],
                      const uint8_t mask[], uint32_t priority,
                      const uint8_t response[], int32_t *status)
{
    *status = cstcam_insert(cstcam, key, mask, priority, response);
    return 0;
}

int cstcam_update_dpi(struct cstcam *cstcam, const uint8_t key[], const uint8_t mask[],
                      const uint8_t response[], int32_t *status)
{
    *status = cstcam_update(cstcam, key, mask, response);
    return 0;
}

int cstcam_delete_dpi(struct cstcam *cstcam, const uint8_t key[], const uint8_t mask[],
                      int32_t *status)
{
    *status = cstcam_delete(cstcam, key, mask);
    return 0;
}

int cstcam_get_by_key_dpi(struct cstcam *cstcam, const uint8_t key[], const uint8_t mask[],
                          uint8_t out_response[], int32_t *status)
{
    *status = cstcam_get_by_key(cstcam, key, mask, out_response);
    return 0;
}

int cstcam_get_by_response_dpi(struct cstcam *cstcam, const uint8_t in_response[],
                               const uint8_t response_mask[], uint32_t *pos,
                               uint8_t out_key[], uint8_t out_mask[], uint8_t out_response[],
                               uint32_t *out_prio, int32_t *status)
{
    *status = cstcam_get_by_response(cstcam, in_response, response_mask, pos,
                                     out_key, out_mask, out_response, out_prio);
    return 0;
}

int cstcam_mu_alloc_dpi(struct cstcam *cstcam, const uint8_t mask[], uint16_t mask_id,
                        int32_t *status)
{
    *status = cstcam_mu_alloc(cstcam, mask, mask_id);
    return 0;
}

int cstcam_mu_free_dpi(struct cstcam *cstcam, uint16_t mask_id, int32_t *status)
{
    *status = cstcam_mu_free(cstcam, mask_id);
    return 0;
}


int cstcam_mask_alloc_dpi(struct cstcam *cstcam, const uint8_t mask[],
                          uint32_t priority, uint16_t *mask_id, int32_t *status)
{
    *status = cstcam_mask_alloc(cstcam, mask, priority, mask_id);
    return 0;
}

int cstcam_mask_free_dpi(struct cstcam *cstcam, uint16_t mask_id, int32_t *status)
{
    *status = cstcam_mask_free(cstcam, mask_id);
    return 0;
}



int ccam_get_stats_sw_dpi(const struct ccam *ccam, struct ccam_sw_stats *sw_stats,
                          int32_t *status)
{
    *status = ccam_get_stats(ccam, CCAM_STATS_SW, (union ccam_stats *) sw_stats);
    return 0;
}

int ccam_get_stats_rate_dpi(const struct ccam *ccam, struct ccam_rate_counters *rate_counters,
                            int32_t *status)
{
    *status = ccam_get_stats(ccam, CCAM_STATS_RATE, (union ccam_stats *) rate_counters);
    return 0;
}

int ccam_get_stats_last_lookup_dpi(const struct ccam *ccam, struct ccam_last_lookup *last_lookup,
                                   int32_t *status)
{
    *status = ccam_get_stats(ccam, CCAM_STATS_LAST_LOOKUP, (union ccam_stats *) last_lookup);
    return 0;
}

int ccam_get_stats_iterations_dpi(const struct ccam *ccam, struct ccam_iteration_count *iterations,
                                  int32_t *status)
{
    *status = ccam_get_stats(ccam, CCAM_STATS_LAST_LOOKUP, (union ccam_stats *) iterations);
    return 0;
}




/* sstcam DPI functions */
int sstcam_create_dpi(const cam_arg_t *cam_arg, struct sstcam **out_stcam,
                      int32_t *status)
{
    *status = sstcam_create(cam_arg, out_stcam);
    return 0;
}

void sstcam_destroy_dpi(struct sstcam *stcam)
{
    sstcam_destroy(stcam);
}

int sstcam_mask_alloc_dpi(struct sstcam *stcam, const uint8_t mask[],
                          uint16_t *out_id, int32_t *status)
{
    *status = sstcam_mask_alloc(stcam, mask, out_id);
    return 0;
}

int sstcam_mask_free_dpi(struct sstcam *stcam, uint16_t id, int32_t *status)
{
    *status = sstcam_mask_free(stcam, id);
    return 0;
}

int sstcam_insert_dpi(struct sstcam *stcam, const uint8_t key[],
                      uint16_t mask_id, uint32_t priority,
                      const uint8_t response[], int32_t *status)
{
    *status = sstcam_insert(stcam, key, mask_id,
                            priority, response);
    return 0;
}

int sstcam_update_dpi(struct sstcam *stcam, const uint8_t key[],
                      uint16_t mask_id, const uint8_t response[],
                      int32_t *status)
{
    *status = sstcam_update(stcam, key, mask_id, response);
    return 0;
}

int sstcam_delete_dpi(struct sstcam *stcam, const uint8_t key[],
                      uint16_t mask_id, int32_t *status)
{
    *status = sstcam_delete(stcam, key, mask_id);
    return 0;
}

int sstcam_lookup_dpi(struct sstcam *stcam, const uint8_t key[],
                      uint8_t response[], int32_t *status)
{
    *status = sstcam_lookup(stcam, key, response);
    return 0;
}

int cue_get_stats_counters_dpi(struct bcam *bcam, struct cue_stats_counters *stats, int32_t *status)
{
    *status = cue_get_stats((client_t *)bcam, CUE_STATS_COUNTERS, (union cue_stats *)stats);
    return 0;
}
