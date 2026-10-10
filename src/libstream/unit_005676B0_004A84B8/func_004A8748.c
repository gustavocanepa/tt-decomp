#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A87A0(s32, s32, s32, s32, s32, s32); /* extern */
s32 func_004A8DF0(s32);                             /* extern */

void func_004A8748(s32 arg0, s32 arg1, s32 arg2) {
    func_004A87A0(arg0, 0, 0, func_004A8DF0(arg1), arg1, arg2);
}
