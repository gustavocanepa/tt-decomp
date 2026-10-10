typedef unsigned int u32;

extern "C" void func_0053FD08();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794260;

extern int D_007944A0;

extern "C" void *func_00545268(void) {
    if (D_007944A0 == 0) {
        func_0053FD08();
        func_0050C6E8(&D_007944A0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794260);
    }
    return &D_007944A0;
}
