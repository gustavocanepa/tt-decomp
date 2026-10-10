#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002F9AA0_arg0 {
    char pad0[0x7E9];
    s8 unk7E9;
};

f32 func_002F9AA0(struct func_002F9AA0_arg0 *arg0) {
    f32 var_f0;

    var_f0 = 0x1.0000000000000p+0f;
    if (arg0->unk7E9 < 0) {
        var_f0 = 0x0.0p+0f;
    }
    return var_f0;
}
