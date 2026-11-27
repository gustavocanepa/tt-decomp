#include "types.h"

struct Obj {
    s32 unk0;
};

extern "C" void func_0055E008(Obj *arg0, u8 arg1) {
    arg0->unk0 = (arg0->unk0 & ~0xFF) | arg1;
}
