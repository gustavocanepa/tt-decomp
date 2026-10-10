typedef int s32;

extern "C" void func_00575180();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_00615130[];
extern int D_00615150;

extern int D_007A6430;

extern "C" void *func_005760F0(void) {
    if (D_007A6430 == 0) {
        func_00575180();
        func_0050C6C0(&D_007A6430, D_00615130, &D_00615150, 1);
    }
    return &D_007A6430;
}
