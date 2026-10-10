typedef int s32;

extern "C" void func_0053F570();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005F0828[];
extern int D_005F0840;

extern int D_00794580;

extern "C" void *func_00546E28(void) {
    if (D_00794580 == 0) {
        func_0053F570();
        func_0050C6C0(&D_00794580, D_005F0828, &D_005F0840, 1);
    }
    return &D_00794580;
}
