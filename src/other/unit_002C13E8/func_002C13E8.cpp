typedef int s32;

extern void *D_005C7A68;
extern "C" void *func_002BC190(void *);

extern "C" void *func_002C13E8(void *arg0, s32 arg1, s32 arg2) {
    void *r0 = func_002BC190(arg0);
    *(void **)((char *)arg0 + 0x4) = &D_005C7A68;
    *(void **)((char *)arg0 + 0xc) = (void *)(arg2);
    return r0;
}
