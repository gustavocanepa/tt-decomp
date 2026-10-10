#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00340CE0_arg0 {
    char pad0[0x4];
    s32 unk4;
};

f32 func_00340CE0(struct func_00340CE0_arg0 *arg0) {
    f32 var_f0;

    var_f0 = -0x1.41cac00000000p+0f;
    if (arg0->unk4 != 0) {
        var_f0 = -0x1.0ac0820000000p-1f;
    }
    return var_f0;
}
