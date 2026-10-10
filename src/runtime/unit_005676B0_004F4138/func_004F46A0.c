/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F45D8(s32 *, s32, s32, s32, s32); /* extern */
s32 func_004F4348(s32);                         /* extern */

void func_004F46A0(s32 *arg0, s32 arg1, s32 arg2) {
    func_004F4348(*arg0);
    func_004F45D8(arg0, arg1, arg2, 0, 0);
}
