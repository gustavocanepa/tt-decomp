extern "C" void func_00370300(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005D41F0;

extern "C" void func_0037BEA8(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x134) = &D_005D41F0;
    func_00370300(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
