#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002BC0B0(s32, s32 *);              /* extern */
s32 func_002BDA28(s32, s32);                    /* extern */
s32 func_002C2198(s32, s32, s32, s32);            /* extern */

s32 func_002C2258(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp[4];
    s32 temp_v0;

    temp_v0 = func_002BDA28(0x14, 4);
    func_002C2198(temp_v0, arg1, arg2, arg3);
    sp[0] = temp_v0;
    func_002BC0B0(arg0, sp);
}
