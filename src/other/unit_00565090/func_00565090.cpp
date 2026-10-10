typedef unsigned int u32;

extern "C" void func_00563D08();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795A00;

extern int D_00795A80;

extern "C" void *func_00565090(void) {
    if (D_00795A80 == 0) {
        func_00563D08();
        func_0050C6E8(&D_00795A80, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795A00);
    }
    return &D_00795A80;
}
