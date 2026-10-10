typedef int s32;

extern void *D_005CCAD8;
extern "C" void *func_002CE108(void *);

extern "C" void *RaceBasic__structor_0(void *arg0) {
    void *r0 = func_002CE108(arg0);
    *(void **)((char *)arg0 + 0xE4C0) = 0x0;
    *(void **)((char *)arg0 + 0x64) = &D_005CCAD8;
    *(void **)((char *)arg0 + 0xE4C4) = 0x0;
    *(void **)((char *)arg0 + 0xE4CC) = 0x0;
    *(void **)((char *)arg0 + 0xE4D4) = 0x0;
    *(void **)((char *)arg0 + 0xE4C8) = 0x0;
    *(void **)((char *)arg0 + 0xE4D0) = 0x0;
    *(void **)((char *)arg0 + 0xE4D8) = 0x0;
    *(void **)((char *)arg0 + 0xE4DC) = 0x0;
    *(void **)((char *)arg0 + 0xE4E0) = 0x0;
    *(void **)((char *)arg0 + 0xE4E4) = 0x0;
    return r0;
}
