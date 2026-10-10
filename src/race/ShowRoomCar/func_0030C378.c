#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0030C378_temp_a0 {
    char pad0[0x658];
    f32 unk658;
};

f32 func_0030C378(void **arg0) {
    f32 var_f0;
    struct func_0030C378_temp_a0 *temp_a0;

    temp_a0 = *arg0;
    var_f0 = 0x0.0p+0f;
    if (temp_a0 != NULL) {
        var_f0 = temp_a0->unk658;
    }
    return var_f0;
}
