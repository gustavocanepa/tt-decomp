/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ref { char *p; int pad[3]; };

extern "C" void func_00290B00(Ref *, void *, int) throw();
extern "C" void func_00290DB0(void *, Ref *) throw();
extern "C" int func_00291638(void *, int, Ref *) throw();
extern "C" void func_002A2740(void *, const int &);
extern "C" void func_002A2758(void *, Ref *);
extern "C" void func_002A2770(Ref *, int);
extern "C" void func_002A2C48(Ref *, int);
extern "C" void func_002C0FE8(void *);
extern "C" void func_002C1050(void *);

static inline void assign(Ref *d, Ref *s) {
    if (d != s) {
        char *q = s->p;
        if (q) func_002C0FE8(q);
        if (d->p) func_002C1050(d->p);
        d->p = q;
    }
}

extern "C" void *func_00291F58(void *a0, void *a1, int a2) {
    Ref r0;
    Ref u;
    func_00290B00(&r0, a1, a2);
    if (r0.p != 0 || (func_002A2C48(&u, a2), assign(&r0, &u), func_002A2770(&u, 2), func_00290DB0(a1, &r0), func_00291638(a1, a2, &r0) != 0)) {
        func_002A2758(a0, &r0);
        func_002A2770(&r0, 2);
    } else {
        func_002A2740(a0, 0);
        func_002A2770(&r0, 2);
    }
    return a0;
}
