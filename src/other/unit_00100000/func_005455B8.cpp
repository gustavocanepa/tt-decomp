struct S {
    int unk0;
};

extern void func_0050E1A8(S *);
extern int D_005AE978;

void func_005455B8(S *arg0, int arg1)
{
    arg1 = arg1 & 1;
    arg0->unk0 = (int)&D_005AE978;
    if (arg1)
    {
        func_0050E1A8(arg0);
        return;
    }
}
