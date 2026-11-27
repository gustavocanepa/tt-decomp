#include "types.h"

struct Obj {
    s32 unk0;
    char pad[0x8];
    s32 unkC;
    char pad2[0x14];
    s32 unk24;
};

extern "C" s32 func_00576668(Obj *arg0) {
    if (arg0->unk0 & 0x100) {
        return arg0->unkC;
    }
    return arg0->unk24;
}
