#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00206050_arg0 {
    char pad0[0x54];
    f32 unk54;
    char pad58[0x54];
    s32 unkAC;
};

void func_00206050(struct func_00206050_arg0 *arg0, f32 fparg0) {
    f32 var_f12;

    var_f12 = fparg0;
    if (var_f12 < 0x0.0p+0f) {
        var_f12 = 0x0.0p+0f;
    }
    if (var_f12 != arg0->unk54) {
        arg0->unk54 = var_f12;
        arg0->unkAC = (s32) (arg0->unkAC | 0x40000);
    }
}
