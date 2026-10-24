#include "types.h"

struct Inner {
    char pad[0x50];
    s32 unk50;
};

struct Obj {
    char pad[0x8];
    Inner *unk8;
};

extern "C" s32 func_00341AD8(Obj *arg0) {
    s32 var_v0;
    Inner *temp_v1;

    temp_v1 = arg0->unk8;
    var_v0 = 0;
    if (temp_v1 != 0) {
        var_v0 = temp_v1->unk50;
    }
    return var_v0;
}
