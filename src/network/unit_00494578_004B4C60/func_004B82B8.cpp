/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char *D_0059834C;
extern "C" int func_005038D8();
extern "C" int func_004B80F8(int) throw();
extern "C" int func_004B82B8(int n) {
    int value = 1;
    int intr = func_005038D8();
    if (func_004B80F8(n)) {
        int q = n / 4;
        int r = n % 4;
        value = *(int *)(((r * 27 + q * 111) << 2) + (int)D_0059834C + 0xe0);
    }
    if (intr) __asm__ volatile("ei");
    return value;
}
