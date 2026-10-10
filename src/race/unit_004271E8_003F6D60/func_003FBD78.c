#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003FBCF8(s32, s32, s32, s32);
s32 func_003FB678(s32, s32);                    /* extern */

s32 func_003FBD78(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_v0;

    temp_v0 = func_003FBCF8(arg0, arg1, arg2, arg4);
    if (temp_v0 >= 0) {
        func_003FB678(arg0 + (temp_v0 << 5) + 8, arg3);
    }
    return temp_v0;
}
