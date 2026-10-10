typedef int s32;

extern "C" void func_00524A00();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005ECE28[];
extern int D_005ECE38;

extern int D_00794040;

extern "C" void *func_00538138(void) {
    if (D_00794040 == 0) {
        func_00524A00();
        func_0050C6C0(&D_00794040, D_005ECE28, &D_005ECE38, 1);
    }
    return &D_00794040;
}
