typedef unsigned int u32;

extern "C" void func_00522D10();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793A10;

extern int D_00793BB0;

extern "C" void *func_00528D40(void) {
    if (D_00793BB0 == 0) {
        func_00522D10();
        func_0050C6E8(&D_00793BB0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793A10);
    }
    return &D_00793BB0;
}
