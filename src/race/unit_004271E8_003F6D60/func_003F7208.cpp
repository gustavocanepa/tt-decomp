#include "types.h"

struct Obj {
    char pad[0xB28];
    s32 unkA68;
    char pad2[0xB2C - 0xB28 - 4];
    u8 unkA6C;
    char pad3[0xC6C - 0xB2C - 1];
    s32 unkBAC;
    u8 unkBB0;
};

extern "C" void func_003F7208(Obj *arg0) {
    arg0->unkBB0 = 0;
    arg0->unkA68 = 0;
    arg0->unkA6C = 0;
    arg0->unkBAC = -1;
}
