#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *);
};

struct Target {
    int m0;
    char *vtbl;
};

struct H {
    Target *p;
    int pad[3];
};

struct T {
    void *v;
    void *get() { return v; }
    int pad[3];
};

extern "C" void func_001FBE10(H *h, void *a);
extern "C" void func_001FBDB8(H *h, int in_chrg);
extern "C" void func_001DF250(T *t, void *a);
extern "C" void func_001DF1F8(T *t, int in_chrg);

extern "C" void func_001FC100(void *self, void *a1, int count, void *arg) {
    if (count > 0) {
        H h;
        func_001FBE10(&h, a1);
        T t;
        func_001DF250(&t, arg);
        Target *o = h.p;
        VEntry *e = (VEntry *)(o->vtbl + 0x1C8);
        e->fn((char *)o + e->delta, t.get());
        func_001DF1F8(&t, 2);
        func_001FBDB8(&h, 2);
    }
}
