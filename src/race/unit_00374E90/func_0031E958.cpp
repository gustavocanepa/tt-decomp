#include "types.h"

struct Obj {
    s32 unk0;
    f32 unk4;
};

extern "C" void func_0031E958(Obj *arg0, s32 arg1, f32 fparg0) {
    arg0->unk0 = arg1;
    arg0->unk4 = fparg0;
}
