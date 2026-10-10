extern "C" void func_001A7938();
extern "C" void func_0050E1A8(void *arg0);

extern "C" void func_001A78E0(void *arg0, int arg1) {
    func_001A7938();
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
