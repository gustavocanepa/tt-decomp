extern char D_007668B8;

extern "C" void func_004A48C0(void *a0);
extern "C" void func_004A48D8(void *a0, int a1);

extern "C" void func_00269E20(int arg0, int arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            func_004A48C0(&D_007668B8);
        }
        if (arg0 == 0) {
            func_004A48D8(&D_007668B8, 2);
        }
    }
}

extern "C" void func_00330900(void) {
    func_00269E20(1, 0xFFFF);
}

extern "C" void func_00330910(void) {
    func_00269E20(0, 0xFFFF);
}
