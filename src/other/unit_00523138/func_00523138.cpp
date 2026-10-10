typedef unsigned int u32;

extern "C" void func_0052EC40();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B6C0;

extern int D_00793A60;

extern "C" void *func_00523138(void) {
    if (D_00793A60 == 0) {
        func_0052EC40();
        func_0050C6E8(&D_00793A60, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B6C0);
    }
    return &D_00793A60;
}
