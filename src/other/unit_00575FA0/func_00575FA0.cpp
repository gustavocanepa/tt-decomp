typedef int s32;

extern "C" void func_005755E8();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_00615108[];
extern int D_00615128;

extern int D_007A6460;

extern "C" void *func_00575FA0(void) {
    if (D_007A6460 == 0) {
        func_005755E8();
        func_0050C6C0(&D_007A6460, D_00615108, &D_00615128, 1);
    }
    return &D_007A6460;
}
