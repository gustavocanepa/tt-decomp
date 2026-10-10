#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001DD3C8_temp_v0 {
    char pad0[0x8];
    f32 unk8;
};

struct func_001DD3C8_arg0 {
    char pad0[0x10];
    f32 unk10;
    f32 unk14;
    char pad18[0x4];
    f32 unk1C;
};

void func_001DD3C8(void *arg0, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 var_f12;
    struct func_001DD3C8_temp_v0 *temp_v0;

    var_f12 = fparg0;
    temp_f0 = ((struct func_001DD3C8_arg0 *)arg0)->unk10;
    temp_v0 = arg0 + 0x20;
    if (var_f12 < temp_f0) {
        var_f12 = temp_f0;
    }
    temp_f0_2 = ((struct func_001DD3C8_arg0 *)arg0)->unk14;
    if (temp_f0_2 <= var_f12) {
        var_f12 = temp_f0_2;
    }
    ((struct func_001DD3C8_arg0 *)arg0)->unk1C = var_f12;
    if (var_f12 < temp_v0->unk8) {
        temp_v0->unk8 = var_f12;
    }
}
