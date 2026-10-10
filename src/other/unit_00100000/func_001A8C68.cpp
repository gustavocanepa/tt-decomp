extern "C" void func_001A9050();
extern "C" void func_0050E1A8(void *arg0);

extern "C" void func_001A8C68(void *arg0, int arg1) {
    func_001A9050();
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
