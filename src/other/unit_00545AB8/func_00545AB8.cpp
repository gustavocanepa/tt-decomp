typedef int s32;

extern "C" void func_00545948();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005F0000[];
extern int D_005F0010;

extern int D_007944D0;

extern "C" void *func_00545AB8(void) {
    if (D_007944D0 == 0) {
        func_00545948();
        func_0050C6C0(&D_007944D0, D_005F0000, &D_005F0010, 1);
    }
    return &D_007944D0;
}
