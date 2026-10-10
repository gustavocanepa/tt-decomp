extern char D_007695E0;
extern char D_005FC008;

extern "C" void func_004AC338(void *a0, void *a1);

extern "C" void func_00410CB8(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_004AC338(&D_007695E0, &D_005FC008);
    }
}

extern "C" void func_00330840(void) {
    func_00410CB8(1, 0xFFFF);
}
