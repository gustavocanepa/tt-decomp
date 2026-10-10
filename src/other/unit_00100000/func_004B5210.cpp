extern "C" void func_004AE9F0(void *arg0, int arg1);
extern "C" void func_0050E1A8(void *arg0);

extern "C" void func_004B5210(void *arg0, int arg1) {
    func_004AE9F0(arg0, 2);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
