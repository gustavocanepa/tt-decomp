#include "types.h"

struct Obj {
    s32 unk0;
};

extern "C" void func_0041CA50(void *arg0, s32 arg1, s32 arg2, s32 arg3);

extern "C" void RaceCarModel__virtual_27(Obj *arg0, s32 arg1, s32 arg2) {
    func_0041CA50((char *)arg0 + 0x18, arg0->unk0, arg1, arg2);
}
