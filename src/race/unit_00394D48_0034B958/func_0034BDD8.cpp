#include "types.h"

struct Inner {
    char pad[0xB0];
    s32 unkB0;
};

struct Obj {
    char pad[0x4];
    Inner *unk4;
};

extern "C" s32 func_0037C438(s32 arg0);

extern "C" s32 func_0034BDD8(Obj *arg0) {
    return func_0037C438(arg0->unk4->unkB0);
}
