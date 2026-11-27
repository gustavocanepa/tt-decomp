#include "types.h"

struct Inner {
    char pad[0x8];
    s32 *unk8;
};

struct Obj {
    char pad[0x60];
    Inner *unk60;
};

extern "C" s32 func_0055AC48(Obj *arg0, s32 arg1) {
    return arg0->unk60->unk8[arg1];
}
