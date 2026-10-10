typedef unsigned int u32;

extern "C" void func_00554648();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B748;

extern int D_00794EF0;

extern "C" void *func_00556128(void) {
    if (D_00794EF0 == 0) {
        func_00554648();
        func_0050C6E8(&D_00794EF0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B748);
    }
    return &D_00794EF0;
}
