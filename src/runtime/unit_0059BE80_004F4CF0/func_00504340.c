/* compiler: ee-gcc2.9-991111 */
/* Shut down the timer service only when no timer records remain allocated.
 * Preserve the original interrupt-handler removal and hardware-reset paths.
 * State names and the unexposed tail of the layout remain provisional. */
struct TimerState {
    unsigned long long ticks;
    int interrupt_handler;
    unsigned generation;
    volatile int allocated;
};
extern struct TimerState D_005A4110;
extern int func_005038D8(void);
extern int func_00503928(void);
extern int func_004FA520(int, int);
extern int func_004FB300(int);
extern void func_005041C8(unsigned);
extern void func_005041B8(unsigned);
int func_00504340(void) {
    int interrupts;
    if (D_005A4110.interrupt_handler < 0) return 0x80008001;
    if (D_005A4110.allocated) return 0x80000010;
    interrupts = func_005038D8();
    if (!func_004FA520(11, D_005A4110.interrupt_handler)) {
        func_004FB300(11);
        func_005041C8(0xC00);
        func_005041B8(0);
    }
    D_005A4110.ticks = 0;
    D_005A4110.interrupt_handler = -1;
    if (interrupts) func_00503928();
    return 0;
}
