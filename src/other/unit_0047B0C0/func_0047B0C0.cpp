struct S {
    int unk0;
};

extern void func_0050E1A8(S *);
extern int D_005DA438;

void func_0047B0C0(S *arg0, int arg1)
{
    arg1 = arg1 & 1;
    arg0->unk0 = (int)&D_005DA438;
    if (arg1)
    {
        func_0050E1A8(arg0);
        return;
    }
}
