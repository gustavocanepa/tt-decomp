#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001EC230_arg0 {
    char pad0[0xDC];
    f32 unkDC;
    f32 unkE0;
    f32 unkE4;
};

s32 func_001EC230(struct func_001EC230_arg0 *arg0, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 temp_f2;
    f32 var_f1;
    s32 var_v0;

    temp_f2 = arg0->unkDC;
    temp_f0 = arg0->unkE0;
    temp_f12 = temp_f2 + fparg0;
    arg0->unkDC = temp_f12;
    if (temp_f12 < temp_f0) {
        arg0->unkDC = temp_f0;
    }
    var_f1 = arg0->unkDC;
    temp_f0_2 = arg0->unkE4;
    if (temp_f0_2 < var_f1) {
        arg0->unkDC = temp_f0_2;
        var_f1 = temp_f0_2;
    }
    var_v0 = 1;
    if (var_f1 == temp_f2) {
        var_v0 = 0;
    }
    return var_v0;
}
