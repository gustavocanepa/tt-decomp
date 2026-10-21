#include "types.h"

struct ObjInner {
    char pad[0x1148];
    s32 unk1140;
};

struct Obj {
    char pad[0x10];
    ObjInner *unk10;
};

extern "C" s32 func_0051B7F8(Obj *arg0) {
    s32 r = 0;
    if (arg0->unk10->unk1140 & 4) {
        r = 1;
    }
    return r;
}
