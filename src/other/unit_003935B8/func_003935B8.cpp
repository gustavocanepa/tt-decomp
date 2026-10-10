typedef int s32;

extern void *D_005D71A8;
extern "C" void *func_00393550(void *);

extern "C" void *func_003935B8(void *arg0) {
    void *r0 = func_00393550(arg0);
    if (r0 != 0) {
        *(void **)((char *)r0 + 0x4) = &D_005D71A8;
        *(void **)(r0) = *(void **)((char *)arg0 + 0x4);
        *(void **)((char *)arg0 + 0x4) = r0;
    }
    return r0;
}
