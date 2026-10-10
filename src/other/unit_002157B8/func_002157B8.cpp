extern "C" void func_001C13B0(void *arg0, int arg1);
extern "C" void func_0050E1A8(void *arg0);

extern "C" void func_002157B8(void *arg0, int arg1) {
    func_001C13B0(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
