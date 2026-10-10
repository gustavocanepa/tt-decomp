#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001EC1A8_arg0 {
    char pad0[0xE0];
    f32 unkE0;
    f32 unkE4;
    char padE8[0x24];
    f32 unk10C;
};

void func_001EC1A8(struct func_001EC1A8_arg0 *arg0, f32 fparg0) {
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
    arg0->unk10C = var_f12;
}
