extern char D_00584498;
extern char D_005844A0;

extern "C" void func_00339D78(void *a0, void *a1);

extern "C" void func_0036D380(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_00339D78(&D_00584498, &D_005844A0);
    }
}

extern "C" void func_00330840(void) {
    func_0036D380(1, 0xFFFF);
}
