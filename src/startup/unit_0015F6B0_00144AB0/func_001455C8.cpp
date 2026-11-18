extern "C" void * func_00141FF0(void *);
extern "C" void func_00141F98(void *, int);
extern "C" void func_0029CF48(void *, void *);
extern "C" void func_0029CEF0(void *, int);
extern "C" int func_0029E9F0(int);

struct Sub {
    char pad0[0x14];
    int value;
};
struct Owner {
    char pad0[0x10];
    char *q;
};
struct A {
    Owner *p;
    int pad[3];
};
struct B {
    int v[4];
};
static inline int get(B *b) { return b->v[0]; }

extern "C" void func_001455C8(void *arg0, void *arg1, int count, void *name)
{
    if (count > 0) {
        A a;
        B b;
        func_00141FF0(&a);
        func_0029CF48(&b, name);
        Sub *t = (Sub *)(a.p->q + 0x1DA0);
        t->value = func_0029E9F0(get(&b));
        func_0029CEF0(&b, 2);
        func_00141F98(&a, 2);
    }
}
