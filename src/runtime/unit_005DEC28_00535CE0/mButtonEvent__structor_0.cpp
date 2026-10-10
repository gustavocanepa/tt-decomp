typedef int s32;

extern void *D_005B56A0;
extern "C" void *func_00211C00(void *);

extern "C" void *mButtonEvent__structor_0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, float farg0, float farg1) {
    void *r0 = func_00211C00(arg0);
    *(float *)((char *)arg0 + 0x2c) = farg1;
    *(short *)((char *)arg0 + 0x20) = arg3;
    *(void **)((char *)arg0 + 0x24) = (void *)(arg4);
    *(float *)((char *)arg0 + 0x28) = farg0;
    *(void **)((char *)arg0 + 0x4) = &D_005B56A0;
    return r0;
}
