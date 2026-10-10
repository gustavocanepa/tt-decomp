typedef unsigned int u32;

extern "C" void func_00556538();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794F20;

extern int D_00794F90;

extern "C" void *func_00556598(void) {
    if (D_00794F90 == 0) {
        func_00556538();
        func_0050C6E8(&D_00794F90, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794F20);
    }
    return &D_00794F90;
}
