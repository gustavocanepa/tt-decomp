extern char D_00584568;
extern char D_00584570;

extern "C" void func_00339D78(void *a0, void *a1);

extern "C" void func_0036F150(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_00339D78(&D_00584568, &D_00584570);
    }
}

extern "C" void func_00330840(void) {
    func_0036F150(1, 0xFFFF);
}
