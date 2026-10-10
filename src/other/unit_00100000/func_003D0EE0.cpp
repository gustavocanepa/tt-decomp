extern "C" void func_003D0F38();
extern "C" void func_0050E1A8(void *arg0);

extern "C" void func_003D0EE0(void *arg0, int arg1) {
    func_003D0F38();
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
