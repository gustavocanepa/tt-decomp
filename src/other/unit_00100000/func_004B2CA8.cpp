struct S {
    char pad[0x10];
    int unk0;
};

extern void func_0050E1A8(S *);
extern int D_005DAEC8;

void func_004B2CA8(S *arg0, int arg1)
{
    arg1 = arg1 & 1;
    arg0->unk0 = (int)&D_005DAEC8;
    if (arg1)
    {
        func_0050E1A8(arg0);
        return;
    }
}
