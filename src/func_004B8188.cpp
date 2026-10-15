/* compiler: ee-gcc2.96-no-strict-aliasing */
extern int D_0059834C;
extern "C" void func_004B7760(void *) throw();
extern "C" int func_004B80F8(void) throw();
extern "C" int func_004B8228(int);
extern "C" void func_004B9C28(void);
extern "C" void func_004B9C50(void);
extern "C" int func_004B8188(int n) {
    if (func_004B80F8() == 0) return 0;
    {
        func_004B9C28();
        int base = D_0059834C;
        int q = n / 4;
        int r = n % 4;
        func_004B7760((void *)(((r * 0x1b + q * 0x6f) << 2) + base + 0x78));
        n = func_004B8228(n);
        func_004B9C50();
    }
    return n;
}
