#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001FC7F8();                   /* extern */

s32 func_001D1C70(s32 arg0, s32 arg1, s32 arg2) {
    if (func_001FC7F8(arg0 + 0x2C) != 0) {
        return 1;
    }
    return func_001FC7F8(arg0 + 0x178, arg1, arg2) != 0;
}
