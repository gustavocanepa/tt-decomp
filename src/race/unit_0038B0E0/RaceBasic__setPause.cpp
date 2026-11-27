#include "types.h"

struct Obj {
    char pad[0xE4D8];
    s32 unkE418;
};

extern "C" void func_0033C3F0(Obj *arg0, s32 arg1);

extern "C" void RaceBasic__setPause(Obj *arg0, s32 arg1) {
    func_0033C3F0(arg0, (arg0->unkE418 == 0) ? 0 : arg1);
}
