typedef int s32;

extern void *D_005D0290;
extern "C" void *func_0038E2B8(void *);
extern "C" void *func_0035E910(void *);
extern "C" void *func_0035EB60(void *);

extern "C" void func_003634B8(void *arg0) {
    func_0038E2B8(arg0);
    *(void **)((char *)arg0 + 0x18) = 0x0;
    *(void **)((char *)arg0 + 0x1c) = 0x0;
    *(void **)((char *)arg0 + 0x14) = &D_005D0290;
    *(void **)((char *)arg0 + 0x20) = 0x0;
    *(void **)((char *)arg0 + 0x24) = 0x0;
    func_0035E910((char *)arg0 + 0x28);
    func_0035EB60((char *)arg0 + 0x28); return;
}
