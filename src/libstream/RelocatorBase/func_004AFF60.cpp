typedef int s32;

struct S0057A070 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    void *unk10;
};

extern "C" char D_005DAE60[];

extern "C" void func_004AFF60(struct S0057A070 *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unk10 = D_005DAE60;
    arg0->unkC = 0;
}
