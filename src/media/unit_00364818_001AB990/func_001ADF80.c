#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001ADF50(void *, s32);                 /* extern */
s32 func_00473A08(s32, s32, void *);            /* extern */

void func_001ADF80(s32 arg0, s32 arg1, s32 arg2) {
    s8 sp[0x10];
    func_001ADF50(sp, arg2);
    func_00473A08(arg0, arg1, sp);
}
