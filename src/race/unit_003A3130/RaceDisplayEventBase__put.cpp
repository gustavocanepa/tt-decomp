struct VEntry {
    short delta;
    short index;
    int (*fn)(void *);
};
struct VObj {
    int m0;
    VEntry *vtbl;
};
static inline int vcall(VObj *o, int slot)
{
    VEntry *e = &o->vtbl[slot];
    return e->fn((char *)o + e->delta);
}
struct Target { char pad[0xF4]; char mF4[4]; };
extern "C" void func_0036C908(void *p, int a, int b, int n);

extern "C" void RaceDisplayEventBase__put(VObj *o, Target *t)
{
    int a = vcall(o, 1);
    int b = vcall(o, 2);
    func_0036C908(t->mF4, a, b, 2);
}
