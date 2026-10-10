typedef unsigned int u32;

extern "C" void func_00551028();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794B80;

extern int D_007954A0;

extern "C" void *func_0055DA40(void) {
    if (D_007954A0 == 0) {
        func_00551028();
        func_0050C6E8(&D_007954A0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794B80);
    }
    return &D_007954A0;
}
