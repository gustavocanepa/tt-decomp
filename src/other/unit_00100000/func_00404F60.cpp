extern "C" void func_003FEC50(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005D9720;

extern "C" void func_00404F60(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0xC) = &D_005D9720;
    func_003FEC50(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
