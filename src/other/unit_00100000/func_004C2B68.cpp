struct Obj {
    char pad0[0x1C];
    int base;
    char pad20[0x2C - 0x20];
    int offset;
    int f30;
    int open;
};

extern "C" int func_005038D8(void);
extern "C" void func_00503928(void);

extern "C" int func_004C2B68(Obj *o) {
    func_005038D8();
    if (o->open == 0) {
        func_00503928();
        return 0;
    }
    int pos = o->base + o->offset;
    func_00503928();
    return pos;
}
