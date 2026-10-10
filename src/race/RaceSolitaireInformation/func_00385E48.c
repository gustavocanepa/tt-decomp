#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00385EB0(s32);                         /* extern */
s32 exception__structor_0(s32);                         /* extern */

s32 func_00385E48(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 temp_v0;

    temp_v0 = exception__structor_0(0xF280);
    func_00385EB0(temp_v0);
    return temp_v0;
}
