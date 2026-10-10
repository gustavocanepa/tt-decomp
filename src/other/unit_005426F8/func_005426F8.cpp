typedef int s32;

extern "C" void func_00522DA0();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EF318[];
extern int D_005EF328;

extern int D_00794390;

extern "C" void *func_005426F8(void) {
    if (D_00794390 == 0) {
        func_00522DA0();
        func_0050C6C0(&D_00794390, D_005EF318, &D_005EF328, 1);
    }
    return &D_00794390;
}
