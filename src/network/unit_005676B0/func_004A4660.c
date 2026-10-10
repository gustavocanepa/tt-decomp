#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AE120(s32, s32, s32, s32);  /* extern */

extern char D_007739A0[];
void func_004A4660(s32 arg0, s32 arg1) {
    func_004AE120((s32)D_007739A0, arg0, arg1, 0x10);
}
