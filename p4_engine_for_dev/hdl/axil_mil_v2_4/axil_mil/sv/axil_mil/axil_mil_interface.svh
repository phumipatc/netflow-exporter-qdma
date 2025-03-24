// (c) Copyright 2017, 2023 Advanced Micro Devices, Inc. All rights reserved.
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
//       Owner:
//       Description:
//
//////////////////////////////////////////////////////////////////////////////

`ifndef __AXIL_MIL_INTERFACE__
`define __AXIL_MIL_INTERFACE__

interface axil_interface_wa #(
    parameter AW = 32
) (
    input logic clk,
    input logic rstn
);

logic        awvalid;
logic        awready;
logic [AW-1:0] awaddr;
logic [2:0]  awprot;

modport master(
    output awvalid,
    input  awready,
    output awaddr,
    output awprot
);

modport slave(
    input  awvalid,
    output awready,
    input  awaddr,
    input  awprot
);

endinterface

interface axil_interface_wd #(
    parameter DW = 32
) (
    input logic clk,
    input logic rstn
);

logic        wvalid;
logic        wready;
logic [DW-1:0] wdata;
logic [(DW/8)-1:0]  wstrb;

modport master(
    output wvalid,
    input  wready,
    output wdata,
    output wstrb
);

modport slave(
    input  wvalid,
    output wready,
    input  wdata,
    input  wstrb
);

endinterface

interface axil_interface_wr(
    input logic clk,
    input logic rstn
);

logic        bvalid;
logic        bready;
logic [1:0]  bresp;

modport master(
    input  bvalid,
    output bready,
    input  bresp
);

modport slave(
    output bvalid,
    input  bready,
    output bresp
);

endinterface

interface axil_interface_ra #(
    parameter AW = 32
) (
    input logic clk,
    input logic rstn
);

logic        arvalid;
logic        arready;
logic [AW-1:0] araddr;
logic [2:0]  arprot;

modport master(
    output arvalid,
    input  arready,
    output araddr,
    output arprot
);

modport slave(
    input  arvalid,
    output arready,
    input  araddr,
    input  arprot
);

endinterface

interface axil_interface_rd #(
    parameter DW = 32
) (
    input logic clk,
    input logic rstn
);

logic        rvalid;
logic        rready;
logic [DW-1:0] rdata;
logic [1:0]  rresp;

modport master(
    input  rvalid,
    output rready,
    input  rdata,
    input  rresp
);

modport slave(
    output rvalid,
    input  rready,
    output rdata,
    output rresp
);

endinterface

`endif

