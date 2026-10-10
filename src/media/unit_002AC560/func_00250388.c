#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001E2D70(s32, s32);                    /* extern */
s32 func_00210118();                                /* extern */

s32 func_00250388(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_00210118();
    if (temp_v0 != 0) {
        func_001E2D70(arg1, temp_v0);
    }
    return 2;
}
