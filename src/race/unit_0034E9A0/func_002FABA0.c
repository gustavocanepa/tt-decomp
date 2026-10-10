#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_002FAB00();                                /* extern */

struct func_002FABA0_arg0 {
    u8 unk0;
    char pad1[0x12];
    u8 unk13;
};

f32 func_002FABA0(struct func_002FABA0_arg0 *arg0) {
    f32 var_f0;

    if (arg0->unk0 == 7) {
        return func_002FAB00();
    }
    var_f0 = 0x1.b314040000000p+3f;
    if (arg0->unk13 != 4) {
        var_f0 = 0x0.0p+0f;
    }
    return var_f0;
}
