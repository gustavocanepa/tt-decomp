#include "types.h"

struct Node_00451078 {
    char pad0[0x7C];
    s32 unk7C;
};

extern "C" s32 func_0041ABA8(s32 *arg0, s32 arg1) {
    char *temp_a0;
    char *addr;
    s32 off;
    s32 alt;
    Node_00451078 *var_v0;
    s32 var_v1;

    temp_a0 = *(char **)arg0;
    if (temp_a0 != 0) {
        alt = 0x24;
        off = 0x20;
        if (arg1 == 0) {
            off = alt;
        }
        addr = temp_a0 + off;
        var_v0 = *(Node_00451078 **)(addr + 0xC);
    } else {
        var_v0 = 0;
    }
    var_v1 = 0;
    if (var_v0 != 0) {
        var_v1 = var_v0->unk7C;
    }
    return var_v1;
}
