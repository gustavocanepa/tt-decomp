#include "types.h"

struct Obj {
    char pad[0x34];
    s32 unk34;
    s32 arr38[4];
    s32 unk48;
};

extern "C" void func_0054E1D0(Obj *arg0, s32 arg1) {
    arg0->unk34 = arg1;
    arg0->unk48 = arg0->arr38[arg1];
}
