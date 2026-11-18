#include "types.h"

struct Obj {
    char pad0[0xC8];
    s32 unkC8;
};

extern "C" s32 func_004C9A88(s32 arg0);

extern "C" s32 func_00574E80(Obj *arg0) {
    return func_004C9A88(arg0->unkC8);
}
