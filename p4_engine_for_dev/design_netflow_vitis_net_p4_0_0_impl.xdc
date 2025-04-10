# (c) Copyright 2012, 2023 Advanced Micro Devices, Inc. All rights reserved.
#
# This file contains confidential and proprietary information
# of AMD and is protected under U.S. and international copyright
# and other intellectual property laws.
#
# DISCLAIMER
# This disclaimer is not a license and does not grant any
# rights to the materials distributed herewith. Except as
# otherwise provided in a valid license issued to you by
# AMD, and to the maximum extent permitted by applicable
# law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
# WITH ALL FAULTS, AND AMD HEREBY DISCLAIMS ALL WARRANTIES
# AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
# BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
# INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
# (2) AMD shall not be liable (whether in contract or tort,
# including negligence, or under any other theory of
# liability) for any loss or damage of any kind or nature
# related to, arising under or in connection with these
# materials, including for any direct, or any indirect,
# special, incidental, or consequential loss or damage
# (including loss of data, profits, goodwill, or any type of
# loss or damage suffered as a result of any action brought
# by a third party) even if such damage or loss was
# reasonably foreseeable or AMD had been advised of the
# possibility of the same.
#
# CRITICAL APPLICATIONS
# AMD products are not designed or intended to be fail-
# safe, or for use in any application requiring fail-safe
# performance, such as life-support or safety devices or
# systems, Class III medical devices, nuclear facilities,
# applications related to the deployment of airbags, or any
# other applications that could lead to death, personal
# injury, or severe property or environmental damage
# (individually and collectively, "Critical
# Applications"). Customer assumes the sole risk and
# liability of any use of AMD products in Critical
# Applications, subject only to applicable laws and
# regulations governing limitations on product liability.
#
# THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
# PART OF THIS FILE AT ALL TIMES.
############################################################
# table 'table0_MyProcessing_nif_ternary' Impl constraints
create_macro table0_MyProcessing_nif_ternary_col0
update_macro table0_MyProcessing_nif_ternary_col0 {{match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[0].CL.C/R[0].M.R/R/KM[0].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y15 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[0].CL.C/R[0].M.R/R/KM[2].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y16 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[0].CL.C/R[0].M.R/R/KM[1].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y17 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[0].CL.C/R[1].M.R/R/KM[0].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y18 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[0].CL.C/R[1].M.R/R/KM[2].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y19 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[0].CL.C/R[1].M.R/R/KM[1].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y20 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[0].CL.C/R[2].M.R/R/KM[0].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y21 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[0].CL.C/R[2].M.R/R/KM[2].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y22 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[0].CL.C/R[2].M.R/R/KM[1].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y23 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[0].CL.C/R[3].M.R/R/KM[0].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y24 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[0].CL.C/R[3].M.R/R/KM[2].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y25 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[0].CL.C/R[3].M.R/R/KM[1].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y26 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[0].CL.C/R[4].M.R/R/KM[0].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y27 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[0].CL.C/R[4].M.R/R/KM[2].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y28 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[0].CL.C/R[4].M.R/R/KM[1].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y29 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[0].CL.C/R[5].M.R/R/KM[0].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y30 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[0].CL.C/R[5].M.R/R/KM[2].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y31 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[0].CL.C/R[5].M.R/R/KM[1].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y32 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[1].CL.C/R[0].M.R/R/KM[0].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y14 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[1].CL.C/R[0].M.R/R/KM[2].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y13 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[1].CL.C/R[0].M.R/R/KM[1].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y12 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[1].CL.C/R[1].M.R/R/KM[0].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y11 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[1].CL.C/R[1].M.R/R/KM[2].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y10 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[1].CL.C/R[1].M.R/R/KM[1].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y9 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[1].CL.C/R[2].M.R/R/KM[0].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y8 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[1].CL.C/R[2].M.R/R/KM[2].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y7 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[1].CL.C/R[2].M.R/R/KM[1].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y6 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[1].CL.C/R[3].M.R/R/KM[0].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y5 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[1].CL.C/R[3].M.R/R/KM[2].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y4 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[1].CL.C/R[3].M.R/R/KM[1].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y3 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[1].CL.C/R[4].M.R/R/KM[0].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y2 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[1].CL.C/R[4].M.R/R/KM[2].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y1 {match_action_engine_inst/table0_MyProcessing_nif_ternary_inst/cam_inst/C*/A*/C[0].M[1].CL.C/R[4].M.R/R/KM[1].*RAM.R/xpm_memory_base_inst/gen_wr_a.gen_word_narrow.mem_reg_*ram_0} X0Y0}
