typedef unsigned int u32;

extern "C" void func_00571C88();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B9B0;

extern int D_007A5D90;

extern "C" void *func_0056F020(void) {
    if (D_007A5D90 == 0) {
        func_00571C88();
        func_0050C6E8(&D_007A5D90, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B9B0);
    }
    return &D_007A5D90;
}
