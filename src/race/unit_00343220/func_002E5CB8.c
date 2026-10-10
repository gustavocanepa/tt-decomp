#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002E68E0();                                /* extern */

struct func_002E5CB8_arg0 {
    char pad0[0x5AC];
    f32 unk5AC;
    char pad5B0[0x94];
    u8 unk644;
};

f32 func_002E5CB8(struct func_002E5CB8_arg0 *arg0) {
    f32 var_f0;

    if ((func_002E68E0() == 0) || (var_f0 = 0x0.0p+0f, (arg0->unk644 != 0))) {
        var_f0 = arg0->unk5AC;
    }
    return var_f0;
}
