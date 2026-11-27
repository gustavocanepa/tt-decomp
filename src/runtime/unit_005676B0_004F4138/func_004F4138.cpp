/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Req { int w0; int a1; int a0; int rest[3]; };
extern int D_0078B120[];
extern "C" void func_004A59F0();
extern "C" void *func_004F6678(void *, int, unsigned);
extern "C" int func_004FA820(Req *);
extern "C" int func_004F4138(int a0, int a1) {
    Req req;
    int gen;
    int idx;
    int none = -1;
    func_004F6678(&req, 0, 0x18);
    Req *rp = &req;
    rp->a0 = a0;
    rp->a1 = a1;
    while ((idx = func_004FA820(rp)) == none) func_004A59F0();
    gen = D_0078B120[idx];
    gen = (gen + 1) & 0x7FFFFF;
    if (gen == 0) gen = 1;
    D_0078B120[idx] = gen;
    return idx | (gen << 8);
}
