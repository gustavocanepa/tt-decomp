#include "types.h"

struct Obj {
    char pad[0x94];
    s32 unk94;
};

extern "C" void func_004B31A0(s32 arg0, Obj *arg1, s32 arg2, s32 arg3);

extern "C" void func_004B3200(s32 arg0, Obj *arg1) {
    func_004B31A0(arg0, arg1, 1, 1);
}
