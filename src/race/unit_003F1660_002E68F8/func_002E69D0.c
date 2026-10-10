#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E69D0_arg0_unk10 {
    char pad0[0x23C];
    f32 unk23C;
};
struct func_002E69D0_arg0 {
    char pad0[0x10];
    struct func_002E69D0_arg0_unk10 *unk10;
};

s32 func_002E69D0(struct func_002E69D0_arg0 *arg0) {
    s32 var_v1;

    var_v1 = 1;
    if (arg0->unk10->unk23C == 0x0.0p+0f) {
        var_v1 = 0;
    }
    return var_v1;
}
