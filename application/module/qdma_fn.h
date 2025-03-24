#ifndef QDMA_FN_H
#define QDMA_FN_H

#include "qdma_config.h"

// Define the same structure used in the kernel
typedef struct {
    unsigned int udd_cnt;
    unsigned int pkt_cnt;
    unsigned int data_len;
} ioctl_c2h_peek_data_t;

// Define the IOCTL command values (ensure they match kernel module)
#define QDMA_CDEV_IOCTL_C2H_PEEK 1

int peek_qdma_data_len(int fd, ioctl_c2h_peek_data_t *c2h_peek_data);

int prepare_q_add(struct xcmd_info *xcmd, unsigned int device_id, unsigned int queue_id, unsigned int queue_mode, unsigned int queue_dir);

int prepare_q_start(struct xcmd_info *xcmd, unsigned int device_id, int queue_id, int queue_dir);

int queue_init(unsigned int device_id, unsigned int queue_id);

int read_qdma_binary(int fd, unsigned char* buffer, int size);

#endif