#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00259D68_arg0 {
    char pad0[0xDC];
    s32 unkDC;
};

s32 func_00259D68(struct func_00259D68_arg0 *arg0) {
    return arg0->unkDC;
}
