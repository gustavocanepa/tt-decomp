typedef int s32;

extern void *D_005D1018;
extern "C" void func_0038E2B8(void *);

extern "C" void func_0035BA70(void *arg0) {
    func_0038E2B8(arg0);
    void *p0 = *(void **)((char *)arg0 + 0x24);
    *(void **)((char *)arg0 + 0x14) = &D_005D1018;
    *(void **)((char *)arg0 + 0x24) = (void *)(((s32)p0 & (s32)-0x100));
    *(void **)((char *)arg0 + 0x1c) = 0x0;
    *(void **)((char *)arg0 + 0x20) = 0x0;
    *(void **)((char *)arg0 + 0x18) = 0x0;
}
