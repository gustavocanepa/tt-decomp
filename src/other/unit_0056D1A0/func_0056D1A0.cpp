typedef unsigned int u32;

extern "C" void func_0056D0B0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B900;

extern int D_00795C20;

extern "C" void *func_0056D1A0(void) {
    if (D_00795C20 == 0) {
        func_0056D0B0();
        func_0050C6E8(&D_00795C20, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B900);
    }
    return &D_00795C20;
}
