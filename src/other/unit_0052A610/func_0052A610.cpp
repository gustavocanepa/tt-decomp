typedef unsigned int u32;

extern "C" void func_00528810();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B6A0;

extern int D_00793C60;

extern "C" void *func_0052A610(void) {
    if (D_00793C60 == 0) {
        func_00528810();
        func_0050C6E8(&D_00793C60, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B6A0);
    }
    return &D_00793C60;
}
