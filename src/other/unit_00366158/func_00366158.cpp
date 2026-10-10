extern char D_00584428;

extern "C" void func_0044C9E8(void *a0);
extern "C" void func_0044C9F8(void *a0, int a1);

extern "C" void func_00366158(int arg0, int arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            func_0044C9E8(&D_00584428);
        }
        if (arg0 == 0) {
            func_0044C9F8(&D_00584428, 2);
        }
    }
}

extern "C" void func_00330900(void) {
    func_00366158(1, 0xFFFF);
}

extern "C" void func_00330910(void) {
    func_00366158(0, 0xFFFF);
}
