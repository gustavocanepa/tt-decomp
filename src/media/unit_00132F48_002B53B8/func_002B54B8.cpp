typedef int s32;

extern void *D_005C6A30;
extern "C" void *func_002C0EB0(void *);

extern "C" void *func_002B54B8(void *arg0, s32 arg1) {
    void *r0 = func_002C0EB0(arg0);
    *(void **)((char *)arg0 + 0x4) = &D_005C6A30;
    *(void **)((char *)arg0 + 0x8) = (void *)(arg1);
    return r0;
}
