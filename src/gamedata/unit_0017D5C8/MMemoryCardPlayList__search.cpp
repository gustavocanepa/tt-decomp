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
extern "C" void func_001596F8(void *, int);
extern "C" void func_00159750(void *);
extern "C" s32 func_00198660(s32, s32);
extern "C" void func_0029CEF0(void *, int);
extern "C" void func_0029EA18(void *, s32);
extern "C" void func_002C0FE8(void *);
extern "C" void func_002C1050(void *);
extern "C" s32 GT4MC__FileGT4GameData__loadInstance(void *, void *, int, void *, void *, void *);

static inline void store(void **out, Inner **r) {
    if (out != (void **)r) {
        void *nv = r[0];
        if (nv != 0)
            func_002C0FE8(nv);
        if (*out != 0)
            func_002C1050(*out);
        *out = nv;
    }
}

extern "C" void MMemoryCardPlayList__search(void **out, int unused, int count, void *arg) {
    Hdr *a[4];
    func_00159750(a);
    if (count > 0) {
        Inner *h[4];
        Inner *r[4];
        Inner **ph = h;
        func_00151AE8(ph, arg);
        Hdr *a0 = a[0];
        Inner *hh = ph[0];
        Base *b = hh->f10;
        s32 v = a0->f10;
        s32 cast = b ? GT4MC__FileGT4GameData__loadInstance(b->vt->fn, D_00520A30, 0, (char *)b + b->vt->delta, D_005206C0, b) : 0;
        s32 res = func_00198660(v, cast);
        Inner **pr = r;
        func_0029EA18(pr, res);
        store(out, pr);
        func_0029CEF0(pr, 2);
        func_00151A90(ph, 2);
    } else {
        Inner *r[4];
        Inner **pr = r;
        func_0029EA18(pr, -1);
        store(out, pr);
        func_0029CEF0(pr, 2);
    }
    func_001596F8(a, 2);
}
