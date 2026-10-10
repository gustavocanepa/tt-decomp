typedef int s32;

extern "C" void func_005755E8();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_006158D8[];
extern int D_006158E8;

extern int D_007A64C0;

extern "C" void *func_00576DF8(void) {
    if (D_007A64C0 == 0) {
        func_005755E8();
        func_0050C6C0(&D_007A64C0, D_006158D8, &D_006158E8, 1);
    }
    return &D_007A64C0;
}
