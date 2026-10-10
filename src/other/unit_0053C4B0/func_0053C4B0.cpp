typedef int s32;

extern "C" void func_00547118();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EDBF0[];
extern int D_005EDBF8;

extern int D_007941B0;

extern "C" void *func_0053C4B0(void) {
    if (D_007941B0 == 0) {
        func_00547118();
        func_0050C6C0(&D_007941B0, D_005EDBF0, &D_005EDBF8, 1);
    }
    return &D_007941B0;
}
