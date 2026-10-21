/* compiler: ee-gcc2.96-no-strict-aliasing */
#define CSR (*(volatile unsigned long *)0x12001000)
extern "C" void func_0046D9A8(void) {
    CSR = 8;
    int i = 0x3A980;
    do {
        unsigned long status = CSR;
        --i;
        if (status & 8) break;
    } while (i);
    CSR = 8;
}
