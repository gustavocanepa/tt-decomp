/* compiler: ee-gcc2.9-991111 */
/* Allocate a timer record from the IRQ-shared pool and assign a generation
 * handle. Callers supply interrupt exclusion. Layout and names provisional. */
struct Timer {
    struct Timer *volatile next;
    unsigned unknown4;
    volatile unsigned id;
    unsigned flags;
    unsigned long long started, elapsed, interval;
    void *callback;
    unsigned global_pointer;
    void *argument;
    char unknown34[12];
};
struct TimerState {
    unsigned long long ticks;
    int interrupt_handler;
    volatile unsigned generation;
    volatile int allocated;
    struct Timer *free;
};
extern struct TimerState D_005A4110;
int func_00504B00(void) {
    struct Timer *timer = D_005A4110.free;
    struct Timer *next;
    int allocated;
    if (!timer) return 0x80008005;
    allocated = D_005A4110.allocated + 1;
    next = timer->next;
    timer->callback = 0;
    D_005A4110.allocated = allocated;
    timer->flags = 0;
    D_005A4110.free = next;
    timer->elapsed = 0;
    ++D_005A4110.generation;
    timer->id = ((D_005A4110.generation << 1) & 0x3FE) | 1;
    return ((unsigned)timer << 4) | timer->id;
}
