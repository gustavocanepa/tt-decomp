extern char D_0057C1F0;
extern char D_005F1130;
extern char D_002A13E0;
extern char D_002A1408;
extern char D_002A1430;

extern "C" void func_00297858(void *a0, void *a1, int a2, void *a3, void *a4, void *a5);

extern "C" void func_002A19A8(int arg0, int arg1) {
    if (arg1 == 0xFFFF && arg0 == 1) {
        func_00297858(&D_0057C1F0, &D_005F1130, 0x18, &D_002A13E0, &D_002A1408, &D_002A1430);
    }
}

extern "C" void func_002977B8(void) {
    func_002A19A8(1, 0xFFFF);
}
