typedef unsigned int u32;

extern "C" void func_00528D90();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793BC0;

extern int D_00793EB0;

extern "C" void *func_005348E0(void) {
    if (D_00793EB0 == 0) {
        func_00528D90();
        func_0050C6E8(&D_00793EB0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793BC0);
    }
    return &D_00793EB0;
}
