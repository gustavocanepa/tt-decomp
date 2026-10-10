typedef unsigned int u32;

extern "C" void func_0054D6E8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794750;

extern int D_00794630;

extern "C" void *func_0054A190(void) {
    if (D_00794630 == 0) {
        func_0054D6E8();
        func_0050C6E8(&D_00794630, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794750);
    }
    return &D_00794630;
}
