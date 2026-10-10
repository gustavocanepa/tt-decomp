typedef unsigned int u32;

extern "C" void func_00576C50();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061BA30;

extern int D_007A6490;

extern "C" void *func_00576400(void) {
    if (D_007A6490 == 0) {
        func_00576C50();
        func_0050C6E8(&D_007A6490, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061BA30);
    }
    return &D_007A6490;
}
