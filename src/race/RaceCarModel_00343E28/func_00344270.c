#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0041A6C8(s32);                         /* extern */
s32 func_0041F840(s32);                         /* extern */

void func_00344270(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_0041F840(arg1);
        func_0041A6C8(arg0 + 0x18);
    }
}
