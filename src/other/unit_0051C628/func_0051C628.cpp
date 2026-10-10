typedef unsigned int u32;

extern "C" void func_00518C28();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793570;

extern int D_00793700;

extern "C" void *func_0051C628(void) {
    if (D_00793700 == 0) {
        func_00518C28();
        func_0050C6E8(&D_00793700, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793570);
    }
    return &D_00793700;
}
