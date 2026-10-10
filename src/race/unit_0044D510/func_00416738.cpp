extern "C" void func_00473050(void);
extern "C" void func_00475248(void);
extern "C" void ModelSet2__render(void *p, int flag);
extern "C" void func_004730A8(void);
extern "C" void func_00470E60(int n);

struct Obj {
    void *a;
    void *b;
};

extern "C" void func_00416738(Obj *o)
{
    if (o->a) {
        func_00473050();
        func_00475248();
        ModelSet2__render(o->a, 0);
        func_004730A8();
    }
    func_00470E60(2);
    if (o->b)
        ModelSet2__render(o->b, 0);
}
