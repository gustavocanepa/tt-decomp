typedef unsigned int u32;

extern "C" void func_0054F640();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B6E8;

extern int D_007947B0;

extern "C" void *func_0054E3A0(void) {
    if (D_007947B0 == 0) {
        func_0054F640();
        func_0050C6E8(&D_007947B0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B6E8);
    }
    return &D_007947B0;
}
