#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004AE9F0(s32, s32);                /* extern */
s32 func_0050E1A8(s32);                         /* extern */
s32 func_00543920(s32, s32);                /* extern */

void func_00543740(s32 arg0, s32 arg1) {
    func_004AE9F0(arg0 + 0x110, 2);
    func_00543920(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
