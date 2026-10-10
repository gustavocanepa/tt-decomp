typedef int s32;

extern void *D_005DAD28;
extern "C" void *func_004A69E0(void *);

extern "C" void *func_004A7C38(void *arg0, s32 arg1) {
    void *r0 = func_004A69E0(arg0);
    *(void **)((char *)arg0 + 0x1C) = &D_005DAD28;
    *(void **)((char *)arg0 + 0x20) = (void *)(arg1);
    return r0;
}
