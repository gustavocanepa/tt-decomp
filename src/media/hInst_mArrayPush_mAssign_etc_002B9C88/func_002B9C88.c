/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0029F850(s32, s32);                    /* extern */
s32 func_002AC250(s32);                         /* extern */

void func_002B9C88(s32 arg0, s32 arg1) {
    func_002AC250(arg0 + 8);
    func_0029F850(arg1, arg0 + 0x18);
}
