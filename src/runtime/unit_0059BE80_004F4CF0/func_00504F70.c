/* compiler: ee-gcc2.9-991111 */
/* Replace a timer's accumulated ticks and return its previous running total.
 * Handle validation and all updates occur under interrupt exclusion.
 * Record/state layouts and names remain provisional. */
struct Timer {
    struct Timer *next;
    unsigned unknown4, id, flags;
    unsigned long long started, elapsed;
};
struct TimerState { char unknown0[0x1C]; int current; };
extern volatile struct TimerState D_005A4110;
extern int func_005038D8(void);
extern int func_00503928(void);
extern unsigned long long func_00504A30(void);
unsigned long long func_00504F70(int handle, unsigned long long replacement) {
    struct Timer *timer = (struct Timer *)(((unsigned)handle >> 10) << 6);
    int interrupts = func_005038D8();
    unsigned long long previous;
    if (handle < 0 || (handle & 0x3FF) != timer->id ||
        D_005A4110.current == handle) {
        if (interrupts) func_00503928();
        return -1;
    }
    previous = timer->elapsed;
    if (timer->flags & 1) {
        unsigned long long now = func_00504A30();
        previous += now - timer->started;
        timer->started = now;
        timer->elapsed = replacement;
    } else {
        timer->elapsed = replacement;
    }
    if (interrupts) func_00503928();
    return previous;
}
