// For Vits HLS

#include "netflow_v5_parser.h"

#include <ap_axi_sdata.h>
#include <ap_int.h>
#include <hls_stream.h>

#define PARSE_ETHERNET 0
#define PARSE_IP 1
#define PARSE_UDP 2
#define PARSE_NETFLOW_HEADER 3
#define PARSE_NETFLOW_RECORD 4
#define DROP_ALL 5

void get_byte_count(ap_uint<8>& keep,
					ap_uint<4>& current_byte_count) {
	#pragma HLS INLINE
	switch (keep) {
		case 0xFF:
			current_byte_count = 8;
			break;
		case 0x7F:
			current_byte_count = 7;
			break;
		case 0x3F:
			current_byte_count = 6;
			break;
		case 0x1F:
			current_byte_count = 5;
			break;
		case 0x0F:
			current_byte_count = 4;
			break;
		case 0x07:
			current_byte_count = 3;
			break;
		case 0x03:
			current_byte_count = 2;
			break;
		case 0x01:
			current_byte_count = 1;
			break;
		default:
			current_byte_count = 0;
	}
}

void get_bit_from_byte(ap_uint<4>& byte, ap_uint<8>& bit) {
	#pragma HLS INLINE
	switch (byte) {
		case 0:
			bit = 0;
			break;
		case 1:
			bit = 8;
			break;
		case 2:
			bit = 16;
			break;
		case 3:
			bit = 24;
			break;
		case 4:
			bit = 32;
			break;
		case 5:
			bit = 40;
			break;
		case 6:
			bit = 48;
			break;
		case 7:
			bit = 56;
			break;
		case 8:
			bit = 64;
			break;
		default:
			bit = 0;
	}
}

void netflow_v5_parser(hls::stream<axis_word>& input_stream,
                       hls::stream<axis_word>& output_stream) {
#pragma HLS INTERFACE axis port=input_stream
#pragma HLS INTERFACE axis port=output_stream
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS PIPELINE II=1

    static ap_uint<3> state = PARSE_ETHERNET;

    static ap_uint<32> data;

	static ap_uint<3> read_count = 0;
	static ap_uint<3> write_count = 0;

	static uint8_t protocol = 0;
	static uint16_t port = 0;

	axis_word input_word;
    axis_word output_word;

    // Read input
    input_word = input_stream.read();
	read_count++;

    // Determine current byte and bit counts
    ap_uint<4> current_byte_count = 8 - input_word.keep.countLeadingZeros();
    ap_uint<8> current_bit_count = current_byte_count * 8;

    // State machine
    switch (state) {
        case PARSE_ETHERNET:
            if (read_count == 2) {

                uint16_t ethernet_type = input_word.data.range(31, 16);
                state = (ethernet_type == 0x0800) ? PARSE_IP : DROP_ALL;
				// if(state == DROP_ALL) {
				// 	std::cout << "Ethernet type is not IPv4: " << ethernet_type << std::endl;
				// }
				// remaining bytes is 16 - 14 = 2 bytes
				read_count = 1;
            }
            break;

        case PARSE_IP:
			if (read_count == 2) {
				// current bytes is 2 + 8 = 10
				protocol = input_word.data.range(7, 0);
			}
            if (read_count == 4) {
				// current bytes is 2 + 8*3 = 26
				port = input_word.data.range(47, 32);
                state = (protocol == 0x11) ? PARSE_UDP : DROP_ALL;
				// if(state == DROP_ALL) {
				// 	std::cout << "Protocol is not UDP: " << protocol << std::endl;
				// }
				// remaining bytes is 26 - 20 = 6 bytes
				read_count = 1;
            }
            break;

        case PARSE_UDP:
            if (read_count == 2) {
				// current bytes is 6 + 8 = 14
                state = (port == 9995) ? PARSE_NETFLOW_HEADER : DROP_ALL;
				// if(state == DROP_ALL) {
				// 	std::cout << "UDP port is not 9995: " << port << std::endl;
				// }
				// remaining bytes is 14 - 8 = 6 bytes
				read_count = 1;
            }
            break;

        case PARSE_NETFLOW_HEADER:
            if (read_count == 4) {
				// current bytes is 6 + 8*3 = 30
                state = PARSE_NETFLOW_RECORD;
				// remaining bytes is 30 - 26 = 4 bytes
				data = input_word.data & 0xFFFFFFFF;
            }
            break;

        case PARSE_NETFLOW_RECORD:
            if(current_bit_count == 64) {
				for(int i=31; i>=0; i--) {
					#pragma HLS UNROLL
					output_word.data[i+32] = data[i];
					output_word.data[i] = input_word.data[i+32];
					data[i] = input_word.data[i];
				}
			}else if(current_bit_count == 32) {
				// last 4 bytes
				for(int i=31; i>=0; i--) {
					#pragma HLS UNROLL
					output_word.data[i+32] = data[i];
					output_word.data[i] = input_word.data[i];
				}
			}
			output_word.last = (++write_count == 6) ? 1 : 0;
			if (write_count == 6) {
				write_count = 0;
			}
			output_word.keep = 0xFF;
			output_stream.write(output_word);
            break;

        case DROP_ALL:
            break;
    }

    // Reset state if last input word
    if (input_word.get_last()) {
        state = PARSE_ETHERNET;
        read_count = 0;
    }
}
