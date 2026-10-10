typedef int s32;

extern void *D_005D7378;
extern "C" void *func_004CA090(void *);
extern "C" void *func_002E8778(void *);
extern "C" void *func_00400A28(void *, void *);
extern "C" void *func_004009E0(void *);

extern "C" void func_003EAD28(void *arg0) {
    func_004CA090(arg0);
    *(void **)((char *)arg0 + 0xd0) = &D_005D7378;
    func_002E8778((char *)arg0 + 0xd4);
    func_00400A28((char *)arg0 + 0x170, (char *)arg0 + 0x150);
    func_004009E0((char *)arg0 + 0x1a0);
    *(void **)((char *)arg0 + 0x1c4) = 0x0;
    *(void **)((char *)arg0 + 0x1cc) = (void *)(0x1);
    *(void **)((char *)arg0 + 0x1c8) = 0x0;
    *(void **)((char *)arg0 + 0x1d0) = 0x0;
    *(void **)((char *)arg0 + 0x1d4) = 0x0;
    *(void **)((char *)arg0 + 0x144) = 0x0;
    *(void **)((char *)arg0 + 0x148) = 0x0;
    *(void **)((char *)arg0 + 0x14c) = 0x0;
    *(void **)((char *)arg0 + 0x194) = 0x0;
    *(void **)((char *)arg0 + 0x19c) = 0x0;
    *(void **)((char *)arg0 + 0x1d8) = 0x0;
    *(void **)((char *)arg0 + 0x1dc) = 0x0;
}
