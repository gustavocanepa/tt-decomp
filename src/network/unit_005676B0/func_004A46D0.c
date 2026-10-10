#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004A4690(s32, s32);                /* extern */

void func_004A46D0(s32 arg0) {
    func_004A4690(0x1000, (arg0 + 0xFFF) & ~0xFFF);
}
