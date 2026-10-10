extern char D_007739F8;

extern "C" void func_004AF048(void *a0);
extern "C" void func_004AF080(void *a0, int a1);

extern "C" void func_004A52E8(int arg0, int arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            func_004AF048(&D_007739F8);
        }
        if (arg0 == 0) {
            func_004AF080(&D_007739F8, 2);
        }
    }
}

extern "C" void func_00330900(void) {
    func_004A52E8(1, 0xFFFF);
}

extern "C" void func_00330910(void) {
    func_004A52E8(0, 0xFFFF);
}
