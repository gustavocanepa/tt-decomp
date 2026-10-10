#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002F8A98_temp_a0 {
    char pad0[0x4EC];
    f32 unk4EC;
    f32 unk4F0;
};

s32 func_002F8A98(s32 arg0) {
    s32 var_v0;
    struct func_002F8A98_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0x104;
    var_v0 = 0;
    if ((temp_a0->unk4EC > 0x0.0p+0f) && (temp_a0->unk4F0 <= 0x0.0p+0f)) {
        var_v0 = 1;
    }
    return var_v0;
}
