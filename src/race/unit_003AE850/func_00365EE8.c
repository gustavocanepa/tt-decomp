#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00365FB8();                            /* extern */
s32 func_00366108();                            /* extern */
s32 func_0050E1A8(s32);                         /* extern */

extern char D_0058441C[];
void func_00365EE8(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = *(s32 *)(s32)D_0058441C - 1;
    *(s32 *)(s32)D_0058441C = temp_v0;
    if (temp_v0 == 0) {
        func_00365FB8();
        func_00366108();
    }
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
