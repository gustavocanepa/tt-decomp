extern "C" void func_00139C38(void *);
extern "C" void func_00139BE0(void *, int);
extern "C" void func_0029CF48(void *, void *);
extern "C" void func_0029CEF0(void *, int);
extern "C" int func_0029E9F0(int);

struct Target {
    char pad0[0xA4];
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

extern "C" void func_0013B140(void *arg0, void *arg1, int count, void *name)
{
    A a;
    B b;
    func_00139C38(&a);
    Target *t = a.p;
    func_0029CF48(&b, name);
    t->value = func_0029E9F0(get(&b));
    func_0029CEF0(&b, 2);
    func_00139BE0(&a, 2);
}
