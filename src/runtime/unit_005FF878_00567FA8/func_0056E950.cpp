typedef unsigned int u32;

extern "C" void func_0056E660();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B980;

extern int D_00795D08;

extern "C" void *func_0056E950(void) {
    if (D_00795D08 == 0) {
        func_0056E660();
        func_0050C6E8(&D_00795D08, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B980);
    }
    return &D_00795D08;
}
