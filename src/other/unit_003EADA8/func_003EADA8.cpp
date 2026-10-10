typedef int s32;

extern void *D_005D7378;
extern "C" void *func_004CA090(void *);
extern "C" void *func_002E8778(void *);
extern "C" void *func_004009E0(void *);

extern "C" void func_003EADA8(void *arg0, s32 arg1) {
    func_004CA090(arg0);
    *(void **)((char *)arg0 + 0xd0) = &D_005D7378;
    func_002E8778((char *)arg0 + 0xd4);
    func_004009E0((char *)arg0 + 0x170);
    func_004009E0((char *)arg0 + 0x1a0);
    *(void **)((char *)arg0 + 0x1c4) = 0x0;
    *(void **)((char *)arg0 + 0x19c) = 0x0;
    *(void **)((char *)arg0 + 0x1c8) = 0x0;
    *(void **)((char *)arg0 + 0x1d0) = 0x0;
    *(void **)((char *)arg0 + 0x1d4) = 0x0;
    *(void **)((char *)arg0 + 0x144) = 0x0;
    *(void **)((char *)arg0 + 0x148) = 0x0;
    *(void **)((char *)arg0 + 0x14c) = 0x0;
    *(void **)((char *)arg0 + 0x194) = 0x0;
    *(void **)((char *)arg0 + 0x1cc) = (void *)(arg1);
}
