extern char D_007666C0;

extern "C" void func_004A48C0(void *a0);
extern "C" void func_004A48D8(void *a0, int a1);

extern "C" void func_00259728(int arg0, int arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            func_004A48C0(&D_007666C0);
        }
        if (arg0 == 0) {
            func_004A48D8(&D_007666C0, 2);
        }
    }
}

extern "C" void func_00330900(void) {
    func_00259728(1, 0xFFFF);
}

extern "C" void func_00330910(void) {
    func_00259728(0, 0xFFFF);
}
