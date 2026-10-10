typedef int s32;

extern void *D_005C6670;
extern "C" void *func_002C0EB0(void *);

extern "C" void *func_002B70F0(void *arg0, s32 arg1) {
    void *r0 = func_002C0EB0(arg0);
    *(void **)((char *)arg0 + 0x4) = &D_005C6670;
    *(void **)((char *)arg0 + 0x8) = (void *)(arg1);
    return r0;
}
