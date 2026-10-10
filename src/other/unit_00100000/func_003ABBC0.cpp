struct S {
    char pad[0x40];
    int unk0;
};

extern void func_0050E1A8(S *);
extern int D_005D6E60;

void func_003ABBC0(S *arg0, int arg1)
{
    arg1 = arg1 & 1;
    arg0->unk0 = (int)&D_005D6E60;
    if (arg1)
    {
        func_0050E1A8(arg0);
        return;
    }
}
