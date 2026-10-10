#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00340D50_arg0 {
    char pad0[0x4];
    s32 unk4;
};

f32 func_00340D50(struct func_00340D50_arg0 *arg0) {
    f32 var_f0;

    var_f0 = -0x1.a0c49a0000000p-1f;
    if (arg0->unk4 != 0) {
        var_f0 = -0x1.89374a0000000p-6f;
    }
    return var_f0;
}
