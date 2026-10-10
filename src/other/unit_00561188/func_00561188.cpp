typedef unsigned int u32;

extern "C" void func_00561080();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795870;

extern int D_00795880;

extern "C" void *func_00561188(void) {
    if (D_00795880 == 0) {
        func_00561080();
        func_0050C6E8(&D_00795880, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795870);
    }
    return &D_00795880;
}
