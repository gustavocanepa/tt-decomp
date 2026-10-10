typedef int s32;

extern "C" void func_00524A00();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EC3C8[];
extern int D_005EC3D8;

extern int D_00793F20;

extern "C" void *func_00535A30(void) {
    if (D_00793F20 == 0) {
        func_00524A00();
        func_0050C6C0(&D_00793F20, D_005EC3C8, &D_005EC3D8, 1);
    }
    return &D_00793F20;
}
