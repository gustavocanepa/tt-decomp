typedef unsigned int u32;

extern "C" void func_005727E0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B9E0;

extern int D_007A5ED0;

extern "C" void *func_005724F8(void) {
    if (D_007A5ED0 == 0) {
        func_005727E0();
        func_0050C6E8(&D_007A5ED0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B9E0);
    }
    return &D_007A5ED0;
}
