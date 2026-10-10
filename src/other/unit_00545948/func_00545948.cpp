typedef int s32;

extern "C" void func_00524A00();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EFEB0[];
extern int D_005EFEC0;

extern int D_007944C0;

extern "C" void *func_00545948(void) {
    if (D_007944C0 == 0) {
        func_00524A00();
        func_0050C6C0(&D_007944C0, D_005EFEB0, &D_005EFEC0, 1);
    }
    return &D_007944C0;
}
