extern char D_00584588;
extern char D_00584590;

extern "C" void func_00339D78(void *a0, void *a1);

extern "C" void func_00371CB8(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_00339D78(&D_00584588, &D_00584590);
    }
}

extern "C" void func_00330840(void) {
    func_00371CB8(1, 0xFFFF);
}
