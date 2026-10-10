typedef unsigned int u32;

extern "C" void func_00554688();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794D70;

extern int D_00794D90;

extern "C" void *func_00554A70(void) {
    if (D_00794D90 == 0) {
        func_00554688();
        func_0050C6E8(&D_00794D90, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794D70);
    }
    return &D_00794D90;
}
