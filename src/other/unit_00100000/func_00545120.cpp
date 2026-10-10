typedef int s32;

extern "C" void func_00524A00();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EFD38[];
extern int D_005EFD48;

extern int D_00794490;

extern "C" void *func_00545120(void) {
    if (D_00794490 == 0) {
        func_00524A00();
        func_0050C6C0(&D_00794490, D_005EFD38, &D_005EFD48, 1);
    }
    return &D_00794490;
}
