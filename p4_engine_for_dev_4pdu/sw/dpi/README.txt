############################################################
# (c) Copyright 2019-2023 Advanced Micro Devices, Inc. All rights reserved.
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


Compiling DPI shared library object file (i.e. cam_dpi_obf.so) for local customisation
-----------------------------------------------------------------------------------

Steps:
1) Ensure the Makefile has a valid path to file "svdpi.h", which is usually located
   at Vivado install location: <Vivado install>/data/xsim/include/svdpi.h
   (i.e. check that environment variable XILINX_VIVADO is set to the Vivado install location)
   
2) Generate "cam_dpi_obf.so" by running "make" in this directory (note default HDL hierarchical path for simulations is set to: "example_top.AXM")
   If your testbench uses a different HDL hierarchical path to module axi_lite_master, instance name AXM, then you can change it by specifying it at the make command line.
   i.e. make DPI_PATH=<your HDL hierarchical path to module axi_lite_master instance>
   e.g. if in your testbench the HDL hierarchical path to module axi_lite_master instance is "tb_top.AXM" then run make with following option
   make DPI_PATH="tb_top.AXM"

3) In HDL simulator script update the path to point to this generated "cam_dpi_obf.so"
   or
   replace the existing "cam_dpi_obf.so" with this generated "cam_dpi_obf.so" version

