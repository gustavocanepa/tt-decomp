typedef int s32;

struct S {
    char pad0[4];
    void *f4;
    s32 f8;
    char pad1[0x54 - 0x0C];
    s32 f54;
    char pad2[0xA0 - 0x58];
    s32 fA0;
    char pad3[0xDC - 0xA4];
    s32 fDC;
    s32 fE0;
    s32 fE4;
    s32 fE8;
    s32 fEC;
    s32 fF0;
    s32 fF4;
    s32 fF8;
    char pad4[0x100 - 0xFC];
    s32 f100;
};

extern "C" void func_0043BE20(void *arg0, s32 arg1);

extern "C" void func_0037A5D8(S *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *t;

    if (arg0->fDC == 0) {
        arg0->fEC = arg2;
        arg0->f100 = arg3;
        arg0->fE4 = 0;
        arg0->fE8 = arg1;
        if (arg1 == 0) {
            arg0->fF0 = arg0->f54;
            arg0->fF4 = arg0->fA0;
        }
        if (arg0->fEC == 0) {
            arg0->fF8 = 0;
        } else {
            arg0->fF8 = 1;
        }
        arg0->fDC = 1;
        t = arg0->f4;
        arg0->fE0 = 1;
        if (t != 0 && arg0->f8 != 0) {
            func_0043BE20(t, 0);
        }
    }
}
