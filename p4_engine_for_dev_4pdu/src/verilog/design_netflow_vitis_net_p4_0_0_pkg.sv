//////////////////////////////////////////////////////////////////////////////
// be767e8644eee50b2645307571242b99d62eea726bb276dae1cba7a07fa60690
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

`ifndef DESIGN_NETFLOW_VITIS_NET_P4_0_0_PKG
`define DESIGN_NETFLOW_VITIS_NET_P4_0_0_PKG

package design_netflow_vitis_net_p4_0_0_pkg;

////////////////////////////////////////////////////////////////////////////////
// Parameters
////////////////////////////////////////////////////////////////////////////////

    // IP configuration info
    localparam JSON_FILE             = "/home/dej/Desktop/Capstone/Netflow_Packet_Analyzer/Netflow_Packet_Analyzer/Netflow_Packet_Analyzer.gen/sources_1/bd/design_netflow/ip/design_netflow_vitis_net_p4_0_0/main.json"; // Note: this localparam is not used internally in the IP, it is just for reference
    localparam P4_FILE               = "/home/dej/Desktop/Capstone/Netflow_Packet_Analyzer/P4_engine_file/nif_nonfb.p4"; // Note: this localparam is not used internally in the IP, it is just for reference
    localparam P4C_ARGS              = " ";

    localparam PACKET_RATE           = 325;
    localparam AXIS_CLK_FREQ_MHZ     = 325.0;
    localparam CAM_MEM_CLK_FREQ_MHZ  = 325.0;
    localparam OUT_META_FOR_DROP     = 0;
    localparam TOTAL_LATENCY         = 116;
    localparam PLUGIN_MODE           = 0;

    localparam TDATA_NUM_BYTES       = 4;
    localparam AXIS_DATA_WIDTH       = 32;
    localparam TUSER_WIDTH           = 0;
    localparam TID_WIDTH             = 11;
    localparam TDEST_WIDTH           = 0;

    localparam USER_META_DATA_WIDTH  = 12;
    localparam NUM_USER_EXTERNS      = 0;
    localparam USER_EXTERN_IN_WIDTH  = 0;
    localparam USER_EXTERN_OUT_WIDTH = 0;
    
    localparam S_AXI_DATA_WIDTH      = 32;
    localparam S_AXI_ADDR_WIDTH      = 13;

    localparam M_AXI_HBM_NUM_SLOTS   = 0;
    localparam M_AXI_HBM_DATA_WIDTH  = 256;
    localparam M_AXI_HBM_ADDR_WIDTH  = 64;

    localparam M_AXI_DDR_NUM_SLOTS   = 0;
    localparam M_AXI_DDR_DATA_WIDTH  = 512;
    localparam M_AXI_DDR_ADDR_WIDTH  = 64;

    // Metadata interface info
    localparam METADATA_ENABLER_WIDTH = 1;
    localparam METADATA_ENABLER_MSB   = 0;
    localparam METADATA_ENABLER_LSB   = 0;
    localparam METADATA_AXIS_TID_WIDTH = 11;
    localparam METADATA_AXIS_TID_MSB   = 11;
    localparam METADATA_AXIS_TID_LSB   = 1;

    // User Extern interface info

    // sub-cores memory map addresses 

    localparam XIL_VITIS_NET_P4_NIF_TERNARY_BASEADDR = 'h00000000;
    localparam XIL_VITIS_NET_P4_NIF_TERNARY_HIGHADDR = 'h00001FFF;


////////////////////////////////////////////////////////////////////////////////
// Declarations
////////////////////////////////////////////////////////////////////////////////

    // Metadata sub-struct metadata
    typedef struct packed {
        logic [10:0] axis_tid;
        logic enabler;
    } USER_META_DATA_METADATA_T;

    // Metadata top-struct
    typedef struct packed {
        logic [10:0] axis_tid;
        logic enabler;
    } USER_META_DATA_T;

`ifndef SYNTHESIS

    import vitis_net_p4_dpi_pkg::*;

////////////////////////////////////////////////////////////////////////////////
// Constants
////////////////////////////////////////////////////////////////////////////////

    // CAM priority width default value
    int XIL_VITIS_NET_P4_CAM_PRIORITY_SIZE_DEFAULT = 'hFF;

    // User metadata definition
    XilVitisNetP4Attribute XilVitisNetP4UserMetadataFields[] =
    '{
        '{
            NameStringPtr : "metadata.axis_tid",
            Value         : 11
        },
        '{
            NameStringPtr : "metadata.enabler",
            Value         : 1
        }
    };

    // Action 'NoAction' Parameters list
    XilVitisNetP4Attribute XilVitisNetP4ActionParams_NoAction[] =
    {
    };

    // Action 'dropPacket' Parameters list
    XilVitisNetP4Attribute XilVitisNetP4ActionParams_dropPacket[] =
    {
    };

    // Action 'NoAction' definition
    XilVitisNetP4Action XilVitisNetP4Action_NoAction =
    '{
        NameStringPtr : "NoAction",
        ParamListSize : 0,
        ParamListPtr  : XilVitisNetP4ActionParams_NoAction
    };

    // Action 'dropPacket' definition
    XilVitisNetP4Action XilVitisNetP4Action_dropPacket =
    '{
        NameStringPtr : "dropPacket",
        ParamListSize : 0,
        ParamListPtr  : XilVitisNetP4ActionParams_dropPacket
    };

    // Table 'nif_ternary' Action list
    XilVitisNetP4Action XilVitisNetP4TableActions_nif_ternary[] =
    '{
        XilVitisNetP4Action_NoAction,
        XilVitisNetP4Action_dropPacket
    };

    // Table 'nif_ternary' definition
    XilVitisNetP4TargetTableConfig XilVitisNetP4Table_nif_ternary =
    '{
        NameStringPtr : "nif_ternary",
        Config        : '{
            Endian            : XIL_VITIS_NET_P4_LITTLE_ENDIAN,
            Mode              : XIL_VITIS_NET_P4_TABLE_MODE_TCAM,
            KeySizeBits       : 48,
            CamConfig         : '{
                BaseAddr           : XIL_VITIS_NET_P4_NIF_TERNARY_BASEADDR,
                FormatStringPtr    : "16t:32p",
                // Note: The following are not strictly needed for PLUGIN_MODE
                NumEntries         : 64,
                RamFrequencyHz     : 325000000,
                LookupFrequencyHz  : 325000000,
                LookupsPerSec      : 325000000,
                ResponseSizeBits   : 1,
                PrioritySizeBits   : XIL_VITIS_NET_P4_CAM_PRIORITY_SIZE_DEFAULT,
                NumMasks           : 0,
                Endian             : XIL_VITIS_NET_P4_LITTLE_ENDIAN,
                MemType            : XIL_VITIS_NET_P4_CAM_MEM_BRAM,
                OptimizationType   : XIL_VITIS_NET_P4_CAM_OPTIMIZE_NONE,
                RamSizeKbytes      : 0,
                RamChannelWidth    : 0,
                RamNumBanks        : 0
            },
            ActionIdWidthBits : 1,
            ActionListSize    : 2,
            ActionListPtr     : XilVitisNetP4TableActions_nif_ternary
        }
    };

    // list of all tables defined in the design
    XilVitisNetP4TargetTableConfig XilVitisNetP4TableList[] =
    '{
        XilVitisNetP4Table_nif_ternary
    };

    
    // list of all counter externs defined in the design
    XilVitisNetP4TargetCounterConfig XilVitisNetP4CounterList[] =
    {
    };

    // statistics and control registers not enabled
    XilVitisNetP4TargetBuildInfoConfig XilVitisNetP4BuildInfo;
    XilVitisNetP4TargetInterruptConfig XilVitisNetP4Interrupt;
    XilVitisNetP4TargetCtrlConfig      XilVitisNetP4Control;

    // Top Level VitisNetP4 Configuration
    XilVitisNetP4TargetConfig XilVitisNetP4Config_design_netflow_vitis_net_p4_0_0 =
    '{
        Endian          : XIL_VITIS_NET_P4_LITTLE_ENDIAN,
        TableListSize   : 1,
        TableListPtr    : XilVitisNetP4TableList,
        CounterListSize : 0,
        CounterListPtr  : XilVitisNetP4CounterList,
        // Note: The following 3 Ptr's are not strictly needed unless EN_STATS_REGS is enabled
        BuildInfoPtr    : XilVitisNetP4BuildInfo,
        InterruptPtr    : XilVitisNetP4Interrupt,
        CtrlConfigPtr   : XilVitisNetP4Control
    };

////////////////////////////////////////////////////////////////////////////////
// Tasks and Functions
////////////////////////////////////////////////////////////////////////////////

    // get table ID
    function int get_table_id;
       input string table_name;

       for (int tbl_idx = 0; tbl_idx < XilVitisNetP4TableList.size(); tbl_idx++) begin
           if (table_name == XilVitisNetP4TableList[tbl_idx].NameStringPtr) begin
               return tbl_idx;
           end
       end

       return -1;
    endfunction

    // get table format string
    function string get_table_format_string;
        input string table_name;

        int tbl_idx;
        string format_str;

        tbl_idx = get_table_id(table_name);
        format_str = XilVitisNetP4TableList[tbl_idx].Config.CamConfig.FormatStringPtr;

        return format_str;
    endfunction

    // check if table is of a ternary mode type (e.g.: TCAM/STCAM)
    function int table_is_ternary;
        input string table_name;

        int tbl_idx;

        tbl_idx = get_table_id(table_name);
        if (XilVitisNetP4TableList[tbl_idx].Config.Mode == XIL_VITIS_NET_P4_TABLE_MODE_BCAM || 
            XilVitisNetP4TableList[tbl_idx].Config.Mode == XIL_VITIS_NET_P4_TABLE_MODE_TINY_BCAM || 
            XilVitisNetP4TableList[tbl_idx].Config.Mode == XIL_VITIS_NET_P4_TABLE_MODE_DCAM) begin
            return 0;
        end

        return 1;
    endfunction

    // get table action ID width
    function int get_table_action_id_width;
        input string table_name;

        int tbl_idx, width;

        tbl_idx = get_table_id(table_name);
        width = XilVitisNetP4TableList[tbl_idx].Config.ActionIdWidthBits;

        return width;
    endfunction

    // get action ID
    function int get_action_id;
       input string table_name;
       input string action_name;

       for (int tbl_idx = 0; tbl_idx < XilVitisNetP4TableList.size(); tbl_idx++) begin
           if (table_name == XilVitisNetP4TableList[tbl_idx].NameStringPtr) begin
               for (int act_idx = 0; act_idx < XilVitisNetP4TableList[tbl_idx].Config.ActionListPtr.size(); act_idx++) begin
                   if (action_name == XilVitisNetP4TableList[tbl_idx].Config.ActionListPtr[act_idx].NameStringPtr) begin
                       return act_idx;
                   end
               end
           end
       end

       return -1;
    endfunction

    // get table action argument widths list
    function void get_action_arg_widths;
        input string table_name;
        input string action_name;
        output int   widths[$];

        int tbl_idx, act_idx;

        widths = {};
        tbl_idx = get_table_id(table_name);
        act_idx = get_action_id(table_name, action_name);

        for (int i = 0; i < XilVitisNetP4TableList[tbl_idx].Config.ActionListPtr[act_idx].ParamListPtr.size(); i++) begin
            widths[i] = XilVitisNetP4TableList[tbl_idx].Config.ActionListPtr[act_idx].ParamListPtr[i].Value;
        end

    endfunction

    // return user Metadata format string
    // format: 'field1=Value1,Field2=Value2,etc.'
    function string get_userMetadata_formatStr;
        string metadata_format; 

        for (int i = 0; i < XilVitisNetP4UserMetadataFields.size(); i++) begin
            metadata_format = {metadata_format, ",", XilVitisNetP4UserMetadataFields[i].NameStringPtr};
            metadata_format = {metadata_format, "=", $sformatf("0x%0h", XilVitisNetP4UserMetadataFields[i].Value)};
        end
        
        return metadata_format.substr(1, metadata_format.len()-1);
    endfunction

    // Initialize and instantiate all required drivers: tables, externs, etc. ...
   task automatic initialize;
        ref    chandle PrivateCtxPtr[$];
        input  chandle env;

        chandle config_data;
        longint cfg_size;

        if (env != null) begin
            for (int tbl_idx = 0; tbl_idx < XilVitisNetP4TableList.size(); tbl_idx++) begin
                case (XilVitisNetP4TableList[tbl_idx].Config.Mode)
                    XIL_VITIS_NET_P4_TABLE_MODE_BCAM : begin
                        XilVitisNetP4BcamInit(PrivateCtxPtr[tbl_idx], env, XilVitisNetP4TableList[tbl_idx].Config.CamConfig);
                    end
                    XIL_VITIS_NET_P4_TABLE_MODE_TINY_BCAM : begin
                        XilVitisNetP4TinyBcamInit(PrivateCtxPtr[tbl_idx], env, XilVitisNetP4TableList[tbl_idx].Config.CamConfig);
                    end
                    XIL_VITIS_NET_P4_TABLE_MODE_TCAM : begin
                        XilVitisNetP4TcamInit(PrivateCtxPtr[tbl_idx], env, XilVitisNetP4TableList[tbl_idx].Config.CamConfig);
                    end
                    XIL_VITIS_NET_P4_TABLE_MODE_STCAM : begin
                        XilVitisNetP4StcamInit(PrivateCtxPtr[tbl_idx], env, XilVitisNetP4TableList[tbl_idx].Config.CamConfig);
                    end
                    XIL_VITIS_NET_P4_TABLE_MODE_TINY_TCAM : begin
                        XilVitisNetP4TinyTcamInit(PrivateCtxPtr[tbl_idx], env, XilVitisNetP4TableList[tbl_idx].Config.CamConfig);
                    end
                    XIL_VITIS_NET_P4_TABLE_MODE_DCAM : begin
                        XilVitisNetP4DcamInit(PrivateCtxPtr[tbl_idx], env, XilVitisNetP4TableList[tbl_idx].Config.CamConfig);
                    end
                endcase
            end
        end

    endtask

    // Terminate and destroy all instantiated drivers: tables, externs, etc. ...
    task automatic terminate;
        ref  chandle PrivateCtxPtr[$];

        for (int tbl_idx = 0; tbl_idx < XilVitisNetP4TableList.size(); tbl_idx++) begin
            case (XilVitisNetP4TableList[tbl_idx].Config.Mode)
                XIL_VITIS_NET_P4_TABLE_MODE_BCAM : begin
                    XilVitisNetP4BcamExit(PrivateCtxPtr[tbl_idx]);
                end
                XIL_VITIS_NET_P4_TABLE_MODE_TINY_BCAM : begin
                    XilVitisNetP4TinyBcamExit(PrivateCtxPtr[tbl_idx]);
                end
                XIL_VITIS_NET_P4_TABLE_MODE_TCAM : begin
                    XilVitisNetP4TcamExit(PrivateCtxPtr[tbl_idx]);
                end
                XIL_VITIS_NET_P4_TABLE_MODE_STCAM : begin
                    XilVitisNetP4StcamExit(PrivateCtxPtr[tbl_idx]);
                end
                XIL_VITIS_NET_P4_TABLE_MODE_TINY_TCAM : begin
                    XilVitisNetP4TinyTcamExit(PrivateCtxPtr[tbl_idx]);
                end
                XIL_VITIS_NET_P4_TABLE_MODE_DCAM : begin
                    XilVitisNetP4DcamExit(PrivateCtxPtr[tbl_idx]);
                end
            endcase
        end

    endtask

    // Add entry to a table.
    // Usage: table_add <table name> <entry key> <key mask> <entry response> <entry priority>
    task automatic table_add;
        ref    chandle     PrivateCtxPtr[$];
        input  string      table_name;
        input  bit[1023:0] entry_key;
        input  bit[1023:0] key_mask;
        input  bit[1023:0] entry_response;
        input  int         entry_priority;

        int tbl_idx;
        tbl_idx = get_table_id(table_name);

        case (XilVitisNetP4TableList[tbl_idx].Config.Mode)
            XIL_VITIS_NET_P4_TABLE_MODE_BCAM : begin
                XilVitisNetP4BcamInsert(PrivateCtxPtr[tbl_idx], byteArray'(entry_key), byteArray'(entry_response));
            end
            XIL_VITIS_NET_P4_TABLE_MODE_TINY_BCAM : begin
                XilVitisNetP4TinyBcamInsert(PrivateCtxPtr[tbl_idx], byteArray'(entry_key), byteArray'(entry_response));
            end
            XIL_VITIS_NET_P4_TABLE_MODE_TCAM : begin
                XilVitisNetP4TcamInsert(PrivateCtxPtr[tbl_idx], byteArray'(entry_key), byteArray'(key_mask), entry_priority, byteArray'(entry_response));
            end
            XIL_VITIS_NET_P4_TABLE_MODE_STCAM : begin
                XilVitisNetP4StcamInsert(PrivateCtxPtr[tbl_idx], byteArray'(entry_key), byteArray'(key_mask), entry_priority, byteArray'(entry_response));
            end
            XIL_VITIS_NET_P4_TABLE_MODE_TINY_TCAM : begin
                XilVitisNetP4TinyTcamInsert(PrivateCtxPtr[tbl_idx], byteArray'(entry_key), byteArray'(key_mask), entry_priority, byteArray'(entry_response));
            end
            XIL_VITIS_NET_P4_TABLE_MODE_DCAM : begin
                XilVitisNetP4DcamInsert(PrivateCtxPtr[tbl_idx], int'(entry_key), byteArray'(entry_response));
            end
        endcase

    endtask

    // Modify entry from a table.
    // Usage: table_modify <table name> <entry key> <key mask> <entry response>
    task automatic table_modify;
        ref   chandle     PrivateCtxPtr[$];
        input string      table_name;
        input bit[1023:0] entry_key;
        input bit[1023:0] key_mask;
        input bit[1023:0] entry_response;

        int tbl_idx;
        tbl_idx = get_table_id(table_name);

        case (XilVitisNetP4TableList[tbl_idx].Config.Mode)
            XIL_VITIS_NET_P4_TABLE_MODE_BCAM : begin
                XilVitisNetP4BcamUpdate(PrivateCtxPtr[tbl_idx], byteArray'(entry_key), byteArray'(entry_response));
            end
            XIL_VITIS_NET_P4_TABLE_MODE_TINY_BCAM : begin
                XilVitisNetP4TinyBcamUpdate(PrivateCtxPtr[tbl_idx], byteArray'(entry_key), byteArray'(entry_response));
            end
            XIL_VITIS_NET_P4_TABLE_MODE_TCAM : begin
                XilVitisNetP4TcamUpdate(PrivateCtxPtr[tbl_idx], byteArray'(entry_key), byteArray'(key_mask), byteArray'(entry_response));
            end
            XIL_VITIS_NET_P4_TABLE_MODE_STCAM : begin
                XilVitisNetP4StcamUpdate(PrivateCtxPtr[tbl_idx], byteArray'(entry_key), byteArray'(key_mask), byteArray'(entry_response));
            end
            XIL_VITIS_NET_P4_TABLE_MODE_TINY_TCAM : begin
                XilVitisNetP4TinyTcamUpdate(PrivateCtxPtr[tbl_idx], byteArray'(entry_key), byteArray'(key_mask), byteArray'(entry_response));
            end
            XIL_VITIS_NET_P4_TABLE_MODE_DCAM : begin
                XilVitisNetP4DcamUpdate(PrivateCtxPtr[tbl_idx], int'(entry_key), byteArray'(entry_response));
            end
        endcase

    endtask

    // Delete entry from a match table.
    // Usage: table_delete <table name> <entry key> <key mask>
    task automatic table_delete;
        ref   chandle     PrivateCtxPtr[$];
        input string      table_name;
        input bit[1023:0] entry_key;
        input bit[1023:0] key_mask;

        int tbl_idx;
        tbl_idx = get_table_id(table_name);

        case (XilVitisNetP4TableList[tbl_idx].Config.Mode)
            XIL_VITIS_NET_P4_TABLE_MODE_BCAM : begin
                XilVitisNetP4BcamDelete(PrivateCtxPtr[tbl_idx], byteArray'(entry_key));
            end
            XIL_VITIS_NET_P4_TABLE_MODE_TINY_BCAM : begin
                XilVitisNetP4TinyBcamDelete(PrivateCtxPtr[tbl_idx], byteArray'(entry_key));
            end
            XIL_VITIS_NET_P4_TABLE_MODE_TCAM : begin
                XilVitisNetP4TcamDelete(PrivateCtxPtr[tbl_idx], byteArray'(entry_key), byteArray'(key_mask));
            end
            XIL_VITIS_NET_P4_TABLE_MODE_STCAM : begin
                XilVitisNetP4StcamDelete(PrivateCtxPtr[tbl_idx], byteArray'(entry_key), byteArray'(key_mask));
            end
            XIL_VITIS_NET_P4_TABLE_MODE_TINY_TCAM : begin
                XilVitisNetP4TinyTcamDelete(PrivateCtxPtr[tbl_idx], byteArray'(entry_key), byteArray'(key_mask));
            end
            XIL_VITIS_NET_P4_TABLE_MODE_DCAM : begin
                XilVitisNetP4DcamDelete(PrivateCtxPtr[tbl_idx], int'(entry_key));
            end
        endcase

    endtask

    // Delete all entries from a match table.
    // Usage: table_clear <table name>
    task automatic table_clear;
        ref   chandle  PrivateCtxPtr[$];
        input string   table_name;

        int tbl_idx;
        tbl_idx = get_table_id(table_name);

        case (XilVitisNetP4TableList[tbl_idx].Config.Mode)
            XIL_VITIS_NET_P4_TABLE_MODE_BCAM : begin
                XilVitisNetP4BcamReset(PrivateCtxPtr[tbl_idx]);
            end
            XIL_VITIS_NET_P4_TABLE_MODE_TINY_BCAM : begin
                XilVitisNetP4TinyBcamReset(PrivateCtxPtr[tbl_idx]);
            end
            XIL_VITIS_NET_P4_TABLE_MODE_TCAM : begin
                XilVitisNetP4TcamReset(PrivateCtxPtr[tbl_idx]);
            end
            XIL_VITIS_NET_P4_TABLE_MODE_STCAM : begin
                XilVitisNetP4StcamReset(PrivateCtxPtr[tbl_idx]);
            end
            XIL_VITIS_NET_P4_TABLE_MODE_TINY_TCAM : begin
                XilVitisNetP4TinyTcamReset(PrivateCtxPtr[tbl_idx]);
            end
            XIL_VITIS_NET_P4_TABLE_MODE_DCAM : begin
                XilVitisNetP4DcamReset(PrivateCtxPtr[tbl_idx]);
            end
        endcase

    endtask

    // Reset all state in the switch (tables and externs, etc.), but P4 config is preserved.
    // Usage: reset_state
    task automatic reset_state;
        ref  chandle PrivateCtxPtr[$];

        for (int tbl_idx = 0; tbl_idx < XilVitisNetP4TableList.size(); tbl_idx++) begin
            case (XilVitisNetP4TableList[tbl_idx].Config.Mode)
                XIL_VITIS_NET_P4_TABLE_MODE_BCAM : begin
                    XilVitisNetP4BcamReset(PrivateCtxPtr[tbl_idx]);
                end
                XIL_VITIS_NET_P4_TABLE_MODE_TINY_BCAM : begin
                    XilVitisNetP4TinyBcamReset(PrivateCtxPtr[tbl_idx]);
                end
                XIL_VITIS_NET_P4_TABLE_MODE_TCAM : begin
                    XilVitisNetP4TcamReset(PrivateCtxPtr[tbl_idx]);
                end
                XIL_VITIS_NET_P4_TABLE_MODE_STCAM : begin
                    XilVitisNetP4StcamReset(PrivateCtxPtr[tbl_idx]);
                end
                XIL_VITIS_NET_P4_TABLE_MODE_TINY_TCAM : begin
                    XilVitisNetP4TinyTcamReset(PrivateCtxPtr[tbl_idx]);
                end
                XIL_VITIS_NET_P4_TABLE_MODE_DCAM : begin
                    XilVitisNetP4DcamReset(PrivateCtxPtr[tbl_idx]);
                end
            endcase
        end

    endtask

`endif

endpackage

`endif


//--------------------------------------------------------------------------
// Machine-generated file - do NOT modify by hand !
// File created on 01 of April, 2025 @ 22:36:26
// by VitisNetP4 IP, version v2.0 revision 0
//--------------------------------------------------------------------------
