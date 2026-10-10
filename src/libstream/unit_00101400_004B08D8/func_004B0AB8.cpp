extern "C" void func_004B08D8(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005DAE78;

extern "C" void func_004B0AB8(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x30) = &D_005DAE78;
    func_004B08D8(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
