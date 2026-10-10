typedef int s32;

extern "C" void func_0052FE98();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005E18E8[];
extern int D_005E1900;

extern int D_00793580;

extern "C" void *func_00518E38(void) {
    if (D_00793580 == 0) {
        func_0052FE98();
        func_0050C6C0(&D_00793580, D_005E18E8, &D_005E1900, 1);
    }
    return &D_00793580;
}
