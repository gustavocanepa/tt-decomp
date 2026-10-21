#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void *(*fn)(void *, int);
};

struct Obj {
    char pad0[0x64];
    char *vtbl;
    char pad68[0x3A944 - 0x68];
    int m24EE0;
    int m24EE4;
};

extern "C" void func_0033AE38(Obj *o);
extern "C" void func_0031AAC0(void *p, int a);

extern "C" void func_00371388(Obj *o) {
    func_0033AE38(o);
    if (o->m24EE0 && !o->m24EE4) {
        VEntry *e = (VEntry *)(o->vtbl + 0xD0);
        func_0031AAC0(e->fn((char *)o + e->delta, 0), 0);
    }
}
