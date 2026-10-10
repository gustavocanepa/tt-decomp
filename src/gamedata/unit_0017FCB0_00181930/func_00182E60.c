#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00182E60_arg0 {
    char pad0[0xB4];
    void *unkB4;
};
struct func_00182E60_temp_v0 {
    char pad0[0x40];
    f32 unk40;
};

f32 func_00182E60(struct func_00182E60_arg0 *arg0) {
    f32 var_f0;
    struct func_00182E60_temp_v0 *temp_v0;

    temp_v0 = arg0->unkB4;
    var_f0 = 0x0.0p+0f;
    if (temp_v0 != NULL) {
        var_f0 = temp_v0->unk40;
    }
    return var_f0;
}
