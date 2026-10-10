#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 hArrayCompare__structor_0(void *, s32, s32);        /* extern */
s32 func_00128B38(void *);                      /* extern */
s32 func_002931B0(void *, s32);                 /* extern */
s32 func_002931C8(s32, s32);                /* extern */

extern char D_00128760[];
void func_00128FA8(s32 arg0, s32 arg1) {
    s8 sp[0x10];
    func_002931B0(sp, arg0);
    func_00128B38(sp);
    func_002931B0(sp, arg0);
    hArrayCompare__structor_0(sp, (s32)D_00128760, arg1);
    func_002931C8(arg0, 2);
}
