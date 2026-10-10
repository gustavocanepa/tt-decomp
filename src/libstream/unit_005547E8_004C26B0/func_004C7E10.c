/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004C40B8();                            /* extern */
s32 func_004C4EF8();                            /* extern */
s32 func_004C78B8(s32, s32);            /* extern */

extern char D_0059D4A8[];
void func_004C7E10(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_004C40B8();
    func_004C4EF8();
    func_004C78B8((s32)D_0059D4A8, 1);
}
