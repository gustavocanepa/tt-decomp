/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef signed char s8;

struct Obj;
struct VEnt {
    short adj;
    short pad;
    s32 (*fn)(Obj *);
};
struct VTab {
    char pad[0x68];
    VEnt e;
};
struct Obj {
    s32 pad0;
    VTab *vt;
};

struct Hdr {
    char pad[0x10];
    s32 v10;
};

struct Owned {
    char pad[0x14];
    s32 f14;
};

extern "C" void func_00151A90(void *, int);
extern "C" void func_001563C8(void *, void *);
extern "C" void func_001596F8(void *, int) throw();
extern "C" void func_00159750(void *) throw();
extern "C" s8 func_0019CC78(void *);
extern "C" void *func_00198600(s32, int, void *);
extern "C" char *func_00199B30(int);
extern "C" void func_002C0FE8(void *);
extern "C" void func_002C1050(void *);
extern "C" char *func_004F7B74(char *, const char *);

extern "C" void func_00159E80(Owned **out, int unused, int count, Obj **pobj) {
    Hdr *a[4];
    char sp10[0x40];
    Owned *sp50[4];
    func_00159750(a);
    if (count > 0) {
        Obj *o = *pobj;
        VEnt *e = &o->vt->e;
        int idx = e->fn((Obj *)((char *)o + e->adj));
        if (idx >= 0) {
            Hdr *h = a[0];
            char *pt = sp10;
            func_00198600(h->v10, idx, pt);
            char *s = func_00199B30(func_0019CC78(pt));
            if (s != 0) {
                func_004F7B74(s + 0x24, pt);
                Owned **ps = sp50;
                func_001563C8(ps, s);
                ps[0]->f14 = 1;
                if (out != ps) {
                    Owned *nv = ps[0];
                    if (nv != 0)
                        func_002C0FE8(nv);
                    if (*out != 0)
                        func_002C1050(*out);
                    *out = nv;
                }
                func_00151A90(ps, 2);
            }
        }
    }
    func_001596F8(a, 2);
}
