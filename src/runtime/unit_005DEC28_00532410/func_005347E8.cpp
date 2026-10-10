typedef unsigned int u32;

extern "C" void func_0053B2D8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794100;

extern int D_00793E80;

extern "C" void *func_005347E8(void) {
    if (D_00793E80 == 0) {
        func_0053B2D8();
        func_0050C6E8(&D_00793E80, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794100);
    }
    return &D_00793E80;
}
