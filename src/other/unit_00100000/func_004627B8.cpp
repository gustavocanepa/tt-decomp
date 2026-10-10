struct S {
    char pad[0x98C];
    int unk0;
};

extern void func_0050E1A8(S *);
extern int D_005DA2C8;

void func_004627B8(S *arg0, int arg1)
{
    arg1 = arg1 & 1;
    arg0->unk0 = (int)&D_005DA2C8;
    if (arg1)
    {
        func_0050E1A8(arg0);
        return;
    }
}
