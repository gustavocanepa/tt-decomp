typedef unsigned int u32;

extern "C" void func_00567CF0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B8D0;

extern int D_00795BD0;

extern "C" void *func_00567C60(void) {
    if (D_00795BD0 == 0) {
        func_00567CF0();
        func_0050C6E8(&D_00795BD0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B8D0);
    }
    return &D_00795BD0;
}
