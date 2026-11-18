struct Entry { short delta, index; int (*fn)(void *, int); };
struct Entry5 { short delta, index; void (*fn)(void *, char *, int, int, int); };
struct Obj { char *vtbl; };
struct Tgt { char *vtbl; };
extern "C" void func_00321B08(int, char *, char *, char *, char *);
extern "C" void func_003A7880(char *, int);
static inline int VCALL(Obj *self, int idx) {
    Entry *e = (Entry *)(self->vtbl + 0xE0);
    return e->fn((char *)self + e->delta, idx);
}
extern "C" void func_0031E330(Obj *self, char *ctx, int a2, int idx, unsigned flags, int *out) {
    int r = 0;
    char *base = (char *)self + idx * 0x1B4;
    char *s1 = base + 0x10;
    char *fp = base + 0xF8;
    int v = *(int *)(s1 + 0x1A4);
    if (v >= 0) {
        func_003A7880(s1, v);
        r = 1;
    }
    if (r) {
        flags |= 2;
        out[1] = 1;
    }
    int hit = 0;
    if (flags & 2) hit = 1;
    if (flags & 4) hit = 1;
    if (hit) {
        Tgt *t = *(Tgt **)(s1 + 0x16C);
        Entry5 *e = (Entry5 *)(t->vtbl + 0x148);
        e->fn((char *)t + e->delta, s1, *(int *)((char *)t + 0x180), *(int *)(ctx + 0xBC), *(unsigned char *)((char *)t + 0x1D0));
    }
    int p = VCALL(self, idx);
    func_00321B08(p, ctx, fp, s1, (char *)self + 0xA80);
}
