#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0041E548_arg0 {
    s32 unk0;
    char pad4[0x5C];
    f32 unk60;
    f32 unk64;
    f32 unk68;
    f32 unk6C;
    f32 unk70;
    f32 unk74;
};

s32 func_0041E548(struct func_0041E548_arg0 *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if ((arg0->unk0 & 1) || ((arg0->unk60 == arg0->unk6C) && (arg0->unk64 == arg0->unk70) && (arg0->unk68 == arg0->unk74))) {
        var_v1 = 1;
    }
    return var_v1;
}
