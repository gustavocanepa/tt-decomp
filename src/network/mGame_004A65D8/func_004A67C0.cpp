typedef int s32;

extern void *D_005DAC90;
extern "C" void *RefCounter__structor_0(void *);

extern "C" void *func_004A67C0(void *arg0, s32 arg1) {
    void *r0 = RefCounter__structor_0(arg0);
    *(void **)((char *)arg0 + 0x1C) = &D_005DAC90;
    *(void **)((char *)arg0 + 0x20) = (void *)(arg1);
    return r0;
}
