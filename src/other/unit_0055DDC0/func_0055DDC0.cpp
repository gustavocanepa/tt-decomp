extern "C" void func_00100970(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005D58C0;

extern "C" void func_0055DDC0(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x64) = &D_005D58C0;
    func_00100970(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
