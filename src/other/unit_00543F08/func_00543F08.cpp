typedef int s32;

extern "C" void func_0053C698();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EF7B0[];
extern int D_005EF7C0;

extern int D_007943F0;

extern "C" void *func_00543F08(void) {
    if (D_007943F0 == 0) {
        func_0053C698();
        func_0050C6C0(&D_007943F0, D_005EF7B0, &D_005EF7C0, 1);
    }
    return &D_007943F0;
}
