#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0045A688(s32);                             /* extern */

s32 func_00457AF0(s32 arg0, s32 arg1, s32 arg2) {
    return (func_0045A688(arg0 + 0x85C) - arg1) + (arg2 * 0xC) + 6;
}
