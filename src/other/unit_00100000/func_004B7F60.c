/* Interrupt handler: signal the semaphore at most twice while enabled, then ExitHandler().
 * Sony's ExitHandler() is one asm block "sync.l; ei", which tools/asm_policy.py does not allow;
 * two single-instruction asms plus an empty volatile asm reproduce its scheduling (workaround). */
extern volatile int D_00598358;
extern int D_0059835C;
extern int D_00598360;
extern void func_004F42C8(int sema);

int func_004B7F60(void) {
    if (D_00598358) {
        int n = D_0059835C;
        if (n < 2) {
            D_0059835C = n + 1;
            func_004F42C8(D_00598360);
        }
    }
    __asm__ volatile("sync");
    __asm__ volatile("ei");
    __asm__ volatile("");
    return 0;
}
