/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004B7A28(s32, s32, s32, s32, s32, s32, s32, s32); /* extern */

void func_004B9D40(s32 arg0, s32 arg1, s32 arg2) {
    func_004B7A28(5, arg0, 0, 0, 0, 0, arg1, arg2);
}
