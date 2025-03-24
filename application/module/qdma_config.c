#include "qdma_config.h"

#include <errno.h>

void xnl_dump_response(const char *resp)
{
	printf("%s", resp);
}

int xnl_proc_cmd(struct xcmd_info *xcmd)
{
	xcmd->log_msg_dump = xnl_dump_response;
	if (xnl_proc_fn[xcmd->op])
		return xnl_proc_fn[xcmd->op](xcmd);

	return -EOPNOTSUPP;
}