extern "C" void func_0047F608(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005D9D68;

extern "C" void func_0042ECE8(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x20) = &D_005D9D68;
    func_0047F608(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
