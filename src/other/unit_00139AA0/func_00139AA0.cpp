extern char D_00764180;
extern char D_005E1618;

extern "C" void func_004AC338(void *a0, void *a1);

extern "C" void func_00139AA0(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_004AC338(&D_00764180, &D_005E1618);
    }
}

extern "C" void func_00330840(void) {
    func_00139AA0(1, 0xFFFF);
}
