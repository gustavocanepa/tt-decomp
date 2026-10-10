extern "C" void *RaceValueDisplayBase__structor_1(void *arg0);
extern "C" char D_005D0C18[];

struct func_0035ED10_s0 {
    char pad0[0x14];
    void *unk14;
    char pad18[0x50];
    int unk68;
    int unk6C;
};

extern "C" void func_0035ED10(void *arg0) {
    void *s0 = arg0;
    RaceValueDisplayBase__structor_1(s0);
    ((struct func_0035ED10_s0 *)s0)->unk6C = 0;
    ((struct func_0035ED10_s0 *)s0)->unk68 = 0;
    ((struct func_0035ED10_s0 *)s0)->unk14 = D_005D0C18;
}
