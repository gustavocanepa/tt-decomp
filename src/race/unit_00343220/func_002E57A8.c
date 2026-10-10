#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E57A8_temp_a0 {
    char pad0[0x58C];
    f32 unk58C;
    char pad590[0x8];
    f32 unk598;
};

f32 func_002E57A8(s32 arg0) {
    f32 var_f0;
    f32 var_f1;
    struct func_002E57A8_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0x104;
    var_f1 = temp_a0->unk58C - temp_a0->unk598;
    if (var_f1 < 0x0.0p+0f) {
        var_f1 = -var_f1;
    }
    var_f0 = 0x1.6b93f60000000p+0f - var_f1;
    if (var_f0 < 0x0.0p+0f) {
        var_f0 = 0x0.0p+0f;
    }
    return var_f0;
}
