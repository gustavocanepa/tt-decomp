struct S {
    int unk0;
};

extern void func_0050E1A8(S *);
extern int D_005D9D88;

void func_0042F4C0(S *arg0, int arg1)
{
    arg1 = arg1 & 1;
    arg0->unk0 = (int)&D_005D9D88;
    if (arg1)
    {
        func_0050E1A8(arg0);
        return;
    }
}
