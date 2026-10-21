typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Inner {
    char pad0[0xDC];
    s32 fDC;
    char pad1[0xF0 - 0xE0];
    s32 fF0;
};

struct Obj {
    char pad0[0x64];
    char *vtbl;
    char pad1[0x6C - 0x68];
    Inner *p6C;
    char pad2[0xF1D4 - 0x70];
    s32 fF050;
};

extern "C" char D_005DF600[];
extern "C" void func_0011FAD0(void *);
extern "C" void func_0011FAE0(int);
extern "C" void func_0010B458(char *);
extern "C" void func_0033A158(void *, int, int);
extern "C" void func_003715E0(void *, int);

extern "C" void func_001147F0(Obj *o) {
    char *base = (char *)o;
    Inner *i = o->p6C;
    s32 saved = o->fF050;
    s32 one = 1;
    o->fF050 = 0;
    i->fDC = 1;
    i->fF0 = 1;
    func_003715E0(o, 1);
    func_0033A158(o, 4, 1);
    func_0011FAD0(o);
    func_0011FAE0(1);
    func_0010B458(D_005DF600);
    func_0011FAD0(0);
    VEntry *e = (VEntry *)(o->vtbl + 0x2D0);
    e->fn(base + e->delta);
    func_003715E0(o, 0);
    i->fF0 = 0;
    i->fDC = 0;
    o->fF050 = saved;
}
