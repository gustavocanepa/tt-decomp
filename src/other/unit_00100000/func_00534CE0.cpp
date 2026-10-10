typedef int s32;

extern "C" void func_00522DA0();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EC0C0[];
extern int D_005EC0D0;

extern int D_00793EE0;

extern "C" void *func_00534CE0(void) {
    if (D_00793EE0 == 0) {
        func_00522DA0();
        func_0050C6C0(&D_00793EE0, D_005EC0C0, &D_005EC0D0, 1);
    }
    return &D_00793EE0;
}
