#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00370880(s32);                         /* extern */

struct func_0010C9D0_arg0 {
    char pad0[0x60];
    s32 *unk60;
};

void func_0010C9D0(struct func_0010C9D0_arg0 *arg0) {
    s32 temp_v0;
    s32 var_s0;

    var_s0 = 0;
    if (*arg0->unk60 > 0) {
        do {
            temp_v0 = var_s0 * 4;
            var_s0 += 1;
            func_00370880(*(s32 *)(temp_v0 + M2C_FIELD(arg0->unk60, s32 *, 8)) + 0x1220);
        } while (var_s0 < *arg0->unk60);
    }
}
