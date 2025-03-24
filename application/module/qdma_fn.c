#include "qdma_fn.h"

#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <unistd.h>

int peek_qdma_data_len(int fd, ioctl_c2h_peek_data_t *c2h_peek_data) {
	// Call the QDMA_CDEV_IOCTL_C2H_PEEK IOCTL command
	if (ioctl(fd, QDMA_CDEV_IOCTL_C2H_PEEK, c2h_peek_data) != 0) {
		perror("ioctl failed");
		return errno;
	}

	return 0;
}

int prepare_q_get_state(struct xcmd_info *xcmd, unsigned int device_id, unsigned int queue_id, unsigned int queue_mode, unsigned int queue_dir) {
	int ret;
	char *p;

	memset(xcmd, 0, sizeof(struct xcmd_info));

	struct xcmd_q_parm *qparm = &xcmd->req.qparm;

	xcmd->op = XNL_CMD_GET_Q_STATE;
	xcmd->vf = 0;
	xcmd->if_bdf = device_id;

	qparm->idx = queue_id;
	qparm->num_q = 1;
	qparm->flags = queue_mode | queue_dir;
	qparm->sflags = (1 << QPARM_IDX) | (1 << QPARM_MODE) | (1 << QPARM_DIR);

	ret = xnl_proc_cmd(xcmd);
	printf("response: %d\n", xcmd->resp.q_info.state);
	if (ret < 0) {
		printf("Error in processing q dump command with ret = %d\n", ret);
		return ret;
	}

	return 0;
}

int prepare_q_add(struct xcmd_info *xcmd, unsigned int device_id, unsigned int queue_id, unsigned int queue_mode, unsigned int queue_dir) {
	int ret;
	char *p;

	memset(xcmd, 0, sizeof(struct xcmd_info));

	struct xcmd_q_parm *qparm = &xcmd->req.qparm;

	xcmd->op = XNL_CMD_Q_ADD;
	xcmd->vf = 0;
	xcmd->if_bdf = device_id;

	qparm->idx = queue_id;
	qparm->num_q = 1;
	qparm->flags = queue_mode | queue_dir;
	qparm->sflags = (1 << QPARM_IDX) | (1 << QPARM_MODE) | (1 << QPARM_DIR);

	ret = xnl_proc_cmd(xcmd);
	if (ret < 0) {
		printf("Error in processing q add command with ret = %d\n", ret);
		return ret;
	}

	return 0;
}

int prepare_q_start(struct xcmd_info *xcmd, unsigned int device_id, int queue_id, int queue_dir) {
	int ret;
	char *p;

	memset(xcmd, 0, sizeof(struct xcmd_info));

	struct xcmd_q_parm *qparm = &xcmd->req.qparm;

	xcmd->op = XNL_CMD_Q_START;
	xcmd->vf = 0;
	xcmd->if_bdf = device_id;

	qparm->idx = queue_id;
	qparm->num_q = 1;
	qparm->flags = queue_dir;
	qparm->qrngsz_idx = 9;
	qparm->sflags = (1 << QPARM_IDX) | (1 << QPARM_DIR) | (1 << QPARM_RNGSZ_IDX);

	ret = xnl_proc_cmd(xcmd);
	if (ret < 0) {
		printf("Error in processing q start command with ret = %d\n", ret);
		return ret;
	}

	return 0;
}

int queue_init(unsigned int device_id, unsigned int queue_id) {
	struct xcmd_info xcmd;
	int ret;

	// ret = prepare_q_get_state(&xcmd, device_id, queue_id, XNL_F_QMODE_ST, XNL_F_QDIR_BOTH);
	// if (ret < 0) {
	// 	printf("Error in preparing q dump command with ret = %d\n", ret);
	// 	return ret;
	// }

	ret = prepare_q_add(&xcmd, device_id, queue_id, XNL_F_QMODE_ST, XNL_F_QDIR_BOTH);
	if (ret < 0) {
		printf("Error in preparing q add command with ret = %d\n", ret);
		return ret;
	}

	ret = prepare_q_start(&xcmd, device_id, queue_id, XNL_F_QDIR_BOTH);
	if (ret < 0) {
		printf("Error in preparing q start command with ret = %d\n", ret);
		return ret;
	}

	return 0;
}

int read_qdma_binary(int fd, unsigned char* buffer, int size) {
	int res = read(fd, buffer, size);

	if (res < 0) {
		perror("Failed to read the device");
		return errno;
	}

	return res;
}