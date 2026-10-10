struct Obj {
    int a;
    int b;
};

extern "C" void func_00415E70(Obj *self, int b);
extern "C" void func_0045FE50(void *mgr, int x, int y, int one, int zero);
extern "C" void func_00415FC8(Obj *self);
extern void *D_00586EF4;

extern "C" void func_00415DB0(Obj *self, int x, int y)
{
    func_00415E70(self, self->b);
    func_0045FE50(D_00586EF4, x, y, 1, 0);
    func_00415FC8(self);
}
