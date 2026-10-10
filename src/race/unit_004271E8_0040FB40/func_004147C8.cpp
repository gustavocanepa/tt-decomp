struct Obj {
    int a;
    int b;
};

extern "C" void func_00414460(unsigned char *p, unsigned char *q, int a, int b);

extern "C" void func_004147C8(Obj *o, unsigned char *base, int n)
{
    for (unsigned char *p = base + n - 8; p >= base; p--)
        func_00414460(p, p, o->a, o->b);
}
