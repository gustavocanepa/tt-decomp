/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003FFA08();                                /* extern */
s32 func_003FFA40(s32, s32, s32);               /* extern */

void func_003FFB00(s32 arg0, s32 arg1, s32 arg2) {
    if (func_003FFA08() != arg1) {
        func_003FFA40(arg0, arg1, arg2);
    }
}
