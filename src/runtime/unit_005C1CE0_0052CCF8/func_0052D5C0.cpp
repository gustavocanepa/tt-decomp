typedef unsigned int u32;

extern "C" void func_0052D6D8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793D30;

extern int D_00793D40;

extern "C" void *func_0052D5C0(void) {
    if (D_00793D40 == 0) {
        func_0052D6D8();
        func_0050C6E8(&D_00793D40, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793D30);
    }
    return &D_00793D40;
}
