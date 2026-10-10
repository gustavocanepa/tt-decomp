extern "C" void func_00107280();
extern "C" void func_0050E1A8(void *arg0);

extern "C" void func_001071E8(void *arg0, int arg1) {
    func_00107280();
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
