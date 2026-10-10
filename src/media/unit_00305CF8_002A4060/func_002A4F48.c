#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A4988(s32, s32, void *);            /* extern */
s32 func_002C19D8(void *, s32);             /* extern */
s32 func_002C1DD8(void *, s32, s32);            /* extern */

s32 func_002A4F48(s32 arg0, s32 arg1, s32 arg2) {
    s8 sp[0x10];
    func_002C1DD8(sp, arg2, arg1);
    func_002A4988(arg0, arg1, sp);
    func_002C19D8(sp, 2);
    return arg0;
}
