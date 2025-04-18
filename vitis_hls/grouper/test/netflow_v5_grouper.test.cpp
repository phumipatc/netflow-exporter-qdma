#include "netflow_v5_parser.h"

#include <iostream>
using namespace std;

#define PACKET 1

int main() {
	hls::stream<axis_word> input_stream, output_stream;

	axis_word input_word, output_word;

	ap_uint<64> input_data[] = {
		0xFFFFFFFFFFFFFFFF,
		0xFFFFFFFF08001234,
		0x56789ABCDEF01211,
		0x4567890ABCDEFFFF,
		0xFFFF270BFFFFFFFF,
		0xFFFFFFFFFFFFFFFF,
		0xFFFFFFFFFFFFFFFF,
		0xFFFFFFFFFFFFFFFF
	};
	
	int input_size = 8;
	ap_uint<8> input_keep[input_size];

	for(int i=0;i<input_size-1;i++){
		input_keep[i] = 0xFF;
	}
	input_keep[input_size-1] = 0x0F;

	for(int p=0;p<PACKET;p++){
		for(int i = 0; i < input_size; i++) {
			input_word.data = input_data[i];
			input_word.keep = input_keep[i];
			if(i%2 == 1) {
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
		0xFFFFFFFFFFFFFFFF,
		0xFFFFFFFF08001234,
		0x56789ABCDEF01211,
		0x4567890ABCDEFFFF,
		0xFFFF270BFFFFFFFF,
		0xFFFFFFFFFFFFFFFF,
		0xFFFFFFFFFFFFFFFF,
		0xFFFFFFFFFFFFFFFF
	};
	ap_uint<8> expected_output_keep[] = {
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0x0F
	};
	ap_uint<1> expected_output_last[] = {
		0, 1, 0, 1, 0, 1, 0, 1
	};
	int expected_output_size = 8;

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
