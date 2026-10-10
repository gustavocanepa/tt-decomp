extern "C" void func_001BE168(void *arg0, int arg1);
extern "C" void func_0050E1A8(void *arg0);

extern "C" void func_0017BC58(void *arg0, int arg1) {
    func_001BE168(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
