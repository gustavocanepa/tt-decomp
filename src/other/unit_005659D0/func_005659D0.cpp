typedef unsigned int u32;

extern "C" void func_00563580();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B868;

extern int D_00795B40;

extern "C" void *func_005659D0(void) {
    if (D_00795B40 == 0) {
        func_00563580();
        func_0050C6E8(&D_00795B40, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B868);
    }
    return &D_00795B40;
}
