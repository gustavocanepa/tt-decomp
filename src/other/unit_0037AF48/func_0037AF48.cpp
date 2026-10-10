extern char D_00584680;
extern char D_00584688;

extern "C" void func_00339D78(void *a0, void *a1);

extern "C" void func_0037AF48(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_00339D78(&D_00584680, &D_00584688);
    }
}

extern "C" void func_00330840(void) {
    func_0037AF48(1, 0xFFFF);
}
