typedef unsigned int u32;

extern "C" void func_00551160();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794B60;

extern int D_00794D70;

extern "C" void *func_00554688(void) {
    if (D_00794D70 == 0) {
        func_00551160();
        func_0050C6E8(&D_00794D70, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794B60);
    }
    return &D_00794D70;
}
