#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002F8A68_arg0 {
    char pad0[0x5F0];
    f32 unk5F0;
};

s32 func_002F8A68(struct func_002F8A68_arg0 *arg0) {
    s32 var_v0;

    var_v0 = 1;
    if (!(arg0->unk5F0 > 0x0.0p+0f)) {
        var_v0 = 0;
    }
    return var_v0;
}
