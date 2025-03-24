#include<iostream>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define O_RDWR	02
#define O_NONBLOCK 04000

using namespace std;

int main() {
	unsigned char buffer[200];
	int fd = open("dma1.txt", O_RDWR | O_NONBLOCK);
	int res = read(fd, buffer, 146);

	printf("%d\n",res);
	for(int i=0;i<res;i++){
		printf("%02X ", buffer[i]);
	}
	return 0;
}
