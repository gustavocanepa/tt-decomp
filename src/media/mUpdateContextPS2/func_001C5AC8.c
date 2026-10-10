#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001C7768(s32, s32);                    /* extern */
s32 func_002BDA28(s32, s32);                /* extern */

s32 func_001C5AC8(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_002BDA28(0x1DA8, 4);
    func_001C7768(temp_v0, arg0);
    return temp_v0;
}
