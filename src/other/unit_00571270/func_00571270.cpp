typedef unsigned int u32;

extern "C" void func_00572140();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007A5E90;

extern int D_007A5E20;

extern "C" void *func_00571270(void) {
    if (D_007A5E20 == 0) {
        func_00572140();
        func_0050C6E8(&D_007A5E20, ((char *)"Q212GranTurismo413UpdateManager"), &D_007A5E90);
    }
    return &D_007A5E20;
}
