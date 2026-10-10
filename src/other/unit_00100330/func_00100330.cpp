struct Obj {
    int f0;
    int f4;
    int pad[14];
    Obj() __asm__("func_00104838");
    ~Obj() __asm__("func_00104868");
    void setA(int a) __asm__("func_001049E0");
    void setSize(int w, int h) __asm__("func_00104A48");
};

extern "C" void func_00100308(Obj *o);

extern "C" void func_00100330(void) {
    Obj o;
    o.setA(0);
    o.f4 = 0;
    o.setSize(0x400, 0x400);
    func_00100308(&o);
}
