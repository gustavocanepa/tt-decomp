typedef unsigned int u32;

extern "C" void func_00561120();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795860;

extern int D_00795840;

extern "C" void *func_00560ED8(void) {
    if (D_00795840 == 0) {
        func_00561120();
        func_0050C6E8(&D_00795840, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795860);
    }
    return &D_00795840;
}
