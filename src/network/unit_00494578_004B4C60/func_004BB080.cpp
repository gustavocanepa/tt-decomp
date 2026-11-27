/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_004BB610(void);
#define CTRL (*(volatile int *)0x10002010)
#define CMD (*(volatile unsigned int *)0x10002000)
#define BP (*(volatile unsigned int *)0x10002020)
extern "C" void func_004BB080(void) {
    func_004BB610();
    unsigned int value=0x58000000;
    do {} while (CTRL < 0);
    CMD = value;
    __asm__ volatile("sync" ::: "memory");
    while (CTRL < 0) {
        value = BP;
        if (((value >> 8) & 15) == 0) func_004BB610();
    }
}
