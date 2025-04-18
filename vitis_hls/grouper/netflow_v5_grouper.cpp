#include "netflow_v5_grouper.h"

void netflow_v5_parser(hls::stream<axis_word>& input_stream,
						ap_uint<6>& qid,
						hls::stream<axis_word>& output_stream) {
#pragma HLS INTERFACE axis port=input_stream
#pragma HLS INTERFACE axis port=output_stream
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS PIPELINE II=1

	static ap_uint<2> read_count = 0;
	static ap_uint<6> last_qid = 0;
	static axis_word last_word;

	axis_word word;

	word = input_stream.read();

	if(last_qid != qid) {
		if(last_qid == 0) {
			last_qid = qid;
		}
	}

	if(word.last == 1) {

	}
}

// things to be consider in this module:
// timeout: if the input stream is empty for a certain amount of time, the output stream should be flushed