typedef unsigned int u32;

extern "C" void func_00554000();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794D10;

extern int D_00794D30;

extern "C" void *func_005540F0(void) {
    if (D_00794D30 == 0) {
        func_00554000();
        func_0050C6E8(&D_00794D30, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794D10);
    }
    return &D_00794D30;
}
