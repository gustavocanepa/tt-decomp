#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005417D8_arg0 {
    char pad0[0x120];
    f32 unk120;
};

void func_005417D8(struct func_005417D8_arg0 *arg0, f32 fparg0) {
    f32 var_f12;

    var_f12 = fparg0;
    if (var_f12 < 0x0.0p+0f) {
        var_f12 = 0x0.0p+0f;
    }
    if (var_f12 > 0x1.0000000000000p+0f) {
        var_f12 = 0x1.0000000000000p+0f;
    }
    arg0->unk120 = var_f12;
}
