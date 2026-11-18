#include "types.h"

struct Pair {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_004C8118(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_004C7908(s32 arg0, struct Pair *arg1) {
    func_004C8118(arg0, arg1->unk0, arg1->unk4);
}
