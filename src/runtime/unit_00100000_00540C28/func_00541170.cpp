typedef unsigned int u32;

extern "C" void func_00538608();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794070;

extern int D_007942F0;

extern "C" void *func_00541170(void) {
    if (D_007942F0 == 0) {
        func_00538608();
        func_0050C6E8(&D_007942F0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794070);
    }
    return &D_007942F0;
}
