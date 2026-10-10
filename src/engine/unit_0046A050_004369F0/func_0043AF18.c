/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00439E80(s32, s32, s32);       /* extern */
s32 func_0043A080(s32, s32, s32, s32, s32); /* extern */
s32 func_0046F0F8(s32);                     /* extern */
s32 func_00472268(s32, s32);            /* extern */

void func_0043AF18(s32 arg0, s32 arg1) {
    func_00439E80(arg1, 0, 0);
    func_0046F0F8(6);
    func_00472268(2, 1);
    func_00472268(3, 1);
    func_0043A080(arg1, 1, 1, 1, 1);
}
