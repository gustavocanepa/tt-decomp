typedef int s32;

extern "C" void DynamicsConductor__structor_1(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005C92A0;

extern "C" void func_00552780(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x241CC) = &D_005C92A0;
    DynamicsConductor__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
