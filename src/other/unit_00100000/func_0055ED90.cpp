typedef unsigned int u32;

extern "C" void func_00552840();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B728;

extern int D_00795600;

extern "C" void *func_0055ED90(void) {
    if (D_00795600 == 0) {
        func_00552840();
        func_0050C6E8(&D_00795600, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B728);
    }
    return &D_00795600;
}
