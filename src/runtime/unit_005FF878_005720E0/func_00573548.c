/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F45D8(s32 *, s32, s32, s32, s32); /* extern */
s32 func_004F4348(s32);                         /* extern */
s32 func_004F7B74(void *, s32);                 /* extern */

void func_00573548(s32 *arg0, s32 arg1) {
    func_004F4348(*arg0);
    func_004F7B74(arg0 + 0x10, arg1);
    func_004F45D8(arg0, 8, 0, 0, 0);
}
