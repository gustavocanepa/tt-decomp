extern "C" void func_00456A00(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005D74F8;

extern "C" void func_003EE5E0(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x24) = &D_005D74F8;
    func_00456A00(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
