extern "C" void func_00123F58(void *);
extern "C" void func_00123F00(void *, int);
extern "C" void func_0029CF48(void *, void *);
extern "C" int func_0029E9F0(int);
extern "C" void func_0029CEF0(void *, int);

struct Target {
    char pad[0x300];
    volatile int value;
};

struct A {
    Target *p;
    int pad[3];
};

struct B {
    int v[4];
};

static inline int get(B *b) { return b->v[0]; }

extern "C" void func_00124FB0(void *arg0, void *arg1, void *arg2, void *name)
{
    A a;
    B b;
    func_00123F58(&a);
    func_0029CF48(&b, name);
    Target *t = a.p;
    t->value = func_0029E9F0(get(&b)) != 0;
    func_0029CEF0(&b, 2);
    func_00123F00(&a, 2);
}
