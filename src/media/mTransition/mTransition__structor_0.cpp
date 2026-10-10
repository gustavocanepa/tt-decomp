typedef int s32;

extern void *D_005B3178;
extern "C" void *func_002A7618(void *);

extern "C" void *mTransition__structor_0(void *arg0) {
    void *r0 = func_002A7618(arg0);
    *(void **)((char *)arg0 + 0x4) = &D_005B3178;
    *(void **)((char *)arg0 + 0x1c) = 0x0;
    *(void **)((char *)arg0 + 0x10) = 0x0;
    *(void **)((char *)arg0 + 0x14) = (void *)(0x3);
    *(void **)((char *)arg0 + 0x18) = (void *)(0x3);
    return r0;
}
