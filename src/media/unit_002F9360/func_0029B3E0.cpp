extern char D_0057C130;
extern char D_005F0E38;
extern char D_00299BF8;
extern char D_00299C20;
extern char D_00299C48;

extern "C" void func_00297858(void *a0, void *a1, int a2, void *a3, void *a4, void *a5);

extern "C" void func_0029B3E0(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_00297858(&D_0057C130, &D_005F0E38, 0x14, &D_00299BF8, &D_00299C20, &D_00299C48);
    }
}

extern "C" void func_00297710(void) {
    func_0029B3E0(1, 0xFFFF);
}
