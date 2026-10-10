struct S {
    char pad[0x4];
    int unk4;
};

extern void func_0050E1A8(S *);
extern int D_005D8450;

void func_003F4078(S *arg0, int arg1)
{
    arg1 = arg1 & 1;
    arg0->unk4 = (int)&D_005D8450;
    if (arg1)
    {
        func_0050E1A8(arg0);
        return;
    }
}
