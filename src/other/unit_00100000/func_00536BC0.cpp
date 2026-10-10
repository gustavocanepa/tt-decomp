typedef int s32;

extern "C" void func_0052FE98();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EC9C0[];
extern int D_005EC9D0;

extern int D_00793FC0;

extern "C" void *func_00536BC0(void) {
    if (D_00793FC0 == 0) {
        func_0052FE98();
        func_0050C6C0(&D_00793FC0, D_005EC9C0, &D_005EC9D0, 1);
    }
    return &D_00793FC0;
}
