extern char D_00769568;
extern char D_005F9F00;

extern "C" void func_004AC338(void *a0, void *a1);

extern "C" void func_003FAA68(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_004AC338(&D_00769568, &D_005F9F00);
    }
}

extern "C" void func_00330840(void) {
    func_003FAA68(1, 0xFFFF);
}
