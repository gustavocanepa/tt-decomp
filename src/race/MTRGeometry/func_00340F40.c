#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00340F40_arg0 {
    char pad0[0x4];
    s32 unk4;
};

f32 func_00340F40(struct func_00340F40_arg0 *arg0) {
    f32 var_f0;

    var_f0 = -0x1.f1a9fa0000000p-3f;
    if (arg0->unk4 != 0) {
        var_f0 = -0x1.78d4fc0000000p-2f;
    }
    return var_f0;
}
