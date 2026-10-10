typedef unsigned int u32;

extern "C" void func_0055CD80();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795410;

extern int D_00795430;

extern "C" void *func_0055CE20(void) {
    if (D_00795430 == 0) {
        func_0055CD80();
        func_0050C6E8(&D_00795430, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795410);
    }
    return &D_00795430;
}
