typedef unsigned int u32;

extern "C" void func_0050EB20();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007933A0;

extern int D_00793990;

extern "C" void *func_00521E70(void) {
    if (D_00793990 == 0) {
        func_0050EB20();
        func_0050C6E8(&D_00793990, ((char *)"Q212GranTurismo413UpdateManager"), &D_007933A0);
    }
    return &D_00793990;
}
