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
#include <core.p4>

error {
    HeaderDepthLimitExceeded
}

match_kind {
    range,
    field_mask,
    unused
}

struct standard_metadata_t {
    bit<1>  drop;
    bit<64> ingress_timestamp;
    bit<16> parsed_bytes;
    error   parser_error;
}

extern UserExtern<I, O> {
    UserExtern(bit<16> fixed_latency_in_cycles);
    void apply(in I data_in, out O result);
}

enum CounterType_t {
    PACKETS,
    BYTES,
    PACKETS_AND_BYTES
}

extern Counter<W, S> {
  Counter(bit<32> n_counters, CounterType_t type);
  void count(in S index);
}

// BEGIN:Hash_algorithms
enum HashAlgorithm_t {
  CRC32,
  CRC16,
  ONES_COMPLEMENT16  /// One's complement 16-bit sum used for IPv4 headers,
}
// END:Hash_algorithms

// BEGIN:Checksum_extern
extern Checksum<H>{
  /// Constructor
  Checksum(HashAlgorithm_t hash);

  void apply<T, W>(in T data, out W result);
}
// END:Checksum_extern

// BEGIN:InternetChecksum_extern
// Checksum based on `ONES_COMPLEMENT16` algorithm used in IPv4, TCP, and UDP.
// Supports incremental updating via `subtract` method.
// See IETF RFC 1624.
extern InternetChecksum {
  InternetChecksum();
  void clear();
  /// Add data to checksum.  data must be a multiple of 16 bits long.
  void add<T>(in T data);
  /// Subtract data from existing checksum.  data must be a multiple of
  /// 16 bits long.
  void subtract<T>(in T data);
  void get<W>(out W result);

}
// END:InternetChecksum_extern

parser Parser<H, M>(packet_in b,
                    out H hdr,
                    inout M meta,
                    inout standard_metadata_t standard_metadata);

control MatchAction<H, M>(inout H hdr,
                          inout M meta,
                          inout standard_metadata_t standard_metadata);

control Deparser<H, M>(packet_out b,
                       in H hdr,
                       inout M meta,
                       inout standard_metadata_t standard_metadata);

package XilinxPipeline<H, M>(Parser<H, M> p,
                             MatchAction<H, M> ma,
                             Deparser<H, M> dep);
