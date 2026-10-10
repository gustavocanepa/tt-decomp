typedef unsigned int u32;

extern "C" void func_0050EE18();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793430;

extern int D_00793450;

extern "C" void *func_0050EE68(void) {
    if (D_00793450 == 0) {
        func_0050EE18();
        func_0050C6E8(&D_00793450, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793430);
    }
    return &D_00793450;
}
