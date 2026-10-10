extern "C" void func_001803E8(void *);
extern "C" void func_00180390(void *, int);
extern "C" void func_00182D38(int, int);
extern "C" void func_001DF250(void *, void *);
extern "C" void func_001DF1F8(void *, int);

struct B {
    int v[4];
};

static inline int get(B *b) { return b->v[0]; }

extern "C" void func_00180E08(void *arg0, void *arg1, void *arg2, void *arg3)
{
    int a[8];
    B b;
    int x;

    func_001803E8(a);
    x = a[0];
    func_001DF250(&b, arg3);
    func_00182D38(x, get(&b));
    func_001DF1F8(&b, 2);
    func_00180390(a, 2);
}
