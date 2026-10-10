extern "C" void func_001FCB00(void *arg0, int arg1);
extern "C" void func_0050E1A8(void *arg0);

extern "C" void func_001C5608(void *arg0, int arg1) {
    func_001FCB00(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
