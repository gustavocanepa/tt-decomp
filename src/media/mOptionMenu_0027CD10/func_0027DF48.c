/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001E4EA0(s32);                             /* extern */
s32 func_0027DA28(s32, s32);                    /* extern */
s32 func_0027E1C8(s32, s32);                    /* extern */
s32 func_004AC580(s32, s32);                    /* extern */

void func_0027DF48(s32 arg0, s32 arg1, s32 arg2) {
    func_004AC580(arg0 + 0xE0, arg2);
    func_0027E1C8(arg0, func_001E4EA0(arg1));
    func_0027DA28(arg0, arg1);
}
