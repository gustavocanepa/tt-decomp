typedef int s32;

extern "C" void func_0052FE98();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005E0350[];
extern int D_005E0368;

extern int D_00793500;

extern "C" void *func_00512300(void) {
    if (D_00793500 == 0) {
        func_0052FE98();
        func_0050C6C0(&D_00793500, D_005E0350, &D_005E0368, 1);
    }
    return &D_00793500;
}
