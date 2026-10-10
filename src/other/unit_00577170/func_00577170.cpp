typedef int s32;

extern "C" void func_00575180();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_006158F0[];
extern int D_00615900;

extern int D_007A64B0;

extern "C" void *func_00577170(void) {
    if (D_007A64B0 == 0) {
        func_00575180();
        func_0050C6C0(&D_007A64B0, D_006158F0, &D_00615900, 1);
    }
    return &D_007A64B0;
}
