typedef unsigned int u32;

extern "C" void func_00554C08();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B750;

extern int D_00794B70;

extern "C" void *func_00551078(void) {
    if (D_00794B70 == 0) {
        func_00554C08();
        func_0050C6E8(&D_00794B70, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B750);
    }
    return &D_00794B70;
}
