typedef int s32;

extern "C" void func_00547118();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005F0720[];
extern int D_005F0728;

extern int D_00794570;

extern "C" void *func_00546D00(void) {
    if (D_00794570 == 0) {
        func_00547118();
        func_0050C6C0(&D_00794570, D_005F0720, &D_005F0728, 1);
    }
    return &D_00794570;
}
