extern "C" void func_00262C60(void *);
extern "C" void func_00262C08(void *, int);
extern "C" void func_00299B08(void *, void *);
extern "C" void func_00299AB0(void *, int);
extern "C" float func_0029B188(int);

struct Target {
    char pad0[0x88];
    float value;
};

struct A {
    Target *p;
    int pad[3];
};

struct B {
    int v[4];
};

static inline int get(B *b) { return b->v[0]; }

extern "C" void func_00263278(void *arg0, void *arg1, int count, void *name)
{
    if (count > 0) {
        A a;
        B b;
        func_00262C60(&a);
        func_00299B08(&b, name);
        Target *t = a.p;
        t->value = func_0029B188(get(&b));
        func_00299AB0(&b, 2);
        func_00262C08(&a, 2);
    }
}
