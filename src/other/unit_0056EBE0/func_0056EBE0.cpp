typedef unsigned int u32;

extern "C" void func_00571EF0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B9D0;

extern int D_0079DD40;

extern "C" void *func_0056EBE0(void) {
    if (D_0079DD40 == 0) {
        func_00571EF0();
        func_0050C6E8(&D_0079DD40, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B9D0);
    }
    return &D_0079DD40;
}
