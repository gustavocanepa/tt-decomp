#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

f32 func_002E6418(s8 *, s32, f32);
f32 func_002E64C8(s8 *, s32, f32);
f32 func_002E6518(s8 *, s32, f32);
void *func_0037B760(void *arg0, void *arg1, s32 arg2, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f20;
    f32 var_f22;
    s8 temp_s1;

    temp_s1 = M2C_FIELD((arg1 + arg2), s8 *, 0xC);
    if (M2C_FIELD(arg1, s32 *, 8) != 0) {
        var_f22 = -(func_002E6518(M2C_FIELD(arg1, s8 **, 4), (s32) temp_s1, fparg0) * 0x1.ca5dc00000000p+5f);
    } else {
        var_f22 = 0x0.0p+0f;
    }
    temp_f20 = func_002E6418(M2C_FIELD(arg1, s8 **, 4), (s32) temp_s1, fparg0) * 0x1.ca5dc00000000p+5f;
    temp_f0 = func_002E64C8(M2C_FIELD(arg1, s8 **, 4), (s32) temp_s1, fparg0) * 0x1.ca5dc00000000p+5f;
    M2C_FIELD(arg0, f32 *, 4) = temp_f20;
    M2C_FIELD(arg0, f32 *, 0) = var_f22;
    M2C_FIELD(arg0, f32 *, 8) = temp_f0;
    return arg0;
}
