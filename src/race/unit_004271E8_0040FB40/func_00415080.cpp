/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Buf { u8 *p; unsigned size; int pad[2]; };
extern "C" int func_00414830(void *);
extern "C" void *func_00414B78(void *, void *, void *, void *);
extern "C" void *func_004F64C4(void *, const void *, unsigned);
extern "C" void *func_004F6678(void *, int, unsigned);

extern "C" void func_00415080(Buf *src) {
    Buf a, b, c;
    Buf *pb = &b;
    u8 ten = 10;
    Buf *pc = &c;
    unsigned n = src->size;
    unsigned sz = (n + 15) >> 4 << 4;
    a.size = n;
    a.p = (u8 *)__builtin_alloca(sz);
    pb->p = (u8 *)__builtin_alloca(sz);
    b.size = n;
    pc->p = (u8 *)__builtin_alloca(sz);
    c.size = n;
    func_004F6678(pb->p, 0, b.size);
    pb->p[0] = ten;
    pb->p[1] = 0;
    pb->p[2] = 0;
    pb->p[3] = 0;
    func_004F64C4(a.p, src->p, a.size);
    func_00414B78(src, &a, pb, pc);
    func_00414830(pc);
}
