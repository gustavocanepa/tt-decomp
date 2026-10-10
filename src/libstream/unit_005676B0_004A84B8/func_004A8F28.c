#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A8DF0(s32);                             /* extern */
s32 func_004A8F88(s32, s32, s32, s32, s32);     /* extern */

void func_004A8F28(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_004A8F88(arg0, arg1, arg2, func_004A8DF0(arg3), arg3);
}
