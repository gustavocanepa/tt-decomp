#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0033C9B0_arg0 {
    char pad0[0xE00];
    f32 unkE00;
    char padE04[0x10];
    s32 unkE14;
};

f32 func_0033C9B0(struct func_0033C9B0_arg0 *arg0) {
    f32 var_f0;

    var_f0 = 0x1.9999980000000p-5f;
    if (arg0->unkE14 <= 0) {
        var_f0 = arg0->unkE00;
    }
    return var_f0;
}
