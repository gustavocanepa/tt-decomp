typedef unsigned int u32;

extern "C" void func_00524400();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793A90;

extern int D_00793D20;

extern "C" void *func_0052D610(void) {
    if (D_00793D20 == 0) {
        func_00524400();
        func_0050C6E8(&D_00793D20, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793A90);
    }
    return &D_00793D20;
}
