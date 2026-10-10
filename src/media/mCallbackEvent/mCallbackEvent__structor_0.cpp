typedef int s32;

extern void *D_005B5BF8;
extern "C" void *mEvent__structor_0(void *);

extern "C" void *mCallbackEvent__structor_0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *r0 = mEvent__structor_0(arg0);
    *(void **)((char *)arg0 + 0x4) = &D_005B5BF8;
    *(void **)((char *)arg0 + 0x20) = (void *)(arg3);
    return r0;
}
