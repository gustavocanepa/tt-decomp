#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0035B998_arg0 {
    u8 unk0;
    char pad1[0x2B];
    f32 unk2C;
};

s32 func_0035B998(struct func_0035B998_arg0 *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if ((arg0->unk0 != 0) && (arg0->unk2C >= 0x0.0p+0f)) {
        var_v1 = 1;
    }
    return var_v1;
}
