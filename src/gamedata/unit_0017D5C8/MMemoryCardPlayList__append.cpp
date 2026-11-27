/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Entry {
    short delta;
    short index;
    void *fn;
};

struct Base {
    char pad0[0x4C];
    Entry *vt;
};

struct Inner {
    char pad[0x10];
    Base *f10;
};

struct Hdr {
    char pad[0x10];
    s32 f10;
    char pad14[4];
    s32 f18;
};

extern char D_00520A30[];
extern char D_005206C0[];
extern "C" void func_00151A90(void *, int);
extern "C" s32 func_00151AE8(void *, void *);
extern "C" void func_001596F8(void *, int) throw();
extern "C" void func_00159750(void *, void *) throw();
extern "C" Hdr *func_00198540(s32, void *);
extern "C" void func_0029CEF0(void *, int);
extern "C" void func_0029EA18(void *, int);
extern "C" void func_002C0FE8(void *);
extern "C" void func_002C1050(void *);
extern "C" void *GT4MC__FileGT4GameData__loadInstance(void *, void *, int, void *, void *, void *);

extern "C" void MMemoryCardPlayList__append(void **out, void *input, int count, void *arg) {
    Hdr *a[4];
    Hdr *ok = 0;
    func_00159750(a,input);
    if (count > 0) {
        Inner *inner[4];
        Inner **h=inner;

    func_00151AE8(h, arg);
    Base *b = h[0]->f10;
    s32 v = a[0]->f10;
    void *cast;
    if (b != 0) {
        Entry *e = b->vt;
        cast = GT4MC__FileGT4GameData__loadInstance(e->fn, D_00520A30, 0, (char *)b + e->delta, D_005206C0, b);
    } else {
        cast = 0;
    }
    ok = func_00198540(v, cast);
    if (ok != 0) a[0]->f18 = 1;
    func_00151A90(h, 2);

    }
    Inner *sp10[4];
    Inner **p=sp10;
    func_0029EA18(p, ok != 0);
    if (out != (void **)p) {
        void *nv = p[0];
        if (nv != 0)
            func_002C0FE8(nv);
        if (*out != 0)
            func_002C1050(*out);
        *out = nv;
    }
    func_0029CEF0(p, 2);
    func_001596F8(a, 2);
}
