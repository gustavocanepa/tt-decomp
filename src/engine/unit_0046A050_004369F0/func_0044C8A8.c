#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_0044C720(void *, s32);                     /* extern */
s32 func_004A4D68();                            /* extern */
s32 func_004A4DD8(void *);                      /* extern */

struct func_0044C8A8_arg0 {
    char pad0[0x30];
    s32 unk30;
};

s32 func_0044C8A8(struct func_0044C8A8_arg0 *arg0, s32 arg1, s32 (*arg2)(s64)) {
    s32 temp_v0;
    s32 var_s0;

    func_004A4D68();
    var_s0 = 0;
    temp_v0 = func_0044C720(arg0, arg1);
    if (temp_v0 >= 0) {
        var_s0 = 1;
        arg2(M2C_FIELD(((temp_v0 * 0x10) + arg0->unk30), s64 *, 8));
    }
    func_004A4DD8(arg0);
    return var_s0;
}
