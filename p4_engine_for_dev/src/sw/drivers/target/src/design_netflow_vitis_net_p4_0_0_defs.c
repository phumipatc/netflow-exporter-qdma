// (c) Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// (c) Copyright 2022-2025 Advanced Micro Devices, Inc. All rights reserved.
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
// 
// DO NOT MODIFY THIS FILE.


/*
 * Public control plane definitions for design design_netflow_vitis_net_p4_0_0
 */

/****************************************************************************************************************************************************/
/* SECTION: Header includes */
/****************************************************************************************************************************************************/

#include "design_netflow_vitis_net_p4_0_0_defs.h"

/****************************************************************************************************************************************************/
/* SECTION: Constants */
/****************************************************************************************************************************************************/

// Action 'NoAction' definition
static XilVitisNetP4Action XilVitisNetP4Action_NoAction =
{
    .NameStringPtr = "NoAction",
    .ParamListSize = 0,
    .ParamListPtr  = NULL
};

// Action 'dropPacket' definition
static XilVitisNetP4Action XilVitisNetP4Action_dropPacket =
{
    .NameStringPtr = "dropPacket",
    .ParamListSize = 0,
    .ParamListPtr  = NULL
};

// Table 'nif_ternary' Action list
static XilVitisNetP4Action *XilVitisNetP4TableActions_nif_ternary[] =
{
    &XilVitisNetP4Action_NoAction,
    &XilVitisNetP4Action_dropPacket
};

// Table 'nif_ternary' definition
static XilVitisNetP4TargetTableConfig XilVitisNetP4TargetTableConfig_nif_ternary =
{
    .NameStringPtr = "nif_ternary",
    .Config        = {
        .Endian            = XIL_VITIS_NET_P4_BIG_ENDIAN,
        .Mode              = XIL_VITIS_NET_P4_TABLE_MODE_TCAM,
        .KeySizeBits       = 48,
        .CamConfig         = {
            .BaseAddr           = XIL_VITIS_NET_P4_DESIGN_NETFLOW_VITIS_NET_P4_0_0_NIF_TERNARY_BASEADDR,
            .FormatStringPtr    = "16t:32p",
            .NumEntries         = 64,
            .RamFrequencyHz     = 325000000,
            .LookupFrequencyHz  = 325000000,
            .LookupsPerSec      = 325000000,
            .ResponseSizeBits   = 1,
            .PrioritySizeBits   = XIL_VITIS_NET_P4_CAM_PRIORITY_SIZE_DEFAULT,
            .NumMasks           = 0,
            .Endian             = XIL_VITIS_NET_P4_BIG_ENDIAN,
            .MemType            = XIL_VITIS_NET_P4_CAM_MEM_BRAM,
            .OptimizationType   = XIL_VITIS_NET_P4_CAM_OPTIMIZE_NONE,
            .RamSizeKbytes      = 0,
            .RamChannelWidth    = 0,
            .RamNumBanks        = 0
        },
        .ActionIdWidthBits = 1,
        .ActionListSize    = 2,
        .ActionListPtr     = &(XilVitisNetP4TableActions_nif_ternary[0])
    }
};

// list of all tables defined in the design
static XilVitisNetP4TargetTableConfig *XilVitisNetP4TableList[] =
{
    &XilVitisNetP4TargetTableConfig_nif_ternary
};


// Top Level VitisNetP4 Configuration
XilVitisNetP4TargetConfig XilVitisNetP4TargetConfig_design_netflow_vitis_net_p4_0_0 =
{
    .Endian          = XIL_VITIS_NET_P4_BIG_ENDIAN,
    .TableListSize   = 1,
    .TableListPtr    = &(XilVitisNetP4TableList[0]),
    .CounterListSize = 0,
    .CounterListPtr  = NULL,
    .BuildInfoPtr    = NULL,
    .InterruptPtr    = NULL,
    .CtrlConfigPtr   = NULL
};

/**************************************************************************
 * Machine-generated file - do NOT modify by hand !
 * File created on 01 of April, 2025 @ 22:36:29
 * by VitisNetP4 IP, version v2.0 revision 0
 **************************************************************************/
