typedef unsigned int u32;

extern "C" void func_00528680();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B698;

extern int D_00793B50;

extern "C" void *func_005286F8(void) {
    if (D_00793B50 == 0) {
        func_00528680();
        func_0050C6E8(&D_00793B50, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B698);
    }
    return &D_00793B50;
}
