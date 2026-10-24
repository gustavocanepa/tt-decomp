#include "types.h"

struct S_001056A0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    f32 unk20;
    f32 unk24;
    s32 unk28;
    s32 unk2C;
};

extern "C" void func_0046FF48(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern "C" void func_004707F0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern "C" void func_00473DF0(s32 arg0);
extern "C" void func_004704E0(s32 arg0);
extern "C" void func_004705E0(f32 arg0, f32 arg1);

extern "C" void func_00104C88(S_001056A0 *arg0) {
    func_0046FF48(arg0->unk0, arg0->unk4, arg0->unk8, arg0->unkC);
    func_004707F0(arg0->unk10, arg0->unk14, arg0->unk18, arg0->unk1C);
    func_00473DF0(arg0->unk2C);
    func_004704E0(arg0->unk28);
    func_004705E0(arg0->unk20, arg0->unk24);
}
