typedef int s32;

extern "C" void func_00545948();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005F0660[];
extern int D_005F0670;

extern int D_00794550;

extern "C" void *func_00546A40(void) {
    if (D_00794550 == 0) {
        func_00545948();
        func_0050C6C0(&D_00794550, D_005F0660, &D_005F0670, 1);
    }
    return &D_00794550;
}
