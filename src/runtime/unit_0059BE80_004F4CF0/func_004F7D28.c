#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004A47E0(s32, s32);                        /* extern */
s32 func_004A8368(s32);                             /* extern */
s32 func_004F64C4(s32, s32, s32);               /* extern */

s32 func_004F7D28(s32 arg0, s32 arg1) {
    s32 temp_s2;
    s32 temp_v0;

    temp_s2 = func_004A8368(arg1) + 1;
    temp_v0 = func_004A47E0(arg0, temp_s2);
    if (temp_v0 != 0) {
        func_004F64C4(temp_v0, arg1, temp_s2);
    }
    return temp_v0;
}
