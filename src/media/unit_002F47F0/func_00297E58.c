#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_002C10F0(s32);
void func_002C1148(s32);
void func_00297E58(s8 *arg0, s32 arg1) {
    s32 *h = (s32 *)(arg0 + 0x20);
    if (arg1 != 0) {
        func_002C10F0(arg1);
    }
    if (*h != 0) {
        func_002C1148(*h);
    }
    *h = arg1;
}
