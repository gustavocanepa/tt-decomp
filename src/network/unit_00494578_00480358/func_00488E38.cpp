/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEnt {
    short adj;
    short pad;
    int (*fn)(char *, ...);
};
struct Slot {
    char pad[8];
    void *data;
};
struct Obj {
    char pad0[4];
    void *cache;
    char pad8[0x48];
    int f50;
    char pad54[0x14];
    int f68;
    char pad6C[0xC];
    char *vt;
};
extern "C" int func_00487850(void *, int) throw();
extern "C" void func_00487A00(void *, Slot *) throw();
extern "C" int func_00488918(Obj *, int) throw();
extern "C" int func_00488BF8(Obj *, int, int, void **, int *) throw();
extern "C" void *func_004F6678(void *, int, int);

static inline VEnt *ve(Obj *o, int off) {
    return (VEnt *)(o->vt + off);
}
#define VCALL(o, off, ...) (ve(o, off)->fn((char *)(o) + ve(o, off)->adj, __VA_ARGS__))

extern "C" int func_00488E38(Obj *o, int s0, void **arg2, int *arg3) {
    if (s0 == 0) {
        return VCALL(o, 0x30, arg2, arg3);
    }
    int s2 = 0;
    while (VCALL(o, 8, s0) == 0) {
        int r = func_00488BF8(o, func_00488918(o, s0), o->f68, arg2, arg3);
        if (r != 0) return r;
        s2 = s0;
        s0 = VCALL(o, 0x18, s2);
        if (s0 < 0) return s0;
    }
    s0 = VCALL(o, 0x40, s2, 1);
    if (s0 < 0) return s0;
    int s3 = func_00488918(o, s0);
    Slot *sl = 0;
    s0 = o->f68 - 1;
    for (;;) {
        if (s0 < 0) {
            break;
        }
        sl = (Slot *)func_00487850(o->cache, s3 + s0);
        if (sl == 0) return -5;
        func_004F6678(sl->data, 0, o->f50);
        if (s0 == 0) {
            break;
        }
        func_00487A00(o->cache, sl);
        s0--;
    }
    *arg2 = sl;
    *arg3 = (int)sl->data;
    return 0;
}
