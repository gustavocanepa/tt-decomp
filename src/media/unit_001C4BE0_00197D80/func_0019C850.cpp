/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct VE { short off; short pad; s32 (*fn)(void *, ...); };
struct A { char pad[0x4C]; char *vt; };
struct B { char *vt; };
struct C { s32 f0; s32 f4; s32 f8; };
extern "C" void *func_004F6574(s32, s32, s32) throw();
extern "C" void func_005203E8(C *, s32, s32, char *);
#define VCALL(o, off, ...) (((VE *)((o)->vt + (off)))->fn((char *)(o) + ((VE *)((o)->vt + (off)))->off, __VA_ARGS__))
static inline s32 callA(A *a, char *buf) {
    VE *e = (VE *)(a->vt + 0x78);
    return e->fn((char *)a + e->off, buf);
}
static inline s32 callB(B *b, int slot) {
    VE *e = (VE *)(b->vt + slot);
    return e->fn((char *)b + e->off);
}
static inline s32 readB(B *b, char *buf, s32 p, s32 n) {
    VE *e = (VE *)(b->vt + 0x90);
    return e->fn((char *)b + e->off, buf, p, n, 0);
}
extern "C" s32 func_0019C850(A *a, B *b, C *c) {
    char buf[0x50];
    char z;
    s32 flag = 0;
    callA(a, buf);
    VE *f = (VE *)(b->vt + 0x98);
    s32 n = f->fn((char *)b + f->off, buf);
    VE *g = (VE *)(b->vt + 0x28);
    if (g->fn((char *)b + g->off) != 0 || n < 0) flag = 1;
    if (flag) return ((n ^ -2) == 0) ? 2 : 1;
    s32 s1 = c->f8;
    s32 v = c->f4;
    n = (n + 0x3F) & ~0x3F;

    z = 0;
    char *pz = &z;
    s32 s3 = v + n;
    u32 rem = s1 - v;
    if ((u32)n < rem) {
        func_004F6574(s3, s1, 0);
        c->f8 = c->f8 - (s1 - s3);
    } else {
        func_005203E8(c, s1, n - rem, pz);
    }
    readB(b, buf, c->f4, n);
    return callB(b, 0x28) != 0;
}
