#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00287D48_arg0 {
    char pad0[0x3E4];
    s32 unk3E4;
    s32 unk3E8;
};

f32 func_00287D48(struct func_00287D48_arg0 *arg0) {
    f32 var_f0;

    var_f0 = (f32) arg0->unk3E8 / (f32) arg0->unk3E4;
    if (var_f0 > 0x1.0000000000000p+0f) {
        var_f0 = 0x1.0000000000000p+0f;
    }
    return var_f0;
}
