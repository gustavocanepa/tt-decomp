#include "types.h"

struct Obj {
    char pad0[0x8];
    s32 unk8;
};

extern "C" s32 func_003AAE88(Obj *arg0, s32 arg1) {
    return arg0->unk8 + (arg1 * 0x74);
}
