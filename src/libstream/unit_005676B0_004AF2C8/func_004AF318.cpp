extern "C" void func_004A5530(void *arg0, int arg1);
extern "C" void func_0050E1A8(void *arg0);

extern "C" void func_004AF318(void *arg0, int arg1) {
    func_004A5530(arg0, 2);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
