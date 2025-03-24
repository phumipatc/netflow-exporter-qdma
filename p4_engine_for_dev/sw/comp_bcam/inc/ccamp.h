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
 * Private API of the Computational CAM.
 *
 * @file ccamp.h
 *

 */

#ifndef _CCAMP_H_
#define _CCAMP_H_


#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ccam.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CCAM_MAX_ENTRY_WIDTH 2048

#ifndef NULL_CHECK
#define NULL_CHECK(ptr)  if (ptr == NULL) return CCAM_ERROR_NULL_POINTER
#endif

typedef enum CAM_OPERATION_STATUS_ENUM {
    CAM_OPERATION_STATUS_SUCCESS        = 0x00,
    CAM_OPERATION_STATUS_CAMFULL        = 0x01,
    CAM_OPERATION_STATUS_KEYNOTFOUND    = 0x02,
    CAM_OPERATION_STATUS_DUPLICATEKEY   = 0x03,
    CAM_OPERATION_STATUS_FSMBUSY        = 0x04,
    CAM_OPERATION_STATUS_MASKNOTFOUND   = 0x05,
    CAM_OPERATION_STATUS_SUCCESSBLOCKED = 0x06
} CAM_OPERATION_STATUS_ENUM;

typedef enum CAM_OPERATION_ENUM {
    CAM_OPERATION_INSERT   = 0x00,
    CAM_OPERATION_UPDATE   = 0x01,
    CAM_OPERATION_DELETE   = 0x02,
    CAM_OPERATION_GETBYKEY = 0x03,
    CAM_OPERATION_RDBYADDR = 0x04,
    CAM_OPERATION_WRBYADDR = 0x05
} CAM_OPERATION_ENUM;

#define COMP_BCAM_BASE_INDIRECT_ADDR_REG_OFFSET (0x100)
#define COMP_BCAM_BASE_INDIRECT_RD_DATA_00_REG_OFFSET (0x104)
#define COMP_BCAM_BASE_INDIRECT_WR_DATA_00_REG_OFFSET (0x108)
#define COMP_BCAM_BASE_INDIRECT_WR_DATA_01_REG_OFFSET (0x10c)

#define INDIRECT_ADDR_KEY_WIDTH             (0x100)
#define INDIRECT_ADDR_PRIO                  (0x104)
#define INDIRECT_ADDR_RESP_WIDTH            (0x108)
#define INDIRECT_ADDR_UNITS                 (0x10C)
#define INDIRECT_ADDR_TIME_SLOTS            (0x110)
#define INDIRECT_ADDR_KM_DATA               (0x114)
#define INDIRECT_ADDR_KM_ADDR               (0x118)
#define INDIRECT_ADDR_MODE                  (0x11C)
#define INDIRECT_ADDR_NUM_ENTRIES           (0x120)
#define INDIRECT_ADDR_BUILD_NUM             (0x128)
#define INDIRECT_ADDR_ASIC                  (0x12C)
#define INDIRECT_ADDR_NUM_MASKS             (0x130)
#define INDIRECT_ADDR_CACHE_EN              (0x134)
#define INDIRECT_ADDR_AGING_EN              (0x138)
#define INDIRECT_ADDR_HW_STATS_EN           (0x13C)
#define INDIRECT_ADDR_SCRATCH               (0x184)
#define INDIRECT_ADDR_SBITERR_CNT           (0x300)
#define INDIRECT_ADDR_DBITERR_CNT           (0x304)
#define INDIRECT_ADDR_SBITERR_FFA           (0x308)
#define INDIRECT_ADDR_DBITERR_FFA           (0x30C)
#define INDIRECT_ADDR_ECC_TEST              (0x310)
#define INDIRECT_ADDR_CUCKOO_REG            (0x20000)
#define INDIRECT_ADDR_LAST_LOOKUP_KEY       (0x400)
// Last INDIRECT_ADDR_LAST_LOOKUP_KEY (0x47c)
#define INDIRECT_ADDR_LAST_LOOKUP_RESPONSE  (0x480)
// Last INDIRECT_ADDR_LAST_LOOKUP_RESPONSE (0x4fc)
#define INDIRECT_ADDR_LAST_LOOKUP_STATUS    (0x500)
// Bit 0: Match/No match, Bit 1: Double bit error


#define COMP_BCAM_BASE_VERSION_REG_OFFSET (0x0)
#define COMP_BCAM_BASE_NUMBER_PASSES_REG_OFFSET (0x14)
#define COMP_BCAM_BASE_INSERT_COUNT_REG_OFFSET (0x18)
#define COMP_BCAM_BASE_LOOKUP_COUNT_REG_OFFSET (0x28)
#define COMP_BCAM_BASE_HIT_COUNT_REG_OFFSET (0x2c)
#define COMP_BCAM_BASE_EXT_EVENT_COUNT_REG_OFFSET (0x38)
#define COMP_BCAM_BASE_LI_REQ_WS_COUNT_REG_OFFSET (0x3c)
#define COMP_BCAM_BASE_TOTAL_NUM_PASS_COUNT_LO_REG_OFFSET (0x40)
#define COMP_BCAM_BASE_TOTAL_NUM_PASS_COUNT_HI_REG_OFFSET (0x44)
#define COMP_BCAM_BASE_LAST_DET_NUM_PASS_COUNT_REG_OFFSET (0x48)
#define COMP_BCAM_BASE_MAX_DET_NUM_PASS_COUNT_REG_OFFSET (0x4c)

#define COMP_BCAM_BASE_CAM_CLEAR_REG_OFFSET (0x11c)



#define COMP_BCAM_BASE_STATUS_REG_OFFSET (0x110)

#define COMP_BCAM_BASE_PRIORITY_REG_OFFSET (0x144)

#define COMP_BCAM_BASE_MASK_ID_REG_OFFSET (0x120)


#define COMP_BCAM_BASE_RESPONSE_DATA_00_REG_OFFSET (0x300)

#define COMP_BCAM_BASE_KEY_DATA_00_REG_OFFSET (0x200)

#define COMP_BCAM_BASE_ENTRY_CTRL_REG_OFFSET (0x280)

#define COMP_BCAM_BASE_OPERATION_REG_OFFSET (0x114)

#define COMP_BCAM_BASE_MU_SELECT_REG_OFFSET (0x148)

#define COMP_BCAM_BASE_CHMU_REG_OFFSET (0x14C)

#define COMP_BCAM_BASE_SAMPLE_PER_CHMU_REG_OFFSET (0x150)

#define COMP_BCAM_BASE_SAMPLE_PER_REG_OFFSET (0x118)

#define CCAM_SAMPLE_RATE_1US        0
#define CCAM_SAMPLE_RATE_10US       1
#define CCAM_SAMPLE_RATE_100US      2
#define CCAM_SAMPLE_RATE_1MS        3
#define CCAM_SAMPLE_RATE_10MS       4
#define CCAM_SAMPLE_RATE_100MS      5
#define CCAM_SAMPLE_RATE_1S         6
#define CCAM_SAMPLE_RATE_NO_SAMPLE  7



#define CCAM_AGING_BITS 7

#define CCAM_FILL_RATIO 95/100
#define CCAM_2W_CUCKOO_FILL_RATIO 5/10
#define CCAM_3W_CUCKOO_FILL_RATIO 9/10


#define INSTANCE_CBCAM      5
#define INSTANCE_CSTCAM     6

#define CCAM_SW_VERSION_MAJOR   2
#define CCAM_SW_VERSION_MINOR   6
#define CCAM_SW_VERSION_PATCH   0
#define CCAM_BUILD_NUMBER       0

// LOGICAL ADDRESSING
#define PHMDEF_CR_WORD       0x04
#define PHMDEF_CA_WORD       0x08
#define PHMDEF_ECC_WORD      0x04
#define PHMDEF_SM_WORD       0x80
#define PHMDEF_MM_WORD       0x80
#define PHMDEF_BM_WORD       0x08
#define PHMDEF_KM_WORD       0x100

#define PHMDEF_CR_BASE       0x000100
#define PHMDEF_CA_BASE       0x000200
#define PHMDEF_ECC_BASE      0x000300
#define PHMDEF_SM_BASE       0x040000
#define PHMDEF_MM_BASE       0x100000
#define PHMDEF_BM_BASE       0x200000
#define PHMDEF_KM_BASE       0x400000

#define PHMDEF_CR_MASK       0x0fff00
#define PHMDEF_CA_MASK       0x0ffff0
#define PHMDEF_ECC_MASK      0x0ffff0
#define PHMDEF_SM_MASK       0x7c0000
#define PHMDEF_MM_MASK       0x700000
#define PHMDEF_BM_MASK       0x600000
#define PHMDEF_KM_MASK       0x400000

#define PHMDEF_UNIT_BASE     0x00800000
#define PHMDEF_UNIT_MASK     0xff800000



struct ccam_config {
    uint32_t hw_version;
    uint32_t hw_build_num;
    uint32_t key_width;
    uint32_t prio_width;  // Always zero for comp bcam
    uint32_t response_width;
    uint32_t num_slots;
    uint32_t phys_units;
    uint32_t ram_data_width;
    uint32_t ram_addresses;
    uint32_t instance_type;
    uint32_t num_entries;
    uint32_t num_masks; // Always zero for comp bcam
    uint32_t cache_en;
    uint32_t aging_en;
    uint32_t hw_stats_en; // Hardware was generated with statistics registers
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

void ccam_indirect_read(const struct ccam *ccam, uint32_t indirect_address, uint32_t *data);

void ccam_indirect_write(struct ccam *ccam, uint32_t indirect_address, uint64_t data);

void ccam_direct_write(const struct ccam *ccam, uint32_t direct_address, uint32_t data);

void ccam_direct_read(const struct ccam *ccam, uint32_t direct_address, uint32_t *data);
//ccam should be zeroed before calling
int ccam_init(const struct ccam_arg *arg, struct ccam *ccam);

int ccam_clear(const struct ccam *ccam);

/*uint16_t ccam_get_key_width(struct ccam *ccam);
uint16_t ccam_get_response_width(struct ccam *ccam);

uint32_t ccam_get_num_entries(struct ccam *ccam);
 */

bool ccam_is_blocked(const struct ccam *ccam);

bool ccam_is_cache(const struct ccam *ccam);

uint32_t ccam_calculate_max_num_entries(const struct ccam *ccam);
uint32_t ccam_calculate_base_address(const struct ccam *ccam, uint16_t unit, uint32_t entry_number);
int ccam_read_entry(struct ccam *ccam, uint16_t unit, uint32_t entry_number, bool cuckoo_reg);

// Only response_width is compared.
// start_entry_number and entry are only changed if the response is found and the function returns 0
int ccam_get_entry_by_response(struct ccam *ccam, const uint8_t response[], const uint8_t response_mask[],
                               uint16_t unit, uint32_t *start_entry_number);
int ccam_get_cuckoo_by_response(struct ccam *ccam, const uint8_t response[], const uint8_t response_mask[]);


#ifdef __cplusplus
}
#endif

#endif
