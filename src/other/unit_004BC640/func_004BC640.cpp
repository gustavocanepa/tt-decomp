struct Obj {
    char pad0[0x198];
    int f198;
    char pad19C[0x2C0 - 0x19C];
    char sub2C0[0x404 - 0x2C0];
    int f404;
};

extern "C" void func_004BC7A0(Obj *o);
extern "C" void func_004BC160(Obj *o);
extern "C" void func_004AEB30(void *p);

extern "C" void func_004BC640(Obj *o) {
    func_004BC7A0(o);
    if (o->f198) {
        func_004BC160(o);
    }
    o->f404 = 0;
    func_004AEB30(o->sub2C0);
}
