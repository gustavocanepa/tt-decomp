typedef int s32;

extern "C" void func_00524A00();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EFD08[];
extern int D_005EFD18;

extern int D_00794480;

extern "C" void *func_00545048(void) {
    if (D_00794480 == 0) {
        func_00524A00();
        func_0050C6C0(&D_00794480, D_005EFD08, &D_005EFD18, 1);
    }
    return &D_00794480;
}
