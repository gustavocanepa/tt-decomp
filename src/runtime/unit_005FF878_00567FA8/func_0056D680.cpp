#include "types.h"

struct Obj {
    char pad[0x10];
    s16 *unk10;
};

extern "C" void func_0056D680(Obj *arg0, s32 arg1, s16 arg2) {
    arg0->unk10[arg1] = arg2;
}
