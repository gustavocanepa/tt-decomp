#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001FC7F8(s32);                             /* extern */

s32 func_001943E0(s32 arg0) {
    return func_001FC7F8(arg0 + 0x2C) != 0;
}
