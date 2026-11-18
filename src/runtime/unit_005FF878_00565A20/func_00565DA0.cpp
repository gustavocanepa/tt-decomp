#include "types.h"

struct Obj {
    char pad0[0x94];
    u8 unk94;
};

extern "C" s32 func_00565DA0(Obj *arg0) {
    return arg0->unk94 * 10;
}
