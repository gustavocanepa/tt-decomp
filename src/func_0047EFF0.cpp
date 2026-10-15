typedef int s32;

extern char D_005DA788[];

struct func_0047EFF0_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
};

extern "C" void func_0047EFF0(struct func_0047EFF0_arg0 *arg0) {
    s32 *p = &arg0->unk18;
    arg0->unk20 = (s32)D_005DA788;
    arg0->unk10 = 1;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unkC = 0;
    arg0->unk14 = 0;
    arg0->unk0 = 0;
    p[0] = 0;
    p[1] = 0;
}
