typedef unsigned int u32;

extern "C" void func_0054E848();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007949E0;

extern int D_00794900;

extern "C" void *func_0054F220(void) {
    if (D_00794900 == 0) {
        func_0054E848();
        func_0050C6E8(&D_00794900, ((char *)"Q212GranTurismo413UpdateManager"), &D_007949E0);
    }
    return &D_00794900;
}
