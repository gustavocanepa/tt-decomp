typedef int s32;

extern void *D_005C7C38;
extern "C" void *func_002A25F8(void *);

extern "C" void *func_002C28E0(void *arg0, s32 arg1, s32 arg2) {
    void *r0 = func_002A25F8(arg0);
    *(void **)((char *)arg0 + 0x4) = &D_005C7C38;
    *(void **)((char *)arg0 + 0xc) = (void *)(arg2);
    return r0;
}
