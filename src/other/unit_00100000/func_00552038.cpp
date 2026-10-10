typedef unsigned int u32;

extern "C" void func_00566668();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795B60;

extern int D_00794BA0;

extern "C" void *func_00552038(void) {
    if (D_00794BA0 == 0) {
        func_00566668();
        func_0050C6E8(&D_00794BA0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795B60);
    }
    return &D_00794BA0;
}
