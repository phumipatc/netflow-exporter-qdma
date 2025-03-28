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
 * Public control plane definitions for design p4_engine
 */

/****************************************************************************************************************************************************/
/* SECTION: Header guards */
/****************************************************************************************************************************************************/

#ifndef XIL_VITIS_NET_P4_P4_ENGINE_DEFS_H
#define XIL_VITIS_NET_P4_P4_ENGINE_DEFS_H

/****************************************************************************************************************************************************/
/* SECTION: Header includes */
/****************************************************************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#include "vitisnetp4_target.h"

/****************************************************************************************************************************************************/
/* SECTION: Constants */
/****************************************************************************************************************************************************/

extern XilVitisNetP4TargetConfig XilVitisNetP4TargetConfig_p4_engine;

/* Address map */

// Table ipv4_lpm
#define XIL_VITIS_NET_P4_P4_ENGINE_IPV4_LPM_BASEADDR (0x00000000)
#define XIL_VITIS_NET_P4_P4_ENGINE_IPV4_LPM_HIGHADDR (0x00001FFF)

/****************************************************************************************************************************************************/
/* SECTION: End */
/****************************************************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif

/**************************************************************************
 * Machine-generated file - do NOT modify by hand !
 * File created on 08 of March, 2025 @ 17:45:43
 * by VitisNetP4 IP, version v2.0 revision 0
 **************************************************************************/
