extern char D_007654D0;

extern "C" void func_004AE9C0(void *a0);
extern "C" void func_004AE9F0(void *a0, int a1);

extern "C" void func_001DCB80(int arg0, int arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            func_004AE9C0(&D_007654D0);
        }
        if (arg0 == 0) {
            func_004AE9F0(&D_007654D0, 2);
        }
    }
}

extern "C" void func_00330900(void) {
    func_001DCB80(1, 0xFFFF);
}

extern "C" void func_00330910(void) {
    func_001DCB80(0, 0xFFFF);
}
