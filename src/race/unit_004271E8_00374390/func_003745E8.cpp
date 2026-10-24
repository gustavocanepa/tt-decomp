#include "types.h"

struct Obj {
    char pad[0x1780];
    s32 unk1780;
};

extern "C" void func_003750E0(Obj *arg0, s32 arg1);

extern "C" void func_003745E8(Obj *arg0) {
    s32 temp_s1 = arg0->unk1780;
    arg0->unk1780 = 1;
    func_003750E0(arg0, 1);
    arg0->unk1780 = temp_s1;
}
