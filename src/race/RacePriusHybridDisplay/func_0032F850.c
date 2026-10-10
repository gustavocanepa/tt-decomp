#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_0032F710(s32, s32);                    /* extern */
s32 func_0032F8E8(s32, s32, f32, f32, f32);     /* extern */

s32 func_0032F850(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2) {
    f32 temp_f20;
    f32 temp_f21;

    temp_f20 = fparg0 - func_0032F710(arg1, 0);
    temp_f21 = fparg1 - func_0032F710(arg1, 1);
    func_0032F8E8(arg0, arg1, temp_f20, temp_f21, fparg2 - func_0032F710(arg1, 2));
    return arg0;
}
