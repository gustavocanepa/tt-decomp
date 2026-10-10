#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0036D500(s32, s32);                /* extern */
s32 exception__structor_0(s32);                         /* extern */

s32 func_0036D490(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 temp_v0;

    temp_v0 = exception__structor_0(0x39E40);
    func_0036D500(temp_v0, 0);
    return temp_v0;
}
