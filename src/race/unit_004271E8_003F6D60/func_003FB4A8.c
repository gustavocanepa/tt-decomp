/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003FB350(s32, s32, s32, s32);          /* extern */
s32 func_0040FB40(s32);                             /* extern */

void func_003FB4A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_003FB350(arg0, func_0040FB40(arg1), arg2, arg3);
}
