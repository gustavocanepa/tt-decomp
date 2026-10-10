typedef int s32;

extern "C" void func_004CEDF0(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005DB1A8;

extern "C" void func_004C1190(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x68) = &D_005DB1A8;
    func_004CEDF0(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
