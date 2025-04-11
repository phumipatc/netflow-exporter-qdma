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
 * Public API of the CAM drivers
 *
 * @file cam_top.h
 * @addtogroup cam_top VitisNetP4 CAM public API
 * @{
 * @details
 *
 * \section Introduction
 *
 * The basic operating principle of Content Addressable Memory (CAM) technology
 * is that of a lookup table, in which a lookup value (called a key) is provided
 * to the CAM, which then searches its memory for a match.  The CAM then
 * generates an output (called a response), the contents of which depend on
 * whether or not a match was found.  In a typical usage scenario, control plane
 * software is responsible for populating the contents of the CAM with entries
 * and associated data (key and response data), and the data plane of the FPGA
 * design performs lookups by constructing keys and passing them to the CAM.
 * The response data produced can then be used by the data plane to perform
 * additional processing.
 *
 * This CAM driver provides an API that allows the control plane management of
 * four types of CAM IP are supported by the Vitis Net P4.  These are as follows:
 *  - <b> Direct CAM (DCAM) </b>: Useful for implementing very small tables
 *      with exact matching semantics, the Direct CAM is essentially a lookup
 *      table - the key translates directly to a location in  the table's memory
 *  - <b> Binary CAM (BCAM) </b>: Useful for implementing exact match sematics
 *      i.e. the CAM searches its memory for an entry which exactly matches the
 *      key provided
 *  - <b> Semi-ternary CAM (STCAM) </b>: Supports most of the modes that the
 *     TCAM supports, but is constrained to support a limited number of masks
 *     at any one time.  This constraint enables faster lookup because the CAM
 *     does not need to handle as many mask permutations as the full TCAM does.
 *     Also, unlike the TCAM, range based matching is not supported.
 *  - <b> Ternary CAM (TCAM) </b>: Provides support for full ternary matching
 *      semantics.  Like the STCAM, an additional mask is stored for each entry
 *      but the number of unique masks used is not restricted.  Unlike with the
 *      DCAM and BCAM, when a lookup is performed, it is possible that the CAM
 *      will contain multiple matching entries.  For this reason, each entry
 *      also has a priority value - in the event of multiple matches, the entry
 *      with the lowest priority value becomes the response.  The consequence
 *      of the additional flexibility is increased hardware utilization.
 *
 * \section fmt Key and mask format specification
 *
 * The entries in a given CAM instance can consist of several fields. The layout
 * of the entries is described by a format string which is provided by the user
 * via the FormatStringPtr member of the  XilVitisNetP4CamConfig structure that is
 * passed in during initialization.  <b> The format string exists primarily to
 * support the TCAM driver, but is used by the other drivers to determine the
 * width of the key. </b>  The syntax of this format string is as follows:
 *  - The string is read left to right
 *  - The string consists of one or more fields
 *  - The fields are separated by the ':' character
 *  - Each field is specified as: \<field len\> \<field type\>.
 *  - There are no alignment restrictions for the fields.
 *  - The following field types and lengths are supported:
 *      - <b> b </b>: Bit field (mask can either be all bits set or all bits cleared)
 *      - <b> c </b>: Constant field (bit field with mask bits always set)
 *      - <b> u </b>: Unused field (bit field with mask bits always cleared)
 *      - <b> p </b>: Prefix field (bit field where the set bits are contiguous)
 *      - <b> t </b>: Ternary field (mask can have any mixture of set and cleared bits)
 *      - <b> r </b>: Range field (mask specifies upper limit of range, key specifies lower limit)
 *
 * For example, the format <b>"16r:16r:64p:64p:48b:48b"</b> contains 2 x 16 bit
 * range fields for port numbers, 2 x 64 bit prefix fields for IPv6 addresses
 * and 2 x 48 bit fields for MAC addresses.
 *
 * \section endian Layout of byte arrays
 *
 * The various control plane operations provided by these APIs expect pointers
 * to arrays of bytes for specifying the key, mask and response data.  Given
 * that such values are composed of several bit fields, the sizes of which may
 * not align with the number of bits in a byte, it is necessary to select scheme
 * for organizing the data for storage in the arrays of bytes. This driver
 * supports both a little-endian and a big-endian arrangement - this is selected
 * using the Endian member of the XilVitisNetP4CamConfig structure that is passed in
 * during initialization.  The semantics of these two options are described with
 * the following set of use cases.
 *
 * Consider a CAM which uses the format string "16c".  A key with the value
 * "1234h" is to be inserted into the CAM. The byte array would be populated as
 * follows:
 *
 * <i> XIL_VITIS_NET_P4_LITTLE_ENDIAN </i>
 *  - key[0] = 34h
 *  - key[1] = 12h
 *
 * <i> XIL_VITIS_NET_P4_BIG_ENDIAN </i>
 *  - key[0] = 12h
 *  - key[1] = 34h
 *
 * As the names imply, XIL_VITIS_NET_P4_LITTLE_ENDIAN requires that key[0] holds the
 * least significant byte, whereas XIL_VITIS_NET_P4_BIG_ENDIAN requires that key[0]
 * holds the least significant byte.
 *
 * Consider a CAM which uses the format string "12c".  A key with the value
 * "123h" is to be inserted into the CAM. The byte array would be populated as
 * follows:
 *
 * <i> XIL_VITIS_NET_P4_LITTLE_ENDIAN </i>
 *  - key[0] = 23h
 *  - key[1] = x1h
 *
 * <i> XIL_VITIS_NET_P4_BIG_ENDIAN </i>
 *  - key[0] = x1h
 *  - key[1] = 23h
 *
 * The above example describes the padding behaviour where the key's length is
 * not a multiple of 8.  The value <b>x</b> implies unused/don't care bits.  The
 * driver expects that the key data has been padded from 12 bits to 16 bits,
 * such that when the Endian is XIL_VITIS_NET_P4_LITTLE_ENDIAN, key[1] contains the
 * padding, whereas when Endian is XIL_VITIS_NET_P4_LITTLE_ENDIAN, key[0] contains the
 * padding.  Another way of interpreting this is that for little-endian mode,
 * the data is left-aligned in the byte array (data is packed towards byte 0
 * of the array, with padding appended) whereas in big-endian mode the data is
 * right aligned in the byte array (padding is added to byte 0 such that the
 * last byte in the array always holds a full data byte).
 *
 * Consider a CAM where the format string is "8c:16c:8".  A key with the value
 * "AAh : BBCCh : DDh" is to be inserted into the CAM.  The byte array would be
 * populated as follows:
 *
 * <i> XIL_VITIS_NET_P4_LITTLE_ENDIAN </i>
 *  - key[0] = DDh
 *  - key[1] = CCh
 *  - key[2] = BBh
 *  - key[3] = AAh
  *
 * <i> XIL_VITIS_NET_P4_BIG_ENDIAN </i>
 *  - key[0] = AAh
 *  - key[1] = BBh
 *  - key[2] = CCh
 *  - key[3] = DDh
 *
 * The above example shows how keys wth multiple fields are handled.  As can be
 * seen, when the Endian is XIL_VITIS_NET_P4_LITTLE_ENDIAN, key[0] contains the least
 * significant byte of the last field described by the format string, whereas
 * when the Endian is XIL_VITIS_NET_P4_BIG_ENDIAN, key[0] contains the most significant
 * byte of the first field.
 *
 * Consider a CAM where the format string is "9c:9c".  A key with the binary
 * value "1 10000100 : 1 00011100" (or "184h : 11Ch") is to be inserted into
 * the CAM. The byte array would be populated as follows:
 *
 * <i> XIL_VITIS_NET_P4_LITTLE_ENDIAN </i>
 *  - key[0] = 00011100 (1Ch)
 *  - key[1] = 00001001 (09h)
 *  - key[2] = xxxxxx11 (3h)
 *
 * <i> XIL_VITIS_NET_P4_BIG_ENDIAN </i>
 *  - key[0] = xxxxxx11 (3h)
 *  - key[1] = 00001001 (09h)
 *  - key[2] = 00011100 (1Ch)
 *
 * The above example demonstrates how data is to be formatted under the complex
 * scenario in which there are multiple fields, none of which are multiples of 8
 * bits and the total length of the key is not a multiple of 8 bits.  <b> As can
 * be seen from the above, there is no padding between the individual fields of
 * the key.</b>  When the Endian is XIL_VITIS_NET_P4_LITTLE_ENDIAN, the padding shows
 * up in the last byte of the key i.e. key[2] and when the When the Endian
 * is XIL_VITIS_NET_P4_BIG_ENDIAN, the padding shows up in the first byte of the
 * key i.e. key[0].
 *
 */

#ifndef CAM_TOP_H
#define CAM_TOP_H

/****************************************************************************************************************************************************/
/* SECTION: Header includes */
/****************************************************************************************************************************************************/

#include "vitisnetp4_common.h"


#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************************************************************************************/
/* SECTION: Constants */
/****************************************************************************************************************************************************/

/**
 * Configures the TCAM to automatically compute the size of the priority field
 */
#define XIL_VITIS_NET_P4_CAM_PRIORITY_SIZE_DEFAULT (0xFF)

/****************************************************************************************************************************************************/
/* SECTION: Type definitions */
/****************************************************************************************************************************************************/
typedef enum XilVitisNetP4CamType
{
    XIL_VITIS_NET_P4_CAM_BCAM,
    XIL_VITIS_NET_P4_CAM_STCAM,
    XIL_VITIS_NET_P4_CAM_TCAM,
    XIL_VITIS_NET_P4_CAM_DCAM,
    XIL_VITIS_NET_P4_CAM_TINY_BCAM,
    XIL_VITIS_NET_P4_CAM_TINY_TCAM,
    XIL_VITIS_NET_P4_CAM_NUM_CAM_TYPES
} XilVitisNetP4CamType;


/** Selects what type of optimization that was applied to the implemented CAM */
typedef enum XilVitisNetP4CamOptimizationType
{
    XIL_VITIS_NET_P4_CAM_OPTIMIZE_NONE,         /**< No optimizations */
    XIL_VITIS_NET_P4_CAM_OPTIMIZE_RAM,          /**< Used to reduce ram cost with a potentially higher logic cost.
                                              Reducing both ram and logic is not possible. Not supported for hbm  */
    XIL_VITIS_NET_P4_CAM_OPTIMIZE_LOGIC,        /**< Used to reduce logic cost with a potentially higher ram cost.
                                              Reducing both ram and logic is not possible. Not supported for hbm */
    XIL_VITIS_NET_P4_CAM_OPTIMIZE_ENTRIES,      /**< Valid for stcam and bcam only, allows insert of extra entries if 
                                              memory avialable.*/
    XIL_VITIS_NET_P4_CAM_OPTIMIZE_MASKS,        /**< Valid for stcam only, allows extra masks if distrubution is favourable 
                                              but may reduce the number of entries allowed */
    XIL_VITIS_NET_P4_NUM_CAM_OPTIMIZATION_TYPE  /**< For validation by driver - do not use */
} XilVitisNetP4CamOptimizationType;


/** Selects which type of FPGA memory resources are used to implement the CAM */
typedef enum XilVitisNetP4CamMemType
{
    XIL_VITIS_NET_P4_CAM_MEM_AUTO,     /**< Automatically selects between BRAM and URAM based on CAM size */
    XIL_VITIS_NET_P4_CAM_MEM_BRAM,     /**< CAM storage uses BRAM  */
    XIL_VITIS_NET_P4_CAM_MEM_URAM,     /**< CAM storage uses URAM  */
    XIL_VITIS_NET_P4_CAM_MEM_HBM,      /**< CAM storage uses HBM (for use with BCAM only) */
    XIL_VITIS_NET_P4_CAM_MEM_RAM,      /**< CAM storage uses external RAM (future feature, only used for internal testing) */
    XIL_VITIS_NET_P4_CAM_MEM_DDR,      /**< CAM storage uses external DDR */
    XIL_VITIS_NET_P4_NUM_CAM_MEM_TYPE  /**< For validation by driver - do not use */
} XilVitisNetP4CamMemType;

/** Populated by the user to define the CAM configuration */
typedef struct XilVitisNetP4CamConfig
{
    XilVitisNetP4AddressType         BaseAddr;           /**< Base address of the CAM */
    char                        *FormatStringPtr;   /**< Format string - refer to \ref fmt for details */
    uint32_t                    NumEntries;         /**< Number of entries the CAM holds */
    uint32_t                    RamFrequencyHz;     /**< RAM clock frequency, specified in Hertz */
    uint32_t                    LookupFrequencyHz;  /**< Lookup engine clock frequency, specified in Hertz */
    uint32_t                    LookupsPerSec;      /**< Number of lookups per second */
    uint16_t                    ResponseSizeBits;   /**< Size of CAM response data, specified in bits */
    uint8_t                     PrioritySizeBits;   /**< Size of priority field, specified in bits (applies to TCAM only, also see \ref XIL_VITIS_NET_P4_CAM_PRIORITY_SIZE_DEFAULT) */
    uint8_t                     NumMasks;           /**< STCAM only: specifies the number of unique masks that are available */
    XilVitisNetP4Endian              Endian;             /**< Format of key, mask and response data byte arrays */
    XilVitisNetP4CamMemType          MemType;            /**< FPGA memory resource selection */
    uint32_t                    RamSizeKbytes;      /**< RAM size in KiloBytes, (for internal testing of asic ram the unit eqauls datawidth)*/
    XilVitisNetP4CamOptimizationType OptimizationType;   /**< Optimization type applied to the CAM */
    uint32_t                    RamChannelWidth;      /**< RAM Channel Width*/
    uint32_t                    RamNumBanks;          /**<  Number of Banks*/
} XilVitisNetP4CamConfig;

/** Forward declaration to support context structure declaration */
typedef struct XilVitisNetP4CamCtx XilVitisNetP4CamCtx;

/** Holds context information needed by the DCAM driver's API */
typedef struct XilVitisNetP4DcamCtx
{
    XilVitisNetP4CamCtx *PrivateCtxPtr;  /**< Internal context data used by driver implementation */
} XilVitisNetP4DcamCtx;

/** Holds context information needed by the BCAM driver's API */
typedef struct XilVitisNetP4BcamCtx
{
    XilVitisNetP4CamCtx *PrivateCtxPtr;  /**< Internal context data used by driver implementation */
} XilVitisNetP4BcamCtx;

/** Holds context information needed by the TCAM driver's API */
typedef struct XilVitisNetP4TcamCtx
{
    XilVitisNetP4CamCtx *PrivateCtxPtr;  /**< Internal context data used by driver implementation */
} XilVitisNetP4TcamCtx;

/** Holds context information needed by the STCAM driver's API */
typedef struct XilVitisNetP4StcamCtx
{
    XilVitisNetP4CamCtx *PrivateCtxPtr;  /**< Internal context data used by driver implementation */
} XilVitisNetP4StcamCtx;


/****************************************************************************************************************************************************/
/* SECTION: Global function prototypes */
/****************************************************************************************************************************************************/

/**
 * @addtogroup vitisp4net_dcam VitisNetP4DCAM public API
 * @{
 * Please refer to the following sections to understand key and response data layout:
 *  - \ref fmt
 *  - \ref endian
 */

/**
 * Initialization function for the DCAM driver API
 *
 * @param[in,out] CtxPtr        Pointer to an uninitialized DCAM context structure instance.
 *                              Is populated by function execution.
 *
 * @param[in] EnvIfPtr          Pointer to environment interface definition
 *
 * @param[in] ConfigPtr         Pointer to driver configuration definition
 *
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4DcamInit(XilVitisNetP4DcamCtx *CtxPtr, const  XilVitisNetP4EnvIf *EnvIfPtr, XilVitisNetP4CamConfig *ConfigPtr);

/**
 * Resets a DCAM instance.
 *
 * All existing entries in the table (if any) are deleted
 *
 * @param[in]  CtxPtr           Pointer to the DCAM instance context
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4DcamReset(XilVitisNetP4DcamCtx *CtxPtr);

/**
 * Inserts an entry into the DCAM instance.
 *
 * If an existing matching entry is found, the function fails by returning error
 * code XIL_VITIS_NET_P4_CAM_ERR_DUPLICATE_FOUND. If an existing matching entry is not
 * found, then it is inserted in the DCAM instance.
 *
 * @param[in] CtxPtr        Pointer to the DCAM instance context
 *
 * @param[in] Key           Specifies location in the table of the entry to access
 *
 * @param[in] ResponsePtr   Pointer to byte array holding the response of the entry
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4DcamInsert(XilVitisNetP4DcamCtx *CtxPtr, uint32_t Key, uint8_t *ResponsePtr);

/**
 * Updates an entry in the DCAM instance.
 *
 * If the entry is found, the response is updated. If the entry is not found,
 * the function fails with error code XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND.
 *
 * @param[in] CtxPtr        Pointer to the DCAM instance context
 *
 * @param[in] Key           Specifies location in the table of the entry to access
 *
 * @param[in] ResponsePtr   Pointer to byte array holding the response of the entry
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4DcamUpdate(XilVitisNetP4DcamCtx *CtxPtr, uint32_t Key, uint8_t *ResponsePtr);

/**
 * Gets an entry from the DCAM instance with the matching response value.
 *
 * If the entry is not found, the function fails with error code XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND.
 *
 * The PositionPtr argument enables multiple matching entries to be found. The first time the function is
 * called the integer at PositionPtr should be set to zero. To find all entries matching the response, the function is
 * called multiple times, each call returns one matching entry.
 *
 * For every consecutive call the returned PositionPtr value must be used again as input argument.
 * When XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND is returned no more entries matching the response could be found.
 *
 * The ResponseMaskPtr is used to limit the search to subfields of the response. If the complete,
 * exact response value is searched, then all bits in the byte array at ResponseMaskPtr should be set to one.
 * By setting the bits to all zeros, any response value will match.
 * This can be used for getting all entries without prior knowledge of the response values.
 *
 * The function uses a linear search to read the entries from hardware.
 *
 * @param[in] CtxPtr            Pointer to the DCAM instance context
 *
 * @param[in] ResponsePtr       Pointer to byte array holding the response to search for
 *
 * @param[in] ResponseMaskPtr   The buffers pointed to by ResponsePtr and ResponseMaskPtr are ANDed and then
 *                              searched for. The stored response is also ANDed
 *                              with the ResponseMaskPtr before the comparison takes place.
 *
 * @param[in,out] PositionPtr   Position in the database. Used for
 *                              consecutive get operations, set to 0 for
 *                              first get.
 *
 * @param[out] KeyPtr           Pointer to integer which is updated with the location in the table of the
 *                              entry when matches are found
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4DcamGetByResponse(XilVitisNetP4DcamCtx *CtxPtr,
                                                       uint8_t *ResponsePtr,
                                                       uint8_t *ResponseMaskPtr,
                                                       uint32_t *PositionPtr,
                                                       uint32_t *KeyPtr);

/**
 * Looks up an entry in the DCAM instance.
 *
 * This function provides the same response as if a lookup had been performed in hardware.
 * If an entry is not found, the function returns XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND.
 *
 * @param[in] CtxPtr        Pointer to the DCAM instance context
 *
 * @param[in] Key           Specifies location in the table of the entry to access
 *
 * @param[out] ResponsePtr  Pointer to byte array with storage for the response that is read
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4DcamLookup(XilVitisNetP4DcamCtx *CtxPtr, uint32_t Key, uint8_t *ResponsePtr);

/**
 * Get the last Key-Response lookup entry that has been performed on the hardware.
 *
 * If an entry is not found i.e no hit, the function returns XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND.
 *
 * @param[in] CtxPtr        Pointer to the DCAM instance context
 *
 * @param[in] Key           Specifies location in the table of the entry to access
 *
 * @param[out] ResponsePtr  Pointer to byte array with storage for the response that is read
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4DcamGetLastLookup(XilVitisNetP4DcamCtx* CtxPtr, uint32_t* Key, uint8_t* ResponsePtr, bool* HitMissStatusPtr);

/**
 * Switch on\off the debug mode of the DCAM. Will cause the table entry read/write registers to be updated automatically with every data plane lookup operation
 *
 *
 * @param[in] CtxPtr        Pointer to the DCAM instance context
 *
 * @param[in] DebugMode     Debug Mode, boolean. True = Debug on, False = Debug off
 *
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4DcamSetLastLookupDebugMode(XilVitisNetP4DcamCtx* CtxPtr, bool DebugMode);

/**
 * Set the Debug Flags, this flag is set during cam initializtion.
 *
 * @param[in] flags Flags to enable
 *
 * @return void
 */

void XilVitisNetP4CamSetDebugFlags(uint32_t flags);

/**
 * Get the Debug Flags, can be called at any stage to view debug levels.
 *
 * @param[in] none
 *
 * @return Debug Flags
 */

uint32_t XilVitisNetP4CamGetDebugFlags(void);


/**
 * Delete an entry with the specified key from the DCAM instance.
 *
 * If an entry is not found, the function fails with error code XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND.
 *
 * @param[in] CtxPtr    Pointer to the DCAM instance context
 *
 * @param[in] Key       Specifies location in the table of the entry to access
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4DcamDelete(XilVitisNetP4DcamCtx *CtxPtr, uint32_t Key);

/**
 * Reads and clears the ECC counters of the DCAM instance.
 *
 * @param[in] CtxPtr                        Pointer to the DCAM instance context
 *
 * @param[out] CorrectedSingleBitErrorsPtr  The number of single bit errors the hardware scrubbing
 *                                          process has detected and corrected. Errors might
 *                                          have been detected by a hardware lookup and then corrected
 *                                          dynamically for the lookups, but still not counted.
 *                                          The scrubbing process runs in the background and corrects
 *                                          errors permanently. The counter is only incremented after
 *                                          the error is corrected permanently.
 *
 * @param[out] DetectedDoubleBitErrorsPtr   The number of detected double-bit errors. Double-bit
 *                                          errors are fatal errors and the data base is corrupt. The hardware
 *                                          cannot correct the error without help from software. The instance
 *                                          has generated an interrupt and this counter can be used to find
 *                                          the instance which caused the interrupt if multiple instances are
 *                                          in use. Lookups detecting double-bit errors will not discard the lookup,
 *                                          the lookup result might be corrupt. Once the double-bit error is
 *                                          detected the interrupt pin is asserted and it is advised to use this
 *                                          signal to discard packets until the data base is corrected.
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4DcamGetEccCountersClearOnRead(XilVitisNetP4DcamCtx *CtxPtr,
                                                                  uint32_t *CorrectedSingleBitErrorsPtr,
                                                                  uint32_t *DetectedDoubleBitErrorsPtr);

/**
 * Reads and clears the ECC adress registers of the DCAM instance.
 *
 * @param[in] CtxPtr                            Pointer to the DCAM instance context
 *
 * @param[out] FailingAddressSingleBitErrorPtr  The address of the first single bit error detected and corrected
 *                                              by the hardware scrubbing process. Additional errors might
 *                                              have been detected during a hardware lookup and then corrected
 *                                              dynamically, but this register only reflects the
 *                                              errors detected by hardware scrubbing.
 *
 * @param[out] FailingAddressDoubleBitErrorPtr The address of the first double-bit error detected by the
 *                                              hardware scrubbing process.
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */
XilVitisNetP4ReturnType XilVitisNetP4DcamGetEccAddressesClearOnRead(XilVitisNetP4DcamCtx *CtxPtr,
                                                                    uint32_t *FailingAddressSingleBitErrorPtr,
                                                                    uint32_t *FailingAddressDoubleBitErrorPtr);

/**
 * Destroy the DCAM instance
 *
 * All memory allocated by \ref XilVitisNetP4DcamInit is released.
 *
 * @param[in] CtxPtr    Pointer to the DCAM instance context
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4DcamExit(XilVitisNetP4DcamCtx *CtxPtr);

/** @} */

/**
 * @addtogroup vitisp4net_bcam VitisNetP4BCAM public API
 * @{
 * Please refer to the following sections to understand key and response data layout:
 *  - \ref fmt
 *  - \ref endian
 */

/**
 * Initialization function for the BCAM driver API
 *
 * @param[in,out] CtxPtr        Pointer to an uninitialized BCAM context structure instance.
 *                              Is populated by function execution.
 *
 * @param[in] EnvIfPtr          Pointer to environment interface definition
 *
 * @param[in] ConfigPtr         Pointer to driver configuration definition
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4BcamInit(XilVitisNetP4BcamCtx *CtxPtr, const XilVitisNetP4EnvIf *EnvIfPtr, XilVitisNetP4CamConfig *ConfigPtr);

/**
 * Resets a BCAM instance.
 *
 * All existing entries in the table (if any) are deleted.
 *
 * @param[in]  CtxPtr           Pointer to the BCAM instance context
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4BcamReset(XilVitisNetP4BcamCtx *CtxPtr);

/**
 * Inserts an entry into the BCAM instance.
 *
 * If an existing matching entry is found, the function fails by returning error
 * code XIL_VITIS_NET_P4_CAM_ERR_DUPLICATE_FOUND. If an existing matching entry is not
 * found, then it is inserted in the BCAM instance.
 *
 * @param[in] CtxPtr        Pointer to the BCAM instance context
 *
 * @param[in] KeyPtr        Pointer to byte array holding the key for the entry
 *
 * @param[in] ResponsePtr   Pointer to byte array holding the response of the entry
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4BcamInsert(XilVitisNetP4BcamCtx *CtxPtr, uint8_t *KeyPtr, uint8_t *ResponsePtr);

/**
 * Updates an entry in the BCAM instance.
 *
 * If the entry is found, the response is updated. If the entry is not found,
 * the function fails with error code XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND.
 *
 * @param[in] CtxPtr        Pointer to the BCAM instance context
 *
 * @param[in] KeyPtr        Pointer to byte array holding the key for the entry
 *
 * @param[in] ResponsePtr   Pointer to byte array holding the response of the entry
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4BcamUpdate(XilVitisNetP4BcamCtx *CtxPtr, uint8_t *KeyPtr, uint8_t *ResponsePtr);

/**
 * Gets an entry from the BCAM instance with the matching response value.
 *
 * If the entry is not found, the function fails with error code XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND.
 *
 * The PositionPtr argument enables multiple matching entries to be found. The first time the function is
 * called the integer at PositionPtr should be set to zero. To find all entries matching the response, the function is
 * called multiple times, each call returns one matching entry.
 *
 * For every consecutive call the returned PositionPtr value must be used again as input argument.
 * When XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND is returned no more entries matching the response could be found.
 *
 * The ResponseMaskPtr is used to limit the search to subfields of the response. If the complete,
 * exact response value is searched, then all bits in the byte array at ResponseMaskPtr should be set to one.
 * By setting the bits to all zeros, any response value will match.
 * This can be used for getting all entries without prior knowledge of the response values.
 *
 * The function does not read from the hardware, it reads from the shadow copy in system memory.
 * The function uses a linear search.
 *
 * @param[in] CtxPtr            Pointer to the BCAM instance context
 *
 * @param[in] ResponsePtr       Pointer to byte array holding the response to search for
 *
 * @param[in] ResponseMaskPtr   The buffers pointed to by ResponsePtr and ResponseMaskPtr are ANDed and then
 *                              searched for. The stored response is also ANDed
 *                              with the ResponseMaskPtr before compare takes place.
 *
 * @param[in,out] PositionPtr   Position in the database. Used for
 *                              consecutive get operations, set to 0 for
 *                              first get.
 *
 * @param[out] KeyPtr           Pointer to byte array with storage for the key that is read
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4BcamGetByResponse(XilVitisNetP4BcamCtx *CtxPtr,
                                                       uint8_t *ResponsePtr,
                                                       uint8_t *ResponseMaskPtr,
                                                       uint32_t *PositionPtr,
                                                       uint8_t *KeyPtr);

/**
 * Gets an entry from the BCAM instance with the specified key

 * If an entry is not found, the function fails with error code XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND.
 * The function does not read from the hardware, it reads from the shadow copy in system memory.
 * The function uses a hash table and is fast.
 *
 * @param[in] CtxPtr        Pointer to the BCAM instance context
 *
 * @param[in] KeyPtr        Pointer to byte array holding the key to search for
 *
 * @param[out] ResponsePtr  Pointer to byte array with storage for the response that is read
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4BcamGetByKey(XilVitisNetP4BcamCtx *CtxPtr, uint8_t *KeyPtr, uint8_t *ResponsePtr);

/**
 * Delete an entry with the specified key from the BCAM instance.
 *
 * If an entry is not found, the function fails with error code XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND.
 *
 * @param[in] CtxPtr    Pointer to the BCAM instance context
 *
 * @param[in] KeyPtr    Pointer to byte array holding the key to be deleted
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4BcamDelete(XilVitisNetP4BcamCtx *CtxPtr, uint8_t *KeyPtr);

/**
 * Reads and clears the ECC counters of the BCAM instance.
 *
 * @param[in] CtxPtr                        Pointer to the BCAM instance context
 *
 * @param[out] CorrectedSingleBitErrorsPtr  The number of single bit errors the hardware scrubbing
 *                                          process has detected and corrected. Errors might
 *                                          have been detected by a hardware lookup and then corrected
 *                                          dynamically for the lookups, but still not counted.
 *                                          The scrubbing process runs in the background and corrects
 *                                          errors permanently. The counter is only incremented after
 *                                          the error is corrected permanently.
 *
 * @param[out] DetectedDoubleBitErrorsPtr   The number of detected double-bit errors. Double-bit
 *                                          errors are fatal errors and the data base is corrupt. The hardware
 *                                          cannot correct the error without help from software. The instance
 *                                          has generated an interrupt and this counter can be used to find
 *                                          the instance which caused the interrupt if multiple instances are
 *                                          in use. Lookups detecting double-bit errors will not discard the lookup,
 *                                          the lookup result might be corrupt. Once the double-bit error is
 *                                          detected the interrupt pin is asserted and it is advised to use this
 *                                          signal to discard packets until the data base is corrected.
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4BcamGetEccCountersClearOnRead(XilVitisNetP4BcamCtx *CtxPtr,
                                                         uint32_t *CorrectedSingleBitErrorsPtr,
                                                         uint32_t *DetectedDoubleBitErrorsPtr);

/**
 * Reads and clears the ECC adress registers of the BCAM instance.
 *
 * @param[in] CtxPtr                            Pointer to the BCAM instance context
 *
 * @param[out] FailingAddressSingleBitErrorPtr  The address of the first single bit error detected and corrected
 *                                              by the hardware scrubbing process. Additional errors might
 *                                              have been detected during a hardware lookup and then corrected
 *                                              dynamically, but this register only reflects the
 *                                              errors detected by hardware scrubbing.
 *
 * @param[out] FailingAddressDoubleBitErrorPtr The address of the first double-bit error detected by the
 *                                              hardware scrubbing process.
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */
XilVitisNetP4ReturnType XilVitisNetP4BcamGetEccAddressesClearOnRead(XilVitisNetP4BcamCtx *CtxPtr,
                                                          uint32_t *FailingAddressSingleBitErrorPtr,
                                                          uint32_t *FailingAddressDoubleBitErrorPtr);

/**
 * Destroy the BCAM instance
 *
 * All memory allocated by \ref XilVitisNetP4BcamInit is released.
 *
 * @param[in] CtxPtr    Pointer to the BCAM instance context
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4BcamExit(XilVitisNetP4BcamCtx *CtxPtr);

/** @} */

/**
 * @addtogroup vitisp4net_tcam VitisNetP4TCAM public API
 * @{
 * Please refer to the following sections to understand key, mask and response data layout:
 *  - \ref fmt
 *  - \ref endian
 */

/**
 * Initialization function for the TCAM driver API
 *
 * @param[in,out] CtxPtr        Pointer to an uninitialized TCAM context structure instance.
 *                              Is populated by function execution.
 *
 * @param[in] EnvIfPtr          Pointer to environment interface definition
 *
 * @param[in] ConfigPtr         Pointer to driver configuration definition
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4TcamInit(XilVitisNetP4TcamCtx *CtxPtr, const XilVitisNetP4EnvIf *EnvIfPtr, XilVitisNetP4CamConfig *ConfigPtr);


/**
 * Resets a TCAM instance.
 *
 * All existing entries in the table (if any) are deleted
 *
 * @param[in]  CtxPtr           Pointer to the TCAM instance context
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4TcamReset(XilVitisNetP4TcamCtx *CtxPtr);

/**
 * Inserts an entry into the TCAM instance.
 *
 * If an existing matching entry is found, the function fails by returning error
 * code XIL_VITIS_NET_P4_CAM_ERR_DUPLICATE_FOUND. If an existing matching entry is not
 * found, then it is inserted in the TCAM instance.
 *
 * @param[in] CtxPtr        Pointer to the TCAM instance context
 *
 * @param[in] KeyPtr        Pointer to byte array holding the key for the entry
 *
 * @param[in] MaskPtr       Pointer to byte array holding the mask for the entry
 *
 * @param[in] Priority      The priority of the entry. If multiple matches occur, the winning matching
 *                          entry is determined based on the priority value. The entry with the lowest priority
 *                          wins. If there are multiple matches with the same lowest priority, any of them becomes
 *                          the winner.
 *
 * @param[in] ResponsePtr   Pointer to byte array holding the response of the entry
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4TcamInsert(XilVitisNetP4TcamCtx *CtxPtr, uint8_t *KeyPtr, uint8_t *MaskPtr, uint32_t Priority, uint8_t *ResponsePtr);

/**
 * Updates an entry in the TCAM instance.
 *
 * If the entry is found, the response is updated. If the entry is not found,
 * the function fails with error code XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND.
 *
 * @param[in] CtxPtr        Pointer to the TCAM instance context
 *
 * @param[in] KeyPtr        Pointer to byte array holding the key for the entry
 *
 * @param[in] MaskPtr       Pointer to byte array holding the mask for the entry
 *
 * @param[in] ResponsePtr   Pointer to byte array holding the response of the entry
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4TcamUpdate(XilVitisNetP4TcamCtx *CtxPtr, uint8_t *KeyPtr, uint8_t *MaskPtr, uint8_t *ResponsePtr);

/**
 * Gets an entry from the TCAM instance with the matching response value.
 *
 * If the entry is not found, the function fails with error code XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND.
 *
 * The PositionPtr argument enables multiple matching entries to be found. The first time the function is
 * called the integer at PositionPtr should be set to zero. To find all entries matching the response, the function is
 * called multiple times, each call returns one matching entry.
 *
 * For every consecutive call the returned PositionPtr value must be used again as input argument.
 * When XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND is returned no more entries matching the response could be found.
 *
 * The ResponseMaskPtr is used to limit the search to subfields of the response. If the complete,
 * exact response value is searched, then all bits in the byte array at ResponseMaskPtr should be set to one.
 * By setting the bits to all zeros, any response value will match.
 * This can be used for getting all entries without prior knowledge of the response values.
 *
 * The function does not read from the hardware, it reads from the shadow copy in system memory.
 * The function uses a linear search.
 *
 * @param[in] CtxPtr            Pointer to the TCAM instance context
 *
 * @param[in] ResponsePtr       Pointer to byte array holding the response to search for
 *
 * @param[in] ResponseMaskPtr   The buffers pointed to by ResponsePtr and ResponseMaskPtr are ANDed and then
 *                              searched for. The stored response is also ANDed
 *                              with the ResponseMaskPtr before compare takes place.
 *
 * @param[in,out] PositionPtr   Position in the database. Used for
 *                              consecutive get operations, set to 0 for
 *                              first get.
 *
 * @param[out] KeyPtr           Pointer to byte array with storage for the key that is read
 *
 * @param[out] MaskPtr          Pointer to byte array with storage for the mask that is read
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4TcamGetByResponse(XilVitisNetP4TcamCtx *CtxPtr,
                                             uint8_t *ResponsePtr,
                                             uint8_t *ResponseMaskPtr,
                                             uint32_t *PositionPtr,
                                             uint8_t *KeyPtr,
                                             uint8_t *MaskPtr);

/**
 * Gets an entry from the TCAM instance with the specified key

 * If an entry is not found, the function fails with error code XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND.
 * The function does not read from the hardware, it reads from the shadow copy in system memory.
 * The function uses a hash table and is fast.
 *
 * @param[in] CtxPtr        Pointer to the TCAM instance context
 *
 * @param[in] KeyPtr        Pointer to byte array holding the key to search for
 *
 * @param[in] MaskPtr       Pointer to byte array holding the mask to search for
 *
 * @param[out] PriorityPtr  Pointer to integer with storage for the priority of the entry that is read
 *
 * @param[out] ResponsePtr  Pointer to byte array with storage for the response that is read
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4TcamGetByKey(XilVitisNetP4TcamCtx *CtxPtr, uint8_t *KeyPtr, uint8_t *MaskPtr, uint32_t *PriorityPtr, uint8_t *ResponsePtr);

/**
 * Looks up an entry in the TCAM instance.
 *
 * This function provides the same response as if a lookup had been performed in hardware.
 * If an entry is not found, the function returns XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND.
 *
 * @param[in] CtxPtr        Pointer to the TCAM instance context
 *
 * @param[in] KeyPtr        Pointer to byte array holding the key to lookup
 *
 * @param[out] ResponsePtr  Pointer to byte array with storage for the response that is read
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4TcamLookup(XilVitisNetP4TcamCtx *CtxPtr, uint8_t *KeyPtr, uint8_t *ResponsePtr);

/**
 * Delete an entry with the specified key from the TCAM instance.
 *
 * If an entry is not found, the function fails with error code XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND.
 *
 * @param[in] CtxPtr    Pointer to the TCAM instance context
 *
 * @param[in] KeyPtr    Pointer to byte array holding the key to be deleted
 *
 * @param[in] MaskPtr   Pointer to byte array holding the mask to be deleted
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4TcamDelete(XilVitisNetP4TcamCtx *CtxPtr, uint8_t *KeyPtr, uint8_t *MaskPtr);

/**
 * Reads and clears the ECC counters of the TCAM instance.
 *
 * @param[in] CtxPtr                        Pointer to the TCAM instance context
 *
 * @param[out] CorrectedSingleBitErrorsPtr  The number of single bit errors the hardware scrubbing
 *                                          process has detected and corrected. Errors might
 *                                          have been detected by a hardware lookup and then corrected
 *                                          dynamically for the lookups, but still not counted.
 *                                          The scrubbing process runs in the background and corrects
 *                                          errors permanently. The counter is only incremented after
 *                                          the error is corrected permanently.
 *
 * @param[out] DetectedDoubleBitErrorsPtr   The number of detected double-bit errors. Double-bit
 *                                          errors are fatal errors and the data base is corrupt. The hardware
 *                                          cannot correct the error without help from software. The instance
 *                                          has generated an interrupt and this counter can be used to find
 *                                          the instance which caused the interrupt if multiple instances are
 *                                          in use. Lookups detecting double-bit errors will not discard the lookup,
 *                                          the lookup result might be corrupt. Once the double-bit error is
 *                                          detected the interrupt pin is asserted and it is advised to use this
 *                                          signal to discard packets until the data base is corrected.
 */

XilVitisNetP4ReturnType XilVitisNetP4TcamGetEccCountersClearOnRead(XilVitisNetP4TcamCtx *CtxPtr,
                                                         uint32_t *CorrectedSingleBitErrorsPtr,
                                                         uint32_t *DetectedDoubleBitErrorsPtr);

/**
 * Reads and clears the ECC adress registers of the TCAM instance.
 *
 * @param[in] CtxPtr                            Pointer to the TCAM instance context
 *
 * @param[out] FailingAddressSingleBitErrorPtr  The address of the first single bit error detected and corrected
 *                                              by the hardware scrubbing process. Additional errors might
 *                                              have been detected during a hardware lookup and then corrected
 *                                              dynamically, but this register only reflects the
 *                                              errors detected by hardware scrubbing.
 *
 * @param[out] FailingAddressDoubleBitErrorPtr The address of the first double-bit error detected by the
 *                                              hardware scrubbing process.
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */
XilVitisNetP4ReturnType XilVitisNetP4TcamGetEccAddressesClearOnRead(XilVitisNetP4TcamCtx *CtxPtr,
                                                          uint32_t *FailingAddressSingleBitErrorPtr,
                                                          uint32_t *FailingAddressDoubleBitErrorPtr);

/**
 * Destroy the TCAM instance
 *
 * All memory allocated by \ref XilVitisNetP4TcamInit is released.
 *
 * @param[in] CtxPtr    Pointer to the TCAM instance context
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4TcamExit(XilVitisNetP4TcamCtx *CtxPtr);

/** @} */

/**
 * @addtogroup vitisp4net_stcam VitisNetP4STCAM public API
 * @{
 * Please refer to the following sections to understand key, mask and response data layout:
 *  - \ref fmt
 *  - \ref endian
 */

/**
 * Initialization function for the STCAM driver API
 *
 * @param[in,out] CtxPtr        Pointer to an uninitialized STCAM context structure instance.
 *                              Is populated by function execution.
 *
 * @param[in] EnvIfPtr          Pointer to environment interface definition
 *
 * @param[in] ConfigPtr         Pointer to driver configuration definition
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4StcamInit(XilVitisNetP4StcamCtx *CtxPtr, const XilVitisNetP4EnvIf *EnvIfPtr, XilVitisNetP4CamConfig *ConfigPtr);


/**
 * Resets a STCAM instance.
 *
 * All existing entries in the table (if any) are deleted
 *
 * @param[in]  CtxPtr           Pointer to the STCAM instance context
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4StcamReset(XilVitisNetP4StcamCtx *CtxPtr);

/**
 * Inserts an entry into the STCAM instance.
 *
 * If an existing matching entry is found, the function fails by returning error
 * code XIL_VITIS_NET_P4_CAM_ERR_DUPLICATE_FOUND. If an existing matching entry is not
 * found, then it is inserted in the STCAM instance.
 *
 * @param[in] CtxPtr        Pointer to the STCAM instance context
 *
 * @param[in] KeyPtr        Pointer to byte array holding the key for the entry
 *
 * @param[in] MaskPtr       Pointer to byte array holding the mask for the entry
 *
 * @param[in] Priority      The priority of the entry. If multiple matches occur, the winning matching
 *                          entry is determined based on the priority value. The entry with the lowest priority
 *                          wins. If there are multiple matches with the same lowest priority, any of them becomes
 *                          the winner.
 *
 * @param[in] ResponsePtr   Pointer to byte array holding the response of the entry
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4StcamInsert(XilVitisNetP4StcamCtx *CtxPtr, uint8_t *KeyPtr, uint8_t *MaskPtr, uint32_t Priority, uint8_t *ResponsePtr);

/**
 * Updates an entry in the STCAM instance.
 *
 * If the entry is found, the response is updated. If the entry is not found,
 * the function fails with error code XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND.
 *
 * @param[in] CtxPtr        Pointer to the STCAM instance context
 *
 * @param[in] KeyPtr        Pointer to byte array holding the key for the entry
 *
 * @param[in] MaskPtr       Pointer to byte array holding the mask for the entry
 *
 * @param[in] ResponsePtr   Pointer to byte array holding the response of the entry
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4StcamUpdate(XilVitisNetP4StcamCtx *CtxPtr, uint8_t *KeyPtr, uint8_t *MaskPtr, uint8_t *ResponsePtr);

/**
 * Gets an entry from the STCAM instance with the matching response value.
 *
 * If the entry is not found, the function fails with error code XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND.
 *
 * The PositionPtr argument enables multiple matching entries to be found. The first time the function is
 * called the integer at PositionPtr should be set to zero. To find all entries matching the response, the function is
 * called multiple times, each call returns one matching entry.
 *
 * For every consecutive call the returned PositionPtr value must be used again as input argument.
 * When XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND is returned no more entries matching the response could be found.
 *
 * The ResponseMaskPtr is used to limit the search to subfields of the response. If the complete,
 * exact response value is searched, then all bits in the byte array at ResponseMaskPtr should be set to one.
 * By setting the bits to all zeros, any response value will match.
 * This can be used for getting all entries without prior knowledge of the response values.
 *
 * The function does not read from the hardware, it reads from the shadow copy in system memory.
 * The function uses a linear search.
 *
 * @param[in] CtxPtr            Pointer to the STCAM instance context
 *
 * @param[in] ResponsePtr       Pointer to byte array holding the response to search for
 *
 * @param[in] ResponseMaskPtr   The buffers pointed to by ResponsePtr and ResponseMaskPtr are ANDed and then
 *                              searched for. The stored response is also ANDed
 *                              with the ResponseMaskPtr before compare takes place.
 *
 * @param[in,out] PositionPtr   Position in the database. Used for
 *                              consecutive get operations, set to 0 for
 *                              first get.
 *
 * @param[out] KeyPtr           Pointer to byte array with storage for the key that is read
 *
 * @param[out] MaskPtr          Pointer to byte array with storage for the mask that is read
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4StcamGetByResponse(XilVitisNetP4StcamCtx *CtxPtr,
                                              uint8_t *ResponsePtr,
                                              uint8_t *ResponseMaskPtr,
                                              uint32_t *PositionPtr,
                                              uint8_t *KeyPtr,
                                              uint8_t *MaskPtr);

/**
 * Gets an entry from the STCAM instance with the specified key

 * If an entry is not found, the function fails with error code XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND.
 * The function does not read from the hardware, it reads from the shadow copy in system memory.
 * The function uses a hash table and is fast.
 *
 * @param[in] CtxPtr        Pointer to the STCAM instance context
 *
 * @param[in] KeyPtr        Pointer to byte array holding the key to search for
 *
 * @param[in] MaskPtr       Pointer to byte array holding the mask to search for
 *
 ** @param[out] PriorityPtr Pointer to integer with storage for the priority of the entry that is read
 *
 * @param[out] ResponsePtr  Pointer to byte array with storage for the response that is read
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4StcamGetByKey(XilVitisNetP4StcamCtx *CtxPtr, uint8_t *KeyPtr, uint8_t *MaskPtr, uint32_t *PriorityPtr, uint8_t *ResponsePtr);

/**
 * Looks up an entry in the STCAM instance.
 *
 * This function provides the same response as if a lookup had been performed in hardware.
 * If an entry is not found, the function returns XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND.
 *
 * @param[in] CtxPtr        Pointer to the STCAM instance context
 *
 * @param[in] KeyPtr        Pointer to byte array holding the key to lookup
 *
 * @param[out] ResponsePtr  Pointer to byte array with storage for the response that is read
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4StcamLookup(XilVitisNetP4StcamCtx *CtxPtr, uint8_t *KeyPtr, uint8_t *ResponsePtr);

/**
 * Delete an entry with the specified key from the STCAM instance.
 *
 * If an entry is not found, the function fails with error code XIL_VITIS_NET_P4_CAM_ERR_KEY_NOT_FOUND.
 *
 * @param[in] CtxPtr    Pointer to the STCAM instance context
 *
 * @param[in] KeyPtr    Pointer to byte array holding the key to be deleted
 *
 * @param[in] MaskPtr   Pointer to byte array holding the mask to be deleted
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4StcamDelete(XilVitisNetP4StcamCtx *CtxPtr, uint8_t *KeyPtr, uint8_t *MaskPtr);

/**
 * Reads and clears the ECC counters of the STCAM instance.
 *
 * @param[in] CtxPtr                        Pointer to the STCAM instance context
 *
 * @param[out] CorrectedSingleBitErrorsPtr  The number of single bit errors the hardware scrubbing
 *                                          process has detected and corrected. Errors might
 *                                          have been detected by a hardware lookup and then corrected
 *                                          dynamically for the lookups, but still not counted.
 *                                          The scrubbing process runs in the background and corrects
 *                                          errors permanently. The counter is only incremented after
 *                                          the error is corrected permanently.
 *
 * @param[out] DetectedDoubleBitErrorsPtr   The number of detected double-bit errors. Double-bit
 *                                          errors are fatal errors and the data base is corrupt. The hardware
 *                                          cannot correct the error without help from software. The instance
 *                                          has generated an interrupt and this counter can be used to find
 *                                          the instance which caused the interrupt if multiple instances are
 *                                          in use. Lookups detecting double-bit errors will not discard the lookup,
 *                                          the lookup result might be corrupt. Once the double-bit error is
 *                                          detected the interrupt pin is asserted and it is advised to use this
 *                                          signal to discard packets until the data base is corrected.
 */

XilVitisNetP4ReturnType XilVitisNetP4StcamGetEccCountersClearOnRead(XilVitisNetP4StcamCtx *CtxPtr,
                                                          uint32_t *CorrectedSingleBitErrorsPtr,
                                                          uint32_t *DetectedDoubleBitErrorsPtr);

/**
 * Reads and clears the ECC adress registers of the STCAM instance.
 *
 * @param[in] CtxPtr                            Pointer to the STCAM instance context
 *
 * @param[out] FailingAddressSingleBitErrorPtr  The address of the first single bit error detected and corrected
 *                                              by the hardware scrubbing process. Additional errors might
 *                                              have been detected during a hardware lookup and then corrected
 *                                              dynamically, but this register only reflects the
 *                                              errors detected by hardware scrubbing.
 *
 * @param[out] FailingAddressDoubleBitErrorPtr The address of the first double-bit error detected by the
 *                                              hardware scrubbing process.
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */
XilVitisNetP4ReturnType XilVitisNetP4StcamGetEccAddressesClearOnRead(XilVitisNetP4StcamCtx *CtxPtr,
                                                          uint32_t *FailingAddressSingleBitErrorPtr,
                                                          uint32_t *FailingAddressDoubleBitErrorPtr);

/**
 * Destroy the STCAM instance
 *
 * All memory allocated by \ref XilVitisNetP4StcamInit is released.
 *
 * @param[in] CtxPtr    Pointer to the STCAM instance context
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */

XilVitisNetP4ReturnType XilVitisNetP4StcamExit(XilVitisNetP4StcamCtx *CtxPtr);

/** @} */

/**
 * @addtogroup vitisp4net_cam_util VitisNetP4 CAM utilities
 * @{
 * A collection of helper functions for use with the VITISNETP4 CAM API.
 */

/**
 * Please refer to the following sections to understand key, mask and response data layout:
 *  - \ref fmt
 *
 * Function that uses the Key and mask format information from FormatStringPtr to calculate the Key width in bits.
 *
 * @param[in] FormatStringPtr   Pointer to the STCAM instance context
 *
 * @param[out] KeyLengthPtr     Pointer to byte array with storage for the response that is read
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */
XilVitisNetP4ReturnType XilVitisNetP4CamGetKeyLengthInBits(char *FormatStringPtr, uint32_t *KeyLengthPtr);

/**
 * Calculate the Heap size, in bytes, that will be required to create the specified CAM
 *
 * @param[in,out] CtxPtr        Pointer to an uninitialized CAM context structure instance (STCAM\TCAM\BCAM)
 *                              Is populated by function execution.
 *
 * @param[in] EnvIfPtr          Pointer to environment interface definition
 *
 * @param[in] ConfigPtr         Pointer to driver configuration definition
 *
 * @param[in] CamType           Specifies which type of cam is being handled by the CtxPtr
 *
 * @param[out] HeapSizePtr       Pointer to the calculated heap size in bytes
 *
 *
 * @return XIL_VITIS_NET_P4_SUCCESS if successful, otherwise an error code.
 */
XilVitisNetP4ReturnType XilVitisNetP4CamGetMaxHeapSize(void* CtxPtr, XilVitisNetP4EnvIf* EnvIfPtr, XilVitisNetP4CamConfig* ConfigPtr, XilVitisNetP4CamType CamType, uint64_t* HeapSizePtr);

/** @} */
#ifdef __cplusplus
}
#endif

#endif
/** @} */
