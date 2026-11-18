struct Ref { char *p; int pad[3]; };
struct Obj {
    char pad0[0x31C];
    int f2BC;
    Ref r2C0;
};
extern "C" void func_0020B408(void *);
extern "C" void func_001CE620(Ref *, const int &);
extern "C" void func_001CE650(Ref *, int);
extern "C" void func_001C1380(Ref *, const int &);
extern "C" void func_001C13B0(Ref *, int);
extern "C" void func_001CDA78(void *, void *);
extern "C" void func_001CDAA8(void *, void *);
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

extern "C" void func_00260298(Obj *o) {
    char *c = (char *)o;
    Ref t;
    func_0020B408(o);
    o->f2BC = 0;
    func_001CE620(&t, 0);
    assign((Ref *)(c + 0x320), &t);
    func_001CE650(&t, 2);
    func_001CE620(&t, 0);
    assign((Ref *)(c + 0x324), &t);
    func_001CE650(&t, 2);
    *(int *)(c + 0x32C) = 0;
    Ref *d = (Ref *)(c + 0x330);
    func_001C1380(&t, 0);
    assign(d, &t);
    func_001C13B0(&t, 2);
    func_001C1380(&t, 0);
    assign((Ref *)(c + 0x334), &t);
    func_001C13B0(&t, 2);
    func_001CDA78(c + 0xB4, c + 0x344);
    func_001CDAA8(c + 0xB4, c + 0x350);
}
