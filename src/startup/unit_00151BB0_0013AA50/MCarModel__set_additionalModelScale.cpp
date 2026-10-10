extern "C" void func_00299B08(void *b, void *value);
extern "C" void func_00299AB0(void *b, int in_chrg);
extern "C" float func_0029B188(int v);
extern "C" void func_00139C38(void *a, void *self);
extern "C" void func_00139BE0(void *a, int in_chrg);
extern "C" void func_0013C908(void *obj, float v);

struct A {
    void *p;
    int pad[3];
};

struct B {
    int v[4];
};

static inline void *obj(A *a) { return a->p; }

extern "C" void MCarModel__set_additionalModelScale(void *arg0, void *self, void *arg2, void *value)
{
    B b;
    A a;
    func_00299B08(&b, value);
    func_00139C38(&a, self);
    void *o = obj(&a);
    func_0013C908(o, func_0029B188(b.v[0]));
    func_00139BE0(&a, 2);
    func_00299AB0(&b, 2);
}
