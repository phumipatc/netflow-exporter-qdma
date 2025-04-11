#include "p4_env.h"
#include "vitisnetp4_target.h"
#include "p4_engine_defs.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>

#define DISPLAY_ERROR(ErrorCode)  printf("Error Code is value %s", XilVitisNetP4ReturnTypeToString(ErrorCode))

int main() {
	XilVitisNetP4EnvIf EnvIf;
	XilVitisNetP4ReturnType Result;

	Result = XilVitisNetP4EnvIfPrep(&EnvIf);

	if (Result != XIL_VITIS_NET_P4_SUCCESS) {
		DISPLAY_ERROR(Result);
		return Result;
	}

	XilVitisNetP4AddressType Address;
	uint32_t ReadValue;
	uint32_t WriteValue;
	scanf("%d %d", &Address, &WriteValue);

	Result = EnvIf.WordRead32(&EnvIf, Address, &ReadValue);
	if (Result != XIL_VITIS_NET_P4_SUCCESS) {
		DISPLAY_ERROR(Result);
		return Result;
	}

	printf("Read value at address %d: %d\n", Address, ReadValue);

	Result = EnvIf.WordWrite32(&EnvIf, Address, WriteValue);
	if (Result != XIL_VITIS_NET_P4_SUCCESS) {
		DISPLAY_ERROR(Result);
		return Result;
	}
	printf("Wrote value %d to address %d\n", WriteValue, Address);

	Result = EnvIf.WordRead32(&EnvIf, Address, &ReadValue);
	if (Result != XIL_VITIS_NET_P4_SUCCESS) {
		DISPLAY_ERROR(Result);
		return Result;
	}
	printf("Read value at address %d: %d\n", Address, ReadValue);

	return 0;
}