struct Car;
struct S { char p[0x1C]; Car *car; };
extern "C" void func_003691B0(Car *c) throw();
extern "C" Car *exception__structor_0(int size);

extern "C" Car *func_0036BFF8(S *self) {
    Car *t = self->car;
    Car *c;
    if (t != 0) {
        c = t;
        self->car = 0;
    } else {
        c = exception__structor_0(0x55C0);
        func_003691B0(c);
    }
    return c;
}
