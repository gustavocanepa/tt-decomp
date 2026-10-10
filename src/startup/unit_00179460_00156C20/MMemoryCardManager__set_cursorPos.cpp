extern "C" void func_00156538(void *);
extern "C" void func_001564E0(void *, int);
extern "C" void func_0029CF48(void *, void *);
extern "C" void func_0029CEF0(void *, int);
extern "C" int func_0029E9F0(int);

struct Target {
    char pad0[0x688];
    int value;
};

struct Owner {
    char pad0[0x20];
    Target *target;
};

struct A {
    Owner *p;
    int pad[3];
};

struct B {
    int v[4];
};

static inline int get(B *b) { return b->v[0]; }

extern "C" void MMemoryCardManager__set_cursorPos(void *arg0, void *arg1, int count, void *name)
{
    if (count > 0) {
        A a;
        B b;
        func_00156538(&a);
        Target *t = a.p->target;
        func_0029CF48(&b, name);
        t->value = func_0029E9F0(get(&b));
        func_0029CEF0(&b, 2);
        func_001564E0(&a, 2);
    }
}
