#include "types.h"

struct Obj {
    void *unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
};

extern "C" char D_005D9A58[];

extern "C" void func_00419A10(Obj *arg0, s32 arg1) {
    arg0->unk4 = arg1;
    arg0->unk0 = D_005D9A58;
    arg0->unk8 = 0;
    arg0->unkC = 0;
    arg0->unk10 = 0;
    arg0->unk14 = 0;
    arg0->unk18 = 0;
    arg0->unk1C = 0;
    arg0->unk20 = 0;
    arg0->unk24 = 0;
}
