typedef int s32;

extern "C" void func_00522DA0();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EF900[];
extern int D_005EF910;

extern int D_00794410;

extern "C" void *func_00544188(void) {
    if (D_00794410 == 0) {
        func_00522DA0();
        func_0050C6C0(&D_00794410, D_005EF900, &D_005EF910, 1);
    }
    return &D_00794410;
}
