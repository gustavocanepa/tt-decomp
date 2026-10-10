typedef unsigned int u32;

extern "C" void func_0052C2B8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793CC0;

extern int D_00794220;

extern "C" void *func_0053FC80(void) {
    if (D_00794220 == 0) {
        func_0052C2B8();
        func_0050C6E8(&D_00794220, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793CC0);
    }
    return &D_00794220;
}
