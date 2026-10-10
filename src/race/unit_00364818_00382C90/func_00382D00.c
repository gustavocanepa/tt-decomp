#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003E6F48(f32);                             /* extern */

struct func_00382D00_arg0 {
    char pad0[0x58];
    f32 unk58;
    f32 unk5C;
    f32 unk60;
    f32 unk64;
};

void func_00382D00(struct func_00382D00_arg0 *arg0, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f3;
    f32 var_f0;

    temp_f0 = arg0->unk5C + fparg0;
    arg0->unk5C = temp_f0;
    if (temp_f0 > 0x1.e000000000000p+4f) {
        temp_f20 = temp_f0 - 0x0.0p+0f;
        arg0->unk5C = (f32) ((temp_f20 - ((f32) func_003E6F48(temp_f20 / 0x1.e000000000000p+4f) * 0x1.e000000000000p+4f)) + 0x0.0p+0f);
    }
    var_f0 = arg0->unk58 / 0x1.0c15200000000p-1f;
    if (var_f0 < -0x1.0000000000000p+0f) {
        var_f0 = -0x1.0000000000000p+0f;
    } else if (var_f0 > 0x1.0000000000000p+0f) {
        var_f0 = 0x1.0000000000000p+0f;
    }
    temp_f3 = arg0->unk60;
    temp_f2 = arg0->unk64;
    temp_f2_2 = temp_f2 + ((((var_f0 - temp_f3) * 0x1.9000000000000p+6f) - (temp_f2 * 0x1.4000000000000p+4f)) * fparg0);
    arg0->unk64 = temp_f2_2;
    arg0->unk60 = (f32) (temp_f3 + (temp_f2_2 * fparg0));
}
