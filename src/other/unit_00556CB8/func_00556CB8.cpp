typedef unsigned int u32;

extern "C" void func_00556BD0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795070;

extern int D_00794FC0;

extern "C" void *func_00556CB8(void) {
    if (D_00794FC0 == 0) {
        func_00556BD0();
        func_0050C6E8(&D_00794FC0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795070);
    }
    return &D_00794FC0;
}
