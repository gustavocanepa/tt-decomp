typedef int s32;

extern "C" void func_0052FE98();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EE008[];
extern int D_005EE020;

extern int D_007941E0;

extern "C" void *func_0053D570(void) {
    if (D_007941E0 == 0) {
        func_0052FE98();
        func_0050C6C0(&D_007941E0, D_005EE008, &D_005EE020, 1);
    }
    return &D_007941E0;
}
