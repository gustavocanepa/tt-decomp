extern "C" void func_0043BE20(void *p, int a);
extern "C" void func_0043C410(void *p);

struct Flags {
    unsigned int bits;
    void clear() { bits &= ~0xFF; }
};

struct Obj {
    char pad0[4];
    void *m4;
    char pad8[0x30];
    int m38;
    char pad3C[0x68];
    unsigned int mA4;
    char padA8[0x2B0];
    Flags m358;
};

extern "C" void func_002D8150(Obj *o) {
    o->m38 = 0;
    func_0043BE20(o->m4, 1);
    func_0043C410(o->m4);
    o->mA4 = (o->mA4 & 0xFFFF00FF) | 0x100;
    o->m358.clear();
}
