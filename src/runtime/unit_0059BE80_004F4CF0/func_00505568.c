/* compiler: ee-gcc2.9-991111 */
/* Allocate an alarm record and a timer handle under interrupt exclusion.
 * Roll back the record on timer-allocation failure. Handle encoding combines
 * the record address with the timer generation bits; names are provisional. */
/* The dispatcher forwards four registers, including two 64-bit timer values.
 * Their precise meaning and the original callback typedef remain provisional. */
typedef unsigned long long (*TimerCallback)(int, unsigned long long,
    unsigned long long, void *);
struct Alarm {
    struct Alarm *next;
    volatile int timer;
    TimerCallback callback;
    void *argument;
};
extern struct Alarm *volatile D_00791BC0;
static inline struct Alarm *take_record(void) {
    struct Alarm *record=D_00791BC0;
    if(record) D_00791BC0=record->next;
    return record;
}
extern int func_005038D8(void);
extern int func_00503928(void);
extern int func_00504B70(void);
extern int func_00505290(int, unsigned long long, TimerCallback, void *);
extern unsigned long long func_00505508(int, unsigned long long, unsigned long long, void *);
extern int func_00504E08(int);
int func_00505568(unsigned long long delay, TimerCallback callback, void *argument) {
    struct Alarm *alarm;
    int interrupts, timer;
    if(!callback) return 0x80000016;
    interrupts=func_005038D8();
    alarm=take_record();
    if(!alarm) {
        if(interrupts) func_00503928();
        return 0x80008005;
    }
    timer=func_00504B70();
    if(timer<0) {
        struct Alarm *previous=D_00791BC0;
        D_00791BC0=alarm;
        alarm->next=previous;
        alarm->timer=0;
        if(interrupts) func_00503928();
        return timer;
    }
    alarm->callback=callback;
    alarm->argument=argument;
    alarm->timer=timer;
    func_00505290(timer,delay,func_00505508,alarm);
    func_00504E08(timer);
    if(interrupts) func_00503928();
    return ((unsigned)alarm<<4)|(timer&0xFE)|1;
}
