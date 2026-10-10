typedef int s32;

extern "C" void func_00522DA0();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EC270[];
extern int D_005EC280;

extern int D_00793EF0;

extern "C" void *func_00535658(void) {
    if (D_00793EF0 == 0) {
        func_00522DA0();
        func_0050C6C0(&D_00793EF0, D_005EC270, &D_005EC280, 1);
    }
    return &D_00793EF0;
}
