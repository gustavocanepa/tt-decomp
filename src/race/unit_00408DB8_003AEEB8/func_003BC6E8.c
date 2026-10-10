#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003AC3D8(void *);                      /* extern */
f32 func_003AC490(s32);                             /* extern */
f32 func_003AC498(s32);                             /* extern */
f32 func_003AC4A0(s32);                             /* extern */
f32 *func_003AC890(void *);                         /* extern */
f32 *func_003AC8A0(void *);                         /* extern */
f32 *func_003AC8B0(void *);                         /* extern */
f32 func_003BC618(f32, f32, f32);                   /* extern */

void func_003BC6E8(s32 arg0, f32 fparg0) {
    s8 sp[0x10];
    f32 *temp_s2;
    f32 *temp_s2_2;
    f32 *temp_s2_3;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    s32 temp_s0;
    s32 temp_s1;

    temp_s0 = arg0 + 0x450;
    temp_s1 = arg0 + 0x310;
    func_003AC3D8(sp);
    temp_s2 = func_003AC890(sp);
    temp_f20 = func_003AC490(temp_s1);
    *temp_s2 = func_003BC618(temp_f20, func_003AC490(temp_s0), fparg0);
    temp_s2_2 = func_003AC8A0(sp);
    temp_f20_2 = func_003AC498(temp_s1);
    *temp_s2_2 = func_003BC618(temp_f20_2, func_003AC498(temp_s0), fparg0);
    temp_s2_3 = func_003AC8B0(sp);
    temp_f20_3 = func_003AC4A0(temp_s1);
    *temp_s2_3 = func_003BC618(temp_f20_3, func_003AC4A0(temp_s0), fparg0);
}
