typedef int s32;

extern "C" void func_005718F8();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_0060C350[];
extern int D_0060C370;

extern int D_007A5E60;

extern "C" void *func_00571AA8(void) {
    if (D_007A5E60 == 0) {
        func_005718F8();
        func_0050C6C0(&D_007A5E60, D_0060C350, &D_0060C370, 1);
    }
    return &D_007A5E60;
}
