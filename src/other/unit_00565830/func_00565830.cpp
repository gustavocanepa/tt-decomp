typedef unsigned int u32;

extern "C" void func_005658D0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795B30;

extern int D_00795B10;

extern "C" void *func_00565830(void) {
    if (D_00795B10 == 0) {
        func_005658D0();
        func_0050C6E8(&D_00795B10, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795B30);
    }
    return &D_00795B10;
}
