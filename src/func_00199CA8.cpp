/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blk { long q[8]; };
struct Ent { short off; short pad; int (*fn)(void *); };
struct VT { char p[0x38]; Ent e; };
struct Sub { VT *vptr; };
struct Arg1 { char p[0x30]; Sub *sub; };
struct Res { long pad; Blk b; };
extern "C" int func_0019CC78(void *);
extern "C" int func_00198E80(void *, int) throw();
extern "C" Res *func_00199B30(int) throw();

struct H { Res *p; H() {} H(const H &h) : p(h.p) {} };
static inline int test(Sub *s) { Ent *e = &s->vptr->e; return e->fn((char *)s + e->off); }

extern "C" H func_00199CA8(Arg1 *a1, char *a2) {
    int kind = 0x44;
    if (test(a1->sub) == 0)
        kind = func_0019CC78(a2 + 0x1C);
    Res *r = 0;
    if (func_00198E80(a1, kind) != 0) {
        r = func_00199B30(kind);
        if (r != 0)
            r->b = *(Blk *)a2;
    }
    H h;
    h.p = r;
    return h;
}
