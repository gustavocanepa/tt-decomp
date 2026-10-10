struct S {
    int unk0;
};

extern void func_0050E1A8(S *);
extern int D_005B3370;

void func_001FC7C0(S *arg0, int arg1)
{
    arg1 = arg1 & 1;
    arg0->unk0 = (int)&D_005B3370;
    if (arg1)
    {
        func_0050E1A8(arg0);
        return;
    }
}
