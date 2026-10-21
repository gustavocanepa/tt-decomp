#include "types.h"

struct S {
    u32 unk0;
    s32 unk4;
};

extern "C" void func_00445480(S *arg0) {
    arg0->unk4 = 0;
    arg0->unk0 = 0x80808080;
}
