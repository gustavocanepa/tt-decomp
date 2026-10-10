extern char D_005845B8;
extern char D_005845C0;

extern "C" void func_00339D78(void *a0, void *a1);

extern "C" void func_00374238(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_00339D78(&D_005845B8, &D_005845C0);
    }
}

extern "C" void func_00330840(void) {
    func_00374238(1, 0xFFFF);
}
