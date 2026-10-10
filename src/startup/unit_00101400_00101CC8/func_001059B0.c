/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00105778(s32, s32, s32, s32); /* extern */
s32 func_00105860(s32, s32, s32);       /* extern */
s32 func_001059F8();                            /* extern */

void func_001059B0(s32 arg0) {
    func_001059F8();
    func_00105778(arg0, 1, 2, 1);
    func_00105860(arg0, 0x280, 0x1C0);
}
