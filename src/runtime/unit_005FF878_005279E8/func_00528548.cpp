typedef unsigned int u32;

extern "C" void func_0052F108();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793DB0;

extern int D_00793B60;

extern "C" void *func_00528548(void) {
    if (D_00793B60 == 0) {
        func_0052F108();
        func_0050C6E8(&D_00793B60, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793DB0);
    }
    return &D_00793B60;
}
