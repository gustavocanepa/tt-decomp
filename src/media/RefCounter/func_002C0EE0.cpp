struct S {
    char pad[0x4];
    int unk4;
};

extern void func_002BDA70(S *, int, int);
extern int D_005C7A18;

void func_002C0EE0(S *arg0, int arg1)
{
    arg0->unk4 = (int)&D_005C7A18;
    if (arg1 & 1) {
        return func_002BDA70(arg0, 8, 4);
    }
}
