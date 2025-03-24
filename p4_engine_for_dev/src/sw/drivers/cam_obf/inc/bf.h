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

#ifndef BF_H
#define BF_H

#include <stddef.h>
#include <stdint.h>
#include <assert.h>

#define BIT(n)                  ( 1<<(n) )
#define BIT_SET(y, mask)        ( y |=  (mask) )
#define BIT_CLEAR(y, mask)      ( y &= ~(mask) )
#define BIT_FLIP(y, mask)       ( y ^=  (mask) )
// Create a bitmask of length len
#define BIT_MASK(len) (( 1<<(len) )-1)

static inline uint8_t bf_mask8(uint8_t len);
static inline uint16_t bf_mask16(uint8_t len);
static inline uint32_t bf_mask(uint8_t len);
static inline uint64_t bf_mask64(uint8_t len);

static inline uint8_t bf_get8(uint8_t y, uint8_t shift, uint8_t len);
static inline uint16_t bf_get16(uint16_t y, uint8_t shift, uint8_t len);
static inline uint32_t bf_get(uint32_t y, uint8_t shift, uint8_t len);
static inline uint64_t bf_get64(uint64_t y, uint8_t shift, uint8_t len);

static inline uint8_t bf_merge8(uint8_t y, uint8_t x, uint8_t shift, uint8_t len);
static inline uint16_t bf_merge16(uint16_t y, uint16_t x, uint8_t shift, uint8_t len);
static inline uint32_t bf_merge(uint32_t y, uint32_t x, uint8_t shift, uint8_t len);
static inline uint64_t bf_merge64(uint64_t y, uint64_t x, uint8_t shift, uint8_t len);

static inline uint16_t bf_mask16(uint8_t len)
{
    assert(len <= 16);

    if (len == 16) {
        return UINT16_MAX;
    } else {
        return ~(UINT16_MAX << len);
    }
}

static inline uint8_t bf_mask8(uint8_t len)
{
    assert(len <= 8);

    if (len == 8) {
        return UINT8_MAX;
    } else {
        return ~(UINT8_MAX << len);
    }
}

static inline uint32_t bf_mask(uint8_t len)
{
    assert(len <= 32);

    if (len == 32) {
        return UINT32_MAX;
    } else {
        return ~(UINT32_MAX << len);
    }
}

static inline uint64_t bf_mask64(uint8_t len)
{
    assert(len <= 64);

    if (len == 64) {
        return UINT64_MAX;
    } else {
        return ~(UINT64_MAX << len);
    }
}
static inline uint8_t bf_get8(uint8_t y, uint8_t shift, uint8_t len)
{
    assert(len <= 8);
    assert(shift <= 7);
    assert(shift + len <= 8);

    uint8_t mask = bf_mask8(len);
    return (y >> shift) & mask;
}

static inline uint16_t bf_get16(uint16_t y, uint8_t shift, uint8_t len)
{
    assert(len <= 16);
    assert(shift <= 15);
    assert(shift + len <= 16);

    uint16_t mask = bf_mask16(len);
    return (y >> shift) & mask;
}

static inline uint32_t bf_get(uint32_t y, uint8_t shift, uint8_t len)
{
    assert(len <= 32);

        assert(shift <= 31);


        assert((shift + len) <= 32);

    uint32_t mask = bf_mask(len);
    return (y >> shift) & mask;
}

static inline uint64_t bf_get64(uint64_t y, uint8_t shift, uint8_t len)
{
    assert(len <= 64);
    assert(shift <= 63);
    assert(shift + len <= 64);

    uint64_t mask = bf_mask64(len);
    return (y >> shift) & mask;
}

static inline uint16_t bf_merge16(uint16_t y, uint16_t x, uint8_t shift, uint8_t len)
{
    assert(len <= 16);
    assert(shift <= 15);
    assert(shift + len <= 16);

    uint16_t mask = bf_mask16(len);
    return (y & ~(mask << shift)) | ((x & mask) << shift);
}

static inline uint8_t bf_merge8(uint8_t y, uint8_t x, uint8_t shift, uint8_t len)
{
    assert(len <= 8);
    assert(shift <= 7);
    assert(shift + len <= 8);

    uint16_t mask = bf_mask8(len);
    return (y & ~(mask << shift)) | ((x & mask) << shift);
}
static inline uint32_t bf_merge(uint32_t y, uint32_t x, uint8_t shift, uint8_t len)
{
    assert(len <= 32);
    assert(shift <= 31);
    assert((shift + len) <= 32);

    uint32_t mask = bf_mask(len);
    return (y & ~(mask << shift)) | ((x & mask) << shift);
}

static inline uint64_t bf_merge64(uint64_t y, uint64_t x, uint8_t shift, uint8_t len)
{
    assert(len <= 64);
    assert(shift <= 63);
    assert(shift + len <= 64);

    uint64_t mask = bf_mask64(len);
    return (y & ~(mask << shift)) | ((x & mask) << shift);
}

static inline uint32_t bf_rotate_left32(uint32_t x, uint8_t r)
{
    return (x << r) | (x >> (32 - r));
}

void cam_write_field8(uint8_t *target, const uint8_t *source, uint16_t target_start_pos, uint16_t bit_len);

void cam_read_field8(uint8_t *target, const uint8_t *source, uint16_t source_start_pos, uint16_t bit_len);

void cam_copy_bits(uint8_t *target, const uint8_t *source, uint16_t bit_len);

void cam_write_field(uint32_t *target, uint16_t start_pos, uint16_t end_pos, const uint32_t *source,
                     uint16_t prio_end_pos);

void cam_read_field(const uint32_t *source, uint16_t start_pos, uint16_t end_pos, uint32_t *target);

#endif
