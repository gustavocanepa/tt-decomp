/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_00131BF0(s32, s32, s32, s32);          /* extern */
f32 func_001321D0();                                /* extern */

void func_00131D30(s32 arg0, s32 arg1, s32 arg2) {
    func_00131BF0(arg0, arg1, arg2, (s32) (func_001321D0() + 0x1.0000000000000p-1f));
}
