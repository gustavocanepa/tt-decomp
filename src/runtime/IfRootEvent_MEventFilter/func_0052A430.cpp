struct S {
    int unk0;
};

extern void func_0050E1A8(S *);
extern int D_005B1788;

void func_0052A430(S *arg0, int arg1)
{
    arg1 = arg1 & 1;
    arg0->unk0 = (int)&D_005B1788;
    if (arg1)
    {
        func_0050E1A8(arg0);
        return;
    }
}
