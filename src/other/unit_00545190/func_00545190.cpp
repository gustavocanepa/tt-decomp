typedef int s32;

extern "C" void func_0053B0C8();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EFD50[];
extern int D_005EFD60;

extern int D_00794470;

extern "C" void *func_00545190(void) {
    if (D_00794470 == 0) {
        func_0053B0C8();
        func_0050C6C0(&D_00794470, D_005EFD50, &D_005EFD60, 1);
    }
    return &D_00794470;
}
