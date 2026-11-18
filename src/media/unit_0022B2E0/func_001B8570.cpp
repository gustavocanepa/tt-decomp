extern "C" void func_001B7F98(void *);
extern "C" void func_001B7F40(void *, int);
extern "C" void func_001DF250(void *, void *);
extern "C" void func_001DF1F8(void *, int);

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, int);
};

struct Target {
    int m0;
    char *vtbl;
};

struct A {
    Target *p;
    int pad[3];
};
struct B {
    int v[4];
};
static inline int get(B *b) { return b->v[0]; }

extern "C" void func_001B8570(void *arg0, void *arg1, int count, void *name)
{
    if (count > 0) {
        A a;
        B b;
        func_001B7F98(&a);
        func_001DF250(&b, name);
        Target *t = a.p;
        VEntry *e = (VEntry *)(t->vtbl + 0x3A8);
        e->fn((char *)t + e->delta, get(&b));
        func_001DF1F8(&b, 2);
        func_001B7F40(&a, 2);
    }
}
