typedef unsigned int u32;

extern "C" void func_00556E50();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795280;

extern int D_00795270;

extern "C" void *func_00559098(void) {
    if (D_00795270 == 0) {
        func_00556E50();
        func_0050C6E8(&D_00795270, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795280);
    }
    return &D_00795270;
}
