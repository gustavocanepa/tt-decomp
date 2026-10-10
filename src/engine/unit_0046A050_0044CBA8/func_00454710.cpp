struct M {
    char pad0[0x20];
    float m20;
};

extern "C" void func_004542D0(M *d, int axis, M *a, M *b);

extern "C" void func_00454710(M *d, M *a, M *b) {
    func_004542D0(d, 0, a, b);
    func_004542D0(d, 1, a, b);
    d->m20 = a->m20 / b->m20;
}
