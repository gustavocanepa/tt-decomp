typedef unsigned int u32;

extern "C" void func_005563C0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794F00;

extern int D_00794F10;

extern "C" void *func_00556478(void) {
    if (D_00794F10 == 0) {
        func_005563C0();
        func_0050C6E8(&D_00794F10, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794F00);
    }
    return &D_00794F10;
}
