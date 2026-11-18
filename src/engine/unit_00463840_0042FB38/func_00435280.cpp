#include "types.h"

struct Inner {
    char pad[0x20A39];
    u8 unk20A39;
};

struct Obj {
    char pad[4];
    Inner *unk4;
};

extern "C" s32 func_00435280(Obj *arg0) {
    s32 result = 1;
    if (arg0->unk4->unk20A39 == 0) {
        result = -1;
    }
    return result;
}
