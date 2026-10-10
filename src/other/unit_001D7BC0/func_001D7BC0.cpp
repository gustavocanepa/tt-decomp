extern "C" void func_002A2770(void *arg0, int arg1);
extern "C" void func_0050E1A8(void *arg0);

extern "C" void func_001D7BC0(void *arg0, int arg1) {
    func_002A2770(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
