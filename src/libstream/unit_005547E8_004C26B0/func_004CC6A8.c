/* compiler: ee-gcc2.9-991111 */
/* Issue IPU FDEC with an eight-bit shift; preserve the original sync barrier.
   This helper does not wait for the decoder before issuing the command. */
typedef unsigned int u32;

void func_004CC6A8(void) {
    *(volatile u32 *)0x10002000 = 0x40000008;
    __asm__ volatile("sync");
}
