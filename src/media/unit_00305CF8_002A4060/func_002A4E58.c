#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A4988(s32, s32, void *);            /* extern */
s32 func_002C2690(void *, s32);             /* extern */
s32 func_002C2990(void *, s32, s32);            /* extern */

s32 func_002A4E58(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s8 sp[0x10];
    func_002C2990(sp, arg2, arg3);
    func_002A4988(arg0, arg1, sp);
    func_002C2690(sp, 2);
    return arg0;
}
