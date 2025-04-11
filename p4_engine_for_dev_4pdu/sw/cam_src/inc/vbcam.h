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


/**
 * Public API of the virtual bcam.
 *
 * @file vbcam.h
 *
 *
 * @addtogroup vbcam VBCAM Public API
 * @{
 */

#ifndef _VBCAM_H_
#define _VBCAM_H_

#include "cam.h"

#ifdef __cplusplus
extern "C" {
#endif

    // Forward declaration of the vbcam struct.
struct vbcam;


/**
 * Creates a virtual bcam instance. Each bcam uses dedicated HW. Each bcam is completely independent and uses its own AXI-lite interface,
 * lookup hw and URAMs/BRAMs/PCs. Each bcam could have different parameters
 * such as memory type, lookup rate, key width and number of entries. Each bcam can be virtualized, that is, if there are three bcams each of
 * them could be virtualized. When a bcam is virtualized it is divided in 256 segments of equal size. Both the hw and sw memory is divided.
 *
 *
 * A virtual bcam uses one or multiple segments of the 256 segments. Two virtual bcams can not
 * share any segments. Up to 128 virtual bcams are supported per bcam and each virtual bcam is identified with a unique 7 bit identifier (vcid). The
 * user must ensure that the vcids are unique and that two vcids do not use the same segments. No checks are made and failing to ensure this results in
 * undefined behavior. The idea is that if the virtual bcams are created from different SW processes, the SW memory gets isolated and
 * protected by the OS. Different processes might also execute on different cores allowing for independent processing performance.
 * The requested segments and the vcid are passed in the cam_arg together with other arguments which are common for the bcam. The common parameters are
 * key width, lookup rate, response width and number of entries among others. Number of entries is the total number of entries for the bcam.
 * This number is automatically (internally) divided by 256 for each segment. The SW shadow for the segments and all hw memory for the segments are
 * cleared by this function.
 *
 * In the HW data path all packets must be
 * classified to a virtual bcam (vcid). The vcid is used to select the right segment mapping table. Each virtual bcam has its own
 * segment mapping table. The segment mapping table contains 256 entries and is populated by this function. The virtual bcam's segments as
 * specified in cam_arg are sprayed out over the 256 entries. E.g. If segment 1 ,23 and 78 are allocated, then the
 * segment mapping table is set to segment_map[0] = 1, segment_map[1] = 23, segment_map[2] = 78,segment_map[3] = 0, ...., segment_map[254] = 78
 * and segment_map[255] = 1. The entry in the segment mapping table is picked
 * based on an eight bit hash value of the key. For correct operation the HW datapath should not classify any packets to a
 * virtual bcam (vcid) which is not yet created by this function.
 * Returns 0 if successful, otherwise an error code Returns 0 if successful, otherwise an error code. A shadow of the hw memory
 * is created for fast read accesses.
 *
 * @param[in] cam_arg    Arguments used to create the virtual bcam instance. cam_arg is copied to the
 *                       virtual bcam instance, and can be destroyed immediately after this call.
 *
 * @param[out] out_vbcam Returns the newly created virtual bcam instance, memory is allocated.
 *                       If vbcam_create returns an error the instance is not created.
 *                       In this case no memory is allocated, and out_bcam is left unchanged.
 *
 * @return               Returns 0 for success, otherwise the error code.
 */
int vbcam_create(const cam_arg_t *cam_arg, struct vbcam **out_vbcam);


/**
 * Inserts an entry to the virtual bcam instance. If the key of the entry is found in the vbcam,
 * the function fails by returning error code CAM_ERROR_DUPLICATE_FOUND.
 * If the entry is not found, then it is inserted to the vbcam instance.
 * Returns 0 if successful, otherwise an error code.
 *
 * @param[in] vbcam     Pointer to the virtual bcam instance
 *
 * @param[in] key       The key of the entry. The key width is passed in cam_arg to vbcam_create. the key width is
 *                      set using cam_arg_set_key_width. Any contents outside the scope of the key width is ignored.
 *                      The key is assumed to be in little-endian format.
 *                      key[0] bit 0 is the least significant bit of the key.
 *                      key[1] bit 0 is bit 8 of the key and so on.
 *                      For vbcams using hbm, mixed mode is supported.
 *                      This means that a second key width is supported. In addition to the wide regular key width
 *                      specified by cam_arg_set_key_width, a new narrow key width specified by cam_set_narrow_key_width
 *                      is supported. both wide and narrow keys can be inserted in the same vbcam.
 *                      Narrow keys saves hbm memory, e.g an IPv6 flow can
 *                      be stored as a wide key and an IPv4 flow can be stored as narrow key of half the entry size.
 *                      If the inserted key is wide or narrow is specified by the options argument.
 *
 * @param[in] response  The response of the entry. The response width of the response is the
 *                      same for all functions calls and was originally passed in the cam_arg to
 *                      vbcam_create when the instance was created. The response width in cam_arg
 *                      is specified with cam_arg_set_response_width.
 *                      Any contents outside the scope of the response width is ignored.
 *                      The response is assumed to be in little-endian format.
 *                      response[0] bit 0 is the least significant bit of the response.
 *                      response[1] bit 0 is bit 8 of the response and so on.
 *
 * @param[in] options   The options argument is a pointer to additional control
 *                      arguments which are set using the cam_options_*** functions. Options is copied inside the function and can
 *                      therefore be immediately destroyed after the call.
 *
 * @return              Returns 0 for success, otherwise the error code.
 *
 */
int vbcam_insert(struct vbcam* vbcam, const uint8_t key[], const uint8_t response[], const cam_options_t *options);



/**
 * Updates an entry in the vbcam. If the entry is found, the response is updated.
 * If the entry is not found, the function fails with error code CAM_ERROR_KEY_NOT_FOUND.
 * Returns 0 if successful, otherwise an error code.
 *
 * @param[in] vbcam     Pointer to the vbcam instance
 *
 * @param[in] key       See key for vbcam_insert
 *
 * @param[in] response  See response vbcam_insert
 *
 * @param[in] options   See options for vbcam_insert
 *
 * @return              Returns 0 for success, otherwise the error code.
 *
 */
int vbcam_update(struct vbcam *vbcam, const uint8_t key[], const uint8_t response[], const cam_options_t *options);



/**
 * Gets an entry with matching response value. If an entry is found, the function returns 0.
 * If the entry is not found, the function fails with error code CAM_ERROR_KEY_NOT_FOUND.
 *
 * The pos argument enables multiple matching entries to be found. The first time the function is
 * called pos should be set to zero. To find all entries matching the response, the function is
 * called multiple times, each call returns one matching entry.
 * For every consecutive call the returned pos value must be used again as input argument.
 * When CAM_ERROR_KEY_NOT_FOUND is returned no more entries matching the response could be found.
 *
 * The response_mask is used to limit the search to subfields of the response. If the complete,
 * exact response value is searched, then all response_mask bits should be set to one.
 * By setting the response_mask bits to all zeros, any response value will match.
 * This can be used for getting all entries without prior knowledge of the response values.
 *
 * The get function does not read from the hardware. It reads from the shadow.
 * vbcam_get_by_response uses linear search.
 *
 * If vbcam_cam_get_by_response is called multiple times using the pos argument it should be noted that
 * vbcam_insert can not be used between the calls since the pos argument then becomes invalid.
 *
 * * @param[in]       vbcam           Pointer to the vbcam instance
 *
 * @param[in]       response        The response to search for. See vbcam_insert,
 *
 * @param[in]       response_mask   The response and response_mask are ANDed and then
 *                                  searched for. The stored response is also ANDed
 *                                  with the response_mask before compare takes place.
 *                                  Cleared bits in the response_mask works as "don't care"
 *                                  bits.
 *                                  The response_mask is in little-endian format.
 *
 * @param[in,out]   pos             Position in the database. Used for
 *                                  consecutive get operations, set to 0 for
 *                                  first get_by_response. If the function
 *                                  returns with an error code, the pos cannot be sent in again. It is unreliable.
 *                                  The exception is for the error code CAM_ERROR_FOUND_IN_SHADOW_BUT_NOT_IN_HW. For
 *                                  this error code pos can be sent in again to resume the search.
 *
 * @param[out]      out_key         The read key. Key width bits are copied to the key.
 *                                  The key is in little-endian format. If the function
 *                                  returns with an error code, the  out_key is left unchanged except for the error code
 *                                  CAM_ERROR_FOUND_IN_SHADOW_BUT_NOT_IN_HW. For this error code the out_key contains the response
 *                                  stored in the shadow.
 *
 * @param[in]       options         See options for vbcam_insert
 *
 * @return                          Returns 0 for success, otherwise the error code.
 *
 */
int vbcam_get_by_response(struct vbcam *vbcam, const uint8_t response[],
        const uint8_t response_mask[], uint32_t *pos,
        uint8_t out_key[], const cam_options_t *options);


/**
 * Gets an entry with matching key from the vbcam instance.
 * If an entry is not found, the response data is copied from the default response and the return code is CAM_ERROR_KEY_NOT_FOUND.
 * If an entry is found in the instance, the function returns 0 and the response associated with the key is passed.
 *
 * @param[in]   vbcam       Pointer to the vbcam instance
 *
 * @param[in]   key         See key for vbcam_insert
 *
 * @param[out]  response    The response of the entry. The response width was originally passed in the
 *                          cam_arg to vbcam_create when the instance was created. The response width in cam_arg
 *                          is specified with cam_arg_set_response_width.
 *                          Any contents outside the scope of the response width is left unchanged.
 *                          The response is assumed to be in little-endian format.
 *                          response[0] bit 0 is the least significant bit of the response.
 *                          response[1] bit 0 is bit 8 of the response and so on. If the function
 *                          returns with an error code, the  response is left unchanged except for the error code
 *                          CAM_ERROR_FOUND_IN_SHADOW_BUT_NOT_IN_HW. For this error code the response contains the response
 *                          stored in shadow
 *
 * @param[in]   options     See options for vbcam_insert
 *
 * @return                  Returns 0 for success, otherwise the error code.
 *
 */
int vbcam_get_by_key(struct vbcam *vbcam, const uint8_t key[], uint8_t response[], const cam_options_t *options);



/**
 * Delete an entry from the vbcam. If the entry is found, the function returns 0.
 * If an entry is not found, the function fails with error code CAM_ERROR_KEY_NOT_FOUND.
 *
 * @param[in] vbcam     Pointer to the vbcam instance
 *
 * @param[in] key       See key for vbcam_insert
 *
 * @param[in] options   See options for vbcam_insert
 *
 * @return              Returns 0 for success, otherwise the error code.
 *
 */
int vbcam_delete(struct vbcam *vbcam, const uint8_t key[], const cam_options_t *options);



/**
 * Computes the hash value of the key. This function is used together with vbcam_get_segment to know
 * in which segment a key will be stored. This can be useful in a multi-threaded environment to guarantee
 * a thread exclusive rights to a segment. Each segment contains state information and should only be
 * accessed by one thread at a time.  The computed hash value can be passed to the other api functions using
 * CAM_OPTIONS_USE_PRECOMPUTED_HASH. The pre-computed hash value will then be used, thus avoiding the hash value
 * to be computed twice. If a pre-computed hash value is passed to vbcam_insert, vbcam_delete,
 * vbcam_get_by_key etc, the passed key must match the hash value, otherwise the behavior is undefined.
 *
 * @param[in]   vbcam           Pointer to the vbcam instance
 *
 * @param[in]   key             See key for vbcam_insert
 *
 * @param[out]  hash_value      The computed hash value
 *
 * @param[in]   options         See options for vbcam_insert
 *
 * @return                      Returns 0 for success, otherwise the error code.
 *
 */
int vbcam_compute_hash_value(const struct vbcam *vbcam, const uint8_t key[], uint8_t hash_value[32],
        const cam_options_t *options);


/**
 * Provides the segment in which keys with the computed hash value are stored.
 *
 * @param[in]   vbcam           Pointer to virtual bcam instance
 *
 * @param[in]   hash_value      The hash value as returned from vbcam_calculate_hash_value
 *
 * @param[out]  segment         The segment associated with the hash value
 *
 * @return                      Returns 0 for success, otherwise the error code.
 *
 */
int vbcam_get_segment(const struct vbcam *vbcam, const uint8_t hash_value[32], uint16_t *segment);

/**
 * Deletes all entries from the vbcam. Prior to the call all segments needs to be locked in a multi-threaded
 * environment. When the call returns the segments should be unlocked. Segments can also be deleted one by one,
 * use the options argument to specify single segment. For single segment just lock/unlock a single segment.
 * The function always return 0. The function does not respect max_hw_writes in cam_arg.
 *
 * @param[in] vbcam     Pointer to the vbcam instance
 *
 * @param[in] options   See options for vbcam_insert
 *
 * @return              Returns 0
 *
 */
int vbcam_delete_all(struct vbcam* vbcam, const cam_options_t *options);


/**
 * Destroys a virtual bcam instance. All memory allocated by vbcam_create is released. No hw is touched by this function.
 *
 * @param[in]   vbcam    Pointer to the virtual bcam instance
 *
 * @return               Returns 0 for success, otherwise the error code.
 *
 */
int vbcam_destroy(struct vbcam *vbcam);


/**
 * See bcam_read_and_clear_ecc_counters. ECC counters are not supported for individual segments. The counters show the total
 * for all segments. This function is just a wrapper for bcam_read_and_clear_ecc_counters
 *
 * @param[in]  vbcam                        Pointer to virtual bcam instance
 *
 * @param[out] corrected_single_bit_errors  The number of corrected single bit errors, see bcam_read_and_clear_ecc_counters for details.
 *
 * @param[out] detected_double_bit_errors   The number of detected double-bit errors, see bcam_read_and_clear_ecc_counters for details.
 *
 * @return                                  Returns 0 for success, otherwise the error code.
 */
int vbcam_read_and_clear_ecc_counters(struct vbcam *vbcam, uint32_t *corrected_single_bit_errors,
        uint32_t *detected_double_bit_errors);


/**
 * See bcam_read_and_clear_ecc_addresses. ECC addresses are not supported for individual segments. The recorded addresses are shared for all segments.
 * This function is just a wrapper for bcam_read_and_clear_ecc_addresses
 *
 * @param[in]  vbcam                             Pointer to virtual bcam instance
 *
 * @param[out] failing_address_single_bit_error  The address of the first single bit error detected and corrected, see bcam_read_and_clear_ecc_addresses.
 *
 * @param[out] failing_address_double_bit_error  The address of the first double-bit error detected, see bcam_read_and_clear_ecc_addresses.
 *
 * @return                                       Returns 0 for success, otherwise the error code.
 *
 */
int vbcam_read_and_clear_ecc_addresses(struct vbcam *vbcam, uint32_t *failing_address_single_bit_error,
        uint32_t *failing_address_double_bit_error);


/**
 * Set error injection for ECC test. Error injection makes subsequently inserted entries to be stored in memory with errors.
 * This function is not supported for HBM.
 *
 * @param[in] vbcam                              Pointer to virtual bcam instance
 *
 * @param[in] inject_single_bit_errors           Enable insertion of single-bit errors (correctable).
 *
 * @param[in] inject_double_bit_errors           Enable insertion of double-bit errors (uncorrectable).
 *
 * @return                                       Returns 0 for success, otherwise the error code.
 *
 */
int vbcam_set_ecc_test(struct vbcam* vbcam, bool inject_single_bit_errors,
                       bool inject_double_bit_errors);


/**
 * When the  hw write, hw read, hw_write_sequence_start, hw_write_sequence_end,
 * info print and error print callbacks are called due to an operation in a segment, the original context as set by
 * cam_arg_set_inst_ctx is replaced with a new context pointer of type segment_ctx_t *
 * containing the segment number.
 * The segment number indicates which segment the callback refers to. In addition to the segment number, the
 * new context pointer also contains the original context pointer. The memory for the new contexts
 * is allocated in vbcam_create and de-allocated in vbcam_destroy. The vbcam also performs callbacks
 * which are not related  to a particular segment. This is for instance the case when the segment mapping table
 * for the vcid is configured in vbcam_create. The segment mapping table is used by all segments. Callbacks not
 * related to a particular segment sets the segment to -1.
 */
typedef struct {
    void *ctx;
    int16_t segment;
} segment_ctx_t;


/** @}*/

#ifdef __cplusplus
}
#endif

#endif
