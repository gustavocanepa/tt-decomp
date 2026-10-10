#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0040B840(s32, s32, s32);           /* extern */

extern char D_00585A30[];
s32 func_0040FD28(s32 arg0) {
    return ~func_0040B840((s32)D_00585A30, arg0, 0x26) != 0;
}
