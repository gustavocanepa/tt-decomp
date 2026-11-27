#include "types.h"

struct Obj {
    char pad[0x20];
    s32 unk20;
};

extern "C" s32 func_0041AB38(Obj **arg0) {
    s32 var_v0;
    Obj *temp_a0;

    temp_a0 = *arg0;
    var_v0 = 0;
    if (temp_a0 != 0) {
        var_v0 = temp_a0->unk20;
    }
    return var_v0;
}
