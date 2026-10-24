struct S {
    int unk0;
};

extern void func_002BDA70(S *, int, int);
extern int D_005C7458;

void func_0054E360(S *arg0, int arg1)
{
    arg0->unk0 = (int)&D_005C7458;
    if (arg1 & 1) {
        return func_002BDA70(arg0, 8, 4);
    }
}
