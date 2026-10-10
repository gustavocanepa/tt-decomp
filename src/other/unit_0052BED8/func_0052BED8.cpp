typedef int s32;

extern "C" void func_0053B0C8();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EA190[];
extern int D_005EA1A0;

extern int D_00793C90;

extern "C" void *func_0052BED8(void) {
    if (D_00793C90 == 0) {
        func_0053B0C8();
        func_0050C6C0(&D_00793C90, D_005EA190, &D_005EA1A0, 1);
    }
    return &D_00793C90;
}
