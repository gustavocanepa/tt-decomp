extern "C" void func_003F3E30(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005D7F70;

extern "C" void func_003F24A8(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x4) = &D_005D7F70;
    func_003F3E30(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
