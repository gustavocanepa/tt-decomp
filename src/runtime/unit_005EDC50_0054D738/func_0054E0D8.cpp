#include "types.h"

struct Inner {
    char pad0[0x8];
    s32 unk14;
    char pad1[0x8];
    s32 unk20;
};

struct Obj {
    char pad[0x2C];
    Inner *unk2C;
};

extern "C" s32 func_0054E0D8(struct Obj *arg0) {
    struct Inner *temp = arg0->unk2C;
    return temp->unk14 + ((temp->unk20 - 1) << 2);
}
