#include <dmautils.h>
#include <qdma_nl.h>

#include "vitisnetp4_common.h"
#include "vitisnetp4_target.h"
#include "p4_engine_defs.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

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

const char *XilVitisNetP4TableModeToString(XilVitisNetP4TableMode Value);

XilVitisNetP4ReturnType write_register(XilVitisNetP4EnvIf *EnvIfPtr, XilVitisNetP4AddressType Address, uint32_t WriteValue);
XilVitisNetP4ReturnType write_register_mmap(XilVitisNetP4EnvIf *EnvIfPtr, XilVitisNetP4AddressType Address, uint32_t WriteValue);

XilVitisNetP4ReturnType read_register(XilVitisNetP4EnvIf *EnvIfPtr, XilVitisNetP4AddressType Address, uint32_t *ReadValuePtr);
XilVitisNetP4ReturnType read_register_mmap(XilVitisNetP4EnvIf *EnvIfPtr, XilVitisNetP4AddressType Address, uint32_t *ReadValuePtr);

XilVitisNetP4ReturnType log_error(XilVitisNetP4EnvIf *EnvIfPtr, const char *MessagePtr);

XilVitisNetP4ReturnType log_info(XilVitisNetP4EnvIf *EnvIfPtr, const char *MessagePtr);

XilVitisNetP4ReturnType XilVitisNetP4EnvIfPrep(XilVitisNetP4EnvIf *EnvIfPtr);
XilVitisNetP4ReturnType XilVitisNetP4EnvIfPrepMmap(XilVitisNetP4EnvIf *EnvIfPtr);