extern "C" void func_0047CAD0(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005DA818;

extern "C" void func_004802F0(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0xA4) = &D_005DA818;
    func_0047CAD0(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
