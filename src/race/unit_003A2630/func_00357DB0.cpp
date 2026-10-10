extern char D_005840A0;

extern "C" void func_0045D898(void *a0);
extern "C" void func_0045D8D8(void *a0, int a1);

extern "C" void func_00357DB0(int arg0, int arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            func_0045D898(&D_005840A0);
        }
        if (arg0 == 0) {
            func_0045D8D8(&D_005840A0, 2);
        }
    }
}

extern "C" void func_00330900(void) {
    func_00357DB0(1, 0xFFFF);
}

extern "C" void func_00330910(void) {
    func_00357DB0(0, 0xFFFF);
}
