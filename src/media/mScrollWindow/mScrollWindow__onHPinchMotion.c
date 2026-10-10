#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00205C80(s32, f32);                    /* extern */
s32 func_002761A0(void *);                          /* extern */

struct func_00276EA8_temp_s1 {
    char pad0[0x14];
    f32 unk14;
};

struct func_00276EA8_arg0 {
    char pad0[0xF0];
    s32 unkF0;
};

s32 mScrollWindow__onHPinchMotion(void *arg0) {
    s32 temp_s2;
    s32 temp_v0;
    struct func_00276EA8_temp_s1 *temp_s1;

    temp_s1 = arg0 + 0xF4;
    temp_s2 = func_002761A0(temp_s1);
    temp_v0 = ((struct func_00276EA8_arg0 *)arg0)->unkF0;
    if (temp_v0 != 0) {
        func_00205C80(temp_v0, -temp_s1->unk14);
    }
    return temp_s2;
}
