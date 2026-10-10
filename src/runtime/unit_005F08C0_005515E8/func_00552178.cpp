typedef unsigned int u32;

extern "C" void func_005522E8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B6F8;

extern int D_00794BB0;

extern "C" void *func_00552178(void) {
    if (D_00794BB0 == 0) {
        func_005522E8();
        func_0050C6E8(&D_00794BB0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B6F8);
    }
    return &D_00794BB0;
}
