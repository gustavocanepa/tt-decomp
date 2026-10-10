typedef unsigned int u32;

extern "C" void func_0054F7E8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794A90;

extern int D_00794720;

extern "C" void *func_0054CCC8(void) {
    if (D_00794720 == 0) {
        func_0054F7E8();
        func_0050C6E8(&D_00794720, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794A90);
    }
    return &D_00794720;
}
