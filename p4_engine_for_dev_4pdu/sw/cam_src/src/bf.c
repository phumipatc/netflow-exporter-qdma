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

#include <stdio.h>
#include <string.h>
#include "bf.h"

void cam_read_field8(uint8_t *target, const uint8_t *source, uint16_t source_start_pos, uint16_t bit_len) {

    assert(bit_len > 0);
    assert((UINT16_MAX - bit_len) >= source_start_pos);
    uint16_t i;
    const uint16_t end_pos = bit_len + source_start_pos - 1;
    uint16_t start_byte = source_start_pos / 8;
    uint16_t start_byte_start = source_start_pos - start_byte * 8;

    uint16_t end_byte = end_pos / 8;
    uint16_t end_byte_end = end_pos - end_byte * 8;

    uint16_t byte_diff = end_byte - start_byte;

    switch (byte_diff) {
    case 0:

        target[0] = bf_get8(source[start_byte], start_byte_start, end_byte_end - start_byte_start + 1);
        break;
    case 1:

        // Fill target[0] from the first byte
        target[0] = bf_get8(source[start_byte], start_byte_start, 8 - start_byte_start);

        // Everything in the second word fits in target[0]
        if (bit_len <= 8) {
            const uint8_t value = bf_get8(source[end_byte], 0, end_byte_end + 1);
            target[0] = bf_merge8(target[0], value, 8 - start_byte_start, end_byte_end + 1);
        } else {
            if (start_byte_start > 0) {
                // Read from the second byte the number of bits that fits in target[0]
                const uint32_t value = bf_get8(source[end_byte], 0, start_byte_start);
                target[0] = bf_merge8(target[0], value, 8 - start_byte_start, start_byte_start);
            }

            // Read what remains in the second byte and store it in target[1]
            target[1] = bf_get8(source[end_byte], start_byte_start, bit_len - 8);
        }

        break;
    default:
        // Fill target[0] from the first byte
        target[0] = bf_get8(source[start_byte], start_byte_start, 8 - start_byte_start);

        for (i = 0; i < (byte_diff - 1); i++) {
            // Fill what remains in target[i] from the i+1 byte
            if (start_byte_start > 0) {
                const uint8_t value = bf_get8(source[start_byte + i + 1], 0, start_byte_start);
                target[i] = bf_merge8(target[i], value, 8 - start_byte_start, start_byte_start);
            }
            // The (i+1):th byte might contain more data. This data needs to be stored in target[i+1].
            // We have already read start_byte_start bits from the i:th word so what remains to be read is (8 - start_byte_start) bits

            target[i + 1] = bf_get8(source[start_byte + i + 1], start_byte_start, 8 - start_byte_start);

        }

        if ((end_byte_end + 1) <= start_byte_start) {
            //target[i] has sufficient bits to store what remains in the last word
            const uint8_t value = bf_get8(source[end_byte], 0, end_byte_end + 1);
            target[i] = bf_merge8(target[i], value, 8 - start_byte_start, end_byte_end + 1);
        } else {
            // target[i] has not sufficient bits to store what remains in the last byte. We need to write to target[i+1] as well.
            // start to fill target[i]
            if (start_byte_start > 0) {
                const uint8_t value = bf_get8(source[end_byte], 0, start_byte_start);
                target[i] = bf_merge8(target[i], value, 8 - start_byte_start, start_byte_start);
            }
            // Continue to read the remains in the last word and store it in target[i+1]
            const uint8_t value = bf_get8(source[end_byte], start_byte_start, end_byte_end - start_byte_start + 1);
            target[i + 1] = bf_merge8(target[i + 1], value, 0, end_byte_end - start_byte_start + 1);
        }

    }
}


void cam_write_field8(uint8_t *target, const uint8_t *source, uint16_t target_start_pos, uint16_t bit_len) {
    assert(bit_len > 0);
    assert((UINT16_MAX - bit_len) >= target_start_pos);
    const uint16_t end_pos = bit_len + target_start_pos - 1;

    uint16_t i;
    uint16_t start_byte = target_start_pos / 8;
    uint16_t start_byte_start = target_start_pos - start_byte * 8;

    uint16_t end_byte = end_pos / 8;
    uint16_t end_byte_end = end_pos - end_byte * 8;

    uint16_t byte_diff = end_byte - start_byte;
    uint8_t value;

    switch (byte_diff) {
    case 0:

        target[start_byte] = bf_merge8(target[start_byte], source[0], start_byte_start,
                end_byte_end - start_byte_start + 1);
        break;
    case 1:
        // Fill first byte from source[0]
        value = bf_get8(source[0], 0, 8 - start_byte_start);
        target[start_byte] = bf_merge8(target[start_byte], value, start_byte_start, 8 - start_byte_start);
        // The reminder in source[0] fits in the second byte

        // Fill second byte with the reminder form source[0]. What remains in source[0] is start_byte_start bits
        if (bit_len <= 8) {
            value = bf_get8(source[0], 8 - start_byte_start, bit_len - (8 - start_byte_start));
            target[end_byte] = bf_merge8(target[end_byte], value, 0, bit_len - (8 - start_byte_start));
        } else {
            if (start_byte_start > 0) {
                value = bf_get8(source[0], 8 - start_byte_start, start_byte_start);
                target[end_byte] = bf_merge8(target[end_byte], value, 0, start_byte_start);
            }
            value = bf_get8(source[1], 0, bit_len - 8);
            target[end_byte] = bf_merge8(target[end_byte], value, start_byte_start, bit_len - 8);
        }

        break;
    default:
        // Fill first byte from source[0]
        value = bf_get8(source[0], 0, 8 - start_byte_start);
        target[start_byte] = bf_merge8(target[start_byte], value, start_byte_start, 8 - start_byte_start);

        for (i = 0; i < (byte_diff - 1); i++) {
            // Fill (i+1) byte with the reminder form source[i]. What remains in source[i] is start_byte_start bits
            if (start_byte_start > 0) {
                value = bf_get8(source[i], 8 - start_byte_start, start_byte_start);
                target[start_byte + 1 + i] = bf_merge8(target[start_byte + 1 + i], value, 0, start_byte_start);
            }
            // The (i+1) byte might require more data. The (i+1) byte is already filled with start_byte_start bits so what remains is
            // (8 - start_byte_start) bits
            value = bf_get8(source[i + 1], 0, 8 - start_byte_start);
            target[start_byte + 1 + i] = bf_merge8(target[start_byte + 1 + i], value, start_byte_start,
                    8 - start_byte_start);
        }
        // (i) is now (byte_diff-1)
        // start_byte_start bits remains in source[i]. This should go to the end byte
        if ((end_byte_end + 1) <= start_byte_start) {
            // source[i] has sufficient bits to fill the end byte
            value = bf_get8(source[i], 8 - start_byte_start, end_byte_end + 1);
            target[end_byte] = bf_merge8(target[end_byte], value, 0, end_byte_end + 1);
        } else {
            // source[i] has not sufficient bits to fill the end byte. We need to read from source[i+1] as well.
            // start to read what remains in source[i]
            if (start_byte_start > 0) {
                value = bf_get8(source[i], 8 - start_byte_start, start_byte_start);
                target[end_byte] = bf_merge8(target[end_byte], value, 0, start_byte_start);
            }
            // Continue to read the remains from source[i+1]
            value = bf_get8(source[i + 1], 0, end_byte_end - start_byte_start + 1);
            target[end_byte] = bf_merge8(target[end_byte], value, start_byte_start,
                    end_byte_end - start_byte_start + 1);
        }

    }
}

void cam_copy_bits(uint8_t *target, const uint8_t *source, uint16_t bit_len)
{
    const uint16_t num_bytes = bit_len / 8;
    const uint8_t rem_bits = bit_len - num_bytes * 8;
    memcpy(target, source, num_bytes);
    if (rem_bits)
        target[num_bytes] = bf_get8(source[num_bytes], 0, rem_bits);

}

void cam_read_field(const uint32_t *source, uint16_t start_pos, uint16_t end_pos, uint32_t *target) {
    uint16_t i;
    const uint16_t bit_diff = end_pos - start_pos + 1;
    uint16_t start_word = start_pos / 32;
    uint16_t start_word_start = start_pos - start_word * 32;

    uint16_t end_word = end_pos / 32;
    uint16_t end_word_end = end_pos - end_word * 32;

    uint16_t word_diff = end_word - start_word;

    switch (word_diff) {
    case 0:

        target[0] = bf_get(source[start_word], start_word_start, end_word_end - start_word_start + 1);
        break;
    case 1:

        // Fill target[0] from the first word
        target[0] = bf_get(source[start_word], start_word_start, 32 - start_word_start);

        // Everything in the second word fits in target[0]
        if (bit_diff <= 32) {
            const uint32_t value = bf_get(source[end_word], 0, end_word_end + 1);
            target[0] = bf_merge(target[0], value, 32 - start_word_start, end_word_end + 1);
        } else {
            if (start_word_start > 0) {
                // Read from the second word the number of bits that fits in target[0]
                const uint32_t value = bf_get(source[end_word], 0, start_word_start);
                target[0] = bf_merge(target[0], value, 32 - start_word_start, start_word_start);
            }

            // Read what remains in the second word and store it in target[1]
            /* coverity[array_vs_singleton] */
            target[1] = bf_get(source[end_word], start_word_start, bit_diff - 32);
        }

        break;
    default:
        // Fill target[0] from the first word
        target[0] = bf_get(source[start_word], start_word_start, 32 - start_word_start);

        for (i = 0; i < (word_diff - 1); i++) {
            // Fill what remains in target[i] from the i+1 word
            if (start_word_start > 0) {
                const uint32_t value = bf_get(source[start_word + i + 1], 0, start_word_start);
                target[i] = bf_merge(target[i], value, 32 - start_word_start, start_word_start);
            }
            // The (i+1):th word might contain more data. This data needs to be stored in target[i+1].
            // We have already read start_word_start bits from the i:th word so what remains to be read is (32 - start_word_start) bits

            target[i + 1] = bf_get(source[start_word + i + 1], start_word_start, 32 - start_word_start);

        }

        //
        //
        if ((end_word_end + 1) <= start_word_start) {
            //target[i] has sufficient bits to store what remains in the last word
            const uint32_t value = bf_get(source[end_word], 0, end_word_end + 1);
            target[i] = bf_merge(target[i], value, 32 - start_word_start, end_word_end + 1);
        } else {
            // target[i] has not sufficient bits to store what remains in the last word. We need to write to target[i+1] as well.
            // start to fill target[i]
            if (start_word_start > 0) {
                const uint32_t value = bf_get(source[end_word], 0, start_word_start);
                target[i] = bf_merge(target[i], value, 32 - start_word_start, start_word_start);
            }
            // Continue to read the remains in the last word and store it in target[i+1]
            const uint32_t value = bf_get(source[end_word], start_word_start, end_word_end - start_word_start + 1);
            target[i + 1] = bf_merge(target[i + 1], value, 0, end_word_end - start_word_start + 1);
        }

    }
}

void cam_write_field(uint32_t *target, uint16_t start_pos, uint16_t end_pos, const uint32_t *source,
        uint16_t prio_end_pos) {
    assert(start_pos <= prio_end_pos);
    assert(end_pos <= prio_end_pos);
    const uint16_t bit_diff = end_pos - start_pos + 1;
    if (bit_diff == 0) {
        assert(bit_diff > 0);
    }
    uint16_t i;
    uint16_t start_word = start_pos / 32;
    uint16_t start_word_start = start_pos - start_word * 32;

    uint16_t end_word = end_pos / 32;
    uint16_t end_word_end = end_pos - end_word * 32;

    uint16_t word_diff = end_word - start_word;
    uint64_t value;
    // Set words to dirty, so we know to write this word to PCI later when we flush
    //*dirty_vector = bf_merge64(*dirty_vector, value, start_word, word_diff + 1);

    assert(word_diff < ((prio_end_pos + 1 + 31) / 32));

    switch (word_diff) {
    case 0:

        target[start_word] = bf_merge(target[start_word], source[0], start_word_start,
                end_word_end - start_word_start + 1);
        break;
    case 1:
        // Fill first word from source[0]
        value = bf_get(source[0], 0, 32 - start_word_start);
        target[start_word] = bf_merge(target[start_word], value, start_word_start, 32 - start_word_start);
        // The reminder in source[0] fits in the second word

        // Fill second word with the reminder form source[0]. What remains in source[0] is start_word_start bits
        if (bit_diff <= 32) {
            value = bf_get(source[0], 32 - start_word_start, bit_diff - (32 - start_word_start));
            target[end_word] = bf_merge(target[end_word], value, 0, bit_diff - (32 - start_word_start));
        } else {
            if (start_word_start > 0) {
                value = bf_get(source[0], 32 - start_word_start, start_word_start);
                target[end_word] = bf_merge(target[end_word], value, 0, start_word_start);
            }
            value = bf_get(source[1], 0, bit_diff - 32);
            target[end_word] = bf_merge(target[end_word], value, start_word_start, bit_diff - 32);
        }

        break;
    default:
        // Fill first word from source[0]
        value = bf_get(source[0], 0, 32 - start_word_start);
        target[start_word] = bf_merge(target[start_word], value, start_word_start, 32 - start_word_start);

        for (i = 0; i < (word_diff - 1); i++) {
            // Fill (i+1) word with the reminder form source[i]. What remains in source[i] is start_word_start bits
            if (start_word_start > 0) {
                value = bf_get(source[i], 32 - start_word_start, start_word_start);
                target[start_word + 1 + i] = bf_merge(target[start_word + 1 + i], value, 0, start_word_start);
            }
            // The (i+1) word might require more data. The (i+1) word is already filled with start_word_start bits so what remains is (32 - start_word_start) bit
            value = bf_get(source[i + 1], 0, 32 - start_word_start);
            target[start_word + 1 + i] = bf_merge(target[start_word + 1 + i], value, start_word_start,
                    32 - start_word_start);
        }
        // (i) is now (word_diff-1)
        // start_word_start bits remains in source[i]. This should go to the end word
        if ((end_word_end + 1) <= start_word_start) {
            // source[i] has sufficient bits to fill the end word
            value = bf_get(source[i], 32 - start_word_start, end_word_end + 1);
            target[end_word] = bf_merge(target[end_word], value, 0, end_word_end + 1);
        } else {
            // source[i] has not sufficient bits to fill the end word. We need to read from source[i+1] as well.
            // start to read what remains in source[i]
            if (start_word_start > 0) {
                value = bf_get(source[i], 32 - start_word_start, start_word_start);
                target[end_word] = bf_merge(target[end_word], value, 0, start_word_start);
            }
            // Continue to read the remains from source[i+1]
            value = bf_get(source[i + 1], 0, end_word_end - start_word_start + 1);
            target[end_word] = bf_merge(target[end_word], value, start_word_start, end_word_end - start_word_start + 1);
        }

    }
}
