struct Obj {
    char pad0[0xAC];
    int pending;
};

extern "C" void func_004A4D68(void *lock);
extern "C" void func_004A4DD8(void *lock);
extern "C" void func_0047ECC0(Obj *o);

extern "C" void func_0047E818(Obj *o) {
    func_004A4D68(o);
    bool idle = o->pending == 0;
    func_004A4DD8(o);
    if (!idle) {
        func_0047ECC0(o);
    }
}
