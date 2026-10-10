/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_002F0570(s32);                             /* extern */
s32 gtbPenaltiedNumLaps(void *);                          /* extern */

struct func_0030DC40_arg1 {
    char pad0[0x4C4];
    f32 unk4C4;
};
struct func_0030DC40_arg2 {
    char pad0[0x4C4];
    f32 unk4C4;
};

void func_0030DC40(s32 arg0, struct func_0030DC40_arg1 *arg1, struct func_0030DC40_arg2 *arg2, s32 *arg3, f32 *arg4) {
    f32 var_f20;
    s32 temp_s0;
    s32 var_s0;

    temp_s0 = gtbPenaltiedNumLaps(arg1);
    var_s0 = temp_s0 - gtbPenaltiedNumLaps(arg2);
    var_f20 = arg1->unk4C4 - arg2->unk4C4;
    if ((var_s0 > 0) && (var_f20 < 0x0.0p+0f)) {
        var_s0 -= 1;
        var_f20 += func_002F0570(arg0);
    } else if ((var_s0 < 0) && (var_f20 > 0x0.0p+0f)) {
        var_s0 += 1;
        var_f20 -= func_002F0570(arg0);
    }
    *arg3 = var_s0;
    *arg4 = var_f20;
}
