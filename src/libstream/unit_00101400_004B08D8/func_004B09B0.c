#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00571EE8(s32, s32);                        /* extern */

struct func_004B09B0_arg0 {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
};

void func_004B09B0(struct func_004B09B0_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk8 = arg1;
    arg0->unkC = func_00571EE8(arg1, arg2);
}
