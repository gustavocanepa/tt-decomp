typedef int s32;

extern "C" void func_00385BC8(void *arg0);
extern "C" void *func_0050E018(s32 arg0);

extern "C" void *func_00385D78(void) {
    void *s0 = func_0050E018(0x5C);
    func_00385BC8(s0);
    return s0;
}
