typedef unsigned int u32;

extern "C" void func_0055D150();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795480;

extern int D_00795460;

extern "C" void *func_0055D000(void) {
    if (D_00795460 == 0) {
        func_0055D150();
        func_0050C6E8(&D_00795460, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795480);
    }
    return &D_00795460;
}
