typedef int s32;

extern "C" void func_0052FE98();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EE270[];
extern int D_005EE288;

extern int D_00794200;

extern "C" void *func_0053DE28(void) {
    if (D_00794200 == 0) {
        func_0052FE98();
        func_0050C6C0(&D_00794200, D_005EE270, &D_005EE288, 1);
    }
    return &D_00794200;
}
