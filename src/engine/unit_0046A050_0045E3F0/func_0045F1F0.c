#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0045F1F0_arg0 {
    char pad0[0x2C];
    void *unk2C;
    char pad30[0x10];
    f32 unk40;
};
struct func_0045F1F0_temp_v0 {
    char pad0[0xD];
    u8 unkD;
};

f32 func_0045F1F0(struct func_0045F1F0_arg0 *arg0) {
    f32 var_f0;
    struct func_0045F1F0_temp_v0 *temp_v0;

    temp_v0 = arg0->unk2C;
    var_f0 = 0x0.0p+0f;
    if (temp_v0 != NULL) {
        var_f0 = (f32) temp_v0->unkD * arg0->unk40;
    }
    return var_f0;
}
