#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001BEC40_arg0 {
    char pad0[0x54];
    f32 unk54;
    f32 unk58;
    f32 unk5C;
};

void func_001BEC40(struct func_001BEC40_arg0 *arg0, f32 fparg0) {
    f32 var_f0;
    f32 var_f12;

    var_f12 = fparg0;
    if (var_f12 <= 0x0.0p+0f) {
        var_f12 = 0x1.0000000000000p+0f;
    }
    var_f0 = arg0->unk58 - arg0->unk54;
    if (!(var_f0 >= 0x0.0p+0f)) {
        var_f0 = -var_f0;
    }
    arg0->unk5C = (f32) (var_f0 / var_f12);
}
