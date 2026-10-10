#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00287D08_arg0 {
    char pad0[0x3E4];
    s32 unk3E4;
    s32 unk3E8;
    char pad3EC[0x8];
    f32 unk3F4;
};

f32 func_00287D08(struct func_00287D08_arg0 *arg0) {
    f32 temp_f2;
    f32 var_f0;

    temp_f2 = (f32) arg0->unk3E4;
    var_f0 = ((temp_f2 - arg0->unk3F4) - (f32) arg0->unk3E8) / temp_f2;
    if (var_f0 < 0x0.0p+0f) {
        var_f0 = 0x0.0p+0f;
    }
    return var_f0;
}
