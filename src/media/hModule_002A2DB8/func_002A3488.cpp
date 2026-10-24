#include "types.h"

extern "C" void func_002A27C8(void *arg0, void *arg1);
extern "C" void func_002ADC48(void *arg0, void *arg1);
extern "C" void func_002ADBF0(void *arg0, int arg1);
extern "C" void func_002A2770(void *arg0, int arg1);
extern "C" u8 *func_002AFE68(u8 *arg0);

struct VEntry { s16 delta; s16 index; void (*fn)(void *, void *); };
struct VObj { char pad0[4]; char *vtbl; };

struct A {
    VObj *p;
    int pad[3];
};
struct B {
    int v[4];
};
static inline int get(B *b) { return b->v[0]; }

extern "C" void func_002A3488(void *arg0, void *arg1, int count, void *name)
{
    if (count == 1) {
        A a;
        B b;
        func_002A27C8(&a, arg1);
        func_002ADC48(&b, name);
        VObj *o = a.p;
        VEntry *e = (VEntry *)(o->vtbl + 0x1B0);
        char *self = (char *)o + e->delta;
        u8 *arg = func_002AFE68((u8 *)get(&b));
        e->fn(self, arg);
        func_002ADBF0(&b, 2);
        func_002A2770(&a, 2);
    }
}
