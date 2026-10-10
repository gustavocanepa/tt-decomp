typedef unsigned int u32;

extern "C" void func_00558120();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795100;

extern int D_00795290;

extern "C" void *func_005581F0(void) {
    if (D_00795290 == 0) {
        func_00558120();
        func_0050C6E8(&D_00795290, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795100);
    }
    return &D_00795290;
}
