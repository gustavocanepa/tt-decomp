#include "types.h"

struct Obj {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_003EBBF8(Obj *arg0) {
    arg0->unk4 = 0;
    arg0->unk0 = 1;
}
