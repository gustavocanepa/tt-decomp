typedef int s32;

extern "C" void func_005761C0();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_006150B8[];
extern int D_006150C8;

extern int D_007A6450;

extern "C" void *func_00575180(void) {
    if (D_007A6450 == 0) {
        func_005761C0();
        func_0050C6C0(&D_007A6450, D_006150B8, &D_006150C8, 1);
    }
    return &D_007A6450;
}
