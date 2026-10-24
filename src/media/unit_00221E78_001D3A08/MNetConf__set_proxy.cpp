#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
};

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, const char *);
};

struct VObj {
    char pad0[4];
    char *vtbl;
};

struct A {
    VObj *p;
    s32 pad[3];
};

struct B {
    s32 v[4];
};

static inline s32 get(B *b) {
    return b->v[0];
}

extern char D_005E9530[];

extern "C" void func_001D3548(void *arg0, int arg1);
extern "C" void func_001D35A0(void *arg0, void *arg1);
extern "C" void func_002ADBF0(void *arg0, int arg1);
extern "C" void func_002ADC48(void *arg0, void *arg1);
extern "C" u8 *func_002AFE68(u8 *arg0);

extern "C" void MNetConf__set_proxy(void *arg0, void *arg1, s32 count, void *name) {
    if (count > 0) {
        A a;
        B b;
        func_001D35A0(&a, arg1);
        func_002ADC48(&b, name);
        VObj *o = a.p;
        VEntry *e = (VEntry *)(o->vtbl + 0x258);
        char *self = (char *)o + e->delta;
        Str *s = (Str *)func_002AFE68((u8 *)get(&b));
        const char *v = D_005E9530;
        s32 len = ((Rep *)s->p)[-1].len;
        if (len != 0) {
            s->p[len] = 0;
            v = s->p;
        }
        e->fn(self, v);
        func_002ADBF0(&b, 2);
        func_001D3548(&a, 2);
    }
}
