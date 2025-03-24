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
 * Public API of the Counter Extern.
 *
 * @file counter_extern.h
 *
 * $Id: //IP3/REL/2023.2.1/hw/vitis_net_p4/vitis_net_p4_v2_0/src/sw/drivers/counter/inc/counter_extern.h#1 $
 *
 * @addtogroup counter COUNTER EXTERN Public API
 * @{
 */

#ifndef COUNTER_EXTERN_H
#define COUNTER_EXTERN_H

/****************************************************************************************************************************************************/
/* SECTION: Header includes */
/****************************************************************************************************************************************************/

#include "vitisnetp4_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************************************************************************************/
/* SECTION: Constants */
/****************************************************************************************************************************************************/

#define XIL_VITIS_NET_P4_COMBO_PACKET_COUNT_SIZE_BITS    (29)
#define XIL_VITIS_NET_P4_COMBO_BYTE_COUNT_SIZE_BITS      (35)

#define XIL_VITIS_NET_P4_COMBO_PACKET_COUNT_MAX    ((1UL << XIL_VITIS_NET_P4_COMBO_PACKET_COUNT_SIZE_BITS) - 1)
#define XIL_VITIS_NET_P4_COMBO_BYTE_COUNT_MAX      ((1UL << XIL_VITIS_NET_P4_COMBO_BYTE_COUNT_SIZE_BITS) - 1)

#define XIL_VITIS_NET_P4_COMBO_PACKET_COUNT_SHIFT  (XIL_VITIS_NET_P4_BITS_PER_REG - XIL_VITIS_NET_P4_COMBO_PACKET_COUNT_SIZE_BITS)

/****************************************************************************************************************************************************/
/* SECTION: Type definitions */
/****************************************************************************************************************************************************/

/**
 * Counter Extern Type enumeration
 * Contains the counter type settings for the Counter Extern instance (Flag/Simple/Combo).
 *
 */
typedef enum XilVitisNetP4CounterType
{
    XIL_VITIS_NET_P4_COUNTER_PACKETS,           /**< Packet Mode*/
    XIL_VITIS_NET_P4_COUNTER_BYTES,             /**< Byte Mode*/
    XIL_VITIS_NET_P4_COUNTER_PACKETS_AND_BYTES, /**< Packets and Bytes mode*/
    XIL_VITIS_NET_P4_COUNTER_FLAG,              /**< Flag Mode*/
    XIL_VITIS_NET_P4_NUM_COUNTER_TYPES          /**< Number of counter types*/
} XilVitisNetP4CounterType;

/**
 * Counter Extern Config structure
 * Contains the configuration settings for the Counter Extern instance.
 *
 */
typedef struct XilVitisNetP4CounterConfig
{
    XilVitisNetP4AddressType BaseAddr;       /**< Base Address of the Counter Extern instance*/
    XilVitisNetP4CounterType CounterType;    /**< Type of Counter (Flag/Simple/Combo)*/
    uint32_t            NumCounters;         /**< Number of counter entries in the Counter Extern instance*/
    uint32_t            Width;               /**< Width of counter entries in the counter extern instance*/
} XilVitisNetP4CounterConfig;

/**
 * Counter Extern Context structure
 * Contains nessessary information regarding the Counter Extern instance.
 *
 */
typedef struct XilVitisNetP4CounterCtx
{
    XilVitisNetP4EnvIf           *EnvIfPtr;  /**< Pointer to the Device interface (Read/write functions)*/
    XilVitisNetP4CounterConfig   Config;     /**< Configuration settings for the counter extern instance*/
} XilVitisNetP4CounterCtx;

/****************************************************************************************************************************************************/
/* SECTION: Global function prototypes */
/****************************************************************************************************************************************************/

/**
 * XilVitisNetP4CounterInit function
 * Initialisation function to allocate memory and populate the members of CtxPtr.
 *
 * If the function was successful, 0 is returned. If the function fails an error code is returned.
 *
 * @param[in]  CtxPtr           Pointer to an empty Counter Extern context structure.
 *
 * @param[in]  EnvIfPtr         Pointer to EnvIfPtr.
 *                              Contains pointers to read/write functions and user context.
 *
 * @param[in]  ConfigPtr        Pointer to ConfigPtr.
 *                              Contains base address, counter type and number of counter entries.
 *
 * @param[out]  CtxPtr          The newly populated CtxPtr.
 *                              If successful, memory was allocated and context members populated with meaningful data.
 *                              If unsuccesful, no memory was allocated and CtxPtr is left unchagned.
 *
 */
XilVitisNetP4ReturnType XilVitisNetP4CounterInit(XilVitisNetP4CounterCtx *CtxPtr, XilVitisNetP4EnvIf *EnvIfPtr, XilVitisNetP4CounterConfig *ConfigPtr);

/**
 * XilVitisNetP4CounterReset function
 * Resets all counter entries saved to CtxPtr.
 *
 * If the function was successful, 0 is returned. If the function fails an error code is returned.
 *
 * @param[in]  CtxPtr           Pointer to Counter Extern context structure which has been initialised.
 *
 * @param[out]  CtxPtr          CtxPtr which has been cleared.
 *                              If successful, all counter entries data registers will be set to zero.
 *                              If unsuccesful, an error code is returned.
 *
 */
XilVitisNetP4ReturnType XilVitisNetP4CounterReset(XilVitisNetP4CounterCtx *CtxPtr);

/**
 * XilVitisNetP4CounterSimpleWrite function
 * Function to write data to an indexed counter entry when it is in Simple mode.
 *
 * If the function was successful, 0 is returned. If the function fails an error code is returned.
 *
 * @param[in]  CtxPtr           Pointer to Counter Extern context structure which has been initialised.
 *
 * @param[in]  Index            Represents the index of the counter entry in the Counter Extern context structure.
 *
 * @param[in]  Value            Represents the 64 bits of data to be written to the indexed counter entry data registers.
 *
 * @param[out]  CtxPtr          If successful, the intexed counter entry data registers will be allocated the value saved in input variable Value.
 *                              If unsuccesful, an error code is returned.
 *
 */
XilVitisNetP4ReturnType XilVitisNetP4CounterSimpleWrite(XilVitisNetP4CounterCtx *CtxPtr, uint32_t Index, uint64_t Value);

/**
 * XilVitisNetP4CounterSimpleRead function
 * Function to read data from an indexed counter entry when it is in Simple mode.
 *
 * If the function was successful, 0 is returned. If the function fails an error code is returned.
 *
 * @param[in]  CtxPtr           Pointer to Counter Extern context structure which has been initialised.
 *
 * @param[in]  Index            Represents the index of the counter entry in the Counter Extern context structure.
 *
 * @param[in]  ValuePtr         Pointer to an empty 64-bit variable.
 *
 *
 * @param[out] ValuePtr         If successful, The variable has been populated with the 64 bits of data stored in the indexed counter entry data registers.
 *                              If unsuccesful, an error code is returned.
 *
 */
XilVitisNetP4ReturnType XilVitisNetP4CounterSimpleRead(XilVitisNetP4CounterCtx *CtxPtr, uint32_t Index, uint64_t *ValuePtr);

/**
 * XilVitisNetP4CounterComboWrite function
 * Function to write data to an indexed counter entry when it is in Combo mode.
 *
 * If the function was successful, 0 is returned. If the function fails an error code is returned.
 *
 * @param[in]  CtxPtr           Pointer to Counter Extern context structure which has been initialised.
 *
 * @param[in]  Index            Represents the index of the counter entry in the Counter Extern context structure.
 *
 * @param[in]  PacketCount      Represents packet count value to be written to the indexed counter entry data registers.
 *
 * @param[in]  ByteCount        Represents the byte count value to be written to the indexed counter entry data registers.
 *
 * @param[out]  CtxPtr          If successful, the intexed counter entry data registers will be populated with the packet count and byte count values, in the correct order.
 *                              i.e. Byte count is stored at Counter[34:0] or DataReg1[31:0] and SataReg2[2:0].
 *                                   Packet count is stored at Counter[63:35] or DataReg2[31:3].
 *                              If unsuccesful, an error code is returned.
 *
 */
XilVitisNetP4ReturnType XilVitisNetP4CounterComboWrite(XilVitisNetP4CounterCtx *CtxPtr, uint32_t Index, uint64_t PacketCount, uint64_t ByteCount);

/**
 * XilVitisNetP4CounterComboRead function
 * Function to read data from an indexed counter entry when it is in Combo mode.
 *
 * If the function was successful, 0 is returned. If the function fails an error code is returned.
 *
 * @param[in]  CtxPtr           Pointer to Counter Extern context structure which has been initialised.
 *
 * @param[in]  Index            Represents the index of the counter entry in the Counter Extern context structure.
 *
 * @param[in]  PacketCountPtr   Pointer to an empty 64-bit variable which shall be used to store the packet count.
 *
 * @param[in]  ByteCountPtr     Pointer to an empty 64-bit variable which shall be used to store the byte count.
 *
 * @param[out] ValuePtr         If successful, The PacketCountPtr and ByteCountPtr have been populated with the data stored in the indexed counter entry data registers.
 *                              If unsuccesful, an error code is returned.
 *
 */
XilVitisNetP4ReturnType XilVitisNetP4CounterComboRead(XilVitisNetP4CounterCtx *CtxPtr, uint32_t Index, uint64_t *PacketCountPtr, uint64_t *ByteCountPtr);

/**
 * XilVitisNetP4CounterExit function
 * Exit CtxPtr. The memory allocated to CtxPtr is released and thus, the pointer is invalid for use.
 *
 * If the function was successful, 0 is returned. If the function fails an error code is returned.
 *
 * @param[in]  CtxPtr           Pointer to Counter Extern context structure which has been initialised.
 *
 *
 */
XilVitisNetP4ReturnType XilVitisNetP4CounterExit(XilVitisNetP4CounterCtx *CtxPtr);

/**
 * XilVitisNetP4CounterCollectRead function
 * Exit CtxPtr. The memory allocated to CtxPtr is released and thus, the pointer is invalid for use.
 *
 * If the function was successful, 0 is returned. If the function fails an error code is returned.
 *
 * @param[in]  CtxPtr           Pointer to Counter Extern context structure which has been initialised.
 * @param[out] *ValuePtr        If successful, The ValuePtr have been populated with values of all counters in the array
 *                              If width = 1 then each 64 bit value contains 64 1-bit values
 *                              If unsuccesful, an error code is returned.
 *
 */

XilVitisNetP4ReturnType XilVitisNetP4CounterCollectRead(XilVitisNetP4CounterCtx *CtxPtr,  uint32_t Index, uint32_t NumCounters, uint64_t *ValuePtr);

/**
 * XilVitisNetP4CounterCollectComboRead function
 * Exit CtxPtr. The memory allocated to CtxPtr is released and thus, the pointer is invalid for use.
 *
 * If the function was successful, 0 is returned. If the function fails an error code is returned.
 *
 * @param[in]  CtxPtr           Pointer to Counter Extern context structure which has been initialised.
 * @param[out] *Packets         If successful, The packets will  have been populated with values of all packets counters in the array
 * @param[out] *Bytes         If successful, The packets will  have been populated with values of all Bytes counters in the array*                              If unsuccesful, an error code is returned.
 *
 */

XilVitisNetP4ReturnType XilVitisNetP4CounterCollectComboRead(XilVitisNetP4CounterCtx *CtxPtr,  uint32_t Index, uint32_t NumCounters, uint64_t *Packets, uint64_t *Bytes);

#ifdef __cplusplus
}
#endif

#endif
