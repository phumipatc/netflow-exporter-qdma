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
//       Owner:          cmcnally         
//       Description:
//
//          Check parameters of MCFH for correctness.
//
//////////////////////////////////////////////////////////////////////////////


// VCS coverage off
`ifndef SYNTHESIS
`ifndef SYNTH

   initial
   begin: CheckParams

      // Key Width
      check_key_width : assert((KEY_WIDTH >= MIN_KEY_WIDTH) && (KEY_WIDTH <= MAX_KEY_WIDTH)) else
            $fatal(1, "### ERROR: KEY_WIDTH should be between %3d and %3d - currently %3d", MIN_KEY_WIDTH, MAX_KEY_WIDTH, KEY_WIDTH); 

      // Number of entries

      // Fingerprint size
      check_fp_size : assert((FP_SIZE == 0) || (FP_SIZE == 2) || (FP_SIZE == 4) || (FP_SIZE == 8) || (FP_SIZE == 16)) else
            $fatal(1, "### ERROR: FP_SIZE should be one of 0,2,4,8,16 - currently %3d", FP_SIZE); 

      // Fingerprint size
      check_local_fp_size : assert((LOCAL_FP_SIZE == 2) || (LOCAL_FP_SIZE == 4) || (LOCAL_FP_SIZE == 8) || (LOCAL_FP_SIZE == 16)) else
            $fatal(1, "### ERROR: Internal calculated LOCAL_FP_SIZE should be one of 2,4,8,16 - currently %3d", LOCAL_FP_SIZE); 

      // Hash Type
      check_hash_type : assert((HASH_TYPE == "siphash") || (HASH_TYPE == "llhash")  || (HASH_TYPE == "mmhash")) else
            $fatal(1, "### ERROR: HASH_TYPE should be \"siphash\" or \"llhash\" or \"mmhash\" - currently %s", HASH_TYPE);

      // SIP C/D
      check_sip_rounds : assert (((SIP_CROUNDS  == 1) && (SIP_DROUNDS == 2)) || ((SIP_CROUNDS  == 1) && (SIP_DROUNDS == 3)) || ((SIP_CROUNDS  == 2) && (SIP_DROUNDS == 4)) 
                                || (HASH_TYPE != "siphash")) else
            $fatal(1, "### ERROR: SIP_CROUNDS/SIP_DROUNDS valid combos are 1/2, 1/3, 2/4 - currently %1d/%1d", SIP_CROUNDS, SIP_DROUNDS);

      // SIP Mode
      check_sip_mode : assert((SIP_MODE == "TURBO") || (SIP_MODE == "STANDARD")) else
            $fatal(1, "### ERROR: SIP_MODE should be \"TURBO\" or \"STANDARD\" - currently %s", SIP_MODE);                      

      // SIP CPH
      check_sip_cph : assert(((SIP_CPH >= MIN_SIP_CPH) && (SIP_CPH <= MAX_SIP_CPH)) || (HASH_TYPE != "siphash")) else
            $fatal(1, "### ERROR: SIP_CPH should be between %3.1f and %3.1f - currently %3.1f", MIN_SIP_CPH, MAX_SIP_CPH, SIP_CPH); 

      // FP BYPASS
      check_fp_bypass : assert((FP_BYPASS == 0) || (FP_BYPASS == 1)) else
            $fatal(1, "### ERROR: FP_BYPASS should be 0 or 1 - currently %d", FP_BYPASS);  

      // Memory Primitive
      check_mem_prim : assert((MEM_PRIM == "auto") || (MEM_PRIM == "block") || (MEM_PRIM == "ultra") || (MEM_PRIM == "dist")) else
            $fatal(1, "### ERROR: MEM_PRIM should be \"auto\" / \"block\" / \"ultra\" / \"dist\" - currently %s", MEM_PRIM); 

      // Memory Primitive
      check_calc_mem_prim : assert((CALC_MEM_PRIM == "block") || (CALC_MEM_PRIM == "ultra") || (CALC_MEM_PRIM == "dist")) else
            $fatal(1, "### ERROR: Internal calculated CALC_MEM_PRIM should be \"block\" / \"ultra\" / \"dist\" - currently %s", CALC_MEM_PRIM); 

      // // Clock Frequency
      // check_clk_freq_hz : assert((CLK_FREQ_HZ == 400000000) || (CLK_FREQ_HZ == 250000000) || (CLK_FREQ_HZ == 300000000)) else
      //       $fatal(1, "### ERROR: CLK_FREQ_HZ should be 400000000 / 300000000 / 250000000 - currently %d", CLK_FREQ_HZ);


   end

`endif
`endif
// VCS coverage on

