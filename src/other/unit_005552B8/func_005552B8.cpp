typedef unsigned int u32;

extern "C" void func_005522E8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B6F8;

extern int D_00794E30;

extern "C" void *func_005552B8(void) {
    if (D_00794E30 == 0) {
        func_005522E8();
        func_0050C6E8(&D_00794E30, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B6F8);
    }
    return &D_00794E30;
}
