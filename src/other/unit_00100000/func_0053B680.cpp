typedef int s32;

extern "C" void func_0053C698();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005ED6E8[];
extern int D_005ED700;

extern int D_00794140;

extern "C" void *func_0053B680(void) {
    if (D_00794140 == 0) {
        func_0053C698();
        func_0050C6C0(&D_00794140, D_005ED6E8, &D_005ED700, 1);
    }
    return &D_00794140;
}
