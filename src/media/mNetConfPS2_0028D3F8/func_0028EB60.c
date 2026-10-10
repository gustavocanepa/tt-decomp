#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0020E2C0(s32);                             /* extern */
s32 func_0020E470(s32);                             /* extern */

struct func_0028EB60_arg0 {
    char pad0[0xDC];
    s32 unkDC;
};

void func_0028EB60(struct func_0028EB60_arg0 *arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    s32 var_v0;

    if (arg0->unkDC != 0) {
        *arg2 = func_0020E2C0(arg1);
        var_v0 = func_0020E470(arg1);
    } else {
        *arg2 = func_0020E470(arg1);
        var_v0 = func_0020E2C0(arg1);
    }
    *arg3 = var_v0;
}
