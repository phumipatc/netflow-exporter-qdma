#include "p4_env.h"

#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

#define OFFSET 0x400000

static const char * XilVitisNetP4TableModeStrings[XIL_VITIS_NET_P4_NUM_RETURN_CODES] =
{
	"XIL_VITIS_NET_P4_TABLE_MODE_BCAM",
    "XIL_VITIS_NET_P4_TABLE_MODE_STCAM",
    "XIL_VITIS_NET_P4_TABLE_MODE_TCAM",
    "XIL_VITIS_NET_P4_TABLE_MODE_DCAM",
    "XIL_VITIS_NET_P4_TABLE_MODE_TINY_BCAM",
    "XIL_VITIS_NET_P4_TABLE_MODE_TINY_TCAM",
};

const char *XilVitisNetP4TableModeToString(XilVitisNetP4TableMode Value)
{
    if ((uint32_t)Value < XIL_VITIS_NET_P4_NUM_TABLE_MODES)
    {
        return XilVitisNetP4TableModeStrings[Value];
    }

    return "XIL_VITIS_NET_P4_UNKNOWN_RETURN_CODE";
}

uint32_t convertEndian(uint32_t value)
{
	return ((value & 0x000000FF) << 24) | ((value & 0x0000FF00) << 8) | ((value & 0x00FF0000) >> 8) | ((value & 0xFF000000) >> 24);
}

// read register
XilVitisNetP4ReturnType read_register(XilVitisNetP4EnvIf *EnvIfPtr, XilVitisNetP4AddressType Address, uint32_t *ReadValuePtr)
{
	struct xcmd_info xcmd;
	struct xcmd_reg *regcmd = &xcmd.req.reg;
	int rv;

	memset(&xcmd, 0, sizeof(struct xcmd_info));
	memset(regcmd, 0, sizeof(struct xcmd_reg));

	xcmd.op = XNL_CMD_REG_RD;
	xcmd.vf = 0;
	xcmd.if_bdf = strtoul("1000", NULL, 16);
	
	regcmd->bar = 2;
	regcmd->sflags |= XCMD_REG_F_BAR_SET;

	regcmd->reg = (unsigned int )Address + OFFSET;
	regcmd->sflags |= XCMD_REG_F_REG_SET;

	// printf("Reading register %x\n", regcmd->reg);

	rv = xnl_proc_cmd(&xcmd);
	if (rv < 0) {
		printf("Error in processing read register command with ret = %d\n", rv);
		return XIL_VITIS_NET_P4_REGISTER_ERR_INVALID_INDEX;
	}

	// printf("Read register %x, got value %08x\n", regcmd->reg, regcmd->val);

	*ReadValuePtr = regcmd->val;

	return XIL_VITIS_NET_P4_SUCCESS;
}

XilVitisNetP4ReturnType read_register_mmap(XilVitisNetP4EnvIf *EnvIfPtr, XilVitisNetP4AddressType Address, uint32_t *ReadValuePtr)
{
	int fd;
	void *map_base, *virt_addr;
	uint32_t read_result;
	unsigned int page_size = sysconf(_SC_PAGESIZE);
	unsigned int map_size = page_size;
	unsigned int offset = Address & (page_size-1);
	unsigned int access_size = 4;

	fd = open("/dev/mem", O_RDWR | O_SYNC);
	if(fd == -1) {
		printf("Failed to open /dev/mem\n");
		return XIL_VITIS_NET_P4_REGISTER_ERR_INVALID_INDEX;
	}

	offset = (unsigned int)(Address & (page_size - 1));
    if (offset + access_size > page_size)
    {
        // Access straddles page boundary:  add another page:
        map_size += page_size;
    }

	map_base = mmap(0, map_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, Address & ~(page_size-1));
	if(map_base == (void *) -1) {
		printf("Failed to map memory\n");
		return XIL_VITIS_NET_P4_GENERAL_ERR_INTERNAL_ASSERTION;
	}

	virt_addr = map_base + offset;
	read_result = *((uint32_t *) virt_addr);
	*ReadValuePtr = read_result;

	if(munmap(map_base, map_size) == -1) {
		printf("Failed to unmap memory\n");
		return XIL_VITIS_NET_P4_GENERAL_ERR_INTERNAL_ASSERTION;
	}

	close(fd);

	return XIL_VITIS_NET_P4_SUCCESS;
}

XilVitisNetP4ReturnType write_register(XilVitisNetP4EnvIf *EnvIfPtr, XilVitisNetP4AddressType Address, uint32_t WriteValue)
{
	struct xcmd_info xcmd;
	struct xcmd_reg *regcmd = &xcmd.req.reg;

	memset(&xcmd, 0, sizeof(struct xcmd_info));
	memset(regcmd, 0, sizeof(struct xcmd_reg));

	xcmd.op = XNL_CMD_REG_WRT;
	xcmd.vf = 0;
	xcmd.if_bdf = strtoul("1000", NULL, 16);

	regcmd->bar = 2;
	regcmd->sflags |= XCMD_REG_F_BAR_SET;

	regcmd->reg = (unsigned int )Address + OFFSET;
	regcmd->sflags |= XCMD_REG_F_REG_SET;

	regcmd->val = WriteValue;
	regcmd->sflags |= XCMD_REG_F_VAL_SET;

	// printf("Writing register %x with value %x\n", regcmd->reg, regcmd->val);

	int rv = xnl_proc_cmd(&xcmd);
	if (rv < 0) {
		printf("Error in processing write register command with ret = %d\n", rv);
		return XIL_VITIS_NET_P4_REGISTER_ERR_INVALID_INDEX;
	}

	// printf("Writed register %x with value %08x, got value %08x\n", regcmd->reg, WriteValue, regcmd->val);

	return XIL_VITIS_NET_P4_SUCCESS;
}

XilVitisNetP4ReturnType write_register_mmap(XilVitisNetP4EnvIf *EnvIfPtr, XilVitisNetP4AddressType Address, uint32_t WriteValue)
{
	int fd;
	void *map_base, *virt_addr;
	unsigned int page_size = sysconf(_SC_PAGESIZE);
	unsigned int map_size = page_size;
	unsigned int offset = Address & (page_size-1);
	unsigned int access_size = 4;

	fd = open("/dev/mem", O_RDWR | O_SYNC);
	if(fd == -1) {
		printf("Failed to open /dev/mem\n");
		return XIL_VITIS_NET_P4_REGISTER_ERR_INVALID_INDEX;
	}

	offset = (unsigned int)(Address & (page_size - 1));
	if (offset + access_size > page_size)
	{
		// Access straddles page boundary:  add another page:
		map_size += page_size;
	}

	map_base = mmap(0, map_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, Address & ~(page_size-1));
	if(map_base == (void *) -1) {
		printf("Failed to map memory\n");
		return XIL_VITIS_NET_P4_GENERAL_ERR_INTERNAL_ASSERTION;
	}

	virt_addr = map_base + offset;
	*((uint32_t *) virt_addr) = WriteValue;

	if(munmap(map_base, map_size) == -1) {
		printf("Failed to unmap memory\n");
		return XIL_VITIS_NET_P4_GENERAL_ERR_INTERNAL_ASSERTION;
	}

	close(fd);

	return XIL_VITIS_NET_P4_SUCCESS;
}

XilVitisNetP4ReturnType log_error(XilVitisNetP4EnvIf *EnvIfPtr, const char *MessagePtr)
{
	if (EnvIfPtr == NULL)
	{
		return XIL_VITIS_NET_P4_GENERAL_ERR_NULL_PARAM;
	}

	if (MessagePtr == NULL)
	{
		return XIL_VITIS_NET_P4_GENERAL_ERR_NULL_PARAM;
	}

	printf("Error: %s\n", MessagePtr);

	return XIL_VITIS_NET_P4_SUCCESS;
}

XilVitisNetP4ReturnType log_info(XilVitisNetP4EnvIf *EnvIfPtr, const char *MessagePtr)
{
	if (EnvIfPtr == NULL)
	{
		return XIL_VITIS_NET_P4_GENERAL_ERR_NULL_PARAM;
	}

	if (MessagePtr == NULL)
	{
		return XIL_VITIS_NET_P4_GENERAL_ERR_NULL_PARAM;
	}

	printf("Info: %s\n", MessagePtr);

	return XIL_VITIS_NET_P4_SUCCESS;
}

XilVitisNetP4ReturnType XilVitisNetP4EnvIfPrep(XilVitisNetP4EnvIf *EnvIfPtr)
{
	if (EnvIfPtr == NULL)
	{
		return XIL_VITIS_NET_P4_GENERAL_ERR_NULL_PARAM;
	}

	EnvIfPtr->UserCtx = NULL;

	EnvIfPtr->WordWrite32 = write_register;
	EnvIfPtr->WordRead32 = read_register;
	EnvIfPtr->LogError = log_error;
	EnvIfPtr->LogInfo = log_info;

	return XIL_VITIS_NET_P4_SUCCESS;
}

XilVitisNetP4ReturnType XilVitisNetP4EnvIfPrepMmap(XilVitisNetP4EnvIf *EnvIfPtr)
{
	if (EnvIfPtr == NULL)
	{
		return XIL_VITIS_NET_P4_GENERAL_ERR_NULL_PARAM;
	}

	EnvIfPtr->UserCtx = NULL;

	EnvIfPtr->WordWrite32 = write_register_mmap;
	EnvIfPtr->WordRead32 = read_register_mmap;
	EnvIfPtr->LogError = log_error;
	EnvIfPtr->LogInfo = log_info;

	return XIL_VITIS_NET_P4_SUCCESS;
}