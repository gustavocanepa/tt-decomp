typedef unsigned int u32;

extern "C" void func_0054F790();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794A80;

extern int D_00794AC0;

extern "C" void *func_005501F0(void) {
    if (D_00794AC0 == 0) {
        func_0054F790();
        func_0050C6E8(&D_00794AC0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794A80);
    }
    return &D_00794AC0;
}
