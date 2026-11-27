struct Obj {
    char pad[0x447A4];
    int f447A4;
    int f447A8;
};

extern "C" void func_002CD038(int arg);
extern "C" void func_002CBAB0(int arg);
extern "C" void func_002CD120(int arg);

extern "C" void func_002C8B08(Obj *arg) {
    func_002CD038(arg->f447A8);
    if (arg->f447A4 != 0) {
        return func_002CBAB0(arg->f447A8);
    }
    func_002CD120(arg->f447A8);
}
