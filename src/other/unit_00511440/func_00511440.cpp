typedef int s32;

extern "C" void func_00512000();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005E01E8[];
extern int D_005E0200;

extern int D_007934C0;

extern "C" void *func_00511440(void) {
    if (D_007934C0 == 0) {
        func_00512000();
        func_0050C6C0(&D_007934C0, D_005E01E8, &D_005E0200, 1);
    }
    return &D_007934C0;
}
