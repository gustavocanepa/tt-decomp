extern "C" void func_001A8AB8();
extern "C" void func_0050E1A8(void *arg0);

extern "C" void func_001A8A60(void *arg0, int arg1) {
    func_001A8AB8();
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
