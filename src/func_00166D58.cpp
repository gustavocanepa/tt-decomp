extern char D_00579AF0;
extern char D_005E3198;
extern char D_0015A7D8;
extern char D_0015A800;
extern char D_0015A828;

extern "C" void func_00297858(void *a0, void *a1, int a2, void *a3, void *a4, void *a5);

extern "C" void func_00166D58(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_00297858(&D_00579AF0, &D_005E3198, 0x1738, &D_0015A7D8, &D_0015A800, &D_0015A828);
    }
}

extern "C" void func_00330900(void) {
    func_00166D58(1, 0xFFFF);
}
