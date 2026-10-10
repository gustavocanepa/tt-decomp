extern "C" void func_00151AE8(void *);
extern "C" void func_00151A90(void *, int);
extern "C" void func_0029CF48(void *, void *);
extern "C" void func_0029CEF0(void *, int);
extern "C" int func_0029E9F0(int);
extern "C" void func_0019B550(void *obj, bool on);

struct Owner {
    char pad0[0x10];
    void *target;
};

struct A {
    Owner *p;
    int pad[3];
};

struct B {
    int v[4];
};

static inline int get(B *b) { return b->v[0]; }

extern "C" void MMemoryCardFile__setNewFile(void *arg0, void *arg1, int count, void *name)
{
    if (count > 0) {
        A a;
        B b;
        func_00151AE8(&a);
        func_0029CF48(&b, name);
        func_0019B550(a.p->target, func_0029E9F0(get(&b)) != 0);
        func_0029CEF0(&b, 2);
        func_00151A90(&a, 2);
    }
}
