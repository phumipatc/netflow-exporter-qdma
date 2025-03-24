#include<iostream>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


using namespace std;

int convertToInteger(unsigned char* buffer, int size, int base=16){
	int result = 0;
	for(int i=0;i<size;i++){
		result = result*base + buffer[i];
	}
	return result;
}

int main(int argc, char* argv[]){
	// read size of the buffer
	if(argc < 2){
		cout<<"Usage: "<<argv[0]<<" <size to read>"<<endl;
		return 1;
	}

	int size = atoi(argv[1]);

	unsigned char buffer[size];
	int fd = open("/dev/qdma01000-ST-32", O_RDWR | O_NONBLOCK);
	int res = read(fd, buffer, size);

	if(res < 0) {
		perror("Failed to read the device");
		return errno;
	}

	printf("read size: %d\n",res);
	for(int i=0;i<res;i++){
		printf("%02X ", buffer[i]);
	}
	return 0;
}
