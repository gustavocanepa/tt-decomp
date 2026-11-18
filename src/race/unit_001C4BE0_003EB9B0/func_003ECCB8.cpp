#include "types.h"

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern "C" void func_003ECCB8(struct Obj *arg0) {
    s32 temp_v0 = arg0->unk0;
    arg0->unk8 = 0;
    arg0->unk4 = (temp_v0 > 0) ? 0 : -1;
}
