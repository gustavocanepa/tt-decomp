#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001E94D8(s32);                             /* extern */
s32 func_0020D888(s32);                             /* extern */
s32 func_00210118(void *);                          /* extern */
s32 func_002774B0(void *, s32, s32, s32);       /* extern */

struct func_00277690_arg0 {
    char pad0[0xEC];
    s32 unkEC;
};

s32 func_00277690(struct func_00277690_arg0 *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    s32 temp_v0_2;

    if (func_0020D888(arg0->unkEC) != 0) {
        temp_v0 = func_00210118(arg0);
        if (temp_v0 != 0) {
            temp_v0_2 = func_001E94D8(temp_v0);
            if (temp_v0_2 != 0) {
                func_002774B0(arg0, temp_v0_2, arg1, arg2);
                return 1;
            }
        }
    }
    return 0;
}
