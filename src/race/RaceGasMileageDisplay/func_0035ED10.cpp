extern "C" void *RaceValueDisplayBase__structor_1(void *arg0);
extern "C" char D_005D0C18[];

extern "C" void func_0035ED10(void *arg0) {
    void *s0 = arg0;
    RaceValueDisplayBase__structor_1(s0);
    *(int *)((char *)s0 + 0x6C) = 0;
    *(int *)((char *)s0 + 0x68) = 0;
    *(void **)((char *)s0 + 0x14) = D_005D0C18;
}
