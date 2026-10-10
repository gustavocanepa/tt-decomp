extern "C" void func_0038E308(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005D1180;

extern "C" void func_005570E8(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x14) = &D_005D1180;
    func_0038E308(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
