#include "types.h"

struct Obj {
    char pad[0x2A8];
    s32 unk27C;
    char pad2[0xC];
    f32 unk28C;
    f32 unk290;
    s32 unk294;
};

extern "C" void func_00322B88(Obj *arg0, s32 arg1, f32 fparg0, f32 fparg1) {
    arg0->unk27C = 3;
    arg0->unk28C = fparg0;
    arg0->unk290 = fparg1;
    arg0->unk294 = arg1;
}
