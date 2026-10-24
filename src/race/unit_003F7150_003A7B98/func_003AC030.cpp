#include "types.h"

struct Obj {
    char pad0[0x1C];
    s32 unk1C;
};

extern "C" s32 func_003AC030(Obj *arg0) {
    return arg0->unk1C > 0;
}
