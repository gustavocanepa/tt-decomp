#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0020E5A0();                                /* extern */
s32 func_0020E5B0(s32, s32);                /* extern */
s32 func_0020E5E0(s32, s32);                    /* extern */

s32 func_0020E760(s32 arg0) {
    s32 temp_s1;

    temp_s1 = func_0020E5A0();
    func_0020E5B0(arg0, 0);
    func_0020E5E0(arg0, temp_s1);
    return temp_s1;
}
