#include "types.h"

struct func_00556F28_obj {
    f32 unk0;
    char pad4[0x14];
    s32 unk18;
};

extern "C" s32 func_00556F28(u8 *arg0) {
    struct func_00556F28_obj *p = (struct func_00556F28_obj *)(arg0 + 0x54);
    s32 var_a1 = 0;

    if (p->unk18 == 2 && p->unk0 <= 0.0f) {
        var_a1 = 1;
    }
    return var_a1;
}
