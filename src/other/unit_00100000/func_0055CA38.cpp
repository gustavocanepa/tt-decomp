typedef unsigned int u32;

extern "C" void func_005547E8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794D60;

extern int D_007953E0;

extern "C" void *func_0055CA38(void) {
    if (D_007953E0 == 0) {
        func_005547E8();
        func_0050C6E8(&D_007953E0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794D60);
    }
    return &D_007953E0;
}
