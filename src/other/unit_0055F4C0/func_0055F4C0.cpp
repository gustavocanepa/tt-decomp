typedef unsigned int u32;

extern "C" void func_0055E2A0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795530;

extern int D_00795670;

extern "C" void *func_0055F4C0(void) {
    if (D_00795670 == 0) {
        func_0055E2A0();
        func_0050C6E8(&D_00795670, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795530);
    }
    return &D_00795670;
}
