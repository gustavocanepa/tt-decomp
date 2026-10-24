/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ref { char *p; int pad[3]; };
struct Cb { void *vtbl; void *fn; char *p; int pad; };

extern char D_005A7A18[];
extern char D_005A7A38[];

extern "C" void func_001564E0(void *arg0, int arg1);
extern "C" void func_00156538(void *arg0, void *arg1);
extern "C" int func_0019BC90(void *a, void *b);
extern "C" void func_00151C90(void *);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_0029EA18(void *arg0, int arg1);
extern "C" void func_002C0FE8(void *p);
extern "C" void func_002C1050(void *p);

static inline void assign(Ref *d, Ref *s) {
    if (d != s) {
        char *q = s->p;
        if (q) func_002C0FE8(q);
        if (d->p) func_002C1050(d->p);
        d->p = q;
    }
}

extern "C" void MMemoryCardFile__format(Ref *out, void *a1, int count, void *a3) {
    if (count > 0) {
        Ref b;
        Cb c;
        Ref r;
        func_00156538(&b, a3);
        Cb *pc = &c;
        void *fnp = (void *)func_00151C90;
        char *t = b.p + 0x10;
        pc->vtbl = D_005A7A18;
        c.fn = fnp;
        c.p = t;
        func_0029EA18(&r, func_0019BC90(*(void **)(b.p + 0x1C), pc) != 0);
        assign(out, &r);
        func_0029CEF0(&r, 2);
        pc->vtbl = D_005A7A38;
        func_001564E0(&b, 2);
    } else {
        Ref r;
        func_0029EA18(&r, 0);
        assign(out, &r);
        func_0029CEF0(&r, 2);
    }
}
