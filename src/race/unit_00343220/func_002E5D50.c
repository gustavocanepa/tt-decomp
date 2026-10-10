#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E5D50_arg0 {
    char pad0[0x5B0];
    f32 unk5B0;
    char pad5B4[0x1FC];
    f32 unk7B0;
};

s32 func_002E5D50(struct func_002E5D50_arg0 *arg0) {
    s32 var_v0;

    var_v0 = 0;
    if ((arg0->unk5B0 > 0x0.0p+0f) || (arg0->unk7B0 > 0x0.0p+0f)) {
        var_v0 = 1;
    }
    return var_v0;
}
