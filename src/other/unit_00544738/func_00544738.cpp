typedef unsigned int u32;

extern "C" void func_0052F320();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793DC0;

extern int D_00794440;

extern "C" void *func_00544738(void) {
    if (D_00794440 == 0) {
        func_0052F320();
        func_0050C6E8(&D_00794440, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793DC0);
    }
    return &D_00794440;
}
