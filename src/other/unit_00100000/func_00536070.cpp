typedef unsigned int u32;

extern "C" void func_0053B058();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007940C0;

extern int D_00793F70;

extern "C" void *func_00536070(void) {
    if (D_00793F70 == 0) {
        func_0053B058();
        func_0050C6E8(&D_00793F70, ((char *)"Q212GranTurismo413UpdateManager"), &D_007940C0);
    }
    return &D_00793F70;
}
