struct B { char p[0x1C]; char *tab; };
struct A { char p[4]; B *f4; };
struct E { char p[4]; short a; short b; short c; };
extern "C" int func_003F1860(A *self, int idx);
extern "C" void func_003EF8B8(A *self, int a1, int a2, int a3, int a4, float f0, int a5, float f1);

extern "C" void func_003EFAE0(A *self, int arg1, int arg2, int arg3, float f0, float f1) {
    if (func_003F1860(self, arg1) != 0) {
        if (self->f4 != 0) {
            func_003EF8B8(self, ((E *)(self->f4->tab + arg1 * 0x10))->a, ((E *)(self->f4->tab + arg1 * 0x10))->b, ((E *)(self->f4->tab + arg1 * 0x10))->c, arg2, f0, arg3, f1);
        }
    }
}
