#include "types.h"

struct Obj {
    u8 pad[0x1CE8];
    s32 unk1D00;
};

extern "C" void func_001E4DE0(Obj *arg0);

extern "C" void func_001E4C78(Obj *arg0) {
    func_001E4DE0(arg0);
    arg0->unk1D00 = arg0->unk1D00 - 1;
}
