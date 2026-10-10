extern "C" void func_0040BC48(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005D1560;

extern "C" void func_003690E8(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x194) = &D_005D1560;
    func_0040BC48(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
