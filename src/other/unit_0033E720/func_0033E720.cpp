extern char D_00583EF8;
extern char D_00583F00;

extern "C" void func_00339D78(void *a0, void *a1);

extern "C" void func_0033E720(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_00339D78(&D_00583EF8, &D_00583F00);
    }
}

extern "C" void func_00330840(void) {
    func_0033E720(1, 0xFFFF);
}
