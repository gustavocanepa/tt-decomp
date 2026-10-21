#include "types.h"

struct Obj {
    char pad[0xC4];
    s32 unkC4;
};

extern "C" s32 func_004C99C0(s32 arg0);

extern "C" s32 func_00574E50(Obj *arg0) {
    return func_004C99C0(arg0->unkC4);
}
