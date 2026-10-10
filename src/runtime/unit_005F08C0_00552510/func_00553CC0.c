/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00552A68(s32, s32);                    /* extern */

void func_00553CC0(s32 arg0, s32 arg1) {
    func_00552A68(arg1, arg0 + 0x1C0);
}
