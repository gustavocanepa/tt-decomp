typedef int s32;

extern "C" void func_005442B0();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EA450[];
extern int D_005EA460;

extern int D_00793CD0;

extern "C" void *func_0052C6D8(void) {
    if (D_00793CD0 == 0) {
        func_005442B0();
        func_0050C6C0(&D_00793CD0, D_005EA450, &D_005EA460, 1);
    }
    return &D_00793CD0;
}
