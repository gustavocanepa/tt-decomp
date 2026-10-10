typedef int s32;

extern "C" void func_00377E90(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005D3AF8;

extern "C" void func_00377F78(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x8) = &D_005D3AF8;
    func_00377E90(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
