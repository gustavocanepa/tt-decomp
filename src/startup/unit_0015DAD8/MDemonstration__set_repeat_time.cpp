extern "C" void func_00141000(void *);
extern "C" void func_00140FA8(void *, int);
extern "C" void func_0029CF48(void *, void *);
extern "C" void func_0029CEF0(void *, int);
extern "C" int func_0029E9F0(int);

struct Target {
    char pad0[0x50];
    int value;
};

struct Owner {
    char pad0[0x10];
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

extern "C" void MDemonstration__set_repeat_time(void *arg0, void *arg1, void *arg2, void *name)
{
    A a;
    B b;
    func_00141000(&a);
    Target *t = a.p->target;
    func_0029CF48(&b, name);
    t->value = func_0029E9F0(get(&b));
    func_0029CEF0(&b, 2);
    func_00140FA8(&a, 2);
}
