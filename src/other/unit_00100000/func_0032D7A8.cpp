struct Obj {
    char pad0[0x148];
    int kind;
    char pad14C[0x1C0 - 0x14C];
    int a[3];
    int b[3];
};

extern "C" void func_003AC118(Obj *o);
extern "C" void func_004F6678(void *p, int c, int n);

extern "C" void func_0032D7A8(Obj *o) {
    func_003AC118(o);
    o->kind = 0x11;
    func_004F6678(o->a, 0, sizeof(o->a));
    func_004F6678(o->b, 0, sizeof(o->b));
}
