typedef int s32;

extern "C" void func_00522DA0();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005E8A80[];
extern int D_005E8A90;

extern int D_00793AE0;

extern "C" void *func_00526340(void) {
    if (D_00793AE0 == 0) {
        func_00522DA0();
        func_0050C6C0(&D_00793AE0, D_005E8A80, &D_005E8A90, 1);
    }
    return &D_00793AE0;
}
