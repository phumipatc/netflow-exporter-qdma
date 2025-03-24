#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#include<dmautils.h>
#include<qdma_nl.h>

static int (*xnl_proc_fn[XNL_CMD_MAX])(struct xcmd_info *xcmd) = {
	qdma_dev_list_dump,      /* XNL_CMD_DEV_LIST */
	qdma_dev_info,           /* XNL_CMD_DEV_INFO */
	qdma_dev_stat,           /* XNL_CMD_DEV_STAT */
	qdma_dev_stat_clear,     /* XNL_CMD_DEV_STAT_CLEAR */
	qdma_reg_dump,           /* XNL_CMD_REG_DUMP */
	qdma_reg_read,           /* XNL_CMD_REG_RD */
	qdma_reg_write,          /* XNL_CMD_REG_WRT */
	qdma_dev_q_list_dump,    /* XNL_CMD_Q_LIST */
	qdma_q_add,              /* XNL_CMD_Q_ADD */
	qdma_q_start,            /* XNL_CMD_Q_START */
	qdma_q_stop,             /* XNL_CMD_Q_STOP */
	qdma_q_del,              /* XNL_CMD_Q_DEL */
	qdma_q_dump,             /* XNL_CMD_Q_DUMP */
	qdma_q_desc_dump,        /* XNL_CMD_Q_DESC */
	qdma_q_desc_dump,        /* XNL_CMD_Q_CMPT */
	NULL,                    /* XNL_CMD_Q_RX_PKT */
	qdma_q_cmpt_read,        /* XNL_CMD_Q_CMPT_READ */
#ifdef ERR_DEBUG
	NULL,                    /* XNL_CMD_Q_ERR_INDUCE */
#endif
	qdma_dev_intr_ring_dump, /* XNL_CMD_INTR_RING_DUMP */
	NULL,                    /* XNL_CMD_Q_UDD */
	qdma_dev_get_global_csr, /* XNL_CMD_GLOBAL_CSR */
	qdma_dev_cap,            /* XNL_CMD_DEV_CAP */
	NULL,                    /* XNL_CMD_GET_Q_STATE */
	qdma_reg_info_read,       /* XNL_CMD_REG_INFO_READ */
#ifdef TANDEM_BOOT_SUPPORTED
	qdma_en_st,           /* XNL_CMD_EN_ST */
#endif
};

// std::string getQueueSetupCmd(int queue_id) {
// 	return "dma-ctl qdma01000 q add idx " 
// 				+ std::to_string(queue_id) 
// 				+ " mode st dir bi && dma-ctl qdma01000 q start idx " 
// 				+ std::to_string(queue_id) 
// 				+ " dir bi";
// }

static void xnl_dump_response(const char *resp)
{
	printf("%s", resp);
}

static int xnl_proc_cmd(struct xcmd_info *xcmd)
{
	xcmd->log_msg_dump = xnl_dump_response;
	if (xnl_proc_fn[xcmd->op])
		return xnl_proc_fn[xcmd->op](xcmd);

	return -EOPNOTSUPP;
}

static int prepare_q_add(struct xcmd_info *xcmd, unsigned int queue_id, unsigned int queue_mode, unsigned int queue_dir) {
	int ret;
	char *p;

	memset(xcmd, 0, sizeof(struct xcmd_info));

	struct xcmd_q_parm *qparm = &xcmd->req.qparm;

	xcmd->op = XNL_CMD_Q_ADD;
	xcmd->vf = 0;
	xcmd->if_bdf = strtoul("1000", &p, 16);

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

static int prepare_q_start(struct xcmd_info *xcmd, int queue_id, int queue_dir) {
	int ret;
	char *p;

	memset(xcmd, 0, sizeof(struct xcmd_info));

	struct xcmd_q_parm *qparm = &xcmd->req.qparm;

	xcmd->op = XNL_CMD_Q_START;
	xcmd->vf = 0;
	xcmd->if_bdf = strtoul("1000", &p, 16);

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

int main() {
	int queue_id = 32;
	int ret;

	// std::string cmd = getQueueSetupCmd(queue_id);
	// ret = system(cmd.c_str());

	struct xcmd_info xcmd;

	ret = prepare_q_add(&xcmd, queue_id, XNL_F_QMODE_ST, XNL_F_QDIR_BOTH);

	ret = prepare_q_start(&xcmd, queue_id, XNL_F_QDIR_BOTH);

	return 0;
}