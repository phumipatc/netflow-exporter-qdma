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
 * Public API of the Hardware Managed STCAM.
 *
 * @file cstcam.h
 *
 *
 * @addtogroup cstcam Hardware Managed STCAM Public API
 * @{
 */

#ifndef _CSTCAM_H_
#define _CSTCAM_H_


#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ccam.h"

#ifdef __cplusplus
extern "C" {
#endif

// Forward declaration of the cstcam struct.
struct cstcam;


/**
 * Returns the size of cstcam instance in bytes. The size is useful for allocating the right amount of memory
 * for the cstcam instance.
 *
 * @return              The size of the cstcam in bytes
 */
size_t cstcam_size(void);


/**
 * Initializes a cstcam instance. Returns 0 if successful, otherwise an error code. Memory for
 * the cstcam instance must be allocated but not necessarily cleared prior to calling cstcam_init.
 * The instance is initialized using passed arguments containing hw read/write functions,
 * debug flags and optimization flags and other information. In addition to this HW configuration
 * data is read from the HW itself. This way the CAM driver can be used for many different
 * HW configurations. The cstcam is HW managed which means that the basic insert, update, delete
 * and get_by_key functions are implemented in HW and that the CAM driver writes high level
 * commands to the HW to get them executed. The CAM driver does not use shadow memory and
 * no heap allocations take place inside the driver. A cstcam instance is a superset of a
 * ccam instance. This means that all the functions in the ccam.h API can be used for the cstcam
 * after typecasting to ccam.
 * The HW is configured in either cache or standalone mode. In cache mode the API is limited to the cstcam_size,
 * cstcam_init, cstcam_get_stats, cstcam_mu_alloc and cstcam_mu_free functions.
 * There are two sets of functions used in standalone mode for the convenience of the user. One set uses the full mask as argument.
 * The other set uses a mask_id as argument. The full mask set includes the cstcam_insert, cstcam_delete and
 * cstcam_update functions. The mask_id set includes the cstcam_insert_by_id, cstcam_delete_by_id,
 * cstcam_update_by_id, cstcam_mask_alloc and cstcam_mask_free functions.
 * The mask_id to use is obtained by first calling the cstcam_mask_alloc function
 * which assigns a mask_id to the full mask. When a mask is not used anymore, the mask_id and its associated HW resources
 * should be released by calling cstcam_mask_free. The full mask set and mask_id set of functions can not be used at the same time.
 * The set of functions to use is selected automatically the first time cstcam_mask_alloc or cstcam_insert is called.
 * cstcam_size, cstcam_insit, cstcam_get_by_key, cstcam_get_by_response and cstcam_get_stats can be used for both sets.
 *
 * @param[in]   arg         Arguments used to initialize the cstcam instance. the content of arg is copied to the
 *                          cstcam instance
 *
 * @param[out]  cstcam      Returns the initialized  cstcam instance.
 *
 *
 * @return                  Returns 0 for success, otherwise the error code.
 */
int cstcam_init(const struct ccam_arg *arg, struct cstcam *cstcam);


/**
 * This function can only be used when the HW is configured for standalone mode.
 * Inserts an entry to the cstcam instance. If an entry with the same key and mask is found, the function fails by returning
 * error code CCAM_ERROR_DUPLICATE_FOUND.
 * If the entry is not found, then it is inserted in the cstcam instance. If an entry with a new mask is inserted,
 * the mask is created.
 *
 * Returns 0 if successful, otherwise an error code. If an error code is returned nothing is inserted.
 *
 * @param[in] cstcam     Pointer to the cstcam instance
 *
 * @param[in] key       The key of the entry. The key width is read from the HW configuration during cstcam_init.
 *                      Any contents outside the scope of the key width is ignored.
 *                      The key is assumed to be in little-endian format.
 *                      key[0] bit 0 is the least significant bit of the key.
 *                      key[1] bit 0 is bit 8 of the key and so on.
 *
 * @param[in] mask      The ternary mask. The key width is read from the HW configuration during cstcam_init.
 *                      Any content outside the scope of the defined key width is ignored.
 *                      The ternary mask is assumed to be in little-endian format.
 *                      mask[0] bit 0 is the least significant bit of the ternary mask.
 *                      mask[1] bit 0 is bit 8 of the ternary mask and so on.
 *
 *
 * @param[in] priority  The priority of the entry. If multiple matches occur, the winning matching
 *                      entry is determined based on the priority value. The entry with the lowest priority
 *                      wins. Two different masks cannot have the same priority. The first insert for a mask
 *                      determines the priority of the mask. Subsequent inserts to that mask must use the same priority.
 *                      Priority values greater than what can be represented by the defined priority
 *                      width generates an error code.
 *
 * @param[in] response  The response of the entry. The response width is read from the HW configuration
 *                      during cstcam_init.
 *                      Any contents outside the scope of the response width is ignored.
 *                      The response is assumed to be in little-endian format.
 *                      response[0] bit 0 is the least significant bit of the response.
 *                      response[1] bit 0 is bit 8 of the response and so on.
 *
 * @return              Returns 0 for success, otherwise the error code.
 *
 */
int cstcam_insert(struct cstcam *cstcam, const uint8_t key[], const uint8_t mask[], uint32_t priority,
        const uint8_t response[]);


/**
 * This function can only be used when the HW is configured for standalone mode and the full mask set of functions is used.
 * Updates an entry in the cstcam instance. If the entry is found, the response is updated.
 * If the entry is not found, the function fails with error code CCAM_NOT_FOUND.
 * Returns 0 if successful, otherwise an error code.
 *
 * @param[in] cstcam    Pointer to the cstcam instance
 *
 * @param[in] key       See key for cstcam_insert
 *
 * @param[in] mask      See mask for cstcam_insert
 *
 * @param[in] response  See response for cstcam_insert
 *
 * @return              Returns 0 for success, otherwise the error code.
 *
 */
int cstcam_update(struct cstcam *cstcam, const uint8_t key[], const uint8_t mask[], const uint8_t response[]);



/**
 * This function can only be used when the HW is configured for standalone mode.
 * Gets an entry with matching key from the cbcam instance.
 * If an entry is not found, the return code is CCAM_NOT_FOUND.
 * If an entry is found in the instance, the function returns 0 and the response associated with the key is passed.
 *
 * @param[in]   cstcam      Pointer to the cstcam instance
 *
 * @param[in]   key         See key for cstcam_insert
 *
 * @param[in]   mask        See mask for cstcam_insert
 *
 * @param[out]  response    The response width is read from the HW configuration
 *                          during cstcam_init.
 *                          Only response width bits are written to the out argument.
 *                          The response is assumed to be in little-endian format.
 *                          response[0] bit 0 is the least significant bit of the response.
 *                          response[1] bit 0 is bit 8 of the response and so on.
 *
 * @return                  Returns 0 for success, otherwise the error code.
 *
 */
int cstcam_get_by_key(struct cstcam *cstcam, const uint8_t key[], const uint8_t mask[], uint8_t response[]);



/**
 * This function can only be used when the HW is configured for standalone mode and the full mask set of functions is used.
 * Deletes an entry from the cstcam instance. If the entry is found, the function returns 0.
 * If an entry is not found, the function fails with error code CCAM_NOT_FOUND.
 *
 * @param[in] cstcam   Pointer to the cstcam instance
 *
 * @param[in] key       See key for cstcam_insert
 *
 * @param[in] mask      See mask for cstcam_insert
 *
 * @return              Returns 0 for success, otherwise the error code.
 *
 */
int cstcam_delete(struct cstcam *cstcam, const uint8_t key[], const uint8_t mask[]);

/**
 * This function can only be used when the HW is configured for standalone mode.
 * .Gets an entry with matching response from the cstcam instance.
 * The function uses linear search and reads address by address from the HW. Many entries might
 * have a matching response. To get all matching responses cstcam_get_by_response can be called
 * repeatedly until CCAM_NOT_FOUND is returned.
 * The first time a response is searched, pos should be cleared.
 * For succeeding calls the returned pos should be passed in again. pos keeps track of
 * the address in  the linear search that takes place.
 *
 * @param[in]       cstcam           Pointer to the cstcam instance
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
 * @param[out]      out_mask        The mask for the matching response.
 *                                  The key width is read from the HW configuration
 *                                  during cstcam_init.
 *                                  Only key width bits are written to out_mask.
 *                                  The  out_mask is assumed to be in little-endian format.
 *                                  out_mask[0] bit 0 is the least significant bit of the out_mask.
 *                                  out_mask[1] bit 0 is bit 8 of the out_mask and so on.
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
 * @param[out]      out_prio        The priority for the matching response.
 *
 * @return          Returns 0 for success, otherwise the error code.
 *
 */
int cstcam_get_by_response(struct cstcam *cstcam, const uint8_t in_response[], const uint8_t response_mask[],
        uint32_t *pos, uint8_t out_key[], uint8_t out_mask[], uint8_t out_response[], uint32_t *out_prio);

#define CSTCAM_MAX_MASKS 64

/*
 * defines for stats_group for cstcam_get_stats
 *
 */
#define CSTCAM_STATS_EFFICIENCY 0
#define CSTCAM_STATS_MEMORY_USAGE 1


/*
 * The efficiency per mask is calculated during 1 second. The total number of hits for the mask is summed up and then
 * divided by the amount of memory resources to obtain an average.
 * The hit counters used for the calculation are sampled by the hardware every second. The sample is taken for all masks the
 * same clock cycle so the mask efficiency can be meaningfully compared. If a memory has been added or deleted to mask,
 * it would take almost 2 seconds in the worst case before the mask has an accurate efficiency value again. The reason for
 * this when a memory unit is added is that the hit counter of the memory unit needs a full sample period (1s) to get its
 * right value and the next full sample period started (unluckily) almost 1s after we added the memory unit. When a
 * memory unit is deleted from a mask, the remaining memory units are likely to receive a lot more hits and this efficiency
 * improvement must be measured before any new decisions can be made based on mask efficiency.
 *
 */
struct cstcam_mask_efficiency {
    struct tuple {
        uint16_t mask_id;
        uint32_t efficiency;
    } tuple[CSTCAM_MAX_MASKS];
    uint8_t num_masks;
};

struct cstcam_mask_memory_usage {
    uint32_t num_masks;
    uint32_t phys_units;
    uint32_t num_slots;
    struct {
        uint32_t mask_id;
        uint32_t num_mus;
    } usage[CSTCAM_MAX_MASKS];
};

/*
 * See documentation for each struct in the union.
 *
 */
union cstcam_stats {
    struct cstcam_mask_efficiency mask_efficiency;
    struct cstcam_mask_memory_usage memory_usage;
    struct cstcam_reserved {
        uint8_t resv[1000];
    } reserved;
};

/**
 * Reads statistics information. The statistics information
 * is organized in different groups. The statistics associated with a certain group is read from the instance.
 * See cstcam_stats union for more information
 *
 * @param[in]   cstam           Pointer to cstcam instance
 *
 * @param[in]   stats_group     Selects the group of statistics to be read.
 * @param[out]  stats           The read statistics
 *
 * @retval 0                    Success.
 *
 * @retval CCAM_ERROR_ENVIRONMENT_POLLED_OUT
 *                              It was not possible to read from the hardware.
 */
int cstcam_get_stats(const struct cstcam *cstcam, uint64_t stats_group, union cstcam_stats *stats);

/**
 * This function can only be used when the HW is configured for cache mode.
 * Finds unallocated  memory and allocates it to the mask. The first time memory is allocated
 * to the mask, the mask_id is bound to the mask. The mask_id should be seen as compression identifier
 * and is unique per mask. I.e. the same mask_id can not be used for multiple masks. For successive
 * allocations to the same mask, the same mask_id must be used.
 *
 * @param[in]   cstam           Pointer to cstcam instance
 *
 * @param[in]   mask            The mask to allocate memory for
 * @param[in]   mask_id         The mask_id associated to the mask
 *
 * @retval 0                    Success.
 *
 * @retval CAM_ERROR_INVALID_ARG
 *                              The mask_id is out of range.
 *
 * @retval CAM_ERROR_WRONG_API  The hardware is not in cache mode.
 *
 * @retval CAM_ERROR_NO_MASK    The mask_id has previously been used for a different mask, or a
 *                              different mask_id has previously been used for the same mask.
 *
 * @retval CAM_ERROR_FULL       No free memory units are available, or the number of distinct masks with
 *                              memory allocated to them has reached the limit set when the CAM was
 *                              dimensioned (set CCAM_OPTIMIZE_MASKS to disable the latter case).
 */
int cstcam_mu_alloc(struct cstcam *cstcam, const uint8_t mask[], uint16_t mask_id);

/**
 * This function can only be used when the HW is configured for cache mode.
 * Clears and frees memory for the mask associated to mask_id.
 *
 * @param[in]   cstam           Pointer to cstcam instance
 *
 * @param[in]   mask_id         The mask_id associated to the mask
 *
 * @retval 0                    Success.
 *
 * @retval CAM_ERROR_INVALID_ARG
 *                              The mask_id is out of range.
 *
 * @retval CAM_ERROR_WRONG_API  The hardware is not in cache mode.
 *
 * @retval CAM_ERROR_NOT_FOUND  No memory units were assigned to the given mask_id.
 */
int cstcam_mu_free(struct cstcam *cstcam, uint16_t mask_id);

#define CSTCAM_MAX_MASK_IDS 1024

/**
 * This function can only be used when the HW is configured for standalone mode and the mask_id set of functions is used.
 * Inserts an entry to the cstcam instance. If an entry with the same key and mask is found, the function fails by returning
 * error code CCAM_ERROR_DUPLICATE_FOUND.
 * If the entry is not found, then it is inserted in the cstcam instance.
 * Returns 0 if successful, otherwise an error code. If an error code is returned nothing is inserted.
 *
 * @param[in] cstcam     Pointer to the cstcam instance
 *
 * @param[in] key       The key of the entry. The key width is read from the HW configuration during cstcam_init.
 *                      Any contents outside the scope of the key width is ignored.
 *                      The key is assumed to be in little-endian format.
 *                      key[0] bit 0 is the least significant bit of the key.
 *                      key[1] bit 0 is bit 8 of the key and so on.
 *
 * @param[in] mask_id   The mask_id. This must be a mask_id previously returned by cstcam_mask_alloc.
 *
 *
 * @param[in] priority  The priority of the entry. If multiple matches occur, the winning matching
 *                      entry is determined based on the priority value. The entry with the lowest priority
 *                      wins. If there are multiple matches with the same lowest priority, any of them becomes
 *                      the winner.
 *                      Priority values greater than what can be represented by the defined priority
 *                      width generates an error code.
 *
 * @param[in] response  The response of the entry. The response width is read from the HW configuration
 *                      during cstcam_init.
 *                      Any contents outside the scope of the response width is ignored.
 *                      The response is assumed to be in little-endian format.
 *                      response[0] bit 0 is the least significant bit of the response.
 *                      response[1] bit 0 is bit 8 of the response and so on.
 *
 * @return              Returns 0 for success, otherwise the error code.
 *
 */
int cstcam_insert_by_id(struct cstcam *cstcam, const uint8_t key[], uint16_t mask_id,
        const uint8_t response[]);

/**
 * This function can only be used when the HW is configured for standalone mode and the mask_id set of functions is used.
 * Deletes an entry from the cstcam instance. If the entry is found, the function returns 0.
 * If an entry is not found, the function fails with error code CCAM_NOT_FOUND.
 *
 * @param[in] cstcam   Pointer to the cstcam instance
 *
 * @param[in] key       See key for cstcam_insert
 *
 * @param[in] mask_id   See mask_id for cstcam_insert_by_id
 *
 * @return              Returns 0 for success, otherwise the error code.
 *
 */
int cstcam_delete_by_id(struct cstcam *cstcam, const uint8_t key[], uint16_t mask_id);

/**
 * This function can only be used when the HW is configured for standalone mode and the mask_id set of functions is used.
 * Updates an entry in the cstcam instance. If the entry is found, the response is updated.
 * If the entry is not found, the function fails with error code CCAM_NOT_FOUND.
 * Returns 0 if successful, otherwise an error code.
 *
 * @param[in] cstcam    Pointer to the cstcam instance
 *
 * @param[in] key       See key for cstcam_insert
 *
 * @param[in] mask_id   See mask_id for cstcam_insert_by_id
 *
 * @param[in] response  See response for cstcam_insert
 *
 * @return              Returns 0 for success, otherwise the error code.
 *
 */
int cstcam_update_by_id(struct cstcam *cstcam, const uint8_t key[], uint16_t mask_id, const uint8_t response[]);

/**
 * This function can only be used when the HW is configured for standalone mode and the mask_id set of functions is used.
 * Assigns a mask_id to a mask and allocates HW resources for the mask.
 * Returns 0 if successful, otherwise an error code.
 *
 * @param[in]   cstcam      Pointer to the cstcam instance
 *
 * @param[in]   mask        See mask for cstcam_insert
 *
 * @param[in]   priority    The priority of the mask. If multiple matches occur, the winning matching
 *                          entry is determined based on the priority value. The entry with the lowest priority
 *                          wins. Two different masks cannot have the same priority.
 *                          Priority values greater than what can be represented by the defined priority
 *                          width generates an error code.
 *
 * @param[out]  mask_id     The assigned mask_id
 *
 * @return                  Returns 0 for success, otherwise the error code.
 *
 */
int cstcam_mask_alloc(struct cstcam *cstcam, const uint8_t mask[], uint32_t priority, uint16_t *mask_id);

/**
 * This function can only be used when the HW is configured for standalone mode and the mask_id set of functions is used.
 * Releases a mask_id and its HW resources. A mask_id can not be freed if there a still entries associted to the mask_id
 * Returns 0 if successful, otherwise an error code.
 *
 * @param[in] cstcam    Pointer to the cstcam instance
 *
 * @param[in] mask_id   The mask_id to be freed
 *
 * @return              Returns 0 for success, otherwise the error code.
 *
 */
int cstcam_mask_free(struct cstcam *cstcam, uint16_t mask_id);


/** @}*/
#ifdef __cplusplus
}
#endif

#endif
