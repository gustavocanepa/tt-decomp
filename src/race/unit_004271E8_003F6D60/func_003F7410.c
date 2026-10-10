#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004A8368(s32);                             /* extern */
s32 func_004F7B74(void *, s32);                 /* extern */

struct func_003F7410_arg0 {
    char pad0[0xB28];
    s32 unkB28;
};

void func_003F7410(void *arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_004A8368(arg1);
    temp_v0_2 = ((struct func_003F7410_arg0 *)arg0)->unkB28;
    if ((temp_v0 + temp_v0_2) < 0xFF) {
        func_004F7B74(arg0 + temp_v0_2 + 0xB2C, arg1);
        ((struct func_003F7410_arg0 *)arg0)->unkB28 = (s32) (((struct func_003F7410_arg0 *)arg0)->unkB28 + temp_v0 + 1);
    }
}
