/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ref { char *p; int pad[3]; };
struct Cb { void *vtbl; void *fn; char *p; int pad; };

extern char D_005A7A18[];
extern char D_005A7A38[];

extern "C" void func_00151A90(void *arg0, int arg1) throw();
extern "C" void func_00151AE8(void *arg0, void *arg1) throw();
extern "C" void func_001564E0(void *arg0, int arg1);
extern "C" void func_00156538(void *arg0, void *arg1);
extern "C" int func_0019BA60(void *a, void *b, void *c);
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

static inline void initCb(Cb *t, Ref *b) {
    t->vtbl = D_005A7A18;
    t->fn = (void *)func_00151C90;
    t->p = b->p + 0x10;
}

extern "C" void MMemoryCardFile__remove(Ref *out, void *a1, int count, void *a3) {
    if (count > 0) {
        Ref a;
        Ref b;
        Cb c;
        Ref r;
        func_00151AE8(&a, a1);
        Ref *pb = &b;
        func_00156538(pb, a3);
        Cb *pc = &c;
        void *fnp = (void *)func_00151C90;
        char *t = pb->p + 0x10;
        pc->vtbl = D_005A7A18;
        c.fn = fnp;
        c.p = t;
        func_0029EA18(&r, func_0019BA60(*(void **)(a.p + 0x10), *(void **)(pb->p + 0x1C), pc) != 0);
        assign(out, &r);
        func_0029CEF0(&r, 2);
        pc->vtbl = D_005A7A38;
        func_001564E0(pb, 2);
        func_00151A90(&a, 2);
    } else {
        Ref r;
        func_0029EA18(&r, 0);
        assign(out, &r);
        func_0029CEF0(&r, 2);
    }
}
