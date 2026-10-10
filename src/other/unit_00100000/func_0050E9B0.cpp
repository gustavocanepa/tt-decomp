typedef int s32;

extern "C" void func_004ACAB8(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005A49C0;

extern "C" void func_0050E9B0(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x8) = &D_005A49C0;
    func_004ACAB8(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
