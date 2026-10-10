#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_002FED98(void *);                          /* extern */
s32 func_003744B8(void *, f32);                 /* extern */

struct func_00345EE8_arg0 {
    char pad0[0x4];
    void *unk4;
    char pad8[0x3548];
    s32 unk3550;
    s32 unk3554;
};

s32 func_00345EE8(void *arg0, f32 fparg0) {
    f32 var_f20;

    if (func_002FED98(((struct func_00345EE8_arg0 *)arg0)->unk4) == 1) {
        var_f20 = fparg0 + M2C_FIELD(((struct func_00345EE8_arg0 *)arg0)->unk4, f32 *, 0x574);
    } else {
        var_f20 = 0x0.0p+0f;
    }
    if (((struct func_00345EE8_arg0 *)arg0)->unk3550 != 0) {
        func_003744B8(arg0 + 0x620, var_f20);
    }
    if (((struct func_00345EE8_arg0 *)arg0)->unk3554 != 0) {
        func_003744B8(arg0 + 0x1DB0, var_f20);
    }
}
