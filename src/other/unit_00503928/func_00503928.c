/* Enables interrupts (EI) and returns whether they were enabled before: libkernel's EIntr(). */
int func_00503928(void)
{
    int status;
    __asm__ volatile("mfc0 %0, $12" : "=r"(status));
    status &= 0x10000;
    __asm__ volatile("ei");
    return status != 0;
}
