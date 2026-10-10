typedef int s32;

extern void *D_005B2380;
extern "C" void *func_002A7618(void *);

extern "C" void *func_001F01A0(void *arg0, s32 arg1) {
    void *r0 = func_002A7618(arg0);
    *(void **)((char *)arg0 + 0x4) = &D_005B2380;
    *(void **)((char *)arg0 + 0x10) = (void *)(arg1);
    return r0;
}
