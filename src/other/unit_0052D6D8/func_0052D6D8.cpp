typedef unsigned int u32;

extern "C" void func_00524710();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B688;

extern int D_00793D30;

extern "C" void *func_0052D6D8(void) {
    if (D_00793D30 == 0) {
        func_00524710();
        func_0050C6E8(&D_00793D30, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B688);
    }
    return &D_00793D30;
}
