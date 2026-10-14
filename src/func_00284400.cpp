/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x30]; unsigned long bits; };
struct Handle { Obj *p; int pad[3]; };
extern "C" void func_00283D10(void *, int) throw();
extern "C" void *func_00283D68(void *, void *) throw();
extern "C" void func_0029CEF0(void *, int);
extern "C" void func_0029CF48(void *, void *);
extern "C" int func_0029E9F0(void *);
extern "C" void func_0029EA18(void *, int);
extern "C" void func_002C0FE8(int);
extern "C" void func_002C1050(int);
extern "C" void MStorageEntry__get_size(int *dst, void *src, int n, void *value) {
    Handle a;
    int b4[4];
    int shift = 0;
    if (n > 0) {
        func_0029CF48(&a, value);
        shift = func_0029E9F0(a.p);
        func_0029CEF0(&a, 2);
    }
    func_00283D68(&a, src);
    int *b = b4;
    func_0029EA18(b, (int)(a.p->bits >> shift));
    if (dst != b) {
        int v = *b;
        if (v) func_002C0FE8(v);
        int old = *dst;
        if (old) func_002C1050(old);
        *dst = v;
    }
    func_0029CEF0(b, 2);
    func_00283D10(&a, 2);
}
