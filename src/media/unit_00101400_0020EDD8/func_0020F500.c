#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0020F500_arg0 {
    char pad0[0xA0];
    f32 unkA0;
};

void func_0020F500(struct func_0020F500_arg0 *arg0, f32 fparg0) {
    f32 var_f12;

    var_f12 = fparg0;
    if (var_f12 < 0x0.0p+0f) {
        var_f12 = 0x0.0p+0f;
    }
    if (var_f12 > 0x1.0000000000000p+0f) {
        var_f12 = 0x1.0000000000000p+0f;
    }
    arg0->unkA0 = var_f12;
}
