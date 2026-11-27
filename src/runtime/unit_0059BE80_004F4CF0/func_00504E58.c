/* compiler: ee-gcc2.9-991111 */
/* Stop a running timer, accumulating its elapsed ticks and removing any
 * pending callback from the scheduler. Caller supplies IRQ exclusion.
 * Partial record/state layouts remain provisional. */
struct Timer {
    struct Timer *next;
    unsigned unknown4, id, flags;
    unsigned long long started, elapsed;
};
struct TimerState { char unknown0[0x1C]; int current; };
extern volatile struct TimerState D_005A4110;
extern unsigned long long func_00504A30(void);
extern struct Timer *func_00504750(struct Timer *);
extern void func_00504538(unsigned long long);
int func_00504E58(int handle) {
    struct Timer *timer = (struct Timer *)(((unsigned)handle >> 10) << 6);
    unsigned flags;
    unsigned long long now;
    if (handle < 0 || (handle & 0x3FF) != timer->id) return 0x80008002;
    if (D_005A4110.current == handle) return 0x80000010;
    if (!(timer->flags & 1)) return 0;
    now = func_00504A30();
    flags = timer->flags;
    timer->elapsed += now - timer->started;
    timer->flags = flags & ~1U;
    if (flags & 2) {
        func_00504750(timer);
        func_00504538(now);
    }
    return 1;
}
