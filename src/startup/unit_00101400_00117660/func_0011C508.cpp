#include "types.h"
struct Rec { char pad[0x1D0]; s32 f1D0; };
struct Self { char pad[0x2E8]; f32 f2E8; char pad1[0x308 - 0x2EC]; f32 f308; };
extern "C" Rec *func_0011C628(s32);
extern "C" s32 func_0011C768(Self *, s32);
extern "C" s32 func_0011C780(Self *, s32);
extern "C" s32 func_0011C7B0(Self *, s32);

extern "C" f32 func_0011C508(Self *arg0) {
    f32 var_f4;
    s32 var_s1;
    s32 var_s2;
    s32 var_v1;

    var_s2 = 0;
    if (func_0011C628(0)->f1D0 == 0) {
        var_s2 = func_0011C7B0(arg0, 0) != 0;
    }
    var_s1 = 0;
    if (func_0011C628(1)->f1D0 == 0) {
        var_s1 = func_0011C7B0(arg0, 1) != 0;
    }
    s32 temp_s2 = var_s2 + var_s1;
    s32 temp_s1 = func_0011C768(arg0, 0);
    s32 temp_v0 = func_0011C780(arg0, 0);
    var_v1 = 0;
    if ((temp_s2 != 0) && ((temp_s1 != 0) || (temp_v0 != 0))) {
        var_v1 = 1;
    }
    var_f4 = 0.0f;
    if (var_v1 != 0) {
        var_f4 = 4.0f;
        var_f4 = (f32)temp_s2 * 50.0f + var_f4;
    }
    var_f4 += 10.0f;
    f32 q = arg0->f308 / arg0->f2E8;
    return var_f4 + (q + 75.0f);
}
