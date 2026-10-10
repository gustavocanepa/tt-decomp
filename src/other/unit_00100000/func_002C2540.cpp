typedef int s32;

extern void *D_005C7BB8;
extern "C" void *func_0029BCC0(void *);

extern "C" void *func_002C2540(void *arg0, s32 arg1, s32 arg2) {
    void *r0 = func_0029BCC0(arg0);
    *(void **)((char *)arg0 + 0x4) = &D_005C7BB8;
    *(void **)((char *)arg0 + 0xc) = (void *)(arg2);
    return r0;
}
