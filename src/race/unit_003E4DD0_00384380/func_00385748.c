#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003858D8(s32, s32, s32, s32);      /* extern */
s32 func_004F6574(s32, s32, s32);           /* extern */

void func_00385748(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_004F6574(arg1, arg3, 0xC);
    func_004F6574(arg2, arg4, 0xC);
    func_003858D8(arg0, arg1, arg2, 0);
}
