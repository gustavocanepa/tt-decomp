#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0042B860(void *, s32, s32);            /* extern */

struct func_0042B8F0_arg0 {
    char pad0[0x8];
    void *unk8;
    u32 unkC;
};

void func_0042B8F0(void *arg0, s32 (*arg1)(void *), s32 arg2) {
    s32 temp_s4;
    u32 var_s3;
    void *temp_a0;
    void *var_a0;
    void *var_s0;

    var_s3 = 0;
    temp_s4 = arg0 - ((struct func_0042B8F0_arg0 *)arg0)->unk8;
    ((struct func_0042B8F0_arg0 *)arg0)->unk8 = arg0;
    if (((struct func_0042B8F0_arg0 *)arg0)->unkC != 0) {
        var_s0 = arg0 + 0x14;
        var_a0 = var_s0;
        do {
            func_0042B860(var_a0, temp_s4, arg2);
            temp_a0 = var_s0;
            var_s0 += 8;
            if (arg1 != NULL) {
                arg1(temp_a0);
            }
            var_s3 += 1;
            var_a0 = var_s0;
        } while (var_s3 < (u32) ((struct func_0042B8F0_arg0 *)arg0)->unkC);
    }
}
