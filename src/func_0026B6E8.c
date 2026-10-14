#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001E4EA0(s32);                             /* extern */
s32 func_001E9558(s32, s32);                    /* extern */
s32 func_0026AA90(void *);                          /* extern */

struct func_0026B6E8_arg0 {
    char pad0[0xE0];
    s32 unkE0;
};

s32 func_0026B6E8(struct func_0026B6E8_arg0 *arg0, s32 arg1) {
    s32 temp_s0;
    s32 temp_v0;

    if (arg0->unkE0 == 0) {
        return 0;
    }
    temp_s0 = func_001E4EA0(arg1);
    temp_v0 = func_0026AA90(arg0);
    if (temp_v0 != 0) {
        func_001E9558(temp_s0, temp_v0);
    }
    return temp_v0;
}
