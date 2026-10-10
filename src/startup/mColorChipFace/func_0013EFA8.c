#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

char * func_0050F0F0(void *);
struct func_0013EFA8_temp_a1 {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
};

s8 **func_0013EFA8(s8 **arg0, s8 *arg1, s32 arg2) {
    s8 *temp_v0;
    s8 *var_a2;
    s8 *temp_a1;
    s8 *e = arg1 + arg2 * 4;
    temp_v0 = *(s8 **)(e + 0xB4);
    temp_a1 = temp_v0 - 0x10;
    var_a2 = temp_v0;
    if (((struct func_0013EFA8_temp_a1 *)temp_a1)->unkC != 0) {
        var_a2 = func_0050F0F0(temp_a1);
    } else {
        ((struct func_0013EFA8_temp_a1 *)temp_a1)->unk8 = (s32) (((struct func_0013EFA8_temp_a1 *)temp_a1)->unk8 + 1);
    }
    *arg0 = var_a2;
    return arg0;
}
