/* compiler: ee-gcc2.9-991111 */
/* Dispatch a timer event through its alarm record. A zero callback result
 * releases the record and asks the timer to stop. Register views for the
 * timer values and callback result remain provisional. */
typedef unsigned long long (*TimerCallback)(int, unsigned long long,
    unsigned long long, void *);
struct Alarm {
    struct Alarm *next;
    volatile int timer;
    TimerCallback callback;
    void *argument;
};
extern struct Alarm *volatile D_00791BC0;
unsigned long long func_00505508(int timer, unsigned long long time0,
                              unsigned long long time1, struct Alarm *alarm) {
    unsigned long long result = alarm->callback(
        ((unsigned)alarm << 4) | (timer & 0xFE) | 1,
        time0, time1, alarm->argument);
    if (result) return result;
    {
        struct Alarm *previous = D_00791BC0;
        D_00791BC0 = alarm;
        alarm->next = previous;
        alarm->timer = 0;
    }
    return -1;
}
