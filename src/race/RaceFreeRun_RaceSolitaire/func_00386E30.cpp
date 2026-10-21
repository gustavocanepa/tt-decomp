#include "types.h"

struct Obj {
    char pad[0x1A20];
    s32 unk1AA0;
};

extern "C" void AutomobileControlRecord__Manager__save(s32 arg0, struct Obj *arg1, s32 arg2);

extern "C" void func_00386E30(s32 arg0, struct Obj *arg1) {
    arg1->unk1AA0 = 1;
    AutomobileControlRecord__Manager__save(arg0 + 0xE620, arg1, 1);
}
