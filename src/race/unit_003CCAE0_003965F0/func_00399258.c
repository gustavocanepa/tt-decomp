#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003015D8(s32);                             /* extern */
s32 func_00396468(s32);                             /* extern */
s32 func_00396470(s32);                             /* extern */
s32 func_00396480(s32);                             /* extern */
s32 func_00399380(s32);                             /* extern */
s32 func_003993C0(s32, s32, s32);                   /* extern */
s32 func_00399410(s32, s32);                        /* extern */
s32 func_0039C748(s32, s32, s32);               /* extern */
s32 func_0039C7E8(s32, s32);                        /* extern */

s32 func_00399258(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_s0;

    if (func_00396468(arg1) != 0) {
        return func_00399380(arg3);
    }
    if (func_00396470(arg1) != 0) {
        temp_s0 = func_003015D8(arg2);
        return func_003993C0(arg3, temp_s0, func_0039C7E8(arg0, arg4));
    }
    if (func_00396480(arg1) != 0) {
        return func_00399410(arg3, func_0039C748(arg0, arg4, -1));
    }
    return 0x8FFFFFFF;
}
