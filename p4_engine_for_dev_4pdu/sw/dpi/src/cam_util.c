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

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "cam_util.h"



/*
 * Get the number of fields in a format string.
 */
int get_num_fields(char *format)
{
    int cnt = 0;
    for (uint16_t i = 0; i < strlen(format); i++) {
        if (format[i] == ':') {
            cnt++;
        }
    }
    return cnt + 1;
}

/*
 * Get the format type 'b/t/c/u/p/r' of field (starting from field_num = 0).
 */
char get_field_type(char *format, int field_num)
{
    size_t i = 0;
    if (field_num > 0) {
        // Skip 'field_num' colons
        int cnt = 0;
        for (i = 0; i < strlen(format); i++) {
            if (format[i] == ':') {
                cnt++;
                if (cnt == field_num) {
                    i++;
                    break;
                }
            }
        }
    }

    // Skip length value
    while (format[i] >= '0' && format[i] <= '9')
        i++;

    // The field type
    return format[i];
}



/*
 * Get the length (bits) for a field.
 */
uint16_t get_field_len(char *format, int field_num)
{
    size_t i = 0;
    if (field_num > 0) {
        // Skip 'field_num' colons
        int cnt = 0;
        for (i = 0; i < strlen(format); i++) {
            if (format[i] == ':') {
                cnt++;
                if (cnt == field_num) {
                    i++;
                    break;
                }
            }
        }
    }
    // The length value
    uint16_t val = strtoul(&format[i], NULL, 10);
    return val;
}



/*
 * Get the total length (in bits) for key.
 */
uint16_t get_key_len(char *format)
{
    uint16_t len = 0;
    uint8_t f;
    for (f = 0; f < get_num_fields(format); f++)
        len += get_field_len(format, f);
    return len;
}



/*
 * Mallocs a C byte array on the heap
 */
uint8_t *byte_arr_create(uint16_t bit_len)
{
    int byte_len = (bit_len + 7) / 8;
    uint8_t *byte_arr = malloc(byte_len);
    assert(byte_arr != NULL);
    return byte_arr;
}

/*
 * Callocs a C byte array on the heap
 */
uint8_t *calloc_byte_arr_create(uint32_t byte_len)
{
    uint8_t *byte_arr = calloc(byte_len, sizeof(uint8_t));
    assert(byte_arr != NULL);
    return byte_arr;
}


/*
 * Deallocates a C byte array from the heap.
 */
void byte_arr_destroy(uint8_t *byte_arr)
{
    free(byte_arr);
}



/*
 * Convert hex string to byte array.
 */
int str2byte_arr(const uint16_t bit_len, char *src, uint8_t *dst)
{
    assert(src != NULL);
    char *str = src;

    // Skip leading 0x
    if (strlen(str) > 2) {
        if (strncmp(str, "0x", 2) == 0) {
            str += 2;
        }
    }
    int byte_len = (bit_len + 7) / 8;
    memset(dst, 0, byte_len);
    /* Odd len, such as fff? Consume single char first */
    int len = strlen(str);
    if (strlen(str) & 1) {
        sscanf(str, "%1hhx", &dst[len / 2]);
        str += 1;
    }

    len /= 2;
    if(len > byte_len)
        return -1;

    /* Perform byte swapping on the fly */
    int i;
    for (i = len - 1; i >= 0; i--) {
        sscanf(str, "%2hhx", &dst[i]);
        str += 2;
    }

    return 0;
}



/*
 * Convert byte array to hex string.
 */
void byte_arr2str(const uint16_t bit_len, const uint8_t *src, char **dst)
{
    assert(src != NULL);
    assert(dst != NULL);

    int byte_len = (bit_len + 7) / 8;
    uint8_t tailbits = bit_len % 8;
    if (tailbits == 0)
        tailbits = 8;
    uint8_t tailmask = 0xff >> (8 - tailbits);

    char *str = *dst;
    sprintf(str, "0x");
    str += 2;
    for (int i = byte_len - 1; i >= 0; i--) {
        if ((i == byte_len - 1) && (byte_len != (bit_len + 3) / 8)) {
            // First byte, when odd number of bytes
            sprintf(str, "%1x", src[i] & tailmask);
            str += 1;
        } else {
            sprintf(str, "%02x", src[i] & tailmask);
            str += 2;
        }
        tailmask = 0xff;
    }
}



/*
 * Allocate a uint32_t to be used as in-out argument by other API functions.
 */
uint32_t *uint32_create(void)
{
    return malloc(sizeof(uint32_t));
}



/*
 * Deallocate a uint32_t.
 */
void uint32_destroy(uint32_t *num)
{
    free(num);
}


/*
 * Set the value of a uint32.
 */
void uint32_set(uint32_t *dst, uint32_t value)
{
    *dst = value;
}


/*
 * Get the value of a uint32.
 */
uint32_t uint32_get(uint32_t *dst)
{
    return *dst;
}





/**
 * Read a text file and store in two arrays of strings.
 * One array each is used for key and mask.
 * Each array has one string entry per line.
 * Memory is allocated according to file size.
 */
void read_file(char *file_name, int *lines, char ***key_data, char ***mask_data)
{
    int lines_allocated = 10000;
    int max_line_len = 500;

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        fprintf(stderr, "** Error: Cannot open file %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    /* Allocate lines of text */
    char **key_words = (char **) malloc(sizeof(char*) * lines_allocated);
    char **mask_words = (char **) malloc(sizeof(char*) * lines_allocated);
    if (key_words == NULL || mask_words == NULL) {
        fprintf(stderr, "** Error: Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    char *next_line;

    bool read_key = true;
    int i = 0;
    while(true) {
        int j;

        /* Have we gone over our line allocation? */
        if (i >= lines_allocated) {
            int new_size;

            /* Double our allocation and re-allocate */
            new_size = lines_allocated * 2;
            key_words = (char **) realloc(key_words, sizeof(char*) * new_size);
            if (key_words == NULL)
                assert(false);
            mask_words = (char **) realloc(mask_words, sizeof(char*) * new_size);
            if (mask_words == NULL)
                assert(false);
            if (key_words == NULL || mask_words == NULL) {
                fprintf(stderr, "** Error: Failed to allocate memory\n");
                exit(EXIT_FAILURE);
            }
            lines_allocated = new_size;
        }
        /* Allocate space for the next line */
        next_line = malloc(max_line_len);
        if (next_line == NULL) {
            fprintf(stderr, "** Error: Failed to allocate memory\n");
            exit(EXIT_FAILURE);
        }
        if (fgets(next_line, max_line_len-1, fp) == NULL) {
            free(next_line);
            break;
        }

        // Skip comments
        if (next_line[0] == '#') {
            free(next_line);
            continue;
        }

        /* Get rid of CR or LF at end of line */
        for (j = strlen(next_line) - 1; j >= 0 && (next_line[j] == '\n' || next_line[j] == '\r'); j--)
            ;
        next_line[j+1] = '\0';

        if (read_key) {
            key_words[i] = next_line;
        } else {
            mask_words[i] = next_line;
            i++;
        }
        read_key = !read_key;
    }
    fclose(fp);
    *lines = i;
    *key_data = key_words;
    *mask_data = mask_words;
}



/**
 * Deallocates arrays of strings.
 */
void free_string_arrays(int lines, char **key_data, char **mask_data)
{
    for (int line_num = 0; line_num < lines; line_num++) {
        free(key_data[line_num]);
        free(mask_data[line_num]);
    }
    free(key_data);
    free(mask_data);
}


