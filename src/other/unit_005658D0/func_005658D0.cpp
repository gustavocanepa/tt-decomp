typedef unsigned int u32;

extern "C" void func_00563100();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B860;

extern int D_00795B30;

extern "C" void *func_005658D0(void) {
    if (D_00795B30 == 0) {
        func_00563100();
        func_0050C6E8(&D_00795B30, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B860);
    }
    return &D_00795B30;
}
