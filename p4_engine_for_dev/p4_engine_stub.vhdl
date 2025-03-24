-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2023.2.1 (lin64) Build 4081461 Thu Dec 14 12:22:04 MST 2023
-- Date        : Sat Mar  8 17:46:53 2025
-- Host        : hoshino-System-Product-Name running 64-bit Ubuntu 22.04.5 LTS
-- Command     : write_vhdl -force -mode synth_stub
--               /home/hoshino/Desktop/Dej/MAIN_FPGA/NetFlow_Packet_Analyzer_shell.gen/sources_1/ip/p4_engine/p4_engine_stub.vhdl
-- Design      : p4_engine
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xcve2302-sfva784-1LP-e-S
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity p4_engine is
  Port ( 
    s_axis_aclk : in STD_LOGIC;
    s_axis_aresetn : in STD_LOGIC;
    s_axi_aclk : in STD_LOGIC;
    s_axi_aresetn : in STD_LOGIC;
    cam_mem_aclk : in STD_LOGIC;
    cam_mem_aresetn : in STD_LOGIC;
    user_metadata_in : in STD_LOGIC_VECTOR ( 11 downto 0 );
    user_metadata_in_valid : in STD_LOGIC;
    user_metadata_out : out STD_LOGIC_VECTOR ( 11 downto 0 );
    user_metadata_out_valid : out STD_LOGIC;
    s_axi_awaddr : in STD_LOGIC_VECTOR ( 12 downto 0 );
    s_axi_awvalid : in STD_LOGIC;
    s_axi_awready : out STD_LOGIC;
    s_axi_wdata : in STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axi_wstrb : in STD_LOGIC_VECTOR ( 3 downto 0 );
    s_axi_wvalid : in STD_LOGIC;
    s_axi_wready : out STD_LOGIC;
    s_axi_bresp : out STD_LOGIC_VECTOR ( 1 downto 0 );
    s_axi_bvalid : out STD_LOGIC;
    s_axi_bready : in STD_LOGIC;
    s_axi_araddr : in STD_LOGIC_VECTOR ( 12 downto 0 );
    s_axi_arvalid : in STD_LOGIC;
    s_axi_arready : out STD_LOGIC;
    s_axi_rdata : out STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axi_rvalid : out STD_LOGIC;
    s_axi_rready : in STD_LOGIC;
    s_axi_rresp : out STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axis_tdata : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_axis_tkeep : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axis_tvalid : out STD_LOGIC;
    m_axis_tlast : out STD_LOGIC;
    m_axis_tid : out STD_LOGIC_VECTOR ( 10 downto 0 );
    m_axis_tready : in STD_LOGIC;
    s_axis_tdata : in STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axis_tkeep : in STD_LOGIC_VECTOR ( 3 downto 0 );
    s_axis_tvalid : in STD_LOGIC;
    s_axis_tlast : in STD_LOGIC;
    s_axis_tid : in STD_LOGIC_VECTOR ( 10 downto 0 );
    s_axis_tready : out STD_LOGIC
  );

end p4_engine;

architecture stub of p4_engine is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "s_axis_aclk,s_axis_aresetn,s_axi_aclk,s_axi_aresetn,cam_mem_aclk,cam_mem_aresetn,user_metadata_in[11:0],user_metadata_in_valid,user_metadata_out[11:0],user_metadata_out_valid,s_axi_awaddr[12:0],s_axi_awvalid,s_axi_awready,s_axi_wdata[31:0],s_axi_wstrb[3:0],s_axi_wvalid,s_axi_wready,s_axi_bresp[1:0],s_axi_bvalid,s_axi_bready,s_axi_araddr[12:0],s_axi_arvalid,s_axi_arready,s_axi_rdata[31:0],s_axi_rvalid,s_axi_rready,s_axi_rresp[1:0],m_axis_tdata[31:0],m_axis_tkeep[3:0],m_axis_tvalid,m_axis_tlast,m_axis_tid[10:0],m_axis_tready,s_axis_tdata[31:0],s_axis_tkeep[3:0],s_axis_tvalid,s_axis_tlast,s_axis_tid[10:0],s_axis_tready";
begin
end;
