extern "C" void func_0050C648(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005DB808;

extern "C" void func_00578278(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x4) = &D_005DB808;
    func_0050C648(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
