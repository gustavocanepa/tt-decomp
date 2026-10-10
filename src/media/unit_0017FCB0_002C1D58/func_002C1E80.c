/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A97D8(s32, s32);                    /* extern */

void func_002C1E80(s32 arg0, s32 *arg1) {
    func_002A97D8(*arg1, arg0 + 0xC);
}
