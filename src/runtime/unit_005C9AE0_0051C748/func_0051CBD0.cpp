typedef int s32;

extern "C" void func_00526340();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005E4BF0[];
extern int D_005E4C00;

extern int D_00793710;

extern "C" void *func_0051CBD0(void) {
    if (D_00793710 == 0) {
        func_00526340();
        func_0050C6C0(&D_00793710, D_005E4BF0, &D_005E4C00, 1);
    }
    return &D_00793710;
}
