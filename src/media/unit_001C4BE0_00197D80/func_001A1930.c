#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001A19E8(void *, s32, s32);            /* extern */
s32 func_001A1B30(void *, s32);                 /* extern */

void func_001A1930(s32 arg0, s32 arg1, s32 arg2) {
    s8 sp[0x10];
    func_001A1B30(sp, arg2);
    func_001A19E8(sp, arg0, arg1);
}
