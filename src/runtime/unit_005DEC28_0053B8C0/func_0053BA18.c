/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004C9C08(s32, s32);                    /* extern */
s32 func_004C9C50(s32);                             /* extern */

void func_0053BA18(s32 arg0, s32 arg1) {
    func_004C9C08(arg1 + 0x10, func_004C9C50(arg0 + 0x14));
}
