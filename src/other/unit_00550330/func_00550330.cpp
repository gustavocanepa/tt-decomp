typedef unsigned int u32;

extern "C" void func_0054F790();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794A80;

extern int D_00794B00;

extern "C" void *func_00550330(void) {
    if (D_00794B00 == 0) {
        func_0054F790();
        func_0050C6E8(&D_00794B00, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794A80);
    }
    return &D_00794B00;
}
