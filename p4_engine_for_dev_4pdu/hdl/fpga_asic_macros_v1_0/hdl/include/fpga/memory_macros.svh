// (c) Copyright 2017, 2023 Advanced Micro Devices, Inc. All rights reserved.
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
//
//       Owner:          
//       Description:
//
//////////////////////////////////////////////////////////////////////////////

`ifndef MEMORY_MACROS_SVH_DEFINED
`define MEMORY_MACROS_SVH_DEFINED

// Target FPGA
//`define MEM_MACROS_ASIC_NOT_FPGA

`ifdef MEM_MACROS_ASIC_NOT_FPGA

`define ECC_DATA_WIDTH(width) width;

`define ECC_CTL_FIFO   "en_ecc"
`define ECC_CTL_MEMORY "both_encode_and_decode"

`endif // ifdef MEM_MACROS_ASIC_NOT_FPGA

`ifndef MEM_MACROS_ASIC_NOT_FPGA

`define ECC_DATA_WIDTH(width)((int'(width)/64) + (((width % 64) > 0) ? 1 : 0))*64;

`define ECC_CTL_FIFO   "no_ecc"
`define ECC_CTL_MEMORY "no_ecc"

`endif // ifndef MEM_MACROS_ASIC_NOT_FPGA

`endif // MEMORY_MACROS_SVH_DEFINED

