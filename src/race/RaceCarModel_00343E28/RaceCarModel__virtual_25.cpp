#include "types.h"

struct Obj {
    s32 unk0;
};

extern "C" void func_0041BED8(void *arg0, s32 arg1, s32 arg2);

extern "C" void RaceCarModel__virtual_25(Obj *arg0, s32 arg1) {
    func_0041BED8((char *)arg0 + 0x18, arg0->unk0, arg1);
}
