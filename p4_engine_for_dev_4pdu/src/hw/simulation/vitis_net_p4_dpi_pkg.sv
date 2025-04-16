// (c) Copyright 2015, 2023 Advanced Micro Devices, Inc. All rights reserved.
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
//
//       Description: This package file contains the DPI-related definitions and
//                    task/function imports for vitis_net_p4 simulation.
//
//////////////////////////////////////////////////////////////////////////////

`ifndef VITIS_NET_P4_DPI_PKG
`define VITIS_NET_P4_DPI_PKG

package vitis_net_p4_dpi_pkg;

`ifndef SYNTHESIS

    // Common internal data structures
    typedef chandle XilVitisNetP4CamCtx;
    typedef chandle XilVitisNetP4TargetBuildInfoCtx;
    typedef chandle XilVitisNetP4TargetInterruptCtx;
    typedef chandle XilVitisNetP4TargetControlCtx;
    typedef longint XilVitisNetP4AddressType;
    typedef byte byteArray [127:0];

    // Select which type of endian is used
    typedef enum {
        XIL_VITIS_NET_P4_LITTLE_ENDIAN,    // < use the little endian format 
        XIL_VITIS_NET_P4_BIG_ENDIAN,       // < use the big endian format 
        XIL_VITIS_NET_P4_NUM_ENDIAN        // < For validation by driver - do not use 
    } XilVitisNetP4Endian;

    // Selects which type of mode is used to implement the table
    typedef enum {
        XIL_VITIS_NET_P4_TABLE_MODE_BCAM,      // < Table configured as exact match or BCAM 
        XIL_VITIS_NET_P4_TABLE_MODE_STCAM,     // < Table configured as lpm or STCAM 
        XIL_VITIS_NET_P4_TABLE_MODE_TCAM,      // < Table configured as ternary or TCAM 
        XIL_VITIS_NET_P4_TABLE_MODE_DCAM,      // < Table configured as direct or DCAM 
        XIL_VITIS_NET_P4_TABLE_MODE_TINY_BCAM, // < Table configured as tiny CAM 
        XIL_VITIS_NET_P4_TABLE_MODE_TINY_TCAM, // < Table configured as tiny CAM 
        XIL_VITIS_NET_P4_NUM_TABLE_MODES       // < For validation by driver - do not use 
    } XilVitisNetP4TableMode;

    // Selects which type of FPGA memory resources are used to implement the CAM
    typedef enum {
        XIL_VITIS_NET_P4_CAM_MEM_AUTO,     // < Automatically selects between BRAM and URAM based on CAM size 
        XIL_VITIS_NET_P4_CAM_MEM_BRAM,     // < CAM storage uses block RAM  
        XIL_VITIS_NET_P4_CAM_MEM_URAM,     // < CAM storage uses ultra RAM  
        XIL_VITIS_NET_P4_CAM_MEM_HBM,      // < CAM storage uses High Bandwidth Memory  
        XIL_VITIS_NET_P4_CAM_MEM_RAM,      // < CAM storage uses external RAM (future feature, only used for internal testing) 
        XIL_VITIS_NET_P4_CAM_MEM_DDR,      // < CAM storage uses external DDR Memory
        XIL_VITIS_NET_P4_NUM_CAM_MEM_TYPES // < For validation by driver - do not use 
    } XilVitisNetP4CamMemType;

    // Selects what type of optimization that was applied to the implemented CAM
    typedef enum {
        XIL_VITIS_NET_P4_CAM_OPTIMIZE_NONE,         // < No optimizations 
        XIL_VITIS_NET_P4_CAM_OPTIMIZE_RAM,          // < Used to reduce ram cost with a potentially higher logic cost. 
        XIL_VITIS_NET_P4_CAM_OPTIMIZE_LOGIC,        // < Used to reduce logic cost with a potentially higher ram cost. 
        XIL_VITIS_NET_P4_NUM_CAM_OPTIMIZATION_TYPE  // < For validation by driver - do not use 
    } XilVitisNetP4CamOptimizationType;

    // ECC error types 
    typedef enum {
        XIL_VITIS_NET_P4_INTERRUPT_ECC_ERROR_SINGLE_BIT,  // < Single bit ECC error - internally recoverable 
        XIL_VITIS_NET_P4_INTERRUPT_ECC_ERROR_DOUBLE_BIT,  // < Double bit ECC error - internally not recoverable 
        XIL_VITIS_NET_P4_INTERRUPT_ECC_ERROR_ALL,         // < Both single and double bit ECC errors 
        XIL_VITIS_NET_P4_INTERRUPT_ECC_ERROR_TYPE_MAX     // < For validation by driver - do not use 
    } XilVitisNetP4InterruptEccErrorType;
    
    // Individual engine reset control
    typedef enum {
        XIL_VITIS_NET_P4_TARGET_CTRL_ALL_ENGINES,        // < Target all internal engines 
        XIL_VITIS_NET_P4_TARGET_CTRL_DEPARSER_ENGINE,    // < Target Deparser engine only 
        XIL_VITIS_NET_P4_TARGET_CTRL_FIFO_ENGINE,        // < Target sync FIFOs engine only 
        XIL_VITIS_NET_P4_TARGET_CTRL_MA_ENGINE,          // < Target Match-Action engine only 
        XIL_VITIS_NET_P4_TARGET_CTRL_PARSER_ENGINE       // < Target Parser engine only 
    } XilVitisNetP4ControlEngineId;

    // Counter extern types
    typedef enum {
        XIL_VITIS_NET_P4_COUNTER_PACKETS,           // < Packet Mode
        XIL_VITIS_NET_P4_COUNTER_BYTES,             // < Byte Mode
        XIL_VITIS_NET_P4_COUNTER_PACKETS_AND_BYTES, // < Packets and Bytes mode
        XIL_VITIS_NET_P4_COUNTER_FLAG,              // < Flag Mode
        XIL_VITIS_NET_P4_NUM_COUNTER_TYPES          // < Number of counter types
    } XilVitisNetP4CounterType;

    // Structure to define the XilVitisNetP4Version
    typedef struct {
        byte Major;    // < VitisNetP4 major version number
        byte Minor;    // < VitisNetP4 minor version number
        byte Revision; // < VitisNetP4 revision number
    } XilVitisNetP4Version;

    // Structure to define the XilVitisNetP4Version
    typedef struct {
        int PacketRateMps;      // < Packet rate in Mp/s
        int CamMemoryClockMhz;  // < CAM memory clock in MHz
        int AxiStreamClockMhz;  // < AXI Stream clock in MHz
    } XilVitisNetP4TargetBuildInfoIpSettings;

    typedef struct {
        int unsigned SingleBitErrorStatus; // < 1 indicates present, 0 indicates not present 
        int unsigned DoubleBitErrorStatus; // < 1 indicates present, 0 indicates not present 
    } XilVitisNetP4TargetInterruptEccErrorStatus;

    // Structure to define the CAM configuration
    typedef struct {
        XilVitisNetP4AddressType         BaseAddr;           // < Base address of the CAM 
        string                           FormatStringPtr;    // < Format string - refer to \ref fmt for details 
        // Note: The following are not strictly needed for PLUGIN_MODE
        int                              NumEntries;         // < Number of entries the CAM holds 
        int                              RamFrequencyHz;     // < RAM clock frequency, specified in Hertz 
        int                              LookupFrequencyHz;  // < Lookup engine clock frequency, specified in Hertz 
        int                              LookupsPerSec;      // < Number of lookups per second 
        shortint                         ResponseSizeBits;   // < Size of CAM response data, specified in bits 
        byte                             PrioritySizeBits;   // < Size of priority field, specified in bits (applies to TCAM only) 
        byte                             NumMasks;           // < STCAM only: specifies the number of unique masks that are available 
        XilVitisNetP4Endian              Endian;             // < Format of key, mask and response data 
        XilVitisNetP4CamMemType          MemType;            // < FPGA memory resource selection 
        int                              RamSizeKbytes;      // < RAM size in KiloBytes, (for internal testing of ASIC ram the unit equals data-width)
        XilVitisNetP4CamOptimizationType OptimizationType;   // < Optimization type applied to the CAM 
        int                              RamChannelWidth;    // < DDR channel width in bits
        int                              RamNumBanks;        // < number of banks in DDR memory
    } XilVitisNetP4CamConfig;

    // Structure to define a name-value pairs
    typedef struct {
       string  NameStringPtr;    // < Name of the attribute 
       int     Value;            // < value of the attribute 
    } XilVitisNetP4Attribute;

    // Structure to define the action configuration
    typedef struct {
        string                  NameStringPtr;    // < Name of the action 
        int                     ParamListSize;    // < Total number of parameters 
        XilVitisNetP4Attribute  ParamListPtr[];   // < List of parameters 
    } XilVitisNetP4Action;

    // Structure to define the table configuration
    typedef struct {
        XilVitisNetP4Endian     Endian;            // < Format of key, mask and action parameter byte arrays 
        XilVitisNetP4TableMode  Mode;              // < Table mode selection 
        int                     KeySizeBits;       // < Size of table key data, specified in bits 
        XilVitisNetP4CamConfig  CamConfig;         // < CAM configuration 
        int                     ActionIdWidthBits; // < Size of action ID field in response data, specified in bits 
        int                     ActionListSize;    // < Total number of associated actions 
        XilVitisNetP4Action     ActionListPtr[];   // < List of associated actions 
    } XilVitisNetP4TableConfig;
    
    // Wrapper structure to group table name with table configuration
    typedef struct {
        string                     NameStringPtr;   // < Table control plane name 
        XilVitisNetP4TableConfig   Config;          // < Table configuration 
    } XilVitisNetP4TargetTableConfig;

    // Counter Extern Config structure
    typedef struct {
        XilVitisNetP4AddressType  BaseAddr;       // < Base Address of the Counter Extern instance
        XilVitisNetP4CounterType  CounterType;    // < Type of Counter 
        int                       NumCounters;    // < Number of counter entries in the Counter Extern instance
        int                       Width;          // < Width of counter entries in the counter extern instance
    } XilVitisNetP4CounterConfig;

    // Wrapper structure to group counter extern name with table configuration
    typedef struct {
        string                       NameStringPtr;   // < Table control plane name 
        XilVitisNetP4CounterConfig   Config;          // < Table configuration 
    } XilVitisNetP4TargetCounterConfig;

    // Structure to define the FIFOs names
    typedef struct {
        string NameStringPtr;
    } XilVitisNetP4ComponentName;

    // Configuration that describes the block information of the VitisNetP4 instance
    typedef struct {
        XilVitisNetP4AddressType BaseAddr;   // < Base address within the VitisNetP4 instance 
    } XilVitisNetP4TargetBuildInfoConfig;

    // Configuration that describes the interrupt controller of the VitisNetP4 instance
    typedef struct {
        XilVitisNetP4AddressType    BaseAddr;                // < Base address within the VitisNetP4 instance 
        int                         NumP4Elements;           // < Number of P4 Elements present in the VitisNetP4 instance 
        int                         NumComponents;           // < Number of internal FIFOs present in the VitisNetP4 instance 
        XilVitisNetP4ComponentName  ComponentNameList[2];    // < List of FIFOs name that are present in the VitisNetP4 instance 
    } XilVitisNetP4TargetInterruptConfig;
    
    // Configuration that describes the operations controller of the VitisNetP4 instance
    typedef struct {
        XilVitisNetP4AddressType  BaseAddr;           // < Base address within the VitisNetP4 instance 
        int                       NumP4Elements;      // < Number of P4 Elements present in the VitisNetP4 instance 
        int                       NumComponents;      // < Number of internal FIFOs present in the VitisNetP4 instance 
        int                       ClkInHz;            // < Clock in Hz 
        int                       PktRatePerSec;      // < Packet rate in packets per second 
    } XilVitisNetP4TargetCtrlConfig;

    // Structure to define VitisNetP4's configuration
    typedef struct {
        XilVitisNetP4Endian                  Endian;           // < Global endianness setting - applies to all P4 element drivers instantiated by the target 
        int                                  TableListSize;    // < Total number of tables in the design 
        XilVitisNetP4TargetTableConfig       TableListPtr[];   // < List of tables in the design 
        int                                  CounterListSize;  // < Total number of counter externs in the design 
        XilVitisNetP4TargetCounterConfig     CounterListPtr[]; // < List of counter externs in the design 
        // Note: The following are not strictly needed unless EN_STATS_REGS is enabled
        XilVitisNetP4TargetBuildInfoConfig   BuildInfoPtr;     // < Pointer to the configuration for the build information reader 
        XilVitisNetP4TargetInterruptConfig   InterruptPtr;     // < Pointer to the configuration for the interrupt manager 
        XilVitisNetP4TargetCtrlConfig        CtrlConfigPtr;    // < Pointer to the configuration for the control manager 
    } XilVitisNetP4TargetConfig;

    // Utilities
    import "DPI-C" context function chandle XilVitisNetP4DpiCreateEnv(string hier_path);
    import "DPI-C" context function int XilVitisNetP4DpiDestroyEnv(chandle env_handle);
    import "DPI-C" context function chandle XilVitisNetP4DpiByteArrayCreate(int unsigned bit_len);
    import "DPI-C" context function void XilVitisNetP4DpiStringToByteArray(string str, chandle key_mask, int unsigned bit_len);
    import "DPI-C" context function void XilVitisNetP4DpiByteArrayDestroy(chandle key_mask);
    import "DPI-C" context function void XilVitisNetP4CamSetDebugFlags(int unsigned flags);
    import "DPI-C" context function void FillCamConfigsFromJson(input string file_path);
    import "DPI-C" context function void FindCamConfigByName(input string table_name, chandle cfg, inout longint cfg_size);

    // BuildInfo Driver API
    import "DPI-C" context task XilVitisNetP4TargetBuildInfoInit(inout XilVitisNetP4TargetBuildInfoCtx ctx, input chandle env, input XilVitisNetP4TargetBuildInfoConfig cfg);
    import "DPI-C" context task XilVitisNetP4TargetBuildInfoGetIpVersion(inout XilVitisNetP4TargetBuildInfoCtx ctx, XilVitisNetP4Version ip_version);
    import "DPI-C" context task XilVitisNetP4TargetBuildInfoGetIpSettings(inout XilVitisNetP4TargetBuildInfoCtx ctx, XilVitisNetP4TargetBuildInfoIpSettings ip_settings);
    import "DPI-C" context task XilVitisNetP4TargetBuildInfoExit(inout XilVitisNetP4TargetBuildInfoCtx ctx);

    // Interrupt Driver API
    import "DPI-C" context function int XilVitisNetP4TargetInterruptGetP4ElementCount(inout XilVitisNetP4TargetInterruptCtx ctx, int unsigned num_elements);
    import "DPI-C" context function int XilVitisNetP4TargetInterruptGetComponentCount(inout XilVitisNetP4TargetInterruptCtx ctx, int unsigned num_components);
    import "DPI-C" context function int XilVitisNetP4TargetInterruptGetComponentIndexByName(inout XilVitisNetP4TargetInterruptCtx ctx, input string component_name, int unsigned idx);
    import "DPI-C" context task XilVitisNetP4TargetInterruptInit(inout XilVitisNetP4TargetInterruptCtx ctx, input chandle env, input XilVitisNetP4TargetInterruptConfig cfg);
    import "DPI-C" context task XilVitisNetP4TargetInterruptEnableP4ElementEccErrorById(inout XilVitisNetP4TargetInterruptCtx ctx, input int unsigned element_id, XilVitisNetP4InterruptEccErrorType ecc_type);
    import "DPI-C" context task XilVitisNetP4TargetInterruptDisableP4ElementEccErrorById(inout XilVitisNetP4TargetInterruptCtx ctx, input int unsigned element_id, XilVitisNetP4InterruptEccErrorType ecc_type);
    import "DPI-C" context task XilVitisNetP4TargetInterruptGetP4ElementEccErrorStatusById(inout XilVitisNetP4TargetInterruptCtx ctx, input int unsigned element_id, XilVitisNetP4TargetInterruptEccErrorStatus status);
    import "DPI-C" context task XilVitisNetP4TargetInterruptClearP4ElementEccErrorStatusById(inout XilVitisNetP4TargetInterruptCtx ctx, input int unsigned element_id, XilVitisNetP4InterruptEccErrorType ecc_type);
    import "DPI-C" context task XilVitisNetP4TargetInterruptEnableComponentEccErrorByIndex(inout XilVitisNetP4TargetInterruptCtx ctx, input int unsigned fifo_idx, XilVitisNetP4InterruptEccErrorType ecc_type);
    import "DPI-C" context task XilVitisNetP4TargetInterruptDisableComponentEccErrorByIndex(inout XilVitisNetP4TargetInterruptCtx ctx, input int unsigned fifo_idx, XilVitisNetP4InterruptEccErrorType ecc_type);
    import "DPI-C" context task XilVitisNetP4TargetInterruptGetComponentEccErrorStatusByIndex(inout XilVitisNetP4TargetInterruptCtx ctx, input int unsigned fifo_idx, XilVitisNetP4TargetInterruptEccErrorStatus status);
    import "DPI-C" context task XilVitisNetP4TargetInterruptClearComponentEccErrorStatusByIndex(inout XilVitisNetP4TargetInterruptCtx ctx, input int unsigned fifo_idx, XilVitisNetP4InterruptEccErrorType ecc_type);
    import "DPI-C" context task XilVitisNetP4TargetInterruptExit(inout XilVitisNetP4TargetInterruptCtx ctx);
    
    // Control Driver API
    import "DPI-C" context task XilVitisNetP4TargetCtrlInit(inout XilVitisNetP4TargetControlCtx ctx, input chandle env, input XilVitisNetP4TargetCtrlConfig cfg);
    import "DPI-C" context task XilVitisNetP4TargetCtrlExit(inout XilVitisNetP4TargetControlCtx ctx);
    import "DPI-C" context task XilVitisNetP4TargetCtrlGetP4ElementCount(inout XilVitisNetP4TargetControlCtx ctx, int unsigned num_p4_elements);
    import "DPI-C" context task XilVitisNetP4TargetCtrlGetClkInHz(inout XilVitisNetP4TargetControlCtx ctx, int unsigned clk_in_hz);
    import "DPI-C" context task XilVitisNetP4TargetCtrlGetNumComponents(inout XilVitisNetP4TargetControlCtx ctx, int unsigned num_components);
    import "DPI-C" context task XilVitisNetP4TargetCtrlGetPktRatePerSec(inout XilVitisNetP4TargetControlCtx ctx, int unsigned pkt_rate_per_sec);
    import "DPI-C" context task XilVitisNetP4TargetCtrlSoftResetEngine(inout XilVitisNetP4TargetControlCtx ctx, XilVitisNetP4ControlEngineId EngineId);
    import "DPI-C" context task XilVitisNetP4TargetCtrlSetPacketRateLimitMargin(inout XilVitisNetP4TargetControlCtx ctx, input int unsigned packet_rate_margin);
    import "DPI-C" context task XilVitisNetP4TargetCtrlGetPacketRateLimitMargin(inout XilVitisNetP4TargetControlCtx ctx, int unsigned packet_rate_margin);
    import "DPI-C" context task XilVitisNetP4TargetCtrlIpComponentEnableInjectEccError(inout XilVitisNetP4TargetControlCtx ctx, input int unsigned component_index, XilVitisNetP4InterruptEccErrorType ecc_type);
    import "DPI-C" context task XilVitisNetP4TargetCtrlIpComponentDisableInjectEccError(inout XilVitisNetP4TargetControlCtx ctx, input int unsigned component_index, XilVitisNetP4InterruptEccErrorType ecc_type);
    import "DPI-C" context task XilVitisNetP4TargetCtrlP4ElementEnableInjectEccError(inout XilVitisNetP4TargetControlCtx ctx, input int unsigned p4_element_id, XilVitisNetP4InterruptEccErrorType ecc_type);
    import "DPI-C" context task XilVitisNetP4TargetCtrlP4ElementDisableInjectEccError(inout XilVitisNetP4TargetControlCtx ctx, input int unsigned p4_element_id, XilVitisNetP4InterruptEccErrorType ecc_type);    

    // BCAM API
    import "DPI-C" context task XilVitisNetP4BcamInit(inout XilVitisNetP4CamCtx ctx, input chandle env, XilVitisNetP4CamConfig cfg);
    import "DPI-C" context task XilVitisNetP4BcamInsert(inout XilVitisNetP4CamCtx ctx, input byteArray key, byteArray resp);
    import "DPI-C" context task XilVitisNetP4BcamUpdate(inout XilVitisNetP4CamCtx ctx, input byteArray key, byteArray resp);
    import "DPI-C" context task XilVitisNetP4BcamGetByResponse(inout XilVitisNetP4CamCtx ctx, input byteArray resp, byteArray resp_mask, inout int unsigned pos, byteArray key);
    import "DPI-C" context task XilVitisNetP4BcamGetByKey(inout XilVitisNetP4CamCtx ctx, input byteArray key, inout byteArray resp);
    import "DPI-C" context task XilVitisNetP4BcamDelete(inout XilVitisNetP4CamCtx ctx, input byteArray key);
    import "DPI-C" context task XilVitisNetP4BcamGetEccCountersClearOnRead(inout XilVitisNetP4CamCtx ctx, inout int unsigned corrected_single, inout int unsigned uncorrected_double);
    import "DPI-C" context task XilVitisNetP4BcamGetEccAddressesClearOnRead(inout XilVitisNetP4CamCtx ctx, inout int unsigned failing_address_single, inout int unsigned failing_address_double);
    import "DPI-C" context task XilVitisNetP4BcamReset(inout XilVitisNetP4CamCtx ctx);
    import "DPI-C" context task XilVitisNetP4BcamExit(inout XilVitisNetP4CamCtx ctx);

    // Tiny BCAM API
    import "DPI-C" context task XilVitisNetP4TinyBcamInit(inout XilVitisNetP4CamCtx ctx, input chandle env, XilVitisNetP4CamConfig cfg);
    import "DPI-C" context task XilVitisNetP4TinyBcamInsert(inout XilVitisNetP4CamCtx ctx, input byteArray key, byteArray resp);
    import "DPI-C" context task XilVitisNetP4TinyBcamUpdate(inout XilVitisNetP4CamCtx ctx, input byteArray key, byteArray resp);
    import "DPI-C" context task XilVitisNetP4TinyBcamGetByResponse(inout XilVitisNetP4CamCtx ctx, input byteArray resp, byteArray resp_mask, inout int unsigned pos, byteArray key);
    import "DPI-C" context task XilVitisNetP4TinyBcamGetByKey(inout XilVitisNetP4CamCtx ctx, input byteArray key, inout byteArray resp);
    import "DPI-C" context task XilVitisNetP4TinyBcamDelete(inout XilVitisNetP4CamCtx ctx, input byteArray key);
    import "DPI-C" context task XilVitisNetP4TinyBcamGetEccCountersClearOnRead(inout XilVitisNetP4CamCtx ctx, inout int unsigned corrected_single, inout int unsigned uncorrected_double);
    import "DPI-C" context task XilVitisNetP4TinyBcamGetEccAddressesClearOnRead(inout XilVitisNetP4CamCtx ctx, inout int unsigned failing_address_single, inout int unsigned failing_address_double);
    import "DPI-C" context task XilVitisNetP4TinyBcamReset(inout XilVitisNetP4CamCtx ctx);
    import "DPI-C" context task XilVitisNetP4TinyBcamExit(inout XilVitisNetP4CamCtx ctx);

    // TCAM Driver API
    import "DPI-C" context task XilVitisNetP4TcamInit(inout XilVitisNetP4CamCtx ctx, input chandle env, XilVitisNetP4CamConfig cfg);
    import "DPI-C" context task XilVitisNetP4TcamInsert(inout XilVitisNetP4CamCtx ctx, input byteArray key, byteArray mask, int unsigned prio, byteArray resp);
    import "DPI-C" context task XilVitisNetP4TcamUpdate(inout XilVitisNetP4CamCtx ctx, input byteArray key, byteArray mask, byteArray resp);
    import "DPI-C" context task XilVitisNetP4TcamGetByResponse(inout XilVitisNetP4CamCtx ctx, input byteArray resp, byteArray resp_mask, inout int unsigned pos, byteArray key, byteArray key_mask);
    import "DPI-C" context task XilVitisNetP4TcamGetByKey(inout XilVitisNetP4CamCtx ctx, input byteArray key, byteArray mask, inout int unsigned prio, byteArray resp);
    import "DPI-C" context task XilVitisNetP4TcamLookup(inout XilVitisNetP4CamCtx ctx, input byteArray key, inout byteArray resp);
    import "DPI-C" context task XilVitisNetP4TcamDelete(inout XilVitisNetP4CamCtx ctx, input byteArray key, byteArray mask);
    import "DPI-C" context task XilVitisNetP4TcamGetEccCountersClearOnRead(inout XilVitisNetP4CamCtx ctx, inout int unsigned corrected_single, inout int unsigned uncorrected_double);
    import "DPI-C" context task XilVitisNetP4TcamGetEccAddressesClearOnRead(inout XilVitisNetP4CamCtx ctx, inout int unsigned failing_address_single, inout int unsigned failing_address_double);
    import "DPI-C" context task XilVitisNetP4TcamReset(inout XilVitisNetP4CamCtx ctx);
    import "DPI-C" context task XilVitisNetP4TcamExit(inout XilVitisNetP4CamCtx ctx);

    // Tiny TCAM API
    import "DPI-C" context task XilVitisNetP4TinyTcamInit(inout XilVitisNetP4CamCtx ctx, input chandle env, XilVitisNetP4CamConfig cfg);
    import "DPI-C" context task XilVitisNetP4TinyTcamInsert(inout XilVitisNetP4CamCtx ctx, input byteArray key, byteArray mask, int unsigned prio, byteArray resp);
    import "DPI-C" context task XilVitisNetP4TinyTcamUpdate(inout XilVitisNetP4CamCtx ctx, input byteArray key, byteArray mask, byteArray resp);
    import "DPI-C" context task XilVitisNetP4TinyTcamGetByResponse(inout XilVitisNetP4CamCtx ctx, input byteArray resp, byteArray resp_mask, inout int unsigned pos, byteArray key, byteArray key_mask);
    import "DPI-C" context task XilVitisNetP4TinyTcamGetByKey(inout XilVitisNetP4CamCtx ctx, input byteArray key, byteArray mask, inout int unsigned prio, byteArray resp);
    import "DPI-C" context task XilVitisNetP4TinyTcamDelete(inout XilVitisNetP4CamCtx ctx, input byteArray key, byteArray mask);
    import "DPI-C" context task XilVitisNetP4TinyTcamGetEccCountersClearOnRead(inout XilVitisNetP4CamCtx ctx, inout int unsigned corrected_single, inout int unsigned uncorrected_double);
    import "DPI-C" context task XilVitisNetP4TinyTcamGetEccAddressesClearOnRead(inout XilVitisNetP4CamCtx ctx, inout int unsigned failing_address_single, inout int unsigned failing_address_double);
    import "DPI-C" context task XilVitisNetP4TinyTcamReset(inout XilVitisNetP4CamCtx ctx);
    import "DPI-C" context task XilVitisNetP4TinyTcamExit(inout XilVitisNetP4CamCtx ctx);

    // STCAM Driver API
    import "DPI-C" context task XilVitisNetP4StcamInit(inout XilVitisNetP4CamCtx ctx, input chandle env, XilVitisNetP4CamConfig cfg);
    import "DPI-C" context task XilVitisNetP4StcamInsert(inout XilVitisNetP4CamCtx ctx, input byteArray key, byteArray mask, int unsigned prio, byteArray resp);
    import "DPI-C" context task XilVitisNetP4StcamUpdate(inout XilVitisNetP4CamCtx ctx, input byteArray key, byteArray mask, byteArray resp);
    import "DPI-C" context task XilVitisNetP4StcamGetByResponse(inout XilVitisNetP4CamCtx ctx, input byteArray resp, byteArray resp_mask, inout int unsigned pos, byteArray key, byteArray key_mask);
    import "DPI-C" context task XilVitisNetP4StcamGetByKey(inout XilVitisNetP4CamCtx ctx, input byteArray key, byteArray mask, inout int unsigned prio, byteArray resp);
    import "DPI-C" context task XilVitisNetP4StcamLookup(inout XilVitisNetP4CamCtx ctx, input byteArray key, inout byteArray resp);
    import "DPI-C" context task XilVitisNetP4StcamDelete(inout XilVitisNetP4CamCtx ctx, input byteArray key, byteArray mask);
    import "DPI-C" context task XilVitisNetP4StcamGetEccCountersClearOnRead(inout XilVitisNetP4CamCtx ctx, inout int unsigned corrected_single, inout int unsigned uncorrected_double);
    import "DPI-C" context task XilVitisNetP4StcamGetEccAddressesClearOnRead(inout XilVitisNetP4CamCtx ctx, inout int unsigned failing_address_single, inout int unsigned failing_address_double);
    import "DPI-C" context task XilVitisNetP4StcamReset(inout XilVitisNetP4CamCtx ctx);
    import "DPI-C" context task XilVitisNetP4StcamExit(inout XilVitisNetP4CamCtx ctx);

    // DCAM Driver API
    import "DPI-C" context task XilVitisNetP4DcamInit(inout XilVitisNetP4CamCtx ctx, input chandle env, XilVitisNetP4CamConfig cfg);
    import "DPI-C" context task XilVitisNetP4DcamInsert(inout XilVitisNetP4CamCtx ctx, input int unsigned key, byteArray resp);
    import "DPI-C" context task XilVitisNetP4DcamUpdate(inout XilVitisNetP4CamCtx ctx, input int unsigned key, byteArray resp);
    import "DPI-C" context task XilVitisNetP4DcamGetByResponse(inout XilVitisNetP4CamCtx ctx, input byteArray resp, byteArray resp_mask, inout int unsigned pos, inout int unsigned key);
    import "DPI-C" context task XilVitisNetP4DcamLookup(inout XilVitisNetP4CamCtx ctx, input int unsigned key, inout byteArray resp);
    import "DPI-C" context task XilVitisNetP4DcamDelete(inout XilVitisNetP4CamCtx ctx, input int unsigned key);
    import "DPI-C" context task XilVitisNetP4DcamGetEccCountersClearOnRead(inout XilVitisNetP4CamCtx ctx, inout int unsigned corrected_single, inout int unsigned uncorrected_double);
    import "DPI-C" context task XilVitisNetP4DcamGetEccAddressesClearOnRead(inout XilVitisNetP4CamCtx ctx, inout int unsigned failing_address_single, inout int unsigned failing_address_double);
    import "DPI-C" context task XilVitisNetP4DcamReset(inout XilVitisNetP4CamCtx ctx);
    import "DPI-C" context task XilVitisNetP4DcamExit(inout XilVitisNetP4CamCtx ctx);

    // PLUGIN mode API
    import "DPI-C" context task XilVitisNetP4PluginCamInit(inout XilVitisNetP4CamCtx ctx, input chandle env, input longint base_addr, chandle cfg, longint cfg_size);
    import "DPI-C" context task XilVitisNetP4PluginCamInsert(inout XilVitisNetP4CamCtx ctx, input byteArray key, byteArray mask, int unsigned prio, byteArray resp);
    import "DPI-C" context task XilVitisNetP4PluginCamUpdate(inout XilVitisNetP4CamCtx ctx, input byteArray key, byteArray mask, byteArray resp);
    import "DPI-C" context task XilVitisNetP4PluginCamGetByKey(inout XilVitisNetP4CamCtx ctx, input byteArray key, byteArray mask, int unsigned prio, byteArray resp);
    import "DPI-C" context task XilVitisNetP4PluginCamLookup(inout XilVitisNetP4CamCtx ctx, input byteArray key, inout byteArray resp);
    import "DPI-C" context task XilVitisNetP4PluginCamDelete(inout XilVitisNetP4CamCtx ctx, input byteArray key, byteArray mask);
    import "DPI-C" context task XilVitisNetP4PluginCamReset(inout XilVitisNetP4CamCtx ctx);
    import "DPI-C" context task XilVitisNetP4PluginCamExit(inout XilVitisNetP4CamCtx ctx);

`endif

endpackage

`endif

