typedef unsigned int u32;

extern "C" void func_005593C0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794FD0;

extern int D_007951B0;

extern "C" void *func_005594C8(void) {
    if (D_007951B0 == 0) {
        func_005593C0();
        func_0050C6E8(&D_007951B0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794FD0);
    }
    return &D_007951B0;
}
