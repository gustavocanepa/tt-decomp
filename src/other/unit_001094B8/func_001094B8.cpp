struct S {
    int unk0;
};

extern void func_0050E1A8(S *);
extern int D_005A4F28;

void func_001094B8(S *arg0, int arg1)
{
    arg1 = arg1 & 1;
    arg0->unk0 = (int)&D_005A4F28;
    if (arg1)
    {
        func_0050E1A8(arg0);
        return;
    }
}
