#include "types.h"

struct Obj {
    char pad0[4];
    f32 unk4;
    f32 unk8;
};

extern "C" s32 func_00319860(Obj *arg0, f32 fparg0) {
    s32 result = 0;
    if (!(fparg0 < arg0->unk4) && !(arg0->unk8 < fparg0)) {
        result = 1;
    }
    return result;
}
