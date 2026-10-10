/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004B7A28(s32, s32, s32, s32, s32, s32, s32, s32); /* extern */

void func_004B9EF0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    func_004B7A28(0xB, arg0, arg1, arg2, arg3, 0, arg4, arg5);
}
