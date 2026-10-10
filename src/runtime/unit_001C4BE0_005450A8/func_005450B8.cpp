typedef int s32;

extern "C" void func_00524A00();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EFD20[];
extern int D_005EFD30;

extern int D_00794460;

extern "C" void *func_005450B8(void) {
    if (D_00794460 == 0) {
        func_00524A00();
        func_0050C6C0(&D_00794460, D_005EFD20, &D_005EFD30, 1);
    }
    return &D_00794460;
}
