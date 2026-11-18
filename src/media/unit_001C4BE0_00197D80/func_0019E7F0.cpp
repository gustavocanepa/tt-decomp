#include "types.h"

struct Obj {
    char pad0[0x48];
    u16 unk48;
    char pad1[0x188 - 0x4A];
    s32 unk148;
};

extern "C" s32 func_0019E7F0(Obj *arg0) {
    if ((arg0->unk48 & 1) == 0) {
        return 0;
    }
    return arg0->unk148;
}
