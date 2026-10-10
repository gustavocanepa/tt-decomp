#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00444C98_arg0 {
    f32 unk0;
    f32 unk4;
};
struct func_00444C98_arg1 {
    f32 unk0;
    f32 unk4;
};

s32 func_00444C98(struct func_00444C98_arg0 *arg0, struct func_00444C98_arg1 *arg1) {
    s32 var_v0;

    var_v0 = 0;
    if ((arg0->unk0 == arg1->unk0) && (arg0->unk4 == arg1->unk4)) {
        var_v0 = 1;
    }
    return var_v0;
}
