#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0030C938_temp_a0 {
    char pad0[0x1694];
    s16 unk1694;
};

f32 func_0030C938(void **arg0) {
    f32 var_f0;
    struct func_0030C938_temp_a0 *temp_a0;

    temp_a0 = *arg0;
    var_f0 = 0x0.0p+0f;
    if (temp_a0 != NULL) {
        var_f0 = (f32) temp_a0->unk1694;
    }
    return var_f0;
}
