-- (c) Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- (c) Copyright 2022-2025 Advanced Micro Devices, Inc. All rights reserved.
-- 
-- This file contains confidential and proprietary information
-- of AMD and is protected under U.S. and international copyright
-- and other intellectual property laws.
-- 
-- DISCLAIMER
-- This disclaimer is not a license and does not grant any
-- rights to the materials distributed herewith. Except as
-- otherwise provided in a valid license issued to you by
-- AMD, and to the maximum extent permitted by applicable
-- law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
-- WITH ALL FAULTS, AND AMD HEREBY DISCLAIMS ALL WARRANTIES
-- AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
-- BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
-- INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
-- (2) AMD shall not be liable (whether in contract or tort,
-- including negligence, or under any other theory of
-- liability) for any loss or damage of any kind or nature
-- related to, arising under or in connection with these
-- materials, including for any direct, or any indirect,
-- special, incidental, or consequential loss or damage
-- (including loss of data, profits, goodwill, or any type of
-- loss or damage suffered as a result of any action brought
-- by a third party) even if such damage or loss was
-- reasonably foreseeable or AMD had been advised of the
-- possibility of the same.
-- 
-- CRITICAL APPLICATIONS
-- AMD products are not designed or intended to be fail-
-- safe, or for use in any application requiring fail-safe
-- performance, such as life-support or safety devices or
-- systems, Class III medical devices, nuclear facilities,
-- applications related to the deployment of airbags, or any
-- other applications that could lead to death, personal
-- injury, or severe property or environmental damage
-- (individually and collectively, "Critical
-- Applications"). Customer assumes the sole risk and
-- liability of any use of AMD products in Critical
-- Applications, subject only to applicable laws and
-- regulations governing limitations on product liability.
-- 
-- THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
-- PART OF THIS FILE AT ALL TIMES.
-- 
-- DO NOT MODIFY THIS FILE.
-- IP VLNV: xilinx.com:ip:vitis_net_p4:2.0
-- IP Revision: 0

-- The following code must appear in the VHDL architecture header.

------------- Begin Cut here for COMPONENT Declaration ------ COMP_TAG
COMPONENT p4_engine
  PORT (
    s_axis_aclk : IN STD_LOGIC;
    s_axis_aresetn : IN STD_LOGIC;
    s_axi_aclk : IN STD_LOGIC;
    s_axi_aresetn : IN STD_LOGIC;
    cam_mem_aclk : IN STD_LOGIC;
    cam_mem_aresetn : IN STD_LOGIC;
    user_metadata_in : IN STD_LOGIC_VECTOR(11 DOWNTO 0);
    user_metadata_in_valid : IN STD_LOGIC;
    user_metadata_out : OUT STD_LOGIC_VECTOR(11 DOWNTO 0);
    user_metadata_out_valid : OUT STD_LOGIC;
    s_axis_tdata : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
    s_axis_tkeep : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
    s_axis_tlast : IN STD_LOGIC;
    s_axis_tvalid : IN STD_LOGIC;
    s_axis_tready : OUT STD_LOGIC;
    s_axis_tid : IN STD_LOGIC_VECTOR(10 DOWNTO 0);
    m_axis_tdata : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
    m_axis_tkeep : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
    m_axis_tlast : OUT STD_LOGIC;
    m_axis_tvalid : OUT STD_LOGIC;
    m_axis_tready : IN STD_LOGIC;
    m_axis_tid : OUT STD_LOGIC_VECTOR(10 DOWNTO 0);
    s_axi_araddr : IN STD_LOGIC_VECTOR(12 DOWNTO 0);
    s_axi_arready : OUT STD_LOGIC;
    s_axi_arvalid : IN STD_LOGIC;
    s_axi_awaddr : IN STD_LOGIC_VECTOR(12 DOWNTO 0);
    s_axi_awready : OUT STD_LOGIC;
    s_axi_awvalid : IN STD_LOGIC;
    s_axi_bready : IN STD_LOGIC;
    s_axi_bresp : OUT STD_LOGIC_VECTOR(1 DOWNTO 0);
    s_axi_bvalid : OUT STD_LOGIC;
    s_axi_rdata : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
    s_axi_rready : IN STD_LOGIC;
    s_axi_rresp : OUT STD_LOGIC_VECTOR(1 DOWNTO 0);
    s_axi_rvalid : OUT STD_LOGIC;
    s_axi_wdata : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
    s_axi_wready : OUT STD_LOGIC;
    s_axi_wstrb : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
    s_axi_wvalid : IN STD_LOGIC 
  );
END COMPONENT;
-- COMP_TAG_END ------ End COMPONENT Declaration ------------

-- The following code must appear in the VHDL architecture
-- body. Substitute your own instance name and net names.

------------- Begin Cut here for INSTANTIATION Template ----- INST_TAG
your_instance_name : p4_engine
  PORT MAP (
    s_axis_aclk => s_axis_aclk,
    s_axis_aresetn => s_axis_aresetn,
    s_axi_aclk => s_axi_aclk,
    s_axi_aresetn => s_axi_aresetn,
    cam_mem_aclk => cam_mem_aclk,
    cam_mem_aresetn => cam_mem_aresetn,
    user_metadata_in => user_metadata_in,
    user_metadata_in_valid => user_metadata_in_valid,
    user_metadata_out => user_metadata_out,
    user_metadata_out_valid => user_metadata_out_valid,
    s_axis_tdata => s_axis_tdata,
    s_axis_tkeep => s_axis_tkeep,
    s_axis_tlast => s_axis_tlast,
    s_axis_tvalid => s_axis_tvalid,
    s_axis_tready => s_axis_tready,
    s_axis_tid => s_axis_tid,
    m_axis_tdata => m_axis_tdata,
    m_axis_tkeep => m_axis_tkeep,
    m_axis_tlast => m_axis_tlast,
    m_axis_tvalid => m_axis_tvalid,
    m_axis_tready => m_axis_tready,
    m_axis_tid => m_axis_tid,
    s_axi_araddr => s_axi_araddr,
    s_axi_arready => s_axi_arready,
    s_axi_arvalid => s_axi_arvalid,
    s_axi_awaddr => s_axi_awaddr,
    s_axi_awready => s_axi_awready,
    s_axi_awvalid => s_axi_awvalid,
    s_axi_bready => s_axi_bready,
    s_axi_bresp => s_axi_bresp,
    s_axi_bvalid => s_axi_bvalid,
    s_axi_rdata => s_axi_rdata,
    s_axi_rready => s_axi_rready,
    s_axi_rresp => s_axi_rresp,
    s_axi_rvalid => s_axi_rvalid,
    s_axi_wdata => s_axi_wdata,
    s_axi_wready => s_axi_wready,
    s_axi_wstrb => s_axi_wstrb,
    s_axi_wvalid => s_axi_wvalid
  );
-- INST_TAG_END ------ End INSTANTIATION Template ---------

-- You must compile the wrapper file p4_engine.vhd when simulating
-- the core, p4_engine. When compiling the wrapper file, be sure to
-- reference the VHDL simulation library.



