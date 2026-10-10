extern char D_00582A50;
extern char D_00582A58;

extern "C" void func_00339D78(void *a0, void *a1);

extern "C" void func_002CA510(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_00339D78(&D_00582A50, &D_00582A58);
    }
}

extern "C" void func_00330840(void) {
    func_002CA510(1, 0xFFFF);
}
