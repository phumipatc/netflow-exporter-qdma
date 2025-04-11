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
/****************************************************************************************************************************************************/
/* SECTION: Header includes */
/****************************************************************************************************************************************************/

#include "counter_extern.h"
#include <string.h>
#include <stdio.h>

/****************************************************************************************************************************************************/
/* SECTION: Local function declarations */
/****************************************************************************************************************************************************/

static XilVitisNetP4ReturnType XilVitisNetP4CounterValidateCtx(XilVitisNetP4CounterCtx *CtxPtr);
static XilVitisNetP4ReturnType XilVitisNetP4CounterValidateConfig(XilVitisNetP4CounterConfig *ConfigPtr);
static XilVitisNetP4ReturnType XilVitisNetP4CounterValidateIndex(XilVitisNetP4CounterCtx *CtxPtr, uint32_t Index);
static XilVitisNetP4ReturnType XilVitisNetP4CounterValidateSimpleMode(XilVitisNetP4CounterCtx *CtxPtr);
static XilVitisNetP4ReturnType XilVitisNetP4CounterValidateComboMode(XilVitisNetP4CounterCtx *CtxPtr);
static XilVitisNetP4ReturnType XilVitisNetP4CounterValidatePacketCount(uint64_t PacketCount);
static XilVitisNetP4ReturnType XilVitisNetP4CounterValidateByteCount(uint64_t ByteCount);
static XilVitisNetP4ReturnType XilVitisNetP4CounterWaitForBurstComplete(XilVitisNetP4CounterCtx *CtxPtr);

/****************************************************************************************************************************************************/
/* SECTION: New Constants */
/****************************************************************************************************************************************************/
#define XIL_VITIS_NET_P4_COUNTER_CONTROL_REG (0x00)
#define XIL_VITIS_NET_P4_COUNTER_STATUS_REG  (0x04)
#define XIL_VITIS_NET_P4_COUNTER_ECC_CTL     (0x08)
#define XIL_VITIS_NET_P4_COUNTER_READ_MODE   (0x0C)
#define XIL_VITIS_NET_P4_COUNTER_SBITTERR_COUNT   (0x10)
#define XIL_VITIS_NET_P4_COUNTER_DBITERR_COUNT   (0x14)
#define XIL_VITIS_NET_P4_COUNTER_WRITE_VALUE_LSB   (0x20)
#define XIL_VITIS_NET_P4_COUNTER_WRITE_VALUE_MSB   (0x24)
#define XIL_VITIS_NET_P4_COUNTER_COLLECTION_RAM   (0x800)


#define XIL_VITIS_NET_P4_COUNTER_BURST_SIZE  (0x80)

#define XIL_VITIS_NET_P4_CONTROL_REG_START_ADDR_MASK (0x0000FFFF)
#define XIL_VITIS_NET_P4_CONTROL_REG_START_ADDR_SHIFT (0)
#define XIL_VITIS_NET_P4_CONTROL_REG_START_SIZE_MASK (0x00FF0000)
#define XIL_VITIS_NET_P4_CONTROL_REG_START_SIZE_SHIFT (16)
#define XIL_VITIS_NET_P4_CONTROL_REG_READ_WRITE_SIZE_MASK (0x01000000)
#define XIL_VITIS_NET_P4_CONTROL_REG_READ_WRITE_SIZE_SHIFT (24)

/****************************************************************************************************************************************************/
/* SECTION: Function definitions */
/****************************************************************************************************************************************************/

XilVitisNetP4ReturnType XilVitisNetP4CounterInit(XilVitisNetP4CounterCtx *CtxPtr, XilVitisNetP4EnvIf *EnvIfPtr, XilVitisNetP4CounterConfig *ConfigPtr)
{
    XilVitisNetP4ReturnType Result;

    /* Check input parameters */
    if (CtxPtr == NULL)
    {
        return XIL_VITIS_NET_P4_GENERAL_ERR_NULL_PARAM;
    }

    Result = XilVitisNetP4ValidateEnvIf(EnvIfPtr);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    Result = XilVitisNetP4CounterValidateConfig(ConfigPtr);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    /* Initialise context pointer */
    CtxPtr->EnvIfPtr = EnvIfPtr;
    memcpy(&(CtxPtr->Config), ConfigPtr, sizeof(XilVitisNetP4CounterConfig));

    return Result;
}

XilVitisNetP4ReturnType XilVitisNetP4CounterReset(XilVitisNetP4CounterCtx *CtxPtr)
{
    XilVitisNetP4ReturnType Result;
    XilVitisNetP4CounterConfig Config;
    XilVitisNetP4EnvIf *EnvIfPtr;
    XilVitisNetP4AddressType BaseAddr;
    uint32_t NumCounters;

    //printf("XilVitisNetP4CounterReset\n");
    /* Check input parameters */
    Result = XilVitisNetP4CounterValidateCtx(CtxPtr);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    Config = CtxPtr->Config;
    EnvIfPtr = CtxPtr->EnvIfPtr;
    BaseAddr = Config.BaseAddr;
    NumCounters = Config.NumCounters;


    /* Setup write data registers to zero */

    Result = EnvIfPtr->WordWrite32(EnvIfPtr, (BaseAddr + XIL_VITIS_NET_P4_COUNTER_WRITE_VALUE_LSB), 0);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    Result = EnvIfPtr->WordWrite32(EnvIfPtr, (BaseAddr + XIL_VITIS_NET_P4_COUNTER_WRITE_VALUE_MSB), 0);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    /* Loop through all counters and set them equal to zero */
    /* Write data to the Data registers */

    uint16_t start_address = 0x0;
    uint16_t increment = 0x80;
    uint32_t remaining = NumCounters;

        //64 1-bit counters in each address
    while (remaining > 0)
    {
        /* Write Index value to the Address register */
        uint32_t size =  (remaining >= XIL_VITIS_NET_P4_COUNTER_BURST_SIZE) ? XIL_VITIS_NET_P4_COUNTER_BURST_SIZE : remaining;
        size -= 1;

        uint32_t ctrl = (start_address & XIL_VITIS_NET_P4_CONTROL_REG_START_ADDR_MASK) | \
            ((size << XIL_VITIS_NET_P4_CONTROL_REG_START_SIZE_SHIFT) & XIL_VITIS_NET_P4_CONTROL_REG_START_SIZE_MASK) | \
            ((0x1  << XIL_VITIS_NET_P4_CONTROL_REG_READ_WRITE_SIZE_SHIFT) & XIL_VITIS_NET_P4_CONTROL_REG_READ_WRITE_SIZE_MASK);

        Result = EnvIfPtr->WordWrite32(EnvIfPtr, (BaseAddr + XIL_VITIS_NET_P4_COUNTER_CONTROL_REG),
                                       ctrl);
        if (Result != XIL_VITIS_NET_P4_SUCCESS)
        {
            return Result;
        }


        Result = XilVitisNetP4CounterWaitForBurstComplete(CtxPtr);
        if (Result != XIL_VITIS_NET_P4_SUCCESS)
        {
            return Result;
        }
        if (remaining >= increment)
            remaining -= increment;
        else
            remaining = 0;
        start_address += increment;
    }

    return Result;
}

XilVitisNetP4ReturnType XilVitisNetP4CounterSimpleWrite(XilVitisNetP4CounterCtx *CtxPtr, uint32_t Index, uint64_t Value)
{
    XilVitisNetP4ReturnType Result;
    XilVitisNetP4CounterConfig Config;
    XilVitisNetP4EnvIf *EnvIfPtr;
    XilVitisNetP4AddressType BaseAddr;

    /* Check input parameters */
    Result = XilVitisNetP4CounterValidateCtx(CtxPtr);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    Result = XilVitisNetP4CounterValidateIndex(CtxPtr, Index);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    Result = XilVitisNetP4CounterValidateSimpleMode(CtxPtr);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    Config = CtxPtr->Config;
    EnvIfPtr = CtxPtr->EnvIfPtr;
    BaseAddr = Config.BaseAddr;

    Result = EnvIfPtr->WordWrite32(EnvIfPtr, (BaseAddr + XIL_VITIS_NET_P4_COUNTER_WRITE_VALUE_LSB), (uint32_t)Value);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    Result = EnvIfPtr->WordWrite32(EnvIfPtr, (BaseAddr + XIL_VITIS_NET_P4_COUNTER_WRITE_VALUE_MSB), (uint32_t) (Value >> 32));
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    uint32_t ctrl = (Index & XIL_VITIS_NET_P4_CONTROL_REG_START_ADDR_MASK) | \
        ((0x0 << XIL_VITIS_NET_P4_CONTROL_REG_START_SIZE_SHIFT) & XIL_VITIS_NET_P4_CONTROL_REG_START_SIZE_MASK) | \
        ((0x1  << XIL_VITIS_NET_P4_CONTROL_REG_READ_WRITE_SIZE_SHIFT) & XIL_VITIS_NET_P4_CONTROL_REG_READ_WRITE_SIZE_MASK);

    Result = EnvIfPtr->WordWrite32(EnvIfPtr, (BaseAddr + XIL_VITIS_NET_P4_COUNTER_CONTROL_REG),
                                   ctrl);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    Result = XilVitisNetP4CounterWaitForBurstComplete(CtxPtr);

    return Result;
}

XilVitisNetP4ReturnType XilVitisNetP4CounterSimpleRead(XilVitisNetP4CounterCtx *CtxPtr, uint32_t Index, uint64_t *ValuePtr)
{
    XilVitisNetP4ReturnType Result;
    XilVitisNetP4CounterConfig Config;
    XilVitisNetP4EnvIf *EnvIfPtr;
    XilVitisNetP4AddressType BaseAddr;
    uint32_t ReadValue32Bit = 0;
    uint64_t ReadValue64Bit = 0;

    //printf("XilVitisNetP4CounterSimpleRead\n");
    /* Check input parameters */
    Result = XilVitisNetP4CounterValidateCtx(CtxPtr);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    Result = XilVitisNetP4CounterValidateIndex(CtxPtr, Index);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    Result = XilVitisNetP4CounterValidateSimpleMode(CtxPtr);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    if (ValuePtr == NULL)
    {
        return XIL_VITIS_NET_P4_GENERAL_ERR_NULL_PARAM;
    }

    Config = CtxPtr->Config;
    EnvIfPtr = CtxPtr->EnvIfPtr;
    BaseAddr = Config.BaseAddr;

    uint32_t ctrl = (Index & XIL_VITIS_NET_P4_CONTROL_REG_START_ADDR_MASK) | \
        ((0x0 << XIL_VITIS_NET_P4_CONTROL_REG_START_SIZE_SHIFT) & XIL_VITIS_NET_P4_CONTROL_REG_START_SIZE_MASK) | \
        ((0x0  << XIL_VITIS_NET_P4_CONTROL_REG_READ_WRITE_SIZE_SHIFT) & XIL_VITIS_NET_P4_CONTROL_REG_READ_WRITE_SIZE_MASK);

    Result = EnvIfPtr->WordWrite32(EnvIfPtr, (BaseAddr + XIL_VITIS_NET_P4_COUNTER_CONTROL_REG),
                                   ctrl);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    Result = XilVitisNetP4CounterWaitForBurstComplete(CtxPtr);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }


    /* Read data from the Data register Counter[63:32] */
    Result = EnvIfPtr->WordRead32(EnvIfPtr, (BaseAddr + XIL_VITIS_NET_P4_COUNTER_COLLECTION_RAM+0x4), &ReadValue32Bit);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    /* Cast the read data (Counter[31:0]) to a uint64_t type */
    ReadValue64Bit = ReadValue32Bit;

    /* Left shift the read data To allign with the MSB */
    ReadValue64Bit <<= XIL_VITIS_NET_P4_BITS_PER_REG;

    /* Read data from the Data register Counter[31:0] */
    Result = EnvIfPtr->WordRead32(EnvIfPtr, (BaseAddr + XIL_VITIS_NET_P4_COUNTER_COLLECTION_RAM), &ReadValue32Bit); // Counter[63:32]
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    /* Combine both read values into ReadValue64Bit */
    ReadValue64Bit |= ReadValue32Bit;

    *ValuePtr = ReadValue64Bit;

    return Result;
}

XilVitisNetP4ReturnType XilVitisNetP4CounterComboWrite(XilVitisNetP4CounterCtx *CtxPtr, uint32_t Index, uint64_t PacketCount, uint64_t ByteCount)
{
    XilVitisNetP4ReturnType Result;
    XilVitisNetP4CounterConfig Config;
    XilVitisNetP4EnvIf *EnvIfPtr;
    XilVitisNetP4AddressType BaseAddr;
    uint32_t WriteData = 0;

    /* Check input parameters */
    Result = XilVitisNetP4CounterValidateCtx(CtxPtr);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    Result = XilVitisNetP4CounterValidateIndex(CtxPtr, Index);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    Result = XilVitisNetP4CounterValidateComboMode(CtxPtr);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    Result = XilVitisNetP4CounterValidatePacketCount(PacketCount);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    Result = XilVitisNetP4CounterValidateByteCount(ByteCount);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    Config = CtxPtr->Config;
    EnvIfPtr = CtxPtr->EnvIfPtr;
    BaseAddr = Config.BaseAddr;

    /* ByteCount is written to Counter[34:0]
     * PacketCount is written to Counter[63:35] */

    WriteData = (uint32_t)ByteCount;
    Result = EnvIfPtr->WordWrite32(EnvIfPtr, (BaseAddr + XIL_VITIS_NET_P4_COUNTER_WRITE_VALUE_LSB), (uint32_t)WriteData);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    /* Left shift to align to MSB */
    PacketCount <<= XIL_VITIS_NET_P4_COMBO_PACKET_COUNT_SHIFT;

    /* Right shift to get bits [63:32] */
    ByteCount >>= XIL_VITIS_NET_P4_BITS_PER_REG;

    /* Concatinate values */
    WriteData = (ByteCount|PacketCount);

    Result = EnvIfPtr->WordWrite32(EnvIfPtr, (BaseAddr + XIL_VITIS_NET_P4_COUNTER_WRITE_VALUE_MSB), (uint32_t) WriteData);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    /* Write to Counter[63:32] */
    uint32_t ctrl = (Index & XIL_VITIS_NET_P4_CONTROL_REG_START_ADDR_MASK) | \
        ((0x0 << XIL_VITIS_NET_P4_CONTROL_REG_START_SIZE_SHIFT) & XIL_VITIS_NET_P4_CONTROL_REG_START_SIZE_MASK) | \
        ((0x1  << XIL_VITIS_NET_P4_CONTROL_REG_READ_WRITE_SIZE_SHIFT) & XIL_VITIS_NET_P4_CONTROL_REG_READ_WRITE_SIZE_MASK);

    Result = EnvIfPtr->WordWrite32(EnvIfPtr, (BaseAddr + XIL_VITIS_NET_P4_COUNTER_CONTROL_REG),
                                   ctrl);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    Result = XilVitisNetP4CounterWaitForBurstComplete(CtxPtr);

    return Result;
}

XilVitisNetP4ReturnType XilVitisNetP4CounterComboRead(XilVitisNetP4CounterCtx *CtxPtr, uint32_t Index, uint64_t *PacketCountPtr, uint64_t *ByteCountPtr)
{
    XilVitisNetP4ReturnType Result;
    XilVitisNetP4CounterConfig Config;
    XilVitisNetP4EnvIf *EnvIfPtr;
    XilVitisNetP4AddressType BaseAddr;
    uint64_t ByteCount = 0;
    uint64_t PacketCount = 0;
    uint32_t ReadData = 0;
    uint32_t Mask = (1 << XIL_VITIS_NET_P4_COMBO_PACKET_COUNT_SHIFT) - 1;

    /* Check input parameters */
    Result = XilVitisNetP4CounterValidateCtx(CtxPtr);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    Result = XilVitisNetP4CounterValidateIndex(CtxPtr, Index);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    Result = XilVitisNetP4CounterValidateComboMode(CtxPtr);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    if ((PacketCountPtr == NULL) || (ByteCountPtr == NULL))
    {
        return XIL_VITIS_NET_P4_GENERAL_ERR_NULL_PARAM;
    }

    Config = CtxPtr->Config;
    EnvIfPtr = CtxPtr->EnvIfPtr;
    BaseAddr = Config.BaseAddr;

    /* Write to Counter[63:32] */
    uint32_t ctrl = (Index & XIL_VITIS_NET_P4_CONTROL_REG_START_ADDR_MASK) | \
        ((0x0 << XIL_VITIS_NET_P4_CONTROL_REG_START_SIZE_SHIFT) & XIL_VITIS_NET_P4_CONTROL_REG_START_SIZE_MASK) | \
        ((0x0  << XIL_VITIS_NET_P4_CONTROL_REG_READ_WRITE_SIZE_SHIFT) & XIL_VITIS_NET_P4_CONTROL_REG_READ_WRITE_SIZE_MASK);

    Result = EnvIfPtr->WordWrite32(EnvIfPtr, (BaseAddr + XIL_VITIS_NET_P4_COUNTER_CONTROL_REG),
                                   ctrl);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    Result = XilVitisNetP4CounterWaitForBurstComplete(CtxPtr);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }


    /* Read data from data register (Counter[63:32]) */
    Result = EnvIfPtr->WordRead32(EnvIfPtr, (BaseAddr + XIL_VITIS_NET_P4_COUNTER_COLLECTION_RAM+0x4), &ReadData);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    /* PacketCount is Counter[63:35]
     * ByteCount is Counter[34:0] */

    /* Counter[63:35] - Shift right to remove least significant 3 bits and to allign to LSB */
    PacketCount = ReadData >> XIL_VITIS_NET_P4_COMBO_PACKET_COUNT_SHIFT;

    /* Counter[34:32] - Assign and mask least significant three bits */
    ByteCount = ReadData & Mask;

    /* Read data from data register (Counter[31:0]) */
    Result = EnvIfPtr->WordRead32(EnvIfPtr, (BaseAddr + XIL_VITIS_NET_P4_COUNTER_COLLECTION_RAM), &ReadData); // Counter[31:0]
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    ByteCount <<= XIL_VITIS_NET_P4_BITS_PER_REG;

    /* ( (Counter[34:32] << 32) | Counter[31:0] ) */
    ByteCount |= ReadData;

    *PacketCountPtr = PacketCount;
    *ByteCountPtr   = ByteCount;

    return Result;
}

XilVitisNetP4ReturnType XilVitisNetP4CounterExit(XilVitisNetP4CounterCtx *CtxPtr)
{
    XilVitisNetP4ReturnType Result;

    /* Check input parameters */
    Result = XilVitisNetP4CounterValidateCtx(CtxPtr);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    /* Set the contents of the context structure to zero and thus, the pointer is invalid for use */
    memset(CtxPtr, 0, sizeof(XilVitisNetP4CounterCtx));

    return Result;
}

/****************************************************************************************************************************************************/
/* SECTION: Static local function definitions */
/****************************************************************************************************************************************************/

static XilVitisNetP4ReturnType XilVitisNetP4CounterValidateCtx(XilVitisNetP4CounterCtx *CtxPtr)
{
    XilVitisNetP4ReturnType Result = XIL_VITIS_NET_P4_SUCCESS;

    if (CtxPtr == NULL)
    {
        Result = XIL_VITIS_NET_P4_GENERAL_ERR_NULL_PARAM;
    }

    if (Result == XIL_VITIS_NET_P4_SUCCESS)
    {
        Result = XilVitisNetP4ValidateEnvIf(CtxPtr->EnvIfPtr);
        if (Result != XIL_VITIS_NET_P4_SUCCESS)
        {
            Result = XIL_VITIS_NET_P4_GENERAL_ERR_INVALID_CONTEXT;
        }
    }

    return Result;
}

static XilVitisNetP4ReturnType XilVitisNetP4CounterValidateConfig(XilVitisNetP4CounterConfig *ConfigPtr)
{
    XilVitisNetP4ReturnType Result = XIL_VITIS_NET_P4_SUCCESS;

    /* Initial parameter validation */
    if (ConfigPtr == NULL)
    {
        return XIL_VITIS_NET_P4_GENERAL_ERR_NULL_PARAM;
    }
    /* Validate that each platform-specific function points somewhere - the CounterType and BaseAddr are omitted since NULL is potentially valid */
    if ((ConfigPtr->NumCounters) == 0)
    {
        return XIL_VITIS_NET_P4_COUNTER_ERR_CONFIG_INVALID_NUM_COUNTERS;
    }
    /* Validate that the enumeration input is within the given bounds*/
    switch (ConfigPtr->CounterType)
    {
        case XIL_VITIS_NET_P4_COUNTER_FLAG:
        case XIL_VITIS_NET_P4_COUNTER_PACKETS:
        case XIL_VITIS_NET_P4_COUNTER_BYTES:
        case XIL_VITIS_NET_P4_COUNTER_PACKETS_AND_BYTES:
            /* A valid Counter Type has been found. Break. */
            break;
        default:
            return XIL_VITIS_NET_P4_COUNTER_ERR_CONFIG_INVALID_MODE;
    }

    return Result;
}

static XilVitisNetP4ReturnType XilVitisNetP4CounterValidateIndex(XilVitisNetP4CounterCtx *CtxPtr, uint32_t Index)
{
    XilVitisNetP4ReturnType Result = XIL_VITIS_NET_P4_SUCCESS;
    XilVitisNetP4CounterConfig Config;
    uint32_t NumCounters;

    Config = CtxPtr->Config;
    NumCounters = Config.NumCounters;


    if(Index >= NumCounters)
    {
        return XIL_VITIS_NET_P4_COUNTER_ERR_INVALID_INDEX;
    }

    return Result;
}

static XilVitisNetP4ReturnType XilVitisNetP4CounterValidateSimpleMode(XilVitisNetP4CounterCtx *CtxPtr)
{
    XilVitisNetP4ReturnType Result = XIL_VITIS_NET_P4_SUCCESS;
    XilVitisNetP4CounterConfig Config;
    XilVitisNetP4CounterType CounterType;

    Config = CtxPtr->Config;
    CounterType = Config.CounterType;

    if((CounterType != XIL_VITIS_NET_P4_COUNTER_PACKETS) && (CounterType != XIL_VITIS_NET_P4_COUNTER_BYTES))
    {
        return XIL_VITIS_NET_P4_COUNTER_ERR_CONFIG_UNSUPPORTED_OPERATION;
    }

    return Result;
}

static XilVitisNetP4ReturnType XilVitisNetP4CounterValidateComboMode(XilVitisNetP4CounterCtx *CtxPtr)
{
    XilVitisNetP4ReturnType Result = XIL_VITIS_NET_P4_SUCCESS;
    XilVitisNetP4CounterConfig Config;
    XilVitisNetP4CounterType CounterType;

    Config = CtxPtr->Config;
    CounterType = Config.CounterType;

    if(CounterType != XIL_VITIS_NET_P4_COUNTER_PACKETS_AND_BYTES)
    {
        return XIL_VITIS_NET_P4_COUNTER_ERR_CONFIG_UNSUPPORTED_OPERATION;
    }

    return Result;
}

static XilVitisNetP4ReturnType XilVitisNetP4CounterValidatePacketCount(uint64_t PacketCount)
{
    XilVitisNetP4ReturnType Result = XIL_VITIS_NET_P4_SUCCESS;

    if(PacketCount > XIL_VITIS_NET_P4_COMBO_PACKET_COUNT_MAX)
    {
        return XIL_VITIS_NET_P4_COUNTER_ERR_INVALID_PACKET_COUNT;
    }

    return Result;
}

static XilVitisNetP4ReturnType XilVitisNetP4CounterValidateByteCount(uint64_t ByteCount)
{
    XilVitisNetP4ReturnType Result = XIL_VITIS_NET_P4_SUCCESS;

    if(ByteCount > XIL_VITIS_NET_P4_COMBO_BYTE_COUNT_MAX)
    {
        return XIL_VITIS_NET_P4_COUNTER_ERR_INVALID_BYTE_COUNT;
    }

    return Result;
}

static XilVitisNetP4ReturnType XilVitisNetP4CounterWaitForBurstComplete(XilVitisNetP4CounterCtx *CtxPtr)
{
    XilVitisNetP4CounterConfig Config;
    XilVitisNetP4EnvIf *EnvIfPtr;
    XilVitisNetP4AddressType BaseAddr;

    Config = CtxPtr->Config;
    EnvIfPtr = CtxPtr->EnvIfPtr;
    BaseAddr = Config.BaseAddr;

    XilVitisNetP4ReturnType Result = XIL_VITIS_NET_P4_SUCCESS;
    bool BurstInProgress = true;
    uint32_t ReadData = 0;
    while(BurstInProgress)
    {
        Result = EnvIfPtr->WordRead32(EnvIfPtr, (BaseAddr + XIL_VITIS_NET_P4_COUNTER_STATUS_REG), &ReadData); // Counter[31:0]
        if (Result != XIL_VITIS_NET_P4_SUCCESS)
        {
            return Result;
        }
        if (!(ReadData & 0x1))
            BurstInProgress = false;
    }
    return(Result);
}

XilVitisNetP4ReturnType XilVitisNetP4CounterCollectRead(XilVitisNetP4CounterCtx *CtxPtr, uint32_t Index, uint32_t NumCounters, uint64_t *ValuePtr)
{
    XilVitisNetP4CounterConfig Config;
    XilVitisNetP4EnvIf *EnvIfPtr;
    XilVitisNetP4AddressType BaseAddr;
    XilVitisNetP4ReturnType Result = XIL_VITIS_NET_P4_SUCCESS;
    uint32_t ReadValue32Bit = 0;
    uint64_t ReadValue64Bit = 0ULL;

    Config = CtxPtr->Config;
    EnvIfPtr = CtxPtr->EnvIfPtr;
    BaseAddr = Config.BaseAddr;

    Result = XilVitisNetP4CounterValidateIndex(CtxPtr, Index);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    if(NumCounters > Config.NumCounters - Index)
    {
        return XIL_VITIS_NET_P4_COUNTER_ERR_CONFIG_INVALID_NUM_COUNTERS;
    }
    /* Loop through all counters and write them to address at ValuePtr */

    uint16_t start_address = Index;
    uint16_t increment = 0x80;
    uint32_t remaining = NumCounters;
    uint64_t *DataPtr = ValuePtr;
    while (remaining > 0)
    {
        /* Write Index value to the Address register */
        uint32_t size =  (remaining >= XIL_VITIS_NET_P4_COUNTER_BURST_SIZE) ? XIL_VITIS_NET_P4_COUNTER_BURST_SIZE : remaining;
        size -= 1;

        uint32_t ctrl = (start_address & XIL_VITIS_NET_P4_CONTROL_REG_START_ADDR_MASK) | \
            ((size << XIL_VITIS_NET_P4_CONTROL_REG_START_SIZE_SHIFT) & XIL_VITIS_NET_P4_CONTROL_REG_START_SIZE_MASK) | \
            ((0x0  << XIL_VITIS_NET_P4_CONTROL_REG_READ_WRITE_SIZE_SHIFT) & XIL_VITIS_NET_P4_CONTROL_REG_READ_WRITE_SIZE_MASK);

        Result = EnvIfPtr->WordWrite32(EnvIfPtr, (BaseAddr + XIL_VITIS_NET_P4_COUNTER_CONTROL_REG),
                                       ctrl);
        if (Result != XIL_VITIS_NET_P4_SUCCESS)
        {
            return Result;
        }


        Result = XilVitisNetP4CounterWaitForBurstComplete(CtxPtr);
        if (Result != XIL_VITIS_NET_P4_SUCCESS)
        {
            return Result;
        }


        for(uint32_t i = 0; i <size + 1; i++)
        {
            /* Read data from the Data register Counter[63:32] */
            Result = EnvIfPtr->WordRead32(EnvIfPtr, (BaseAddr + XIL_VITIS_NET_P4_COUNTER_COLLECTION_RAM+i*0x8+0x4), &ReadValue32Bit);
            if (Result != XIL_VITIS_NET_P4_SUCCESS)
            {
                return Result;
            }

            /* Cast the read data (Counter[31:0]) to a uint64_t type */
            ReadValue64Bit = ReadValue32Bit;

            /* Left shift the read data To allign with the MSB */
            ReadValue64Bit <<= XIL_VITIS_NET_P4_BITS_PER_REG;

            /* Read data from the Data register Counter[31:0] */
            Result = EnvIfPtr->WordRead32(EnvIfPtr, (BaseAddr + XIL_VITIS_NET_P4_COUNTER_COLLECTION_RAM+i*0x8), &ReadValue32Bit); // Counter[63:32]
            if (Result != XIL_VITIS_NET_P4_SUCCESS)
            {
                return Result;
            }

            /* Combine both read values into ReadValue64Bit */
            ReadValue64Bit |= ReadValue32Bit;
            *DataPtr =  ReadValue64Bit;
            DataPtr++;
        }

        if (remaining >= increment)
            remaining -= increment;
        else
            remaining = 0;
        start_address += increment;
    }

    return(Result);
}

XilVitisNetP4ReturnType XilVitisNetP4CounterCollectComboRead(XilVitisNetP4CounterCtx *CtxPtr,  uint32_t Index, uint32_t NumCounters, uint64_t *Packets, uint64_t *Bytes)
{
    XilVitisNetP4CounterConfig Config;
    XilVitisNetP4EnvIf *EnvIfPtr;
    XilVitisNetP4AddressType BaseAddr;

    XilVitisNetP4ReturnType Result = XIL_VITIS_NET_P4_SUCCESS;
    uint64_t ByteCount = 0;
    uint64_t PacketCount = 0;
    uint32_t ReadData = 0;
    uint32_t Mask = (1 << XIL_VITIS_NET_P4_COMBO_PACKET_COUNT_SHIFT) - 1;

    Config = CtxPtr->Config;
    EnvIfPtr = CtxPtr->EnvIfPtr;
    BaseAddr = Config.BaseAddr;

    Result = XilVitisNetP4CounterValidateIndex(CtxPtr, Index);
    if (Result != XIL_VITIS_NET_P4_SUCCESS)
    {
        return Result;
    }

    if(NumCounters > Config.NumCounters - Index)
    {
        return XIL_VITIS_NET_P4_COUNTER_ERR_CONFIG_INVALID_NUM_COUNTERS;
    }

    /* Loop through all counters and write them to address at ValuePtr */
    uint16_t start_address = Index;
    uint16_t increment = 0x80;
    uint32_t remaining = NumCounters;
    while (remaining > 0)
    {
        /* Write Index value to the Address register */
        uint32_t size =  (remaining >= XIL_VITIS_NET_P4_COUNTER_BURST_SIZE) ? XIL_VITIS_NET_P4_COUNTER_BURST_SIZE : remaining;
        size -= 1;

        uint32_t ctrl = (start_address & XIL_VITIS_NET_P4_CONTROL_REG_START_ADDR_MASK) | \
            ((size << XIL_VITIS_NET_P4_CONTROL_REG_START_SIZE_SHIFT) & XIL_VITIS_NET_P4_CONTROL_REG_START_SIZE_MASK) | \
            ((0x0  << XIL_VITIS_NET_P4_CONTROL_REG_READ_WRITE_SIZE_SHIFT) & XIL_VITIS_NET_P4_CONTROL_REG_READ_WRITE_SIZE_MASK);

        Result = EnvIfPtr->WordWrite32(EnvIfPtr, (BaseAddr + XIL_VITIS_NET_P4_COUNTER_CONTROL_REG),
                                       ctrl);
        if (Result != XIL_VITIS_NET_P4_SUCCESS)
        {
            return Result;
        }


        Result = XilVitisNetP4CounterWaitForBurstComplete(CtxPtr);
        if (Result != XIL_VITIS_NET_P4_SUCCESS)
        {
            return Result;
        }


        for(uint32_t i = 0; i <size + 1; i++)
        {
            /* Read data from the Data register Counter[63:32] */
            Result = EnvIfPtr->WordRead32(EnvIfPtr, (BaseAddr + XIL_VITIS_NET_P4_COUNTER_COLLECTION_RAM+i*0x8+0x4), &ReadData);
            if (Result != XIL_VITIS_NET_P4_SUCCESS)
            {
                return Result;
            }
            /* PacketCount is Counter[63:35]
             * ByteCount is Counter[34:0] */

            /* Counter[63:35] - Shift right to remove least significant 3 bits and to allign to LSB */
            PacketCount = ReadData >> XIL_VITIS_NET_P4_COMBO_PACKET_COUNT_SHIFT;

            /* Counter[34:32] - Assign and mask least significant three bits */
            ByteCount = ReadData & Mask;

            /* Read data from the Data register Counter[31:0] */
            Result = EnvIfPtr->WordRead32(EnvIfPtr, (BaseAddr + XIL_VITIS_NET_P4_COUNTER_COLLECTION_RAM+i*0x8), &ReadData); // Counter[63:32]
            if (Result != XIL_VITIS_NET_P4_SUCCESS)
            {
                return Result;
            }

            ByteCount <<= XIL_VITIS_NET_P4_BITS_PER_REG;

            /* ( (Counter[34:32] << 32) | Counter[31:0] ) */
            ByteCount |= ReadData;

            *Packets = PacketCount;
            *Bytes   = ByteCount;

            Packets++;
            Bytes++;
        }

        if (remaining >= increment)
            remaining -= increment;
        else
            remaining = 0;
        start_address += increment;
    }

    return(Result);
}
