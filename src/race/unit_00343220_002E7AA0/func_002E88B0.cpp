#include "types.h"

struct Obj {
    char pad0[0x5C];
    s32 unk5C;
    s32 unk60;
};

extern "C" void func_002E7B48(struct Obj *arg0, s32 arg1, s32 arg2);

extern "C" void func_002E88B0(struct Obj *arg0, s32 arg1) {
    s32 temp_a1 = arg0->unk5C + (arg1 << 16);
    arg0->unk60 = temp_a1;
    func_002E7B48((struct Obj *)((char *)arg0 + 8), temp_a1 + 0x4994, 0xB664);
}
