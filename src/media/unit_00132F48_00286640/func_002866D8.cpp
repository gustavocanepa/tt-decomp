extern "C" void func_00286240(void *);
extern "C" void func_002861E8(void *, int);
extern "C" void func_0029CF48(void *, void *);
extern "C" void func_0029CEF0(void *, int);
extern "C" int func_0029E9F0(int);

struct Target {
    char pad0[0x58];
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

extern "C" void func_002866D8(void *arg0, void *arg1, int count, void *name)
{
    if (count > 0) {
        A a;
        B b;
        func_00286240(&a);
        func_0029CF48(&b, name);
        Target *t = a.p;
        t->value = func_0029E9F0(get(&b));
        func_0029CEF0(&b, 2);
        func_002861E8(&a, 2);
    }
}
