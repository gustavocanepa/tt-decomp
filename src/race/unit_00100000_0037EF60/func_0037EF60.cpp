extern "C" void func_0037FB98(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005D4500;

extern "C" void func_0037EF60(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x18) = &D_005D4500;
    func_0037FB98(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
