typedef int s32;

extern "C" void func_00522DA0();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005ECEC0[];
extern int D_005ECED8;

extern int D_00794050;

extern "C" void *func_00538260(void) {
    if (D_00794050 == 0) {
        func_00522DA0();
        func_0050C6C0(&D_00794050, D_005ECEC0, &D_005ECED8, 1);
    }
    return &D_00794050;
}
