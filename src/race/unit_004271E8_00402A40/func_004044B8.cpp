#include "types.h"

struct Obj {
    char pad[0x10];
    s8 unk10;
    s8 unk11;
};

extern "C" void func_004044B8(s32 arg0, u32 arg1, s32 arg2) {
    if (arg1 < 3U) {
        ((Obj *)arg0)->unk10 = 0;
        ((Obj *)(arg1 + arg0))->unk11 = arg2;
    }
}
