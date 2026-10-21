extern char D_00579C08;
extern char D_005E47D8;
extern char D_001740B8;
extern char D_001740E0;
extern char D_00174108;

extern "C" void func_00297858(void *a0, void *a1, int a2, void *a3, void *a4, void *a5);

extern "C" void func_00178140(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_00297858(&D_00579C08, &D_005E47D8, 0x10, &D_001740B8, &D_001740E0, &D_00174108);
    }
}

extern "C" void func_001A6430(void) {
    func_00178140(1, 0xFFFF);
}
