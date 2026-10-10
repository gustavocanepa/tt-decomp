typedef int s32;

extern "C" void func_00522DA0();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005F0568[];
extern int D_005F0578;

extern int D_00794530;

extern "C" void *func_005466D8(void) {
    if (D_00794530 == 0) {
        func_00522DA0();
        func_0050C6C0(&D_00794530, D_005F0568, &D_005F0578, 1);
    }
    return &D_00794530;
}
