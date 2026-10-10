#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00489720();                  /* extern */
s32 func_004A8368(s8 *);                            /* extern */
s32 func_004F6678(s8 *, s32, s32);      /* extern */
s32 func_004F7A30(s8 *, s8 *);                  /* extern */
s8 *func_0050E130(s32);                             /* extern */
s32 func_0050E1C8(s8 *);                        /* extern */

struct func_001A2480_arg0 {
    char pad0[0xC];
    s32 unkC;
};

s32 func_001A2480(struct func_001A2480_arg0 *arg0, s8 *arg1, s32 arg2) {
    s32 var_s1;
    s8 *temp_v0;
    s8 temp_v1;

    temp_v1 = *arg1;
    if ((temp_v1 == 0x2F) || (temp_v1 == 0x5C)) {
        var_s1 = func_00489720(arg0->unkC);
    } else {
        temp_v0 = func_0050E130(func_004A8368(arg1) + 2);
        func_004F6678(temp_v0, 0, 4);
        *temp_v0 = 0x2F;
        func_004F7A30(temp_v0, arg1);
        var_s1 = func_00489720(arg0->unkC, temp_v0, arg2);
        func_0050E1C8(temp_v0);
    }
    return var_s1;
}
