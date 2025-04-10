// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2023.2.1 (lin64) Build 4081461 Thu Dec 14 12:22:04 MST 2023
// Date        : Tue Apr  1 22:41:28 2025
// Host        : dej-IdeaPad-Gaming-3-15ACH6 running 64-bit Ubuntu 22.04.5 LTS
// Command     : write_verilog -force -mode synth_stub
//               /home/dej/Desktop/Capstone/Netflow_Packet_Analyzer/Netflow_Packet_Analyzer/Netflow_Packet_Analyzer.gen/sources_1/bd/design_netflow/ip/design_netflow_vitis_net_p4_0_0/design_netflow_vitis_net_p4_0_0_stub.v
// Design      : design_netflow_vitis_net_p4_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xcve2302-sfva784-1LP-e-S
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
module design_netflow_vitis_net_p4_0_0(s_axis_aclk, s_axis_aresetn, s_axi_aclk, 
  s_axi_aresetn, cam_mem_aclk, cam_mem_aresetn, user_metadata_in, user_metadata_in_valid, 
  user_metadata_out, user_metadata_out_valid, s_axi_awaddr, s_axi_awvalid, s_axi_awready, 
  s_axi_wdata, s_axi_wstrb, s_axi_wvalid, s_axi_wready, s_axi_bresp, s_axi_bvalid, 
  s_axi_bready, s_axi_araddr, s_axi_arvalid, s_axi_arready, s_axi_rdata, s_axi_rvalid, 
  s_axi_rready, s_axi_rresp, m_axis_tdata, m_axis_tkeep, m_axis_tvalid, m_axis_tlast, 
  m_axis_tid, m_axis_tready, s_axis_tdata, s_axis_tkeep, s_axis_tvalid, s_axis_tlast, 
  s_axis_tid, s_axis_tready)
/* synthesis syn_black_box black_box_pad_pin="s_axis_aresetn,s_axi_aresetn,cam_mem_aclk,cam_mem_aresetn,user_metadata_in[11:0],user_metadata_in_valid,user_metadata_out[11:0],user_metadata_out_valid,s_axi_awaddr[12:0],s_axi_awvalid,s_axi_awready,s_axi_wdata[31:0],s_axi_wstrb[3:0],s_axi_wvalid,s_axi_wready,s_axi_bresp[1:0],s_axi_bvalid,s_axi_bready,s_axi_araddr[12:0],s_axi_arvalid,s_axi_arready,s_axi_rdata[31:0],s_axi_rvalid,s_axi_rready,s_axi_rresp[1:0],m_axis_tdata[31:0],m_axis_tkeep[3:0],m_axis_tvalid,m_axis_tlast,m_axis_tid[10:0],m_axis_tready,s_axis_tdata[31:0],s_axis_tkeep[3:0],s_axis_tvalid,s_axis_tlast,s_axis_tid[10:0],s_axis_tready" */
/* synthesis syn_force_seq_prim="s_axis_aclk" */
/* synthesis syn_force_seq_prim="s_axi_aclk" */;
  input s_axis_aclk /* synthesis syn_isclock = 1 */;
  input s_axis_aresetn;
  input s_axi_aclk /* synthesis syn_isclock = 1 */;
  input s_axi_aresetn;
  input cam_mem_aclk;
  input cam_mem_aresetn;
  input [11:0]user_metadata_in;
  input user_metadata_in_valid;
  output [11:0]user_metadata_out;
  output user_metadata_out_valid;
  input [12:0]s_axi_awaddr;
  input s_axi_awvalid;
  output s_axi_awready;
  input [31:0]s_axi_wdata;
  input [3:0]s_axi_wstrb;
  input s_axi_wvalid;
  output s_axi_wready;
  output [1:0]s_axi_bresp;
  output s_axi_bvalid;
  input s_axi_bready;
  input [12:0]s_axi_araddr;
  input s_axi_arvalid;
  output s_axi_arready;
  output [31:0]s_axi_rdata;
  output s_axi_rvalid;
  input s_axi_rready;
  output [1:0]s_axi_rresp;
  output [31:0]m_axis_tdata;
  output [3:0]m_axis_tkeep;
  output m_axis_tvalid;
  output m_axis_tlast;
  output [10:0]m_axis_tid;
  input m_axis_tready;
  input [31:0]s_axis_tdata;
  input [3:0]s_axis_tkeep;
  input s_axis_tvalid;
  input s_axis_tlast;
  input [10:0]s_axis_tid;
  output s_axis_tready;
endmodule
