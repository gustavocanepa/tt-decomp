extern "C" void *RaceDisplayEventBase__structor_0(void *arg0);
extern "C" char D_005CFBA0[];

struct func_00358B80_arg0 {
    char pad0[0x4];
    void *unk4;
    int unk8;
    int unkC;
};

extern "C" void func_00358B80(struct func_00358B80_arg0 *arg0)
{
    RaceDisplayEventBase__structor_0(arg0);
    arg0->unkC = 0;
    arg0->unk8 = 0;
    arg0->unk4 = D_005CFBA0;
}
