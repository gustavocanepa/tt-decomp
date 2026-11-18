#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
};

struct Obj {
    VEntry *vtbl;
};

struct Sub {
    char pad[0x500];
    VEntry e;
};

struct Owner {
    char pad[0x64];
    Sub *p;
};

typedef Obj *(*GetFn)(void *self, s32 arg);
typedef void (*SetFn)(void *self, s32 arg);

extern "C" void func_0033FBC8(Owner *arg0, s32 arg1) {
    VEntry *e = &arg0->p->e;
    Obj *r = ((GetFn)e->fn)((char *)arg0 + e->delta, arg1);
    VEntry *f = &r->vtbl[28];
    ((SetFn)f->fn)((char *)r + f->delta, arg1);
}
