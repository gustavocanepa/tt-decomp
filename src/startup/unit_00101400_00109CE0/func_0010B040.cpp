#include "types.h"

struct Obj {
    char pad[0x1748];
    s32 unk1748;
};

extern "C" struct Obj *D_005857DC;

extern "C" void func_003768B0(void *arg0, s32 arg1, s32 arg2);

extern "C" void func_0010B040(void *arg0) {
    func_003768B0(arg0, D_005857DC->unk1748 ^ 1, 0);
}
