#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <string.h>

// Define the same structure used in the kernel
typedef struct {
    unsigned int udd_cnt;
    unsigned int pkt_cnt;
    unsigned int data_len;
} ioctl_c2h_peek_data_t;

// Define the IOCTL command values (ensure they match kernel module)
#define QDMA_CDEV_IOCTL_C2H_PEEK 1

int main() {
    int fd;
    ioctl_c2h_peek_data_t c2h_peek_data = {0, 0, 0};

    // Open the device file
    fd = open("/dev/qdma01000-ST-32", O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return errno;
    }

    // Call the QDMA_CDEV_IOCTL_C2H_PEEK IOCTL command
    if (ioctl(fd, QDMA_CDEV_IOCTL_C2H_PEEK, &c2h_peek_data) != 0) {
        perror("ioctl failed");
        close(fd);
        return errno;
    }

    // Display the updated data received from the kernel
    printf("Updated data received from kernel:\n");
    printf("data_len: %u\n", c2h_peek_data.data_len);

    // Close the device file
    close(fd);
    return 0;
}
