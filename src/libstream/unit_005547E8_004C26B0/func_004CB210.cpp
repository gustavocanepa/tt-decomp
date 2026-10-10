extern char D_005A07B0[];

extern "C" void func_004A4D68(void *m);
extern "C" void func_004A4DD8(void *m);
extern "C" int func_004DB618(void *x);
extern "C" void func_004A59F0(void);
extern "C" void func_004CBA28(int *a, int *b);

extern "C" int func_004CB210(void *x) {
    int a, b;
    func_004A4D68(D_005A07B0);
    while (func_004DB618(x))
        func_004A59F0();
    func_004CBA28(&a, &b);
    func_004A4DD8(D_005A07B0);
    return b;
}
