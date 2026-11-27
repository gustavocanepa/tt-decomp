struct B { char p[0x1C]; char *tab; };
struct A { char p[4]; B *f4; };
struct E { char p[4]; short a; short b; short c; };
extern "C" int func_003F1860(A *self, int idx);
extern "C" void func_003EF300(A *self, int a1, int a2, int a3, float f0, float f1, float f2, float f3, int a4, float f4);

extern "C" void func_003EF458(A *self, int arg1, int arg2, float f0, float f1, float f2, float f3, float f4) {
    if (func_003F1860(self, arg1) != 0) {
        if (self->f4 != 0) {
            func_003EF300(self, ((E *)(self->f4->tab + arg1 * 0x10))->a, ((E *)(self->f4->tab + arg1 * 0x10))->b, ((E *)(self->f4->tab + arg1 * 0x10))->c, f0, f1, f2, f3, arg2, f4);
        }
    }
}
