extern "C" void func_001B4360(void *arg0, int arg1);
extern "C" void func_0050E1A8(void *arg0);

extern "C" void func_0022FBA8(void *arg0, int arg1) {
    func_001B4360(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
