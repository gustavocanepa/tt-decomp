extern "C" void *func_001F8CD0(void *);
extern "C" void func_001F8C78(void *, int);
extern "C" void func_0029CF48(void *, void *);
extern "C" int func_0029E9F0(int);
extern "C" void func_0029CEF0(void *, int);

struct Target {
    char pad[0x134];
    unsigned int value;
};

struct A {
    Target *p;
    int pad[3];
};

struct B {
    int v[4];
};

static inline int get(B *b) { return b->v[0]; }

extern "C" void func_001F9518(void *arg0, void *arg1, void *arg2, void *name)
{
    A a;
    B b;
    func_001F8CD0(&a);
    Target *t = a.p;
    func_0029CF48(&b, name);
    t->value = func_0029E9F0(get(&b)) != 0;
    func_0029CEF0(&b, 2);
    func_001F8C78(&a, 2);
}
