#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003375B0_arg0 {
    char pad0[0x10E8];
    f32 unk10E8;
};

s32 func_003375B0(struct func_003375B0_arg0 *arg0) {
    s32 var_v0;

    var_v0 = 1;
    if (!(arg0->unk10E8 > 0x1.0000000000000p-3f)) {
        var_v0 = 0;
    }
    return var_v0;
}
