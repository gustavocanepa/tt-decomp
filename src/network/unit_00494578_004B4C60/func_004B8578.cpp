/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char *D_0059834C;
extern "C" int func_005038D8();
extern "C" int func_004B80F8(int) throw();
struct State { char pad[0x68]; int value; };
extern "C" int func_004B8578(int n) {
    int value = 1;
    int intr = func_005038D8();
    if (func_004B80F8(n)) {
        int q = n / 4;
        int r = n % 4;
        State *p = (State *)((((r * 27 + q * 111) << 2) + (int)D_0059834C) + 0x78);
        value = p->value;
        p->value = 0;
    }
    if (intr) __asm__ volatile("ei");
    return value;
}
