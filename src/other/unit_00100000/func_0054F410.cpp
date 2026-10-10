typedef unsigned int u32;

extern "C" void func_0054A7D8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794690;

extern int D_00794850;

extern "C" void *func_0054F410(void) {
    if (D_00794850 == 0) {
        func_0054A7D8();
        func_0050C6E8(&D_00794850, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794690);
    }
    return &D_00794850;
}
