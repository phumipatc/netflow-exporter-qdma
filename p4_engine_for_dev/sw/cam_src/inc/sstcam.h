/////////////////////////////////////////////////////////////////////////////
//
// (c) Copyright 2021, 2023 Advanced Micro Devices, Inc. All rights reserved.
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


/**
 * Public API of the SSTCAM.
 *
 * This API is intended to work with the full Keystone B miss handler even though only a preliminary "simple"
 * implementation will be delivered at first, which will be missing certain features and optimisations.
 *
 * @file sstcam.h
 *
 * @addtogroup sstcam SSTCAM Public API
 * @{
 */


#ifndef _SSTCAM_H_
#define _SSTCAM_H_

#include <stdint.h>
#include "cam.h"

#ifdef __cplusplus
extern "C" {
#endif

struct sstcam;

/**
 * Creates a stcam instance. Returns 0 if successful, otherwise an error code. A shadow of the HW instance is
 * created.
 *
 * @param[in] cam_arg       Arguments used to create the stcam instance. cam_arg is copied to the
 *                          stcam instance, and can be destroyed immediately after this call.
 *
 * @param[out] out_stcam    Returns the newly created stcam instance. Memory is allocated using malloc.
 *                          If stcam_create returns an error the instance is not created.
 *                          In this case no memory is allocated, and out_stcam is left unchanged.
 *
 * @return                  Returns 0 for success, otherwise the error code.
 *
 */
int sstcam_create(const cam_arg_t *cam_arg,
                  struct sstcam **out_stcam);

/**
 * The STCAM only supports a small number of masks. Masks are identified by small integers from 0 to N-1 where
 * N is the maximum number of masks supported by the instance.
 */
typedef uint16_t sstcam_mask_id_t;

#define SSTCAM_MASK_ID_NONE ((sstcam_mask_id_t) -1)

#define SSTCAM_MASK_MAX (64)

/**
 * Allocate a mask.
 *
 * @param[in] stcam     Pointer to the STCAM instance
 *
 * @param[in] mask      The ternary mask to allocate. The width is specified when the instance is created.
 *
 * @param[out] id       On success, the newly assigned ID.
 *
 * @return              0 for success.
 *                      CAM_ERROR_FULL if all available IDs are allocated.
 */
int sstcam_mask_alloc(struct sstcam *stcam,
                      const uint8_t mask[],
                      sstcam_mask_id_t *id);

/**
 * Free an allocated mask.
 *
 * This operation is only permitted if the STCAM contains no entries for the given mask.
 *
 * @param[in] stcam     Pointer to the STCAM instance
 *
 * @param[in] id        The mask ID to deallocate.
 *
 * @return              0 for success.
 *                      CAM_ERROR_INVALID_ARG if the mask ID was not allocated.
 *                      CAM_ERROR_NOT_EMPTY if there are entries in the STCAM for this mask.
 */
int sstcam_mask_free(struct sstcam *stcam,
                     sstcam_mask_id_t id);

/**
 * Inserts an entry to the stcam instance. If the entry is found, the function fails by returning
 * error code CAM_ERROR_DUPLICATE_FOUND.
 * If the entry is not found, then it is inserted to the stcam instance.
 * Returns 0 if successful, otherwise an error code.
 *
 * @param[in] stcam     Pointer to the stcam instance
 *
 * @param[in] key       The key. The key width (in bits) of the stcam instance specifies the number of bits
 *                      which will be copied from the argument. Any content outside the scope of the key width
 *                      is ignored.  The key is assumed to be in little-endian format.
 *                      key[0] bit 0 is the least significant bit of the key.
 *                      key[1] bit 0 is bit 8 of the key and so on.
 *
 * @param[in] mask      The mask associated with this key, as returned by sstcam_mask_alloc().
 *
 * @param[in] priority  The priority of the entry. Not used in this implementation.
 *
 * @param[in] response  The response of the entry.
 *                      The response width of the instance specifies how many bits are copied and stored as response.
 *                      The response is in little-endian format.
 *
 * @return              Returns 0 for success, otherwise the error code.
 *
 */
int sstcam_insert(struct sstcam *stcam,
                  const uint8_t key[],
                  sstcam_mask_id_t mask,
                  uint32_t priority,
                  const uint8_t response[]);

/**
 * Updates an entry in the stcam instance. If the entry is found, the response is updated. For an entry to be found,
 * both the key and mask must match the "old entry".
 * If the entry is not found, the function fails with error code CAM_ERROR_NO_ENTRY.
 * Returns 0 if successful, otherwise an error code.
 *
 * @param[in] stcam      Pointer to the stcam instance
 *
 * @param[in] key       The key. The key width (in bits) of the stcam instance specifies the number of bits
 *                      which will be used from the argument. Any content outside the scope of the key width is ignored.
 *                      The key is assumed to be in little-endian format.
 *                      key[0] bit 0 is the least significant bit of the key.
 *                      key[1] bit 0 is bit 8 of the key and so on.
 *
 * @param[in] mask      The mask associated with this key, as returned by sstcam_mask_alloc().
 *
 * @param[in] response  The response of the entry.
 *                      The response width of the instance specifies the number of bits copied from the argument.
 *                      Any content outside the scope of the response width is ignored.
 *                      The response is in little-endian format.
 *
 * @return              Returns 0 for success, otherwise the error code.
 *
 */
int sstcam_update(struct sstcam *stcam,
                  const uint8_t key[],
                  sstcam_mask_id_t mask,
                  const uint8_t response[]);

/**
 * Iterate over entries in the STCAM.
 *
 * The key, key_mask, response and response_mask allow the returned values to be limited to those which contain
 * particular bit values in particular positions.
 *
 * The pos argument should be set to zero when the function is first called. If it returns success, it can be
 * called again with the same pos value to find the next matching entry. The search is complete when it returns
 * CAM_ERROR_KEY_NOT_FOUND.
 *
 * Any of the output parameters may be NULL if the caller is not interested in the corresponding value.
 *
 * @param[in] stcam          Pointer to stcam instance
 *
 * @param[in] key            The key value to search for. May be NULL to specify that any stored key should match.
 *
 * @param[in] key_mask       Mask limiting the search to certain subfields of the key. Set bits in this mask
 *                           specify bits of the key which should be matched against the stored entry; clear bits
 *                           in this mask will match against any value in the stored entry. May be NULL to specify
 *                           that any stored key should match.
 *
 * @param[in] response       The response value to search for. May be NULL to specify that any stored response
 *                           should match.
 *
 * @param[in] response_mask  Mask limiting the search to certain subfields of the response. Set bits in this mask
 *                           specify bits of the response which should be matched against the stored entry; clear
 *                           bits in this mask will match against any value in the stored entry. May be NULL to
 *                           specify that any stored response should match.
 *
 * @param[in] mask           Which ternary mask to search for, as returned by sstcam_mask_alloc(). May be
 *                           SSTCAM_MASK_ID_NONE to specify that any ternary mask should match.
 *
 * @param[in,out] pos        Current position of the iteration. Use 0 for the first call.
 *
 * @param[out] out_key       The matched key.
 *
 * @param[out] out_response  The matched response.
 *
 * @param[out] out_mask      The ternary mask of the matched entry.
 *
 * @param[out] out_priority  The priority of the matched entry. Always zero in this implementation.
 *
 * @return                   Returns 0 for success, otherwise the error code.
 */
int sstcam_iterate(struct sstcam *stcam,
                   const uint8_t key[], const uint8_t key_mask[],
                   const uint8_t response[], const uint8_t response_mask[],
                   sstcam_mask_id_t mask,
                   uint32_t *pos,
                   uint8_t out_key[],
                   uint8_t out_response[],
                   sstcam_mask_id_t *out_mask,
                   uint32_t *out_priority);

/**
 * Delete an entry from the stcam instance. If the entry is found, the function returns 0.
 * For an entry to be found both the key and mask must match an "old" entry".
 * If an entry is not found, the function fails with error code CAM_ERROR_KEY_NOT_FOUND.
 *
 * @param[in] stcam     Pointer to stcam instance
 *
 * @param[in] key       The key to delete. The key. The key width (in bits) of the stcam instance specifies
 *                      the number of bits which will be copied from the argument. Any content outside the
 *                      scope of the key width is ignored.  The key is assumed to be in little-endian format.
 *                      key[0] bit 0 is the least significant bit of the key.
 *                      key[1] bit 0 is bit 8 of the key and so on.
 *
 * @param[in] mask      The mask associated with this key, as returned by sstcam_mask_alloc().
 *
 * @return              Returns 0 for success, otherwise the error code.
 *
 */
int sstcam_delete(struct sstcam *stcam,
                  const uint8_t key[], sstcam_mask_id_t mask);

/**
 * Looks up an entry in the stcam instance.
 * This function provides the same response as if a lookup had been performed in hardware.
 * If no match is found in the database, the response value associated with the default response entry
 * is returned and the return code is CAM_ERROR_KEY_NOT_FOUND.
 * If an entry is found in the data base, the function returns 0.
 *
 * @param[in] stcam     Pointer to stcam instance
 *
 * @param[in] key       The key to lookup. The key. The key width (in bits) of the stcam instance specifies
 *                      the number of bits in the key. Any content outside the scope of the key width is
 *                      ignored.  The key is assumed to be in little-endian format.
 *                      key[0] bit 0 is the least significant bit of the key.
 *                      key[1] bit 0 is bit 8 of the key and so on.
 *
 * @param[out] response The response from the lookup. The response is in little-endian format.
 *
 * @return              Returns 0 for success, otherwise the error code.
 *
 */
int sstcam_lookup(struct sstcam *stcam,
                  const uint8_t key[],
                  uint8_t response[]);

/**
 * Reads and clears the ECC counters of the stcam instance. When the instance is created the ECC counters
 * are automatically cleared. This function always returns zero.
 *
 * The initial "simple" implementation does not support ECC scrubbing and so the returned counter values will
 * always be zero.
 *
 * @param[in] stcam                         Pointer to stcam instance
 *
 * @param[out] corrected_single_bit_errors  The number of single bit errors the hardware scrubbing
 *                                          process has detected and corrected permanently. Errors might
 *                                          have been detected by hardware lookups and then corrected
 *                                          dynamically for the lookups, these errors are not counted.
 *                                          The scrubbing process runs in the background and corrects
 *                                          errors permanently. The counter is only incremented after
 *                                          the error is corrected permanently.The counter is cleared
 *                                          when read.
 *
 * @param[out] detected_double_bit_errors   The number of detected double-bit errors. Double-bit
 *                                          errors are fatal errors and the database is corrupt. The hardware
 *                                          cannot correct the error without help from software. When a
 *                                          double bit error is detected either by scrubbing or a lookup, an
 *                                          interrupt signal is asserted. Double bit errors detected by scrubbing
 *                                          are counted by this counter. The counter is cleared when read.
 *                                          Lookups detecting double-bit errors will mark the lookup response with
 *                                          a double-bit-error indication. It is advised to use this indication to
 *                                          discard packets. Double bit errors detected by lookups are not counted.
 *
 * @return                                  Returns 0 for success, otherwise the error code.
 *
 */
int sstcam_read_and_clear_ecc_counters(struct sstcam *stcam,
                                       uint32_t *corrected_single_bit_errors,
                                       uint32_t *detected_double_bit_errors);

/**
 * Reads and clears the ECC address registers of the stcam instance. The ECC adresses registers are
 * automatically cleared when the stcam instance is created. This function always returns zero.
 *
 * The initial simple implementation does not support ECC scrubbing and so the returned addresses will always
 * be zero.
 *
 * @param[in] stcam                              Pointer to stcam instance
 *
 * @param[out] failing_address_single_bit_error  The address of the first single bit error detected and corrected
 *                                               by the hardware scrubbing process. Additional errors might
 *                                               have been detected during a hardware lookup and then corrected
 *                                               dynamically, but this register only reflect the
 *                                               errors detected by hardware scrubbing.
 *
 * @param[out] failing_address_double_bit_error  The address of the first double-bit error detected by the
 *                                               hardware scrubbing process.
 *
 * @return                                       Returns 0 for success, otherwise the error code.
 *
 */
int sstcam_read_and_clear_ecc_addresses(struct sstcam *stcam,
                                        uint32_t *failing_address_single_bit_error,
                                        uint32_t *failing_address_double_bit_error);

/**
 * Set error injection for ECC test. Error injection makes subsequently inserted entries to be stored in
 * memory with errors.
 *
 * The initial simple implementation does not support ECC scrubbing and so this function has no effect.
 *
 * @param[in] stcam                              Pointer to stcam instance
 *
 * @param[in] inject_single_bit_errors           Enable insertion of single-bit errors (correctable).
 *
 * @param[in] inject_double_bit_errors           Enable insertion of double-bit errors (uncorrectable).
 *
 * @return                                       Returns 0 for success, otherwise the error code.
 *
 */
int sstcam_set_ecc_test(struct sstcam *stcam,
                        bool inject_single_bit_errors,
                        bool inject_double_bit_errors);

/**
 * Structure used to return per-mask hit counts.
 *
 * The timestamp field indicates which time period the counters relate to. Calling code can use this
 * to determine whether a new sample has been generated or whether it is re-reading the same sample
 * it saw last time.
 */
struct sstcam_stats_hits_per_mask {
    uint32_t timestamp;
    uint32_t hits[SSTCAM_MASK_MAX];
    uint32_t misses;
};

/**
 * Structure used to return backpressure statistics.
 */
struct sstcam_stats_backpressure {
    uint32_t timestamp;
    uint32_t request; /* Wait cycles per second on the request interface. */
};

/**
 * Structure used to return statistics to the caller. The SSTCAM_STATS_* constants determine which
 * member of the union will be filled in by sstcam_get_stats().
 */
union sstcam_stats {

    struct sstcam_stats_hits_per_mask hits_per_mask;
    struct sstcam_stats_backpressure  backpressure;

    struct sstcam_reserved {
        uint8_t resv[512];
    } reserved;
};

#define SSTCAM_STATS_HITS_PER_MASK (0x1000)
#define SSTCAM_STATS_BACKPRESSURE  (0x1001)

/**
 * Reads statistics information. The statistics information is organized into different groups. The
 * statistics associated with a certain group are read from the instance.  See documentation for the
 * members of the sstcam_stats union for further information.
 *
 * If this function returns an error, the contents of the sstcam_stats union are undefined.
 *
 * @param[in]   stcam            Pointer to stcam instance
 *
 * @param[in]   stats_group     Selects the group of statistics to be read
 * @param[out]  stats           The read statistics
 *
 * @return                      0 for success.
 *
 *                              CAM_ERROR_INVALID_ARG if the value of 'stats_group' was not
 *                              recognised or if either of the pointer arguments is NULL.
 *
 *                              CAM_ERROR_ENVIRONMENT if reading from the hardware failed in some
 *                              way.
 */
int sstcam_get_stats(const struct sstcam *stcam, uint64_t stats_group, union sstcam_stats *stats);

/**
 * Destroy stcam instance.
 *
 * @param[in]   stcam    Pointer to stcam instance. All memory previously allocated by stcam_create is released.
 */
void sstcam_destroy(struct sstcam *stcam);


/** @}*/

#ifdef __cplusplus
}
#endif

#endif
