#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_0020E360(s32);                             /* extern */
f32 func_0020E510(s32);                             /* extern */

struct func_0028EAE8_arg0 {
    char pad0[0xDC];
    s32 unkDC;
};

void func_0028EAE8(struct func_0028EAE8_arg0 *arg0, s32 arg1, f32 *arg2, f32 *arg3) {
    f32 var_f0;

    if (arg0->unkDC != 0) {
        *arg2 = func_0020E360(arg1);
        var_f0 = func_0020E510(arg1);
    } else {
        *arg2 = func_0020E510(arg1);
        var_f0 = func_0020E360(arg1);
    }
    *arg3 = var_f0;
}
