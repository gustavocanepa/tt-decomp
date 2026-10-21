extern char D_0057B5D0;
extern char D_005ED158;
extern char D_0022F178;
extern char D_0022F1A0;
extern char D_0022F1C8;

extern "C" void func_00297858(void *a0, void *a1, int a2, void *a3, void *a4, void *a5);

extern "C" void func_0022FB00(int arg0, int arg1) {
    if (arg1 == 0xFFFF && arg0 == 1) {
        func_00297858(&D_0057B5D0, &D_005ED158, 0x20, &D_0022F178, &D_0022F1A0, &D_0022F1C8);
    }
}

extern "C" void func_0029E600(void) {
    func_0022FB00(1, 0xFFFF);
}
