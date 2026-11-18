#include "types.h"

struct Pair {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_004B09B0(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_00571FB0(s32 arg0, struct Pair *arg1) {
    func_004B09B0(arg0, arg1->unk0, arg1->unk4);
}
