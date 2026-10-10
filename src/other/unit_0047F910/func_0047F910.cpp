extern char D_0076FC90;

extern "C" void func_004A48C0(void *a0);
extern "C" void func_004A48D8(void *a0, int a1);

extern "C" void func_0047F910(int arg0, int arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            func_004A48C0(&D_0076FC90);
        }
        if (arg0 == 0) {
            func_004A48D8(&D_0076FC90, 2);
        }
    }
}

extern "C" void func_00330900(void) {
    func_0047F910(1, 0xFFFF);
}

extern "C" void func_00330910(void) {
    func_0047F910(0, 0xFFFF);
}
