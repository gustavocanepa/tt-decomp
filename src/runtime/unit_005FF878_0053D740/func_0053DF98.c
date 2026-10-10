#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0053DF98_arg0 {
    char pad0[0xDC];
    s32 unkDC;
};

void func_0053DF98(struct func_0053DF98_arg0 *arg0, s32 arg1) {
    arg0->unkDC = arg1;
}
