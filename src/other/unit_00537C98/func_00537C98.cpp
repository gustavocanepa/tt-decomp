typedef int s32;

extern "C" void func_00524A00();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005ECD88[];
extern int D_005ECD98;

extern int D_00794030;

extern "C" void *func_00537C98(void) {
    if (D_00794030 == 0) {
        func_00524A00();
        func_0050C6C0(&D_00794030, D_005ECD88, &D_005ECD98, 1);
    }
    return &D_00794030;
}
