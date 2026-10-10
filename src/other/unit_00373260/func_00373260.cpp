extern char D_005845A0;
extern char D_005845A8;

extern "C" void func_00339D78(void *a0, void *a1);

extern "C" void func_00373260(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_00339D78(&D_005845A0, &D_005845A8);
    }
}

extern "C" void func_00330840(void) {
    func_00373260(1, 0xFFFF);
}
