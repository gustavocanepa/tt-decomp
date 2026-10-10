extern "C" void func_00108908(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005A48F8;

extern "C" void func_00100970(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x64) = &D_005A48F8;
    func_00108908(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
