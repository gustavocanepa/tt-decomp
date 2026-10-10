typedef int s32;

extern void *D_005B3EA8;
extern "C" void *func_002345D8(void *);

extern "C" void *func_00215098(void *arg0) {
    void *r0 = func_002345D8(arg0);
    *(void **)((char *)arg0 + 0xc) = 0x0;
    *(void **)((char *)arg0 + 0x4) = &D_005B3EA8;
    *(void **)((char *)arg0 + 0x10) = 0x0;
    *(void **)((char *)arg0 + 0x14) = 0x0;
    *(void **)((char *)arg0 + 0x18) = 0x0;
    *(void **)((char *)arg0 + 0x1c) = 0x0;
    return r0;
}
