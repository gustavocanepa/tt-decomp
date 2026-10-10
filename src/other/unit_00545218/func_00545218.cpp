typedef unsigned int u32;

extern "C" void func_00524400();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793A90;

extern int D_007944B0;

extern "C" void *func_00545218(void) {
    if (D_007944B0 == 0) {
        func_00524400();
        func_0050C6E8(&D_007944B0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793A90);
    }
    return &D_007944B0;
}
