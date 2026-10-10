extern char D_00773E48;

extern "C" void func_004AF048(void *a0);
extern "C" void func_004AF080(void *a0, int a1);

extern "C" void func_004AEFB0(int arg0, int arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            func_004AF048(&D_00773E48);
        }
        if (arg0 == 0) {
            func_004AF080(&D_00773E48, 2);
        }
    }
}

extern "C" void func_00330900(void) {
    func_004AEFB0(1, 0xFFFF);
}

extern "C" void func_00330910(void) {
    func_004AEFB0(0, 0xFFFF);
}
