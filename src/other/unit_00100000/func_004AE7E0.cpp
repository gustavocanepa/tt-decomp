extern char D_00773E18;

extern "C" void func_004AE9C0(void *a0);
extern "C" void func_004AE9F0(void *a0, int a1);

extern "C" void func_004AE7E0(int arg0, int arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            func_004AE9C0(&D_00773E18);
        }
        if (arg0 == 0) {
            func_004AE9F0(&D_00773E18, 2);
        }
    }
}

extern "C" void func_00330900(void) {
    func_004AE7E0(1, 0xFFFF);
}

extern "C" void func_00330910(void) {
    func_004AE7E0(0, 0xFFFF);
}
