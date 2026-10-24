#include "types.h"

struct Obj {
    char pad0[0xAC];
    s32 unkAC;
};

extern "C" s32 func_0047E2E8(s32 arg0);

extern "C" s32 func_00480358(Obj *arg0) {
    return func_0047E2E8(arg0->unkAC);
}
