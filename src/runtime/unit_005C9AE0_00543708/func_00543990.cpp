typedef unsigned int u32;

extern "C" void func_00543950();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B6E0;

extern int D_007943D0;

extern "C" void *func_00543990(void) {
    if (D_007943D0 == 0) {
        func_00543950();
        func_0050C6E8(&D_007943D0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B6E0);
    }
    return &D_007943D0;
}
