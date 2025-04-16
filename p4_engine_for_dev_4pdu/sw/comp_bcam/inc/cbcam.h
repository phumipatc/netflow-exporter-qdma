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
 * Public API of the Hardware Managed BCAM.
 *
 * @file cbcam.h
 *
 *
 * @addtogroup cbcam Hardware Managed BCAM Public API
 * @{
 */

#ifndef _CBCAM_H_
#define _CBCAM_H_


#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ccam.h"

#ifdef __cplusplus
extern "C" {
#endif

// Forward declaration of the cbcam struct.
struct cbcam;


/**
 * Returns the size of cbcam instance in bytes. The size is useful for allocating the right amount of memory
 * for the cbcam instance.
 *
 * @return              The size of cbcam in bytes
 */
size_t cbcam_size(void);

/**
 * Initializes a cbcam instance. Returns 0 if successful, otherwise an error code. Memory for
 * the cbcam instance must be allocated but not necessarily cleared prior to calling cbcam_init.
 * The instance is initialized using passed arguments containing hw read/write functions,
 * debug flags and optimization flags and other infromation. In addition to this HW configuration
 * data is read from the HW itself. This way the CAM driver can be used for many different
 * HW configurations. The cbcam is HW managed which means that the basic insert, update, delete
 * and get_by_key functions are implemented in HW and that the CAM driver writes high level
 * commands to the HW to get them executed. The CAM driver does not use shadow memory and
 * no heap allocations take place inside the driver. A cbcam instance is a superset of a
 * ccam instance. This means that all the functions in the ccam.h API can be used for the cbcam
 * after typecasting to ccam.
 *
 * @param[in]   arg         Arguments used to initialize the cbcam instance. the content of arg is copied to the
 *                          cbcam instance
 *
 * @param[out]  cbcam       Returns the initialized  cbcam instance.
 *
 *
 * @return                  Returns 0 for success, otherwise the error code.
 */
int cbcam_init(const struct ccam_arg *arg, struct cbcam *cbcam);



/**
 * Inserts an entry to the cbcam instance. If an entry with the same key is found, the function fails by returning
 * error code CCAM_ERROR_DUPLICATE_FOUND.
 * If the entry is not found, then it is inserted in the cbcam instance.
 * Returns 0 if successful, otherwise an error code. If an error code is returned nothing is inserted.
 *
 * @param[in] cbcam     Pointer to the cbcam instance
 *
 * @param[in] key       The key of the entry. The key width is read from the HW configuration during cbcam_init.
 *                      Any contents outside the scope of the key width is ignored.
 *                      The key is assumed to be in little-endian format.
 *                      key[0] bit 0 is the least significant bit of the key.
 *                      key[1] bit 0 is bit 8 of the key and so on.
 *
 * @param[in] response  The response of the entry. The response width is read from the HW configuration
 *                      during cbcam_init.
 *                      Any contents outside the scope of the response width is ignored.
 *                      The response is assumed to be in little-endian format.
 *                      response[0] bit 0 is the least significant bit of the response.
 *                      response[1] bit 0 is bit 8 of the response and so on.
 *
 * @return              Returns 0 for success, otherwise the error code.
 *
 */
int cbcam_insert(struct cbcam *cbcam, const uint8_t key[], const uint8_t response[]);



/**
 * Updates an entry in the cbcam instance. If the entry is found, the response is updated.
 * If the entry is not found, the function fails with error code CCAM_NOT_FOUND.
 * Returns 0 if successful, otherwise an error code.
 *
 * @param[in] cbcam     Pointer to the cbcam instance
 *
 * @param[in] key       See key for cbcam_insert
 *
 * @param[in] response  See response for cbcam_insert
 *
 * @return              Returns 0 for success, otherwise the error code.
 *
 */
int cbcam_update(struct cbcam *cbcam, const uint8_t key[], const uint8_t response[]);



/**
 * Gets an entry with matching key from the cbcam instance.
 * If an entry is not found, the return code is CCAM_NOT_FOUND.
 * If an entry is found in the instance, the function returns 0 and the response associated with the key is passed.
 *
 * @param[in]   cbcam       Pointer to the cbcam instance
 *
 * @param[in]   key         See key for cbcam_insert
 *
 * @param[out]  response    The response width is read from the HW configuration
 *                          during cbcam_init.
 *                          Only response width bits are written to the out argument.
 *                          The response is assumed to be in little-endian format.
 *                          response[0] bit 0 is the least significant bit of the response.
 *                          response[1] bit 0 is bit 8 of the response and so on.
 *
 * @return                  Returns 0 for success, otherwise the error code.
 *
 */
int cbcam_get_by_key(struct cbcam *cbcam, const uint8_t key[], uint8_t response[]);


/**
 * Deletes all entries from the cbcam instance.
 *
 * @param[in] cbcam     Pointer to the cbcam instance
 *
 * @return              Returns 0 for success, otherwise the error code.
 *
 */
int cbcam_delete_all(struct cbcam *cbcam);


/**
 * Deletes an entry from the cbcam instance. If the entry is found, the function returns 0.
 * If an entry is not found, the function fails with error code CCAM_NOT_FOUND.
 *
 * @param[in] cbcam     Pointer to the cbcam instance
 *
 * @param[in] key       See key for cbcam_insert
 *
 * @return              Returns 0 for success, otherwise the error code.
 *
 */
int cbcam_delete(struct cbcam *cbcam, const uint8_t key[]);


/**
 * Gets an entry with matching response from the cbcam instance.
 * The function uses linear search and reads address by address form the HW. Many entries might
 * have a matching response. To get all matching responses cbcam_get_by_response can be called
 * repeatedly until CCAM_NOT_FOUND is returned.
 * The first time a response is searched, pos should be cleared.
 * For succeeding calls the returned pos should be passed in again. pos keeps track of
 * the address in  the linear search that takes place.
 *
 * @param[in]       cbcam           Pointer to the cbcam instance
 *
 * @param[in]       in_response     The response to search for.
 *                                  The response width is read from the HW configuration during cbcam_init.
 *                                  Any contents outside the scope of the response width is ignored.
 *                                  The in_response is assumed to be in little-endian format.
 *                                  in_response[0] bit 0 is the least significant bit of the in_response.
 *                                  in_response[1] bit 0 is bit 8 of the in_response and so on.
 *
 * @param[in]       response_mask   The in_response is masked (ANDed)
 *                                  with response_mask and then compared
 *                                  with response_mask masked (ANDed) with the stored response.
 *                                  If the comparision is successful there is a match. This way
 *                                  sub-fields of the response can be searched for.
 *                                  The response width is read from the HW configuration during cbcam_init.
 *                                  Any contents outside the scope of the response width is ignored.
 *                                  The response_mask is assumed to be in little-endian format.
 *                                  response_mask[0] bit 0 is the least significant bit of the response_mask.
 *                                  response_mask[1] bit 0 is bit 8 of the response_mask and so on.
 *
 * @param[in,out]   pos             The position pointer used for the linear search. Should be
 *                                  cleared the first time a response is searched. Should be
 *                                  fed in again for consecutive searches of the same response
 *
 * @param[out]      out_key         The key for the matching response.
 *                                  The key width is read from the HW configuration
 *                                  during cbcam_init.
 *                                  Only key width bits are written to out_key.
 *                                  The  out_key is assumed to be in little-endian format.
 *                                  out_key[0] bit 0 is the least significant bit of the out_key.
 *                                  out_key[1] bit 0 is bit 8 of the out_key and so on.
 *
 * @param[out]      out_response    The stored response of the matching response. If the
 *                                  response_mask is all 'ones' then out_respone and in_response
 *                                  are equal.
 *                                  The response width is read from the HW configuration
 *                                  during cbcam_init.
 *                                  Only response width bits are written to out_response.
 *                                  The  out_response is assumed to be in little-endian format.
 *                                  out_response[0] bit 0 is the least significant bit of the out_resposne.
 *                                  out_response[1] bit 0 is bit 8 of the out_response and so on.
 *
 * @return          Returns 0 for success, otherwise the error code.
 *
 */
int cbcam_get_by_response(struct cbcam *cbcam, const uint8_t in_response[], const uint8_t response_mask[],
                          uint32_t *pos, uint8_t out_key[], uint8_t out_response[]);



/** @}*/
#ifdef __cplusplus
}
#endif

#endif
