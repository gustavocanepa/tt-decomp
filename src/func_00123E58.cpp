extern char D_005798D0;
extern char D_005E0370;
extern char D_001204E8;
extern char D_00120510;
extern char D_00120538;

extern "C" void func_00297858(void *a0, void *a1, int a2, void *a3, void *a4, void *a5);

extern "C" void func_00123E58(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_00297858(&D_005798D0, &D_005E0370, 0x14, &D_001204E8, &D_00120510, &D_00120538);
    }
}

extern "C" void func_00330840(void) {
    func_00123E58(1, 0xFFFF);
}
