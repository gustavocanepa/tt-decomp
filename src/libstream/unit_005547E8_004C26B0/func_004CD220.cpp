extern int D_005A07F0;
extern int D_005A07F4;
extern int D_005A0828;

extern "C" void func_004CD920(void *x);
extern "C" int func_004CD288(int n);
extern "C" void func_004CCA90(void *x);

extern "C" void func_004CD220(void *x) {
    func_004CD920(x);
    int n = D_005A07F0 * D_005A07F4;
    if (D_005A0828 != 3)
        n >>= 1;
    while (func_004CD288(n) >= 0)
        ;
    return func_004CCA90(x);
}
