#ifndef __QDMA_CONFIG_H__
#define __QDMA_CONFIG_H__

#include "dmautils.h"
#include "qdma_nl.h"

#include <stdio.h>

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

void xnl_dump_response(const char *resp);

int xnl_proc_cmd(struct xcmd_info *xcmd);

#endif /* __QDMA_CONFIG_H__ */