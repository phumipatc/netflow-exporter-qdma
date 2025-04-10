#include "netflow_v5_parser.h"

#include <iostream>
using namespace std;

#define PACKET 1

int main() {
	hls::stream<axis_word> input_stream, output_stream;

	axis_word input_word, output_word;

	ap_uint<64> input_data[] = {
		0xFFFFFFFFFFFFFFFF,
		0xFFFFFFFF08001234, // end of thernet at bytes 14
		0x56789ABCDEF01211,
		0x4567890ABCDEFFFF,
		0xFFFF270BFFFFFFFF,
		0xFFFFFFFFFFFFFFFF,
		0xFFFFFFFFFFFFFFFF,
		0xFFFFFFFFFFFFFFFF,
		0xFFFFFFFF00010203,
		0x0405060708090A0B,
		0x0C0D0E0F10111213,
		0x1415161718191A1B,
		0x1C1D1E1F20212223,
		0x2425262728292A2B,
		0x2C2D2E2F30313233,
		0x3435363738393A3B,
		0x3C3D3E3F40414243,
		0x4445464748494A4B,
		0x4C4D4E4F50515253,
		0x5455565758595A5B,
		0x000000005C5D5E5F
	};
	
	int input_size = 21;
	ap_uint<8> input_keep[input_size];

	for(int i=0;i<input_size-1;i++){
		input_keep[i] = 0xFF;
	}
	input_keep[input_size-1] = 0x0F;

	for(int p=0;p<PACKET;p++){
		for(int i = 0; i < input_size; i++) {
			input_word.data = input_data[i];
			input_word.keep = input_keep[i];
			if(i == input_size - 1) {
				input_word.last = 1;
			} else {
				input_word.last = 0;
			}
			input_stream.write(input_word);
		}
	}

	while(!input_stream.empty()){
		netflow_v5_parser(input_stream, output_stream);
	}

	ap_uint<64> expected_output_data[] = {
		0x0001020304050607,
		0x08090A0B0C0D0E0F,
		0x1011121314151617,
		0x18191A1B1C1D1E1F,
		0x2021222324252627,
		0x28292A2B2C2D2E2F,
		0x3031323334353637,
		0x38393A3B3C3D3E3F,
		0x4041424344454647,
		0x48494A4B4C4D4E4F,
		0x5051525354555657,
		0x58595A5B5C5D5E5F
	};
	ap_uint<8> expected_output_keep[] = {
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF
	};
	ap_uint<1> expected_output_last[] = {
		0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1
	};
	int expected_output_size = 12;

	if(output_stream.size() == expected_output_size * PACKET) {
		cout << "correct size\n";
	} else {
		cout << "wrong size, expected " << expected_output_size * PACKET << " but got " << output_stream.size() << '\n';
		while(!output_stream.empty()) {
			output_word = output_stream.read();
			cout << output_word.data << "\n";
		}
		return 0;
	}

	int output_count = 0;
	while(!output_stream.empty()) {
		output_word = output_stream.read();
		cout << "Index "  << output_count << " : \n";

		cout << "Data: ";
		if (output_word.data == expected_output_data[output_count]) {
			cout << "correct\n";
		} else {
			cout << "wrong, expected " << expected_output_data[output_count] << " but got " << output_word.data << "\n";
		}

		cout << "Keep: ";
		if (output_word.keep == expected_output_keep[output_count]) {
			cout << "correct\n";
		} else {
			cout << "wrong, expected " << expected_output_keep[output_count] << " but got " << output_word.keep << "\n";
		}

		cout << "Last: ";
		if (output_word.last == expected_output_last[output_count]) {
			cout << "correct\n";
		} else {
			cout << "wrong, expected " << expected_output_last[output_count] << " but got " << output_word.last << "\n";
		}

		output_count++;
		if(output_count == expected_output_size) {
			output_count = 0;
		}
	}
	return 0;
}
