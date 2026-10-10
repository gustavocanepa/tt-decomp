typedef unsigned int u32;

extern "C" void func_00574198();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B9F8;

extern int D_007A63B0;

extern "C" void *func_00574248(void) {
    if (D_007A63B0 == 0) {
        func_00574198();
        func_0050C6E8(&D_007A63B0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B9F8);
    }
    return &D_007A63B0;
}
