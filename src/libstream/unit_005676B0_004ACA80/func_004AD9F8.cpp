extern "C" void func_004A48D8(void *arg0, int arg1);
extern "C" void func_0050E1A8(void *arg0);

extern "C" void func_004AD9F8(void *arg0, int arg1) {
    func_004A48D8(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
