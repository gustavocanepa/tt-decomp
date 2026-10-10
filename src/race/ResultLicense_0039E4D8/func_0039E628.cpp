struct Obj {
    int f0;
    int f4;
    void setA(int a) __asm__("func_001049E0");
    void setSize(int w, int h) __asm__("func_00104A48");
    void setB(int b) __asm__("func_00104A88");
};

extern "C" void func_00475A48(int *a, int *b, int *w, int *h);

extern "C" void func_0039E628(void *self, Obj *o) {
    int a, b, w, h;
    func_00475A48(&a, &b, &w, &h);
    o->setA(a);
    o->f4 = b;
    o->setSize(w, h);
    o->setB(0);
}
