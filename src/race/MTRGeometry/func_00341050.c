#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00341050_arg0 {
    char pad0[0x4];
    s32 unk4;
};

f32 func_00341050(struct func_00341050_arg0 *arg0) {
    f32 var_f0;

    var_f0 = -0x1.bc63ec0000000p-1f;
    if (arg0->unk4 != 0) {
        var_f0 = -0x1.78d4fc0000000p-6f;
    }
    return var_f0;
}
