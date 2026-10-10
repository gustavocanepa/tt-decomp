#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00341178_arg0 {
    char pad0[0x4];
    s32 unk4;
};

f32 func_00341178(struct func_00341178_arg0 *arg0) {
    f32 var_f0;

    var_f0 = 0x1.80956c0000000p-3f;
    if (arg0->unk4 != 0) {
        var_f0 = -0x1.1e98560000000p-2f;
    }
    return var_f0;
}
