extern char D_00583EC8;
extern char D_00583ED0;

extern "C" void func_00339D78(void *a0, void *a1);

extern "C" void func_00339C10(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_00339D78(&D_00583EC8, &D_00583ED0);
    }
}

extern "C" void func_00330840(void) {
    func_00339C10(1, 0xFFFF);
}
