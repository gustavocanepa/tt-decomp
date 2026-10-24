#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A4EC8(s32, s32, s32 *, s32, s32); /* extern */
s32 func_002B1070(s32);                             /* extern */

s32 func_002A52B8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 sp[4];
    sp[0] = func_002B1070(arg2);
    func_002A4EC8(arg0, arg1, sp, arg3, arg4);
    return arg0;
}
