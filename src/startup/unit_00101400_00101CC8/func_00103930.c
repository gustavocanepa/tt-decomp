/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00101FA0(s32);                         /* extern */
s32 func_001036F8();                            /* extern */
s32 func_001098E0(s32, f32);                        /* extern */

void func_00103930(s32 arg0, s32 arg1, f32 fparg0) {
    func_001036F8();
    if (func_001098E0(arg0 + 0x44, fparg0) != 0) {
        func_00101FA0(arg1);
    }
}
