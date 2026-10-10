#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00205D10(void *);                          /* extern */
f32 func_00205D70(void *);                          /* extern */
f32 func_00278860();                                /* extern */

struct func_00253E38_arg0 {
    char pad0[0xD4];
    s32 unkD4;
};

f32 func_00253E38(struct func_00253E38_arg0 *arg0) {
    f32 temp_f20;
    f32 var_f0;

    temp_f20 = 0x1.0000000000000p+1f * func_00278860();
    if (arg0->unkD4 == 0) {
        var_f0 = func_00205D10(arg0);
    } else {
        var_f0 = func_00205D70(arg0);
    }
    return var_f0 - temp_f20;
}
