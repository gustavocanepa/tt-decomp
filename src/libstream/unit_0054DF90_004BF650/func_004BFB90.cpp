/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Names { const char *n[6]; };
extern "C" const Names D_00613390;
extern "C" char *func_004F8588(char *dst, const char *src) throw();
extern "C" void func_004C9F00(unsigned int i, char *dst, int n);
extern "C" void func_004BFB90(unsigned int i, char *dst, int n)
{
    Names t = D_00613390;
    if (i < 6)
        func_004F8588(dst, t.n[i]);
    else
        func_004C9F00(i, dst, n);
}
