typedef int s32;

extern "C" void func_0052FE98();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005E02D0[];
extern int D_005E02E8;

extern int D_007934E0;

extern "C" void *func_00512000(void) {
    if (D_007934E0 == 0) {
        func_0052FE98();
        func_0050C6C0(&D_007934E0, D_005E02D0, &D_005E02E8, 1);
    }
    return &D_007934E0;
}
