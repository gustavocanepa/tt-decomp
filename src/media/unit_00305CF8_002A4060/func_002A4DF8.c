#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A4988(s32, s32, void *);            /* extern */
s32 func_002AD2E8(void *, s32);             /* extern */
s32 func_002AD6C8(void *, s32, s32);            /* extern */

s32 func_002A4DF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s8 sp[0x10];
    func_002AD6C8(sp, arg2, arg3);
    func_002A4988(arg0, arg1, sp);
    func_002AD2E8(sp, 2);
    return arg0;
}
