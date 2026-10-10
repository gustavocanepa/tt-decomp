extern "C" void func_002B20C8(void *arg0, int arg1);
extern "C" void func_0050E1A8(void *arg0);

extern "C" void func_002B65E8(void *arg0, int arg1) {
    func_002B20C8(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
