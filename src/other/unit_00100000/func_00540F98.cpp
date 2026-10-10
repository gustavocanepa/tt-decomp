typedef int s32;

extern "C" void func_00524A00();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EE868[];
extern int D_005EE878;

extern int D_007942D0;

extern "C" void *func_00540F98(void) {
    if (D_007942D0 == 0) {
        func_00524A00();
        func_0050C6C0(&D_007942D0, D_005EE868, &D_005EE878, 1);
    }
    return &D_007942D0;
}
