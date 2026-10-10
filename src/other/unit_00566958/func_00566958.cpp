typedef unsigned int u32;

extern "C" void func_00567DC0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B8D8;

extern int D_00795B70;

extern "C" void *func_00566958(void) {
    if (D_00795B70 == 0) {
        func_00567DC0();
        func_0050C6E8(&D_00795B70, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B8D8);
    }
    return &D_00795B70;
}
