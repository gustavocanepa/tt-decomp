/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_002E5E40(s32);                             /* extern */
f32 func_002E5EA0(s32, f32);                        /* extern */
f32 func_002E5ED0(s32, f32);                        /* extern */
s32 func_00416BF8(s32, f32, f32, f32);          /* extern */

void func_00416CB0(s32 arg0, s32 arg1, f32 fparg0) {
    f32 temp_f21;
    f32 temp_f22;

    temp_f22 = func_002E5E40(arg1);
    temp_f21 = func_002E5EA0(arg1, fparg0);
    func_00416BF8(arg0, temp_f22, temp_f21, func_002E5ED0(arg1, fparg0));
}
