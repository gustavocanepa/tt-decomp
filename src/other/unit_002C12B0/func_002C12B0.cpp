extern char D_00767130;

extern "C" void func_004A48C0(void *a0);
extern "C" void func_004A48D8(void *a0, int a1);

extern "C" void func_002C12B0(int arg0, int arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            func_004A48C0(&D_00767130);
        }
        if (arg0 == 0) {
            func_004A48D8(&D_00767130, 2);
        }
    }
}

extern "C" void func_00330900(void) {
    func_002C12B0(1, 0xFFFF);
}

extern "C" void func_00330910(void) {
    func_002C12B0(0, 0xFFFF);
}
