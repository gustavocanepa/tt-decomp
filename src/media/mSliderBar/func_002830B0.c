#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AC650(s32, s32);                    /* extern */

void func_002830B0(s32 arg0, s32 arg1) {
    func_004AC650(arg0 + 0xE8, -arg1);
}
