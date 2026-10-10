extern "C" void func_001B15E8(void *);
extern "C" void func_001B1590(void *, int);
extern "C" void func_0029CF48(void *, void *);
extern "C" void func_0029CEF0(void *, int);
extern "C" int func_0029E9F0(int);

struct Target {
    char pad0[0x1C];
    int value;
};

struct A {
    Target *p;
    int pad[3];
};

struct B {
    int v[4];
};

static inline int get(B *b) { return b->v[0]; }

extern "C" void MStream__set_repeat(void *arg0, void *arg1, int count, void *name)
{
    if (count > 0) {
        A a;
        B b;
        func_001B15E8(&a);
        func_0029CF48(&b, name);
        Target *t = a.p;
        t->value = func_0029E9F0(get(&b)) != 0;
        func_0029CEF0(&b, 2);
        func_001B1590(&a, 2);
    }
}
