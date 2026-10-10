struct Names { const char *n[4]; };
extern "C" const Names D_006134E8;
extern "C" char *func_004F8588(char *dst, const char *src);
extern "C" void func_004C9F00(unsigned int i, char *dst, int n);

extern "C" void func_004C2F58(unsigned int i, char *dst, int n)
{
    Names t = D_006134E8;
    if (i < 4)
        func_004F8588(dst, t.n[i]);
    else
        func_004C9F00(i, dst, n);
}
