#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_0043E0B0(s32);                             /* extern */
s32 func_00447D00(void *, s32);                 /* extern */
f32 func_004EE530(f32);                             /* extern */

struct func_00442B10_arg1 {
    char pad0[0x8];
    s32 unk8;
};

f32 func_00442B10(s32 arg0, struct func_00442B10_arg1 *arg1) {
    f32 var_f20;

    if (arg0 != 0) {
        var_f20 = func_0043E0B0(arg1->unk8 - 8);
    } else {
        var_f20 = 0.0f;
    }
    func_00447D00(arg1, arg0);
    return 1.5707963f - func_004EE530(var_f20);
}
