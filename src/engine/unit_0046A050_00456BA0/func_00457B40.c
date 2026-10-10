#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A8368(s32);                             /* extern */

s32 func_00457B40(s32 arg0, s32 arg1) {
    return (func_004A8368(arg1) + 0x10) & ~0xF;
}
