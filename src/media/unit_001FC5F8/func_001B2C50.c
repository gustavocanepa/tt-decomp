#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001B2C50_arg0 {
    char pad0[0x88];
    s32 unk88;
    char pad8C[0x7C];
    s32 unk108;
};

s32 func_001B2C50(struct func_001B2C50_arg0 *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if ((arg0->unk88 != 0) || (arg0->unk108 != 0)) {
        var_v1 = 1;
    }
    return var_v1;
}
