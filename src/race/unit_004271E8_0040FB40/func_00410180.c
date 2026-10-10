#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0040FB40(s32);                             /* extern */
s32 func_0040FDA0();                                /* extern */
s32 func_004100A8(s32, s32);                    /* extern */

s32 func_00410180(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_0040FDA0();
    if (temp_v0 != 0) {
        func_004100A8(func_0040FB40(temp_v0), arg1);
    }
}
