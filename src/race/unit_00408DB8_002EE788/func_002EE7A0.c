#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002EE7A0_temp_a0 {
    char pad0[0x4A8];
    f32 unk4A8;
    f32 unk4AC;
};

s32 func_002EE7A0(s32 arg0) {
    s32 var_v0;
    struct func_002EE7A0_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0x104;
    var_v0 = 1;
    if (!(temp_a0->unk4A8 > 0x0.0p+0f)) {
        var_v0 = -1;
        if (!(temp_a0->unk4AC > 0x0.0p+0f)) {
            var_v0 = 0;
        }
    }
    return var_v0;
}
