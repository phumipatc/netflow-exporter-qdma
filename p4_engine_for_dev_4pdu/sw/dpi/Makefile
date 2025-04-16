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

#
# Makefile for compiling DPI shared library object file (i.e. cam_dpi.so) for local customization
#

CC     = gcc
CFLAGS = -std=gnu99 -fpic -fgnu89-inline
CFLAGS += -Wall -Wextra -Wstrict-prototypes -Wmissing-prototypes -Wwrite-strings


ifndef XILINX_VIVADO
    $(error Vivado not installed, cannot find "$$XILINX_VIVADO/data/xsim/include/svdpi.h")
endif

DPI_PATH=""
ifneq ($(DPI_PATH), "")
CFLAGS += -DDPI_PATH="$(DPI_PATH)"
endif

SVDPI_PATH = ${XILINX_VIVADO}/data/xsim/include

INC = -I ../cam_src/inc -I ../comp_bcam/inc -I ./inc -I $(SVDPI_PATH)

# Shared library includes drivers for both software managed and hardware managed CAMs
cam_dpi.so: ../cam_src/src/cam_obf.c ../comp_bcam/src/ccam_obf.c ../cam_src/src/common/bf.c $(wildcard ./*/cam_util.[ch] ./*/cam_dpi.[ch])
	$(CC) $(CFLAGS) $(INC) -shared -o cam_dpi.so $^

all:	cam_dpi.so

clean:
	-rm -f cam_dpi.so
