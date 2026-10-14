extern char D_00579A18;
extern char D_005E1BD0;
extern char D_001420E0;
extern char D_00142108;
extern char D_00142130;

extern "C" void func_00297858(void *a0, void *a1, int a2, void *a3, void *a4, void *a5);

extern "C" void func_0014D480(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_00297858(&D_00579A18, &D_005E1BD0, 0x18, &D_001420E0, &D_00142108, &D_00142130);
    }
}

extern "C" void func_00330900(void) {
    func_0014D480(1, 0xFFFF);
}
