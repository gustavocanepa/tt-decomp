/* compiler: ee-gcc2.9-991111 */
/* Validate the alarm handle's generation, release its timer and return the
 * record to the shared pool under interrupt exclusion. Layout provisional. */
typedef unsigned long long (*TimerCallback)(int, unsigned long long,
    unsigned long long, void *);
struct Alarm {
    struct Alarm *next;
    volatile int timer;
    TimerCallback callback;
    void *argument;
};
extern struct Alarm *volatile D_00791BC0;
extern int func_005038D8(void);
extern int func_00503928(void);
extern int func_00504C58(int);
int func_00505788(int handle) {
    struct Alarm *alarm = (struct Alarm *)(((unsigned)handle >> 8) << 4);
    int interrupts = func_005038D8();
    if (handle < 0 || ((handle ^ alarm->timer) & 255)) {
        if (interrupts) func_00503928();
        return 0x80008002;
    }
    func_00504C58(alarm->timer);
    {
        struct Alarm *previous = D_00791BC0;
        D_00791BC0 = alarm;
        alarm->next = previous;
        alarm->timer = 0;
    }
    if (interrupts) func_00503928();
    return 0;
}
