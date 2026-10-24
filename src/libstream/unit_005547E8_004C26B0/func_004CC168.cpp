/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Writes the low 7 bits of x to the hardware register at 0x10002000 between two calls of
   func_004BB350, with a sync after the store; the second call is a tail call. */
typedef unsigned int u32;

extern "C" void func_004BB350(void);

extern "C" void func_004CC168(u32 x) {
    func_004BB350();
    *(volatile u32 *)0x10002000 = x & 0x7F;
    __asm__ volatile ("sync");
    return func_004BB350();
}
