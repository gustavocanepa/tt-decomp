typedef unsigned int u32;

extern "C" void func_00521068();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793930;

extern int D_00793940;

extern "C" void *func_00521240(void) {
    if (D_00793940 == 0) {
        func_00521068();
        func_0050C6E8(&D_00793940, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793930);
    }
    return &D_00793940;
}
