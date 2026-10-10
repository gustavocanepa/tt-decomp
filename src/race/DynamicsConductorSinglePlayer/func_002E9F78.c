#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E9F78_temp_a0 {
    char pad0[0x4AC];
    f32 unk4AC;
    char pad4B0[0x1FC];
    f32 unk6AC;
    char pad6B0[0x8];
    s8 unk6B8;
};

f32 func_002E9F78(s32 arg0) {
    f32 temp_f2;
    f32 var_f1;
    struct func_002E9F78_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0x104;
    var_f1 = temp_a0->unk4AC;
    if (temp_a0->unk6B8 != 0) {
        var_f1 = temp_a0->unk6AC;
    } else {
        temp_f2 = temp_a0->unk6AC;
        if (temp_f2 > 0x0.0p+0f) {
            var_f1 = temp_f2;
        }
    }
    return var_f1;
}
