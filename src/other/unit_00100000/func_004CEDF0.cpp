struct S {
    char pad_near0[104];
    int unk0;
};

extern void func_0050E1A8(S *);
extern int D_005DB3E0;

void func_004CEDF0(S *arg0, int arg1)
{
    arg1 = arg1 & 1;
    arg0->unk0 = (int)&D_005DB3E0;
    if (arg1)
    {
        func_0050E1A8(arg0);
        return;
    }
}
