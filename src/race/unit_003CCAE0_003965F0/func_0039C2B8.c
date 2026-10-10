/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0039B7F8(s32, s32, s32, s32);          /* extern */
s32 func_0039B940();                            /* extern */

void func_0039C2B8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_0039B940();
    func_0039B7F8(arg0, arg2, arg3, arg1);
}
