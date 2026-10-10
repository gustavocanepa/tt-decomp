struct Obj { int m0; int handle; };
extern "C" void func_00415E70(Obj *self, int handle);
extern "C" void func_0045FE50(void *sys, int arg, int a, int b, int c);
extern "C" void func_00415FC8(Obj *self);
extern "C" void *D_00586EF4;

extern "C" void GT3OLDFONT__GT3OldFontManagerClass__putstring(Obj *self, int arg)
{
    func_00415E70(self, self->handle);
    func_0045FE50(D_00586EF4, arg, 0, 0, 0);
    func_00415FC8(self);
}
