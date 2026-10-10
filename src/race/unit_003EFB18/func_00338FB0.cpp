extern "C" void func_0037A840(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005CBC28;

extern "C" void func_00338FB0(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x134) = &D_005CBC28;
    func_0037A840(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
