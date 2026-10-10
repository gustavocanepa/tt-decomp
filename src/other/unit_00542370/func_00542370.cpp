typedef int s32;

extern "C" void func_0052FE98();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EF100[];
extern int D_005EF110;

extern int D_00794370;

extern "C" void *func_00542370(void) {
    if (D_00794370 == 0) {
        func_0052FE98();
        func_0050C6C0(&D_00794370, D_005EF100, &D_005EF110, 1);
    }
    return &D_00794370;
}
