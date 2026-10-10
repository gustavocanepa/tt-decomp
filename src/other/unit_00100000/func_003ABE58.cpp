struct S {
    char pad_near0[36];
    int unk0;
};

extern void func_0050E1A8(S *);
extern int D_005D6E48;

void func_003ABE58(S *arg0, int arg1)
{
    arg1 = arg1 & 1;
    arg0->unk0 = (int)&D_005D6E48;
    if (arg1)
    {
        func_0050E1A8(arg0);
        return;
    }
}
