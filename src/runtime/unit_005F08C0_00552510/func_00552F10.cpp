typedef unsigned int u32;

extern "C" void func_00552CC8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794BD0;

extern int D_00794BE0;

extern "C" void *func_00552F10(void) {
    if (D_00794BE0 == 0) {
        func_00552CC8();
        func_0050C6E8(&D_00794BE0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794BD0);
    }
    return &D_00794BE0;
}
