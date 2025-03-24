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

/*
 * @file tcam.h
 *
 */

#ifndef _CAM_UTIL_H
#define _CAM_UTIL_H

#include <stdint.h>
#include "tcam.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Get the number of fields in a format string.
 */
int get_num_fields(char *format);


/**
 * Get the format type 'b/t/c/u/p/r' of field (starting from field_num = 0).
 */
char get_field_type(char *format, int field_num);


/**
 * Get the length (bits) for a field.
 */
uint16_t get_field_len(char *format, int field_num);


/**
 * Get the total length (in bits) for key.
 */
uint16_t get_key_len(char *format);


/**
 * Mallocs a C byte array on the Heap.
 */
uint8_t *byte_arr_create(uint16_t bit_len);

/**
 * Callocs a C byte array on the Heap.
 */
uint8_t *calloc_byte_arr_create(uint32_t byte_len);

/**
 * Deallocates a C byte array from the heap.
 */
void byte_arr_destroy(uint8_t *byte_arr);


/**
 * Convert hex string to byte array.
 *
 * If the string is too short, the result will be padded with zeros.
 * If it is too long, -1 is returned, and the contents of 'dst' are
 * undefined.
 */
int str2byte_arr(const uint16_t bit_len, char *src, uint8_t *dst);


/**
 * Convert byte array to hex string.
 */
void byte_arr2str(const uint16_t bit_len, const uint8_t *src, char **dst);


/**
 * Allocate a uint32_t to be used as in-out argument by other API functions.
 */
uint32_t *uint32_create(void);


/**
 * Deallocate a uint32_t.
 */
void uint32_destroy(uint32_t *num);


/**
 * Set the value of a uint32.
 */
void uint32_set(uint32_t *dst, uint32_t value);


/**
 * Get the value of a uint32.
 */
uint32_t uint32_get(uint32_t *dst);


/**
 * Read a text file and store in two arrays of strings.
 * One array each is used for key and mask.
 * Each array has one string entry per line.
 * Memory is allocated according to file size.
 */
void read_file(char *file_name, int *lines, char ***key_data, char ***mask_data);


/**
 * Deallocates arrays of strings.
 */
void free_string_arrays(int lines, char **key_data, char **mask_data);



#ifdef __cplusplus
}
#endif

#endif
