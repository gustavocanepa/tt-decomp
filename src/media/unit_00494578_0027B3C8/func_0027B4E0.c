typedef int s32;
typedef float f32;
f32 func_00205D10(void *);
f32 func_00205D70(void *);
f32 func_00278870(void *);
s32 func_004AC5A0(void *);
f32 func_0027B4E0(char *arg0) {
    f32 temp_f20;
    f32 var_f0;
    f32 var_f21;
    s32 temp_v0;

    temp_v0 = *(s32 *)(arg0 + 0xD4);
    if (temp_v0 == 0) var_f21 = *(f32 *)(arg0 + 0x108); else var_f21 = *(f32 *)(arg0 + 0x10C);
    if (temp_v0 == 0) {
        var_f0 = func_00205D10(arg0);
    } else {
        var_f0 = func_00205D70(arg0);
    }
    temp_f20 = var_f21 + func_00278870(arg0);
    return var_f0 / ((temp_f20 * (f32) (func_004AC5A0(arg0 + 0xE0) - 1)) + (var_f21 * *(f32 *)(arg0 + 0xF8)));
}
