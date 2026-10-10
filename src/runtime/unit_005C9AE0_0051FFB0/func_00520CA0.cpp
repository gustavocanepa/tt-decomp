typedef unsigned int u32;

extern "C" void func_00520A30();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007938C0;

extern int D_007938A0;

extern "C" void *func_00520CA0(void) {
    if (D_007938A0 == 0) {
        func_00520A30();
        func_0050C6E8(&D_007938A0, ((char *)"Q212GranTurismo413UpdateManager"), &D_007938C0);
    }
    return &D_007938A0;
}
