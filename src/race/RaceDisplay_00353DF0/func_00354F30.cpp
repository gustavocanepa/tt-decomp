#include "types.h"

struct Obj {
    char pad0[0x4];
    s32 unk4;
    char pad0x8[0x2E - 0x8];
    s8 unk2E;
};

extern "C" void func_003735F0(void *arg0, s32 arg1, s8 arg2);

extern "C" void func_00354F30(Obj *arg0) {
    func_003735F0((char *)arg0 + 0x10C8, arg0->unk4, arg0->unk2E);
}
