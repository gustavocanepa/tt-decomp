typedef int s32;

extern "C" void func_0052FE98();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005F08B0[];
extern int D_005F08C0;

extern int D_00794590;

extern "C" void *func_00546EB8(void) {
    if (D_00794590 == 0) {
        func_0052FE98();
        func_0050C6C0(&D_00794590, D_005F08B0, &D_005F08C0, 1);
    }
    return &D_00794590;
}
