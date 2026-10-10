typedef int s32;

extern "C" void func_00529600();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EBB80[];
extern int D_005EBB90;

extern int D_00793E50;

extern "C" void *func_0052FE98(void) {
    if (D_00793E50 == 0) {
        func_00529600();
        func_0050C6C0(&D_00793E50, D_005EBB80, &D_005EBB90, 1);
    }
    return &D_00793E50;
}
