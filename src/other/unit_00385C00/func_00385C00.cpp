extern "C" void func_002CE0A0(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005D4D28;

extern "C" void func_00385C00(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x20) = &D_005D4D28;
    func_002CE0A0(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
