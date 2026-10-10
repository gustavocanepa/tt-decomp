#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001EC208_arg0 {
    char pad0[0xDC];
    f32 unkDC;
    f32 unkE0;
    f32 unkE4;
};

void func_001EC208(struct func_001EC208_arg0 *arg0, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 var_f12;

    var_f12 = fparg0;
    temp_f0 = arg0->unkE0;
    if (var_f12 < temp_f0) {
        var_f12 = temp_f0;
    }
    temp_f0_2 = arg0->unkE4;
    if (temp_f0_2 < var_f12) {
        var_f12 = temp_f0_2;
    }
    arg0->unkDC = var_f12;
}
