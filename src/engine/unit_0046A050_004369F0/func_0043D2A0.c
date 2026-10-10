#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0043D280(s32);                             /* extern */
s32 func_004A8368();                                /* extern */
s32 func_004F7B74(s32, s32);                    /* extern */

s32 func_0043D2A0(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_0043D280(func_004A8368());
    func_004F7B74(temp_v0 + 2, arg0);
    return temp_v0;
}
