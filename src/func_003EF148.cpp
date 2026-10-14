struct B { char p[0x1C]; char *tab; };
struct A { char p[4]; B *f4; };
struct E { char p[4]; short a; short b; short c; };
extern "C" int func_003F1860(A *self, int idx);
extern "C" int func_003EEFE0(A *self, int a1, int a2, int a3, int a4, float f0, int a5, float f1);

extern "C" int func_003EF148(A *self, int arg1, int arg2, int arg3, float f0, float f1) {
    int r = func_003F1860(self, arg2);
    if (r != 0) {
        r = 0;
        if (self->f4 != 0) {
            return func_003EEFE0(self, arg1, ((E *)(self->f4->tab + arg2 * 0x10))->a, ((E *)(self->f4->tab + arg2 * 0x10))->b, ((E *)(self->f4->tab + arg2 * 0x10))->c, f0, arg3, f1);
        }
    }
    return r;
}
