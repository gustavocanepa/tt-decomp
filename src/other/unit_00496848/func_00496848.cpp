typedef int s32;

struct S {
    void *unk0;
    char pad[0xC - 0x4];
    s32 unkC;
    s32 unk10;
};

extern "C" char D_00494E80[];

extern "C" void func_00496848(S *arg0) {
    arg0->unkC = 0;
    arg0->unk10 = 0;
    arg0->unk0 = D_00494E80;
}
