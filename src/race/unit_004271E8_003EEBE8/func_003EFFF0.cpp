struct Table;
struct A { int p0; Table *t; };
extern "C" int func_003EEBE8(Table *, const char *) throw();
extern "C" void func_003EFF48(A *, int, float, int, int, float) throw();
extern "C" void func_003EFFF0(A *self, const char *name, float f0, int b, int c, float f1) {
    if (self->t) {
        func_003EFF48(self, func_003EEBE8(self->t, name), f0, b, c, f1);
    }
}
