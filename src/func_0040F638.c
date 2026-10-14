#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0040F5F8(s32, s32);                    /* extern */
s32 func_0040FB40();                                /* extern */

s32 func_0040F638(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_0040FB40();
    if (temp_v0 != -1) {
        return func_0040F5F8(temp_v0, arg1);
    }
    return 0;
}
