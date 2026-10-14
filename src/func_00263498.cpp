extern "C" void func_00262C60(void *);
extern "C" void func_00262C08(void *, int);
extern "C" void func_0029CF48(void *, void *);
extern "C" int func_0029E9F0(int);
extern "C" void func_0029CEF0(void *, int);

struct Target {
    char pad0[0x94];
    volatile int m94;
};

struct A {
    Target *p;
    int pad[3];
};

struct B {
    int v[4];
};

static inline int get(B *b) { return b->v[0]; }

extern "C" void func_00263498(void *arg0, void *arg1, int count, void *name)
{
    if (count > 0) {
        A a;
        B b;
        func_00262C60(&a);
        func_0029CF48(&b, name);
        Target *t = a.p;
        t->m94 = func_0029E9F0(get(&b)) != 0;
        func_0029CEF0(&b, 2);
        func_00262C08(&a, 2);
    }
}
