typedef unsigned int u32;

extern "C" void func_00529480();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793BF0;

extern int D_00793C00;

extern "C" void *func_005294E0(void) {
    if (D_00793C00 == 0) {
        func_00529480();
        func_0050C6E8(&D_00793C00, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793BF0);
    }
    return &D_00793C00;
}
