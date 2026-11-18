extern char D_0057C018;
extern char D_005F08F0;
extern char D_0028D068;
extern char D_0028D090;
extern char D_0028D0B8;

extern "C" void func_00297858(void *a0, void *a1, int a2, void *a3, void *a4, void *a5);

extern "C" void func_0028DD90(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_00297858(&D_0057C018, &D_005F08F0, 0x24, &D_0028D068, &D_0028D090, &D_0028D0B8);
    }
}

extern "C" void func_002977A8(void) {
    func_0028DD90(1, 0xFFFF);
}
