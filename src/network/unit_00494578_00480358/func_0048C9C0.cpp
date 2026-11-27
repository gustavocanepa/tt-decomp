#include "types.h"

struct Obj {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_0048C9C0(Obj *arg0, s32 arg1) {
    s32 a = arg0->unk0;
    s32 b = arg0->unk4;
    if (b == a) {
        arg0->unk4 = arg1;
    }
    arg0->unk0 = arg1;
}
