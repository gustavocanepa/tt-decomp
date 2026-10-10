typedef int s32;

extern void *D_005ADCF8;
extern "C" void *func_002A7618(void *);

extern "C" void func_001B1790(void *arg0) {
    func_002A7618(arg0);
    *(void **)((char *)arg0 + 0x4) = &D_005ADCF8;
    *(void **)((char *)arg0 + 0x24) = 0x0;
    *(void **)((char *)arg0 + 0x10) = 0x0;
    *(void **)((char *)arg0 + 0x14) = 0x0;
    *(void **)((char *)arg0 + 0x18) = 0x0;
    *(void **)((char *)arg0 + 0x20) = 0x0;
    *(void **)((char *)arg0 + 0x1c) = (void *)(0x1);
}
