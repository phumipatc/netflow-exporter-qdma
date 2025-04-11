#
#/*
# * This file is part of the QDMA userspace application
# * to enable the user to execute the QDMA functionality
# *
# * Copyright (c) 2018-2022, Xilinx, Inc. All rights reserved.
# * Copyright (c) 2022-2023, Advanced Micro Devices, Inc. All rights reserved.
# *
# * This source code is licensed under BSD-style license (found in the
# * LICENSE file in the root directory of this source tree)
# */

SHELL = /bin/bash

CFLAGS += -g
#CFLAGS += -O2 -fno-inline -Wall -Wstrict-prototypes
CFLAGS += -I. -I../include -I../../drivers/install/include
CFLAGS += $(EXTRA_FLAGS)

reg = reg
INCLUDE_OBJS := $(patsubst %.c,%.o,$(wildcard ../include/*.c))
# P4_OBJS := $(patsubst %.c,%.o,$(wildcard ../../drivers/*/src/*.c))
BUILD_OBJS := $(wildcard ../../drivers/build/*/obj/*.o)
REG_OBJS := $(patsubst %.c,%.o,$(wildcard *.c))
REG_OBJS += $(INCLUDE_OBJS) $(BUILD_OBJS)

ifneq ($(CROSS_COMPILE_FLAG),)
	CC=$(CROSS_COMPILE_FLAG)gcc
endif
 
all: clean p4-ctl

p4-ctl: $(REG_OBJS)
	$(CC) -pthread -lrt $^ -o $(reg) -laio -D_FILE_OFFSET_BITS=64 -D_GNU_SOURCE -D_LARGE_FILE_SOURCE -lm
	
%.o: %.c
	$(CC) $(CFLAGS) -c -std=c99 -o $@ $< -D_FILE_OFFSET_BITS=64 -D_GNU_SOURCE -D_LARGE_FILE_SOURCE -D_AIO_AIX_SOURCE

clean:
	@rm -f *.o */*.o ../include/*.o $(reg)
