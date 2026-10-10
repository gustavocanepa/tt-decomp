#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0037C700_arg0 {
    char pad0[0x3C];
    s32 unk3C;
    s32 unk40;
};

s32 func_0037C700(struct func_0037C700_arg0 *arg0, s32 arg1) {
    s32 temp_a0;
    s32 var_v0;
    s32 var_v1;

    var_v1 = -1;
    if (arg1 < arg0->unk3C) {
        temp_a0 = arg0->unk40;
        var_v0 = -1;
        if (temp_a0 != 0) {
            var_v1 = *(s32 *)((arg1 * 4) + temp_a0);
            goto block_3;
        }
    } else {
block_3:
        var_v0 = var_v1;
    }
    return var_v0;
}
