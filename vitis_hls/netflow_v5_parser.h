#pragma once

#include <ap_axi_sdata.h>
// #include <ap_int.h>

typedef ap_axiu<64, 0, 0, 0> axis_word;

void netflow_v5_parser(	hls::stream<axis_word>& input_stream,
						hls::stream<axis_word>& output_stream
);