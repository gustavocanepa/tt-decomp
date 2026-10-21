typedef unsigned long u64;
struct Entry { short delta, index; int (*fn)(void *, int); };
struct Entry5 { short delta, index; void (*fn)(void *, char *, int, int, int); };
struct Obj { char *vtbl; };
struct Tgt { char *vtbl; char pad[0x164]; u64 u168; };
extern "C" void func_00321B08(Tgt *, char *, char *, char *, char *);
extern "C" void func_003A7880(char *, int);
extern "C" int func_003A8A20(char *, char *, int);
static inline Tgt *VCALL(Obj *self, int idx) {
    Entry *e = (Entry *)(self->vtbl + 0xE0);
    return (Tgt *)e->fn((char *)self + e->delta, idx);
}
extern "C" void func_0031E1A8(Obj *self, char *ctx, int a2, int idx, unsigned flags, int *out) {
    int r = 0;
    char *base = (char *)self + idx * 0x1B4;
    char *s2 = base + 0x10;
    char *fp = base + 0xF8;
    int v = *(int *)(s2 + 0x1A4);
    if (v >= 0) {
        r = 1;
        func_003A7880(s2, v);
    }
    signed char c = fp[0x1F];
    if (c != 0) {
        if (func_003A8A20(ctx, s2, c > 0)) r = 1;
    }
    if (r) {
        flags |= 2;
        out[1] = 1;
    }
    int hit = 0;
    if (flags & 2) hit = 1;
    if (flags & 4) hit = 1;
    if (hit) {
        Tgt *t = *(Tgt **)(s2 + 0x16C);
        Entry5 *e = (Entry5 *)(t->vtbl + 0x148);
        e->fn((char *)t + e->delta, s2, *(int *)((char *)t + 0x180), *(int *)(ctx + 0xBC), *(unsigned char *)((char *)t + 0x1D0));
        t->u168 &= 0xFFFFFFFF00FFFFFFul;
    }
    Tgt *p = VCALL(self, idx);
    func_00321B08(p, ctx, fp, s2, (char *)self + 0xA80);
    if (hit)
        p->u168 &= 0xFFFFFFFF00FFFFFFul;
}
