typedef int s32;

extern "C" void func_0053F570();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005ED2B0[];
extern int D_005ED2D0;

extern int D_007940E0;

extern "C" void *func_0053B1F8(void) {
    if (D_007940E0 == 0) {
        func_0053F570();
        func_0050C6C0(&D_007940E0, D_005ED2B0, &D_005ED2D0, 1);
    }
    return &D_007940E0;
}
