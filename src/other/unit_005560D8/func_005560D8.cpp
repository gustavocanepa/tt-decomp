typedef unsigned int u32;

extern "C" void func_00556098();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B760;

extern int D_00794EE0;

extern "C" void *func_005560D8(void) {
    if (D_00794EE0 == 0) {
        func_00556098();
        func_0050C6E8(&D_00794EE0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B760);
    }
    return &D_00794EE0;
}
