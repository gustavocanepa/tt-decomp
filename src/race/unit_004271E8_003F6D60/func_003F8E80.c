#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AC3B8(s32, s32, s32);           /* extern */

extern char D_00769560[];
s32 func_003F8E80(s32 arg0) {
    return func_004AC3B8((s32)D_00769560, arg0, 0xE) & 0xFF;
}
