extern char D_0057B130;
extern char D_005EB2F0;
extern char D_00201DE0;
extern char D_00201E08;
extern char D_00201E30;

extern "C" void func_00297858(void *a0, void *a1, int a2, void *a3, void *a4, void *a5);

extern "C" void func_002022F8(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_00297858(&D_0057B130, &D_005EB2F0, 0x1C, &D_00201DE0, &D_00201E08, &D_00201E30);
    }
}

extern "C" void func_00297598(void) {
    func_002022F8(1, 0xFFFF);
}
