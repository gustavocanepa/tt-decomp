#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

f32 func_002E6518(s8 *, s32, f32);
f32 func_0037B930(void *arg0, s32 arg1) {
    f32 temp_f20;
    s8 *temp_a0;
    s8 temp_s1;
    void *temp_s2;

    temp_a0 = M2C_FIELD(arg0, s8 **, 4);
    temp_s1 = M2C_FIELD((arg0 + arg1), s8 *, 0xC);
    temp_s2 = M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_a0, void **, 8), void **, 4), void **, 0x80);
    temp_f20 = func_002E6518(temp_a0, (s32) temp_s1, 0x0.0p+0f);
    return (temp_f20 - func_002E6518(M2C_FIELD(arg0, s8 **, 4), (s32) temp_s1, 0x1.0000000000000p+0f)) * M2C_FIELD(temp_s2, f32 *, 0xEA0) * 0x1.ca5dc00000000p+5f;
}
