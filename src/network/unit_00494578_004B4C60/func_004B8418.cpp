/* compiler: ee-gcc2.96-no-strict-aliasing */
extern int D_0059834C;
extern "C" int func_004B80F8(int) throw();
extern "C" int func_005038D8(void);
extern "C" int func_004B8418(int n) {
    int result = 0;
    int enabled = func_005038D8();
    int valid = func_004B80F8(n);
    int q = n / 4;
    if (valid) {
        int base = D_0059834C;
        int r = n % 4;
        result = *(int *)(((r * 0x1b + q * 0x6f) << 2) + base + 0xD4);
    }
    if (enabled) __asm__ volatile("ei");
    return result;
}
