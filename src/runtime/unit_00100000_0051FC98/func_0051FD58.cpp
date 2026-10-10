typedef int s32;

extern "C" void func_0052FE98();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005E64C0[];
extern int D_005E64D8;

extern int D_00793810;

extern "C" void *func_0051FD58(void) {
    if (D_00793810 == 0) {
        func_0052FE98();
        func_0050C6C0(&D_00793810, D_005E64C0, &D_005E64D8, 1);
    }
    return &D_00793810;
}
