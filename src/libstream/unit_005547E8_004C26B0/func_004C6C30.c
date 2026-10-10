/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004C6BE0();                            /* extern */
s32 func_004C6C08(s32, s32, s32);               /* extern */

void func_004C6C30(s32 arg0, s32 arg1, s32 arg2) {
    func_004C6BE0();
    func_004C6C08(arg0, arg1, arg2);
}
