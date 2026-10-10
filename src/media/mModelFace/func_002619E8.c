#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001C1A68(s32, s32, s32);                   /* extern */
s32 func_001FC7F8();                   /* extern */

s32 func_002619E8(s32 arg0, s32 arg1, s32 arg2) {
    if ((func_001FC7F8(arg0 + 0x2C) != 0) || (func_001FC7F8(arg0 + 0x100, arg1, arg2) != 0)) {
        return 1;
    }
    return func_001C1A68(arg0 + 0x16C, arg1, arg2) != 0;
}
