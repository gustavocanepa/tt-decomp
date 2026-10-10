typedef unsigned int u32;

extern "C" void func_0054D6E8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794750;

extern int D_00794730;

extern "C" void *func_0054CD18(void) {
    if (D_00794730 == 0) {
        func_0054D6E8();
        func_0050C6E8(&D_00794730, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794750);
    }
    return &D_00794730;
}
