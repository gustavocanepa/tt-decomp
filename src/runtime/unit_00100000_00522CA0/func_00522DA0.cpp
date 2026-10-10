typedef int s32;

extern "C" void func_00529600();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005E83B0[];
extern int D_005E83B8;

extern int D_00793A20;

extern "C" void *func_00522DA0(void) {
    if (D_00793A20 == 0) {
        func_00529600();
        func_0050C6C0(&D_00793A20, D_005E83B0, &D_005E83B8, 1);
    }
    return &D_00793A20;
}
