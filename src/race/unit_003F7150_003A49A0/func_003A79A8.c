#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002FED98(s32);                             /* extern */

struct func_003A79A8_arg0 {
    char pad0[0x8];
    s32 unk8;
    char padC[0x4];
    void *unk10;
};
struct func_003A79A8_temp_a0 {
    char pad0[0x18];
    s32 unk18;
};

f32 func_003A79A8(struct func_003A79A8_arg0 *arg0) {
    f32 var_f0;
    s32 temp_s0;
    struct func_003A79A8_temp_a0 *temp_a0;

    temp_s0 = arg0->unk8;
    var_f0 = 0x0.0p+0f;
    if (temp_s0 == 1) {
        temp_a0 = arg0->unk10;
        if (temp_a0 != NULL) {
            var_f0 = 0x1.9999980000000p-3f;
            if (func_002FED98(temp_a0->unk18) == temp_s0) {
                var_f0 = 0x1.9999980000000p-4f;
            }
        }
    }
    return var_f0;
}
