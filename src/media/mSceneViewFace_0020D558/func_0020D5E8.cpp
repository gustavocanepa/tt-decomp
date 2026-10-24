#include "types.h"

struct Obj {
    char pad[0xAC];
    s32 unk98;
};

extern "C" void func_0020D5E8(Obj *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unk98;
    v = v & ~0x20000;
    v = v | (temp << 17);
    arg0->unk98 = v;
}
