typedef int s32;

extern void *D_005D0CC8;
extern "C" void *func_0038E2B8(void *);

extern "C" void *func_0035AD20(void *arg0) {
    void *r0 = func_0038E2B8(arg0);
    *(void **)((char *)arg0 + 0x18) = 0x0;
    *(void **)((char *)arg0 + 0x14) = &D_005D0CC8;
    *(void **)((char *)arg0 + 0x1c) = 0x0;
    *(void **)((char *)arg0 + 0x20) = 0x0;
    *(void **)((char *)arg0 + 0x24) = 0x0;
    return r0;
}
