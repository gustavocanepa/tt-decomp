#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00206088_arg0 {
    char pad0[0x58];
    f32 unk58;
    char pad5C[0x50];
    s32 unkAC;
};

void func_00206088(struct func_00206088_arg0 *arg0, f32 fparg0) {
    f32 var_f12;

    var_f12 = fparg0;
    if (var_f12 < 0x0.0p+0f) {
        var_f12 = 0x0.0p+0f;
    }
    if (var_f12 != arg0->unk58) {
        arg0->unk58 = var_f12;
        arg0->unkAC = (s32) (arg0->unkAC | 0x40000);
    }
}
