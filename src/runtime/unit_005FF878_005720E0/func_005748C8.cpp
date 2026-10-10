typedef unsigned int u32;

extern "C" void func_005773E8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061BA38;

extern int D_007A63D0;

extern "C" void *func_005748C8(void) {
    if (D_007A63D0 == 0) {
        func_005773E8();
        func_0050C6E8(&D_007A63D0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061BA38);
    }
    return &D_007A63D0;
}
