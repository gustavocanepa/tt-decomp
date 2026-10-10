#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003F8220(s32);                             /* extern */

void func_003F8260(s32 *arg0, s32 arg1) {
    *arg0 = (*arg0 & ~0xF) | (func_003F8220(arg1) & 0xF);
}
