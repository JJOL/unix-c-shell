#include <stdio.h>
#define OUT_ERROR(code, msg) fprintf(stderr, "%s: %s\n", code, msg);
#define USER_ERROR(msg) OUT_ERROR("InvalidInput", msg)
#define KERNEL_ERROR(msg) OUT_ERROR("OSKernelError", msg)